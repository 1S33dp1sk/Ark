
export const AETHER_DOCS = {
    "Essentials":{
            iihtml:'\
        <h2>EVM chains, AetherRouter and parameters</h2>\
        <p>0xAether is fueled by `EVM` compatible chains such as [ ETH, BSC , FTM , MATIC , AVAX ] in which the AetherContracts are utilized to transmit different transaction types and data in between said chains.</p>\
        <p>The system is made from a collection of standalone smart-contracts, where The 0xAether propagation flow, combines different sets and types of web3 implementations to yield better gasFees and a more agile decentralized bridging platform.</p>\
        <b>Obviously All The contracts have the same address on all chains</b>\
        <ul>\
        <li className="ethAddress">\
            <h4 ><span >AetherDAO : </span>0x753e46f7e8F48d9Ac44609415E6905AF7C1872Aa</h4>\
        </li>\
        <li className="ethAddress">\
            <h4> <span>AetherTreasury</span> :0x753e46f7e8F48d9Ac44609415E6905AF7C1872Aa</h4>\
            <div>\
            <ul>\
                <li>\
                    <h4><span>NodesKeeper</span> </h4>\
                </li>\
                <li>\
                    <h4><span>BondsKeeper</span> </h4>\
                </li>\
                <li>\
                    <h4><span>IndexKeeper </span></h4>\
                </li>\
                <li>\
                    <h4><span>TransactionKeeper</span> </h4>\
                </li>\
                <li>\
                    <h4><span>KeeperAether</span> </h4>\
                </li>\
            </ul>\
            </div>\
        </li>\
        <li className="ethAddress">\
            <h4><span>AetherHUB : </span>0x753e46f7e8F48d9Ac44609415E6905AF7C1872Aa</h4>\
        </li>\
        <li className="ethAddress">\
            <h4><span>AetherFactory : </span>0x753e46f7e8F48d9Ac44609415E6905AF7C1872Aa</h4>\
        </li>\
        <li className="ethAddress">\
            <h4 ><span>AetherNode : </span>0x753e46f7e8F48d9Ac44609415E6905AF7C1872Aa</h4>\
        </li>\
        <li>\
        </li>\
    </ul>\
                    ',
    },
    "A-EVM":{
        iihtml:'\
                <h2>Index, AetherDAO and algorthmic stability </h2>\
                <p>Due to the lack of a standard, the 0xAether proposes headlines on how a native crypto index should be defined and calculated.</p>\
                <p>The main variables that go into the calculation that results in the price determination : </p>\
                <ul>\
                    <li>\
                        <h3> reserves0xA </h3>\
                        <h2><strong> Technical Info </strong></h2>\
                        <p>Using `syncReserves()` function, every `refreshTime()` defined in the DAO, will yield a more accurate estimation of the index. However, will actually slow down the growth.</p>\
                        <p> </p>\
                    </li>\
                    <li>\
                        reservesNative\
                    </li>\
                    <li>\
                        currents0xA\
                    </li>\
                    <li>\
                        currentsNative\
                    </li>\
                </ul>\
            ',
    },
    "BondsKeeper":{
        iihtml:'\
                <h2>BondSwap, AetherBonds and utility</h2>\
                <p>AetherBonds such as the name implies, is a purchase for pseudo-debt evaluated at 50% of the current holdings of the treasury. With a grand total of 100 unique bonds.</p>\
                <p>Bonds can be <i>Combined</i> , <i>separated</i> , <i>Defaulted</i> , <i>Auctioned</i> </p>\
                <p>The natural effect on the bond is maturing with time. Unless it has been defined as `Auctioned` or `Defaulted`. While the bonds mature, their values will change based on the latest `syncBonds()` call.</p>\
                <h2><strong>Technical Info</strong></h2>\
                <p>`syncBonds()` function is also included in `sync()`, where the frequency of the call is defined in the DAO using `syncTime()`</p>\
                <p>Each sync call essentially, does a re-evaluation for the overall system and updates the state if needed</p>\
                <p>The bonds can be traded on NFTMarketplaces, and will always have a reserve in-case a Bond prefers a default. <span>The only condition for the default is that the `maturities( bond_id ) > 1`</span></p>\
                <p>Trending with caution, we can use the previously defined strategies to ensure the AetherBond remains stable, as the volume traded does not affect the underlying asset. This way instead of dealing with real inflation, due to the unjustified raise in pricing</p>\
                <p>Prices will deal with more temporary volatility, rather than long-term decreases.</p>\
            ',
    },
    "NodesRegistry":{
        iihtml:'\
                <h2>Addresses, AetherProxy and registeration</h2>{/* multi-chain registery */}\
                <p>As mentioned here, the deployment on the aether is done using a ticket, this way it will guarantee that the same address is available, if needed to be deployed later.</p>\
                <p>While developing smart-contracts for to be deployed with the aether, ensure that you are abiding to the rules.</p>\
                <p>The most important part while developing is to remember that any aether contract uses `initialize()` instead of `constructor()`.</p>\
                <p>The reason for that is the Aether utilizes references and proxies to communicate and query other contracts. Thus while deploying with the AetherFactory, the AetherFactory will essentially deploy a reference proxy that will be utilized to serve data from another contract </p>\
                <p>With that being said, it is most important to note that : </p>\
                <p><b>The initialization call is done ONCE, by the AetherFactory at the time of deployment.<b></p>\
                <p>The 0xAether ecosystem is rapidly growing, so be sure to keep checking this section, or our newsletter for any new updates on our contract ecosystem.</p>\
                <p>The AetherProxy here acts as a router, the AetherDAO has the only right to change the contract addresses implemented in the DAO. __0xAPrice__</p>\
            ',
    },
    "Decentralized":{
        iihtml:'\
                    <h2>Cross-Chain, Multi-Chain and Deployment calls</h2>\
                    <p>More often than not, enthusiasts use the term Cross-Chain-Calls or simply <span> Cross-Chain </span> and Multi-Chain-Calls or <span> Multi-Chain </span> interchangeably. Unfortunately, this is false and the system *Hopefully* will make this clear </p>\
                    <h2> Cross-Chain-Calls <span>CCCs</span></h2>\
                        <p>Simply mean that <i>one particular</i> transaction submitted to the AetherHub should be submitted exactly the same on all different supported blockchains by the submitting smart contract. Please note, that this relationship is obviously <b>not</b> a mutually exclusive one, but rather a congruent one. As any supported chains by the submitting contract must be supported by the AetherHub receiving the transaction</p> \
                        <h4><span>CCCs in 0xA</span> are defined as one transaction that is essentially speaking, async.</h4>\
                        <p>Every CCC transaction takes the following order</p>\
                        <h4><span>Wallet &nbsp;</span>submits a transaction to a smart contract registered with the hub on chainId=1</h4>\
                        <h4><span>Registered Smart Contract &nbsp;</span>Checks the logic of the transaction and reroutes the transaction to the AetherHub</h4>\
                        <h2><strong>Transaction submitted, however no changes took effect in the smart contract yet.</strong></h2>\
                        <h4><span>Nodes &nbsp;</span>validate the transaction on other chains and upon full confirmation will be executed</h4>\
                        <h2><strong>Transaction here is mined from the native blockchain nodes and changes took effect</strong></h2>\
                    <h2> Multi-Chain-Calls <span>MCCs</span></h2>\
                        <p>This means that any series of particular transactions, that need to be executed on different chains in series, are packaged in an array of chainIds and set to be validated by the nodes. Any similar protocols and/or implementations in terms of the same context will need to be submitted as an MCC call from an aethering contract</p>\
                    <h2> Deployment Calls <span>DCs</span></h2>\
                        <p>As the name implies a deployment call, consumes a ticket purchased from the keeper to launch a smart contract and register it with the hub across all different chains, with the same contract address and a pre-defined logical interface between two different solidity smart contracts on two separated blockchains. This is by default a MCC call, and in particular, very useful when an already established project wants to integrate 0xA within their ecosystem.</p>\
                        <p>Moreover, from a development perspective, launching with 0xAether is many magnitudes easier and less of a hassle than trying to create a bridge, or link different smart contracts over different blockchains.</p>\
                        <p><span>Reminder &nbsp;</span>A deployer might utilize the ticket to form different types of handling for any of the above mentioned calls. I.E: No need to deploy all contracts at once, a chain-by-chain roll-out is supported by 0xAether. </p>\
            ',
    },
    "Autonomous":{
        iihtml:'\
            ',
    },
    "Organization":{
        iihtml:'\
                <h2>Contracts, AetherFactory and ticketing</h2>\
                <p>Contracts deployed and linked to the Aether ecosystem, are defined as 3 different contract types, making it easier to track and check the implementations</p>\
                <ul></ul>\
                <p>For any contract that is not Aether. i.e: a contract that was not deployed originally by the DAO. is separated and referenced in the proxy *Read More Here* </p>\
                <p>Contracts that will be aethered or aethering must use the AetherFactory to deploy the contract, by purchasing a ticket through the ticketing office in the smart-contract, that ticket can be redeemed at any point in time for that address.</p>\
                <p>And linked to the AetherHUB with the address provided at any point post-purchase.</p>\
',
    },
    "Aether Blocks":{
        iihtml:'\
                <h2>FIA, AetherNodes and functionality</h2>\
                <p>Every node functions as a controlled transmitter *Telephone* between each of the blockchains. And just like a telephone needs an operator, that will be the web2 client listening and initiating transactions. Continuing, its also a telephone in the network sense, where each line cannot transmit the full payload, i.e: all the voices in the microphone alone, but the more the merrier, as the load will be distributed across different lines </p>\
                <p>The Nodes is where all transactions will flow from and to essentially.</p><p>The Hub controls variables inside the AetherNode contract to ensure correct transaction propagation</p>\
                <p>Nodes get a small percentage from each transaction, defined as a total sum for Fixed Index Annuity (FIA), the Index is calculated YoY, defined by the DAO as `FIA()`</p>\
                <p>The FIA is calculated as nodeIndexValue once `block.timestamp == lastSync() + IAetherDAO( aetherDAO() ).fiaTime()`</p>\
                <p> the `nodeIndexValue` determines the total profitability of the index and rewards the nodes</p>\
            ',
    },
    "Multi Vs. Cross":{
        iihtml:'\
                <h2>Transactions, AetherHUB and onChain consensus</h2>\
                <h2><strong> Technical Info </strong></h2>\
                <p>Transactions are checked against a local up-to-date blockchain on every call submitted, where if the nodes do not pick up the transaction most likely its due to an revert execution error, or too low of collateral supplied. If the transaction does not get validated in `maxWaitTime()` seconds - a variable defined in the DAO. The transaction is qualified to be withdrawn and/or bounty hunter. If the transaction is bounty hunted, the refunded gas will be `txnDepletion` ratioed.</p>\
                <p>With the same logic, we can confidently state that AetherTransactions are processed without any regard for their type, that is, different transactions have the same data layout and are processed almost identically in the TransactionKeeper and the AetherHub.</p>\
                <p>Transactions are verified on the chain using 4 different layers of security embedded in the architecture of the system to avoid expensive contract calls and gasFees</p>\
                <p>Layers are in ascending order</p>\
                    <ul>\
                        <li>\
                            <h3>Node Submission <span> I </span></h3>\
                            <p>The first security layer of the 0xAether, only registered (NODES) contracts are able to submit transactions to the hub.</p>\
                        </li>\
                        <li>\
                            <h3>Bounty Hunt<span> II </span></h3>\
                            <p>The second layer of security is the `Timeout` duration, where ANY 0xA DAO member can submit a *ForfeitTransaction* function for any transaction that will either fail, or not be validated</p>\
                        </li>\
                        <li>\
                            <h3>X Signatures<span> III </span></h3>\
                            <p>Each transaction submitted needs at least `signersThreshold()` signatures before any node can actually execute the transaction from the hub. This variable is defined in the DAO. <i>Read about DAO vars</i></p>\
                        </li>\
                        <li>\
                            <h3>KchecK<span> IV </span></h3>\
                            <p>The KchecK is a data-integrity check performed on the transaction data submitted, just like a checksum would <i>Read about checksums</i> essentially indicate any errors introduced, the KchecK does that task using a slightly different approach </p>\
                            <p>The main parts that compose this bytes32 variable are : </p>\
                            <ul>\
                                <li>\
                                    <h4> Hub-Node Tristate </h4>\
                                    <h2><strong> Technical Info </strong></h2>\
                                    <p>Each node can operate under one specific state at a time only. Where the state can only be toggled via the AetherHub, upon completion of the previously assigned state; either successfully, or unsuccessfully</p>\
                                </li>\
                                <li>\
                                    <h4> Hub-Hub Status </h4>\
                                </li>\
                                <li>\
                                    <h4> Hub-Contract Nonce </h4>\
                                </li>\
                            </ul>\
                        </li>\
                    </ul>\
            ',
    },
    "TruConsensus":{
        iihtml:'\
                <h2>OnChain verification</h2>\
            ',
    },
    "baseGasFee()":{
        iihtml:'\
                <h2>Fees, AetherKeeper and gasPricing</h2>\
                <p>The re-evaluation works based on the pre-defined targets such as targetGas, targetRatio, etc... </p>\
                <p>Key-definition points for 0xAether Transaction fees, is the fact that the user defines a particular collateral amount which they would want to submit, the collateral essentially funds the consensus, theoretically speaking a transaction with correctly calculated fees, could be submitted and signed but never processed which will be labeled stagnant. However, in practice, the Nodes will not submit a transaction that will not be completely mined, as it does not serve the fiduciary duty. </p>\
                <p>The collateral amount & value is calculated when a transaction is submitted by the client and accepted by the node. In each node, collateral is calculated <i>roughly</i> before accepting a transaction, as all the nodes are designed to commit to fulfilling the transactions accepted. The TransactionKeeper will yield a Singular Value (SV) for the transaction accepted, which is a common denominator between the different chainIds - regardless of an MCC or CCC -.</p>\
                <p>The <b>SV</b> of the sending chainId=A is related but not equal to the <b>SV</b> on the receiving chain with chainId=B.</p>\
                <p> Base Strategies </p>\
                <p> Strategies here define the linking and the mathematical relationship between different DAO defined variables that are used in the resulting `baseGasFee()`. On each check a dynamic cost calculation is carried out to determine the current correct value.</p> \
                <ul>\
                    <li>\
                        <h3> AUTO  </h3>\
                        <p> If the strategy is determined automagically on each transaction, the Keeper will use the current reserves as the main determinstic variable in relation with the locked reserves based on the targets defined for the index. </p>\
                    </li>\
                    <li>\
                        <h3> DIRECT  </h3>\
                        <p> Defines the next transaction epoch data as the locked reserves inversely proportional to the totalGas consumed for the target amount of transactions </p>\
                    </li>\
                    <li>\
                        <h3> INVERSE </h3>\
                        <p> Defines the next transaction epoch data as the locked reserves inversely proportional to the totalGas consumed for the target amount of transactions </p>\
                    </li>\
                    <li>\
                        <h3> STABLE </h3>\
                        <p> Defines the next transaction epoch data as the locked reserves inversely proportional to the totalGas consumed for the target amount of transactions </p>\
                    </li>\
                </ul>\
                <h4><span>Selling :: </span> The treasury is allowed to sell 5% of the `totalSupply(chainId)` - `maxSupply(chainId)` every time one half of the target is met on any condition. i.e: `totalGas` or `reservesRatio`</h4>\
            ',
    },
    "Factory Tickets":{
        iihtml:'\
                <h2>Security layers</h2>\
            ',
    },
    "ProxyBodyGuard":{
        iihtml:'\
                <h2>Bountied</h2>\
            ',
    },
    "Router (not wifi)":{
        iihtml:'\
                <h2>Bountied</h2>\
            ',
    },
    "A-E20 <-> ERC20":{
        iihtml:'\
                <h2>A20 layers</h2>\
            ',
    },
    "A-E721 <-> ERC721":{
        iihtml:'\
                <h2>A721 layers</h2>\
            ',
    },
    "A-E1155 <-> ERC721":{
        iihtml:'\
                <h2>A1155 layers</h2>\
            ',
    },
    "Installation":{
        iihtml:'\
                <h2>Security layers</h2>\
            ',
    },
    "Infrastructure":{
        iihtml:'\
                <h2>Bountied</h2>\
            ',
    },
    "Environment":{
        iihtml:'\
                <h2>Bountied</h2>\
            ',
    },
    "WebSocketSecure":{
        iihtml:'\
                <h2>A20 layers</h2>\
            ',
    },
    "Loops":{
        iihtml:'\
                <h2>A721 layers</h2>\
            ',
    },
    "Contracts":{
        iihtml:'\
                <h2>A1155 layers</h2>\
            ',
    },
    "Ethereum Binary Mirrors (EBM)":{
        iihtml:'\
                <h2>A1155 layers</h2>\
            ',
    },
};
