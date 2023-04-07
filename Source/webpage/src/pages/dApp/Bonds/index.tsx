import { FC, useCallback, useEffect, useState } from "react";
import { Link } from "react-router-dom";
import { getTotality } from "../../../utils/helpers";

export const Bonds: FC<any> = (props: any) => {
  const [bonds, setBonds] = useState([]);
  const [bondInfo, setBondInfo] = useState<any>();
  const [bondId, setBondId] = useState<number>();

  const getLastProposals = useCallback(() => {
    var _num: any = 4;
    setBonds(getTotality(_num, bondId!));
  }, [bondId]);

  useEffect(() => {
    if (props.id!) {
      setBondInfo({ id: props.id });
    } else {
      setBondInfo(undefined);
      getLastProposals();
    }
  }, [bondId, props, getLastProposals]);

  return (
    <div className="dapp-container">
      <div className="dapp-content">
        <h1 id="title">0xAetherTreasury {"\n"}:: Bonds</h1>
        <p id="desc">
          Bonds Description {bondInfo?.id} {"\n"}
          Lorem Ipsum is simply dummy text of the printing and typesetting
          industry. Lorem Ipsum has been the industry's standard dummy text ever
          since the 1500s, when an unknown printer took a galley of type and
          scrambled it to make a type specimen book. It has survived not only
          five centuries, but also the leap into electronic typesetting,
          remaining essentially unchanged. It was popularised in the 1960s with
          the release of Letraset sheets containing Lorem Ipsum passages, and
          more recently with desktop publishing software like Aldus PageMaker
          including versions of Lorem Ipsum.
        </p>
        <div className="bonds">
          <input
            id="d-search"
            placeholder="serach by bond ID..."
            onChange={(e) => setBondId(parseInt(e.target.value))}
            value={bondId! ? bondId : undefined}
          />
          {bonds!.length > 0 ? (
            <ul>
              {bonds.map((b, idx) => (
                <li key={idx}>
                  <Link to={`market?${b}`} state={idx < 2 ? true : false}>
                    <h3>#{idx}</h3>
                    <img src={"https://aether.guru/bonds/template"} alt="" />
                  </Link>
                </li>
              ))}
            </ul>
          ) : (
            <div className="bonds">
              <h2>No Bonds</h2>
              <Link to="Bonds/market">Purchase</Link>
            </div>
          )}
        </div>
      </div>
    </div>
  );
};
