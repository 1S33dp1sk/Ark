//SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.8.9;


contract Phase {

    bytes32 public _accessPath;
    bytes32 public _data;
    address public _sender;
    address public _caller;
    string public _exec;

    event Phase(bytes32 AccessPath, bytes data, address indexed Sender, address indexed Caller, bytes32 Exec);
    

   
    function testPhase(bytes32 aP, bytes memory da, address se, address ca, bytes32 exec) public returns (bool) {

        emit Phase(aP, da, se, ca, exec);
        return true;
    }


   
}