import { Web3Provider } from "@ethersproject/providers";
import { Web3ReactProvider } from "@web3-react/core";
import { FC } from "react";
import { AppLayout } from "../../layout";
import { MetamaskProvider } from "./MetamaskProvider";

export const Providers: FC<any> = ({ children }) => {
    
  function getLibrary(provider: any) {
    const library = new Web3Provider(provider);
    library.pollingInterval = 12000;
    return library;
  }

  return (
    <Web3ReactProvider getLibrary={getLibrary}>
      <MetamaskProvider>
        <AppLayout>{children}</AppLayout>
      </MetamaskProvider>
    </Web3ReactProvider>
  );
};
