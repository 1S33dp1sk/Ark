# \_\_ark

Key to understanding Ark is the initialization technique in which the program flows. Initialization of data types with predefined values, reducing errors and null pointer exceptions. Customize default types within the language itself, eliminating reliance on header files or compilation sequences.

## 1. Default Type Initialization


#### 1.1 Variables

```ark
dPRG(
    string(foo, "HelloWorld")
)
```
    Morph into a string-like component into a d_string type by passing or bypassing arguments. With a default initiation of empty memory space, this flexibility enables robust parameters like multi-format constant character sequences, functions, programs, program output, and more.

#### 1.2 Programs

```ark

dPRG(
    program(bar, IXR&->mymodule)
)
```

    Morph into a program-like component using a file or file reference, initializing it with default features such as hash, name, aether-index, and entry points.


#### 1.3 Variables
In Ark, a call is not limited to function-call. Instead, it's a way for @ to locate and run requested data until the End-Execution-Point (EXP).

```ark
dPRG(
    variable(qux, data_size=193013131)
)
```

    Morph into a variable and specify the switch point for different behaviors, between the standard null-terminated key value array, and key references array, and a result-path array, all of which are accessible via a single identifier `sterm` which dictates:
    public <> private

## 2. Single-Process-Calls (SPC)

Ark handles concurrency and parallelism through a single process single thread chained calls which enables nested execution and thus recurssion. Multi-level calls on the same level are executed in parallel, while nested SPCs are executed first (fifo style : first in first out). Any variable declared including programs, functions, structs, classes, etc... each has a unique signature that must be called to output any execution signature and result.

```ark
    dPRG(
        call(foo)
        call(bar)
        call(qux)
    )
```

*Public* **-** *Temp* **-** *Private*. 

Arks' `dPRG` spwans a c-program-like processing which is by default a multi-level paradigm.
A file enables a file, a directory enables a directories, and so forth.
Objects and references result in a multi address variable enough to be both useful and secure.
A compiled file program can be done traditionally using `cc` or `gcc`, however to be useful function header exist and thus signatures as well which can be viewed with tools like `nm`

For centralized systems distributed storage and decentralized calls can decrease the probability of SPOFs (single point of failures).
As for decentralized applications and their systems, the distributed storage offers a much lower redundency than replicating entire databases.

The CDN provides the high demand scaling availability. Nonetheless, that availablity is served using the same system that serves the DHCPs, giving the ability to convert addresses quickly but since these calls is single-chained-processes, the loads are much better handled by using multiple hosts each serving instead of a single host serving the entire request batch.


