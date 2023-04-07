//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;

import "./IMemberships.sol";
import "../Vars/Vars.sol";
import "../../Bond/AetherBonds.sol";
import "../../Keeper/Tracker/ITracker.sol";
import "../../Token/IAetherToken.sol";


contract Memberships is IMemberships , Vars {

    function membershipFor( address _addr , Membership _membership ) external view override returns( bool ) {
    	if ( _membership == Membership.HOLDER ){
    		return isHolder( _addr );
    	}
    	else if ( _membership == Membership.NODE ){
    		return isNodeOwner( _addr );
    	}
    	else if ( _membership == Membership.PARTNER ){
    		return isTreasuryPartner( _addr );
    	}
    	else{
    		return false;
    	}
    }

	function isHolder( address _addr ) public view override returns( bool ) {
		
		return IAetherToken( aetherToken() ).balanceOf( _addr ) > holderThreshold();
	}

	function holderThreshold() public view override returns( uint256 ) {

		return getVarVal( IMemberships.holderThreshold.selector );
	}

	function isNodeOwner( address _addr ) public view override returns( bool ) {

		return ITracker( aetherKeeper() ).nodesOfOwner( _addr ) > nodeThreshold();
	}

	function nodeThreshold() public view override returns( uint256 ) {

		return getVarVal( IMemberships.nodeThreshold.selector );
	}

	function isTreasuryPartner( address _addr ) public view override returns( bool ) {

		return IAetherBonds( aetherKeeper() ).balanceOf( _addr ) > treasuryThreshold();
	}

	function treasuryThreshold() public view override returns( uint256 ) {

		return getVarVal( IMemberships.treasuryThreshold.selector );
	}

    function isDAOMember( address _addr ) public view override returns(bool) {

    	return isHolder( _addr ) || isNodeOwner( _addr ) || isTreasuryPartner( _addr );
    }

    function isDAOPartner( address _addr ) public view override returns( bool ) {

    	return isNodeOwner( _addr ) || isTreasuryPartner( _addr );
    }
}
