//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

/**
 * 
 * respects the index evaluation
 * 
 */
interface IIndex {

	enum Strategy { AUTO , DIRECT , INVERSE , STABLE , SELL }
	enum Split { BONDS , BUYBACK , NODES }

	event ReservesAdapted( uint256 RRatio , uint256 R0xA , uint256 RNative , uint256 RTarget );
	event TargetUpdated( uint256 TreasuryTarget , uint256 TargetTransactions );

	// function indexGain() external view returns(uint256);
	// function indexAllocation() external view returns(uint256);
	// function supplyAllocation() external view returns(uint256);
	function chainId() external view returns(uint256);
	function chainAllocation() external view returns(uint256);

	// function treasuryTarget() external view returns(uint256);
	// function treasuryValue() external view returns(uint256);
	function fullReserves() external view returns(uint256,uint256);
	function baseReserves() external view returns(uint256,uint256);

	// function chainRatio() external view returns(uint256);
	function baseRatio() external view returns(uint256);
	function fullRatio() external view returns(uint256);
	function targetRatio() external view returns(uint256);


	function indexEval() external view returns(uint256);
	function bondsEval() external view returns(uint256);
	function nodesEval() external view returns(uint256);
	function buybackEval() external view returns(uint256);


	// function _0xAValue() external view returns(uint256);
}
