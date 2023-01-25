//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;


/**
 * 
 * respects the nodes logic
 * 
 */
interface ITracker {

	event MakeNode( address indexed NodeOwner , address indexed Node , uint256 NodeFIA , uint256 NodeReleaseTime );
	event NodeDissolved( address Node , uint256 NodeFIA , uint256 NodeReward , uint256 NodeInitialStake , address NodeOwner );
	event NodeActualized( address Node , uint256 NodeInitialStake , uint256 NodeReleaseTime );

	// function nodeEval() external view returns(uint256);
	// function nodeFIA() external view returns(uint256);
	// function dissolveNode(uint256) external view returns(bool);
	// function rewardNode(address,uint256) external;
	// function depleteNode(address,uint256) external;
	function nodesOfOwner(address) external view returns(uint256);
	function registeredNodes() external view returns(address[] memory);
	function depletionRatio() external view returns(uint256,uint256);
}
