import { ethers } from "hardhat";


export async function Deployment(contract_name:string) {

    const Contract = await ethers.getContractFactory(contract_name);
    const contract = await Contract.deploy();
    await contract.deployed();
    return contract;
}


Deployment("Phase").catch((error) => {
    console.error(error);
    process.exitCode = 1;
  });