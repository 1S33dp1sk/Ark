import { ethers } from "hardhat";
import { fromByts } from "./helpers";

const PORT:number = 8545;
// const ACCESS_SOCKET:string = 'WSS';
const ACCESS_PROTOCOL:string = 'ETHEREUM_1';
const LISTENER_FOR:string = '0x5fbdb2315678afecb367f032d93f642f64180aa3';



async function listnerWrapper(contract_name:string, contract_address:string){
    let contract:any;
    if(!contract){
        contract = await ethers.getContractAt(contract_name ,contract_address);
    }
    contract.on("Phase", (AccessPath:string, data:string,Sender:string, Caller:string, Exec:string) => {
        console.log("THIS IS ACCESS PATH", fromByts(AccessPath));
        console.log("THIS IS DATA", fromByts(data));
        console.log("THIS IS SENDER", Sender);
        console.log("THIS IS CALLER", Caller);
        console.log("THIS IS EXEC", fromByts(Exec));
        console.log('------------------------------\n')
    });
};


listnerWrapper("Phase", "0x5fbdb2315678afecb367f032d93f642f64180aa3");