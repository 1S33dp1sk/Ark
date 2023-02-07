//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "../Memberships/Memberships.sol";
import "./IProposals.sol";

contract Proposals is IProposals , Memberships {

	mapping( bytes32 => mapping( address => Poll ) ) private _ballots;
	mapping( bytes32 => Proposal ) private _proposals;

	uint256 public proposalsCount;

	modifier DAOMember() {
		require( isDAOMember( msg.sender ) , "OnlyMembers" );
		_;
	}

	modifier oneVote( bytes32 _ref ) {
		require( _memberVote( _ref , msg.sender ) == Poll.NONE );
		_;
	}

	function proposalTime() public view override returns( uint256 ) {

		return getVarVal( IProposals.proposalTime.selector );
	}

	function getProposalReference( uint256 proposalIndex ) external view override returns( bytes32 ) {

		return keccak256( abi.encodePacked( address( this ) , proposalIndex ) );
	}	

	function isProposalActive( bytes32 proposalReference ) public view override returns( bool ) {

		return _proposals[proposalReference]._expiry > block.timestamp;
	}

	function _proposalResolution( bytes32 _proposalReference ) internal view returns( Poll ) {

		return _proposals[_proposalReference]._resolution;
	}
	
	function getProposalResolution( bytes32 proposalReference ) external view override returns( uint8 ) {

		return uint8( _proposalResolution( proposalReference ) );
	}

	function _proposalStatus( bytes32 _proposalReference ) internal view returns( Status ) {

		return _proposals[_proposalReference]._status;
	}

	function getProposalStatus( bytes32 proposalReference ) external view override returns( uint8 ) {

		return uint8( _proposalStatus( proposalReference ) );
	}

	function _memberVote( bytes32 _proposalReference , address _voter ) internal view returns( Poll ) {

		return _ballots[_proposalReference][_voter];
	}

	function memberVote( bytes32 proposalReference , address voter ) external view override returns( uint8 ) {

		return uint8( _memberVote( proposalReference , voter ) );
	}

	function getProposalVotes( bytes32 proposalReference ) external view override returns( uint256[3] memory ) {

		return _proposals[proposalReference]._votes;
	}

	function getProposalExpiry( bytes32 proposalReference ) external view override returns( uint256 ) {

		return _proposals[proposalReference]._expiry;
	}

	function getProposal( bytes32 proposalReference ) external view override returns( string memory proposalLink , string memory proposalVarName , uint256 proposalVarVal , uint256 proposalExpiry , uint256[3] memory proposalVotes , uint8 proposalStatus , uint8 ProposalResolution ) {
		Proposal memory temp = _proposals[proposalReference]; 
		
		return( temp._link , temp._varName , temp._varVal , temp._expiry , temp._votes , uint8( temp._status ) , uint8( temp._resolution ) );
	}

    function submitProposal( string calldata proposalLink , string calldata proposalVarName , uint256 proposalVal ) external override DAOMember returns( bytes32 proposalReference ) {
    	proposalReference = keccak256( abi.encodePacked( address( this ) , proposalsCount ) );
    	uint256[3] memory proposalVotes = [uint256(0),uint256(0),uint256(0)];
    	
    	require( _proposalStatus( proposalReference ) == Status.NONE , "Reference exists" );
    	_proposals[ proposalReference ] = Proposal( proposalLink , proposalVarName , proposalVal , block.timestamp + proposalTime() , proposalVotes , Status.INITIATED , Poll.NONE );
    	proposalsCount += 1;

    	emit InitiateProposal( address( this ) , msg.sender , proposalLink , proposalReference , proposalVarName , proposalVal );
    }

    function voteOnProposal( bytes32 proposalReference , uint8 proposalVote ) DAOMember oneVote( proposalReference ) external override {
    	Poll proposalVote_ = Poll( proposalVote );
    	Status proposalStatus_ = _proposalStatus( proposalReference );
    	_ballots[proposalReference][msg.sender] = proposalVote_;
    	
    	require( proposalStatus_ == Status.INITIATED , "Cannot vote" );
    	require( proposalVote_ > Poll.NONE && proposalVote_ <= Poll.NEUTRAL );
    	require( isProposalActive( proposalReference ) );

    	_proposals[proposalReference]._votes[uint256( proposalVote_ )] += 1;

    	emit Vote( address( this ) , address( msg.sender ) , proposalReference , proposalVote );
    }

    function finalizeProposal( bytes32 proposalReference ) external override DAOMember {
    	Proposal storage finalProposal = _proposals[proposalReference];
    	Poll _winVote;
    	uint256 _ballotVotes;
    	uint256 _voteCount;

    	require( ( finalProposal._expiry < block.timestamp ) , "Proposal Active" );
    	require( finalProposal._status == Status.INITIATED );
    	finalProposal._status = Status.FINALIZED;

    	for( uint256 i=0; i<3; i++ ) {
    		_voteCount += finalProposal._votes[i];
    		if ( finalProposal._votes[i] >= _ballotVotes ){
    			_ballotVotes = finalProposal._votes[i];
    			_winVote = Poll( i );
    		}
    	}
    	
    	finalProposal._resolution = _winVote;
    	bytes4 _varRef = getVarRef( finalProposal._varName );
    	if( ( _winVote == Poll.WITH ) && varExists( _varRef ) ) {
			changeVarVal( _varRef , finalProposal._varVal );
		}else {
			addVar( finalProposal._varName , finalProposal._varVal , 0 );
		}	
    	
    	emit ConcludeProposal( address( this ) , proposalReference , uint8( _winVote ) , _voteCount );
    }
}
