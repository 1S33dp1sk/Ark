/* Autogenerated file. Do not edit manually. */
/* tslint:disable */
/* eslint-disable */

import {
  ethers,
  EventFilter,
  Signer,
  BigNumber,
  BigNumberish,
  PopulatedTransaction,
  BaseContract,
  ContractTransaction,
  Overrides,
  CallOverrides,
} from "ethers";
import { BytesLike } from "@ethersproject/bytes";
import { Listener, Provider } from "@ethersproject/providers";
import { FunctionFragment, EventFragment, Result } from "@ethersproject/abi";
import type { TypedEventFilter, TypedEvent, TypedListener } from "./common";

interface TreasuryInterface extends ethers.utils.Interface {
  functions: {
    "MAXIMUM_BONDS()": FunctionFragment;
    "_AetherBonds_()": FunctionFragment;
    "aetherBonds()": FunctionFragment;
    "aetherDAO()": FunctionFragment;
    "aetherFactory()": FunctionFragment;
    "aetherHUB()": FunctionFragment;
    "aetherID()": FunctionFragment;
    "aetherKeeper()": FunctionFragment;
    "aetherRouter()": FunctionFragment;
    "aetherToken()": FunctionFragment;
    "auctionBond(uint256)": FunctionFragment;
    "baseRatio()": FunctionFragment;
    "baseReserves()": FunctionFragment;
    "bondEval()": FunctionFragment;
    "bondsEval()": FunctionFragment;
    "buybackEval()": FunctionFragment;
    "chainAllocation()": FunctionFragment;
    "chainId()": FunctionFragment;
    "checkSV(bytes32,uint256)": FunctionFragment;
    "collaterilize(address,uint256,bytes32)": FunctionFragment;
    "depletionRatio()": FunctionFragment;
    "fullRatio()": FunctionFragment;
    "fullReserves()": FunctionFragment;
    "gasMarkup()": FunctionFragment;
    "getAetherAddress(uint256)": FunctionFragment;
    "indexEval()": FunctionFragment;
    "issueBond(address)": FunctionFragment;
    "maturity()": FunctionFragment;
    "nodesEval()": FunctionFragment;
    "nodesOfOwner(address)": FunctionFragment;
    "registeredNodes()": FunctionFragment;
    "single256Array(uint256)": FunctionFragment;
    "spwanNode()": FunctionFragment;
    "swapBond(uint256)": FunctionFragment;
    "targetRatio()": FunctionFragment;
    "totalNodes()": FunctionFragment;
    "txnClaimable(bytes32)": FunctionFragment;
  };

  encodeFunctionData(
    functionFragment: "MAXIMUM_BONDS",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "_AetherBonds_",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "aetherBonds",
    values?: undefined
  ): string;
  encodeFunctionData(functionFragment: "aetherDAO", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "aetherFactory",
    values?: undefined
  ): string;
  encodeFunctionData(functionFragment: "aetherHUB", values?: undefined): string;
  encodeFunctionData(functionFragment: "aetherID", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "aetherKeeper",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "aetherRouter",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "aetherToken",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "auctionBond",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(functionFragment: "baseRatio", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "baseReserves",
    values?: undefined
  ): string;
  encodeFunctionData(functionFragment: "bondEval", values?: undefined): string;
  encodeFunctionData(functionFragment: "bondsEval", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "buybackEval",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "chainAllocation",
    values?: undefined
  ): string;
  encodeFunctionData(functionFragment: "chainId", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "checkSV",
    values: [BytesLike, BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "collaterilize",
    values: [string, BigNumberish, BytesLike]
  ): string;
  encodeFunctionData(
    functionFragment: "depletionRatio",
    values?: undefined
  ): string;
  encodeFunctionData(functionFragment: "fullRatio", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "fullReserves",
    values?: undefined
  ): string;
  encodeFunctionData(functionFragment: "gasMarkup", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "getAetherAddress",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(functionFragment: "indexEval", values?: undefined): string;
  encodeFunctionData(functionFragment: "issueBond", values: [string]): string;
  encodeFunctionData(functionFragment: "maturity", values?: undefined): string;
  encodeFunctionData(functionFragment: "nodesEval", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "nodesOfOwner",
    values: [string]
  ): string;
  encodeFunctionData(
    functionFragment: "registeredNodes",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "single256Array",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(functionFragment: "spwanNode", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "swapBond",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "targetRatio",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "totalNodes",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "txnClaimable",
    values: [BytesLike]
  ): string;

  decodeFunctionResult(
    functionFragment: "MAXIMUM_BONDS",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "_AetherBonds_",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "aetherBonds",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "aetherDAO", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "aetherFactory",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "aetherHUB", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "aetherID", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "aetherKeeper",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "aetherRouter",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "aetherToken",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "auctionBond",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "baseRatio", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "baseReserves",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "bondEval", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "bondsEval", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "buybackEval",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "chainAllocation",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "chainId", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "checkSV", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "collaterilize",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "depletionRatio",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "fullRatio", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "fullReserves",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "gasMarkup", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "getAetherAddress",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "indexEval", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "issueBond", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "maturity", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "nodesEval", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "nodesOfOwner",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "registeredNodes",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "single256Array",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "spwanNode", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "swapBond", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "targetRatio",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "totalNodes", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "txnClaimable",
    data: BytesLike
  ): Result;

  events: {
    "BondDefaulted(uint256,uint256,uint256,address)": EventFragment;
    "BondQueued(uint256,uint256,uint256)": EventFragment;
    "MakeNode(address,address,uint256,uint256)": EventFragment;
    "NodeActualized(address,uint256,uint256)": EventFragment;
    "NodeDissolved(address,uint256,uint256,uint256,address)": EventFragment;
    "ReservesAdapted(uint256,uint256,uint256,uint256)": EventFragment;
    "TargetUpdated(uint256,uint256)": EventFragment;
    "TransactionAccepted(bytes32)": EventFragment;
    "TransactionClaimed(bytes32,uint256)": EventFragment;
    "boneMade(uint256,uint256,address)": EventFragment;
  };

  getEvent(nameOrSignatureOrTopic: "BondDefaulted"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "BondQueued"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "MakeNode"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "NodeActualized"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "NodeDissolved"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "ReservesAdapted"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "TargetUpdated"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "TransactionAccepted"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "TransactionClaimed"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "boneMade"): EventFragment;
}

export type BondDefaultedEvent = TypedEvent<
  [BigNumber, BigNumber, BigNumber, string] & {
    BondId: BigNumber;
    TreasuryOwnership: BigNumber;
    DefaultValue: BigNumber;
    BondOwner: string;
  }
>;

export type BondQueuedEvent = TypedEvent<
  [BigNumber, BigNumber, BigNumber] & {
    BondId: BigNumber;
    QueuePosition: BigNumber;
    BondValue: BigNumber;
  }
>;

export type MakeNodeEvent = TypedEvent<
  [string, string, BigNumber, BigNumber] & {
    NodeOwner: string;
    Node: string;
    NodeFIA: BigNumber;
    NodeReleaseTime: BigNumber;
  }
>;

export type NodeActualizedEvent = TypedEvent<
  [string, BigNumber, BigNumber] & {
    Node: string;
    NodeInitialStake: BigNumber;
    NodeReleaseTime: BigNumber;
  }
>;

export type NodeDissolvedEvent = TypedEvent<
  [string, BigNumber, BigNumber, BigNumber, string] & {
    Node: string;
    NodeFIA: BigNumber;
    NodeReward: BigNumber;
    NodeInitialStake: BigNumber;
    NodeOwner: string;
  }
>;

export type ReservesAdaptedEvent = TypedEvent<
  [BigNumber, BigNumber, BigNumber, BigNumber] & {
    RRatio: BigNumber;
    R0xA: BigNumber;
    RNative: BigNumber;
    RTarget: BigNumber;
  }
>;

export type TargetUpdatedEvent = TypedEvent<
  [BigNumber, BigNumber] & {
    TreasuryTarget: BigNumber;
    TargetTransactions: BigNumber;
  }
>;

export type TransactionAcceptedEvent = TypedEvent<
  [string] & { TransactionReference: string }
>;

export type TransactionClaimedEvent = TypedEvent<
  [string, BigNumber] & { TransactionReference: string; ClaimSize: BigNumber }
>;

export type boneMadeEvent = TypedEvent<
  [BigNumber, BigNumber, string] & {
    BondId: BigNumber;
    TreasuryOwnership: BigNumber;
    BondOwner: string;
  }
>;

export class Treasury extends BaseContract {
  connect(signerOrProvider: Signer | Provider | string): this;
  attach(addressOrName: string): this;
  deployed(): Promise<this>;

  listeners<EventArgsArray extends Array<any>, EventArgsObject>(
    eventFilter?: TypedEventFilter<EventArgsArray, EventArgsObject>
  ): Array<TypedListener<EventArgsArray, EventArgsObject>>;
  off<EventArgsArray extends Array<any>, EventArgsObject>(
    eventFilter: TypedEventFilter<EventArgsArray, EventArgsObject>,
    listener: TypedListener<EventArgsArray, EventArgsObject>
  ): this;
  on<EventArgsArray extends Array<any>, EventArgsObject>(
    eventFilter: TypedEventFilter<EventArgsArray, EventArgsObject>,
    listener: TypedListener<EventArgsArray, EventArgsObject>
  ): this;
  once<EventArgsArray extends Array<any>, EventArgsObject>(
    eventFilter: TypedEventFilter<EventArgsArray, EventArgsObject>,
    listener: TypedListener<EventArgsArray, EventArgsObject>
  ): this;
  removeListener<EventArgsArray extends Array<any>, EventArgsObject>(
    eventFilter: TypedEventFilter<EventArgsArray, EventArgsObject>,
    listener: TypedListener<EventArgsArray, EventArgsObject>
  ): this;
  removeAllListeners<EventArgsArray extends Array<any>, EventArgsObject>(
    eventFilter: TypedEventFilter<EventArgsArray, EventArgsObject>
  ): this;

  listeners(eventName?: string): Array<Listener>;
  off(eventName: string, listener: Listener): this;
  on(eventName: string, listener: Listener): this;
  once(eventName: string, listener: Listener): this;
  removeListener(eventName: string, listener: Listener): this;
  removeAllListeners(eventName?: string): this;

  queryFilter<EventArgsArray extends Array<any>, EventArgsObject>(
    event: TypedEventFilter<EventArgsArray, EventArgsObject>,
    fromBlockOrBlockhash?: string | number | undefined,
    toBlock?: string | number | undefined
  ): Promise<Array<TypedEvent<EventArgsArray & EventArgsObject>>>;

  interface: TreasuryInterface;

  functions: {
    MAXIMUM_BONDS(overrides?: CallOverrides): Promise<[BigNumber]>;

    _AetherBonds_(overrides?: CallOverrides): Promise<[string]>;

    aetherBonds(overrides?: CallOverrides): Promise<[string]>;

    aetherDAO(overrides?: CallOverrides): Promise<[string]>;

    aetherFactory(overrides?: CallOverrides): Promise<[string]>;

    aetherHUB(overrides?: CallOverrides): Promise<[string]>;

    aetherID(overrides?: CallOverrides): Promise<[BigNumber]>;

    aetherKeeper(overrides?: CallOverrides): Promise<[string]>;

    aetherRouter(overrides?: CallOverrides): Promise<[string]>;

    aetherToken(overrides?: CallOverrides): Promise<[string]>;

    auctionBond(
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    baseRatio(overrides?: CallOverrides): Promise<[BigNumber]>;

    baseReserves(overrides?: CallOverrides): Promise<[BigNumber, BigNumber]>;

    bondEval(overrides?: CallOverrides): Promise<[BigNumber]>;

    bondsEval(overrides?: CallOverrides): Promise<[BigNumber]>;

    buybackEval(overrides?: CallOverrides): Promise<[BigNumber]>;

    chainAllocation(overrides?: CallOverrides): Promise<[BigNumber]>;

    chainId(overrides?: CallOverrides): Promise<[BigNumber]>;

    checkSV(
      _forRef: BytesLike,
      _magicValue: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    collaterilize(
      _from: string,
      _amount: BigNumberish,
      _forRef: BytesLike,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    depletionRatio(overrides?: CallOverrides): Promise<[BigNumber, BigNumber]>;

    fullRatio(overrides?: CallOverrides): Promise<[BigNumber]>;

    fullReserves(overrides?: CallOverrides): Promise<[BigNumber, BigNumber]>;

    gasMarkup(overrides?: CallOverrides): Promise<[BigNumber]>;

    getAetherAddress(
      contractId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<[string] & { contractAddress: string }>;

    indexEval(overrides?: CallOverrides): Promise<[BigNumber]>;

    issueBond(
      _to: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    maturity(overrides?: CallOverrides): Promise<[BigNumber]>;

    nodesEval(overrides?: CallOverrides): Promise<[BigNumber]>;

    nodesOfOwner(
      node_owner: string,
      overrides?: CallOverrides
    ): Promise<[BigNumber]>;

    registeredNodes(
      overrides?: CallOverrides
    ): Promise<[string[]] & { _nodes: string[] }>;

    single256Array(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<[BigNumber[]] & { single_bondArr: BigNumber[] }>;

    spwanNode(
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    swapBond(
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    targetRatio(overrides?: CallOverrides): Promise<[BigNumber]>;

    totalNodes(overrides?: CallOverrides): Promise<[BigNumber]>;

    txnClaimable(
      aReference: BytesLike,
      overrides?: CallOverrides
    ): Promise<[boolean]>;
  };

  MAXIMUM_BONDS(overrides?: CallOverrides): Promise<BigNumber>;

  _AetherBonds_(overrides?: CallOverrides): Promise<string>;

  aetherBonds(overrides?: CallOverrides): Promise<string>;

  aetherDAO(overrides?: CallOverrides): Promise<string>;

  aetherFactory(overrides?: CallOverrides): Promise<string>;

  aetherHUB(overrides?: CallOverrides): Promise<string>;

  aetherID(overrides?: CallOverrides): Promise<BigNumber>;

  aetherKeeper(overrides?: CallOverrides): Promise<string>;

  aetherRouter(overrides?: CallOverrides): Promise<string>;

  aetherToken(overrides?: CallOverrides): Promise<string>;

  auctionBond(
    bond_id: BigNumberish,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  baseRatio(overrides?: CallOverrides): Promise<BigNumber>;

  baseReserves(overrides?: CallOverrides): Promise<[BigNumber, BigNumber]>;

  bondEval(overrides?: CallOverrides): Promise<BigNumber>;

  bondsEval(overrides?: CallOverrides): Promise<BigNumber>;

  buybackEval(overrides?: CallOverrides): Promise<BigNumber>;

  chainAllocation(overrides?: CallOverrides): Promise<BigNumber>;

  chainId(overrides?: CallOverrides): Promise<BigNumber>;

  checkSV(
    _forRef: BytesLike,
    _magicValue: BigNumberish,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  collaterilize(
    _from: string,
    _amount: BigNumberish,
    _forRef: BytesLike,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  depletionRatio(overrides?: CallOverrides): Promise<[BigNumber, BigNumber]>;

  fullRatio(overrides?: CallOverrides): Promise<BigNumber>;

  fullReserves(overrides?: CallOverrides): Promise<[BigNumber, BigNumber]>;

  gasMarkup(overrides?: CallOverrides): Promise<BigNumber>;

  getAetherAddress(
    contractId: BigNumberish,
    overrides?: CallOverrides
  ): Promise<string>;

  indexEval(overrides?: CallOverrides): Promise<BigNumber>;

  issueBond(
    _to: string,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  maturity(overrides?: CallOverrides): Promise<BigNumber>;

  nodesEval(overrides?: CallOverrides): Promise<BigNumber>;

  nodesOfOwner(
    node_owner: string,
    overrides?: CallOverrides
  ): Promise<BigNumber>;

  registeredNodes(overrides?: CallOverrides): Promise<string[]>;

  single256Array(
    bond_id: BigNumberish,
    overrides?: CallOverrides
  ): Promise<BigNumber[]>;

  spwanNode(
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  swapBond(
    bond_id: BigNumberish,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  targetRatio(overrides?: CallOverrides): Promise<BigNumber>;

  totalNodes(overrides?: CallOverrides): Promise<BigNumber>;

  txnClaimable(
    aReference: BytesLike,
    overrides?: CallOverrides
  ): Promise<boolean>;

  callStatic: {
    MAXIMUM_BONDS(overrides?: CallOverrides): Promise<BigNumber>;

    _AetherBonds_(overrides?: CallOverrides): Promise<string>;

    aetherBonds(overrides?: CallOverrides): Promise<string>;

    aetherDAO(overrides?: CallOverrides): Promise<string>;

    aetherFactory(overrides?: CallOverrides): Promise<string>;

    aetherHUB(overrides?: CallOverrides): Promise<string>;

    aetherID(overrides?: CallOverrides): Promise<BigNumber>;

    aetherKeeper(overrides?: CallOverrides): Promise<string>;

    aetherRouter(overrides?: CallOverrides): Promise<string>;

    aetherToken(overrides?: CallOverrides): Promise<string>;

    auctionBond(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    baseRatio(overrides?: CallOverrides): Promise<BigNumber>;

    baseReserves(overrides?: CallOverrides): Promise<[BigNumber, BigNumber]>;

    bondEval(overrides?: CallOverrides): Promise<BigNumber>;

    bondsEval(overrides?: CallOverrides): Promise<BigNumber>;

    buybackEval(overrides?: CallOverrides): Promise<BigNumber>;

    chainAllocation(overrides?: CallOverrides): Promise<BigNumber>;

    chainId(overrides?: CallOverrides): Promise<BigNumber>;

    checkSV(
      _forRef: BytesLike,
      _magicValue: BigNumberish,
      overrides?: CallOverrides
    ): Promise<boolean>;

    collaterilize(
      _from: string,
      _amount: BigNumberish,
      _forRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<boolean>;

    depletionRatio(overrides?: CallOverrides): Promise<[BigNumber, BigNumber]>;

    fullRatio(overrides?: CallOverrides): Promise<BigNumber>;

    fullReserves(overrides?: CallOverrides): Promise<[BigNumber, BigNumber]>;

    gasMarkup(overrides?: CallOverrides): Promise<BigNumber>;

    getAetherAddress(
      contractId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<string>;

    indexEval(overrides?: CallOverrides): Promise<BigNumber>;

    issueBond(_to: string, overrides?: CallOverrides): Promise<BigNumber>;

    maturity(overrides?: CallOverrides): Promise<BigNumber>;

    nodesEval(overrides?: CallOverrides): Promise<BigNumber>;

    nodesOfOwner(
      node_owner: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    registeredNodes(overrides?: CallOverrides): Promise<string[]>;

    single256Array(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber[]>;

    spwanNode(overrides?: CallOverrides): Promise<void>;

    swapBond(bond_id: BigNumberish, overrides?: CallOverrides): Promise<void>;

    targetRatio(overrides?: CallOverrides): Promise<BigNumber>;

    totalNodes(overrides?: CallOverrides): Promise<BigNumber>;

    txnClaimable(
      aReference: BytesLike,
      overrides?: CallOverrides
    ): Promise<boolean>;
  };

  filters: {
    "BondDefaulted(uint256,uint256,uint256,address)"(
      BondId?: null,
      TreasuryOwnership?: null,
      DefaultValue?: null,
      BondOwner?: null
    ): TypedEventFilter<
      [BigNumber, BigNumber, BigNumber, string],
      {
        BondId: BigNumber;
        TreasuryOwnership: BigNumber;
        DefaultValue: BigNumber;
        BondOwner: string;
      }
    >;

    BondDefaulted(
      BondId?: null,
      TreasuryOwnership?: null,
      DefaultValue?: null,
      BondOwner?: null
    ): TypedEventFilter<
      [BigNumber, BigNumber, BigNumber, string],
      {
        BondId: BigNumber;
        TreasuryOwnership: BigNumber;
        DefaultValue: BigNumber;
        BondOwner: string;
      }
    >;

    "BondQueued(uint256,uint256,uint256)"(
      BondId?: null,
      QueuePosition?: null,
      BondValue?: null
    ): TypedEventFilter<
      [BigNumber, BigNumber, BigNumber],
      { BondId: BigNumber; QueuePosition: BigNumber; BondValue: BigNumber }
    >;

    BondQueued(
      BondId?: null,
      QueuePosition?: null,
      BondValue?: null
    ): TypedEventFilter<
      [BigNumber, BigNumber, BigNumber],
      { BondId: BigNumber; QueuePosition: BigNumber; BondValue: BigNumber }
    >;

    "MakeNode(address,address,uint256,uint256)"(
      NodeOwner?: string | null,
      Node?: string | null,
      NodeFIA?: null,
      NodeReleaseTime?: null
    ): TypedEventFilter<
      [string, string, BigNumber, BigNumber],
      {
        NodeOwner: string;
        Node: string;
        NodeFIA: BigNumber;
        NodeReleaseTime: BigNumber;
      }
    >;

    MakeNode(
      NodeOwner?: string | null,
      Node?: string | null,
      NodeFIA?: null,
      NodeReleaseTime?: null
    ): TypedEventFilter<
      [string, string, BigNumber, BigNumber],
      {
        NodeOwner: string;
        Node: string;
        NodeFIA: BigNumber;
        NodeReleaseTime: BigNumber;
      }
    >;

    "NodeActualized(address,uint256,uint256)"(
      Node?: null,
      NodeInitialStake?: null,
      NodeReleaseTime?: null
    ): TypedEventFilter<
      [string, BigNumber, BigNumber],
      { Node: string; NodeInitialStake: BigNumber; NodeReleaseTime: BigNumber }
    >;

    NodeActualized(
      Node?: null,
      NodeInitialStake?: null,
      NodeReleaseTime?: null
    ): TypedEventFilter<
      [string, BigNumber, BigNumber],
      { Node: string; NodeInitialStake: BigNumber; NodeReleaseTime: BigNumber }
    >;

    "NodeDissolved(address,uint256,uint256,uint256,address)"(
      Node?: null,
      NodeFIA?: null,
      NodeReward?: null,
      NodeInitialStake?: null,
      NodeOwner?: null
    ): TypedEventFilter<
      [string, BigNumber, BigNumber, BigNumber, string],
      {
        Node: string;
        NodeFIA: BigNumber;
        NodeReward: BigNumber;
        NodeInitialStake: BigNumber;
        NodeOwner: string;
      }
    >;

    NodeDissolved(
      Node?: null,
      NodeFIA?: null,
      NodeReward?: null,
      NodeInitialStake?: null,
      NodeOwner?: null
    ): TypedEventFilter<
      [string, BigNumber, BigNumber, BigNumber, string],
      {
        Node: string;
        NodeFIA: BigNumber;
        NodeReward: BigNumber;
        NodeInitialStake: BigNumber;
        NodeOwner: string;
      }
    >;

    "ReservesAdapted(uint256,uint256,uint256,uint256)"(
      RRatio?: null,
      R0xA?: null,
      RNative?: null,
      RTarget?: null
    ): TypedEventFilter<
      [BigNumber, BigNumber, BigNumber, BigNumber],
      {
        RRatio: BigNumber;
        R0xA: BigNumber;
        RNative: BigNumber;
        RTarget: BigNumber;
      }
    >;

    ReservesAdapted(
      RRatio?: null,
      R0xA?: null,
      RNative?: null,
      RTarget?: null
    ): TypedEventFilter<
      [BigNumber, BigNumber, BigNumber, BigNumber],
      {
        RRatio: BigNumber;
        R0xA: BigNumber;
        RNative: BigNumber;
        RTarget: BigNumber;
      }
    >;

    "TargetUpdated(uint256,uint256)"(
      TreasuryTarget?: null,
      TargetTransactions?: null
    ): TypedEventFilter<
      [BigNumber, BigNumber],
      { TreasuryTarget: BigNumber; TargetTransactions: BigNumber }
    >;

    TargetUpdated(
      TreasuryTarget?: null,
      TargetTransactions?: null
    ): TypedEventFilter<
      [BigNumber, BigNumber],
      { TreasuryTarget: BigNumber; TargetTransactions: BigNumber }
    >;

    "TransactionAccepted(bytes32)"(
      TransactionReference?: null
    ): TypedEventFilter<[string], { TransactionReference: string }>;

    TransactionAccepted(
      TransactionReference?: null
    ): TypedEventFilter<[string], { TransactionReference: string }>;

    "TransactionClaimed(bytes32,uint256)"(
      TransactionReference?: null,
      ClaimSize?: null
    ): TypedEventFilter<
      [string, BigNumber],
      { TransactionReference: string; ClaimSize: BigNumber }
    >;

    TransactionClaimed(
      TransactionReference?: null,
      ClaimSize?: null
    ): TypedEventFilter<
      [string, BigNumber],
      { TransactionReference: string; ClaimSize: BigNumber }
    >;

    "boneMade(uint256,uint256,address)"(
      BondId?: null,
      TreasuryOwnership?: null,
      BondOwner?: null
    ): TypedEventFilter<
      [BigNumber, BigNumber, string],
      { BondId: BigNumber; TreasuryOwnership: BigNumber; BondOwner: string }
    >;

    boneMade(
      BondId?: null,
      TreasuryOwnership?: null,
      BondOwner?: null
    ): TypedEventFilter<
      [BigNumber, BigNumber, string],
      { BondId: BigNumber; TreasuryOwnership: BigNumber; BondOwner: string }
    >;
  };

  estimateGas: {
    MAXIMUM_BONDS(overrides?: CallOverrides): Promise<BigNumber>;

    _AetherBonds_(overrides?: CallOverrides): Promise<BigNumber>;

    aetherBonds(overrides?: CallOverrides): Promise<BigNumber>;

    aetherDAO(overrides?: CallOverrides): Promise<BigNumber>;

    aetherFactory(overrides?: CallOverrides): Promise<BigNumber>;

    aetherHUB(overrides?: CallOverrides): Promise<BigNumber>;

    aetherID(overrides?: CallOverrides): Promise<BigNumber>;

    aetherKeeper(overrides?: CallOverrides): Promise<BigNumber>;

    aetherRouter(overrides?: CallOverrides): Promise<BigNumber>;

    aetherToken(overrides?: CallOverrides): Promise<BigNumber>;

    auctionBond(
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    baseRatio(overrides?: CallOverrides): Promise<BigNumber>;

    baseReserves(overrides?: CallOverrides): Promise<BigNumber>;

    bondEval(overrides?: CallOverrides): Promise<BigNumber>;

    bondsEval(overrides?: CallOverrides): Promise<BigNumber>;

    buybackEval(overrides?: CallOverrides): Promise<BigNumber>;

    chainAllocation(overrides?: CallOverrides): Promise<BigNumber>;

    chainId(overrides?: CallOverrides): Promise<BigNumber>;

    checkSV(
      _forRef: BytesLike,
      _magicValue: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    collaterilize(
      _from: string,
      _amount: BigNumberish,
      _forRef: BytesLike,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    depletionRatio(overrides?: CallOverrides): Promise<BigNumber>;

    fullRatio(overrides?: CallOverrides): Promise<BigNumber>;

    fullReserves(overrides?: CallOverrides): Promise<BigNumber>;

    gasMarkup(overrides?: CallOverrides): Promise<BigNumber>;

    getAetherAddress(
      contractId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    indexEval(overrides?: CallOverrides): Promise<BigNumber>;

    issueBond(
      _to: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    maturity(overrides?: CallOverrides): Promise<BigNumber>;

    nodesEval(overrides?: CallOverrides): Promise<BigNumber>;

    nodesOfOwner(
      node_owner: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    registeredNodes(overrides?: CallOverrides): Promise<BigNumber>;

    single256Array(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    spwanNode(
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    swapBond(
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    targetRatio(overrides?: CallOverrides): Promise<BigNumber>;

    totalNodes(overrides?: CallOverrides): Promise<BigNumber>;

    txnClaimable(
      aReference: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;
  };

  populateTransaction: {
    MAXIMUM_BONDS(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    _AetherBonds_(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherBonds(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherDAO(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherFactory(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherHUB(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherID(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherKeeper(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherRouter(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherToken(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    auctionBond(
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    baseRatio(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    baseReserves(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    bondEval(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    bondsEval(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    buybackEval(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    chainAllocation(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    chainId(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    checkSV(
      _forRef: BytesLike,
      _magicValue: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    collaterilize(
      _from: string,
      _amount: BigNumberish,
      _forRef: BytesLike,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    depletionRatio(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    fullRatio(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    fullReserves(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    gasMarkup(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    getAetherAddress(
      contractId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    indexEval(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    issueBond(
      _to: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    maturity(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    nodesEval(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    nodesOfOwner(
      node_owner: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    registeredNodes(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    single256Array(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    spwanNode(
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    swapBond(
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    targetRatio(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    totalNodes(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    txnClaimable(
      aReference: BytesLike,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;
  };
}
