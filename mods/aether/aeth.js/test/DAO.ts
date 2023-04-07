import { expect } from "chai";
import { ethers } from "hardhat";
import { Contract , ContractTransaction , ContractReceipt } from "ethers";

describe(" Aether Deployment :: 0xAetherDAO" , function() {

  let AetherDAO:any,dao:Contract;
  let token:Contract;

  it("DAO Vars Test" , async function() {
  console.log('\n-----------------------------------------------------------\n')
    AetherDAO = await ethers.getContractFactory("AetherDAO");

    dao = await AetherDAO.deploy();
    await dao.deployed();
    console.log( "DAO ADDRESS\t : " , dao.address );

    const tpb = await dao.functions['getVar(string)']( 'MaxTPB' );
    console.log( 'DAO Transactions per block\t : ' , tpb );
    
    const proposalTime = await dao.proposalTime();
    console.log( 'DAO Proposal break\t : ' , proposalTime );


  console.log('\n-----------------------------------------------------------\n')

  });  

});



