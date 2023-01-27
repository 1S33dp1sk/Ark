//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "./Treasury/Treasury.sol";
import "./IKeeperAether.sol";

contract KeeperAether is Treasury, IKeeperAether {

	uint256 tickets;
	mapping( uint256 => address ) _allTickets;
	mapping( uint256 => uint256 ) _ticketNonce;


	function getTicketMagic( uint256 ticket_id ) external view override returns( uint256 ) {

		return _ticketNonce[ticket_id];
	}

	function ticketOwner( uint256 ticket_id ) external view override returns( address ) {

		return _allTickets[ticket_id];
	}


	function aetherSetup() external override onlyFactory {

		IAetherToken( aetherToken() ).treasuryMint();
	}

	receive() external payable {}

}