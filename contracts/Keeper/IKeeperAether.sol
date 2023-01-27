//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

/**
 * 
 * respects the selling
 * 
 */
interface IKeeperAether {

	function ticketOwner(uint256) external view returns(address);
	function getTicketMagic(uint256) external returns(uint256);
    function aetherSetup() external;
}