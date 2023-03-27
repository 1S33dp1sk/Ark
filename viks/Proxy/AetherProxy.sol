//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "../Context/AetherCtx.sol";
import "./IAetherProxy.sol";
import "../Libraries/StorageSlot.sol";

contract AetherProxy is AetherCtx, IAetherProxy {

	bytes32 internal constant _IMPLEMENTATION_SLOT = 0x360894a13ba1a3210667c828492db98dca3e2076cc3735a920a3ca505d382bbc;
	bytes32 internal constant _DELEGATION_SLOT = 0x3b8036aab80a296c0614759d7eb58cce8015b9c568a8cba1d3aab585b6f07ec0;
	bytes32 internal constant _ADMIN_SLOT = 0xb53127684a568b3173ae13b9f8a6016e243e63b6e8ee1178d6a717850b5d6103;
	uint256 internal constant PROXY_TYPE = 1;



	function _getImplementation() internal view returns( address ) {

		return StorageSlot.getAddressSlot(_IMPLEMENTATION_SLOT).value;
	}

	function _getAdmin() internal view returns( address ) {

		return StorageSlot.getAddressSlot(_ADMIN_SLOT).value;
	}

	function proxyType() external pure override returns( uint256 ) {

		return PROXY_TYPE;
	}

	function implementation() external view override returns( address ) {

		return _getImplementation();
	}

	function _getDelegation() internal view returns( bool ) {

		return StorageSlot.getBooleanSlot(_DELEGATION_SLOT).value;
	}

	constructor() { 
		assert( _IMPLEMENTATION_SLOT == bytes32( uint256( keccak256( "eip1967.proxy.implementation" ) ) - 1 ) );
		StorageSlot.getAddressSlot(_ADMIN_SLOT).value = msg.sender;
	}
	
	modifier onlyFactory() override {
		require( msg.sender == _getAdmin() ); 
		_; 
	}

	function initialize( uint256 _acid_ , address _router_ , address _proxy_ , bool _delegate_ ) public override onlyFactory returns( bool ) {
		if( _getImplementation() == address( 0 ) && _router_ != address( 0 ) && _proxy_ != address( 0 ) ){
			StorageSlot.getAddressSlot(_IMPLEMENTATION_SLOT).value = _proxy_;
			StorageSlot.getBooleanSlot(_DELEGATION_SLOT).value = _delegate_; // Nej
			return super.initialize( _acid_ , _router_ );
		}
		return false;
	}

	function initialize( uint256 _acid_ , address _router_ , bytes memory _contract_ , bool _delegate_ ) public override onlyFactory returns( bool ) {
		if( _getImplementation() == address( 0 ) && _router_ != address( 0 ) && _contract_.length > 0 ){
			address _impl = _deploy( _acid_ , _contract_ );
			StorageSlot.getAddressSlot(_IMPLEMENTATION_SLOT).value = _impl;
			StorageSlot.getBooleanSlot(_DELEGATION_SLOT).value = _delegate_; // Ja
			return super.initialize( _acid_ , _router_ );
		}
		return false;
	}

	/**
	 * !!NOTICE!!
	 * 
	 * test `msg.sender` when hub starts calling
	 *
	 */

    function _fallback() internal {
    	address addr = _getImplementation();
    	bool delegate = !_getDelegation();
        assembly {
            let ptr := mload(0x40)
            // (1) copy incoming call data
            calldatacopy(ptr, 0, calldatasize())
            // result
            let result
            // (2) forward call to logic contract
            switch delegate
            case 0 { result := call(not(0), addr, callvalue(), ptr, calldatasize(), 0, 0) }
            default { result := delegatecall(not(0), addr, ptr, calldatasize(), 0, 0) }
            // let result := delegatecall(not(0), addr, ptr, calldatasize(), 0, 0)
            let size := returndatasize()
            // (3) retrieve return data
            returndatacopy(ptr, 0, size)
            // (4) forward return data back to caller
            switch result
            case 0 { revert(ptr, size) }
            default { return(ptr, size) }
        }
    }

    fallback() external payable {

       _fallback();
    }

    receive() external payable {

        require( payable( _getImplementation() ).send( msg.value ) );
    }
}




/**

I Am documenting this because it's very tricky, once it's completley configured, it will be much easier as a fork. 

The initial idea was to follow one full path with the AetherRouter, i.e: deploy all contracts within the same txn.

Obviously, due to the size of the contracts and due to redDragon limit. The deployment takes a slightly different structure

here. 

The Router deploys the factory. The factory then in turn deploys 6 different proxies that will be used as DAO,Token,Hub,Nodes,Treasury,Bonds.

The amount of proxies is irrelevant here. Different projects might use any arbitrary number on the initial amount of proxies. This is ofcourse, 

not random, but rather an actual number of the contracts need for the project.


In a general view, we need 0xAether to deploy 0xAether. So we divide 0xAether into 4 main parts and then we link the parts according to the strucuture configured
in this documentation, once we have the fully linked chain of contracts we cement it by verifying the `extcodehash(address...)` after the constructor has been called.


**/
