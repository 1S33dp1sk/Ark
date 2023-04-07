//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;


/**
 * 
 * respects the transaction gas
 * 
 */
interface ITransaction {

	struct AetherTxn { address _aetherer; uint256 _gasNeeded; uint256 _collateralSubmitted; uint256 _signersMax; }
 
	event TransactionClaimed( bytes32 TransactionReference , uint256 ClaimSize );
	event TransactionAccepted( bytes32 TransactionReference );

	function collaterilize(address,uint256,bytes32) external returns(bool);
	function checkSV(bytes32,uint256) external returns(bool);
	function gasMarkup() external view returns(uint256);
}
