//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

interface IMemberships {
    enum Membership { NONE , HOLDER , NODE , PARTNER }

    function isHolder(address) external view returns(bool);
    function holderThreshold() external view returns(uint256);
    function isNodeOwner(address) external view returns(bool);
    function nodeThreshold() external view returns(uint256);
    function isTreasuryPartner(address) external view returns(bool);
    function treasuryThreshold() external view returns(uint256);
    function isDAOMember(address) external view returns(bool);
    function isDAOPartner(address) external view returns(bool);
    function membershipFor(address,Membership) external view returns(bool);
}