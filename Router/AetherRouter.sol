//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;


import "./IAetherRouter.sol";

/**
 * 
 * @dev The router is essentially a ticket office for any 
 * deployment with 0xAether. 
 * 
 * Aether Couplings:
 * Router-Factory
 * DAO-0xA
 * HUB-Nodes
 * Treasury-Bonds
 * 
 */
contract AetherRouter is IAetherRouter {

    address private _aetherROUTER;
    bytes32 private ROUTER_PERMITTED_HASH;

    address private _aetherFACTORY;
    bytes32 private FACTORY_PERMITTED_HASH;

    address private _aetherDAO;
    bytes32 private DAO_PERMITTED_HASH;

    address private _aetherTOKEN;
    bytes32 private TOKEN_PERMITTED_HASH;

    address private _aetherHUB;
    bytes32 private HUB_PERMITTED_HASH;

    address private _aetherKEEPER;
    bytes32 private KEEPER_PERMITTED_HASH;

    address private _aetherBONDS;
    bytes32 private BONDS_PERMITTED_HASH;
    
    string internal constant UNKOWN_ACONTRACTID = "AetherRouter :: Unknown ACID";
    string internal constant DORF_ACONTRACTID = "AetherRouter :: Only DAO or factory";
    string internal constant NOTSET_ACONTRACTID = "AetherRouter :: Not Set";
    string internal constant CHNP_ACONTRACTID = "AetherRouter :: Deployed codehash is not permitted";

    constructor() {
        _aetherFACTORY = msg.sender;
        _aetherROUTER = address( this );
    }


    function _getAetherAddress( uint256 _acId ) internal view returns( address ){
        if( _acId == uint256( AContractID.ARouter ) ){
            return _aetherROUTER;
        }else if ( _acId == uint256( AContractID.AFactory ) ){
            return _aetherFACTORY;
        }else if ( _acId == uint256( AContractID.ADAO ) ) {
            return _aetherDAO;
        }else if ( _acId == uint256( AContractID.AToken ) ) { 
            return _aetherTOKEN;
        }else if ( _acId == uint256( AContractID.AHUB ) ) {
            return _aetherHUB;
        }else if ( _acId == uint256( AContractID.AKeeper ) ) {
            return _aetherKEEPER;
        }else if ( _acId == uint256( AContractID.ABonds ) ) {
            return _aetherBONDS;
        }else{
            revert(UNKOWN_ACONTRACTID);
        }
    }

    function _getPermittedHash( uint256 _acId ) internal view returns( bytes32 ) {
        if( _acId == uint256( AContractID.ARouter ) ){
            return ROUTER_PERMITTED_HASH;
        }else if ( _acId == uint256( AContractID.AFactory ) ){
            return FACTORY_PERMITTED_HASH;
        }else if ( _acId == uint256( AContractID.ADAO ) ) {
            return DAO_PERMITTED_HASH;
        }else if ( _acId == uint256( AContractID.AToken ) ) { 
            return TOKEN_PERMITTED_HASH;
        }else if ( _acId == uint256( AContractID.AHUB ) ) {
            return HUB_PERMITTED_HASH;
        }else if ( _acId == uint256( AContractID.AKeeper ) ) {
            return KEEPER_PERMITTED_HASH;
        }else if ( _acId == uint256( AContractID.ABonds ) ) {
            return BONDS_PERMITTED_HASH;
        }else{
            revert(UNKOWN_ACONTRACTID);
        }
    }

    function _setAetherPermittedHash( uint256 _acId , bytes32 _pHash) internal {
        if( _acId == uint256( AContractID.ARouter ) ){
            ROUTER_PERMITTED_HASH = _pHash;
        }else if ( _acId == uint256( AContractID.AFactory ) ){
            FACTORY_PERMITTED_HASH = _pHash;
        }else if ( _acId == uint256( AContractID.ADAO ) ) {
            DAO_PERMITTED_HASH = _pHash;
        }else if ( _acId == uint256( AContractID.AToken ) ) { 
            TOKEN_PERMITTED_HASH = _pHash;
        }else if ( _acId == uint256( AContractID.AHUB ) ) {
            HUB_PERMITTED_HASH = _pHash;
        }else if ( _acId == uint256( AContractID.AKeeper ) ) {
            KEEPER_PERMITTED_HASH = _pHash;
        }else if ( _acId == uint256( AContractID.ABonds ) ) {
            BONDS_PERMITTED_HASH = _pHash;
        }else{
            revert(UNKOWN_ACONTRACTID);
        }
    }

    function _setAetherContractAddr( uint256 _acId , address _addr) internal {
        if( _acId == uint256( AContractID.ARouter ) ){
            _aetherROUTER = _addr;
        }else if ( _acId == uint256( AContractID.AFactory ) ){
            _aetherFACTORY = _addr;
        }else if ( _acId == uint256( AContractID.ADAO ) ) {
            _aetherDAO = _addr;
        }else if ( _acId == uint256( AContractID.AToken ) ) { 
            _aetherTOKEN = _addr;
        }else if ( _acId == uint256( AContractID.AHUB ) ) {
            _aetherHUB = _addr;
        }else if ( _acId == uint256( AContractID.AKeeper ) ) {
            _aetherKEEPER = _addr;
        }else if ( _acId == uint256( AContractID.ABonds ) ) {
            _aetherBONDS = _addr;
        }else{
            revert(UNKOWN_ACONTRACTID);
        }
    }

    function getPermittedHash( uint256 acId ) external override view returns( bytes32 PHash ){
        PHash =  _getPermittedHash( acId );
        require( PHash != bytes32( 0 ) , NOTSET_ACONTRACTID );
    }

    function setPermittedHash( uint256 acId , bytes32 permittedHash ) public override {
       require( msg.sender == _aetherDAO || msg.sender == _aetherFACTORY , DORF_ACONTRACTID );
       _setAetherPermittedHash( acId , permittedHash );
    }

    function getAetherAddress( uint256 acId ) public view override returns( address AAddress ){
        AAddress = _getAetherAddress( acId );
        require( AAddress != address( 0 ) , NOTSET_ACONTRACTID );
    }

    modifier FACTORYorDAO() {
        require( 
            _getAetherAddress( uint256( AContractID.AFactory ) ) == msg.sender 
                                        ||
            _getAetherAddress( uint256( AContractID.ADAO ) ) == msg.sender
            , "OnlyDAO or Factory" );
        _;
    }

    function setAetherAddress( uint256 aCID , address addr ) public override FACTORYorDAO returns( bool ) {
        _setAetherContractAddr( aCID , addr );
        return true;
    }

    function _fallback() internal {
        assembly {
            let addr := sload(_aetherROUTER.slot)
            let ptr := mload(0x40)
            // (1) copy incoming call data
            calldatacopy(ptr, 0, calldatasize())
            // (2) forward call to logic contract
            let result := delegatecall(not(0), addr, ptr, calldatasize(), 0, 0)
            let size := returndatasize()
            // (3) retrieve return data
            returndatacopy(ptr, 0, size)
            // (4) forward return data back to caller
            switch result
            case 0 { revert(ptr, size) }
            default { return(ptr, size) }
        }
    }

    modifier proxyCheck() {
        require( _aetherROUTER != address( this ) && _aetherROUTER != address( 0 ) );
        _;
    }

    fallback() external proxyCheck {

       _fallback();
    }

    receive() external payable {

       require( payable( getAetherAddress( uint256( AContractID.AKeeper ) ) ).send( msg.value ) );
    }
}

