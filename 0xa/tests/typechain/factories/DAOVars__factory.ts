/* Autogenerated file. Do not edit manually. */
/* tslint:disable */
/* eslint-disable */

import { Signer, utils, Contract, ContractFactory, Overrides } from "ethers";
import { Provider, TransactionRequest } from "@ethersproject/providers";
import type { DAOVars, DAOVarsInterface } from "../DAOVars";

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
        name: "AetherDAO",
        type: "address",
      },
      {
        indexed: false,
        internalType: "string",
        name: "VariableName",
        type: "string",
      },
      {
        indexed: false,
        internalType: "uint256",
        name: "VariableValue",
        type: "uint256",
      },
      {
        indexed: false,
        internalType: "uint256",
        name: "VariableOscillation",
        type: "uint256",
      },
    ],
    name: "VariableAdded",
    type: "event",
  },
  {
    anonymous: false,
    inputs: [
      {
        indexed: true,
        internalType: "address",
        name: "AetherDAO",
        type: "address",
      },
      {
        indexed: false,
        internalType: "bytes4",
        name: "VariableReference",
        type: "bytes4",
      },
      {
        indexed: false,
        internalType: "uint256",
        name: "VariableValue",
        type: "uint256",
      },
    ],
    name: "VariableChange",
    type: "event",
  },
  {
    inputs: [],
    name: "aetherBonds",
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
    name: "aetherDAO",
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
    name: "aetherFactory",
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
    name: "aetherHUB",
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
    name: "aetherID",
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
    name: "aetherKeeper",
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
    name: "aetherRouter",
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
    name: "aetherToken",
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
        internalType: "uint256",
        name: "contractId",
        type: "uint256",
      },
    ],
    name: "getAetherAddress",
    outputs: [
      {
        internalType: "address",
        name: "contractAddress",
        type: "address",
      },
    ],
    stateMutability: "view",
    type: "function",
  },
  {
    inputs: [
      {
        internalType: "bytes4",
        name: "varRef",
        type: "bytes4",
      },
    ],
    name: "getLastEdit",
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
        internalType: "string",
        name: "varName",
        type: "string",
      },
    ],
    name: "getLastEdit",
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
        internalType: "string",
        name: "varName",
        type: "string",
      },
    ],
    name: "getVar",
    outputs: [
      {
        internalType: "uint256",
        name: "variableValue",
        type: "uint256",
      },
      {
        internalType: "string",
        name: "variableName",
        type: "string",
      },
      {
        internalType: "uint256",
        name: "variableOsc",
        type: "uint256",
      },
    ],
    stateMutability: "view",
    type: "function",
  },
  {
    inputs: [
      {
        internalType: "bytes4",
        name: "varRef",
        type: "bytes4",
      },
    ],
    name: "getVar",
    outputs: [
      {
        internalType: "uint256",
        name: "variableValue",
        type: "uint256",
      },
      {
        internalType: "string",
        name: "variableName",
        type: "string",
      },
      {
        internalType: "uint256",
        name: "variableOsc",
        type: "uint256",
      },
    ],
    stateMutability: "view",
    type: "function",
  },
  {
    inputs: [
      {
        internalType: "bytes4",
        name: "varRef",
        type: "bytes4",
      },
    ],
    name: "getVarName",
    outputs: [
      {
        internalType: "string",
        name: "",
        type: "string",
      },
    ],
    stateMutability: "view",
    type: "function",
  },
  {
    inputs: [
      {
        internalType: "string",
        name: "varName",
        type: "string",
      },
    ],
    name: "getVarRef",
    outputs: [
      {
        internalType: "bytes4",
        name: "",
        type: "bytes4",
      },
    ],
    stateMutability: "pure",
    type: "function",
  },
  {
    inputs: [
      {
        internalType: "string",
        name: "varName",
        type: "string",
      },
    ],
    name: "getVarVal",
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
        internalType: "bytes4",
        name: "varRef",
        type: "bytes4",
      },
    ],
    name: "getVarVal",
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
        internalType: "bytes4",
        name: "varRef",
        type: "bytes4",
      },
    ],
    name: "varExists",
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
        internalType: "string",
        name: "varName",
        type: "string",
      },
    ],
    name: "varExists",
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
];

const _bytecode =
  "0x60806040523480156200001157600080fd5b50620000606040518060400160405280600c81526020017f70726f706f73616c54696d650000000000000000000000000000000000000000815250620a0668622819a06200055060201b60201c565b50620000ad6040518060400160405280601081526020017f7369676e6572735468726573686f6c6400000000000000000000000000000000815250600262140cd06200055060201b60201c565b50620001046040518060400160405280600d81526020017f6e6f64655468726573686f6c64000000000000000000000000000000000000008152506a084595161401484a00000062784ce06200055060201b60201c565b50620001546040518060400160405280600f81526020017f6e6f64655374616b696e6754696d6500000000000000000000000000000000008152506301e1338062784ce06200055060201b60201c565b50620001a36040518060400160405280601081526020017f626f6e644d6174757269747954696d6500000000000000000000000000000000815250626ebe0062784ce06200055060201b60201c565b50620001ed6040518060400160405280601481526020017f7472616e73616374696f6e5468726573686f6c640000000000000000000000008152504560006200055060201b60201c565b50620002416040518060400160405280600f81526020017f686f6c6465725468726573686f6c64000000000000000000000000000000000081525069d3c21bcecceda100000060006200055060201b60201c565b506200028e6040518060400160405280600f81526020017f7265776172647354726561737572790000000000000000000000000000000000815250603c62140cd06200055060201b60201c565b50620002db6040518060400160405280601181526020017f74726561737572795468726573686f6c64000000000000000000000000000000815250600162784ce06200055060201b60201c565b50620003266040518060400160405280601381526020017f6465706c6574696f6e4d756c7469706c69657200000000000000000000000000815250603260006200055060201b60201c565b50620003716040518060400160405280601081526020017f6465706c6574696f6e44697669736f7200000000000000000000000000000000815250606460006200055060201b60201c565b50620003be6040518060400160405280600c81526020017f7265776172644c6564676572000000000000000000000000000000000000000081525060056203f4806200055060201b60201c565b506200040b6040518060400160405280600881526020017f67617350726963650000000000000000000000000000000000000000000000008152506023620151806200055060201b60201c565b50620004626040518060400160405280600981526020017f74617267657447617300000000000000000000000000000000000000000000008152506c0c9f2c9cd04674edea4000000060006200055060201b60201c565b50620004af6040518060400160405280601281526020017f7461726765745472616e73616374696f6e7300000000000000000000000000008152506298968060006200055060201b60201c565b50620004fc6040518060400160405280600681526020017f4d61784250420000000000000000000000000000000000000000000000000000815250600a620151806200055060201b60201c565b50620005496040518060400160405280600681526020017f4d617854504200000000000000000000000000000000000000000000000000008152506003620151806200055060201b60201c565b5062000adb565b600062000563846200076760201b60201c565b9050600060026000837bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19167bffffffffffffffffffffffffffffffffffffffffffffffffffffffff191681526020019081526020016000206002015414620005ff576040517f08c379a0000000000000000000000000000000000000000000000000000000008152600401620005f6906200098a565b60405180910390fd5b600082146200060f578162000612565b60015b915060405180606001604052808481526020018581526020018381525060026000837bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19167bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19168152602001908152602001600020600082015181600001556020820151816001019080519060200190620006a892919062000799565b50604082015181600201559050504260036000837bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19167bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19168152602001908152602001600020819055503073ffffffffffffffffffffffffffffffffffffffff167fcc182ad97b7e6767e6f1450d65d318e2dd9183580b6ef05d5d99800ec74602b2858585604051620007589392919062000946565b60405180910390a29392505050565b6000816040516020016200077c919062000920565b604051602081830303815290604052805190602001209050919050565b828054620007a79062000a13565b90600052602060002090601f016020900481019282620007cb576000855562000817565b82601f10620007e657805160ff191683800117855562000817565b8280016001018555821562000817579182015b8281111562000816578251825591602001919060010190620007f9565b5b5090506200082691906200082a565b5090565b5b80821115620008455760008160009055506001016200082b565b5090565b60006200085682620009ac565b620008628185620009b7565b935062000874818560208601620009dd565b6200087f8162000a78565b840191505092915050565b60006200089782620009ac565b620008a38185620009c8565b9350620008b5818560208601620009dd565b80840191505092915050565b6000620008d0600283620009c8565b9150620008dd8262000a89565b600282019050919050565b6000620008f7601d83620009b7565b9150620009048262000ab2565b602082019050919050565b6200091a81620009d3565b82525050565b60006200092e82846200088a565b91506200093b82620008c1565b915081905092915050565b6000606082019050818103600083015262000962818662000849565b90506200097360208301856200090f565b6200098260408301846200090f565b949350505050565b60006020820190508181036000830152620009a581620008e8565b9050919050565b600081519050919050565b600082825260208201905092915050565b600081905092915050565b6000819050919050565b60005b83811015620009fd578082015181840152602081019050620009e0565b8381111562000a0d576000848401525b50505050565b6000600282049050600182168062000a2c57607f821691505b6020821081141562000a435762000a4262000a49565b5b50919050565b7f4e487b7100000000000000000000000000000000000000000000000000000000600052602260045260246000fd5b6000601f19601f8301169050919050565b7f2829000000000000000000000000000000000000000000000000000000000000600082015250565b7f54686973207661726961626c6520726566206973206f63637570696564000000600082015250565b6115758062000aeb6000396000f3fe608060405234801561001057600080fd5b50600436106101215760003560e01c80635fd1cf26116100ad5780639fa59f00116100715780639fa59f0014610370578063a74a3685146103a0578063dc601352146103d0578063ec238238146103ee578063eccda8df1461040c57610121565b80635fd1cf2614610290578063689051f2146102ae5780636ebd065a146102e05780637bf45933146103105780639ddd6c831461034057610121565b8063206dffa0116100f4578063206dffa0146101c457806346f733f8146101f45780635096c4391461021257806350ef7d2014610242578063513404291461026057610121565b8063081dd5ff14610126578063177a6ce5146101445780631e4433c4146101625780631ecc918614610194575b600080fd5b61012e61042a565b60405161013b919061116e565b60405180910390f35b61014c6104e2565b604051610159919061116e565b60405180910390f35b61017c60048036038101906101779190610fd3565b61059a565b60405161018b9392919061123c565b60405180910390f35b6101ae60048036038101906101a99190610faa565b6105be565b6040516101bb91906111bf565b60405180910390f35b6101de60048036038101906101d99190610fd3565b6106a4565b6040516101eb9190611221565b60405180910390f35b6101fc6106be565b604051610209919061116e565b60405180910390f35b61022c60048036038101906102279190610faa565b610776565b6040516102399190611189565b60405180910390f35b61024a6107d7565b6040516102579190611221565b60405180910390f35b61027a60048036038101906102759190610faa565b6107e0565b6040516102879190611221565b60405180910390f35b61029861083e565b6040516102a5919061116e565b60405180910390f35b6102c860048036038101906102c39190610faa565b6108f5565b6040516102d79392919061123c565b60405180910390f35b6102fa60048036038101906102f59190610faa565b610a1d565b6040516103079190611221565b60405180910390f35b61032a60048036038101906103259190610fd3565b610a78565b6040516103379190611221565b60405180910390f35b61035a60048036038101906103559190610fd3565b610a92565b6040516103679190611189565b60405180910390f35b61038a60048036038101906103859190610fd3565b610aac565b60405161039791906111a4565b60405180910390f35b6103ba60048036038101906103b59190611014565b610adc565b6040516103c7919061116e565b60405180910390f35b6103d8610b5d565b6040516103e5919061116e565b60405180910390f35b6103f6610c15565b604051610403919061116e565b60405180910390f35b610414610ccd565b604051610421919061116e565b60405180910390f35b60003073ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff16141561049b576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040161049290611201565b60405180910390fd5b6104dd600160068111156104d8577f4e487b7100000000000000000000000000000000000000000000000000000000600052602160045260246000fd5b610d85565b905090565b60003073ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff161415610553576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040161054a90611201565b60405180910390fd5b61059560046006811115610590577f4e487b7100000000000000000000000000000000000000000000000000000000600052602160045260246000fd5b610d85565b905090565b6000606060006105b16105ac85610aac565b6108f5565b9250925092509193909250565b606060026000837bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19167bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19168152602001908152602001600020600101805461061f906113ad565b80601f016020809104026020016040519081016040528092919081815260200182805461064b906113ad565b80156106985780601f1061066d57610100808354040283529160200191610698565b820191906000526020600020905b81548152906001019060200180831161067b57829003601f168201915b50505050509050919050565b60006106b76106b283610aac565b6107e0565b9050919050565b60003073ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff16141561072f576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040161072690611201565b60405180910390fd5b6107716005600681111561076c577f4e487b7100000000000000000000000000000000000000000000000000000000600052602160045260246000fd5b610d85565b905090565b60008060026000847bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19167bffffffffffffffffffffffffffffffffffffffffffffffffffffffff191681526020019081526020016000206002015414159050919050565b60008054905090565b600060026000837bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19167bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19168152602001908152602001600020600001549050919050565b60003073ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff1614156108af576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004016108a690611201565b60405180910390fd5b6108f06006808111156108eb577f4e487b7100000000000000000000000000000000000000000000000000000000600052602160045260246000fd5b610d85565b905090565b6000606060008060026000867bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19167bffffffffffffffffffffffffffffffffffffffffffffffffffffffff1916815260200190815260200160002060405180606001604052908160008201548152602001600182018054610972906113ad565b80601f016020809104026020016040519081016040528092919081815260200182805461099e906113ad565b80156109eb5780601f106109c0576101008083540402835291602001916109eb565b820191906000526020600020905b8154815290600101906020018083116109ce57829003601f168201915b505050505081526020016002820154815250509050806000015193508060200151925080604001519150509193909250565b600060036000837bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19167bffffffffffffffffffffffffffffffffffffffffffffffffffffffff19168152602001908152602001600020549050919050565b6000610a8b610a8683610aac565b610a1d565b9050919050565b6000610aa5610aa083610aac565b610776565b9050919050565b600081604051602001610abf919061114c565b604051602081830303815290604052805190602001209050919050565b60003073ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff161415610b4d576040517f08c379a0000000000000000000000000000000000000000000000000000000008152600401610b4490611201565b60405180910390fd5b610b5682610d85565b9050919050565b60003073ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff161415610bce576040517f08c379a0000000000000000000000000000000000000000000000000000000008152600401610bc590611201565b60405180910390fd5b610c1060026006811115610c0b577f4e487b7100000000000000000000000000000000000000000000000000000000600052602160045260246000fd5b610d85565b905090565b60003073ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff161415610c86576040517f08c379a0000000000000000000000000000000000000000000000000000000008152600401610c7d90611201565b60405180910390fd5b610cc860006006811115610cc3577f4e487b7100000000000000000000000000000000000000000000000000000000600052602160045260246000fd5b610d85565b905090565b60003073ffffffffffffffffffffffffffffffffffffffff163373ffffffffffffffffffffffffffffffffffffffff161415610d3e576040517f08c379a0000000000000000000000000000000000000000000000000000000008152600401610d3590611201565b60405180910390fd5b610d8060036006811115610d7b577f4e487b7100000000000000000000000000000000000000000000000000000000600052602160045260246000fd5b610d85565b905090565b6000600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1663a74a3685836040518263ffffffff1660e01b8152600401610de29190611221565b60206040518083038186803b158015610dfa57600080fd5b505afa925050508015610e2b57506040513d601f19601f82011682018060405250810190610e289190610f81565b60015b610ed0573d8060008114610e5b576040519150601f19603f3d011682016040523d82523d6000602084013e610e60565b606091505b506000831415610e9557600160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff16915050610ed5565b6040517f08c379a0000000000000000000000000000000000000000000000000000000008152600401610ec7906111e1565b60405180910390fd5b809150505b919050565b6000610eed610ee88461129f565b61127a565b905082815260208101848484011115610f0557600080fd5b610f1084828561136b565b509392505050565b600081519050610f27816114fa565b92915050565b600081359050610f3c81611511565b92915050565b600082601f830112610f5357600080fd5b8135610f63848260208601610eda565b91505092915050565b600081359050610f7b81611528565b92915050565b600060208284031215610f9357600080fd5b6000610fa184828501610f18565b91505092915050565b600060208284031215610fbc57600080fd5b6000610fca84828501610f2d565b91505092915050565b600060208284031215610fe557600080fd5b600082013567ffffffffffffffff811115610fff57600080fd5b61100b84828501610f42565b91505092915050565b60006020828403121561102657600080fd5b600061103484828501610f6c565b91505092915050565b611046816112f7565b82525050565b61105581611309565b82525050565b61106481611315565b82525050565b6000611075826112d0565b61107f81856112db565b935061108f81856020860161137a565b6110988161146e565b840191505092915050565b60006110ae826112d0565b6110b881856112ec565b93506110c881856020860161137a565b80840191505092915050565b60006110e1601d836112db565b91506110ec8261147f565b602082019050919050565b60006111046002836112ec565b915061110f826114a8565b600282019050919050565b6000611127600e836112db565b9150611132826114d1565b602082019050919050565b61114681611361565b82525050565b600061115882846110a3565b9150611163826110f7565b915081905092915050565b6000602082019050611183600083018461103d565b92915050565b600060208201905061119e600083018461104c565b92915050565b60006020820190506111b9600083018461105b565b92915050565b600060208201905081810360008301526111d9818461106a565b905092915050565b600060208201905081810360008301526111fa816110d4565b9050919050565b6000602082019050818103600083015261121a8161111a565b9050919050565b6000602082019050611236600083018461113d565b92915050565b6000606082019050611251600083018661113d565b8181036020830152611263818561106a565b9050611272604083018461113d565b949350505050565b6000611284611295565b905061129082826113df565b919050565b6000604051905090565b600067ffffffffffffffff8211156112ba576112b961143f565b5b6112c38261146e565b9050602081019050919050565b600081519050919050565b600082825260208201905092915050565b600081905092915050565b600061130282611341565b9050919050565b60008115159050919050565b60007fffffffff0000000000000000000000000000000000000000000000000000000082169050919050565b600073ffffffffffffffffffffffffffffffffffffffff82169050919050565b6000819050919050565b82818337600083830152505050565b60005b8381101561139857808201518184015260208101905061137d565b838111156113a7576000848401525b50505050565b600060028204905060018216806113c557607f821691505b602082108114156113d9576113d8611410565b5b50919050565b6113e88261146e565b810181811067ffffffffffffffff821117156114075761140661143f565b5b80604052505050565b7f4e487b7100000000000000000000000000000000000000000000000000000000600052602260045260246000fd5b7f4e487b7100000000000000000000000000000000000000000000000000000000600052604160045260246000fd5b6000601f19601f8301169050919050565b7f41657468657220436f6e7472616374204944204e6f7420526f75746564000000600082015250565b7f2829000000000000000000000000000000000000000000000000000000000000600082015250565b7f726563757373696f6e2076696577000000000000000000000000000000000000600082015250565b611503816112f7565b811461150e57600080fd5b50565b61151a81611315565b811461152557600080fd5b50565b61153181611361565b811461153c57600080fd5b5056fea264697066735822122015887e8c72f01960458c93e97c908666211cbbb50531af8db95c252d5a14bbbb64736f6c63430008040033";

export class DAOVars__factory extends ContractFactory {
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
  ): Promise<DAOVars> {
    return super.deploy(overrides || {}) as Promise<DAOVars>;
  }
  getDeployTransaction(
    overrides?: Overrides & { from?: string | Promise<string> }
  ): TransactionRequest {
    return super.getDeployTransaction(overrides || {});
  }
  attach(address: string): DAOVars {
    return super.attach(address) as DAOVars;
  }
  connect(signer: Signer): DAOVars__factory {
    return super.connect(signer) as DAOVars__factory;
  }
  static readonly bytecode = _bytecode;
  static readonly abi = _abi;
  static createInterface(): DAOVarsInterface {
    return new utils.Interface(_abi) as DAOVarsInterface;
  }
  static connect(
    address: string,
    signerOrProvider: Signer | Provider
  ): DAOVars {
    return new Contract(address, _abi, signerOrProvider) as DAOVars;
  }
}
