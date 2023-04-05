//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;


import "./IAccess.sol";
import "../../Context/IAetherCtx.sol";

contract Access is IAccess {

	mapping( address => bool ) internal _access;
	address internal OWNER;
	bool internal SET;
	
	address public immutable AETHER_HUB;
	address public immutable AETHER_FACTORY;
	
	function owner() public view override returns( address ) {

		return OWNER == address( 0 ) ? AETHER_FACTORY : OWNER;
	}

	constructor() {
		AETHER_FACTORY = msg.sender;
		AETHER_HUB = IAetherCtx( msg.sender ).aetherHUB();
	}

	modifier callAccess() {
		require( !SET );
		// require( _access[ msg.sender ] , "Only allowed addresses can access node calls" );
		SET = true;
		_;
		SET = false;
	}

	modifier onlyFactory() {
		require( msg.sender == AETHER_FACTORY );
		_;
	}

	modifier onlyOwner() {
		require( msg.sender == OWNER );
		_;
	}

	function setOwner( address nodeOwner ) public override onlyFactory {
		require( OWNER == address( 0 ) );
		OWNER = nodeOwner;
		_access[ nodeOwner ] = true;
		emit NodeInitialized( address( this ) , nodeOwner );
	}

	function addAccess( address addr ) public override onlyOwner returns( bool ) { 
		_access[ addr ] = true;
		emit AccessGranted( address( this ) , addr );
		return true;

	}

	function revokeAccess( address addr ) public override onlyOwner returns( bool ) {
		_access[ addr ] = false;
		emit AccessRevoked( address( this ) , addr );
		return true;
	}
}

