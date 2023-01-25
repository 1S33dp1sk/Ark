//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

/**
 * Each AetherVar is composed of 
 * the name of the variable `_name`, 
 * the value `_value` , 
 * and how often can it be changed -voted on, in seconds `_oscillation` 
 */
interface IVars {

   	struct Var { uint256 _value; string _name; uint256 _oscillation; }

    event VariableChange(address indexed AetherDAO, bytes4 VariableReference, uint256 VariableValue);
    event VariableAdded(address indexed AetherDAO, string VariableName, uint256 VariableValue, uint256 VariableOscillation);

	function varExists(string memory) external view returns(bool);
	function varExists(bytes4) external view returns(bool);
	function getLastEdit(string memory) external view returns(uint256);
	function getLastEdit(bytes4) external view returns(uint256);
    function getVar(string memory) external view returns(uint256,string memory,uint256);
    function getVar(bytes4) external view returns(uint256,string memory,uint256);
    function getVarVal(bytes4) external view returns(uint256);
    function getVarVal(string memory) external view returns(uint256);
    function getVarRef(string memory) external view returns(bytes4);
    function getVarName(bytes4) external view returns(string memory);
}
