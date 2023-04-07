//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "../Keeper/KeeperAether.sol";
import "../Token/AetherToken.sol";
import "./Proposals/Proposals.sol";
import "hardhat/console.sol";



contract AetherDAO is IAetherDAO , Proposals {


	address public _AetherToken_;

	constructor() {
		_AetherToken_ = _deploy( uint256( AContractID.AToken ) , type(AetherToken).creationCode );
	}


	fallback() external {
		uint256 _val = getVarVal( msg.sig );	
		assembly {
			let ptr
			mstore(ptr, _val)
			return(ptr, add(ptr, 0x20))
		}
	}

	function signersThreshold() external view override returns( uint256 ) {

		return getVarVal( IAetherDAO.signersThreshold.selector );
	}

	function transactionThreshold() external view override returns( uint256 ) {

		return getVarVal( IAetherDAO.transactionThreshold.selector );
	}

	function rewardsTreasury() external view override returns( uint256 ) {

		return getVarVal( IAetherDAO.rewardsTreasury.selector );
	}

	function depletionMultiplier() public view override returns( uint256 ) {

		return getVarVal( IAetherDAO.depletionMultiplier.selector );
	}

	function depletionDivisor() public view override returns( uint256 ) {

		return getVarVal( IAetherDAO.depletionDivisor.selector );
	}

	function depletionRatio() external view override returns(uint256,uint256) {

		return( depletionMultiplier() , depletionDivisor() );
	}

	function rewardLedger() external view override returns( uint256 ) {

		return getVarVal( IAetherDAO.rewardLedger.selector );
	}

	function bondMaturityTime() external view override returns( uint256 ) {

		return getVarVal( IAetherDAO.bondMaturityTime.selector );
	}

	function gasMarkup() external view override returns( uint256 ) {

		return getVarVal( IAetherDAO.gasMarkup.selector );
	}

	function targetGas() external view override returns( uint256 ) {

		return getVarVal( IAetherDAO.targetGas.selector );
	}

	function targetTransactions() external view override returns( uint256 ) {

		return getVarVal( IAetherDAO.targetTransactions.selector );
	}

	function targetNative() external view override returns( uint256 ) {

		return ( getVarVal( IAetherDAO.targetGas.selector ) / 1 gwei );
	}

	function nodesAllocation() external view override returns( uint256 ) {

		return( getVarVal( IAetherDAO.nodesAllocation.selector ) );
	}
}
