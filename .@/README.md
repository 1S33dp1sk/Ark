# Usage 
Ark should be initiated by running `make` which will setup the base directories and execution files, which in return provides a RVE (Runtime Virtual Enviroment).

The main output for the build consists of 2 main parts :
1. `@` **:** the corresponding *IXR(Image Execution Runner)* can be used as an executable, compilier, interpreter and header former.
2. `@charms/` **:** the main files for the requested build, with proper privilages can save, load, execute and run ark scripts and any subsequent files in lower directories that get accessed by the IXR.


# Main Build (Charms)

## 1) *d.lbb*   

	stores, distributes and requests inpar-data according to the collection path.    

## 2) *d.out*   

	A versitalie system build, detecting the operating system processor architicture.

## 3) *d.src*   

	the source code of the main functionality of ARK.    

## 4) *d.run*    

	Adds custom libraries and community contributions

Adding a library or a module is somewhat straight forward. 
As an example, lets add the following module, with the name *HelloArk*.        



Library name : `HelloArk`     

Directory(Folder) name : `mods/HelloArk`     

Entry point is the script : *start.py* which includes the sample 
```python      
if __name__ == '__main__':
	# ...
```

The script can be accessed inside a **`dPRG`** using the following snippet:      

```ark
dPRG(
	module(HelloArk, IXR&->HelloArk)
	program(HelloArk, start.py)
)
```    

then just run `make` and the new `@` will have the module `HelloArk` added on top of it.


*Note* it's important to notice that not all modules require a sample entry point for the program, However, when one is supplied a request can be done directly to the file containing the script without having to initialize it, as being done in the above example.







