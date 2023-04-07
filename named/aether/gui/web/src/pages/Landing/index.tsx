import { FC } from "react";
import { icons } from "../../assets";
import { FeatureGraph } from "../../components/FeatureGraph";
import { ParallaxCard } from "../../components/ParallaxCard";
import { GUIDES, SOCILAS } from "../../constants";

export const Landing: FC<any> = (props: any) => {

  const FEATURES = [
    {
      icon:icons.cost,
      desc:"Minimize cost in EVM compatible chains"
    },
    {
      icon:icons.ip,
      desc:"integrity and speed of data"
    },
    {
      icon:icons.network,
      desc:"tamper-proof network"
    },
    {
      icon:icons.wallet,
      desc:"Secure off-chain computation"
    },
  ]


  return (
    <div className="landing" >

      <div className="land_bg">

        <div className="land_h">
          <div className="l_h">
            <img alt="" src={icons.athr_wht} />
            <h1>The Multi chain Haven</h1>
          </div>
          <div className="r_h">
              <ParallaxCard />
          </div>
        </div>
      </div>

      <div className="features">
        <section>
          <ul>
            <li><a href="/guides#0xAether">Guides</a></li>
            <li><a href="/logs">Logs&TXNS</a></li>
            <li><a href="/dashboard">Dashboard</a></li>
          </ul>

          <ul>
            {FEATURES.map((f, idx) => 
            
            <li key={idx}>
              <img src={f.icon} alt=""/>
              <p>{f.desc}</p>
            </li>
          )}
          </ul>
          </section>
      </div>

      <FeatureGraph />

      <div className="last_sec">
        <div className="guides" id="guides">
          <ul>
            {GUIDES.map((g, idx) => (
              <li key={idx} onClick={() => window.open(g.site, "_blank")}>
                <div>
                  <h2>Guides/{g.name}</h2>
                  <p>{g.desc}</p>
                </div>

                  <h3>{g.action} <img alt="" src={icons.arrow} /></h3>
              </li>
            ))}
            <div className="more">
              
              <button onClick={() => window.open("/guides#0xAether", "_blank")}>
                More developer guides
            </button>
          </div>
          </ul>
          
          
        </div>

        <div className="community">
          <h2>Join Our Community</h2>
          <ul>
            {SOCILAS.map((s, idx) => (
              <li key={idx}>
                <a href={s.link} target="_blank" rel="noreferrer">
                  <h3>
                    <img alt="" src={s.logo} />
                    {s.name}
                  </h3>
                  <p>
                    {s.desc} <img alt="" src={icons.arrow} />
                  </p>
                </a>
              </li>
            ))}
          </ul>
        </div>
      </div>

    </div>
  );
};
