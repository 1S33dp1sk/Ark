//SPDX-License-Identifier: GPL v3

pragma solidity ^0.8.0;


import "../../Factory/IAetherFactory.sol";
import "../Index/Index.sol";
import "./ITracker.sol";


contract Tracker is Index, ITracker {

	mapping( uint256 => uint256 ) private _fairValue;
	mapping( uint256 => address ) private _nodeAddrs;
	uint256 private _nodeCount;


	uint256 private _sequencePtr;



	function depletionRatio() public view override returns( uint256 , uint256 ){

		return(0,0);
	}


	function _nxtSequence() internal {
		if( _sequencePtr >= _nodeCount - 1 ){
			_sequencePtr = 0;
		}
	}


	function spwanNode() external {

		_nodeCount += 1;
		_nodeAddrs[_nodeCount] = IAetherFactory( aetherFactory() ).deployNode();
	}


	function nodesOfOwner( address node_owner ) external view override returns(uint256) {


	} 


	function totalNodes() external view returns( uint256 ) {

		return _nodeCount;
	}


	function registeredNodes() external view override returns( address[] memory _nodes ) {
		uint256 temp = _nodeCount; 
		while ( temp > 10 ){
			temp /= 10;
			temp += 1;
		}
		_nodes = new address[](temp);
		for( uint256 i=0; i<temp; i++ ) {
			_nodes[i] = _nodeAddrs[i];
		}
	}
}