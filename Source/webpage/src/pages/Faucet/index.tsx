import { icons } from "../../assets";

export const Faucet = () => {
  return (
    <div className="faucet">
      
        <div className="box fau">
            <h2> 0xA Faucet<img src={icons.aether} alt=""/></h2>
            <div className="flex col center">
                <form className="flex center">
                    <label className="flex col center">
                        <input placeholder="0xA...."/>
                    </label>
                    <button>Request</button>
                </form>

                <h4>The requested address will receive 10 aether</h4>
                <ul>
                    <li>
                        <h3>Latest block</h3>
                        <h5>1248763</h5>
                    </li>
                    <li>
                        <h3>Limit per address</h3>
                        <h5>1248763</h5>
                    </li>
                    <li>
                        <h3>Queue</h3>
                        <h5>1248763</h5>
                    </li>
                    <li>
                        <h3>Faucet Address</h3>
                        <h5>1248763</h5>
                    </li>
                </ul>
            </div>
        </div>


    </div>
  );
};
