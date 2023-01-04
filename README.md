<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a415938 (kurls)
# ather


## at *point*

## h *hbar*

## e *entry*

## r *lbb*

<<<<<<< HEAD
Let me run you through the reason, distributed systems and decentralization are very important. During the development of centralized systems such as the ones we see today, there has been massive improvments in the sectors revolving around that, with little to none in other broad areas that if explored can sum up to a more effecient process. 

Furthermore, if we consider the grand scheme of things, we can speculate that if we have an *improvment function* `I( x , theta )` that applies on a certain input **x** and that varies with time **theta** hit a "local" threshold, in normal technological terms, the amount of improvments based on the current level of technology in it's sole spectrum is not as profitable as trying to decrease **x** to `s( x_les )` where a different *improvment function* can be applied on 
=======
Let me run you through the reason, distributed systems and decentralization are very important. During the development of centralized systems such as the ones we see today, there has been massive improvments in speed and efficency due to an increase in demand from the sectors revolving around centralized applications, search engines, social media and application specific targeting such as games and data-sharing on social media. However, in light of these with little to none in other broad areas such as decentralization && distributed systems which if explored can yeild a more effecient system. 

Furthermore, if we consider the eagle view of such systems, we can speculate that if we have an *improvment function* `I( x , theta )` that applies on a certain input **x** and that varies with time **theta** hit a "local" threshold, in normal technological terms, the amount of improvments based on the current level of technology in it's sole spectrum is not as profitable as trying to decrease **x** to `s( x_les )` where a different *improvment function* can be applied on 
>>>>>>> a415938 (kurls)

`s` to yeild :: 
	`I_1( I_2( x_les , theta_les ) , theta )`


&& *profitable* here is in terms of opportinuity cost.


** insert richard hendrix quote about ants **

<<<<<<< HEAD

/**
 * each athering device MUST
 * have a singular `atherpoint`
 */
=======
### @point check
=======
# ather
>>>>>>> 4947f52 (v0.01-NS)


## at *point*

## h *hbar*

## e *entry*

## r *lbb*

Let me run you through the reason, distributed systems and decentralization are very important. During the development of centralized systems such as the ones we see today, there has been massive improvments in the sectors revolving around that, with little to none in other broad areas that if explored can sum up to a more effecient process. 

Furthermore, if we consider the grand scheme of things, we can speculate that if we have an *improvment function* `I( x , theta )` that applies on a certain input **x** and that varies with time **theta** hit a "local" threshold, in normal technological terms, the amount of improvments based on the current level of technology in it's sole spectrum is not as profitable as trying to decrease **x** to `s( x_les )` where a different *improvment function* can be applied on 

`s` to yeild :: 
	`I_1( I_2( x_les , theta_les ) , theta )`


&& *profitable* here is in terms of opportinuity cost.


** insert richard hendrix quote about ants **

<<<<<<< HEAD
>>>>>>> a6d7e67 (added README.md)
=======

/**
 * each athering device MUST
 * have a singular `atherpoint`
 */
>>>>>>> 4947f52 (v0.01-NS)
=======
# 0xather *@-Protocol*
=======
# 0xAether|0xA
>>>>>>> d133a7a (Aether)

__Welcome to 0xA, the on-chains blockchain, by AetherLabs.__


## Overview

0xAether is a blockchain messaging space that establishes a standard for IO transactional messages between different protocols. Currently, it supports all `EVM` compatible chains, such as ethereum, binance, polygon and a few more. The 0xAether enables native on-chain messaging across different chainIds, with a slightly enhanced security as the consensus is done on-chain.    

The validation is checked on the fly against each transaction. While non-technical users can enjoy and utilize the functionality of initiating transactions without the knowledge of different networks and their standards, technical users have the privilage of the dev3Suite a collection of tools and plugins to create complete and complex multi-chain & cross-chain dApps and contract-logic. Any transaction can be inititated and finalized through the aether from deployment, transfers, DeFi, game-logic and much more; Regardless of the chainid or the contract deployment state (i.e: if it has already been deployed or not).


### 0xAetherNode

Aether node is packaged to be singular or multi-instance running program, To run an AetherNode you need the following:

-.  `AetherNode` smart contract deployed by the `AetherFactory`. you can obtain one __@AetherLabs.io/nodes__ 

-.  RPC WSS urls for the supported chainIds. 
    *Note that to support any chainId your node(s), you will need an WSS endpoint URL that is able to call :    
    `eth_createFilter` && `eth_getFilterChanges`*



#### Generic Make

After cloning the remote repository, run 
```shell
make
```
in the instalation directory to initiate a generic version of Aether.


#### Configure Aether

<<<<<<< HEAD
>>>>>>> eb99d6a (0xather)
=======
Configurations for Aether is customizable to fit different needs, from testing to production to node-instance running. To define the default enviroment setup, you can run:    
```shell
aether setup
```

Nonetheless, to define any particular enviroment setup, edit the `template-env.conf` && `template-rpc.conf` located in home directory of the installation and use the _(--e) and/or (--r)_ for enviroment and rpc configuration files respectivily. Multiple configurations are possible by adjusting the configurations after creating the default ones and before adding a new node.    

```shell
aether setup --e /path/to/default/env.conf --r /path/to/default/rpc.conf
```    

The default configuration files generated can be found in _`Aether/.conf/env.conf.json`_ && _`Aether/.conf/rpc.conf.json`_.



#### Adding 0xAether|Node

To create a new generic aether node, run:

```shell
aether add
```

However, to run a real instance of the node communicating back and forth with the hub to verify transaction the node address needs to be specified by using _(--a)_ representing the actual address of the smart contract generated by the 0xAetherFactory.

```shell
aether add -a 0x00000000000000000000000000000000000
```


#### Toggling 0xAether|Node

To start a node, a toggle command is provided:

```shell
aether toggle 
```

If only a single node has been added, the aether will automatically start that node however, if multiple node(s) or configurations has been found, please specify which node name to start:

```shell
aether toggle -n NODE_NAME
```


#### Status 0xAether|Node

To query the status of the aether nodes: 

```shell
aether status
```








## Testing Aether

1.  To start 2 different EVM chains running side-by-side
    run `./aether start`

2.  Execute the deployment script on both chains
    run `./aether script -s deploy.ts`

3.  Start the node
    run  `./aether toggle`

4.  Read the variables on both chains
    run  `./aether script -s read.ts`

5.  Write to only one chain (TN1/TN4)
    run  `./aether script -s write.ts -d TN1`

6.  Read the variables again using step 4
    run `./aether script -s read.ts`
>>>>>>> d133a7a (Aether)
=======
each athering device MUST have a singular `atherpoint`.

*******************************
async-safe defined in POSIX ::

 *      _Exit(), 
 *      _exit(), 
 *      abort(), 
 *      accept(), 
 *      access(), 
 *      aio_error(), 
 *      aio_return(), 
 *      aio_suspend(), 
 *      alarm(), 
 *      bind(), 
 *      cfgetispeed(), 
 *      cfgetospeed(), 
 *      cfsetispeed(), 
 *      cfsetospeed(), 
 *      chdir(), 
 *      chmod(), 
 *      chown(), 
 *      clock_gettime(), 
 *      close(), 
 *      connect(), 
 *      creat(), 
 *      dup(), 
 *      dup2(), 
 *      execle(), 
 *      execve(), 
 *      fchmod(), 
 *      fchown(), 
 *      fcntl(), 
 *      fdatasync(), 
 *      fork(), 
 *      fpathconf(), 
 *      fstat(),
 *      fsync(), 
 *      ftruncate(), 
 *      getegid(), 
 *      geteuid(), 
 *      getgid(), 
 *      getgroups(), 
 *      getpeername(), 
 *      getpgrp(), 
 *      getpid(), 
 *      getppid(), 
 *      getsockname(), 
 *      getsockopt(), 
 *      getuid(), 
 *      kill(), 
 *      link(), 
 *      listen(), 
 *      lseek(), 
 *      lstat(), 
 *      mkdir(), 
 *      mkfifo(),
 *      open(), 
 *      pathconf(), 
 *      pause(), 
 *      pipe(), 
 *      poll(), 
 *      posix_trace_event(), 
 *      pselect(), 
 *      raise(), 
 *      read(), 
 *      readlink(), 
 *      recv(), 
 *      recvfrom(), 
 *      recvmsg(), 
 *      rename(), 
 *      rmdir(), 
 *      select(), 
 *      sem_post(), 
 *      send(), 
 *      sendmsg(), 
 *      sendto(), 
 *      setgid(), 
 *      setpgid(), 
 *      setsid(), 
 *      setsockopt(), 
 *      setuid(), 
 *      shutdown(), 
 *      sigaction(), 
 *      sigaddset(), 
 *      sigdelset(), 
 *      sigemptyset(), 
 *      sigfillset(), 
 *      sigismember(), 
 *      sleep(), 
 *      signal(), 
 *      sigpause(), 
 *      sigpending(), 
 *      sigprocmask(), 
 *      sigqueue(), 
 *      sigset(), 
 *      sigsuspend(), 
 *      sockatmark(), 
 *      socket(), 
 *      socketpair(), 
 *      stat(), 
 *      symlink(), 
 *      sysconf(), 
 *      tcdrain(), 
 *      tcflow(), 
 *      tcflush(), 
 *      tcgetattr(), 
 *      tcgetpgrp(), 
 *      tcsendbreak(), 
 *      tcsetattr(), 
 *      tcsetpgrp(), 
 *      time(), 
 *      timer_getoverrun(), 
 *      uname(), 
 *      timer_gettime(), 
 *      timer_settime(), 
 *      times(), 
 *      umask(), 
 *      unlink(), 
 *      utime(), 
 *      wait(), 
 *      waitpid(), 
 *      write()
*******************************
>>>>>>> a415938 (kurls)
