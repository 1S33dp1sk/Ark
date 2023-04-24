# \_\_ark

There are 7 different componenets that compose Ark :

    [file, hash, koder, lang, log, main, string]


Combined together, they yeild the Ark programming language. Key to understanding Ark is the initialization technique in which the program flows. Initialization of data types with predefined values, reducing errors and null pointer exceptions. Customize default types within the language itself, eliminating reliance on header files or compilation sequences.


## 1. Default Type Initialization

#### 1.1 Variables

```ark
    string(foo, "HelloWorld")
```

__Morph into__ a string-like component into a d_string type by passing or bypassing arguments. With a default initiation of empty memory space, this flexibility enables robust parameters like multi-format constant character sequences, functions, programs, program output, and more.

#### 1.2 Programs

```ark
    program(bar, IXR&->mymodule)
```

__Morph into__ a program-like component using a file or file reference, initializing it with default features such as hash, name, aether-index, and entry points.


#### 1.3 Variables
In Ark, a call is not limited to function-call. Instead, it's a way for @ to locate and run requested data until the End-Execution-Point (EXP).

```ark
    variable(qux, 193013131)
```

__Morph into__ a variable and specify the switch point for different behaviors, between the standard null-terminated key value array, and key references array, and a result-path array, all of which are accessible via a single identifier `sterm` which dictates the publication status.


## 2. Single-Process-Calls (SPC)

Ark handles concurrency and parallelism through a single process single thread chained calls which enables nested execution and thus recurssion. Multi-level calls on the same level are executed in parallel, while nested SPCs are executed first 
    
    fifo style :: first in first out
    


Any variable declared including programs, functions, structs, classes, etc... each has a unique signature and permissions are dictated by a SINGLE immutable variable, that is, a must be called variable to initate and thus output any execution result.

The switcher on permissions follows  per file from the start depending on the permissions returned from `@`.
Possible returns are :
    
    build || public || private
    


After verification, Arks' `dPRG` spwans a c-thread, which in terms of processing is, by default, a multi-level paradigm.

```ark
    dPRG(
        call(foo)
        call(bar)
        call(qux)
    )
```






