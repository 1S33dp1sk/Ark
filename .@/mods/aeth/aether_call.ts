// We require the Hardhat Runtime Environment explicitly here. This is optional
// but useful for running the script in a standalone fashion through `node <script>`.
//
// When running the script with `npx hardhat run <script>` you'll find the Hardhat
// Runtime Environment's members available in the global scope.
import { ethers } from "hardhat";
import { Contract , ContractTransaction , ContractReceipt } from "ethers";
import { expect } from "chai";

export default function __call = async () => {

    console.log('\n--------------------AETHER DEPLOYMENT----------------------------------\n')

    const [deployer] = await ethers.getSigners();
    console.log("Deploying contracts with the account:", deployer.address);
    const CIDS = [1234,4321];

    // define contract instances
    // and a common variable to each
    // with deployment-contract variable
    let AetherHUB:any,hub:Contract,hub_address:string='0xb5391Eb3F8Da436ebFAF882b2Db95802167A4A48';
    let AetherReceiver:any,receiver:Contract,receiver_address:string='0xB28a3900E0233cD69CD77f6f35C0c87cae8104AE';

    let WAIT_TIME=10000

    hub = await ethers.getContractAt("AetherHUB", hub_address);
    receiver = await ethers.getContractAt("AetherReceiver" , receiver_address);

    const temp = await receiver.setAetherHUB( hub_address );

    console.log('\n Send 0xAether Transaction : (uint256 Value)')
    
    var stdin = process.openStdin();
    stdin.addListener("data", async function(d) {
    // note:  d is an object, and when converted to a string it will
        // end with a linefeed.  so we (rather crudely) account for that  
        // with toString() and then substring() 
        var _value = d.toString().trim();
        var _txn
        try{
          _txn = await receiver.setValue( _value );
        }catch(ex){
          console.log('Exception for set value');
          console.log(ex)
          process.exit(0)
        }


        console.log( 'Setting value via AetherHUB : ' , _value );
        var _currentValue = await receiver.getValue();
        console.log( 'Checking `current` value after Transacting : ' , _currentValue.toString() );
        
        setTimeout( async function() {
          console.log( 'Checking after X amount of seconds. x = ' , (WAIT_TIME/1000).toString() );
          const currentValue_ = await receiver.getValue();
          console.log( 'Checking `current` value  : ' , currentValue_  )
        } , WAIT_TIME );
        process.exit(0);
    });
};

async function main() {
  return await __call();
};

// We recommend this pattern to be able to use async/await everywhere
// and properly handle errors.
main().catch((error) => {
  console.error(error);
  process.exitCode = 1;
});
