

# 0xAetherFactory


two types of aether contracts


1.	Cloning system :: Same contract handles the logic of the multi-chain call

2.	Master-Slave system :: Contracts handles the logic of a cross-chain interaction with other contracts through a pseudoproxy 




Within every contract, there is a constructor which is usually how some contracts are designed. With 0xAether, there's an extra function named `initialize` , this function is user defined, simply, the function will be called upon successful contractCreation on the blockchain. 

The flow is :

	1. constructor()
	2. initialize()


The optional initialize function is there to input any chain-specific data for usage in master-slave contracts as they are usually deployed sequentially unlike the clones contracts which are originally deployed together.


**Technical Information**

Just like the `constructor()` is used, you can utilize `initiatilze()` in all contracts, like so :

```sol
	function initialize( /* some params */ ) public {
		// more cool code
		return super.initialize();
	}

```

