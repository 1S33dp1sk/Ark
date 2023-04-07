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

interface AetherBondsInterface extends ethers.utils.Interface {
  functions: {
    "aetherBonds()": FunctionFragment;
    "aetherDAO()": FunctionFragment;
    "aetherFactory()": FunctionFragment;
    "aetherHUB()": FunctionFragment;
    "aetherID()": FunctionFragment;
    "aetherKeeper()": FunctionFragment;
    "aetherRouter()": FunctionFragment;
    "aetherToken()": FunctionFragment;
    "approve(address,uint256)": FunctionFragment;
    "balanceOf(address)": FunctionFragment;
    "changeBaseURL(string)": FunctionFragment;
    "combineBonds(uint256[])": FunctionFragment;
    "defaultBond(address,uint256)": FunctionFragment;
    "getAetherAddress(uint256)": FunctionFragment;
    "getApproved(uint256)": FunctionFragment;
    "idsOfBond(uint256)": FunctionFragment;
    "isApprovedForAll(address,address)": FunctionFragment;
    "issueBond(address)": FunctionFragment;
    "maxSupply()": FunctionFragment;
    "name()": FunctionFragment;
    "ownerOf(uint256)": FunctionFragment;
    "safeTransferFrom(address,address,uint256)": FunctionFragment;
    "setApprovalForAll(address,bool)": FunctionFragment;
    "singular256Array(uint256)": FunctionFragment;
    "splitBonds(uint256)": FunctionFragment;
    "supportsInterface(bytes4)": FunctionFragment;
    "symbol()": FunctionFragment;
    "tokenURI(uint256)": FunctionFragment;
    "totalSupply()": FunctionFragment;
    "transferFrom(address,address,uint256)": FunctionFragment;
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
    functionFragment: "approve",
    values: [string, BigNumberish]
  ): string;
  encodeFunctionData(functionFragment: "balanceOf", values: [string]): string;
  encodeFunctionData(
    functionFragment: "changeBaseURL",
    values: [string]
  ): string;
  encodeFunctionData(
    functionFragment: "combineBonds",
    values: [BigNumberish[]]
  ): string;
  encodeFunctionData(
    functionFragment: "defaultBond",
    values: [string, BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "getAetherAddress",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "getApproved",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "idsOfBond",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "isApprovedForAll",
    values: [string, string]
  ): string;
  encodeFunctionData(functionFragment: "issueBond", values: [string]): string;
  encodeFunctionData(functionFragment: "maxSupply", values?: undefined): string;
  encodeFunctionData(functionFragment: "name", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "ownerOf",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "safeTransferFrom",
    values: [string, string, BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "setApprovalForAll",
    values: [string, boolean]
  ): string;
  encodeFunctionData(
    functionFragment: "singular256Array",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "splitBonds",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "supportsInterface",
    values: [BytesLike]
  ): string;
  encodeFunctionData(functionFragment: "symbol", values?: undefined): string;
  encodeFunctionData(
    functionFragment: "tokenURI",
    values: [BigNumberish]
  ): string;
  encodeFunctionData(
    functionFragment: "totalSupply",
    values?: undefined
  ): string;
  encodeFunctionData(
    functionFragment: "transferFrom",
    values: [string, string, BigNumberish]
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
  decodeFunctionResult(functionFragment: "approve", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "balanceOf", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "changeBaseURL",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "combineBonds",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "defaultBond",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "getAetherAddress",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "getApproved",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "idsOfBond", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "isApprovedForAll",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "issueBond", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "maxSupply", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "name", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "ownerOf", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "safeTransferFrom",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "setApprovalForAll",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "singular256Array",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "splitBonds", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "supportsInterface",
    data: BytesLike
  ): Result;
  decodeFunctionResult(functionFragment: "symbol", data: BytesLike): Result;
  decodeFunctionResult(functionFragment: "tokenURI", data: BytesLike): Result;
  decodeFunctionResult(
    functionFragment: "totalSupply",
    data: BytesLike
  ): Result;
  decodeFunctionResult(
    functionFragment: "transferFrom",
    data: BytesLike
  ): Result;

  events: {
    "Approval(address,address,uint256)": EventFragment;
    "ApprovalForAll(address,address,bool)": EventFragment;
    "BondIssued(address,uint256,uint256)": EventFragment;
    "Transfer(address,address,uint256)": EventFragment;
  };

  getEvent(nameOrSignatureOrTopic: "Approval"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "ApprovalForAll"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "BondIssued"): EventFragment;
  getEvent(nameOrSignatureOrTopic: "Transfer"): EventFragment;
}

export type ApprovalEvent = TypedEvent<
  [string, string, BigNumber] & {
    owner: string;
    approved: string;
    bond_id: BigNumber;
  }
>;

export type ApprovalForAllEvent = TypedEvent<
  [string, string, boolean] & {
    owner: string;
    operator: string;
    approved: boolean;
  }
>;

export type BondIssuedEvent = TypedEvent<
  [string, BigNumber, BigNumber] & {
    BondOwner: string;
    BondId: BigNumber;
    BondMintedAt: BigNumber;
  }
>;

export type TransferEvent = TypedEvent<
  [string, string, BigNumber] & { from: string; to: string; bond_id: BigNumber }
>;

export class AetherBonds extends BaseContract {
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

  interface: AetherBondsInterface;

  functions: {
    aetherBonds(overrides?: CallOverrides): Promise<[string]>;

    aetherDAO(overrides?: CallOverrides): Promise<[string]>;

    aetherFactory(overrides?: CallOverrides): Promise<[string]>;

    aetherHUB(overrides?: CallOverrides): Promise<[string]>;

    aetherID(overrides?: CallOverrides): Promise<[BigNumber]>;

    aetherKeeper(overrides?: CallOverrides): Promise<[string]>;

    aetherRouter(overrides?: CallOverrides): Promise<[string]>;

    aetherToken(overrides?: CallOverrides): Promise<[string]>;

    approve(
      to: string,
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    balanceOf(owner: string, overrides?: CallOverrides): Promise<[BigNumber]>;

    changeBaseURL(
      _nBaseUrl: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    combineBonds(
      bond_ids: BigNumberish[],
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    defaultBond(
      bond_owner: string,
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    getAetherAddress(
      contractId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<[string] & { contractAddress: string }>;

    getApproved(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<[string]>;

    idsOfBond(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<[BigNumber[]] & { _bondIds: BigNumber[] }>;

    isApprovedForAll(
      owner: string,
      operator: string,
      overrides?: CallOverrides
    ): Promise<[boolean]>;

    issueBond(
      to: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    maxSupply(overrides?: CallOverrides): Promise<[BigNumber]>;

    name(overrides?: CallOverrides): Promise<[string]>;

    ownerOf(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<[string]>;

    "safeTransferFrom(address,address,uint256)"(
      from: string,
      to: string,
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    "safeTransferFrom(address,address,uint256,bytes)"(
      from: string,
      to: string,
      bond_id: BigNumberish,
      _data: BytesLike,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    setApprovalForAll(
      operator: string,
      approved: boolean,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    singular256Array(
      _in: BigNumberish,
      overrides?: CallOverrides
    ): Promise<[BigNumber[]] & { _out: BigNumber[] }>;

    splitBonds(
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;

    supportsInterface(
      interfaceId: BytesLike,
      overrides?: CallOverrides
    ): Promise<[boolean]>;

    symbol(overrides?: CallOverrides): Promise<[string]>;

    tokenURI(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<[string]>;

    totalSupply(overrides?: CallOverrides): Promise<[BigNumber]>;

    transferFrom(
      from: string,
      to: string,
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<ContractTransaction>;
  };

  aetherBonds(overrides?: CallOverrides): Promise<string>;

  aetherDAO(overrides?: CallOverrides): Promise<string>;

  aetherFactory(overrides?: CallOverrides): Promise<string>;

  aetherHUB(overrides?: CallOverrides): Promise<string>;

  aetherID(overrides?: CallOverrides): Promise<BigNumber>;

  aetherKeeper(overrides?: CallOverrides): Promise<string>;

  aetherRouter(overrides?: CallOverrides): Promise<string>;

  aetherToken(overrides?: CallOverrides): Promise<string>;

  approve(
    to: string,
    bond_id: BigNumberish,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  balanceOf(owner: string, overrides?: CallOverrides): Promise<BigNumber>;

  changeBaseURL(
    _nBaseUrl: string,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  combineBonds(
    bond_ids: BigNumberish[],
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  defaultBond(
    bond_owner: string,
    bond_id: BigNumberish,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  getAetherAddress(
    contractId: BigNumberish,
    overrides?: CallOverrides
  ): Promise<string>;

  getApproved(
    bond_id: BigNumberish,
    overrides?: CallOverrides
  ): Promise<string>;

  idsOfBond(
    bond_id: BigNumberish,
    overrides?: CallOverrides
  ): Promise<BigNumber[]>;

  isApprovedForAll(
    owner: string,
    operator: string,
    overrides?: CallOverrides
  ): Promise<boolean>;

  issueBond(
    to: string,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  maxSupply(overrides?: CallOverrides): Promise<BigNumber>;

  name(overrides?: CallOverrides): Promise<string>;

  ownerOf(bond_id: BigNumberish, overrides?: CallOverrides): Promise<string>;

  "safeTransferFrom(address,address,uint256)"(
    from: string,
    to: string,
    bond_id: BigNumberish,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  "safeTransferFrom(address,address,uint256,bytes)"(
    from: string,
    to: string,
    bond_id: BigNumberish,
    _data: BytesLike,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  setApprovalForAll(
    operator: string,
    approved: boolean,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  singular256Array(
    _in: BigNumberish,
    overrides?: CallOverrides
  ): Promise<BigNumber[]>;

  splitBonds(
    bond_id: BigNumberish,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  supportsInterface(
    interfaceId: BytesLike,
    overrides?: CallOverrides
  ): Promise<boolean>;

  symbol(overrides?: CallOverrides): Promise<string>;

  tokenURI(bond_id: BigNumberish, overrides?: CallOverrides): Promise<string>;

  totalSupply(overrides?: CallOverrides): Promise<BigNumber>;

  transferFrom(
    from: string,
    to: string,
    bond_id: BigNumberish,
    overrides?: Overrides & { from?: string | Promise<string> }
  ): Promise<ContractTransaction>;

  callStatic: {
    aetherBonds(overrides?: CallOverrides): Promise<string>;

    aetherDAO(overrides?: CallOverrides): Promise<string>;

    aetherFactory(overrides?: CallOverrides): Promise<string>;

    aetherHUB(overrides?: CallOverrides): Promise<string>;

    aetherID(overrides?: CallOverrides): Promise<BigNumber>;

    aetherKeeper(overrides?: CallOverrides): Promise<string>;

    aetherRouter(overrides?: CallOverrides): Promise<string>;

    aetherToken(overrides?: CallOverrides): Promise<string>;

    approve(
      to: string,
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<void>;

    balanceOf(owner: string, overrides?: CallOverrides): Promise<BigNumber>;

    changeBaseURL(_nBaseUrl: string, overrides?: CallOverrides): Promise<void>;

    combineBonds(
      bond_ids: BigNumberish[],
      overrides?: CallOverrides
    ): Promise<boolean>;

    defaultBond(
      bond_owner: string,
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<boolean>;

    getAetherAddress(
      contractId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<string>;

    getApproved(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<string>;

    idsOfBond(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber[]>;

    isApprovedForAll(
      owner: string,
      operator: string,
      overrides?: CallOverrides
    ): Promise<boolean>;

    issueBond(to: string, overrides?: CallOverrides): Promise<BigNumber>;

    maxSupply(overrides?: CallOverrides): Promise<BigNumber>;

    name(overrides?: CallOverrides): Promise<string>;

    ownerOf(bond_id: BigNumberish, overrides?: CallOverrides): Promise<string>;

    "safeTransferFrom(address,address,uint256)"(
      from: string,
      to: string,
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<void>;

    "safeTransferFrom(address,address,uint256,bytes)"(
      from: string,
      to: string,
      bond_id: BigNumberish,
      _data: BytesLike,
      overrides?: CallOverrides
    ): Promise<void>;

    setApprovalForAll(
      operator: string,
      approved: boolean,
      overrides?: CallOverrides
    ): Promise<void>;

    singular256Array(
      _in: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber[]>;

    splitBonds(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<boolean>;

    supportsInterface(
      interfaceId: BytesLike,
      overrides?: CallOverrides
    ): Promise<boolean>;

    symbol(overrides?: CallOverrides): Promise<string>;

    tokenURI(bond_id: BigNumberish, overrides?: CallOverrides): Promise<string>;

    totalSupply(overrides?: CallOverrides): Promise<BigNumber>;

    transferFrom(
      from: string,
      to: string,
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<void>;
  };

  filters: {
    "Approval(address,address,uint256)"(
      owner?: string | null,
      approved?: string | null,
      bond_id?: BigNumberish | null
    ): TypedEventFilter<
      [string, string, BigNumber],
      { owner: string; approved: string; bond_id: BigNumber }
    >;

    Approval(
      owner?: string | null,
      approved?: string | null,
      bond_id?: BigNumberish | null
    ): TypedEventFilter<
      [string, string, BigNumber],
      { owner: string; approved: string; bond_id: BigNumber }
    >;

    "ApprovalForAll(address,address,bool)"(
      owner?: string | null,
      operator?: string | null,
      approved?: null
    ): TypedEventFilter<
      [string, string, boolean],
      { owner: string; operator: string; approved: boolean }
    >;

    ApprovalForAll(
      owner?: string | null,
      operator?: string | null,
      approved?: null
    ): TypedEventFilter<
      [string, string, boolean],
      { owner: string; operator: string; approved: boolean }
    >;

    "BondIssued(address,uint256,uint256)"(
      BondOwner?: string | null,
      BondId?: null,
      BondMintedAt?: null
    ): TypedEventFilter<
      [string, BigNumber, BigNumber],
      { BondOwner: string; BondId: BigNumber; BondMintedAt: BigNumber }
    >;

    BondIssued(
      BondOwner?: string | null,
      BondId?: null,
      BondMintedAt?: null
    ): TypedEventFilter<
      [string, BigNumber, BigNumber],
      { BondOwner: string; BondId: BigNumber; BondMintedAt: BigNumber }
    >;

    "Transfer(address,address,uint256)"(
      from?: string | null,
      to?: string | null,
      bond_id?: BigNumberish | null
    ): TypedEventFilter<
      [string, string, BigNumber],
      { from: string; to: string; bond_id: BigNumber }
    >;

    Transfer(
      from?: string | null,
      to?: string | null,
      bond_id?: BigNumberish | null
    ): TypedEventFilter<
      [string, string, BigNumber],
      { from: string; to: string; bond_id: BigNumber }
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

    approve(
      to: string,
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    balanceOf(owner: string, overrides?: CallOverrides): Promise<BigNumber>;

    changeBaseURL(
      _nBaseUrl: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    combineBonds(
      bond_ids: BigNumberish[],
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    defaultBond(
      bond_owner: string,
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    getAetherAddress(
      contractId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    getApproved(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    idsOfBond(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    isApprovedForAll(
      owner: string,
      operator: string,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    issueBond(
      to: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    maxSupply(overrides?: CallOverrides): Promise<BigNumber>;

    name(overrides?: CallOverrides): Promise<BigNumber>;

    ownerOf(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    "safeTransferFrom(address,address,uint256)"(
      from: string,
      to: string,
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    "safeTransferFrom(address,address,uint256,bytes)"(
      from: string,
      to: string,
      bond_id: BigNumberish,
      _data: BytesLike,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    setApprovalForAll(
      operator: string,
      approved: boolean,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    singular256Array(
      _in: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    splitBonds(
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<BigNumber>;

    supportsInterface(
      interfaceId: BytesLike,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    symbol(overrides?: CallOverrides): Promise<BigNumber>;

    tokenURI(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<BigNumber>;

    totalSupply(overrides?: CallOverrides): Promise<BigNumber>;

    transferFrom(
      from: string,
      to: string,
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
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

    approve(
      to: string,
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    balanceOf(
      owner: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    changeBaseURL(
      _nBaseUrl: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    combineBonds(
      bond_ids: BigNumberish[],
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    defaultBond(
      bond_owner: string,
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    getAetherAddress(
      contractId: BigNumberish,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    getApproved(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    idsOfBond(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    isApprovedForAll(
      owner: string,
      operator: string,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    issueBond(
      to: string,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    maxSupply(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    name(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    ownerOf(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    "safeTransferFrom(address,address,uint256)"(
      from: string,
      to: string,
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    "safeTransferFrom(address,address,uint256,bytes)"(
      from: string,
      to: string,
      bond_id: BigNumberish,
      _data: BytesLike,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    setApprovalForAll(
      operator: string,
      approved: boolean,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    singular256Array(
      _in: BigNumberish,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    splitBonds(
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;

    supportsInterface(
      interfaceId: BytesLike,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    symbol(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    tokenURI(
      bond_id: BigNumberish,
      overrides?: CallOverrides
    ): Promise<PopulatedTransaction>;

    totalSupply(overrides?: CallOverrides): Promise<PopulatedTransaction>;

    transferFrom(
      from: string,
      to: string,
      bond_id: BigNumberish,
      overrides?: Overrides & { from?: string | Promise<string> }
    ): Promise<PopulatedTransaction>;
  };
}
