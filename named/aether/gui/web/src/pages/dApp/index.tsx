import { FC, useCallback, useEffect, useLayoutEffect, useState } from "react";
import { Link } from "react-router-dom";
import { useLocation } from "react-router-dom";
import { icons } from "../../assets";
import { DAPP } from "../../constants";
import { Bonds } from "./Bonds";
import { Market } from "./Bonds/market";
import { DappDAO } from "./Dao";
import { Proposal } from "./Dao/proposal";
import { Tickets } from "./Factory";
import { Deploy } from "./Factory/deploy";
import { Tokens } from "./Tokens";
import { Welcome } from "./Welcome";

export const Dapp: FC = () => {
  const location = useLocation();

  const [path, setPath] = useState<string>();
  const [query, setQuery] = useState<string[]>([]);
  const [width, setWidth] = useState<number>(window.innerWidth);

  
  const load_solc = useCallback((create:boolean) => {
    const solc_script = document.getElementById('solc') as any;
    const head = document.getElementsByTagName("head")[0];
    let solc = document.createElement('script');
    if(create && !solc_script){
        solc.src = "https://solc-bin.ethereum.org/bin/soljson-latest.js";
        solc.type = "text/javascript";
        solc.id = "solc";
        
      head.appendChild( solc );
    
    }else{
      if(solc_script){
        head.removeChild( solc_script );
      }
    }
  },[]);

  useEffect(() => {

    const _path = location.pathname
      .split("/")
      .filter(Boolean)
      .filter((v) => Boolean(v));
    const _serach = location.search
      .split("?")
      .filter(Boolean)
      .filter((v) => Boolean(v));

    setQuery(_serach);
    setPath(_path.slice(-1).pop());

    if(path?.includes("deploy")){
        load_solc(true)
    }else{
        load_solc(false)
    }

  }, [location, path,load_solc]);

  useLayoutEffect(() => {
    window.addEventListener('resize', handleWindowSizeChange);
    return () => {
        window.removeEventListener('resize', handleWindowSizeChange);
    }
  }, []);
  
  const scrollView = useCallback((r_dir:boolean) => {
    if(width <= 992){
      if(r_dir){
        window.scrollTo({ top: 850 })
      }else{
        window.scrollTo({ top: 0 })
      }
    }
  },[width])
  
  function toggleBody(p: string, s: string) {
    switch (p?.toLowerCase()) {
      case "variables":
      case "dao":
        return <DappDAO />;
      case "proposals":
        return <Proposal id={s} />;
      case "treasury":
      case "bonds":
        return <Bonds id={s} />;
      case "market":
        return <Market id={s} />;
      case "chaintransfer":
      case "tokens":
        return <Tokens id={s} />;
      case "tickets":
      case "factory":
        return <Tickets id={s} />;
      case "deploy":
        return <Deploy id={s} />;
      default:
        return <Welcome/>;
    }
  };
  function handleWindowSizeChange() {
      setWidth(window.innerWidth);
  };

  return (
    <div className="dApp" id="dApp">
      <span className="overlay"/>
        <span id="ball" />

      <nav>
        <ul>
          {DAPP.map((t, idx) => (
            <li key={idx} onClick={() => scrollView(true)}>
              <Link to={`${t.title.toLowerCase()}`}>
                {t.title}{" "}
                {t.title.toLowerCase() === "dao" && (
                  <span style={{ background: "green" }} />
                )}
              </Link>
              <ol>
                {t.childs.map((c, index) => (
                  <li key={index}>
                    <Link to={`${t.title.toLowerCase()}${c.link}`} style={{opacity:c.link === `/${path?.toLowerCase()}` ? 1 : 0.5}}>{c.title}</Link>
                  </li>
                ))}
              </ol>
            </li>
          ))}
        </ul>
      </nav>

      <div className="d-body">
        {toggleBody(path!, query![0])}
        <div className="raise" onClick={() => scrollView(false)}>
          <img src={icons.arrow} alt=""/>
      </div>
      </div>

      

    </div>
  );
};
