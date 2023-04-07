import { FC, useState } from "react";
import { icons } from "../../../assets";
import { filtration } from "../../../utils/helpers";
import { TOKEN } from "../../../utils/types";

export const Tokens: FC<any> = (props: any) => {
  const TOKENS = [
    {
      title: "0xA Token",
      address: "0x2d9762564fa6802B5Ca0853830AA3676a3a7B706",
      img: icons.aether,
    },
    {
      title: "Test Token",
      address: "0x3FZbgi29cpjq2GjdwV8eyHuJJnkLtktZc5qweadf",
      img: icons.aether,
    },
    {
      title: "second Token",
      address: "0x5dZbgpoiujnhg6tredV8eyHuJJnkLtktZc5zxcxs",
      img: icons.aether,
    },
  ];

  const [swap, setSwap] = useState({
    from: "",
    to: "",
  });

  const [popList, setPopList] = useState(false);
  const [tokens, setTokens] = useState<TOKEN[]>(TOKENS);
  const [token, setToken] = useState<TOKEN>({
    title:"---- Select a Token ----",
    img:"",
    address:""
  });

  const filterToken = (key: string) =>  {
    setTokens(filtration(key, TOKENS));
  };

  const handleToken = (val:TOKEN) => {
    setToken(val);
    setPopList(false);
  };


  return (
    <div className="dapp-container">
      <div className="dapp-content">
      <h1 id="title">0xAetherTokens {'\n'}:: Chain Transfer</h1>
          <p id="desc">
            Tokens Description {"\n"}
            Lorem Ipsum is simply dummy text of the printing and typesetting
            industry. Lorem Ipsum has been the industry's standard dummy text
            ever since the 1500s, when an unknown printer took a galley of type
            and scrambled it to make a type specimen book. It has survived not
            only five centuries, but also the leap into electronic typesetting,
          </p>
        <div className="chain-tf">
         

          <div className="swap">
            {popList && (
              <div className="pop-up">
                <div className="blur" onClick={() => setPopList(false)} />
                <div className="card-list">
                  <h1>Choose a Token</h1>

                  <input
                    type={"text"}
                    placeholder="search for token by address..."
                    onChange={(e) => filterToken(e.target.value)}
                  />
                  <ul>
                    {tokens.map((t, idx) => (
                      <li key={idx} onClick={() => handleToken(t)}>
                        <img src={t.img} alt=""/>{" "}
                        <h3>
                          {t.title}
                          <br />
                          <span>
                          {t.address}
                          </span>
                        </h3>
                      </li>
                    ))}
                  </ul>
                </div>
              </div>
            )}

            <label>
              Token Address:
              <div onClick={() => setPopList(true)} className='tok'>
                <div className="flex center">
                  <img src={token?.img} alt=""/>
                  <h3>
                    {token?.title}
                    <br />
                    <span>{token?.address}</span>
                  </h3>
                </div>
                <img src={icons.arrow} alt=""/>
              </div>
            </label>

            <section>
              <label>
                <h4>From</h4>
                <select
                  onChange={(e: any) =>
                    setSwap({ ...swap, from: e.target.value })
                  }
                >
                  <option disabled defaultValue={undefined}>
                    {" "}
                    -- select an chain --{" "}
                  </option>
                  <option value={"ETH"}>ETH</option>
                  <option value={"BSC"}>BSC</option>
                  <option value={"AVALANCHE"}>AVALANCHE</option>
                </select>
              </label>

              <div className="flex col ">
                <label>
                  Balance: <span>1500 {swap.from}</span>
                </label>
                <label>
                  Amount <input placeholder={`e.g: 0.1${swap.from}`} type={"text"}/>
                  <button>Max</button>
                </label>
              </div>
            </section>

            <section>
              <label>
                <h4>To</h4>
                <select
                  onChange={(e: any) => {
                    setSwap({ ...swap, to: e.target.value });
                  }}
                >
                  <option disabled defaultValue={undefined}>
                    {" "}
                    -- select a chain --{" "}
                  </option>
                  <option value={"ETH"}>ETH</option>
                  <option value={"BSC"}>BSC</option>
                  <option value={"AVALANCHE"}>AVALANCHE</option>
                </select>
              </label>
            </section>
          </div>
        </div>
      </div>

      <div className="action-btn">
        <button>Transfer</button>
      </div>
    </div>
  );
};
