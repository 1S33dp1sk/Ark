// We require the Hardhat Runtime Environment explicitly here. This is optional
// but useful for running the script in a standalone fashion through `node <script>`.
//
// When running the script with `npx hardhat run <script>` you'll find the Hardhat
// Runtime Environment's members available in the global scope.
import { ethers } from "hardhat";
import { Contract , ContractTransaction , ContractReceipt } from "ethers";
import { expect } from "chai";

async function main() {

    console.log('\n--------------------AETHER DEPLOYMENT----------------------------------\n')

    const [deployer] = await ethers.getSigners();
    console.log("Deploying contracts with the account:", deployer.address);
    const CIDS = [1234,4321];

    // define contract instances
    // and a common variable to each
    // with deployment-contract variable
    let AetherHUB:any,hub:Contract;

    let AetherTest:any,test:Contract;

    // deploy hub
    AetherHUB = await ethers.getContractFactory("AetherHUB");
    hub = await AetherHUB.deploy();
    await hub.deployed();
    console.log( 'AETHERHUB : ' , hub.address );

    var _masterHASH = await hub.MASTER_HASH();
    console.log( 'MASTERHASH : ' , _masterHASH );

    var _blocknum = await hub.aetherBlockNum();
    console.log( 'CURRENT AETHER BLOCK #', _blocknum );

    var FIRST_AETHER_BLOCK = await hub.getABlock( 1 );
    console.log( 'FIRST FUCKING BLOCK BRUH : ' , FIRST_AETHER_BLOCK )

    console.log( 'regsitering node....')
    await hub.registerNode( deployer.address );
    expect( await hub.nodeRegistery( deployer.address ) ).to.equal(true);

}

// We recommend this pattern to be able to use async/await everywhere
// and properly handle errors.
main().catch((error) => {
  console.error(error);
  process.exitCode = 1;
});
