//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "../Common/IAetherContractTypes.sol";

interface IAetherFactory is IAetherContractTypes {

    function deployNode() external returns(address);
    function deployProxy(address,uint256) external returns(address);
    function deployContract(bytes memory,uint256) external returns(address);
    function factoryIsNode(address) external view returns(bool);
    function factoryIsProxy(address) external view returns(bool);
    function nodesDeployed() external view returns(uint256); 
    function contractsDeployed() external view returns(uint256);

    function setupAether() external returns(bool);
    function aetherSetup() external;

    event NodeDeployed(address indexed Node,address indexed Owner,uint256 Timestamp,uint256 DeploymentID);
    event ProxyDeployed(address indexed Proxy,address indexed ProxyTo,uint256 DeploymentID);
    event ContractDeployed(address indexed Contract, address indexed Proxy,uint256 DeploymentID);
}