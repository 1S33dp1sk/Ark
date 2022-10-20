import { chainsLogo, icons, levels } from "../assets";

export const truncateRegex = /^(0x[a-zA-Z0-9]{4})[a-zA-Z0-9]+([a-zA-Z0-9]{4})$/;


export const NAVBAR = [
    {
        name:'About',
        link:'/about'
    },
    {
        name:'Guides',
        link:'/guides'
    },
    {
        name:'Logs&TXNS',
        link:'/logs'
    },
];

export const FOOTER = [
    
    {
        title:"Aetherlabs",
        childs: [{title:"Home",link:"/home"},{ title:"Guides",link:'/guides'}, {title:"Logs&TXNS", link:"/logs"}]
    },
    
    {
        title:"dApp",
        childs: [{title:"DAO", link:'/dapp/dao'}, {title:"Bonds",link:'/dapp/bonds'}, {title:"Tokens",link:'/dapp/tokens'}, {title:"Factory",link:'/dapp/factory'}]
    },
   
];

export const GUIDES = [
    {
        name:"DAO",
        desc:"The home of the Aether and it's community.",
        action:"Improve the Aether",
        site:"/guides/dao"
    },
    {
        name:"Factory",
        desc:"Where all Aethered contracts are created and deployed.",
        action:"Smart contract types",
        site:"/guides/factory"
    },
    {
        name:"HUB",
        desc:"The facilitator of all Aether transactions.",
        action:"Tru consensus",
        site:"guides/hub",
    },
    {
        name:"Node",
        desc:"Thriving individual transaction emitters and verifiers.",
        action:"Running a node",
        site:"guides/node",
    },
];

export const SOCILAS = [
    {
        logo:icons.socials.discord,
        name:"Discord",
        link:"https://discord.gg/qbXRJeCm",
        desc:"Hop in",
    },
    {
        logo:icons.socials.telegram,
        name:"Telegram",
        link:"https://t.me/aetherOx",
        desc:"View discussion",

    },
    {
        logo:icons.socials.twitter,
        name:"Twitter",
        link:"https://twitter.com/aetherlabs_io?s=20&t=jLB-Af7qmctAJCcjPcMeDA",
        desc:"Read the lastest",

    },
    {
        logo:icons.socials.github,
        name:"Github",
        link:"https://github.com/A3therLabs",
        desc:"Check updates",
    },
];

export const WALLET_PROVIDERS = [
    
    {
        title:'Metamask',
        logo:icons.metamask,
        desc:"Connect to your MetaMask Wallet",

    },
   
    {
        title:'WalletConnect',
        logo:icons.walletconnect,
        desc:"Scan with WalletConnect",
    },
];
// ---------------------------
export const DOCS ={
    "0xAether": {
        childs: [
            {
                title:"Introduction",
                branches:["Essentials", "A-EVM"],
                c_id: "intro",
                toggleState: false,
            },
            {
                title:"100-Year Economics",
                branches:["BondsKeeper", "NodesRegistry"], // Bonds , Nodes
                c_id: "evm_chains",
                toggleState: false,
            },
            {
                title:"Benchmark Control",
                branches:["Decentralized","Autonomous","Organization"], // DAO , Keeper
                c_id: "chain_calls",
                toggleState: false,

            },
            {
                title:"Technical on-chain",
                branches:["Aether Blocks","Multi Vs. Cross","TruConsensus","baseGasFee()"], // HUB , Token
                c_id: "transactions",
                toggleState: false,
                
            },
            {
                title:"Deployment & Examples",
                branches:["Factory Tickets","ProxyBodyGuard","Router (not wifi)","A-E20 <-> ERC20", "A-E721 <-> ERC721", "A-E1155 <-> ERC721"], // Factory , Proxy , Router
                c_id: "deploy_contract",
                toggleState: false,
            },
        ],

    },
    "devSuite":{
        childs: [
            {
                title:"Initialize",
                branches:["Installation", "Infrastructure"],
                c_id: "start",
                toggleState: false,
            },
            {
                title:"Configure",
                branches:["Environment", "WebSocketSecure"],
                c_id: "conf",
                toggleState: false,
            },
            {
                title:"Build",
                branches:["Loops", "Contracts", "Ethereum Binary Mirrors (EBM)"],
                c_id: "build",
                toggleState: false,
            },
        ],
    }
};

export const TABLES_TITLES = {
    block:["Id", "Master hash", "Aethering Address", "Txn amount"],
    txn:["Id", "Address", "Status", "Time"]
};

export const BLOCKSTABLE = {
    blocks:[
      {
        id:1,
        master_hash:"3ed54831f488a22b28398de0c567a3b064b937f54f81739ae9bd545967f3abab",
        aethering_address:"0x2d9762564fa6802B5Ca0853830AA3676a3a7B706",
        txn_amount:"100"
      },
      {
        id:2,
        master_hash:"3ed54831f488a22b28398de0c567a3b064b937f54f81739ae9bd545967f3abab",
        aethering_address:"0x2d9762564fa6802B5Ca0853830AA3676a3a7B706",
        txn_amount:"100"
      },
      {
        id:3,
        master_hash:"3ed54831f488a22b28398de0c567a3b064b937f54f81739ae9bd545967f3abab",
        aethering_address:"0x2d9762564fa6802B5Ca0853830AA3676a3a7B706",
        txn_amount:"100"
      },
      {
        id:4,
        master_hash:"3ed54831f488a22b28398de0c567a3b064b937f54f81739ae9bd545967f3abab",
        aethering_address:"0x2d9762564fa6802B5Ca0853830AA3676a3a7B706",
        txn_amount:"100"
      },
      {
        id:5,
        master_hash:"3ed54831f488a22b28398de0c567a3b064b937f54f81739ae9bd545967f3abab",
        aethering_address:"0x2d9762564fa6802B5Ca0853830AA3676a3a7B706",
        txn_amount:"100"
      },
  ]
};

export const CHAINS_ = {
    "137":{
        name:"Polygon",
        id:137,
        symbol:"MATIC",
        features:[
            "Afforadable Gas",
        ],
        site:"https://polygon.technology/",
        rpc:"https://polygon-rpc.com",
        logo:chainsLogo.MATIC
    },
    "1":{
        name:"Ethereum",
        id:1,
        symbol:"ETH",
        features:[
            "Consistant Uptime",
        ],
        site:"https://ethereum.org/en/",
        rpc:"https://mainnet.infura.io/v3/",
        logo:chainsLogo.ETH
    },
    "56":{
        name:"Binance",
        id:56,

        symbol:"BSC",
        features:[
            "Transaction Volume",
        ],
        site:"https://www.bnbchain.world/en",
        rpc:"https://bsc-dataseed.binance.org/",
        logo:chainsLogo.BSC
    },
    "43114":{
        name:"Avalanche",
        id:43114,
        symbol:"AVAX",
        features:[
            "Fast Finality Time",
        ],
        site:"https://www.avax.network/",
        rpc:"https://api.avax.network/ext/bc/C/rpc",
        logo:chainsLogo.AVAX
    },
    "250":{
        name:"Fantom",
        id:250,
        symbol:"FTM",
        features:[
            "Scalability",
        ],
        site:"https://fantom.foundation/",
        rpc:"https://rpc.ftm.tools/",
        logo:chainsLogo.FTM
    },
    "25":{
        name:"Cronos",
        id:25,
        symbol:"CRO",
        features:[
            "Scaling Projects",
        ],
        site:"https://cronos.org/",
        rpc:"https://cronoscan.com/",
        logo:chainsLogo.CRO
    },
};

export const FEATURES = {
    "Transaction Processing":[
      {
        img:levels["Transaction Processing"][0],
        section_id:'TP0',
        desc:
            "<p><span>0xAether</span> treats all chains in a pre-defined way.<br/><br/> Native-chain, Cross-chain, and/or Multi-chain transactional experiences" +
            "are totally in your control.</p>"
      },
      {
        img:levels["Transaction Processing"][1],
        section_id:'TP1',
        desc:
            "<p><span>0xAether</span> is responsible for verifying all-submitted on-chain transactions.<br/><br/>"+
            "Where each wallet-originating transaction has a constant, verifiable and trackable MASTERHASH across all chains.</p>"
      },
      {
        img:levels["Transaction Processing"][2],
        section_id:'TP2',
        desc:
            "<p><span>0xAether</span> handles security more robustly than time.<br/><br/>" +
            "Unlike common EVM blockchain transactions, every Aether transaction is an asynchronous transaction, per say. Hence, transactions are also allowed an (optional)"+
            "callback transaction to be submitted, to resolve any discrepencies that might arise from the async call.</p>"
      },
      {
        img:levels["Transaction Processing"][3],
        section_id:'TP3',
        desc:
            "<p><span>0xAether</span> does not waste gas or computational power<br/></br>"+
            "Every transaction is evaluated and a certain amount of 0xA is quoted prior to submittion."+
            "Transactions which are going to fail are evaluated but not quoted, and thus rejected."+
            "Directly from the treasury, the same quoted amount is deducted from a node,"+
            "and the aggregate amount of gas consumed by the unique transaction hash across all chains"+
            "is the deductible 0xA gas from the sender.</p>"
      },
      {
        img:levels["Transaction Processing"][4],
        section_id:'TP4',
        desc:
            "<p><span>0xAether</span> contracts are never directly accessed or called.<br/><br/>"+
            "For every contract deployed, a unique mixin pseudo-proxy (ProxyGuard) contract address is registered in the router."+
            "In which all other wallets or contracts form communication channels with." +
            "Using this technique, the pseudo-proxy acts as a full postive-feedback loop,"+
            "to ensure correct and safe transaction routing and rerouting.</p>"
      }
    ],
    "Index Balancing":[
      {
        img:levels["Index Balancing"][0],
        section_id:'KP0',
        desc:
            "<p><span>0xAether Keepers are always in-sync.</span><br/><br/>"+
            "Syncing the keepers is by design baked into the ecosystem, and thus the protocol itself."+
            "Resulting in a very low arbitrage between different chain keepers and the reserves managed.</p>"
      },
      {
        img:levels["Index Balancing"][1],
        section_id:'KP1',
        desc:
            "<p><span>0xAether and native reserves are always up-to-date.</span><br/><br/>"+
            "The Keeper does not change the reserves based on any sync/update call."+
            "This is only controlled by the 0xAetherDAO, where it defines which measures to take if a certain criteria is met."+
            "Said calls are used to internally check and re-calculate the current reserves and evaluations based on this criteria.</p>"
      },
      {
        img:levels["Index Balancing"][2],
        section_id:'KP2',
        desc:
            "<p><span>0xAether Keeper reserves are completley isolated.</span><br/><br/>"+
            "When a keeper is re-calculating the reserves, it considers the total amount of 3 different allocations:"+
            "<ul><li>0xAetherBonds</li><li>0xAetherNodes</li><li>0xAetherTreasury</li></ul>"+
            "If a new milestone is acheived, the 0xAetherKeeper will automatically lock that liquidity. And start a new DAO-defined target milestone.</p>"
      },
      {
        img:levels["Index Balancing"][3],
        section_id:'KP3',
        desc:
            "<p><span>0xAether is an index. An autonomous index.</span><br/><br/>"+
            "Utilizing the fact that all keepers are in-sync, DAO-defined target milestones and gas stratgies are used"+
            "by the 0xAetherTreasury, to balance the different circulating supplies in different chains, while also being"+
            "hardcapped by the 0xAetherToken contract. Furthermore, the treasury actions themselves are also hardcapped to not be misused.</p>"
      },
    ],
    "PseudoProxy Deployment":[
      {
        img:levels["PseudoProxy Deployment"][0],
        section_id:'DC0',
        desc:
            "<p><span>0xAether deployment will always guarantee a constant address across chains.</span><br/><br/>"+
            "To ensure future address integrity, regardless of the chain,"+
            "contracts deployed with 0xAether are guaranteed a unique and mapping-constant"+
            "address on all different current and future supported blockchains.</p>"
      },
      {
        img:levels["PseudoProxy Deployment"][1],
        section_id:'DC1',
        desc:
            "<p><span>0xAether-connected contracts are secure.</span><br/><br/>"+
            "Any contract deployment from the factory -including the original 0xAether contracts"+
            "are proxy guarded. Therefore, transactions are routed to the proxy and never the actual deployed contract."+
            "Which acts as a firewall to safe-guard transactions, between the contract, the public and the 0xAetherHub</p>"
      },
      {
        img:levels["PseudoProxy Deployment"][2],
        section_id:'DC2',
        desc:
            "<p><span>0xAether deployment tickets are ownable.</span><br/><br/>"+
            "When any contract is to be deployed with 0xAether, a deployment ticket with a unique `ticketID` is required."+
            "The ticketID and the owner of the ticket are constant pairs across all current and future supported blockchains. "+
            "In which the bearer can deploy any arbitrary smart contract and have it linked to previously deployed smart contracts.</p>"
      },
      
    ]
};

export const DAPP = [
    {
        title:"Dao",
        childs: [
            {
                title:"Variables",
                link:"/variables"
            },
            {
                title:"Proposals",
                link:"/proposals"
            },
        ],
    },
    {
        title:"Treasury",
        childs:[
            {
                title:"bonds",
                link:"/bonds"
            },
            {
                title:"Market",
                link:"/market"
            },
        ],
    },
    {
        title:"Tokens",
        childs:[
            {
                title:"Chain Transfer",
                link:"/chaintransfer"
            },
        ],
    },
    {
        title:"Factory",
        childs:[
            {
                title:"Tickets",
                link:"/tickets"
            },
            {
                title:"Deploy",
                link:"/deploy"
            },
        ],
    },
];