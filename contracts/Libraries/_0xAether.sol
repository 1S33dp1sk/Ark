//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "../HUB/IAetherHubV2.sol";

library _0xAether {


	function decodeBlk( bytes calldata _aBlock ) public pure returns( IAetherHubV2.AetherBlock memory , bytes16[] memory ) {
		(
			bytes32 ablock_masterhash,
			uint256 ablock_txncount,
			bytes20 ablock_aethering,
			bytes16[] memory _blockTxnHashes
		) = abi.decode( _aBlock , (bytes32,uint256,bytes20,bytes16[]) );

		IAetherHubV2.AetherBlock memory _aetherBlock = IAetherHubV2.AetherBlock( ablock_masterhash , ablock_txncount , ablock_aethering );

		return( _aetherBlock , _blockTxnHashes );
	}

	function decodeTxn( bytes calldata _aTxn ) public pure returns( IAetherHubV2.AetherTxn memory _aetherTxn ) {
		(
		address atxn_from,
		address atxn_to,
		bytes4 atxn_selector,
		bytes memory atxn_args
		) = abi.decode( _aTxn , (address,address,bytes4,bytes) );

		_aetherTxn = IAetherHubV2.AetherTxn( atxn_from , atxn_to , atxn_selector , atxn_args );
	}
}
