# 0xAether client AKA Node

The 0xAether client uses __Tru__ as a consensus mechanism, which essentially ensures that all of the different blockchains are in-sync. Even though each of the transaction(s) submitted to the 0xAetherHUB is at the very core `async`.

## Tru Consensus

A combination of 3 different proofs to integerate into one, while collectivly attempting to add the holygrail of each of the proofs. Each of the proofs included is explained breifly in the following paragraphs and is linked to it's corresponding (_variable_) in the block strucutre.

1.  Proof Of Work   (_MASTERHASH_)

During the process of creating a new _Aether_ block, the previous __MASTERHASH__ is used in the process, to ensure that sequentiality is acheived in the blockchain itself. However, instead of re-hashing the whole path, we can depend on previously verified hash. 


2.  Proof Of Stake   (_KchecK_)

In order to be able to verify and/or submit any transaction to the 0xAetherHUB, the address associated with the verification or submittion needs to be :    

-.  Registered with the 0xAetherHUB.    
-.  Have Atleast `nodeStakingAmount` locked with said address in the 0xAetherTreasury.

While this may change based on the 0xAetherDAO proposals, and, subsequently the DAOs' resolutions; the _Core_ protocol will always validate whether an address can verify/submit a transaction or not.    


3.  Proof Of Activity   (_Aetherer_)

As a general rule of thumb, The human factor is unpredictable and rather unreliable when compared to machines, with respect to having a DAO and mainly the PoS approach. Further, whenever decentralization is present in any protocol, there are many risks involved, amongst of which is the infamous 51% attack. With that being said, and in order to preserve the 0xAether from being vulnerable to either; the protocol dictates which of the _registered_ nodes needs to submit the next block. By following a global pointer on a dynamic sequence for the registered nodes, we can ensure that the _nodes_ are: __Active__ and __in-sync__ with the network.


- - - - 



A simple __Block__ is structured as follows:

*   AetherBlockNum    

_An autorincrement number constant across all-chains._

*   MASTERHASH    

_MASTERHASHES are calculated by including ONLY the previous MASTERHASH or simply MASTERHASH{ n - 1 }, verifying the whole chain once again. Nonetheless, the Beauty of `Tru` is that you do not need the pre-previous MASTERHASH{ n - 2 }. as that is reliant on the previous one, which has been already verified using the pre-previous one._

*   TxnsKcheck    

_Each block contains a `bytes16[] txn_hashes` which is the first 16 bytes of `keccak256( Transaction , ChainIds )`, where a Transaction is defined by ` struct Transactions { address from , address to , bytes4 selector , bytes memory arguments }` and ` uint256[] ChainIds` is an array of all the chainIds of the different blockchains that the transaction needs to be submiited to. Each indivisual `CHAIN_ID` is unique as defined in  __EIP-155__._

*   TxnCount    

_The length of `txn_hashes` array defined in __TxnsKcheck__._

*   Aetherer    

_Aether blocks needs to be `binding` and for a block to be binding it needs to have a unique messenger address. The messenger address changes based on a forever incrementing loop that includes 2 main parts:_

1.  `uint256 _nonce`

2.  `address _addr`

_Where the `nonce` is determined by how many times any arbitrary address, has been the messenger; and the `_addr` is an __ECDSA__ public key._


