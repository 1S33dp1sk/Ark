## Usage 
Running `make` **once** will setup the base for @source.      

Running `make` **again** will create a runtime virtual enviroment.       

 & the corresponding IXR (Image Execution Runner) dubbed `@` can be used as an executable, compilier, interpreter and header former.
 	-> grants `@` privilages to load, execute and run processes that access files through **@charms/** directory.

# Main Build
	Consisting of a *k512* base architicture & custom *mods* that can be directly integerated in the build through the IXR.


## 1.*d.lbb/*   

	stores, distributes and requests inpar-data according to the collection path.    

## 2.*d.out/*   

	A versitalie system build, detecting the operating system processor architicture.

## 3.*d.src/*   

	the source code of the main functionality of ARK.    

## 4.*d.run/*   
Adding custom libraries can be considered as an example     

Library name : `HelloArk`.     

Directory(Folder) name : `mods/HelloArk`.    

Entry point is the script : `start.py` which includes the sample `if __name__ == '__main__'`      

The script can be accessed inside a **`dPRG`** using the following snippet:      

	```ark
		program(HelloArk, IXR&->HelloArk/start.py)
		dprg_run(HelloArk)
	```      
The symbol `&->` implies the lexical equivalent of its counterpart *And Then*. 
	Now *`HelloArk`* variable can be accessed to know the author, size, content, hash, and if allowed grants the ability to execute it.       

**Providing the field address is required for handling certain path executions, including distributed snips, parameters and arguments.**



