// We require the Hardhat Runtime Environment explicitly here. This is optional
// but useful for running the script in a standalone fashion through `node <script>`.
//
// When running the script with `npx hardhat run <script>` you'll find the Hardhat
// Runtime Environment's members available in the global scope.
import { ethers } from "hardhat";
import { Contract , ContractTransaction , ContractReceipt } from "ethers";
import { expect } from "chai";

async function main() {

    const [deployer] = await ethers.getSigners();

    console.log("Deploying contracts with the account:", deployer.address);
    const CIDS = [1234,4321];

    // define contract instances
    // and a common variable to each
    // with deployment-contract variable

    let AetherFactory:any,factory:Contract;
    let router:Contract;

    let AetherHUB:any,hub:Contract;
    let node:Contract;

    let AetherDAO:any,dao:Contract;
    let token:Contract;

    let KeeperAether:any,keeper:Contract;
    let bonds:Contract;

    // list of all aether contracts that need to be proxiedTo
    let HUB_PROXY,DAO_PROXY,KEEPER_PROXY,TOKEN_PROXY,BONDS_PROXY;
    KeeperAether = await ethers.getContractFactory("KeeperAether");
    AetherFactory = await ethers.getContractFactory("AetherFactory");
    AetherHUB = await ethers.getContractFactory("AetherHUB");
    AetherDAO = await ethers.getContractFactory("AetherDAO");

    console.log('\n--------------------AETHER DEPLOYMENT----------------------------------\n')

    // deploy the factory
    factory = await AetherFactory.deploy();
    await factory.deployed();
    console.log( "FACTORY\tADDRESS\t : " , factory.address );

    // the factory automatically deploys
    // the router, so we just retireve router address
    const routerAddr = await factory.aetherRouter();
    console.log( "ROUTER\tADDRESS\t : " , routerAddr );

    // attach 
    router = await ethers.getContractAt("AetherRouter", routerAddr);

    // the dao automatically deploys
    // the token
    dao = await AetherDAO.deploy();
    await dao.deployed();
    console.log( "DAO\tADDRESS\t : " , dao.address );
    // retireve token address
    token = await dao._AetherToken_();
    console.log( "TOKEN\tADDRESS\t : " , token );

    // the hub selectivly deploys nodes.
    hub = await AetherHUB.deploy(CIDS);
    await hub.deployed();
    console.log("HUB\tADDRESS\t : " , hub.address );

    // the keeper automatically deploys
    // the bonds
    keeper = await KeeperAether.deploy();
    await keeper.deployed();
    console.log( "KEEPER\tADDRESS\t : " , keeper.address );
    // retireve bond address
    bonds = await keeper._AetherBonds_();
    console.log( "BONDS\tADDRESS\t : " , bonds );

    let _proxyTxn:ContractTransaction;
    let _receipt:ContractReceipt;
    let _proxyAddress:string;
    let _ctxCheck:string;


    // DAO
    _proxyTxn = await factory.deployProxy( dao.address , 2 );
    _receipt = await _proxyTxn.wait();
    //@ts-ignore
    _proxyAddress = _receipt.events?.filter( ( x:any ) => { return x.event == "ProxyDeployed" } )[0].args[0];
    // create the actual DAO contract to interact with
    DAO_PROXY = await ethers.getContractAt("AetherDAO", _proxyAddress);
    //system check
    _ctxCheck = await factory.aetherDAO();
    expect( _ctxCheck.toLowerCase()).equal( _proxyAddress.toLowerCase())
    console.log( "Context Check : aetherDAO() :: " , _ctxCheck );


    // TOKEN
    _proxyTxn = await factory.deployProxy( token , 3 );
    _receipt = await _proxyTxn.wait();
    //@ts-ignore
    _proxyAddress = _receipt.events?.filter( ( x:any ) => { return x.event == "ProxyDeployed" } )[0].args[0];
    // create the actual TOKEN contract to interact with
    TOKEN_PROXY = await ethers.getContractAt("AetherToken", _proxyAddress);
    //system check
    _ctxCheck = await factory.aetherToken();
    expect( _ctxCheck.toLowerCase()).equal( _proxyAddress.toLowerCase())
    console.log( "Context Check : aetherToken() :: " , _ctxCheck );


    // HUB
    _proxyTxn = await factory.deployProxy( hub.address , 4 );
    _receipt = await _proxyTxn.wait();
    //@ts-ignore
    _proxyAddress = _receipt.events?.filter( ( x:any ) => { return x.event == "ProxyDeployed" } )[0].args[0];
    HUB_PROXY = await ethers.getContractAt("AetherHUB", _proxyAddress);
    //system check
    _ctxCheck = await factory.aetherHUB();
    expect( _ctxCheck.toLowerCase()).equal( _proxyAddress.toLowerCase())
    console.log( "Context Check : aetherHUB() :: " , _ctxCheck );

    // KEEPER
    _proxyTxn = await factory.deployProxy( keeper.address , 5 );
    _receipt = await _proxyTxn.wait();
    //@ts-ignore
    _proxyAddress = _receipt.events?.filter( ( x:any ) => { return x.event == "ProxyDeployed" } )[0].args[0];
    KEEPER_PROXY = await ethers.getContractAt("KeeperAether", _proxyAddress);
    //system check
    _ctxCheck = await factory.aetherKeeper();
    expect( _ctxCheck.toLowerCase()).equal( _proxyAddress.toLowerCase())
    console.log( "Context Check : aetherKeeper() :: " , _ctxCheck );

    
    // BONDS
    _proxyTxn = await factory.deployProxy( bonds , 6 );
    _receipt = await _proxyTxn.wait();
    //@ts-ignore
    _proxyAddress = _receipt.events?.filter( ( x:any ) => { return x.event == "ProxyDeployed" } )[0].args[0];
    // create the actual TOKEN contract to interact with
    BONDS_PROXY = await ethers.getContractAt("AetherBonds", _proxyAddress);
    //system check
    _ctxCheck = await factory.aetherBonds();
    expect( _ctxCheck.toLowerCase()).equal( _proxyAddress.toLowerCase())
    console.log( "Context Check : aetherBonds() :: " , _ctxCheck );




    // final context check

    // check if the last deployed proxy 
    // AetherBonds has the correct address
    // of the first contract deployed
    // without any proxy AetherFactory

    const aetherFactory_check = await BONDS_PROXY.aetherFactory();
    expect( aetherFactory_check.toLowerCase() ).equal( factory.address.toLowerCase() );
    console.log( "Factory Check Contexted Passed" );

    // && check if the first deployed proxy AetherDAO
    // has the last deployed proxy AetherBonds
    const aetherDAO_check = await DAO_PROXY.aetherBonds();
    expect( aetherDAO_check.toLowerCase() ).equal( BONDS_PROXY.address.toLowerCase() );
    console.log( "DAO Proxy Check Contexted Passed" );
}

// We recommend this pattern to be able to use async/await everywhere
// and properly handle errors.
main().catch((error) => {
  console.error(error);
  process.exitCode = 1;
});
