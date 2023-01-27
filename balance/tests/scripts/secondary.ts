// We require the Hardhat Runtime Environment explicitly here. This is optional
// but useful for running the script in a standalone fashion through `node <script>`.
//
// When running the script with `npx hardhat run <script>` you'll find the Hardhat
// Runtime Environment's members available in the global scope.
import { ethers } from "hardhat";
import { Contract , ContractTransaction , ContractReceipt } from "ethers";
import { expect } from "chai";
import * as readline from 'readline';


async function main() {

    console.log('\n--------------------AETHER DEPLOYMENT----------------------------------\n')

    const [deployer] = await ethers.getSigners();
    console.log("Deploying contracts with the account:", deployer.address);
    const CIDS = [1234,4321];

    // define contract instances
    // and a common variable to each
    // with deployment-contract variable
    let AetherReceiver:any,receiver:Contract;

    let hubAddress:string = '0xb5391Eb3F8Da436ebFAF882b2Db95802167A4A48';

    AetherReceiver = await ethers.getContractFactory("AetherReceiver");
    receiver = await AetherReceiver.deploy();
    await receiver.deployed()
    console.log( 'Aether receiver address : ' , receiver.address );


    // var stdin = process.openStdin();
    // console.log('\n0xAetherHUB address : ')
    // stdin.addListener("data", async function(d) {
    //     // note:  d is an object, and when converted to a string it will
    //     // end with a linefeed.  so we (rather crudely) account for that  
    //     // with toString() and then substring() 
    //     hubAddress = ethers.utils.getAddress(d.toString().trim())
    //     var _txn = await receiver.setAetherHUB( hubAddress );
    //     console.log( 'HUB address set in receiver.' );
    //     process.exit(0);
    // });


}

// We recommend this pattern to be able to use async/await everywhere
// and properly handle errors.
main().catch((error) => {
  console.error(error);
  process.exitCode = 1;
});
