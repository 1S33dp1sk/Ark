import { FC, useCallback, useEffect, useState } from "react";
import { icons } from "../../assets";
import { Searchbar } from "../../components/Searchbar";
import { BLOCKSTABLE, CHAINS_, TABLES_TITLES } from "../../constants";
import { BLOCKDATA, CHAIN } from "../../utils/types";
import { changeChain, initW3Contract } from "../../utils/functions";
import { useWeb3React } from "@web3-react/core";
import { Web3Provider } from "@ethersproject/providers";
import { useParams } from "react-router-dom";
import { CONTRACTS } from "../../constants/contracts";
import { Loader } from "../../components/Loader";
import { notify } from "../../utils/helpers";

export const Logs: FC<any> = (props: any) => {
  const { chainId} = useWeb3React<Web3Provider>();
  const { block_num } = useParams();

  const [searchData, setSearchData] = useState({ address: "", filter: "" });
  const [blocks, setBlocks] = useState<BLOCKDATA[]>(BLOCKSTABLE.blocks);
  const [txns, setTxns] = useState<any>([{
    id:"",
    address:"",
    status:"",
    Time:""
  }])
  const [tab, setTab] = useState("Latest Blocks");
  const [chain, setChain] = useState<CHAIN>(CHAINS_["1"]);
  const [loading, setLoading] = useState(false);

  function openMenu() {
    var menu = document.getElementById("ch-menu");
    if (menu?.className === "ch-menu") {
      menu!.className += " open";
    } else {
      menu!.className = "ch-menu";
    }
  };

  useEffect(() => {
    if (chainId!) {
      if((CHAINS_ as any)[chainId]){
        if ((CHAINS_ as any)[chainId]["id"] === chainId) {
          setChain((CHAINS_ as any)[chainId]);
        }
      }else{
        notify ('warn', "CHANGE CONNECTED CHAIN !")
      }
      
    }
  }, [chainId]);

  const getBlockData = useCallback( async () => {
    var _blocks = [];
    var _cont = await initW3Contract(CONTRACTS.HUB.address, CONTRACTS.HUB.abi);
    var _bn: number = parseInt(await getBlockNumber());
    var _block;
    if (_bn < 5) {
      for (let i = 0; i < _bn; i++) {
        _block = await _cont.methods.getABlock(i).call();
        _blocks.push({
          id: i,
          master_hash: _block["aBlockMasterHash"],
          aethering_address: _block["aBlockAetheringAddr"],
          txn_amount: _block["aBlockTxnCount"],
        });
      }
    } else {
      for (let i = _bn - 4; i <= _bn; i++) {
        _block = await _cont.methods.getABlock(i).call();
        _blocks.push({
          id: i,
          master_hash: _block["aBlockMasterHash"],
          aethering_address: _block["aBlockAetheringAddr"],
          txn_amount: _block["aBlockTxnCount"],
        });
      }
    }
    setBlocks(_blocks);
    setLoading(false);
  },[])

  useEffect(() => {
    if(block_num!){
      getBlockData();
      setTxns(undefined)
    }
  }, [block_num, chainId,getBlockData]);

  async function getBlockNumber() {
    var _cont = await initW3Contract(CONTRACTS.HUB.address, CONTRACTS.HUB.abi);
    try {
      var _bn = await _cont.methods.aetherBlockNum().call();
    } catch {
      notify("error", "Block number not exist");
    }
    return _bn;
  }

  return (
    <div className="logs">

      <div className="bg_cube">
        <div className="h_log">
          <div className="flex col">
            <div className="flex center">
              <h1>Logs & Txns</h1>
              <h2>
                Aether / <span>OxA</span>
              </h2>
            </div>
            <img alt="" src={icons.aether} />
          </div>
          <Searchbar searchData={searchData} setSearchData={setSearchData} />
        </div>
      </div>

      <div className="boxs_cont">
        <div className="info">
          <div className="box">
            <ul>
              <li>
                <img alt="" src={icons.A} />
                <h3>
                  Aether price {"\n"}
                  <span>
                    $0.34
                    <span>(0.44%)</span>
                  </span>
                </h3>
              </li>

              <li>
                <img alt="" src={""} />
                <h3>
                  Transactions {"\n"}
                  <span>14 445 678</span>
                </h3>
              </li>

              <li>
                <img alt="" src={""} />
                <h3>
                  Market capitalization {"\n"}
                  <span>$345,3478,678.00</span>
                </h3>
              </li>
              <li>
                <img alt="" src={""} />
                <h3>
                  Market capitalization {"\n"}
                  <span>$345,3478,678.00</span>
                </h3>
              </li>
            </ul>
          </div>
          <div
            className="ch-menu"
            id="ch-menu"
            onClick={() => openMenu()}
            style={{ backgroundImage: `url(${chain?.logo})` }}
            title={chain?.name}
          >
            {Object.keys(CHAINS_).map((c, idx) => (
              <div
                key={idx}
                className="m-chain"
                style={{
                  backgroundImage: `url(${(CHAINS_ as any)[c]["logo"]})`,
                }}
                onClick={() => changeChain(c)}
                title={(CHAINS_ as any)[c]["name"]}
              ></div>
            ))}
          </div>

          {/* VARIABLES BY DAO */}
          <div className="box">
            <ul>
              <li>
                <img alt="" src={""} />
                <h3>
                  Max Txn / block {"\n"}
                  <span>14 445 678</span>
                </h3>
              </li>
              <li>
                <img alt="" src={""} />
                <h3>
                  Max Blocks / block {"\n"}
                  <span>14 445 678</span>
                </h3>
              </li>
              <li>
                <img alt="" src={""} />
                <h3>
                  Node Threshold{"\n"}
                  <span>14 445 678</span>
                </h3>
              </li>
              <li>
                <img alt="" src={""} />
                <h3>
                  Bond Maturity time {"\n"}
                  <span>14 445 678</span>
                </h3>
              </li>
            </ul>
          </div>
        </div>

        <div className="box blocks">
          <ul className="nav-pills">
            <li className="nav-item">
              <button
                className={tab === "Latest Blocks" ? "active" : ""}
                onClick={() => setTab("Latest Blocks")}
              >
                Latest Blocks
              </button>
            </li>
            <li className="nav-item">
              <button
                className={tab === "Currently Txns" ? "active" : ""}
                onClick={() => setTab("Currently Txns")}
              >
                Currently Txns
              </button>
            </li>
          </ul>
          {loading ? (
            <Loader />
          ) : tab === "Latest Blocks" ? (
              <div className="table-wrap">
              <div className="t_head">
                <p>Total 3230 Blocks Found</p>
                <div className="flex center">
                  <button>
                    <img src={icons.sm_arr} alt=""/>
                  </button>
                  <p>Page 1 Of 123</p>
                  <button>
                    <img src={icons.sm_arr} alt=""/>
                  </button>
                </div>
              </div>
                <table>
                  <thead>
                    <tr>
                      {TABLES_TITLES.block.map((t, idx) => (
                        <th key={idx}>{t}</th>
                      ))}
                    </tr>
                  </thead>

                  <tbody>
                    {blocks.map((b, idx) => (
                      <tr key={idx}>
                        <td>
                          <span>{b.id}</span>
                        </td>
                        <td> {b.master_hash}</td>
                        <td> {b.aethering_address}</td>
                        <td>
                          {" "}
                          <a href="/">
                            {b.txn_amount}
                            &nbsp;
                            <span>{chain["symbol"]}</span>
                          </a>
                        </td>
                      </tr>
                    ))}
                  </tbody>
                </table>
              </div>
          ) : (
            <div className="table-wrap">
            <div className="t_head">
              <p>Total 3230 Txns Found</p>
              <div className="flex center">
                <button>
                  <img src={icons.sm_arr} alt=""/>
                </button>
                <p>Page 1 Of 123</p>
                <button>
                  <img src={icons.sm_arr} alt=""/>
                </button>
              </div>
            </div>
              <table>
                <thead>
                  <tr>
                    {TABLES_TITLES.txn.map((t, idx) => (
                      <th key={idx}>{t}</th>
                    ))}
                  </tr>
                </thead>

                <tbody>
                  {txns?.map((b:any, idx:number) => (
                    <tr key={idx}>
                      <td>
                        <span>{b.id}</span>
                      </td>
                      <td> {b.address}</td>
                      <td> {b.status}</td>
                      <td> {b.Time}</td>
                      
                    </tr>
                  ))}
                </tbody>
              </table>
            </div>
          )}
            <button className="view_btn">View all blocks</button>
        </div>
      </div>
    </div>
  );
};
