//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

interface IAccess {

	event AccessGranted( address indexed Node , address indexed AccessTo );
	event AccessRevoked( address indexed Node , address indexed AccessTo );
	event NodeInitialized( address indexed Node , address indexed Owner );

	function owner() external view returns(address);
	function setOwner(address) external;
	function addAccess(address) external returns(bool);
	function revokeAccess(address) external returns(bool);
}
