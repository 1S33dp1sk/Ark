# 0xAether|0xA

__Welcome to 0xA, the on-chains blockchain, by AetherLabs.__


## Overview

0xAether is a blockchain messaging space that establishes a standard for IO transactional messages between different protocols. Currently, it supports all `EVM` compatible chains, such as ethereum, binance, polygon and a few more. The 0xAether enables native on-chain messaging across different chainIds, with a slightly enhanced security as the consensus is done on-chain.    

The validation is checked on the fly against each transaction. While non-technical users can enjoy and utilize the functionality of initiating transactions without the knowledge of different networks and their standards, technical users have the privilage of the dev3Suite a collection of tools and plugins to create complete and complex multi-chain & cross-chain dApps and contract-logic. Any transaction can be inititated and finalized through the aether from deployment, transfers, DeFi, game-logic and much more; Regardless of the chainid or the contract deployment state (i.e: if it has already been deployed or not).


### 0xAetherNode

Aether node is packaged to be singular or multi-instance running program, To run an AetherNode you need the following:

-.  `AetherNode` smart contract deployed by the `AetherFactory`. you can obtain one __@AetherLabs.io/nodes__ 

-.  RPC WSS urls for the supported chainIds. 
    *Note that to support any chainId your node(s), you will need an WSS endpoint URL that is able to call :    
    `eth_createFilter` && `eth_getFilterChanges`*



#### Generic Make

After cloning the remote repository, run 
```shell
make
```
in the instalation directory to initiate a generic version of Aether.


#### Configure Aether

Configurations for Aether is customizable to fit different needs, from testing to production to node-instance running. To define the default enviroment setup, you can run:    
```shell
aether setup
```

Nonetheless, to define any particular enviroment setup, edit the `template-env.conf` && `template-rpc.conf` located in home directory of the installation and use the _(--e) and/or (--r)_ for enviroment and rpc configuration files respectivily. Multiple configurations are possible by adjusting the configurations after creating the default ones and before adding a new node.    

```shell
aether setup --e /path/to/default/env.conf --r /path/to/default/rpc.conf
```    

The default configuration files generated can be found in _`Aether/.conf/env.conf.json`_ && _`Aether/.conf/rpc.conf.json`_.



#### Adding 0xAether|Node

To create a new generic aether node, run:

```shell
aether add
```

However, to run a real instance of the node communicating back and forth with the hub to verify transaction the node address needs to be specified by using _(--a)_ representing the actual address of the smart contract generated by the 0xAetherFactory.

```shell
aether add -a 0x00000000000000000000000000000000000
```


#### Toggling 0xAether|Node

To start a node, a toggle command is provided:

```shell
aether toggle 
```

If only a single node has been added, the aether will automatically start that node however, if multiple node(s) or configurations has been found, please specify which node name to start:

```shell
aether toggle -n NODE_NAME
```


#### Status 0xAether|Node

To query the status of the aether nodes: 

```shell
aether status
```








## Testing Aether

1.  To start 2 different EVM chains running side-by-side
    run `./aether start`

2.  Execute the deployment script on both chains
    run `./aether script -s deploy.ts`

3.  Start the node
    run  `./aether toggle`

4.  Read the variables on both chains
    run  `./aether script -s read.ts`

5.  Write to only one chain (TN1/TN4)
    run  `./aether script -s write.ts -d TN1`

6.  Read the variables again using step 4
    run `./aether script -s read.ts`