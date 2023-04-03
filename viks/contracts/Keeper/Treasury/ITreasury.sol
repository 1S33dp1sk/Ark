//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;


/**
 * 
 * respects the bonds logic
 * 
 */
interface ITreasury {

	enum BondStatus { MATURING , AUCTIONED , TREASURY }

	struct Bond { uint256 _actionTs; uint8 _ownerEq; uint256[] _idArray; uint256 _maturityEpoch; }
	struct Auction { uint256 _bondId; uint256 _totalEquity; uint256 _value; uint256 _open; uint256 _buyBackPrice; }

	event boneMade( uint256 BondId , uint256 TreasuryOwnership , address BondOwner);
	event BondDefaulted( uint256 BondId , uint256 TreasuryOwnership , uint256 DefaultValue , address BondOwner );
	event BondQueued( uint256 BondId , uint256 QueuePosition , uint256 BondValue );

	function maturity() external view returns(uint256);
	function bondEval() external view returns(uint256);
	function issueBond(address) external returns(uint256);
	function auctionBond(uint256) external returns(uint256);
	// function getQueue() external view returns(uint256[] memory);
	// function cancelAuction(uint256) external returns(bool);
	function swapBond(uint256) external;
}
