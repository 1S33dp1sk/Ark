/* Autogenerated file. Do not edit manually. */
/* tslint:disable */
/* eslint-disable */

import { Contract, Signer, utils } from "ethers";
import { Provider } from "@ethersproject/providers";
import type { IAccess, IAccessInterface } from "../IAccess";

const _abi = [
  {
    anonymous: false,
    inputs: [
      {
        indexed: true,
        internalType: "address",
        name: "Node",
        type: "address",
      },
      {
        indexed: true,
        internalType: "address",
        name: "AccessTo",
        type: "address",
      },
    ],
    name: "AccessGranted",
    type: "event",
  },
  {
    anonymous: false,
    inputs: [
      {
        indexed: true,
        internalType: "address",
        name: "Node",
        type: "address",
      },
      {
        indexed: true,
        internalType: "address",
        name: "AccessTo",
        type: "address",
      },
    ],
    name: "AccessRevoked",
    type: "event",
  },
  {
    anonymous: false,
    inputs: [
      {
        indexed: true,
        internalType: "address",
        name: "Node",
        type: "address",
      },
      {
        indexed: true,
        internalType: "address",
        name: "Owner",
        type: "address",
      },
    ],
    name: "NodeInitialized",
    type: "event",
  },
  {
    inputs: [
      {
        internalType: "address",
        name: "",
        type: "address",
      },
    ],
    name: "addAccess",
    outputs: [
      {
        internalType: "bool",
        name: "",
        type: "bool",
      },
    ],
    stateMutability: "nonpayable",
    type: "function",
  },
  {
    inputs: [],
    name: "owner",
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
  {
    inputs: [
      {
        internalType: "address",
        name: "",
        type: "address",
      },
    ],
    name: "revokeAccess",
    outputs: [
      {
        internalType: "bool",
        name: "",
        type: "bool",
      },
    ],
    stateMutability: "nonpayable",
    type: "function",
  },
  {
    inputs: [
      {
        internalType: "address",
        name: "",
        type: "address",
      },
    ],
    name: "setOwner",
    outputs: [],
    stateMutability: "nonpayable",
    type: "function",
  },
];

export class IAccess__factory {
  static readonly abi = _abi;
  static createInterface(): IAccessInterface {
    return new utils.Interface(_abi) as IAccessInterface;
  }
  static connect(
    address: string,
    signerOrProvider: Signer | Provider
  ): IAccess {
    return new Contract(address, _abi, signerOrProvider) as IAccess;
  }
}
