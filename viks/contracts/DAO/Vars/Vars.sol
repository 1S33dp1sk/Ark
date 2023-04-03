//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "../../Context/AetherCtx.sol";
import "./IVars.sol";

/**
 * Since the DAO is able to decide on different variables
 * it will be ineffecient to deploy a new contract on every update
 * for both the DAO to start controlling that variable and for the 
 * implementation contract to utilze the variable. Instead, here, we 
 * utilize a `fallback` *&* `mapping` to edit, add, recover and call
 * variables without deploying said contracts AGAIN.
 */ 
contract Vars is AetherCtx, IVars {

	mapping( bytes4 => Var ) private _vars;
	// depending on `_oscillation` for each var
	// the whole struct does not need to be accessed
	// so we can utilize a differnt `mapping`
	mapping( bytes4 => uint256 ) private _edits;

	//see{AetherContext.sol}
	// add the initial variables needed for the
	// 0xAether to function correctly.
	constructor() {

		// Time for the proposal to be concluded
		addVar( "proposalTime" , 657000 , 2628000 );
		// minimum amount of signatures before a transaction is aethered
		addVar( "signersThreshold" , 2 , 1314000 );
		// minimum amount of tokens to maintain a node
		addVar( "nodeThreshold" , 10000000 ether , 7884000 );
		// minimum amount of time before a node can be dissolved
		addVar( "nodeStakingTime" , 31536000 , 7884000 );
		// minimum amount of time before a bond is matured
		addVar( "bondMaturityTime" , 7257600 , 7884000 );
		// maximum amount of gas for each transaction
		addVar( "transactionThreshold" , block.gaslimit , 0 );
		// minimum amount of tokens to be eligable for the DAO
		addVar( "holderThreshold" , 1000000 ether , 0 );
		// the node/treasury split for transactions rewards
		addVar( "rewardsTreasury" , 60 , 1314000 );
		// the minimum amount of equity-swaps (0xABonds) needed to be a member
		addVar( "treasuryThreshold" , 1 , 7884000 );
		// combined depletion mul && depletion div will form the ratio
		addVar( "depletionMultiplier" , 50 , 0 );
		// of which the node balance will be depleted
		addVar( "depletionDivisor" , 100 , 0 );
		// the maximum amount of nodes that will be rewarded 
		addVar( "rewardLedger" , 5 , 259200 );
		// cross chain call gas pricing
		addVar( "gasPrice" , 35 , 86400 );
		// the total amount of gas needed before the next target
		addVar( "targetGas" , 1000 ether*1 gwei  , 0 );
		// target amount of transactions before the next target
		addVar( "targetTransactions" , 1e7 , 0 );
		// maximum amount of native blocks per aether block
		addVar( "MaxBPB" , 10 , 86400 );
		// maximum amount of native transactions to the hub before forming an aether block
		addVar( "MaxTPB" , 3 , 86400  );
	}


	function addVar( string memory varName , uint256 varVal , uint256 varOsc ) internal returns( bytes4 varRef ) {
		varRef = getVarRef( varName );
		require( _vars[varRef]._oscillation == 0 , "This variable ref is occupied" );
		varOsc = varOsc == 0 ? 1 : varOsc;
		_vars[varRef] = Var( varVal , varName , varOsc );
		_edits[varRef] = block.timestamp;
		emit VariableAdded( address( this ) , varName , varVal , varOsc );
	}

	function changeVarVal( bytes4 varRef , uint256 varVal ) internal returns( bool ) {
		uint256 _osc = _vars[varRef]._oscillation;
		require( _osc > 1 , "This variable ref is not occupied" );
		if( _edits[varRef] + _osc < block.timestamp ) {
			_vars[varRef]._value = varVal;
			emit VariableChange( address( this ) , varRef , varVal );
			return true;
		}
		return false;
	}

	// function changeAetherVarVal( bytes4 varRef , uint256 varVal ) external override returns( bool ) {
	// 	if( varExists( varRef ) ) {
	// 		_vars[varRef] = varVal;
	// 		return true;
	// 	}
	// 	return false;
	// }

	function varExists( string memory varName ) public view override returns( bool ) {

		return varExists( getVarRef( varName ) );
	}

	function varExists( bytes4 varRef ) public view override returns( bool ) {

		return _vars[varRef]._oscillation != 0;
	}

	function getLastEdit( string memory varName ) external view override returns( uint256 ) {

		return getLastEdit( getVarRef( varName ) );
	}

	function getLastEdit( bytes4 varRef ) public view override returns( uint256 ) {

		return _edits[varRef];
	}

	function getVar( string memory varName ) external view override returns( uint256 variableValue , string memory variableName , uint256 variableOsc ) {

		return getVar( getVarRef( varName ) );
	}

	function getVar( bytes4 varRef ) public view override returns(  uint256 variableValue , string memory variableName , uint256 variableOsc ) {
		Var memory v = _vars[varRef];

		variableValue = v._value;
		variableName = v._name;
		variableOsc = v._oscillation;
	}

	function getVarVal( string memory varName ) public view override returns( uint256 ) {

		return getVarVal( getVarRef( varName ) );
	}

	function getVarVal( bytes4 varRef ) public view override returns( uint256 ) {

		return _vars[varRef]._value;
	}

	function getVarRef( string memory varName ) public pure override returns( bytes4 ) {

		return bytes4( keccak256( abi.encodePacked( varName , "()" ) ) );
	}

	function getVarName( bytes4 varRef ) external view override returns( string memory ) {

		return _vars[varRef]._name;
	}
}
