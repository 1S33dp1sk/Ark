//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;


interface IAetherBonds {

	event Transfer(address indexed from, address indexed to, uint256 indexed bond_id);
    event Approval(address indexed owner, address indexed approved, uint256 indexed bond_id);
    event ApprovalForAll(address indexed owner, address indexed operator, bool approved);
    event BondIssued(address indexed BondOwner, uint256 BondId , uint256 BondMintedAt);

    function name() external view returns (string memory);
    function symbol() external view returns (string memory);
    function tokenURI(uint256) external view returns (string memory);
    function supportsInterface(bytes4) external view returns (bool);
    function balanceOf(address) external view returns (uint256);
    function ownerOf(uint256) external view returns (address);
    function safeTransferFrom(address,address,uint256) external;
    function transferFrom(address,address,uint256) external;
    function approve(address,uint256) external;
    function getApproved(uint256) external view returns (address);
    function setApprovalForAll(address,bool) external;
    function isApprovedForAll(address, address) external view returns (bool);
    function safeTransferFrom(address,address,uint256,bytes calldata) external;
    function issueBond(address) external returns(uint256);
    function idsOfBond(uint256) external view returns(uint256[] memory);
    function maxSupply() external view returns(uint256);
    function totalSupply() external view returns(uint256);
}