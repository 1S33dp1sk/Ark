//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "./IAether0xID.sol";

interface IRouterCall is IAether0xID {
    function getAetherAddress(uint256) external view returns(address);
    function setAetherAddress(uint256,address) external returns(bool);
}