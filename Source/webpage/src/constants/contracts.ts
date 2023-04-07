export const CONTRACTS = {
    'HUB':{
        address:"0x7B641b9aBA6a32Dc6F8Db378247fa50B8fab09be",
        abi:[
            {
              "inputs": [],
              "stateMutability": "nonpayable",
              "type": "constructor"
            },
            {
              "anonymous": false,
              "inputs": [
                {
                  "indexed": false,
                  "internalType": "uint256",
                  "name": "ABlockNum",
                  "type": "uint256"
                },
                {
                  "indexed": false,
                  "internalType": "bytes32",
                  "name": "ABlockMasterHash",
                  "type": "bytes32"
                },
                {
                  "indexed": false,
                  "internalType": "uint256",
                  "name": "ABlockTxnCount",
                  "type": "uint256"
                },
                {
                  "indexed": false,
                  "internalType": "bytes20",
                  "name": "ABlockAethering",
                  "type": "bytes20"
                },
                {
                  "indexed": false,
                  "internalType": "uint256",
                  "name": "NBlockNum",
                  "type": "uint256"
                }
              ],
              "name": "ABlockBind",
              "type": "event"
            },
            {
              "anonymous": false,
              "inputs": [
                {
                  "indexed": false,
                  "internalType": "bytes16",
                  "name": "ATxnHash",
                  "type": "bytes16"
                }
              ],
              "name": "ATxnReceive",
              "type": "event"
            },
            {
              "anonymous": false,
              "inputs": [
                {
                  "indexed": false,
                  "internalType": "bytes16",
                  "name": "ATxnHash",
                  "type": "bytes16"
                },
                {
                  "indexed": false,
                  "internalType": "bool",
                  "name": "ATxnResult",
                  "type": "bool"
                }
              ],
              "name": "ATxnRequest",
              "type": "event"
            },
            {
              "anonymous": false,
              "inputs": [
                {
                  "indexed": false,
                  "internalType": "address",
                  "name": "ANodeAddress",
                  "type": "address"
                },
                {
                  "indexed": false,
                  "internalType": "uint256",
                  "name": "ANodePos",
                  "type": "uint256"
                },
                {
                  "indexed": false,
                  "internalType": "uint256",
                  "name": "ANodesPtr",
                  "type": "uint256"
                }
              ],
              "name": "NodeRegistered",
              "type": "event"
            },
            {
              "inputs": [],
              "name": "MASTER_HASH",
              "outputs": [
                {
                  "internalType": "bytes32",
                  "name": "",
                  "type": "bytes32"
                }
              ],
              "stateMutability": "view",
              "type": "function"
            },
            {
              "inputs": [],
              "name": "MAX_BLOCKS",
              "outputs": [
                {
                  "internalType": "uint256",
                  "name": "",
                  "type": "uint256"
                }
              ],
              "stateMutability": "view",
              "type": "function"
            },
            {
              "inputs": [],
              "name": "MAX_TXNS",
              "outputs": [
                {
                  "internalType": "uint256",
                  "name": "",
                  "type": "uint256"
                }
              ],
              "stateMutability": "view",
              "type": "function"
            },
            {
              "inputs": [
                {
                  "internalType": "address",
                  "name": "aCaller",
                  "type": "address"
                },
                {
                  "internalType": "bytes4",
                  "name": "aSelector",
                  "type": "bytes4"
                },
                {
                  "internalType": "bytes",
                  "name": "aArgs",
                  "type": "bytes"
                }
              ],
              "name": "addTransaction",
              "outputs": [
                {
                  "internalType": "bool",
                  "name": "",
                  "type": "bool"
                }
              ],
              "stateMutability": "nonpayable",
              "type": "function"
            },
            {
              "inputs": [],
              "name": "aetherBlockNum",
              "outputs": [
                {
                  "internalType": "uint256",
                  "name": "",
                  "type": "uint256"
                }
              ],
              "stateMutability": "view",
              "type": "function"
            },
            {
              "inputs": [],
              "name": "aetheringAddress",
              "outputs": [
                {
                  "internalType": "bytes20",
                  "name": "",
                  "type": "bytes20"
                }
              ],
              "stateMutability": "view",
              "type": "function"
            },
            {
              "inputs": [],
              "name": "callerAAddress",
              "outputs": [
                {
                  "internalType": "bytes20",
                  "name": "",
                  "type": "bytes20"
                }
              ],
              "stateMutability": "view",
              "type": "function"
            },
            {
              "inputs": [
                {
                  "internalType": "bytes",
                  "name": "aTxn",
                  "type": "bytes"
                }
              ],
              "name": "commitTransaction",
              "outputs": [
                {
                  "internalType": "bool",
                  "name": "",
                  "type": "bool"
                }
              ],
              "stateMutability": "nonpayable",
              "type": "function"
            },
            {
              "inputs": [
                {
                  "internalType": "bytes",
                  "name": "aBlock",
                  "type": "bytes"
                }
              ],
              "name": "decodeABlock",
              "outputs": [
                {
                  "components": [
                    {
                      "internalType": "bytes32",
                      "name": "_masterHash",
                      "type": "bytes32"
                    },
                    {
                      "internalType": "uint256",
                      "name": "_txnCount",
                      "type": "uint256"
                    },
                    {
                      "internalType": "bytes20",
                      "name": "_aetheringAddress",
                      "type": "bytes20"
                    }
                  ],
                  "internalType": "struct IAetherHUB.AetherBlock",
                  "name": "aetherBlock",
                  "type": "tuple"
                },
                {
                  "internalType": "bytes16[]",
                  "name": "blockTxnHashes",
                  "type": "bytes16[]"
                }
              ],
              "stateMutability": "pure",
              "type": "function"
            },
            {
              "inputs": [
                {
                  "internalType": "bytes",
                  "name": "aTxn",
                  "type": "bytes"
                }
              ],
              "name": "decodeATransaction",
              "outputs": [
                {
                  "components": [
                    {
                      "internalType": "address",
                      "name": "_from",
                      "type": "address"
                    },
                    {
                      "internalType": "address",
                      "name": "_to",
                      "type": "address"
                    },
                    {
                      "internalType": "bytes4",
                      "name": "_select",
                      "type": "bytes4"
                    },
                    {
                      "internalType": "bytes",
                      "name": "_args",
                      "type": "bytes"
                    }
                  ],
                  "internalType": "struct IAetherHUB.AetherTxn",
                  "name": "aetherTxn",
                  "type": "tuple"
                }
              ],
              "stateMutability": "pure",
              "type": "function"
            },
            {
              "inputs": [
                {
                  "internalType": "bytes",
                  "name": "aBlock",
                  "type": "bytes"
                }
              ],
              "name": "execBlock",
              "outputs": [
                {
                  "internalType": "bool",
                  "name": "",
                  "type": "bool"
                }
              ],
              "stateMutability": "nonpayable",
              "type": "function"
            },
            {
              "inputs": [
                {
                  "internalType": "uint256",
                  "name": "ablock_num",
                  "type": "uint256"
                }
              ],
              "name": "getABlock",
              "outputs": [
                {
                  "internalType": "bytes32",
                  "name": "aBlockMasterHash",
                  "type": "bytes32"
                },
                {
                  "internalType": "uint256",
                  "name": "aBlockTxnCount",
                  "type": "uint256"
                },
                {
                  "internalType": "bytes20",
                  "name": "aBlockAetheringAddr",
                  "type": "bytes20"
                }
              ],
              "stateMutability": "view",
              "type": "function"
            },
            {
              "inputs": [
                {
                  "internalType": "bytes16",
                  "name": "atxn_ref",
                  "type": "bytes16"
                }
              ],
              "name": "getATransaction",
              "outputs": [
                {
                  "internalType": "uint256[]",
                  "name": "txn_cids",
                  "type": "uint256[]"
                },
                {
                  "internalType": "address",
                  "name": "txn_from",
                  "type": "address"
                },
                {
                  "internalType": "address",
                  "name": "txn_to",
                  "type": "address"
                },
                {
                  "internalType": "bytes4",
                  "name": "txn_selector",
                  "type": "bytes4"
                },
                {
                  "internalType": "bytes",
                  "name": "txn_args",
                  "type": "bytes"
                }
              ],
              "stateMutability": "view",
              "type": "function"
            },
            {
              "inputs": [
                {
                  "internalType": "address",
                  "name": "nodeAddr",
                  "type": "address"
                }
              ],
              "name": "nodeRegistery",
              "outputs": [
                {
                  "internalType": "bool",
                  "name": "",
                  "type": "bool"
                }
              ],
              "stateMutability": "view",
              "type": "function"
            },
            {
              "inputs": [
                {
                  "internalType": "address",
                  "name": "nodeAddress",
                  "type": "address"
                }
              ],
              "name": "registerNode",
              "outputs": [
                {
                  "internalType": "bool",
                  "name": "",
                  "type": "bool"
                }
              ],
              "stateMutability": "nonpayable",
              "type": "function"
            },
            {
              "inputs": [
                {
                  "internalType": "bytes32",
                  "name": "masterHash",
                  "type": "bytes32"
                }
              ],
              "name": "submitMasterHash",
              "outputs": [
                {
                  "internalType": "bool",
                  "name": "",
                  "type": "bool"
                }
              ],
              "stateMutability": "nonpayable",
              "type": "function"
            }
    ]
    
    },
}