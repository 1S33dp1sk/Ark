import { FC, useState } from "react";
import { icons } from "../../assets";
import { FEATURES } from "../../constants";

export const FeatureGraph: FC = () => {
  const [level, setLevel] = useState<string>("Transaction Processing");
  const [scheme, setScheme] = useState(0);

  const DisplayedScheme: any = () => {
    switch (level) {
      case "Transaction Processing":
        return <img alt=""  src={FEATURES['Transaction Processing'][scheme]['img']} />;
      case "Index Balancing":
        return <img alt=""  src={FEATURES['Index Balancing'][scheme]['img']} />;
      case "PseudoProxy Deployment":
        return <img alt=""  src={FEATURES['PseudoProxy Deployment'][scheme]['img']} />;
      default:
        return;
    }
  };

  function handleScheme(cmd: any) {
    if (cmd === "inc") {
      if (scheme + 1 === (FEATURES as any)[level].length) {
        return;
      }
      setScheme(scheme + 1);
    } else {
      if (scheme === 0) {
        return;
      }
      setScheme(scheme - 1);
    }
  };

  return (
    <div className="tx_process">
      <div className="txp_head">
        <select
          onChange={(e) => {
            setScheme(0);
            setLevel(e.target.value);
          }}
        >
          {Object.keys(FEATURES).map((lv, idx) => (
            <option key={idx} value={lv}>
              {lv}
            </option>
          ))}
        </select>
      </div>

      <div className="tx_card">
        <div className="btns">
          <button onClick={() => handleScheme("dec")} className={scheme === 0 ? "deact" : ""}>
            <img alt=""  src={scheme === 0 ? icons.r_arrw : icons.r_arrw} style={{transform:"rotateZ(180deg)"}}/>
            Simplify scheme
          </button>
          <button onClick={() => handleScheme("inc")} className={scheme +1 === (FEATURES as any)[level].length ? "deact" : ""}>
            Advance scheme 
            <img alt=""  src={scheme +1 === (FEATURES as any)[level].length ? icons.r_arrw : icons.r_arrw} />
          </button>
        </div>

        <div className="sch">
          <DisplayedScheme />
        </div>

        <div className="txp_desc">
          <section id={(FEATURES as any)[level][scheme].section_id}
            dangerouslySetInnerHTML={{ __html: (FEATURES as any)[level][scheme].desc }}
          />
          <div className="sugg">
            <button >
              <img alt="" src={icons.qm} /> Questions?
            </button>
          </div>
        </div>
      </div>
    </div>
  );
};
