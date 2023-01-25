//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "../HUB/IAetherHUB.sol";
import "./Access/Access.sol";
import "./IAetherNode.sol";

contract AetherNode is Access, IAetherNode {


	uint256 private  _staked;
	uint256 private  _releaseTime;


	function releaseTime() external view override returns( uint256 ) {

		return _releaseTime;
	}

	function stakedAmount() external view override returns( uint256 ) {

		return _staked;
	}

	function executeMasterHash( bytes32 master_hash ) external override callAccess returns( bool mhSubmitted ) {

		mhSubmitted = IAetherHUB( AETHER_HUB ).submitMasterHash( master_hash );
	}

	function executeTransaction( bytes calldata aether_txn ) external override callAccess returns( bool txnCommitted ) {

		txnCommitted = IAetherHUB( AETHER_HUB ).commitTransaction( aether_txn );
	}

	function executeBlock( bytes calldata aether_block ) external override callAccess returns( bool blockBinded ) {
		
		blockBinded = IAetherHUB( AETHER_HUB ).execBlock( aether_block );
	}

}