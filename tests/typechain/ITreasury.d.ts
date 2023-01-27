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

interface ITreasuryInterface extends ethers.utils.Interface {
  functions: {
    "auctionBond(uint256)": FunctionFragment;
    "bondEval()": FunctionFragment;
    "issueBond(address)": FunctionFragment;
    "maturity()": FunctionFragment;
    "swapBond(uint256)": FunctionFragment;
  };

  encodeFunctionData(
    functionFragment: "auctionBond",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(functionFragment: "bondEval", values?: undefined): string;
  encodeFunctionData(functionFragment: "issueBond", values: [string]): string;
  encodeFunctionData(functionFragment: "maturity", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "swapBond",
    values: [BigNumberish]
  ): string;

  decodeFunctionResult(
    functionFragment: "auctionBond",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "bondEval", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "issueBond", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "maturity", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "swapBond", data: BytesLike): Result;

  events: {
    "BondDefaulted(uint256,uint256,uint256,address)": EventFragment;
    "BondQueued(uint256,uint256,uint256)": EventFragment;
    "boneMade(uint256,uint256,address)": EventFragment;
  };

  getEvent(nameOrSignatureOrTopic: "BondDefaulted"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "BondQueued"): EventFragment;
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

export type boneMadeEvent = TypedEvent<
  [BigNumber, BigNumber, string] & {
    BondId: BigNumber;
    TreasuryOwnership: BigNumber;
    BondOwner: string;
  }
>;

export class ITreasury extends BaseContract {
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

  interface: ITreasuryInterface;

  functions: {
    auctionBond(
      arg0: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    bondEval(overrides?: CallOverrides): Promise<[BigNumber]>;

    issueBond(
      arg0: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    maturity(overrides?: CallOverrides): Promise<[BigNumber]>;

    swapBond(
      arg0: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;
  };

  auctionBond(
    arg0: BigNumberish,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  bondEval(overrides?: CallOverrides): Promise<BigNumber>;

  issueBond(
    arg0: string,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  maturity(overrides?: CallOverrides): Promise<BigNumber>;

  swapBond(
    arg0: BigNumberish,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  callStatic: {
    auctionBond(
      arg0: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    bondEval(overrides?: CallOverrides): Promise<BigNumber>;

    issueBond(arg0: string, overrides?: CallOverrides): Promise<BigNumber>;

    maturity(overrides?: CallOverrides): Promise<BigNumber>;

    swapBond(arg0: BigNumberish, overrides?: CallOverrides): Promise<void>;
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
    auctionBond(
      arg0: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    bondEval(overrides?: CallOverrides): Promise<BigNumber>;

    issueBond(
      arg0: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    maturity(overrides?: CallOverrides): Promise<BigNumber>;

    swapBond(
      arg0: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;
  };

  populateTransaction: {
    auctionBond(
      arg0: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    bondEval(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    issueBond(
      arg0: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    maturity(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    swapBond(
      arg0: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;
  };
}
