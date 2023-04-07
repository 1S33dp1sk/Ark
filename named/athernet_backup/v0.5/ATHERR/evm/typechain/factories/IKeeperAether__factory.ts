/* Autogenerated file. Do not edit manually. */
/* tslint:disable */
/* eslint-disable */

import { Contract, Signer, utils } from "ethers";
import { Provider } from "@ethersproject/providers";
import type { IKeeperAether, IKeeperAetherInterface } from "../IKeeperAether";

const _abi = [
  {
    inputs: [],
    name: "aetherSetup",
    outputs: [],
    stateMutability: "nonpayable",
    type: "function",
  },
  {
    inputs: [
      {
        internalType: "uint256",
        name: "",
        type: "uint256",
      },
    ],
    name: "getTicketMagic",
    outputs: [
      {
        internalType: "uint256",
        name: "",
        type: "uint256",
      },
    ],
    stateMutability: "nonpayable",
    type: "function",
  },
  {
    inputs: [
      {
        internalType: "uint256",
        name: "",
        type: "uint256",
      },
    ],
    name: "ticketOwner",
    outputs: [
      {
        internalType: "address",
        name: "",
        type: "address",
      },
    ],
    stateMutability: "view",
    type: "function",
  },
];

export class IKeeperAether__factory {
  static readonly abi = _abi;
  static createInterface(): IKeeperAetherInterface {
    return new utils.Interface(_abi) as IKeeperAetherInterface;
  }
  static connect(
    address: string,
    signerOrProvider: Signer | Provider
  ): IKeeperAether {
    return new Contract(address, _abi, signerOrProvider) as IKeeperAether;
  }
}
