//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;




interface IAetherToken {

    function totalSupply() external view returns (uint256);
    function maxSupply() external view returns (uint256);
    function balanceOf(address account) external view returns (uint256);
    function transfer(address recipient, uint256 amount) external returns (bool);
    function allowance(address owner, address spender) external view returns (uint256);
    function approve(address spender, uint256 amount) external returns (bool);
    function transferFrom(address sender,address recipient,uint256 amount) external returns (bool);
    function threshold(address account,uint256 amount) external view returns(bool);
    function treasuryStake(address staker, address node) external returns (bool);
    function treasuryRelease(address node) external returns (bool);
    function treasuryMint() external;
    function supplement(address node, uint256 amount) external returns (bool);
    function depleteNode(address node) external returns (bool);
    function rewardNode(address node, uint256 rewardL) external returns (bool);
    function addCollateral(address,uint256) external;
    function removeCollateral(address,uint256) external;
    function name() external view returns(string memory);
    function symbol() external view returns(string memory);
    function decimals() external view returns(uint8);

    event Transfer(address indexed from, address indexed to, uint256 value);
    event Approval(address indexed owner, address indexed spender, uint256 value);
    event NodeStake(address indexed staker, address indexed node, uint256 stakedAmount);
    event NodeRelease(address indexed staker, address indexed node, uint256 stakedAmount);
    event NodeRewarded(address indexed node, uint256 amount);
    event NodeDepleted(address indexed node, uint256 amount);
}