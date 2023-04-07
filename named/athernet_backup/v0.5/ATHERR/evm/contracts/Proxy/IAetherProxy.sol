//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

interface IAetherProxy {
	// {EIP-897}
	function proxyType() external pure returns (uint256);
	function implementation() external view returns (address);
	function initialize(uint256,address,address,bool) external returns(bool);
	function initialize(uint256,address,bytes memory,bool) external returns(bool);
}
