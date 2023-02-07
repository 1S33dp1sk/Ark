//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;


import "../../Context/AetherCtx.sol";
import "../../Token/IAetherToken.sol";
import "../../DAO/IAetherDAO.sol";
import "./IIndex.sol";



contract Index is AetherCtx, IIndex {
	/**
	 * To balance gasPrices across different chains, we utilize
	 * different prices of gas nativly existant by the chainId.
	 * 
	 * 1. Collateral shifting between chains.
	 * 2. Allocation percentage change.
	 * 3. Treasuary 5% sell off.
	 */

	uint256 private _chainId;
	uint256 internal reserve0xA;
	uint256 internal reserveNative;
	bool private noMint;
	Strategy private indexStrategy;



	constructor() {
		_chainId = block.chainid;
	}

	function chainId() external view override returns( uint256 ) {

		return _chainId;
	}

	function chainAllocation() external view override returns( uint256 ) {
	}


	// returns the current reserves
	function fullReserves() public view override returns( uint256 , uint256 ) {

		return( _current0xA() , _currentNative() ); 
	}

	function _currentNative() internal view returns( uint256 ) {

		return address( this ).balance;
	}

	function _current0xA() internal view returns( uint256 ) {

		return IAetherToken( aetherToken() ).balanceOf( address( this ) );
	}



	function nodesEval() external view override returns( uint256 ) {

		return( indexEval() / 20 );
	}

	function indexEval() public view override returns( uint256 ) {
		( uint256 _resA , uint256 _resB ) = fullReserves();
		return ( _resA / _resB );
	}

	function bondsEval() external view override returns( uint256 ) {

		return( ( indexEval() * 1000 ) / 50 );
	}

	function buybackEval() external view override returns( uint256 ) {

		return (( indexEval() * 1000 ) / 30 );
	}






	function _syncAllocation() internal {


	}

	function _nativeEval( uint256 amnt ) internal view returns( uint256 ) {

		return ( ( amnt * reserve0xA ) / reserveNative );
	}


	function _reserveFor( Split s ) internal view returns( uint256 ) {

		if( s == Split.BONDS ) {
			return ( ( reserveNative*50 ) / 100 );
		}
		else if ( s == Split.BUYBACK ) {
			return ( ( reserveNative*30 ) / 100 );
		}
		else {
			return ( ( reserveNative*20 ) / 100 );
		}
	} 



	function targetRatio() external view override returns( uint256 ) {

		return ( IAetherDAO( aetherDAO() ).targetNative() / reserve0xA ); 
	}


	function baseReserves() public view override returns( uint256 , uint256 ) {

		return( reserve0xA , reserveNative );
	}



	function baseRatio() public view override returns( uint256 ) {
		( uint256 _r0 , uint256 _rN ) = baseReserves();

		return ( _r0 / _rN );
	}

	function fullRatio() public view override returns( uint256 ) {
		( uint256 _r0 , uint256 _rN ) = fullReserves();

		return ( _r0 / _rN );
	}

	function _sync() internal {
		reserve0xA = IAetherToken( aetherToken() ).balanceOf( address( this ) );
		reserveNative = address( this ).balance;
	}


	// function _checkTarget() internal view returns( bool ) {

	// 	return IAetherDAO( aetherDAO() ).targetNative() >= reserveNative ? true : IAetherDAO( aetherDAO() ).targetGas() > gasConsumption ? true : false;
	// }
	
	// function targetReached() internal {
	// 	require( _checkTarget() , "Target not yet reached" );
	// 	if( !noMint ){
	// 		try IAetherToken( aetherToken() ).treasuryMint() {
	// 			_sync();
	// 		} catch Error( string memory ) {
	// 			noMint = true;
	// 		}
	// 	}
	// 	uint256 _treasuryTarget = 20*treasuryTarget;
	// 	treasuryTarget = _treasuryTarget/100;
	// }

	// function setTarget( uint256 nTreasuryTarget ) external onlyDAO {
	// 	require( nTreasuryTarget > treasuryTarget );
	// 	treasuryTarget = nTreasuryTarget;
	// }

	modifier one( address[] memory _allowed ) {
		require( _arrayMemeber( _allowed , msg.sender ) , "Not a submitter" );
		_;
	}

	function _arrayMemeber( address[] memory _arr , address _mem ) internal pure returns( bool ) {
		for( uint256 i = 0; i<_arr.length; i++ ) {
			if( _mem == _arr[i] ){
				return true;
			}
		}
		return false;
	}
}
