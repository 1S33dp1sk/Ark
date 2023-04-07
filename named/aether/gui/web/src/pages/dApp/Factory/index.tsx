import { FC} from "react";

export const Tickets: FC<any> = (props: any) => {
 

  return (
    <div className="dapp-container">
      <div className="dapp-content">
      <h1 id="title">0xAetherFactory {'\n'}:: Tickets</h1>
          <p id="desc">
            Tickets Description {"\n"}
            Lorem Ipsum is simply dummy text of the printing and typesetting
            industry. Lorem Ipsum has been the industry's standard dummy text
            ever since the 1500s, when an unknown printer took a galley of type
            and scrambled it to make a type specimen book. It has survived not
            only five centuries, but also the leap into electronic typesetting,
            remaining essentially unchanged. It was popularised in the 1960s
            with the release of Letraset sheets containing Lorem Ipsum passages,
            and more recently with desktop publishing software like Aldus
            PageMaker including versions of Lorem Ipsum.
          </p>
        <div className="factory">
          <div>
            <h3>
              Last Ticket ID: <span>5</span>
            </h3>
            <h3>
              Ticket Price: <span>0.5 ETH</span>
            </h3>
          </div>
        </div>
      </div>
      <div className="action-btn">
        <button>Buy</button>
      </div>
    </div>
  );
};
