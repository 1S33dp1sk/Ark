/* Autogenerated file. Do not edit manually. */
/* tslint:disable */
/* eslint-disable */

import { Contract, Signer, utils } from "ethers";
import { Provider } from "@ethersproject/providers";
import type {
  IAetherFactory,
  IAetherFactoryInterface,
} from "../IAetherFactory";

const _abi = [
  {
    anonymous: false,
    inputs: [
      {
        indexed: true,
        internalType: "address",
        name: "Contract",
        type: "address",
      },
      {
        indexed: true,
        internalType: "address",
        name: "Proxy",
        type: "address",
      },
      {
        indexed: false,
        internalType: "uint256",
        name: "DeploymentID",
        type: "uint256",
      },
    ],
    name: "ContractDeployed",
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
      {
        indexed: false,
        internalType: "uint256",
        name: "Timestamp",
        type: "uint256",
      },
      {
        indexed: false,
        internalType: "uint256",
        name: "DeploymentID",
        type: "uint256",
      },
    ],
    name: "NodeDeployed",
    type: "event",
  },
  {
    anonymous: false,
    inputs: [
      {
        indexed: true,
        internalType: "address",
        name: "Proxy",
        type: "address",
      },
      {
        indexed: true,
        internalType: "address",
        name: "ProxyTo",
        type: "address",
      },
      {
        indexed: false,
        internalType: "uint256",
        name: "DeploymentID",
        type: "uint256",
      },
    ],
    name: "ProxyDeployed",
    type: "event",
  },
  {
    inputs: [],
    name: "aetherSetup",
    outputs: [],
    stateMutability: "nonpayable",
    type: "function",
  },
  {
    inputs: [],
    name: "contractsDeployed",
    outputs: [
      {
        internalType: "uint256",
        name: "",
        type: "uint256",
      },
    ],
    stateMutability: "view",
    type: "function",
  },
  {
    inputs: [
      {
        internalType: "bytes",
        name: "",
        type: "bytes",
      },
      {
        internalType: "uint256",
        name: "",
        type: "uint256",
      },
    ],
    name: "deployContract",
    outputs: [
      {
        internalType: "address",
        name: "",
        type: "address",
      },
    ],
    stateMutability: "nonpayable",
    type: "function",
  },
  {
    inputs: [],
    name: "deployNode",
    outputs: [
      {
        internalType: "address",
        name: "",
        type: "address",
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
      {
        internalType: "uint256",
        name: "",
        type: "uint256",
      },
    ],
    name: "deployProxy",
    outputs: [
      {
        internalType: "address",
        name: "",
        type: "address",
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
    name: "factoryIsNode",
    outputs: [
      {
        internalType: "bool",
        name: "",
        type: "bool",
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
    name: "factoryIsProxy",
    outputs: [
      {
        internalType: "bool",
        name: "",
        type: "bool",
      },
    ],
    stateMutability: "view",
    type: "function",
  },
  {
    inputs: [],
    name: "nodesDeployed",
    outputs: [
      {
        internalType: "uint256",
        name: "",
        type: "uint256",
      },
    ],
    stateMutability: "view",
    type: "function",
  },
  {
    inputs: [],
    name: "setupAether",
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
];

export class IAetherFactory__factory {
  static readonly abi = _abi;
  static createInterface(): IAetherFactoryInterface {
    return new utils.Interface(_abi) as IAetherFactoryInterface;
  }
  static connect(
    address: string,
    signerOrProvider: Signer | Provider
  ): IAetherFactory {
    return new Contract(address, _abi, signerOrProvider) as IAetherFactory;
  }
}
