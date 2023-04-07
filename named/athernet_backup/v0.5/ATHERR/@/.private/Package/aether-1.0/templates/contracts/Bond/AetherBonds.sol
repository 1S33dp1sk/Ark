//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

/*
                    The 0xAether 
                    
FOR VALUE RECIEVED PROMISES TO PAY TO THE HODLER THE SUM OF 
                ONE HUNDRED THOUSAND


ON OR AFTER THE DUE DATE, AND TO PAY INTEREST ON THE PRINCIPAL SUM FROM THE DATE HEREOF, AT THE RATE SPECIFIED HEREIN. 
THIS BOND AND NODES ARE PAYABLE AT THE 0XAETHER TREASURY ON ANY AND ALL OF THE SUPPORTED CHAINIDS. 
THIS BOND IS ONE OF A SERIES OF 100 TOTAL BONDS, MINTED, PROTECTED AND AUTHORIZED BY THE 0XAETHER KEEPER AND THE PREPUTUAL LOGIC THE 0XAETHER DAO INSINUATES.
AS AMENDED, ISSUED PURSUANT TO THE ABSOLUTE DILUTED VALUE IN 0XAETHER TREASURY RESERVES. 
ALL OR ANY OF NON-FRACTIONAL BONDS CAN BE DEFAULTED OR SOLD, AT THE OPTION OF ANY CHAINID ON THE DATE `MATRUITY()`, AT PAR AND ACCRUED INTRESET OF `INTREST()` 
ON ANY TRANSACTION OR TRANSACTIONS THAT HAVE BEEN PROCESSED BY THE 0XAETHER HUB. IN THE CASE OF DEFAULT OR SALE, 
THE BOND RIGHTFUL OWNER WILL BE THAT OF 0XAETHER KEEPER, AFTER THE DESIGNATED VALUE HAS BEEN GRANTED TO THE ORIGINAL RIGHTFUL OWNER.
THE INCOME DERIVED FROM THE VALUE OF THE BOND AT THE TIME OF THE ACTION IS SUBJECT TO CHANGE AND IS COMPLETLEY DEPENDENT ON THE 
STATE OF THE RESERVES DERIVED BY THE 0XAETHER TREASURY. THIS BOND CAN BE TRANSFERED, SOLD, GIFTED WITH THE EXEMPT OF NON-MINTED BONDS 
AT THE SOLE DISCRETION OF THE RIGHTFUL OWNER REGARDLESS OF PERSON OR PERSONS, PROTOCOL OR OTHERWISE. 

0XAETHER, JULY 6TH 2022.
*/

import "../Context/AetherCtx.sol";
import "./IAetherBonds.sol";

interface IERC721Receiver {

    function onERC721Received(address,address,uint256,bytes calldata) external returns (bytes4);
}

contract AetherBonds is AetherCtx, IAetherBonds {

    uint256 private mintIdx = 1;

    uint256 private constant _maxSupply = 100;

    string private constant _name = "0xAetherBonds";

    string private constant _symbol = "0xABonds";

    string private _baseUrl = "https://aether.guru/bonds/";

    mapping( uint256 => address ) private _owners;

    mapping( address => uint256 ) private _balances;

    mapping( uint256 => address ) private _tokenApprovals;

    mapping( uint256 => uint256[] ) private _bonds;

    mapping( address => mapping( address => bool ) ) private _operatorApprovals;


    function changeBaseURL( string memory _nBaseUrl ) public onlyDAO {

    	_baseUrl = _nBaseUrl;
    }

    function totalSupply() external view override returns( uint256 ) {

    	return mintIdx;
    }

    function maxSupply() external pure override returns( uint256 ) {

    	return _maxSupply;
    }

    function name() public pure override returns (string memory) {
     
        return _name;
    }

    function symbol() public pure override returns (string memory) {
      
        return _symbol;
    }

    function supportsInterface( bytes4 interfaceId ) public pure override returns ( bool ) {

        return interfaceId == type(IAetherBonds).interfaceId;
    }

    function balanceOf( address owner ) public view override returns ( uint256 ) {
        require(owner != address(0), "ERC721: balance query for the zero address");
        return _balances[owner];
    }

    function ownerOf( uint256 bond_id ) public view override returns ( address ) {
        address owner = _owners[bond_id];
        require(owner != address(0), "ERC721: owner query for nonexistent token");
        return owner;
    }

    function tokenURI( uint256 bond_id ) public view virtual override returns ( string memory ) {
        require( _exists( bond_id ), "ERC721Metadata: URI query for nonexistent token" );
        return string( abi.encodePacked( _baseUrl, toString( bond_id ) ) );
    }

    function issueBond( address to ) external override onlyKeeper returns( uint256 ) {
        require( mintIdx <= _maxSupply );
        _mint( to );
        return( mintIdx );
    }

    function defaultBond( address bond_owner , uint256 bond_id ) external onlyKeeper returns( bool ) {
    	require( ownerOf( bond_id ) == bond_owner, "AetherBonds :: can only default owned bonds" );
    	_approve( address(0) , bond_id );
        address _keeper = aetherKeeper();
        _balances[bond_owner] -= 1;
        _balances[_keeper] += 1;
        _owners[bond_id] = _keeper;
        return true;
    }

    function combineBonds( uint256[] memory bond_ids ) external onlyKeeper returns( bool ) {
    	uint256 _totalBondsC = bond_ids.length;
    	require( _totalBondsC > 1 );
    	uint256 _mainBondId = bond_ids[0];
    	address _mainBondOwner = ownerOf( bond_ids[0] );
    	for( uint256 i=0; i<bond_ids.length; i++ ) {
    		require( ownerOf( bond_ids[i] ) == _mainBondOwner );
    		_owners[bond_ids[i]] = address( 0 );
    		delete _bonds[bond_ids[i]];
    	}
    	_balances[_mainBondOwner] -= ( _totalBondsC - 1 );
    	_bonds[_mainBondId] = bond_ids;
        return true;
    }

    function singular256Array( uint256 _in ) public pure returns( uint256[] memory _out ) {
    	_out = new uint256[](1);
    	_out[0] = _in;
    }

    function splitBonds( uint256 bond_id ) external onlyKeeper returns( bool ) {
    	uint256[] memory bondsOwned = _bonds[bond_id];
    	uint256 _totalBondsC = bondsOwned.length;
    	address _bondOwner = ownerOf( bond_id );
    	for( uint256 i=0; i<_totalBondsC; i++ ){
    		_owners[bondsOwned[i]] = _bondOwner;
    		_bonds[bondsOwned[i]] = singular256Array( bondsOwned[i] );
    	}
    	_balances[_bondOwner] += _totalBondsC;
    	_bonds[bond_id] = singular256Array( bond_id );
    	return true;
    }

    function idsOfBond( uint256 bond_id ) external view override returns( uint256[] memory _bondIds ) {
	    	
	    return _bonds[bond_id];
    }

    function approve( address to , uint256 bond_id ) public virtual override {
        address owner = ownerOf(bond_id);
        require(to != owner, "ERC721: approval to current owner");

        require(
            msg.sender == owner || isApprovedForAll(owner, msg.sender),
            "ERC721: approve caller is not owner nor approved for all"
        );

        _approve(to, bond_id);
    }

    function getApproved( uint256 bond_id ) public view virtual override returns ( address ) {
        require(_exists(bond_id), "ERC721: approved query for nonexistent token");

        return _tokenApprovals[bond_id];
    }

    function setApprovalForAll( address operator , bool approved ) public virtual override {
        require(operator != msg.sender, "ERC721: approve to caller");

        _operatorApprovals[msg.sender][operator] = approved;
        emit ApprovalForAll(msg.sender, operator, approved);
    }

    function isApprovedForAll( address owner , address operator ) public view virtual override returns ( bool ) {

        return _operatorApprovals[owner][operator];
    }

    function transferFrom( address from , address to , uint256 bond_id ) public virtual override {
        //solhint-disable-next-line max-line-length
        require(_isApprovedOrOwner(msg.sender, bond_id), "ERC721: transfer caller is not owner nor approved");

        _transfer(from, to, bond_id);
    }

    function safeTransferFrom( address from , address to , uint256 bond_id ) public virtual override {

        safeTransferFrom(from, to, bond_id, "");
    }

    function safeTransferFrom( address from , address to , uint256 bond_id , bytes memory _data ) public virtual override {
        require(_isApprovedOrOwner(msg.sender, bond_id), "ERC721: transfer caller is not owner nor approved");
        _safeTransfer(from, to, bond_id, _data);
    }

    function _safeTransfer( address from , address to , uint256 bond_id , bytes memory _data ) internal virtual {
        _transfer(from, to, bond_id);
        require(_checkOnERC721Received(from, to, bond_id, _data), "ERC721: transfer to non ERC721Receiver implementer");
    }

    function _exists( uint256 bond_id ) internal view virtual returns ( bool ) {

        return _owners[bond_id] != address(0);
    }

    function _isApprovedOrOwner( address spender , uint256 bond_id ) internal view virtual returns ( bool ) {
        require(_exists(bond_id), "ERC721: operator query for nonexistent token");
        address owner = ownerOf(bond_id);
        return (spender == owner || getApproved(bond_id) == spender || isApprovedForAll(owner, spender));
    }

    function _isOwned( uint256 _bond_id ) internal view returns( bool ) {
    	address owner = ownerOf( _bond_id );
		return ( owner != address(0) && owner != address( this ) && owner != aetherKeeper() );    	
    }

    function _mint( address to ) internal virtual {
        require(!_exists( mintIdx ), "ERC721: token already minted");

        _balances[to] += 1;
        _owners[mintIdx] = to;

        uint256[] memory aBondIds = new uint256[](1);
        aBondIds[0] = mintIdx;
        _bonds[mintIdx] = aBondIds; 

        mintIdx += 1;
        emit Transfer(address(0), to, mintIdx);
    }

    function _burn( uint256 bond_id ) internal virtual {
        address owner = ownerOf(bond_id);

        _approve(address(0), bond_id);

        _balances[owner] -= 1;
        delete _owners[bond_id];

        emit Transfer(owner, address(0), bond_id);
    }

    function _transfer( address from , address to , uint256 bond_id ) internal virtual {
        require(ownerOf(bond_id) == from, "ERC721: transfer of token that is not own");
        require(to != address(0), "ERC721: transfer to the zero address");

        // Clear approvals from the previous owner
        _approve(address(0), bond_id);

        _balances[from] -= 1;
        _balances[to] += 1;
        _owners[bond_id] = to;

        emit Transfer(from, to, bond_id);
    }

    function _approve( address to , uint256 bond_id ) internal virtual {
        _tokenApprovals[bond_id] = to;
        emit Approval(ownerOf(bond_id), to, bond_id);
    }

    function toString(uint256 value) internal pure returns (string memory) {
        // Inspired by OraclizeAPI's implementation - MIT licence
        // https://github.com/oraclize/ethereum-api/blob/b42146b063c7d6ee1358846c198246239e9360e8/oraclizeAPI_0.4.25.sol

        if (value == 0) {
            return "0";
        }
        uint256 temp = value;
        uint256 digits;
        while (temp != 0) {
            digits++;
            temp /= 10;
        }
        bytes memory buffer = new bytes(digits);
        while (value != 0) {
            digits -= 1;
            buffer[digits] = bytes1(uint8(48 + uint256(value % 10)));
            value /= 10;
        }
        return string(buffer);
    }

    function isContract(address account) internal view returns (bool) {
        // This method relies on extcodesize, which returns 0 for contracts in
        // construction, since the code is only stored at the end of the
        // constructor execution.

        uint256 size;
        assembly {
            size := extcodesize(account)
        }
        return size > 0;
    }

    function _checkOnERC721Received( address from , address to , uint256 bond_id , bytes memory _data ) private returns ( bool ) {
        if (isContract(to)) {
            try IERC721Receiver(to).onERC721Received(msg.sender, from, bond_id, _data) returns (bytes4 retval) {
                return retval == IERC721Receiver.onERC721Received.selector;
            } catch (bytes memory reason) {
                if (reason.length == 0) {
                    revert("ERC721: transfer to non ERC721Receiver implementer");
                } else {
                    assembly {
                        revert(add(32, reason), mload(reason))
                    }
                }
            }
        } else {
            return true;
        }
    }

}