//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "../Common/IRouterCall.sol";

interface IAetherRouter is IRouterCall {
    function setAetherAddress(uint256,address) external override returns(bool);
    function getPermittedHash(uint256) external view returns(bytes32);
    function setPermittedHash(uint256,bytes32) external;
}
