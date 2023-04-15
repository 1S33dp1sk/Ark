// We require the Hardhat Runtime Environment explicitly here. This is optional
// but useful for running the script in a standalone fashion through `node <script>`.
//
// When running the script with `npx hardhat run <script>` you'll find the Hardhat
// Runtime Environment's members available in the global scope.
import { ethers } from "hardhat";
import { Contract , ContractTransaction , ContractReceipt } from "ethers";
import { expect } from "chai";

export default function __mine = async () => {
    console.log('\n--------------------MINE BLOCK----------------------------------\n')

    const time = ( new Date().getTime() / 1000 ) + 10
  await ethers.provider.send('evm_mine', [time]);
};

async function main() {

  return await __mine();
};

// We recommend this pattern to be able to use async/await everywhere
// and properly handle errors.
main().catch((error) => {
  console.error(error);
  process.exitCode = 1;
});
