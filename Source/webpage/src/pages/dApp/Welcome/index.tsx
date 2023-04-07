import { FC } from "react";
import { icons } from "../../../assets";

export const Welcome:FC = () => {
  return (
    <div className="welcome">
        <h1>
            <img src={icons.aether} alt=""/>
            DASHBOARD
        </h1>
        
        <h2>Welcome to aether dAPP{'\n'}</h2>
        <h3>Select from tabs to proceed your work</h3>
        <i><img src={icons.l_arr} alt=""/></i>
    </div>
  );
};
