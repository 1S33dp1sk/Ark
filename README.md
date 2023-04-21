# Ark Programming Language

Discover the future of programming with Ark, a language boasting innovative syntax and powerful features.

[Get Started](./.@/)

## Key Concepts

Ark redefines programming with a unique approach, designed to tackle common challenges. Experience its groundbreaking features:

1. Distributed storage
2. Decentralized contracts
3. Shared memory
4. Concurrent execution
5. Error handling

*Ark's cutting-edge syntax makes these capabilities possible, offering developers an unparalleled tool for building efficient and reliable applications.*

### 1. Default Type Initialization

Ark initializes data types with predefined values, reducing errors and null pointer exceptions. Customize default types within the language itself, eliminating reliance on header files or compilation sequences.

#### 1.1 Variables

```ark
dPRG(
    string(foo, "HelloWorld")
)
```
Morph into a string-like component into a d_string type by passing or bypassing arguments. With a default initiation of empty memory space, this flexibility enables robust parameters like multi-format constant character sequences, functions, programs, program output, and more.
1.2 Program

```ark

dPRG(
    program(bar, IXR&->mymodule)
)
```

Morph into a program-like component using a file or file reference, initializing it with default features such as hash, name, aether-index, and entry points.
1.3 Calls

In Ark, a call is not limited to function-call. Instead, it's a way for @ to locate and run requested data until the End-Execution-Point (EXP).

```ark
dPRG(
    variable(qux, data_size=193013131)
    dprg_run(bar, foo, qux)
)
```

Morph into a variable and specify the switch point for different behaviors, between the standard null-terminated key value array, and key references array, and a result-path array, all of which are accessible via a single identifier `sterm` which dictates *Public* **-** *Temp* **-** *Private*. 

### 2. Single-Process-Chain (SPC)
Ark handles concurrency and parallelism through single-process-chains and nested execution. Multi-level calls nested on the same level are executed in parallel, while nested SPCs are executed first. Functions have a unique signature that must be called and an output signature once executed.
Arks' `dPRG` key features enables file, directories, objects and references addresses to be useful in both centralized systems to decrease the probability of SPOFs (single point of failures), And for decentralized applications and their systems, the distributions show the effective side of the network, The CDN provides the high availability required but also lessens the need for replicating databases or relying on a DHCPs.


### 3. Core of Ark's System Architecture( IXR, MOD, LBB and ATP )

- **LBBs (Linked Binary Books)** enables distributed storage initialization through the `dPRG(LBB)` function, which creates a default 1200-byte shared memory and the coressponding addresses associated with the initator and the process. 

- **IXRs (Image Execution Runners)** provides binary images for different architectures, enabling seamless integration of executables from other languages, such as Python or TypeScript.     

- **MODs (short for modifications)** mods are a pseudo-variable object, in which it can be an executable, immutable, compilable or an oridinary extensions file type that combined together with objects and libraries can be easily integrated into Ark projects. Distributed storage and allows access to variables via direct API calls from inside the program, as well as through terminal interfaces. 

- **ATP (Ark Terminal Protocol)** is a versatile feature that takes a single argument, an execution string, and evaluates it based on the  input. ATP can serve multiple purposes based on its identifiers:
  - @-Protocol, it interprets the first character command.   

  - Aether Transfer Protocol, it enables the transfer of data across different networks' interfaces including peer-to-peer and dynamic DHCP networks.         

  - Ark Terminal Protocol establishes morphism when calls are shaped by **`calls`** thus, *morphed*, into any request by processing a valid protocol name, such as `@LBB` or `@IXR`.     
  -  ATP is a poly action into a corresponding pre-defined standard protocol (e.g., HTTP(s) or Ethereum).        


### 4. Error Handling
    Ark's error handling mechanism uses exit hashes to ensure the reliability of execution threads. 

### 5. Logging
    It also provides a built-in logging feature, which supports any defined data type.

# Getting Started with Ark

To learn Ark, refer to the available documentation, which covers essential topics such as language syntax, data types, control structures, functions, modules, and error handling. Detailed examples, tutorials, and an API reference are provided to help you become proficient in using Ark.

[Current main](./.@/mods/base/main)

