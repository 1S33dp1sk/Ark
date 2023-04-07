import React, { useEffect, useState } from "react";
import { useWeb3React } from "@web3-react/core";
import { Web3Provider } from "@ethersproject/providers";
import { injectedConnector } from "../../constants/connectors";
import { Loader } from "../../components/Loader";
import { PROPS } from "../types";

export const MetamaskProvider = ({ children }: PROPS): React.ReactElement => {
  const { active, error, activate } = useWeb3React<Web3Provider>();
  const [loaded, setLoaded] = useState(false);

  useEffect(() => {
    setLoaded(true);
    if (!loaded) {
      injectedConnector
        .isAuthorized()
        .then((isAuthorized: boolean) => {
          setLoaded(true);

          if (isAuthorized && !active && !error) {
            activate(injectedConnector);
          }
        })
        .catch(() => {
          setLoaded(true);
        });
    }

    if (window.ethereum && window.ethereum.on && !active && !error) {
      const handleChainChanged = () => {
        activate(injectedConnector);
      };

      const handleAccountsChanged = (accounts: any) => {
        if (accounts.length > 0) {
          activate(injectedConnector);
        }
      };

      window.ethereum.on("chainChanged", handleChainChanged);
      window.ethereum.on("accountsChanged", handleAccountsChanged);

      return () => {
        if (window.ethereum.removeListener) {
          window.ethereum.removeListener("chainChanged", handleChainChanged);
          window.ethereum.removeListener("accountsChanged",handleAccountsChanged);
        };
      };
    };
  }, [active, error, loaded, activate]);

  if (loaded) {
    return children;
  }

  return (
    <div style={{ height: "100vh" }}>
      <Loader />
    </div>
  );
};
