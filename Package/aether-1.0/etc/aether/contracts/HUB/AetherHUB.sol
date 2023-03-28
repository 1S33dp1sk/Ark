//SPDX-License-Identifier: GPL v3
pragma solidity ^0.8.0;

import "../DAO/Vars/IVars.sol";
import "../Context/AetherCtx.sol";
import "./IAetherHUB.sol";

contract AetherHUB is AetherCtx, IAetherHUB {

	mapping( bytes16 => AetherTxn ) internal aether_transactions;
	mapping( bytes16 => bool ) internal _results;
	mapping( uint256 => AetherBlock ) internal aether_blocks;
	mapping( address => uint256[] ) private addr_cids;
	mapping( bytes32 => address[] ) private _submittedMH;
	mapping( address => uint256 ) private _nonces;

	address[] private _nodesRegistered;

	bytes16[] private _acceptedTxns;
	bytes32[] private _submissions;

	uint256[] private _aetheringChains;

	uint256 private _nodeRegisteryPtr;
	uint256 private _nativeBlockNum;
	uint256 private _aetherBlockNum;
	uint256 private _lastAChange;



	constructor() {
		_aetheringChains = new uint256[](2);
		_aetheringChains[0] = 1234;
		_aetheringChains[1] = 4321;
		bytes32 INIT_HASH = keccak256( abi.encodePacked( msg.sender , address( this ) , bytes2( 0xa314 ) ) );
		AetherBlock memory _genesis = AetherBlock( INIT_HASH , 0 , _aetheringAddress( address( this ) , 0 ) );
		_voteOnMasterHash( INIT_HASH );
		_bindBlock( new bytes16[](0) , _genesis );
	}

	function _aetheringAddress( address callerAddr , uint256 callerNonce ) internal pure returns( bytes20 ) {

		return bytes20( keccak256( abi.encodePacked( callerAddr , callerNonce ) ) );
	}

    function _arrayMemeberU256( uint256[] memory _arr , uint256 _mem ) internal pure returns( uint256 _pos , bool _tru ) {
    	for( uint256 i = 0; i<_arr.length; i++ ) {
			if( _mem == _arr[i] ){
				_tru = true;
				_pos = i;
			}
		}
    }

	function _checkIncrement() internal view returns( bool _canInc ){
		if ( block.number >= _nativeBlockNum + IVars( aetherDAO() ).getVarVal( 'MaxBPB' ) ) {
			return true;
		}
		return false;
	}

	function _decodeAetherBlock( bytes calldata _aBlock ) internal pure returns( AetherBlock memory , bytes16[] memory ) {
		(
			bytes32 ablock_masterhash,
			uint256 ablock_txncount,
			bytes20 ablock_aethering,
			bytes16[] memory _blockTxnHashes
		) = abi.decode( _aBlock , (bytes32,uint256,bytes20,bytes16[]) );

		AetherBlock memory _aetherBlock = AetherBlock( ablock_masterhash , ablock_txncount , ablock_aethering );

		return( _aetherBlock , _blockTxnHashes );
	}

	function _decodeAetherTransaction( bytes calldata _aTxn ) internal pure returns( AetherTxn memory _aetherTxn ) {
		(
		address atxn_from,
		address atxn_to,
		bytes4 atxn_selector,
		bytes memory atxn_args
		) = abi.decode( _aTxn , (address,address,bytes4,bytes) );

		_aetherTxn = AetherTxn( atxn_from , atxn_to , atxn_selector , atxn_args );
	}

    function _txnAcceptance( bytes16 _atxnHash ) internal view returns( uint256 _pos , bool _tru ) {
    	for( uint256 i=0; i<_acceptedTxns.length; i++ ){
    		if( _atxnHash == _acceptedTxns[i] ){
    			_tru = true;
    			_pos = i;
    		}
    	}
    }

	function _nodeRegisteration( address _addr ) internal view returns( uint256 _pos , bool _tru ) {
		for( uint256 i=0; i<_nodesRegistered.length; i++ ) {
			if( _nodesRegistered[i] == _addr ) {
				_tru = true;
				_pos = i;
			}
		}
	}
	
	function _mhSubmitted( bytes32 _masterHash ) internal view returns( uint256 _pos , bool _tru ) {
		for( uint256 i=0; i<_submissions.length; i++ ) {
			if( _submissions[i] == _masterHash ){
				_tru = true;
				_pos = i;
			}
		}
	}
	
	function _getTxnHash( AetherTxn memory atxn ) internal view returns( bytes16 txn_hash ) {
		uint256[] memory to_cids = _getCids( atxn._to );
		return bytes16( keccak256( abi.encode( atxn._from , atxn._to , atxn._select , atxn._args , to_cids ) ) );
	}

	function _aetherCids() internal view returns( uint256[] memory ) {

		return _aetheringChains;
	}

	function _getCids( address _addr ) internal view returns( uint256[] memory _value ) {
		_value = addr_cids[_addr];
		return _value.length > 0 ? _value : _aetheringChains;
	}

	function _getNonce( address aCaller ) internal view returns( uint256 ) {

		return _nonces[aCaller];
	}

	function _getBlock( uint256 _blocknum ) internal view returns( bytes32 _aBlockMasterHash , uint256 _aBlockTxnCount , bytes20 _aBlockAetheringAddr ) {

		AetherBlock memory _ablock = aether_blocks[_blocknum];

		_aBlockMasterHash = _ablock._masterHash;
		_aBlockTxnCount = _ablock._txnCount;
		_aBlockAetheringAddr = _ablock._aetheringAddress;
	}

	function _getAetheringAddr( address _addr ) internal view returns( bytes20 ) {

		return _aetheringAddress( _addr , _getNonce( _addr ) );
	}

	function _getAetherer() internal view returns( bytes20 ) {

		return _getAetheringAddr( _nodesRegistered[_nodeRegisteryPtr] );
	}

	function _contextMH( bytes32 _masterHash ) internal view returns( bytes32 cmpMasterHash ) {

		return keccak256( abi.encodePacked( _masterHash , _aetherBlockNum ) );
	}

	function _getMasterHashVotes( bytes32 _masterHash ) internal view returns( uint256 ) {

		return _submittedMH[_contextMH( _masterHash )].length;
	}

	function _getMasterHash() internal view returns( bytes32 MASTERHASH ) {
		uint256 _mostVoted;
		for( uint256 i=0; i<_submissions.length; i++ ){
			uint256 cmpMH = _getMasterHashVotes( _submissions[i] );
			if ( _mostVoted <= cmpMH ) {
				_mostVoted = cmpMH;
				MASTERHASH = _submissions[i];
			}
			_mostVoted = _mostVoted < cmpMH ? cmpMH : _mostVoted;
		}
	}


	function _getTxnStatus( bytes16 _atxnHash ) internal view returns( bool ) {

		return _results[_atxnHash];
	}

	function _initAddrCids( address _caller , uint256[] memory supported_cids ) internal {

		addr_cids[_caller] = supported_cids;
	}

	function _registerNode( address _addr ) internal returns( bool ) {
		_nodesRegistered.push( _addr );
		emit NodeRegistered( _addr , _nodesRegistered.length , _nodeRegisteryPtr );
		return true;
	}

	function _appendTxn( bytes16 _atxnHash , AetherTxn memory _atxn ) internal returns( bool ){
		aether_transactions[_atxnHash] = _atxn;
		emit ATxnReceive( _atxnHash );
		return true;
	}

	function _execTxn( bytes16 _atxnHash , address _callee , bytes4 _selector , bytes memory _args ) internal returns( bool ) {
		( bool _txnStatus , ) = address( _callee ).call( bytes.concat( _selector , _args ) );
		_results[_atxnHash] = _txnStatus;
		emit ATxnRequest( _atxnHash , _txnStatus );
		return _txnStatus;
	}

	function _bindBlock( bytes16[] memory _accTxnHashes , AetherBlock memory _ablock ) internal returns( bool ) {
		delete _acceptedTxns;
		_acceptedTxns = _accTxnHashes;		
		_aetherBlockNum += 1;
		aether_blocks[_aetherBlockNum] = _ablock;
		_nativeBlockNum = block.number;
		_nonces[msg.sender] += 1;
		_nodeRegisteryPtr = _nodeRegisteryPtr+1 >= _nodesRegistered.length ? 0 : _nodeRegisteryPtr+=1;
		emit ABlockBind( _aetherBlockNum , _ablock._masterHash , _ablock._txnCount , _ablock._aetheringAddress , _nativeBlockNum );
		return true;
	}

	function _voteOnMasterHash( bytes32 _masterHash ) internal returns( bool ) {
		( , bool hash_exists ) = _mhSubmitted( _masterHash );
		if( hash_exists ) {
			_submittedMH[_contextMH( _masterHash )].push( msg.sender );
		}
		else{
			_submissions.push( _masterHash );
		}
		return hash_exists;
	}

	function aether_chains() public view override returns( uint256[] memory ){

		return _aetherCids();
	}

	function txnStatus( bytes16 atxn_hash ) public view override returns( bool ) {

		return _getTxnStatus( atxn_hash );
	}

	function nodeRegistery( address nodeAddr ) public view override returns( bool ) {
		( , bool _exists ) = _nodeRegisteration( nodeAddr );
		return _exists;
	}

	function aetheringAddress() public view override returns( bytes20 ) {

		return _getAetherer();
	}

	function MASTER_HASH() public view override returns( bytes32 ) {

		return _getMasterHash();
	}

	function decodeABlock( bytes calldata aBlock ) public pure override returns( AetherBlock memory aetherBlock , bytes16[] memory blockTxnHashes ) {
		
		return _decodeAetherBlock( aBlock ); 
	}

	function decodeATransaction( bytes calldata aTxn ) public pure override returns( AetherTxn memory aetherTxn ) {
		
		return _decodeAetherTransaction( aTxn );
	}

	function getABlock( uint256 ablock_num ) public view override returns( bytes32 aBlockMasterHash , uint256 aBlockTxnCount , bytes20 aBlockAetheringAddr ) {
		require( ablock_num <= _aetherBlockNum , "This block has did not bind yet" );
		return _getBlock( ablock_num );
	}

	function getATransaction( bytes16 atxn_ref ) public view override returns( uint256[] memory txn_cids , address txn_from , address txn_to , bytes4 txn_selector , bytes memory txn_args ) {
		AetherTxn memory _atxn = aether_transactions[atxn_ref];
		require( _atxn._from != address( 0 ) , "This transaction is not submitted" );

		txn_from = _atxn._from;
		txn_to = _atxn._to;
		txn_selector = _atxn._select;
		txn_args = _atxn._args;
		txn_cids = _getCids( txn_to );
	}

	function callerAAddress() public view override returns( bytes20 ) {

		return _aetheringAddress( msg.sender , _getNonce( msg.sender ) );
	}

	function aetherBlockNum() public view override returns( uint256 ) {

		return _aetherBlockNum;
	}

	function nativeBlockNum() public view override returns( uint256 ) {

		return _nativeBlockNum;
	}

	modifier noThrow() {
		require( msg.sender != address( 0 ) , "NoThrow" );
		_;
	}

	function stenner() public view override noThrow returns( bool ) {

		return callerAAddress() == _getAetherer();
	}

	function stepper() public view override noThrow returns( bool ) {

		return _checkIncrement();
	}

	function stekker() public view override noThrow returns( bool ) {

		return stenner() && stepper();
	}

	function registerNode( address nodeAddress ) external override returns( bool ) {
		( , bool nodeAddr_exists) = _nodeRegisteration( nodeAddress );
		require( !nodeAddr_exists , "This node is already registered" );

		return _registerNode( nodeAddress );
	}

	function addTransaction( address aCaller , bytes4 aSelector , bytes calldata aArgs ) external override returns( bool ) {
		AetherTxn memory _aTxn = AetherTxn( aCaller , msg.sender , aSelector , aArgs );
		
		bytes16 _aTxnHash = _getTxnHash( _aTxn );
		require( aether_transactions[_aTxnHash]._from == address( 0 ) , "This transaction is already submitted" );
		return _appendTxn( _aTxnHash , _aTxn );
	}

	function commitTransaction( bytes calldata aTxn ) external override returns( bool ) {
		AetherTxn memory _atxn = decodeATransaction( aTxn );
		bytes16 _atxnHash = _getTxnHash( _atxn );

		( , bool cid_exists) = _arrayMemeberU256( _getCids( _atxn._to ) , block.chainid );
		require( cid_exists , "Address does not support this chainId" );
		
		( , bool hash_exists ) = _txnAcceptance( _atxnHash );
		require( hash_exists , "Transaction hash is not accepted" );

		return _execTxn( _atxnHash , _atxn._to , _atxn._select , _atxn._args );
	}

	function execBlock( bytes calldata aBlock ) external override returns( bool ) {
		( AetherBlock memory _ablock , bytes16[] memory _ablockTxnHashes ) = decodeABlock( aBlock );
		require( _ablock._txnCount == _ablockTxnHashes.length , "Wrong transaction count" );

		bytes20 _aetherer = aetheringAddress();
		require( _getAetheringAddr( msg.sender ) == _aetherer , "Wrong aethering address" );

		bytes32 _masterHash = _getMasterHash();
		bytes32 chained_masterHash = keccak256( abi.encodePacked( _masterHash , _aetherBlockNum , _ablockTxnHashes , _aetherer ) );
		require( _ablock._masterHash == chained_masterHash , "Wrong master hash" );

		require( _checkIncrement() , "Blocks per block not yet acheived" );

		return _bindBlock( _ablockTxnHashes , _ablock );
	}

	function submitMasterHash( bytes32 masterHash ) external override returns( bool ) {
		
		return _voteOnMasterHash( masterHash );
	}


}
