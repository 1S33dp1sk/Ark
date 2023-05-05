//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "../Context/AetherCtx.sol";

import "../DAO/Memberships/IMemberships.sol";
import "../DAO/AetherDAO.sol";
import "../Keeper/Tracker/Tracker.sol";
import "../Keeper/KeeperAether.sol";
import "../Node/AetherNode.sol";
import "../Common/IOwner.sol";
import "./IAetherToken.sol";

contract AetherToken is AetherCtx , IAetherToken {

    mapping( address => uint256 ) private _balances;
    mapping( address => mapping( address => uint256 ) ) private _allowances;
    mapping( address => uint256 ) _collateral;

    uint256 private _totalSupply;
    uint256 private constant _maxSupply = 250000000 ether;
    uint8 private constant _decimals = 18;
    uint8 private constant _conv[2] = [25,100]; 
    string private constant _name = "0xAetherToken";
    string private constant _symbol = "0xA";


    function convert() public pure returns ( uint8 percentage ) {

        return _conv[1]/_conv[0];
    }

    function name() public pure override returns ( string memory ) {

        return _name;
    }
 
    function symbol() public pure override returns ( string memory ) {

        return _symbol;
    }

    function decimals() public pure override returns ( uint8 ) {

        return _decimals;
    }

    function maxSupply() public pure override returns( uint256 ) {

        return _maxSupply;
    }

    function totalSupply() public view override returns ( uint256 ) {

        return _totalSupply;
    }

    function balanceOf( address account ) public view override returns ( uint256 ) {

        return _balances[account];
    }

    function threshold( address addr , uint256 tokenThreshold ) external view override returns( bool ) {

        return _balances[addr] >= tokenThreshold;
    }

    function _calcDepletion( uint256 bal , uint256 multiplier , uint256 divisor ) internal pure returns( uint256 ){
        require(divisor > multiplier, "AetherToken: Depletion divisor is not set correctly");
        return ((bal*multiplier)/divisor);
    }

    function _depleteNode( address node , uint256 depletionAmount ) internal {
        _balances[node] -= depletionAmount;
        _balances[aetherKeeper()] += depletionAmount;
        emit NodeDepleted( node, depletionAmount );
    }

    function depleteNode(address node) external override(IAetherToken) onlyKeeper returns( bool ) {
        (uint256 _depMul, uint256 _depDiv) = ITracker( aetherDAO() ).depletionRatio();
        uint256 depAmount = _calcDepletion( balanceOf( node ) , _depMul, _depDiv );
        _depleteNode( node , depAmount );
        return true;
    }

    function _rewardNode( address node , uint256 rewardAmount ) internal {
        uint256 treasuryBal = _balances[aetherKeeper()];
        require(treasuryBal > rewardAmount, "AetherToken: Treasury cannot reward currently");
        _balances[aetherKeeper()] -= rewardAmount;
        _balances[node] += rewardAmount;
        emit NodeRewarded( node , rewardAmount );
    }

    function rewardNode( address node , uint256 rewardAmount ) external override(IAetherToken) onlyKeeper returns( bool )  {
        _rewardNode( node , rewardAmount );
        return true;
    }

    function transfer( address recipient , uint256 amount ) public override returns ( bool ) {
        _transfer(msg.sender, recipient, amount);
        return true;
    }

    function allowance( address owner , address spender ) public view override returns ( uint256 ) {

        return _allowances[owner][spender];
    }

    function approve( address spender , uint256 amount ) public override returns ( bool ) {
        _approve(msg.sender, spender, amount);
        return true;
    }

    function transferFrom( address sender , address recipient , uint256 amount ) public override returns ( bool ) {
        _transfer( sender , recipient , amount );
        uint256 currentAllowance = _allowances[sender][msg.sender];
        require(currentAllowance >= amount, "AetherToken: transfer amount exceeds allowance");
        unchecked {
            _approve( sender , msg.sender , currentAllowance - amount );
        }
        return true;
    }

    function addCollateral( address _from , uint256 _amount ) public override onlyKeeper {
        require( _balances[_from] > _amount , "Not enough collateral" );
        _balances[_from] -= _amount;
        _collateral[_from] += _amount;
    }

    function removeCollateral( address _from , uint256 _amount ) public override onlyKeeper {
        require( _collateral[_from] > _amount , "less collateral available" );
        _balances[_from] += _amount;
        _collateral[_from] -= _amount;
        if ( _collateral[_from] != 0 ){
            _balances[aetherKeeper()] += _collateral[_from];            
        }
        _collateral[_from] = 0;
    }

    function increaseAllowance( address spender , uint256 addedValue ) public returns ( bool ) {
        _approve( msg.sender , spender , _allowances[msg.sender][spender] + addedValue );
        return true;
    }

    function decreaseAllowance( address spender , uint256 subtractedValue ) public returns ( bool ) {
        uint256 currentAllowance = _allowances[msg.sender][spender];
        require(currentAllowance >= subtractedValue, "AetherToken: decreased allowance below zero");
        unchecked {
            _approve( msg.sender , spender , currentAllowance - subtractedValue );
        }

        return true;
    }

    function _transfer( address sender , address recipient , uint256 amount ) internal {
        require( sender != address( 0 ) , "AetherToken: transfer from the zero address" );
        require( recipient != address( 0 ) , "AetherToken: transfer to the zero address" );

        uint256 senderBalance = _balances[sender];
        require( senderBalance >= amount , "AetherToken: transfer amount exceeds balance" );
        unchecked {
            _balances[sender] = senderBalance - amount;
        }
        _balances[recipient] += amount;

        emit Transfer( sender , recipient , amount );
    }

    function _treasuryStake( address staker , address node ) internal {
        uint256 stakerBalance = _balances[staker];
        uint256 nodeStake = IMemberships( aetherDAO() ).nodeThreshold();

        require( stakerBalance > nodeStake , "AetherToken: Not enough balance to support a stake" );

        _balances[staker] -= nodeStake;
        _balances[node] += nodeStake;

        emit NodeStake( staker , node , nodeStake );        
    }

    function treasuryStake( address staker , address node ) external override onlyHUB returns( bool ) {
        _treasuryStake( staker , node );
        return true;
    }

    function _treasuryRelease( address node ) internal {
        address nodeOwner = IOwner( node ).owner();
        uint256 nodeStakedAmount = IAetherNode( node ).stakedAmount();

        uint256 nodeBalance = _balances[node];
        require(nodeBalance > nodeStakedAmount, "AetherToken: Not enough balance in the node to release");

        _balances[nodeOwner] += nodeStakedAmount;
        _balances[node] -= nodeStakedAmount;

        emit NodeRelease( nodeOwner , node , nodeStakedAmount );
    }

    function treasuryRelease( address node ) external override onlyHUB returns( bool ) {
        _treasuryRelease( node );
        return true;
    }

    function supplement( address node , uint256 amount ) external override onlyHUB returns ( bool ) {
        _transfer( node , IOwner( node ).owner() , amount );
        return true;
    }

    function mint( address account , uint256 amount ) public {

        _mint( account , amount );
    }

    function treasuryMint() public override onlyKeeper {
        uint256 amnt = _maxSupply - _totalSupply;
        amnt /= 100;
        amnt *= 5;
        _mint( aetherKeeper() , amnt );
    }

    function _mint( address account , uint256 amount ) internal {
        require( account != address( 0 ), "AetherToken: mint to the zero address" );

        _totalSupply += amount;
        _balances[account] += amount;
        emit Transfer( address( 0 ) , account , amount );
    }

    function _burn( address account , uint256 amount ) internal {
        require( account != address( 0 ) , "AetherToken: burn from the zero address" );

        uint256 accountBalance = _balances[account];
        require( accountBalance >= amount, "AetherToken: burn amount exceeds balance" );
        unchecked {
            _balances[account] = accountBalance - amount;
        }
        _totalSupply -= amount;

        emit Transfer( account , address( 0 ) , amount );
    }

    function _approve( address owner , address spender , uint256 amount ) internal {
        require( owner != address( 0 ) , "AetherToken: approve from the zero address" );
        require( spender != address( 0 ) , "AetherToken: approve to the zero address" );

        _allowances[owner][spender] = amount;
        emit Approval( owner , spender , amount );
    }
}
