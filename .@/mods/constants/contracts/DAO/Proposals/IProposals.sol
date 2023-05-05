//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

interface IProposals {
	enum Poll { NONE , WITH , AGAINST , NEUTRAL }
	enum Status { NONE , INITIATED , FINALIZED }

    struct Proposal { string _link; string _varName; uint256 _varVal; uint256 _expiry; uint256[3] _votes; Status _status; Poll _resolution; }
    
    event InitiateProposal(address indexed AetherDAO, address indexed Composer, string ProposalLink, bytes32 ProposalReference, string ProposalVariable, uint256 ProposalValue);
    event ConcludeProposal(address indexed AetherDAO, bytes32 ProposalReference, uint8 ProposalResolution, uint256 ProposalVotes);
    event Vote(address indexed AetherDAO, address indexed DAOMember, bytes32 ProposalReference, uint8 voteType);

    function proposalTime() external view returns(uint256);
    function getProposalReference(uint256) external view returns(bytes32);
    function isProposalActive(bytes32) external view returns(bool);
	function getProposalResolution(bytes32) external view returns(uint8);
	function getProposalStatus(bytes32) external view returns(uint8);
    function memberVote(bytes32,address) external view returns(uint8);
    function getProposalVotes(bytes32) external view returns(uint256[3] memory);
    function getProposalExpiry(bytes32) external view returns(uint256);
    function getProposal(bytes32) external view returns(string memory,string memory,uint256,uint256,uint256[3] memory,uint8,uint8);
	function submitProposal(string calldata,string calldata,uint256) external returns(bytes32); 
	function voteOnProposal(bytes32,uint8) external; 
	function finalizeProposal(bytes32) external;
}
