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
  CallOverrides,
} from "ethers";
import { BytesLike } from "@ethersproject/bytes";
import { Listener, Provider } from "@ethersproject/providers";
import { FunctionFragment, EventFragment, Result } from "@ethersproject/abi";
import type { TypedEventFilter, TypedEvent, TypedListener } from "./common";

interface IAetherDAOInterface extends ethers.utils.Interface {
  functions: {
    "bondMaturityTime()": FunctionFragment;
    "depletionDivisor()": FunctionFragment;
    "depletionMultiplier()": FunctionFragment;
    "depletionRatio()": FunctionFragment;
    "gasMarkup()": FunctionFragment;
    "nodesAllocation()": FunctionFragment;
    "rewardLedger()": FunctionFragment;
    "rewardsTreasury()": FunctionFragment;
    "signersThreshold()": FunctionFragment;
    "targetGas()": FunctionFragment;
    "targetNative()": FunctionFragment;
    "targetTransactions()": FunctionFragment;
    "transactionThreshold()": FunctionFragment;
  };

  encodeFunctionData(
    functionFragment: "bondMaturityTime",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "depletionDivisor",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "depletionMultiplier",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "depletionRatio",
    values?: undefined
  ): string;
  encodeFunctionData(functionFragment: "gasMarkup", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "nodesAllocation",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "rewardLedger",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "rewardsTreasury",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "signersThreshold",
    values?: undefined
  ): string;
  encodeFunctionData(functionFragment: "targetGas", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "targetNative",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "targetTransactions",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "transactionThreshold",
    values?: undefined
  ): string;

  decodeFunctionResult(
    functionFragment: "bondMaturityTime",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "depletionDivisor",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "depletionMultiplier",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "depletionRatio",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "gasMarkup", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "nodesAllocation",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "rewardLedger",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "rewardsTreasury",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "signersThreshold",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "targetGas", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "targetNative",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "targetTransactions",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "transactionThreshold",
    data: BytesLike
  ): Result;

  events: {};
}

export class IAetherDAO extends BaseContract {
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

  interface: IAetherDAOInterface;

  functions: {
    bondMaturityTime(overrides?: CallOverrides): Promise<[BigNumber]>;

    depletionDivisor(overrides?: CallOverrides): Promise<[BigNumber]>;

    depletionMultiplier(overrides?: CallOverrides): Promise<[BigNumber]>;

    depletionRatio(overrides?: CallOverrides): Promise<[BigNumber, BigNumber]>;

    gasMarkup(overrides?: CallOverrides): Promise<[BigNumber]>;

    nodesAllocation(overrides?: CallOverrides): Promise<[BigNumber]>;

    rewardLedger(overrides?: CallOverrides): Promise<[BigNumber]>;

    rewardsTreasury(overrides?: CallOverrides): Promise<[BigNumber]>;

    signersThreshold(overrides?: CallOverrides): Promise<[BigNumber]>;

    targetGas(overrides?: CallOverrides): Promise<[BigNumber]>;

    targetNative(overrides?: CallOverrides): Promise<[BigNumber]>;

    targetTransactions(overrides?: CallOverrides): Promise<[BigNumber]>;

    transactionThreshold(overrides?: CallOverrides): Promise<[BigNumber]>;
  };

  bondMaturityTime(overrides?: CallOverrides): Promise<BigNumber>;

  depletionDivisor(overrides?: CallOverrides): Promise<BigNumber>;

  depletionMultiplier(overrides?: CallOverrides): Promise<BigNumber>;

  depletionRatio(overrides?: CallOverrides): Promise<[BigNumber, BigNumber]>;

  gasMarkup(overrides?: CallOverrides): Promise<BigNumber>;

  nodesAllocation(overrides?: CallOverrides): Promise<BigNumber>;

  rewardLedger(overrides?: CallOverrides): Promise<BigNumber>;

  rewardsTreasury(overrides?: CallOverrides): Promise<BigNumber>;

  signersThreshold(overrides?: CallOverrides): Promise<BigNumber>;

  targetGas(overrides?: CallOverrides): Promise<BigNumber>;

  targetNative(overrides?: CallOverrides): Promise<BigNumber>;

  targetTransactions(overrides?: CallOverrides): Promise<BigNumber>;

  transactionThreshold(overrides?: CallOverrides): Promise<BigNumber>;

  callStatic: {
    bondMaturityTime(overrides?: CallOverrides): Promise<BigNumber>;

    depletionDivisor(overrides?: CallOverrides): Promise<BigNumber>;

    depletionMultiplier(overrides?: CallOverrides): Promise<BigNumber>;

    depletionRatio(overrides?: CallOverrides): Promise<[BigNumber, BigNumber]>;

    gasMarkup(overrides?: CallOverrides): Promise<BigNumber>;

    nodesAllocation(overrides?: CallOverrides): Promise<BigNumber>;

    rewardLedger(overrides?: CallOverrides): Promise<BigNumber>;

    rewardsTreasury(overrides?: CallOverrides): Promise<BigNumber>;

    signersThreshold(overrides?: CallOverrides): Promise<BigNumber>;

    targetGas(overrides?: CallOverrides): Promise<BigNumber>;

    targetNative(overrides?: CallOverrides): Promise<BigNumber>;

    targetTransactions(overrides?: CallOverrides): Promise<BigNumber>;

    transactionThreshold(overrides?: CallOverrides): Promise<BigNumber>;
  };

  filters: {};

  estimateGas: {
    bondMaturityTime(overrides?: CallOverrides): Promise<BigNumber>;

    depletionDivisor(overrides?: CallOverrides): Promise<BigNumber>;

    depletionMultiplier(overrides?: CallOverrides): Promise<BigNumber>;

    depletionRatio(overrides?: CallOverrides): Promise<BigNumber>;

    gasMarkup(overrides?: CallOverrides): Promise<BigNumber>;

    nodesAllocation(overrides?: CallOverrides): Promise<BigNumber>;

    rewardLedger(overrides?: CallOverrides): Promise<BigNumber>;

    rewardsTreasury(overrides?: CallOverrides): Promise<BigNumber>;

    signersThreshold(overrides?: CallOverrides): Promise<BigNumber>;

    targetGas(overrides?: CallOverrides): Promise<BigNumber>;

    targetNative(overrides?: CallOverrides): Promise<BigNumber>;

    targetTransactions(overrides?: CallOverrides): Promise<BigNumber>;

    transactionThreshold(overrides?: CallOverrides): Promise<BigNumber>;
  };

  populateTransaction: {
    bondMaturityTime(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    depletionDivisor(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    depletionMultiplier(
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    depletionRatio(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    gasMarkup(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    nodesAllocation(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    rewardLedger(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    rewardsTreasury(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    signersThreshold(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    targetGas(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    targetNative(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    targetTransactions(
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    transactionThreshold(
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;
  };
}