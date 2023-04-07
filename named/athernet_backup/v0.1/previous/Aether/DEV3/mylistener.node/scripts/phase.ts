import { ethers } from "hardhat";
import { Deployment } from "./deployment";
import { fromByts, toBytes } from "./helpers";

async function main() {
  const [owner] = await ethers.getSigners();
  const _caller = ethers.Wallet.createRandom();


  var _accessPath = toBytes("ACCESS PATH EXAMPLE");
  var _data = toBytes("DATA SAMPLE");
  var _exec = toBytes("EXECUTION SAMPLE");

  const phase1 = await ethers.getContractAt("Phase", "0x5fbdb2315678afecb367f032d93f642f64180aa3");
  
  await phase1.testPhase(_accessPath, _data, owner.address, _caller.address, _exec );
}

main().catch((error) => {
  console.error(error);
  process.exitCode = 1;
});
