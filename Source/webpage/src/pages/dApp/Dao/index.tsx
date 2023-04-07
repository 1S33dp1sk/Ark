import { FC, useState } from "react";
import { icons } from "../../../assets";
import { toggleVar } from "../../../utils/helpers";

export const DappDAO: FC<any> = (props: any) => {
  const DUMMY_VARIABLELIST = [
    {
      name: "VARIABLE 0",
      oscillation: "in 4d:2h:30m",
      val: 100000,
      edited: false,
    },
    {
      name: "Budget 1",
      oscillation: "in 4d:2h:30m",
      val: 100000,
      edited: true,
    },
    {
      name: "TXNS 2",
      oscillation: "in 4d:2h:30m",
      val: 100000,
      edited: false,
    },
    {
      name: "VARIABLE 0",
      oscillation: "in 4d:2h:30m",
      val: 100000,
      edited: false,
    },
    {
      name: "Budget 1",
      oscillation: "in 4d:2h:30m",
      val: 100000,
      edited: true,
    },
    {
      name: "TXNS 2",
      oscillation: "in 4d:2h:30m",
      val: 100000,
      edited: false,
    },
    {
      name: "VARIABLE 0",
      oscillation: "in 4d:2h:30m",
      val: 100000,
      edited: false,
    },
    {
      name: "Budget 1",
      oscillation: "in 4d:2h:30m",
      val: 100000,
      edited: true,
    },
    {
      name: "TXNS 2",
      oscillation: "in 4d:2h:30m",
      val: 100000,
      edited: false,
    },
    {
      name: "VARIABLE 0",
      oscillation: "in 4d:2h:30m",
      val: 100000,
      edited: false,
    },
    {
      name: "Budget 1",
      oscillation: "in 4d:2h:30m",
      val: 100000,
      edited: true,
    },
    {
      name: "TXNS 2",
      oscillation: "in 4d:2h:30m",
      val: 100000,
      edited: false,
    },

  ];

  const [result, setResult] = useState(DUMMY_VARIABLELIST);

  const filter = (e: any) => {
    const keyword = e.target.value;

    if (keyword !== "") {
      const _vars = DUMMY_VARIABLELIST.filter((user) => {
        return user.name.toLowerCase().includes(keyword.toLowerCase());
      });

      setResult(_vars);
    } else {
      setResult(DUMMY_VARIABLELIST);
    }
  };


  const updateFieldChanged = (index:any) => (e:any) => {
    let newArr = [...result]; // copying the old datas array
    newArr[index]['val'] = e.target.value; // replace e.target.value with whatever you want to change it to
    setResult(newArr);
  }

  return (
    <div className="dapp-container">
      <div className="dapp-content">
      <h1 id="title">0xAetherDAO {'\n'}:: Variables</h1>
          <p id="desc">
            DAPP DAO Description Lorem Ipsum is simply dummy text of the
            printing and typesetting industry. Lorem Ipsum has been the
            industry's standard dummy text ever since the 1500s, when an unknown
            printer took a galley of type and scrambled it to make a type
            specimen book. It has survived not only five centuries, but also the
            leap into electronic typesetting, remaining essentially unchanged.
            It was popularised in the 1960s with the release of Letraset sheets
            containing Lorem Ipsum passages, and more recently with desktop
            publishing software like Aldus PageMaker including versions of Lorem
            Ipsum.
          </p>
        <div className="dao">
          
            <div className="dao-search">
              <input
                placeholder="Search by variable name/ variable reference..."
                onChange={filter}
              />
            </div>
            <ul>
              {result.length > 0 ? (
                result?.map((v, idx) => (
                  <li key={idx} id={`dao_var${idx}`}>
                    <div onClick={() => toggleVar(`dao_var${idx}`)}>
                      <h4>
                        {v.name}: {v.val}
                      </h4>
                    </div>

                    <div className="d-val">
                      <section>
                          <img alt="" src={icons.clock} style={{filter: v.edited ?"invert(24%) sepia(90%) saturate(1732%) hue-rotate(100deg) brightness(99%) contrast(104%)" : "invert(15%) sepia(99%) saturate(6024%) hue-rotate(2deg) brightness(98%) contrast(118%)"}}/>
                        <h3>{v.oscillation}</h3>
                        <input
                          key={idx}
                          placeholder="Value..."
                          onChange={updateFieldChanged(idx)}
                          style={
                            !v.edited
                              ? { opacity: 0.4, pointerEvents: "none" }
                              : {}
                          }
                        />
                      </section>
                      <button
                        disabled={v.edited ? false : true}
                        style={
                          !v.edited
                            ? {
                                opacity: 0.4,
                                cursor: "default",
                                transform: "none",
                              }
                            : {}
                        }
                      >
                        Submit
                      </button>
                    </div>
                  </li>
                ))
              ) : (
                <h1>No results found!</h1>
              )}
            </ul>
          </div>
        </div>
      </div>
  );
};
