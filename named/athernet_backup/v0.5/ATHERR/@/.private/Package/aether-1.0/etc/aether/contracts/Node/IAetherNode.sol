//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;


interface IAetherNode {

	function stakedAmount() external view returns(uint256);
	function releaseTime() external view returns(uint256);
	function executeMasterHash(bytes32) external returns(bool);
	function executeTransaction(bytes calldata) external returns(bool);
	function executeBlock(bytes calldata) external returns(bool);
}
