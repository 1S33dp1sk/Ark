import Web3 from "web3";
import { CHAINS_ } from "../../constants";
import { injectedConnector, walletconnect } from "../../constants/connectors";


export function connectMapper(conn_type: string, active: any, activate: any) {
  if (!active) {
    switch (conn_type) {
      case "Metamask":
        return connectInjected(activate);
      case "WalletConnect":
        return connectWalletConnect(activate);
      default:
        return connectInjected(activate);
    }
  }
};
async function connectInjected(activate: any) {
  try {
    await activate(injectedConnector);
  } catch (ex) {
  }
};
async function connectWalletConnect(activate: any) {
  await activate(walletconnect);
};
export async function disconnect(deactivate: any) {
  try {
    await deactivate();
  } catch (ex) {
    console.log(ex);
  }
};
export async function changeChain(id:string){
  var ch = (CHAINS_ as any)[id];
  if (window.ethereum.networkVersion !== id) {
      try {
        await window.ethereum.request({
          method: 'wallet_switchEthereumChain',
          params: [{ chainId: Web3.utils.toHex(id) }],
        });

      } catch (err:any) {
          // This error code indicates that the chain has not been added to MetaMask.
        if (err.code === 4902) {
          await window.ethereum.request({
            method: 'wallet_addEthereumChain',
            params: [
              {
                chainName:ch['name'],
                chainId: Web3.utils.toHex(id) ,
                rpcUrls: ch['rpc'],
              },
            ],
          });
        }
      }
    }
};

// WEB3 CALLS

export async function initW3Contract(contractAddress: string, contractAbi: any){
    
  var w3 = new Web3(new Web3.providers.HttpProvider('http://127.0.0.1:8545'));
  //  w3 = new Web3(Web3.givenProvider)
  const contract = new w3.eth.Contract(contractAbi, contractAddress);
  return contract;
};

