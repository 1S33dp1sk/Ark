/* Autogenerated file. Do not edit manually. */
/* tslint:disable */
/* eslint-disable */

import { Signer, utils, Contract, ContractFactory, Overrides } from "ethers";
import { Provider, TransactionRequest } from "@ethersproject/providers";
import type { Access, AccessInterface } from "../Access";

const _abi = [
  {
    inputs: [],
    stateMutability: "nonpayable",
    type: "constructor",
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
    inputs: [],
    name: "AETHER_FACTORY",
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
    inputs: [],
    name: "AETHER_HUB",
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
        name: "addr",
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
        name: "addr",
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
        name: "nodeOwner",
        type: "address",
      },
    ],
    name: "setOwner",
    outputs: [],
    stateMutability: "nonpayable",
    type: "function",
  },
];

const _bytecode =
  "0x60c060405234801561001057600080fd5b503373ffffffffffffffffffffffffffffffffffffffff1660a08173ffffffffffffffffffffffffffffffffffffffff1660601b815250503373ffffffffffffffffffffffffffffffffffffffff1663177a6ce56040518163ffffffff1660e01b815260040160206040518083038186803b15801561008e57600080fd5b505afa1580156100a2573d6000803e3d6000fd5b505050506040513d601f19601f820116820180604052508101906100c69190610116565b73ffffffffffffffffffffffffffffffffffffffff1660808173ffffffffffffffffffffffffffffffffffffffff1660601b81525050610188565b60008151905061011081610171565b92915050565b60006020828403121561012857600080fd5b600061013684828501610101565b91505092915050565b600061014a82610151565b9050919050565b600073ffffffffffffffffffffffffffffffffffffffff82169050919050565b61017a8161013f565b811461018557600080fd5b50565b60805160601c60a05160601c61071c6101c16000396000818161013f015281816102e701526104a0015260006104c7015261071c6000f3fe608060405234801561001057600080fd5b50600436106100625760003560e01c806313af4035146100675780632ba785d21461008357806385e68531146100a15780638da5cb5b146100d1578063956e8d94146100ef578063a118f2491461010d575b600080fd5b610081600480360381019061007c9190610614565b61013d565b005b61008b6102e5565b604051610098919061065b565b60405180910390f35b6100bb60048036038101906100b69190610614565b610309565b6040516100c89190610676565b60405180910390f35b6100d961041f565b6040516100e6919061065b565b60405180910390f35b6100f76104c5565b604051610104919061065b565b60405180910390f35b61012760048036038101906101229190610614565b6104e9565b6040516101349190610676565b60405180910390f35b7f000000000000000000000000000000000000000000000000000000000000000073ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff161461019557600080fd5b600073ffffffffffffffffffffffffffffffffffffffff16600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16146101f057600080fd5b80600160006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555060016000808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060006101000a81548160ff0219169083151502179055508073ffffffffffffffffffffffffffffffffffffffff163073ffffffffffffffffffffffffffffffffffffffff167f97492b5e72b9ce49a6924a36bf80057224c4534c684957c92be22b2410bd338f60405160405180910390a350565b7f000000000000000000000000000000000000000000000000000000000000000081565b6000600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff161461036557600080fd5b60008060008473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060006101000a81548160ff0219169083151502179055508173ffffffffffffffffffffffffffffffffffffffff163073ffffffffffffffffffffffffffffffffffffffff167f825c8be24eb0df19500f63e86c29e7d0d951e73056b889b891d85e40938d9b6e60405160405180910390a360019050919050565b60008073ffffffffffffffffffffffffffffffffffffffff16600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff161461049e57600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff166104c0565b7f00000000000000000000000000000000000000000000000000000000000000005b905090565b7f000000000000000000000000000000000000000000000000000000000000000081565b6000600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff161461054557600080fd5b60016000808473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060006101000a81548160ff0219169083151502179055508173ffffffffffffffffffffffffffffffffffffffff163073ffffffffffffffffffffffffffffffffffffffff167f9f520b3bfc56d06f7065d10b4683b3f57ac8895d5026cd176dee95ce1454cb8d60405160405180910390a360019050919050565b60008135905061060e816106cf565b92915050565b60006020828403121561062657600080fd5b6000610634848285016105ff565b91505092915050565b61064681610691565b82525050565b610655816106a3565b82525050565b6000602082019050610670600083018461063d565b92915050565b600060208201905061068b600083018461064c565b92915050565b600061069c826106af565b9050919050565b60008115159050919050565b600073ffffffffffffffffffffffffffffffffffffffff82169050919050565b6106d881610691565b81146106e357600080fd5b5056fea26469706673582212208fc28d54ef0bc2630767958e41d5f38c61c6fdad61d1e82f0a41be90a0ae0d8c64736f6c63430008040033";

export class Access__factory extends ContractFactory {
  constructor(
    ...args: [signer: Signer] | ConstructorParameters<typeof ContractFactory>
  ) {
    if (args.length === 1) {
      super(_abi, _bytecode, args[0]);
    } else {
      super(...args);
    }
  }

  deploy(
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<Access> {
    return super.deploy(overrides || {}) as Promise<Access>;
  }
  getDeployTransaction(
    overrides?: Overrides & { from?: string | Promise<string> }
  ): TransactionRequest {
    return super.getDeployTransaction(overrides || {});
  }
  attach(address: string): Access {
    return super.attach(address) as Access;
  }
  connect(signer: Signer): Access__factory {
    return super.connect(signer) as Access__factory;
  }
  static readonly bytecode = _bytecode;
  static readonly abi = _abi;
  static createInterface(): AccessInterface {
    return new utils.Interface(_abi) as AccessInterface;
  }
  static connect(address: string, signerOrProvider: Signer | Provider): Access {
    return new Contract(address, _abi, signerOrProvider) as Access;
  }
}
