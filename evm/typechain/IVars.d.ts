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

interface IVarsInterface extends ethers.utils.Interface {
  functions: {
    "getLastEdit(bytes4)": FunctionFragment;
    "getVar(string)": FunctionFragment;
    "getVarName(bytes4)": FunctionFragment;
    "getVarRef(string)": FunctionFragment;
    "getVarVal(string)": FunctionFragment;
    "varExists(bytes4)": FunctionFragment;
  };

  encodeFunctionData(
    functionFragment: "getLastEdit",
    values: [BytesLike]
  ): string;
  encodeFunctionData(functionFragment: "getVar", values: [string]): string;
  encodeFunctionData(
    functionFragment: "getVarName",
    values: [BytesLike]
  ): string;
  encodeFunctionData(functionFragment: "getVarRef", values: [string]): string;
  encodeFunctionData(functionFragment: "getVarVal", values: [string]): string;
  encodeFunctionData(
    functionFragment: "varExists",
    values: [BytesLike]
  ): string;

  decodeFunctionResult(
    functionFragment: "getLastEdit",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "getVar", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "getVarName", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "getVarRef", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "getVarVal", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "varExists", data: BytesLike): Result;

  events: {
    "VariableAdded(address,string,uint256,uint256)": EventFragment;
    "VariableChange(address,bytes4,uint256)": EventFragment;
  };

  getEvent(nameOrSignatureOrTopic: "VariableAdded"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "VariableChange"): EventFragment;
}

export type VariableAddedEvent = TypedEvent<
  [string, string, BigNumber, BigNumber] & {
    AetherDAO: string;
    VariableName: string;
    VariableValue: BigNumber;
    VariableOscillation: BigNumber;
  }
>;

export type VariableChangeEvent = TypedEvent<
  [string, string, BigNumber] & {
    AetherDAO: string;
    VariableReference: string;
    VariableValue: BigNumber;
  }
>;

export class IVars extends BaseContract {
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

  interface: IVarsInterface;

  functions: {
    "getLastEdit(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<[BigNumber]>;

    "getLastEdit(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<[BigNumber]>;

    "getVar(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<[BigNumber, string, BigNumber]>;

    "getVar(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<[BigNumber, string, BigNumber]>;

    getVarName(arg0: BytesLike, overrides?: CallOverrides): Promise<[string]>;

    getVarRef(arg0: string, overrides?: CallOverrides): Promise<[string]>;

    "getVarVal(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<[BigNumber]>;

    "getVarVal(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<[BigNumber]>;

    "varExists(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<[boolean]>;

    "varExists(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<[boolean]>;
  };

  "getLastEdit(bytes4)"(
    arg0: BytesLike,
    overrides?: CallOverrides
  ): Promise<BigNumber>;

  "getLastEdit(string)"(
    arg0: string,
    overrides?: CallOverrides
  ): Promise<BigNumber>;

  "getVar(string)"(
    arg0: string,
    overrides?: CallOverrides
  ): Promise<[BigNumber, string, BigNumber]>;

  "getVar(bytes4)"(
    arg0: BytesLike,
    overrides?: CallOverrides
  ): Promise<[BigNumber, string, BigNumber]>;

  getVarName(arg0: BytesLike, overrides?: CallOverrides): Promise<string>;

  getVarRef(arg0: string, overrides?: CallOverrides): Promise<string>;

  "getVarVal(string)"(
    arg0: string,
    overrides?: CallOverrides
  ): Promise<BigNumber>;

  "getVarVal(bytes4)"(
    arg0: BytesLike,
    overrides?: CallOverrides
  ): Promise<BigNumber>;

  "varExists(bytes4)"(
    arg0: BytesLike,
    overrides?: CallOverrides
  ): Promise<boolean>;

  "varExists(string)"(
    arg0: string,
    overrides?: CallOverrides
  ): Promise<boolean>;

  callStatic: {
    "getLastEdit(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getLastEdit(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getVar(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<[BigNumber, string, BigNumber]>;

    "getVar(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<[BigNumber, string, BigNumber]>;

    getVarName(arg0: BytesLike, overrides?: CallOverrides): Promise<string>;

    getVarRef(arg0: string, overrides?: CallOverrides): Promise<string>;

    "getVarVal(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getVarVal(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "varExists(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<boolean>;

    "varExists(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<boolean>;
  };

  filters: {
    "VariableAdded(address,string,uint256,uint256)"(
      AetherDAO?: string | null,
      VariableName?: null,
      VariableValue?: null,
      VariableOscillation?: null
    ): TypedEventFilter<
      [string, string, BigNumber, BigNumber],
      {
        AetherDAO: string;
        VariableName: string;
        VariableValue: BigNumber;
        VariableOscillation: BigNumber;
      }
    >;

    VariableAdded(
      AetherDAO?: string | null,
      VariableName?: null,
      VariableValue?: null,
      VariableOscillation?: null
    ): TypedEventFilter<
      [string, string, BigNumber, BigNumber],
      {
        AetherDAO: string;
        VariableName: string;
        VariableValue: BigNumber;
        VariableOscillation: BigNumber;
      }
    >;

    "VariableChange(address,bytes4,uint256)"(
      AetherDAO?: string | null,
      VariableReference?: null,
      VariableValue?: null
    ): TypedEventFilter<
      [string, string, BigNumber],
      { AetherDAO: string; VariableReference: string; VariableValue: BigNumber }
    >;

    VariableChange(
      AetherDAO?: string | null,
      VariableReference?: null,
      VariableValue?: null
    ): TypedEventFilter<
      [string, string, BigNumber],
      { AetherDAO: string; VariableReference: string; VariableValue: BigNumber }
    >;
  };

  estimateGas: {
    "getLastEdit(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getLastEdit(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getVar(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getVar(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    getVarName(arg0: BytesLike, overrides?: CallOverrides): Promise<BigNumber>;

    getVarRef(arg0: string, overrides?: CallOverrides): Promise<BigNumber>;

    "getVarVal(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getVarVal(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "varExists(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "varExists(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;
  };

  populateTransaction: {
    "getLastEdit(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "getLastEdit(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "getVar(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "getVar(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    getVarName(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    getVarRef(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "getVarVal(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "getVarVal(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "varExists(bytes4)"(
      arg0: BytesLike,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "varExists(string)"(
      arg0: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;
  };
}