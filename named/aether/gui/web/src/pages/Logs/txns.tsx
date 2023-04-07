import { FC,  useEffect,  useState } from "react";
import { useParams } from "react-router-dom";
import { icons } from "../../assets";
import { Searchbar } from "../../components/Searchbar";
import { CONTRACTS } from "../../constants/contracts";
import { initW3Contract } from "../../utils/functions";
import { SEARCHDATA, TXNDATA } from "../../utils/types";
import Web3 from "web3";

export const Transaction:FC<any> = (props:any) => {
    const {txn_id} = useParams();

    const [searchData, setSearchData] = useState<SEARCHDATA>({address:"",filter:""});
    const [txnDetails, setTxnDetails] = useState<TXNDATA | undefined>({
        chain_ids:['',''],
        txn_from:'',
        txn_to:'',
        txn_slctr:'',
        txn_args:{}
        
    });

    // chainIDs=[], txn_from="", txn_to="", txn_slctr=bytes4, txn_args=bytes

    useEffect(() => {
        var _hash;
        if(txn_id){
            _hash = Web3.utils.isHex(txn_id);
            if(_hash){
                _hash = txn_id;      
            }else{
                _hash = Web3.utils.asciiToHex(txn_id)
            }
        }
        getTxnData(_hash);  
        
    },[txn_id])


    async function getTxnData(txn:any){
        var _cont = await initW3Contract(CONTRACTS.HUB.address, CONTRACTS.HUB.abi);
        try{
            var _txn = await _cont.methods.getATransaction(txn).call();
            console.log(_txn)
        }
        catch(err){
            console.log(err);
            setTxnDetails(undefined)
        }        
    };


    return(
        <div className="logs">
            <div className="h_log">
                <h1>
                    Transactions<span>Aether / <span>OxA</span></span>{'\n'}
                    <img src={icons.aether} alt=""/>
                </h1>
                <Searchbar searchData={searchData} setSearchData={setSearchData}/>
            </div>

            <div className="h_cont">
                <div className="boxs_cont">
                    <div className="box trans">
                        <h2>Transaction Details <img src={icons.txn} alt=""/></h2>
                        {typeof(txnDetails) !== "undefined" ? 
                        <>
                            <ul>
                                <li>
                                    <h3><img src={icons.qm} title="Transaction Hash 1" alt=""/>Transaction From:</h3>
                                    <h3>{txnDetails.txn_from}</h3>
                                </li>
                                <li>
                                    <h3><img src={icons.qm} title="Transaction Hash 2" alt=""/>Transaction To:</h3>
                                    <h3>{txnDetails.txn_to}</h3>
                                </li>
                                <li>
                                    <h3><img src={icons.qm} title="Status" alt=""/>Chains:</h3>
                                    <h3>{txnDetails.chain_ids.map((c) => c)}</h3>
                                </li>
                                <li>
                                    <h3><img src={icons.qm} title="Timestamp" alt=""/>Selector:</h3>
                                    <h3>{txnDetails.txn_slctr}</h3>
                                </li>                            
                            </ul>

                            {/* <ul>
                                <li>
                                    <h3><img src={icons.qm} title="From" alt=""/>From:</h3>
                                    <h3><span>{txnDetails.txn_from}</span></h3>
                                </li>
                                <li>
                                    <h3><img src={icons.qm} title="To" alt=""/>To:</h3>
                                    <h3><span>{txnDetails.txn_to}</span></h3>
                                </li>
                            </ul>  */}
                            
                        </>
                        :
                        <section>
                            <h2>An invalid transaction hash has been entered:{'\n'}
                                <span>{txn_id}</span>
                            </h2>
                        </section>
                        }
                    </div>
                </div>
            </div>

        </div>
    )
}