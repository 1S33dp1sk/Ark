import { FC, useCallback, useEffect, useState } from "react";
import { Link } from "react-router-dom";

export const Proposal: FC<any> = (props: any) => {
  const vote_t = ["With", "Neutral", "Against"];
  const [voteT, setVoteT] = useState<string>();
  const [proposals, setProposals] = useState([]);
  const [proposalId, setProposalId] = useState<number>();
  const [proposalInfo, setProposalInfo] = useState<any>();

  const getLastProposals = useCallback(() => {
    var _propNum = 12;
    let _props: any = [];
    if (proposalId) {
      _props.push(proposalId);
    } else {
      for (let i = _propNum; i > _propNum - 5; i--) {
        if (i >= 0) {
          _props.push(i);
        }
      }
    }
    setProposals(_props);
  },[proposalId]);

  useEffect(() => {
    if (props.id!) {
      setProposalInfo({ value: props.id });
    } else {
      setProposalInfo(undefined);
      getLastProposals();
    }
  }, [proposalId, props, getLastProposals]);

  return (
    <div className="dapp-container">
        {proposalInfo! ?
        <>
          <div className="dapp-content">
          <h1 id="title">0xAetherDAO {'\n'}:: Proposal#{proposalInfo.value}</h1>
            <p id="desc">
              Proposal {proposalInfo.value} Description{'\n'}
              Lorem Ipsum is simply dummy text of the printing and typesetting
              industry. Lorem Ipsum has been the industry's standard dummy text
              ever since the 1500s, when an unknown printer took a galley of
              type and scrambled it to make a type specimen book. It has
              survived not only five centuries, but also the leap into
              electronic typesetting, remaining essentially unchanged. It was
              popularised in the 1960s with the release of Letraset sheets
              containing Lorem Ipsum passages, and more recently with desktop
              publishing software like Aldus PageMaker including versions of
              Lorem Ipsum.
            </p>
          <div className="proposal">
            

            <table>
              <thead>
                <tr>
                  <td>Choose Vote {'->'}</td>
                  {vote_t.map((v, idx) => (
                    <td
                      key={idx}
                      onClick={() => setVoteT(v)}
                      style={{ background: voteT === v ? "#4205F0" : "" }}
                    >
                      {v}
                    </td>
                  ))}
                </tr>
                <tr>
                  <td>Total Votes</td>
                  <td>150</td>
                  <td>100</td>
                  <td>50</td>
                </tr>
              </thead>
            </table>
            </div>
          </div>
          <div className="action-btn">
          <button>Vote</button>
        </div>
        </>
         : 
          <div className="dapp-content">
 <h1 id="title">0xAetherDAO :: Proposals</h1>
            <p id="desc">
              Lorem Ipsum is simply dummy text of the printing and typesetting
              industry. Lorem Ipsum has been the industry's standard dummy text
              ever since the 1500s, when an unknown printer took a galley of
              type and scrambled it to make a type specimen book. It has
              survived not only five centuries, but also the leap into
              electronic typesetting, remaining essentially unchanged. It was
              popularised in the 1960s with the release of Letraset sheets
              containing Lorem Ipsum passages, and more recently with desktop
              publishing software like Aldus PageMaker including versions of
              Lorem Ipsum.
            </p>
          <div className="proposal">
           
            <input
                id="d-search"
                placeholder="serach for speceific proposal..."
                onChange={(e) => setProposalId(parseInt(e.target.value))}
                value={proposalId! ? proposalId : ""}
            />

            <h2>Latest Propsals</h2>
            <ol>
              {proposals.map((p, idx) => (
                <li key={idx}>
                  <Link to={`?${p}`}>AP {p}</Link>
                </li>
              ))}
            </ol>
          </div>
        </div>

        }

      
    </div>
  );
};
