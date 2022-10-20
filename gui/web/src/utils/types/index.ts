export interface PROPS {
    children: React.ReactElement,
};

export type SEARCHDATA = {
    address:string
    filter:string
};

export type BLOCKDATA = {
    id:number,
    master_hash:string,
    aethering_address:string,
    txn_amount:string
}

// chainIDs=[], txn_from="", txn_to="", txn_slctr=bytes4, txn_args=bytes
export type TXNDATA = {
    chain_ids:string[] ,
    txn_from:string,
    txn_to:string,
    txn_slctr:string,
    txn_args:any
    
}

export type CHAIN = {
    id:number,
    name:string,
    symbol:string,
    features:string[],
    site:string,
    rpc:string,
    logo:string
}

export type PROPOSAL = {
    link: string
    name:string
    value:number
    expiry:number
    votes:number[]
    status:number
    resolution:number
}

// -------------


export type TOKEN = {
    title:string,
    address:string,
    img:string
}

export type COMPILEDCONTRACT = {
    abi: any[]
    byte_code: string,
}

export type COMPILINGERROR = {
    component:string
    errorCode:string
    formattedMessage:string
}