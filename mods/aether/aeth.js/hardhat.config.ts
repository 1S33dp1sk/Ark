import * as dotenv from "dotenv";

import { HardhatUserConfig, task } from "hardhat/config";
import "@nomiclabs/hardhat-etherscan";
import "@nomiclabs/hardhat-waffle";
import "@typechain/hardhat";
import "hardhat-gas-reporter";
import "solidity-coverage";
require("@nomiclabs/hardhat-ganache");


dotenv.config();

// This is a sample Hardhat task. To learn how to create your own go to
// https://hardhat.org/guides/create-task.html
task("accounts", "Prints the list of accounts", async (taskArgs, hre) => {
  const accounts = await hre.ethers.getSigners();

  for (const account of accounts) {
    console.log(account.address);
  }
});



const DEPLOYMENT_PVT = "0xc9ff8606e315a8bb8ab276f925485bb8cd5bd8f65bd479824292fb54274ff98d";

// You need to export an object to set up your config
// Go to https://hardhat.org/config/ to learn more

const config: HardhatUserConfig = {
  solidity: "0.8.4",
  networks: {
    ropsten: {
      url: process.env.ROPSTEN_URL || "",
      accounts:
        process.env.PRIVATE_KEY !== undefined ? [process.env.PRIVATE_KEY] : [],
    },
    cid1234: {
      url:"http://127.0.0.1:1234", // ganache-cli --p 1234 -l 10000000
      accounts:[`${DEPLOYMENT_PVT}`]
    },
    cid4321: {
      url:"http://127.0.0.1:4321", // ganache-cli --p 1234 -l 10000000
      accounts:[`${DEPLOYMENT_PVT}`]
    },
    bsc :{
      url:"https://morning-divine-grass.bsc.quiknode.pro/d5c3b0e0146331d619942b021d5b91ddafedceb5/",
      accounts:[`${DEPLOYMENT_PVT}`]
    },
    polygon: {
      url:"https://ancient-wandering-night.matic.quiknode.pro/cc5ced2ac9d5fdb859383f111d776d79c0bb1bca/",
      accounts:[`${DEPLOYMENT_PVT}`]
    },
  },
  gasReporter: {
    enabled: process.env.REPORT_GAS !== undefined,
    currency: "USD",
  },
  etherscan: {
    apiKey: process.env.ETHERSCAN_API_KEY,
  },
};

export default config;
