import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import { Providers } from "../utils/providers";
import { Faucet } from "./Faucet";
import { Guides } from "./Guides";
import { Landing } from "./Landing";
import { Logs } from "./Logs";
import { Transaction } from "./Logs/txns";

// -----------------------------------------
import { Dapp } from "./dApp";


export function Pages() {
  
  return (
    <Providers>
      <Router>
        <Routes>
          <Route path="/" element={<Landing />} />

          <Route path="/guides">
            <Route index element={<Guides />} />
            <Route path=":guide_type" element={<Guides />} />
            <Route path=":guide_type/guide_desc" element={<Guides />} />
          </Route>

          <Route path="/logs">
              <Route index element={<Logs />} />
              <Route path=":block_num" element={<Logs/>}/>
          </Route>
         
          <Route path="/logs/txns/:txn_id" element={<Transaction/>}/>
          <Route path="/faucet" element={<Faucet/>}/>

          {/* dApp Routes */}
          <Route path="/dApp" element={<Dapp/>}/>
          <Route path="/dApp/*" element={<Dapp />} />

          <Route path="*" element={<Landing />} />
        </Routes>
      </Router>
    </Providers>
  );
}

export default Pages;
