//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

interface IAetherCall {
    function submitTransaction(uint256,address,uint256[] memory,bytes4[] memory,bytes[] memory) external returns(bool);
    function tempSubmitTxn(uint256,address,bytes4,bytes memory) external returns(bool);
}
