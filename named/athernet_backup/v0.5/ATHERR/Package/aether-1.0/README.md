# Dev3




## MOR & LES

Although the naming is convenient and easy to remember, i can assure you that it is coincidental. (:

**LES**

: **L**isten **E**valuate **S**end    

: A core blockchain-machine programming enviroment which **MOR** is built upon


**MOR**

: **M**irror **O**r **R**eply

: A proof of concept example, in the form of an application, used to convey the power of **LES**


Much like other enviroments such as REPL, LES attempts to encapsulate all and any possible desired functionality. However, unlike shells and termianls, LES requires minimal interactions and little to no maintainance, the only caveat is that all the logic needs to be defined from the get-go. Essentially, the application integrating MOR has a particular set of pre-defined triggers that it is listening to. Once a certain event is emitted, the evaluation phase will conclude to either _mirror_ that event, creating a form of a redundancy prop, decreasing future computational power usage as it will shortcut identical future triggers. Or it will _reply_ to said event based on a pre-defined set of rules.

> This can result in a recursive behavior as the reply can cause another trigger which will cause another evaluation, creating a chain reaction.



# MORServer

As a real-world example, we can utilize blockchain technology to emulate how such an enviroment can function. 

to create&start a MORS, you need to pass either a path to the configuration file, [read-config-file] or a dict that specifies the needed attributes.

simply:

`mors = MORS( __name__ , config='/path/to/config.json' )`


There are 3 key attributes required for the __MORS__ :

-	__IDENTITY__
	1.	`abis` A list of all the different ABIs for all supported contracts
	2.	`contracts` A list of all the different contract names
	3.	`addresses` A list of all the different addresses for the contracts

-	__CHAINS__
	1.	`chain_ids` A list of strings representing the chain ids
		*Please note that each entry in the `chain_ids` list needs to have it's own object in the attributes*     
	2. `...cids` chain id entry
		+ __wss__
		+ __balance__
		+ __chain_id__
		+ __chain_name__
		+ __chain_symbol__     

-	__CALLER__
	1.	`pvt_key`    
	2.	`pub_key`    





Aether initialization takes the configuration file and a few optional arguments

1.	`log_path`


2.	`exec_path`

