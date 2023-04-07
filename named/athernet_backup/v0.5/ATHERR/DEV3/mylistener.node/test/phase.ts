const { expect } = require("chai");
import { ethers } from "hardhat";

describe("phase1 contract", function () {
  it("Deployment should test event", async function () {

    const [owner] = await ethers.getSigners();
    const _caller = ethers.Wallet.createRandom();


    const _accessPath = toBytes("ACCESS PATH EXAMPLE");
    const _data = toBytes("DATA SAMPLE");
    const _exec = toBytes("EXECUTION SAMPLE");

    const Phase1 = await ethers.getContractFactory("Phase");
    const phase1 = await Phase1.deploy();

    function toBytes(text:string){
        return ethers.utils.formatBytes32String(text)
      };
    

    await expect(phase1.testPhase(_accessPath, _data, owner.address, _caller.address, _exec ));
});
});