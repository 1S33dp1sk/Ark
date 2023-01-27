//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;


import "../Common/IAether0xID.sol";


interface IAetherCtx is IAether0xID {
	function aetherID() external view returns(uint256);
    function aetherRouter() external view returns(address);
    function aetherFactory() external view returns(address);
	function aetherDAO() external view returns(address);
    function aetherToken() external view returns(address);
    function aetherHUB() external view returns(address);
    function aetherKeeper() external view returns(address);
    function aetherBonds() external view returns(address);
}
