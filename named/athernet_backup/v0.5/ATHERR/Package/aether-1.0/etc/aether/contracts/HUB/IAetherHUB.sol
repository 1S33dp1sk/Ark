//SPDX-License-Identifier: GPL v3
pragma solidity ^0.8.0;


interface IAetherHUB {
	struct AetherTxn { address _from; address _to; bytes4 _select; bytes _args; }
	struct AetherBlock { bytes32 _masterHash; uint256 _txnCount; bytes20 _aetheringAddress; }

	function registerNode(address) external returns(bool);
	function addTransaction(address,bytes4,bytes calldata) external returns(bool);
	function commitTransaction(bytes calldata) external returns(bool);
	function execBlock(bytes calldata) external returns(bool);
	function submitMasterHash(bytes32) external returns(bool);	

	function nodeRegistery(address) external view returns(bool);
	function aetheringAddress() external view returns(bytes20);
	function MASTER_HASH() external view returns(bytes32);
	function decodeABlock(bytes calldata) external pure returns(AetherBlock memory,bytes16[] memory);
	function decodeATransaction(bytes calldata) external pure returns(AetherTxn memory);
	function getABlock(uint256) external view returns(bytes32,uint256,bytes20);
	function getATransaction(bytes16) external view returns(uint256[] memory,address,address,bytes4,bytes memory);
	function txnStatus(bytes16) external view returns(bool);
	function callerAAddress() external view returns(bytes20);
	function aetherBlockNum() external view returns(uint256);
	function nativeBlockNum() external view returns(uint256);
	function aether_chains() external view returns(uint256[] memory);
	
	function stepper() external view returns(bool);
	function stenner() external view returns(bool);
	function stekker() external view returns(bool);

	event ATxnReceive( bytes16 ATxnHash );
	event ATxnRequest( bytes16 ATxnHash , bool ATxnResult );
	event ABlockBind( uint256 ABlockNum , bytes32 ABlockMasterHash , uint256 ABlockTxnCount , bytes20 ABlockAethering , uint256 NBlockNum );
	event NodeRegistered( address ANodeAddress , uint256 ANodePos , uint256 ANodesPtr );
}
