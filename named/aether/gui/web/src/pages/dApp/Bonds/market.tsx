import { useState } from "react";
import { useEffect } from "react";
import { FC } from "react";
import { useLocation } from "react-router-dom";

export const Market: FC<any> = (props: any) => {
  const location = useLocation();

  const [voteT, setVoteT] = useState<string>();
  const [isOwner, setIsOwner] = useState<string[]>();
  const [bondId, setBondId] = useState<number>()

  useEffect(() => {
    if(props.id){
      setBondId(props.id)
    }
    else{
      // Here will be the call function to get the last Bond Id available
      setBondId(100)
    }
    if (location.state) {
      setIsOwner(["Sell", "default"]);
    } else {
      setIsOwner(["Buy"]);
    }
  }, [location,props.id]);

  return (
    <div className="dapp-container">
      <div className="dapp-content">
      <h1 id="title">0xAetherTreasury {'\n'}:: Market : Bond#{bondId}</h1>
          <p id="desc">
            Bond {bondId} Description{"\n"} Lorem Ipsum is simply dummy text
            of the printing and typesetting industry. Lorem Ipsum has been the
            industry's standard dummy text ever since the 1500s, when an unknown
            printer took a galley of type and scrambled it to make a type
            specimen book. It has survived not only five centuries, but also the
            leap into electronic typesetting, remaining essentially unchanged.
            It was popularised in the 1960s with the release of Letraset sheets
            containing Lorem Ipsum passages, and more recently with desktop
            publishing software like Aldus PageMaker including versions of Lorem
            Ipsum
          </p>
        <div className="bond">
          
          <ul>
            {isOwner?.map((b, idx) => (
              <li
                key={idx}
                onClick={() => setVoteT(b)}
                style={{ background: voteT === b ? "#4205F0" : "" }}
              >
                {b}
              </li>
            ))}
          </ul>

          <div>Bond Props</div>
        </div>
      </div>
      <div className="action-btn">
        <button>Execute</button>
      </div>
    </div>
  );
};
