//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "./IAetherCtx.sol";
import "../Common/IAetherCall.sol";
import "../Common/IRouterCall.sol";
/**
 * 
 * AetherCtx identifies wich version of 0xAether is being coupled to.
 * 
 * The original are defined in `IAetherCtx` as view functions consuming x gas,
 * consisting of Router,Factory,DAO,Token,Hub,Node,Treasury,Bonds
 * Moreover, using `aetherID()` we can track and verify via the index of the 
 * factory, not only on aether contracts, but also on any contract deployed with 0xA.
 * 
 * 
 * 
 * every deployed contract with 0xA needs to have a synced ID between the router
 * and the factory.
 *  
 */




contract AetherCtx is IAetherCtx {

	uint256 private _id;
	address internal _aetherRouter;

	bool private _in;
    modifier singular() {
    	require( !_in );
    	_in = true;
    	_;
    	require( _in );
    	_in = false;
    }

    bool private _exec;



    /***************************************** Address Modifiers **********************************************/
	modifier onlyFactory() virtual {
		require( msg.sender == aetherFactory() , "OnlyFactory" );
		_;
	}

    modifier onlyDAO() {
    	require( msg.sender == aetherDAO() , "OnlyDAO" );
    	_;
    }

    modifier onlyRouter() {
    	require( msg.sender == aetherRouter() , "OnlyRouter" );
    	_;
    }

    modifier onlyHUB() {
    	require( msg.sender == aetherHUB() , "OnlyHUB" );
    	_;
    }

    modifier onlyKeeper() {
    	require( msg.sender == aetherKeeper() , "OnlyKeeper" );
    	_;
    }

    modifier onlySelf() {
    	require( msg.sender == address( this ) , "OnlySelf" );
    	_;
    }

	/***************************************** Aether Contracts **********************************************/

	function aetherID() public view override returns( uint256 ) {

		return _id;
	}

	modifier NSV() {
		require( msg.sender != address( this ) , "recussion view" );
		_;
	}
    /**
     * 
     * @dev we can utilize a single stop recurssion point ^.
     * 
     */
	function aetherRouter() public view override NSV returns( address ) {

		return _getRoute( uint256( AContractID.ARouter ) );
	}

	function aetherBonds() public view override NSV returns( address ) {

		return _getRoute( uint256( AContractID.ABonds ) );
	}

	function aetherFactory() public view override NSV returns( address ) {

		return _getRoute( uint256( AContractID.AFactory ) );
	}

	function aetherDAO() public view override NSV returns( address ) {

        return _getRoute( uint256( AContractID.ADAO ) );
    }

    function aetherToken() public view override NSV returns( address ) {

        return _getRoute( uint256( AContractID.AToken ) );
    }

    function aetherHUB() public view override NSV returns( address ) {

        return _getRoute( uint256( AContractID.AHUB ) );
    }

    function aetherKeeper() public view override NSV returns( address ) {

        return _getRoute( uint256( AContractID.AKeeper ) );
    }

    function getAetherAddress( uint256 contractId ) public virtual view NSV returns( address contractAddress ) {

    	return _getRoute( contractId );
    }

	function _getRoute( uint256 acId ) private view returns( address ) {
		try IRouterCall( _aetherRouter ).getAetherAddress( acId ) returns( address _proxiedAddress ) {
			return _proxiedAddress;
		} catch ( bytes memory ) {
			if ( acId == 0 ){
				return _aetherRouter;
			}else{
				revert( "Aether Contract ID Not Routed" );
			}
		}
	}

	function initialize( uint256 _acid_ , address _router_ ) internal virtual returns( bool ) {

		return _setId( _acid_ ) && _setRouter( _router_ );
	}

	function _setId( uint256 _acId ) internal returns( bool ) {
		require( _id == 0 && _acId != 0 , "Id already set" );
		_id = _acId;		
		return true;
	}

	function _setRouter( address _addr ) internal returns( bool ) {
		require( _addr != address( 0 ) && _aetherRouter == address( 0 ) , "Router already set" );
		_aetherRouter = _addr;
		return true;
	}

    function _deploy( uint256 _acid , bytes memory _cc ) internal returns( address addr ) {
    	
    	bytes32 _salt = keccak256( abi.encodePacked( address( this ) , bytes2( 0xa314 ) , _acid ) );
        require( _cc.length > 0 , "CreationCode min len is not zero" );
        assembly {
            addr := create2( 0 , add(_cc, 0x20) , mload(_cc) , _salt )
        }
        require( addr != address( 0 ) , "deployment failed" );
        return addr;
    }

	// using a multichain function
	function aetherMulti( uint256 _gas , bytes4 _selector , bytes memory _data ) internal returns( bool ) {

		// gas saving _getRoute( AContractID.AHUB )
		// but it's a little cooler this way.

		return IAetherCall( aetherHUB() ).tempSubmitTxn(
			_gas , // 0xA gas ,
			msg.sender , // caller to be submited to next chain
			_selector , // the function requested selector
			_data // the data to be sent with the request
		);
	}

	// using a crosschain function
	function aetherCross( uint256 _gas , uint256[] memory _cids , bytes4[] memory _selectors , bytes[] memory _data ) internal returns( bool ) {

		return IAetherCall( aetherHUB() ).submitTransaction(
			_gas ,
			msg.sender , 
			_cids , 
			_selectors ,
			_data
		);
	}



}