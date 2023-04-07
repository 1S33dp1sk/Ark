import { expect } from "chai";
import { ethers } from "hardhat";
import { Contract , ContractTransaction , ContractReceipt } from "ethers";

describe(" Aether Deployment :: 0xAetherHUB" , function() {

  let AetherHUB:any,hub:Contract;
  let token:Contract;

  it("HUB Tru Test" , async function() {
  console.log('\n-----------------------------------------------------------\n')
    AetherHUB = await ethers.getContractFactory("AetherHUB");

    hub = await AetherHUB.deploy();
    await hub.deployed();
    console.log( "HUB ADDRESS\t : " , hub.address );


  console.log('\n-----------------------------------------------------------\n')
  });  



});



