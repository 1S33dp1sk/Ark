import { InjectedConnector } from '@web3-react/injected-connector';
import { WalletConnectConnector } from '@web3-react/walletconnect-connector';


const RPC_URLS = {
  1: "https://mainnet.infura.io/v3/84842078b09946638c03157f83405213",
  4: "https://rinkeby.infura.io/v3/84842078b09946638c03157f83405213",
  137:"https://rpc-mainnet.maticvigil.com/"
};


const supportedChainsIDs = [1,3, 4, 5, 42 , 25, 56, 137, 250, 43114]

export const injectedConnector = new InjectedConnector({supportedChainIds:supportedChainsIDs,});

export const walletconnect = new WalletConnectConnector({
  rpc: { 1: RPC_URLS[1], 4: RPC_URLS[4], 137:RPC_URLS[137]},
  bridge: "https://bridge.walletconnect.org",
  qrcode: true,
});