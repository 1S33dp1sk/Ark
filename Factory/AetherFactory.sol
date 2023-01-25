//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;



import "../Router/AetherRouter.sol";
import "../Context/AetherCtx.sol";
import "../Keeper/IKeeperAether.sol";
import "../Proxy/AetherProxy.sol";
import "../Node/AetherNode.sol";
import "./IAetherFactory.sol";

contract AetherFactory is AetherCtx, IAetherFactory {
 
    uint256 private nIndex = 1;

    uint256 private cIndex = 1;

    mapping( address => bool ) _factoryDeployments;

    mapping( uint256 => address ) _proxies;

    bool private AETHER_SETUP;


    constructor() {
        _factoryDeployments[address( this )] = true;
        _aetherRouter = _deploy( uint256( AContractID.ARouter ) , type(AetherRouter).creationCode );
        _factoryDeployments[_aetherRouter] = true;
    }

    modifier redeemTicket( uint256 ticket_id ) {
        if( ticket_id >= 2 && ticket_id <= 7 ) {
            _;
        }
        else{
            require( IKeeperAether( aetherKeeper() ).ticketOwner( ticket_id ) == msg.sender , "ticket owner only can redeem" );
            _;
            require( IKeeperAether( aetherKeeper() ).ticketOwner( ticket_id ) == address( 0 ) );
        }
    }

    function aetherSetup() external override {
        require( !AETHER_SETUP , "AetherFactory :: Already setup" );

        IKeeperAether( aetherKeeper() ).aetherSetup();
        AETHER_SETUP = true;
    }

    function setupAether() external override returns( bool ) {
        require( cIndex == 6 );

        return aetherMulti(
            1 gwei ,
            IAetherFactory.aetherSetup.selector ,
            new bytes(0)
        );
    }

    function getDeploymentAddress( uint256 _cIdx ) public view returns( address ) {

        return _proxies[_cIdx];
    }

    function _factoryInit( bytes32 _salt , bytes memory _cc ) internal returns( address addr ) {
        assembly {
            addr := create2( 0 , add(_cc, 0x20) , mload(_cc) , _salt )
        }
        require( addr != address( 0 ) , "Address 0" );
        return addr;
    }

    function _initBytes( uint256 _cid , address _addr , bytes memory _cCode ) internal returns( bool ) {

        return( IAetherProxy( _addr ).initialize( _cid , _aetherRouter , _cCode , true ) );
    }

    function _initAddress( uint256 _cid , address _addr , address _to , bool _delegation ) internal returns( bool ) {

        return( IAetherProxy( _addr ).initialize( _cid , _aetherRouter , _to , _delegation ) );
    }

    function _getACType( address _addr ) internal view returns( bool ) {

        return _factoryDeployments[_addr];
    }

    function deployNode() external override returns( address addr ) {
        bytes memory cc_ = type(AetherNode).creationCode;
        bytes32 salt_ = keccak256( abi.encodePacked( address( this ) , bytes2( 0x413a ) , nIndex ) );
        addr = _factoryInit( salt_ , cc_ );
        _factoryDeployments[addr] = true;
        nIndex += 1;
    }

    function deployProxy( address proxyTo , uint256 ticketId ) public override redeemTicket( ticketId ) returns( address addr ) {
        bytes memory cc_ = type(AetherProxy).creationCode;
        // uint256 ticket_id = IKeeperAether( aetherKeeper() ).getTicketMagic( ticketId );
        bytes32 salt_ = keccak256( abi.encodePacked( address( this ) , bytes2( 0xa314 ) , ticketId ) );
        addr = _factoryInit( salt_ , cc_ );
        if ( ticketId == 4 ) {
            require( _initAddress( ticketId , addr , proxyTo , true ) , "Cannot Initalize address" );
            _setRoute( proxyTo , ticketId );
            _factoryDeployments[proxyTo] = true;
        }
        else{
            require( _initAddress( ticketId , addr , proxyTo , false ) , "Cannot Initalize address" );
            _setRoute( addr , ticketId );
            _factoryDeployments[addr] = true;
        }
        _proxies[cIndex] = addr;
        cIndex += 1;
        emit ProxyDeployed( addr , proxyTo , ticketId );
    }

    function deployContract( bytes memory cCode , uint256 ticketId ) public override redeemTicket( ticketId ) returns( address addr ) {
        bytes memory cc_ = type(AetherProxy).creationCode;
        bytes32 salt_ = keccak256( abi.encodePacked( address( this ) , bytes2( 0xa314 ) , ticketId ) );
        addr = _factoryInit( salt_ , cc_ );
        _initBytes( ticketId , addr , cCode );
        // require(  , "Cannot Initalize bytes" );
        _factoryDeployments[addr] = true;
        _proxies[cIndex] = addr;
        _setRoute( addr , cIndex );
        cIndex += 1;
    }


    function _setRoute( address _acAddress , uint256 _acID ) internal returns( bool ) {
        try IAetherRouter( _aetherRouter ).setAetherAddress( _acID , _acAddress ) returns( bool _addrSET ) {
            return _addrSET;
        } catch ( bytes memory ) {
            revert( "Aether Contract cannot be routed to" );
        }
    }



    function factoryIsNode( address addr ) external view override returns( bool ) {

        return _getACType( addr );
    }

    function factoryIsProxy( address addr ) external view override returns( bool ) {

        return _getACType( addr );
    }

    function nodesDeployed() external view override returns( uint256 ) {

        return nIndex;
    }

    function contractsDeployed() external view override returns( uint256 ) {

        return cIndex;
    }
}






