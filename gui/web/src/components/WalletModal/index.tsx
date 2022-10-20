import React, { FC } from "react";
import { WALLET_PROVIDERS } from "../../constants";
import { connectMapper } from "../../utils/functions";

export const WalletModal:FC<any> = (props:any) => {
    

   async function connectWallet(prov_name:string) {
      
       await connectMapper(prov_name,props.active,props.activate)?.then(() => {
           props.setDisplayModal(false);
       }).catch(() => {
           props.setDisplayModal(false)
       });
    }

    return(
        <div className="modal">
            <div className="modal_bg" onClick={() => props.setDisplayModal(false)}/>
            <div className="modal_cont">
                <ul >
                    {
                        WALLET_PROVIDERS.map((p,idx) =>
                        <li key={idx} onClick={() => connectWallet(p.title)}>
                            <img src={p.logo} alt=''/>
                            <h2>{p.title}</h2>
                            <p>{p.desc}</p>
                        </li>
                    )}
                </ul>
            </div>
        </div>
    )

}