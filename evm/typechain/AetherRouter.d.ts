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

interface AetherRouterInterface extends ethers.utils.Interface {
  functions: {
    "getAetherAddress(uint256)": FunctionFragment;
    "getPermittedHash(uint256)": FunctionFragment;
    "setAetherAddress(uint256,address)": FunctionFragment;
    "setPermittedHash(uint256,bytes32)": FunctionFragment;
  };

  encodeFunctionData(
    functionFragment: "getAetherAddress",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "getPermittedHash",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "setAetherAddress",
    values: [BigNumberish, string]
  ): string;
  encodeFunctionData(
    functionFragment: "setPermittedHash",
    values: [BigNumberish, BytesLike]
  ): string;

  decodeFunctionResult(
    functionFragment: "getAetherAddress",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "getPermittedHash",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "setAetherAddress",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "setPermittedHash",
    data: BytesLike
  ): Result;

  events: {};
}

export class AetherRouter extends BaseContract {
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

  interface: AetherRouterInterface;

  functions: {
    getAetherAddress(
      acId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<[string] & { AAddress: string }>;

    getPermittedHash(
      acId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<[string] & { PHash: string }>;

    setAetherAddress(
      aCID: BigNumberish,
      addr: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    setPermittedHash(
      acId: BigNumberish,
      permittedHash: BytesLike,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;
  };

  getAetherAddress(
    acId: BigNumberish,
    overrides?: CallOverrides
  ): Promise<string>;

  getPermittedHash(
    acId: BigNumberish,
    overrides?: CallOverrides
  ): Promise<string>;

  setAetherAddress(
    aCID: BigNumberish,
    addr: string,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  setPermittedHash(
    acId: BigNumberish,
    permittedHash: BytesLike,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  callStatic: {
    getAetherAddress(
      acId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<string>;

    getPermittedHash(
      acId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<string>;

    setAetherAddress(
      aCID: BigNumberish,
      addr: string,
      overrides?: CallOverrides
    ): Promise<boolean>;

    setPermittedHash(
      acId: BigNumberish,
      permittedHash: BytesLike,
      overrides?: CallOverrides
    ): Promise<void>;
  };

  filters: {};

  estimateGas: {
    getAetherAddress(
      acId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    getPermittedHash(
      acId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    setAetherAddress(
      aCID: BigNumberish,
      addr: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    setPermittedHash(
      acId: BigNumberish,
      permittedHash: BytesLike,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;
  };

  populateTransaction: {
    getAetherAddress(
      acId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    getPermittedHash(
      acId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    setAetherAddress(
      aCID: BigNumberish,
      addr: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    setPermittedHash(
      acId: BigNumberish,
      permittedHash: BytesLike,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;
  };
}