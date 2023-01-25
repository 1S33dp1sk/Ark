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

interface DAOMembershipsInterface extends ethers.utils.Interface {
  functions: {
    "aetherBonds()": FunctionFragment;
    "aetherDAO()": FunctionFragment;
    "aetherFactory()": FunctionFragment;
    "aetherHUB()": FunctionFragment;
    "aetherID()": FunctionFragment;
    "aetherKeeper()": FunctionFragment;
    "aetherRouter()": FunctionFragment;
    "aetherToken()": FunctionFragment;
    "getAetherAddress(uint256)": FunctionFragment;
    "getLastEdit(bytes4)": FunctionFragment;
    "getVar(string)": FunctionFragment;
    "getVarName(bytes4)": FunctionFragment;
    "getVarRef(string)": FunctionFragment;
    "getVarVal(string)": FunctionFragment;
    "holderThreshold()": FunctionFragment;
    "isDAOMember(address)": FunctionFragment;
    "isDAOPartner(address)": FunctionFragment;
    "isHolder(address)": FunctionFragment;
    "isNodeOwner(address)": FunctionFragment;
    "isTreasuryPartner(address)": FunctionFragment;
    "membershipFor(address,uint8)": FunctionFragment;
    "nodeThreshold()": FunctionFragment;
    "treasuryThreshold()": FunctionFragment;
    "varExists(bytes4)": FunctionFragment;
  };

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
    functionFragment: "getAetherAddress",
    values: [BigNumberish]
  ): string;
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
    functionFragment: "holderThreshold",
    values?: undefined
  ): string;
  encodeFunctionData(functionFragment: "isDAOMember", values: [string]): string;
  encodeFunctionData(
    functionFragment: "isDAOPartner",
    values: [string]
  ): string;
  encodeFunctionData(functionFragment: "isHolder", values: [string]): string;
  encodeFunctionData(functionFragment: "isNodeOwner", values: [string]): string;
  encodeFunctionData(
    functionFragment: "isTreasuryPartner",
    values: [string]
  ): string;
  encodeFunctionData(
    functionFragment: "membershipFor",
    values: [string, BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "nodeThreshold",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "treasuryThreshold",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "varExists",
    values: [BytesLike]
  ): string;

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
    functionFragment: "getAetherAddress",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "getLastEdit",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "getVar", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "getVarName", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "getVarRef", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "getVarVal", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "holderThreshold",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "isDAOMember",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "isDAOPartner",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "isHolder", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "isNodeOwner",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "isTreasuryPartner",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "membershipFor",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "nodeThreshold",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "treasuryThreshold",
    data: BytesLike
  ): Result;
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

export class DAOMemberships extends BaseContract {
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

  interface: DAOMembershipsInterface;

  functions: {
    aetherBonds(overrides?: CallOverrides): Promise<[string]>;

    aetherDAO(overrides?: CallOverrides): Promise<[string]>;

    aetherFactory(overrides?: CallOverrides): Promise<[string]>;

    aetherHUB(overrides?: CallOverrides): Promise<[string]>;

    aetherID(overrides?: CallOverrides): Promise<[BigNumber]>;

    aetherKeeper(overrides?: CallOverrides): Promise<[string]>;

    aetherRouter(overrides?: CallOverrides): Promise<[string]>;

    aetherToken(overrides?: CallOverrides): Promise<[string]>;

    getAetherAddress(
      contractId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<[string] & { contractAddress: string }>;

    "getLastEdit(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<[BigNumber]>;

    "getLastEdit(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<[BigNumber]>;

    "getVar(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<
      [BigNumber, string, BigNumber] & {
        variableValue: BigNumber;
        variableName: string;
        variableOsc: BigNumber;
      }
    >;

    "getVar(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<
      [BigNumber, string, BigNumber] & {
        variableValue: BigNumber;
        variableName: string;
        variableOsc: BigNumber;
      }
    >;

    getVarName(varRef: BytesLike, overrides?: CallOverrides): Promise<[string]>;

    getVarRef(varName: string, overrides?: CallOverrides): Promise<[string]>;

    "getVarVal(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<[BigNumber]>;

    "getVarVal(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<[BigNumber]>;

    holderThreshold(overrides?: CallOverrides): Promise<[BigNumber]>;

    isDAOMember(_addr: string, overrides?: CallOverrides): Promise<[boolean]>;

    isDAOPartner(_addr: string, overrides?: CallOverrides): Promise<[boolean]>;

    isHolder(_addr: string, overrides?: CallOverrides): Promise<[boolean]>;

    isNodeOwner(_addr: string, overrides?: CallOverrides): Promise<[boolean]>;

    isTreasuryPartner(
      _addr: string,
      overrides?: CallOverrides
    ): Promise<[boolean]>;

    membershipFor(
      _addr: string,
      _membership: BigNumberish,
      overrides?: CallOverrides
    ): Promise<[boolean]>;

    nodeThreshold(overrides?: CallOverrides): Promise<[BigNumber]>;

    treasuryThreshold(overrides?: CallOverrides): Promise<[BigNumber]>;

    "varExists(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<[boolean]>;

    "varExists(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<[boolean]>;
  };

  aetherBonds(overrides?: CallOverrides): Promise<string>;

  aetherDAO(overrides?: CallOverrides): Promise<string>;

  aetherFactory(overrides?: CallOverrides): Promise<string>;

  aetherHUB(overrides?: CallOverrides): Promise<string>;

  aetherID(overrides?: CallOverrides): Promise<BigNumber>;

  aetherKeeper(overrides?: CallOverrides): Promise<string>;

  aetherRouter(overrides?: CallOverrides): Promise<string>;

  aetherToken(overrides?: CallOverrides): Promise<string>;

  getAetherAddress(
    contractId: BigNumberish,
    overrides?: CallOverrides
  ): Promise<string>;

  "getLastEdit(bytes4)"(
    varRef: BytesLike,
    overrides?: CallOverrides
  ): Promise<BigNumber>;

  "getLastEdit(string)"(
    varName: string,
    overrides?: CallOverrides
  ): Promise<BigNumber>;

  "getVar(string)"(
    varName: string,
    overrides?: CallOverrides
  ): Promise<
    [BigNumber, string, BigNumber] & {
      variableValue: BigNumber;
      variableName: string;
      variableOsc: BigNumber;
    }
  >;

  "getVar(bytes4)"(
    varRef: BytesLike,
    overrides?: CallOverrides
  ): Promise<
    [BigNumber, string, BigNumber] & {
      variableValue: BigNumber;
      variableName: string;
      variableOsc: BigNumber;
    }
  >;

  getVarName(varRef: BytesLike, overrides?: CallOverrides): Promise<string>;

  getVarRef(varName: string, overrides?: CallOverrides): Promise<string>;

  "getVarVal(string)"(
    varName: string,
    overrides?: CallOverrides
  ): Promise<BigNumber>;

  "getVarVal(bytes4)"(
    varRef: BytesLike,
    overrides?: CallOverrides
  ): Promise<BigNumber>;

  holderThreshold(overrides?: CallOverrides): Promise<BigNumber>;

  isDAOMember(_addr: string, overrides?: CallOverrides): Promise<boolean>;

  isDAOPartner(_addr: string, overrides?: CallOverrides): Promise<boolean>;

  isHolder(_addr: string, overrides?: CallOverrides): Promise<boolean>;

  isNodeOwner(_addr: string, overrides?: CallOverrides): Promise<boolean>;

  isTreasuryPartner(_addr: string, overrides?: CallOverrides): Promise<boolean>;

  membershipFor(
    _addr: string,
    _membership: BigNumberish,
    overrides?: CallOverrides
  ): Promise<boolean>;

  nodeThreshold(overrides?: CallOverrides): Promise<BigNumber>;

  treasuryThreshold(overrides?: CallOverrides): Promise<BigNumber>;

  "varExists(bytes4)"(
    varRef: BytesLike,
    overrides?: CallOverrides
  ): Promise<boolean>;

  "varExists(string)"(
    varName: string,
    overrides?: CallOverrides
  ): Promise<boolean>;

  callStatic: {
    aetherBonds(overrides?: CallOverrides): Promise<string>;

    aetherDAO(overrides?: CallOverrides): Promise<string>;

    aetherFactory(overrides?: CallOverrides): Promise<string>;

    aetherHUB(overrides?: CallOverrides): Promise<string>;

    aetherID(overrides?: CallOverrides): Promise<BigNumber>;

    aetherKeeper(overrides?: CallOverrides): Promise<string>;

    aetherRouter(overrides?: CallOverrides): Promise<string>;

    aetherToken(overrides?: CallOverrides): Promise<string>;

    getAetherAddress(
      contractId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<string>;

    "getLastEdit(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getLastEdit(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getVar(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<
      [BigNumber, string, BigNumber] & {
        variableValue: BigNumber;
        variableName: string;
        variableOsc: BigNumber;
      }
    >;

    "getVar(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<
      [BigNumber, string, BigNumber] & {
        variableValue: BigNumber;
        variableName: string;
        variableOsc: BigNumber;
      }
    >;

    getVarName(varRef: BytesLike, overrides?: CallOverrides): Promise<string>;

    getVarRef(varName: string, overrides?: CallOverrides): Promise<string>;

    "getVarVal(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getVarVal(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    holderThreshold(overrides?: CallOverrides): Promise<BigNumber>;

    isDAOMember(_addr: string, overrides?: CallOverrides): Promise<boolean>;

    isDAOPartner(_addr: string, overrides?: CallOverrides): Promise<boolean>;

    isHolder(_addr: string, overrides?: CallOverrides): Promise<boolean>;

    isNodeOwner(_addr: string, overrides?: CallOverrides): Promise<boolean>;

    isTreasuryPartner(
      _addr: string,
      overrides?: CallOverrides
    ): Promise<boolean>;

    membershipFor(
      _addr: string,
      _membership: BigNumberish,
      overrides?: CallOverrides
    ): Promise<boolean>;

    nodeThreshold(overrides?: CallOverrides): Promise<BigNumber>;

    treasuryThreshold(overrides?: CallOverrides): Promise<BigNumber>;

    "varExists(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<boolean>;

    "varExists(string)"(
      varName: string,
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
    aetherBonds(overrides?: CallOverrides): Promise<BigNumber>;

    aetherDAO(overrides?: CallOverrides): Promise<BigNumber>;

    aetherFactory(overrides?: CallOverrides): Promise<BigNumber>;

    aetherHUB(overrides?: CallOverrides): Promise<BigNumber>;

    aetherID(overrides?: CallOverrides): Promise<BigNumber>;

    aetherKeeper(overrides?: CallOverrides): Promise<BigNumber>;

    aetherRouter(overrides?: CallOverrides): Promise<BigNumber>;

    aetherToken(overrides?: CallOverrides): Promise<BigNumber>;

    getAetherAddress(
      contractId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getLastEdit(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getLastEdit(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getVar(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getVar(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    getVarName(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    getVarRef(varName: string, overrides?: CallOverrides): Promise<BigNumber>;

    "getVarVal(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "getVarVal(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    holderThreshold(overrides?: CallOverrides): Promise<BigNumber>;

    isDAOMember(_addr: string, overrides?: CallOverrides): Promise<BigNumber>;

    isDAOPartner(_addr: string, overrides?: CallOverrides): Promise<BigNumber>;

    isHolder(_addr: string, overrides?: CallOverrides): Promise<BigNumber>;

    isNodeOwner(_addr: string, overrides?: CallOverrides): Promise<BigNumber>;

    isTreasuryPartner(
      _addr: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    membershipFor(
      _addr: string,
      _membership: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    nodeThreshold(overrides?: CallOverrides): Promise<BigNumber>;

    treasuryThreshold(overrides?: CallOverrides): Promise<BigNumber>;

    "varExists(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "varExists(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;
  };

  populateTransaction: {
    aetherBonds(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherDAO(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherFactory(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherHUB(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherID(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherKeeper(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherRouter(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    aetherToken(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    getAetherAddress(
      contractId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "getLastEdit(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "getLastEdit(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "getVar(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "getVar(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    getVarName(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    getVarRef(
      varName: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "getVarVal(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "getVarVal(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    holderThreshold(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    isDAOMember(
      _addr: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    isDAOPartner(
      _addr: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    isHolder(
      _addr: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    isNodeOwner(
      _addr: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    isTreasuryPartner(
      _addr: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    membershipFor(
      _addr: string,
      _membership: BigNumberish,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    nodeThreshold(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    treasuryThreshold(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    "varExists(bytes4)"(
      varRef: BytesLike,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "varExists(string)"(
      varName: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;
  };
}
