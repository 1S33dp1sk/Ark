//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "../../Bond/AetherBonds.sol";
import "../Transaction/Transaction.sol";
import "./ITreasury.sol";

contract Treasury is Transaction, ITreasury {
	/**
	 * Responsible for 50% of the Treasury
	 */
	address public _AetherBonds_;
	uint256 public MAXIMUM_BONDS;
	Auction[] private bondsAuction;

	mapping( uint256 => Bond ) internal _0xABonds;


	constructor() {
		_AetherBonds_ = _deploy( uint256( AContractID.ABonds ) , type(AetherBonds).creationCode );
	}


	function maturity() public view override returns( uint256 ) {

		return IAetherDAO( aetherDAO() ).bondMaturityTime();
	}


	function issueBond( address _to ) public override onlyDAO returns( uint256 ) {

		return( IAetherBonds( aetherBonds() ).issueBond( _to ) );
	}


	function single256Array( uint256 bond_id ) public pure returns( uint256[] memory single_bondArr ){
		single_bondArr = new uint256[](1);
		single_bondArr[0] = bond_id;
		return single_bondArr;
	}

	function _defineBond( uint256 bond_id ) internal {
		require( !_bondDefined( bond_id ) );

		_0xABonds[bond_id] = Bond( block.timestamp , 1 , single256Array( bond_id ) , maturity() );
	}

	function _bondDefined( uint256 bond_id ) internal view returns( bool ) {

		return _0xABonds[bond_id]._ownerEq != 0;
	}

	function _sumArr( uint256[] memory _in ) internal pure returns( uint256 arraySum ) {
		for( uint256 i=0; i<_in.length; i++ ) {
			arraySum += _in[i];
		}
	}

	function _isMatured( uint256 bond_id ) internal view returns( bool ) {
		require( _bondDefined( bond_id ) );
		uint256 _matureC = block.timestamp - _0xABonds[bond_id]._actionTs;
		return ( _matureC / _0xABonds[bond_id]._maturityEpoch ) > 0;
	}

	// function _preserve() internal view returns( bool ) {
	// 	uint8 _allbonds = _sumArr( _maturingBonds );
	// 	_allbonds += _sumArr( _auctionBonds );
	// 	return ( _allbonds + _sumArr( _treasuryBonds ) ) == MAXIMUM_BONDS;
	// }

	function auctionBond( uint256 bond_id ) external override returns( uint256 queuePosition ) {
		require( _isMatured( bond_id ) , "Bond not matured" );
		uint256[] memory bondIds = IAetherBonds( aetherBonds() ).idsOfBond( bond_id );
		queuePosition = bondsAuction.length;
		uint256 _lastSaleTime = block.timestamp;
		if( queuePosition > 1 ){
			_lastSaleTime = bondsAuction[queuePosition-1]._open;
		}
		bondsAuction.push( Auction( bond_id , bondIds.length , bondIds.length*bondEval() , _lastSaleTime+maturity() , _buyBackLimit() ) );
	}

	function _buyBackLimit() internal view returns( uint256 ) {
		uint256 temp = bondEval()*70;
		return ( temp / 100 );
	}

	function bondEval() public view override returns( uint256 ) {

		return _reserveFor( Split.BONDS ) / IAetherBonds( aetherBonds() ).totalSupply();
	}

	function swapBond( uint256 bond_id ) external override {
	}
}