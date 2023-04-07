import { FC, useEffect, useState } from "react";
import { Link } from "react-router-dom";
import { icons } from "../../assets";
import { isNumber, notify } from "../../utils/helpers";

export const Searchbar:FC<any> = (props:any) => {

    const [route, setRoute] = useState<string>('');

    useEffect(() => {
        SearchType(props.searchData.address);
    },[props.searchData])

    function SearchType(to:string){
        if(to!){
            // if(Web3.utils.isHex(to)){
            //     setRoute(`logs/txns/${to}`)
            // }
            // else 
            if(isNumber(to)){
                setRoute(`${to}`)
            }else{
                setRoute('/logs')
            }
        };
    };

    function warningMsg(){
        if(route === '/logs'){
            notify('warn', "Enter valid hash or block number!");
        };
    };

    return(
        <div className="search">
            <select value={props.searchData.filter} onChange={(e) => props.setSearchData({...props.searchData,filter:e.target.value})}>
                <option disabled value="">All Filters</option>
                <option value={"option1"}>Option 1</option>
            </select>
            <input type={"text"} placeholder={"Search by Adress / Txn Hash / Block /Token / Ens"} onChange={(e) => props.setSearchData({...props.searchData,address:e.target.value})}/>
            <Link to={route} onClick={() => warningMsg()}> <button><img src={icons.search} alt=""/></button></Link>
        </div>
    )
}