//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;



interface IAetherDAO {
    function signersThreshold() external view returns(uint256);
    function transactionThreshold() external view returns(uint256);
    function rewardsTreasury() external view returns(uint256);
    function depletionMultiplier() external view returns(uint256);
    function depletionDivisor() external view returns(uint256);
    function rewardLedger() external view returns(uint256);
    function depletionRatio() external view returns(uint256,uint256);
    function bondMaturityTime() external view returns(uint256);
    function gasMarkup() external view returns(uint256);
	function targetGas() external view returns(uint256);
	function targetNative() external view returns(uint256);
	function targetTransactions() external view returns(uint256);
    function nodesAllocation() external view returns(uint256);
}
