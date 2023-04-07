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

interface AccessInterface extends ethers.utils.Interface {
  functions: {
    "AETHER_FACTORY()": FunctionFragment;
    "AETHER_HUB()": FunctionFragment;
    "addAccess(address)": FunctionFragment;
    "owner()": FunctionFragment;
    "revokeAccess(address)": FunctionFragment;
    "setOwner(address)": FunctionFragment;
  };

  encodeFunctionData(
    functionFragment: "AETHER_FACTORY",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "AETHER_HUB",
    values?: undefined
  ): string;
  encodeFunctionData(functionFragment: "addAccess", values: [string]): string;
  encodeFunctionData(functionFragment: "owner", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "revokeAccess",
    values: [string]
  ): string;
  encodeFunctionData(functionFragment: "setOwner", values: [string]): string;

  decodeFunctionResult(
    functionFragment: "AETHER_FACTORY",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "AETHER_HUB", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "addAccess", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "owner", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "revokeAccess",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "setOwner", data: BytesLike): Result;

  events: {
    "AccessGranted(address,address)": EventFragment;
    "AccessRevoked(address,address)": EventFragment;
    "NodeInitialized(address,address)": EventFragment;
  };

  getEvent(nameOrSignatureOrTopic: "AccessGranted"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "AccessRevoked"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "NodeInitialized"): EventFragment;
}

export type AccessGrantedEvent = TypedEvent<
  [string, string] & { Node: string; AccessTo: string }
>;

export type AccessRevokedEvent = TypedEvent<
  [string, string] & { Node: string; AccessTo: string }
>;

export type NodeInitializedEvent = TypedEvent<
  [string, string] & { Node: string; Owner: string }
>;

export class Access extends BaseContract {
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

  interface: AccessInterface;

  functions: {
    AETHER_FACTORY(overrides?: CallOverrides): Promise<[string]>;

    AETHER_HUB(overrides?: CallOverrides): Promise<[string]>;

    addAccess(
      addr: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    owner(overrides?: CallOverrides): Promise<[string]>;

    revokeAccess(
      addr: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    setOwner(
      nodeOwner: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;
  };

  AETHER_FACTORY(overrides?: CallOverrides): Promise<string>;

  AETHER_HUB(overrides?: CallOverrides): Promise<string>;

  addAccess(
    addr: string,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  owner(overrides?: CallOverrides): Promise<string>;

  revokeAccess(
    addr: string,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  setOwner(
    nodeOwner: string,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  callStatic: {
    AETHER_FACTORY(overrides?: CallOverrides): Promise<string>;

    AETHER_HUB(overrides?: CallOverrides): Promise<string>;

    addAccess(addr: string, overrides?: CallOverrides): Promise<boolean>;

    owner(overrides?: CallOverrides): Promise<string>;

    revokeAccess(addr: string, overrides?: CallOverrides): Promise<boolean>;

    setOwner(nodeOwner: string, overrides?: CallOverrides): Promise<void>;
  };

  filters: {
    "AccessGranted(address,address)"(
      Node?: string | null,
      AccessTo?: string | null
    ): TypedEventFilter<[string, string], { Node: string; AccessTo: string }>;

    AccessGranted(
      Node?: string | null,
      AccessTo?: string | null
    ): TypedEventFilter<[string, string], { Node: string; AccessTo: string }>;

    "AccessRevoked(address,address)"(
      Node?: string | null,
      AccessTo?: string | null
    ): TypedEventFilter<[string, string], { Node: string; AccessTo: string }>;

    AccessRevoked(
      Node?: string | null,
      AccessTo?: string | null
    ): TypedEventFilter<[string, string], { Node: string; AccessTo: string }>;

    "NodeInitialized(address,address)"(
      Node?: string | null,
      Owner?: string | null
    ): TypedEventFilter<[string, string], { Node: string; Owner: string }>;

    NodeInitialized(
      Node?: string | null,
      Owner?: string | null
    ): TypedEventFilter<[string, string], { Node: string; Owner: string }>;
  };

  estimateGas: {
    AETHER_FACTORY(overrides?: CallOverrides): Promise<BigNumber>;

    AETHER_HUB(overrides?: CallOverrides): Promise<BigNumber>;

    addAccess(
      addr: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    owner(overrides?: CallOverrides): Promise<BigNumber>;

    revokeAccess(
      addr: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    setOwner(
      nodeOwner: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;
  };

  populateTransaction: {
    AETHER_FACTORY(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    AETHER_HUB(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    addAccess(
      addr: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    owner(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    revokeAccess(
      addr: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    setOwner(
      nodeOwner: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;
  };
}
