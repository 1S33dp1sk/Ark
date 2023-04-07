import { Web3Provider } from "@ethersproject/providers";
import { useWeb3React } from "@web3-react/core";
import { FC, useEffect, useState } from "react";
import { icons, images } from "../../assets";
import { WalletModal } from "../../components/WalletModal";
import { NAVBAR } from "../../constants";
import { walletAddress } from "../../utils/helpers";

export const Navbar: FC<any> = (props: any) => {
  let _path = window.location.pathname;

  const { active, account, activate } = useWeb3React<Web3Provider>();
  const [displayModal, setDisplayModal] = useState<boolean>(false);
  const [responsive, setResponsive] = useState(false);
  const [isDapp, setIsDapp] = useState(false);

  useEffect(() => {
    if (_path.toLowerCase().includes("dapp")) {
      setIsDapp(true);
    }
  }, [_path]);


  const toggleTheme = () => {
    const newTheme = props.theme === "light" ? "dark" : "light";
    props.setTheme(newTheme);
  };

  return (
    <>
      {displayModal && (
        <WalletModal
          active={active}
          activate={activate}
          setDisplayModal={setDisplayModal}
        />
      )}

      <div className="appbar">
        <a href="/" className="logo">
          <img src={props.theme === "dark" ? images.b_logo : images.w_logo} alt="LOGO" />
        </a>

        <div
          className={isDapp ? "none" : "mob_menu"}
          onClick={() => setResponsive(!responsive)}
        >
          <img src={icons.mob_menu} alt="menu" />
        </div>
        {!isDapp && (
          <ul className={responsive ? "res" : ""}>
            {NAVBAR.map((i, idx) => (
              <li key={idx}>
                <a href={i.link}>{i.name}</a>
              </li>
            ))}
          </ul>
        )}
        {
          <section>
            {isDapp ? (
              <button onClick={() => (!active ? setDisplayModal(true) : null)}>
                {walletAddress(account)}
              </button>
            ) : (
              <a href={"/dApp/"} id="nav-btn">
                go to dApp
              </a>
            )}

            <div className="toggle-btn" id="_1st-toggle-btn">
              <input type="checkbox" checked={props.theme === 'light' ? true : false} onChange={toggleTheme}/>
              <span/>
            </div>
          </section>
        }
      </div>
    </>
  );
};
