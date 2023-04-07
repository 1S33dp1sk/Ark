import { FC, useCallback, useEffect, useRef, useState } from "react";
import { SmallLoader } from "../../../components/smallLaoder";
import { copyData, notify } from "../../../utils/helpers";
import { COMPILEDCONTRACT, COMPILINGERROR } from "../../../utils/types";

// contract C { function f(uint x) public { assert(x > 0); } }
export const Deploy: FC<any> = (props: any) => {

  let _code = useRef() as any;
  let _lines = useRef() as any;


  const [contract, setContract] = useState("");
  const [contractData, setContractData] = useState<COMPILEDCONTRACT | undefined>();
  const [compiling, setCompiling] = useState(false);
  const [errorsList, setErrorsList] = useState<COMPILINGERROR[]>();

  const contractCode = (e:any) => {
    setContract(e.target.value);
  };

  function compileContract(contract_:string) {
  
    var abi: any[] = [];
    var bytes: string = "";
    var output

    setCompiling(true);
    setContractData(undefined);
    setErrorsList(undefined);


    if (contract_) {

      var input = {
        language: "Solidity",
        sources: {
          "temp.sol": {
            content: contract_,
          },
        },
        settings: {
          outputSelection: {
            "*": {
              "*": ["*"],
            },
          },
        },
      };

      try{
        const wrapper = require("solc/wrapper");
        const solc = wrapper(window.Module);
        output = JSON.parse(solc.compile(JSON.stringify(input)));

          if(output.errors){
            setErrorsList(output.errors);
            notify('warn', "Contract Compiled With Errors!")

          }else{
            notify('success', "Contract Compiled Successfully!")
          }
          if(output.contracts){
            for (var contractName in output.contracts["temp.sol"]) {
              abi = output.contracts["temp.sol"][contractName].abi;
              bytes = output.contracts["temp.sol"][contractName].evm.bytecode.object;
            }
            setContractData({
              abi: abi,
              byte_code: bytes,
            });
           
          }else{
            notify('error',"Syntax Error!");
          }

      }catch{
        setCompiling(false);
        notify('error',"Refresh your page!");
      }
      
    }else{
      notify("warn", "Enter valid contract code!")
    }
    setTimeout(() => {
      setCompiling(false);
    },1000)
  };

  const copyContData = useCallback((data:any) => {
    copyData(data);
    notify("success", "Data copied to clipboard");
  },[]);

  const keyDown = useCallback((e:any) => {
    if (e.key === 'Tab') {
      e.preventDefault()
      const start = _code.current.selectionStart
      const end = _code.current.selectionEnd
      _code.current.value = _code.current.value.substring(0, start)  + '\t'+ _code.current.value.substring(end)
      _code.current.selectionStart = _code.current.selectionEnd = start +1
    }
  },[])

  const listener =useCallback((e:any) => {
    if (e.ctrlKey && e.key === 's' ) {
      e.preventDefault();
      compileContract(contract)
    }
    keyDown(e)
  },[contract, keyDown]);

  const keyUp = useCallback((e:any) => {
    const numberOfLines = e.target.value.split('\n').length;
    _lines.current.innerHTML = Array(numberOfLines).fill('<span/>').join('')
    _code.current.style.height = _lines.current.scrollHeight + "px" ;
  },[])

  useEffect(() => {
    document.addEventListener("keydown", listener);
    document.addEventListener("keyup", keyUp);

    return () => {
      document.removeEventListener("keydown", listener);
      document.removeEventListener("keyup", keyUp);

    };
  }, [contract, listener, keyUp]);


  return (
    <div className="dapp-container">
      <div className="dapp-content">
      <h1 id="title">0xAetherFactory {'\n'}:: Deploy</h1>
          <p id="desc">
            Deploy Description {"\n"}
            Lorem Ipsum is simply dummy text of the printing and typesetting
            industry. Lorem Ipsum has been the industry's standard dummy text
            ever since the 1500s, when an unknown printer took a galley of type
            and scrambled it to make a type specimen book. It has survived not
            only five centuries,
          </p>
        <div className="deploy">
          <div className="selectors">
            <label>
              Choose Ticket :
              <select>
                <option disabled defaultValue={undefined}>
                  {" "}
                  -- select Ticket --{" "}
                </option>
                <option value={"1"}>1</option>
                <option value={"2"}>2</option>
                <option value={"3"}>3</option>
              </select>
            </label>

            <label>
              Choose Chain :
              <select>
                <option disabled defaultValue={undefined}>
                  -- select a chain --{" "}
                </option>
                <option value={"ETH"}>ETH</option>
                <option value={"BSC"}>BSC</option>
                <option value={"AVALANCHE"}>AVALANCHE</option>
              </select>
            </label>
            </div>
            <div className="compile">
              <section>
                  <div className="editor">
                      <div ref={_lines} className="line-numbers">
                          <span/>
                      </div>
                  <div className="contract">
                    <textarea ref={_code} onChange={contractCode}/>
                    </div>
                  </div>

                <div>
                  <button onClick={() => compileContract(contract)} disabled={compiling ? true : false}>Compile</button> 
                
                  {contractData?.abi && contractData.byte_code! && (
                    <>
                      <button
                        onClick={() =>
                          copyContData(
                            JSON.stringify(contractData.abi, null, '\t')
                          )
                        }
                      >
                        Copy ABI
                      </button>
                      <button
                        onClick={() =>
                          copyContData(contractData.byte_code)
                        }
                      >
                        Copy Bytecode
                      </button>
                    </>
                  )}
                </div>
              </section>
              {errorsList && (
              <label>
                LOGS
                <ul>
                  {compiling ? <SmallLoader/> : 
                     errorsList?.map((e,idx) => 
                    <li key={idx} style={{background:e.formattedMessage.includes('Warning') ? 'orange' : 'red'}}>
                        <p>code::{e.errorCode} : {e.formattedMessage}</p>
                    </li>
                  )
                }
                </ul>
                </label>
              )}

          </div>
        </div>
        <div className="action-btn">
          <button>Deploy</button>
        </div>
      </div>
    </div>
  );
};
