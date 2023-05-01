// We require the Hardhat Runtime Environment explicitly here. This is optional
// but useful for running the script in a standalone fashion through `node <script>`.
//
// When running the script with `npx hardhat run <script>` you'll find the Hardhat
// Runtime Environment's members available in the global scope.
import { ethers } from "hardhat";
import { Contract , ContractTransaction , ContractReceipt } from "ethers";
import { expect } from "chai";

async function main() {

    console.log('\n--------------------AETHER HUB----------------------------------\n')

    const [deployer] = await ethers.getSigners();
    const CIDS = [1234,4321];

    // define contract instances
    // and a common variable to each
    // with deployment-contract variable
    let AetherHUB:any,hub:Contract,hub_address:string='0xb5391Eb3F8Da436ebFAF882b2Db95802167A4A48';

    hub = await ethers.getContractAt("AetherHUB", hub_address);

    const masterHash = await hub.MASTER_HASH();
    const aetherBlock = await hub.aetherBlockNum();
    const nativeBlock = await hub.nativeBlockNum();
    const lastBlock = await hub.getABlock( aetherBlock );

    var blockKeys = lastBlock.slice(-3);
    console.log( 'Displaying 0xAetherHUB details :\n')

    console.log( `Latest Native Block : ${nativeBlock}` )
    console.log( `Latest Aether Block : ${aetherBlock}` )
    console.log( `Latest MASTERHASH : ${masterHash}`);
    
    console.log( `\n\tAether Block #${aetherBlock}` )
    console.log(`\t MASTER_HASH : ${blockKeys[0]}`);
    console.log(`\t TXN_COUNT : ${blockKeys[1]}`);
    console.log(`\t AETHERING_ADDR : ${blockKeys[2]}`);
    


}

// We recommend this pattern to be able to use async/await everywhere
// and properly handle errors.
main().catch((error) => {
  console.error(error);
  process.exitCode = 1;
});
