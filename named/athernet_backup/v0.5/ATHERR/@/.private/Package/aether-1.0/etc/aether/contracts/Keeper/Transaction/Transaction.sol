//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;


import "../Tracker/Tracker.sol";
import "./ITransaction.sol";

contract Transaction is Tracker, ITransaction {
	

	uint256 private gasConsumption;
	uint256 private harmonicGas;
	/**
	 * Responsible for 20% of the Treasury
	 */
	mapping( bytes32 => mapping( address => bool ) ) _claims;
	mapping( bytes32 => AetherTxn ) _txns;


	function _valInReserves( uint256 _val ) internal view returns( uint256 value ) {
		if ( reserveNative == 0 ){
			return 0;
		}
		value = ( ( _val * reserve0xA ) / reserveNative );
	}


	function collaterilize( address _from , uint256 _amount , bytes32 _forRef ) external override onlyHUB returns( bool ) {
		if ( _from == aetherFactory() ) {
			return true;
		}
		require( _txns[_forRef]._gasNeeded == 0 );
		try IAetherToken( aetherToken() ).addCollateral( _from , _amount ) {
			_txns[_forRef] = AetherTxn( _from , 0 , _amount , IAetherDAO( aetherDAO() ).signersThreshold() );	
			return true;	
		} catch Error( string memory ) {
			return false;
		}
	}

	function checkSV( bytes32 _forRef , uint256 _magicValue ) external override onlyHUB returns( bool ) {
		require( _txns[_forRef]._gasNeeded == 0 );
		_txns[_forRef]._gasNeeded = _magicValue;
		if( _valInReserves( _magicValue ) <= reserve0xA ){
			return true;
		}
		return false;
	}


	// function getSV( bytes32 _forRef , uint256 /*_txnStep*/ ) external view override onlyHUB returns( uint256 ) {
	// 	uint256 tg_ = IAetherHUB( aetherHUB() ).transactionGas( _forRef );
	// 	uint256 _initialSV = _txns[_forRef]._gasNeeded;
	// 	if( _initialSV > tg_ ){
	// 		return ( _initialSV - tg_ );
	// 	}
	// 	return 0;
	// }



	// function enableTxn( bytes32 aetherRef , uint256 /*_magicValue*/ ) external override onlyHUB returns( bool ) {
	// 	require( IAetherHUB( aetherHUB() ).transactionFulfilled( aetherRef ) );
	// 	_claims[aetherRef][address( this )] = true;
	// 	uint256 totalGas = IAetherHUB( aetherHUB() ).transactionGas( aetherRef );
	// 	uint256 initialGas = _txns[aetherRef]._gasNeeded;
	// 	if ( initialGas > totalGas ) {
	// 		uint256 gasLeft = initialGas - totalGas;
	// 		IAetherToken( aetherToken() ).removeCollateral( _txns[aetherRef]._aetherer , gasLeft );
	// 	}
	// 	return true;
	// }

	function txnClaimable( bytes32 aReference ) external view returns( bool ) {

		return _claims[aReference][address( this )];
	}

	function gasMarkup() external view override returns( uint256 ) {

		return IAetherDAO( aetherDAO() ).gasMarkup();
	}

	// function _stratagize( Strategy _s , uint256 _gasConsumed ) internal view returns( uint256 _nativeTarget , uint256 _nativeCurrent , uint256 _totalGas ) {
	// 	_nativeBalance = _currentNative();
	// 	if ( _s == Strategy.DIRECT ) {
	// 		_nativeTarget = IAetherDAO( aetherDAO() ).targetNative();
	// 		_nativeCurrent = reserveNative < _nativeBalance ? reserveNative : _nativeBalance;
	// 		_totalGas = IAetherDAO( aetherDAO() ).targetGas(); - _gasConsumed;
	// 	}
	// 	else if ( s == Strategy.INVERSE ) {
	// 		_nativeTarget = IAetherDAO( aetherDAO() ).targetNative();
	// 		_nativeCurrent = reserveNative > _nativeBalance ? reserveNative : _nativeBalance;
	// 		_totalGas = IAetherDAO( aetherDAO() ).targetGas();
	// 	}
	// 	else if ( s == Strategy.STABLE ) {
	// 		_nativeTarget = IAetherDAO( aetherDAO() ).targetNative();
	// 		_nativeCurrent = reserveNative > _nativeBalance ? reserveNative : _nativeBalance;
	// 		_totalGas = IAetherDAO( aetherDAO() ).targetGas(); - _gasConsumed;
	// 	}
	// 	else {
	// 		revert( "Unkown Strategy" );
	// 	}
	// }

	// function baseGasFee() public view returns( uint256 ) {
	// 	uint256 _nativeDiff;
	// 	uint256 _gasOffset = harmonicGas * IAetherDAO( aetherDAO() ).targetTxns();
	// 	if ( IAetherDAO( aetherDAO() ).targetNative(); > reserveNative ){
	// 		_nativeDiff = IAetherDAO( aetherDAO() ).targetNative(); - reserveNative;
	// 	}
	// 	_nativeDiff = ( reserveNative + ( ( 20 * reserveNative ) / 100 ) );
	// 	return ( _nativeDiff / _gasOffset );
	// }

	// function _findStrategy() public view returns( Strategy ) {
	// 	uint256 _full = fullRatio();
	// 	uint256 _target = targetRatio();
	// 	uint256 _markup = gasMarkup();
	// 	if ( _indexStrategy == 0 ) {
	// 		if( _full > _target ) {
	// 			if ( _full * _markup  > _target ){
	// 				return Strategy.INVERSE;
	// 			} 
	// 			return Strategy.STABLE;
	// 		}
	// 		return Strategy.DIRECT;
	// 	}
	// 	return _indexStrategy;	
	// }

	// function gasEstimation( uint256 txnGas ) external view returns( uint256 ) {

	// 	return ( txnGas * baseGasFee() );
	// }

	// function _gasFee( uint256 _gas , uint256 _count ) internal view returns( uint256 ) {

	// 	return _gas * _count * baseGasFee();
	// } 
}
