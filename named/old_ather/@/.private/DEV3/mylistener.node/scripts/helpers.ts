import { ethers } from "hardhat";


export function toBytes(text:string){
    // Convert String To Bytes
    return ethers.utils.formatBytes32String(text)
  };

export function fromByts(bytes:any) {
    // Convert Bytes To String
    return ethers.utils.parseBytes32String(bytes);
  };