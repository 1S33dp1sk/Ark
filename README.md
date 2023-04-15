

running `make` will create the base for @source and the second `make` will create a virtual enviroment inside **@charms**.

## The main build
	We want to build a completely isolated virtual enviroment where the root of the env is `@charms` being the build directory. 
	The enviroment is defined by simple rules.

1. d.lbb 
	stores, distributes and requests inpar-data according to the collection path.
2. d.out
	a detection-system build, one of the objectives in this directory is to be able to execute files by referencing the build system associated with the network and thus, will not be necessary to build it on your machine, or download it, as that data will already be a memeber of the `lbb` address collection.
3. d.src
	the source code of the main functionality of ARK.
4. d.run
	essentially providing the field required for handling a certain path execution, including parameters and arguments.


## Ark

Ark is a programming language developed mostly by utilizing the C89 & C99. The primary focus of the language is to be able to design systems & control a virtual architicture fairly simply, making batch script processing and large data handling a little easier. 

Ark is most notibly known for the inpar process variables, unlike traditional type cast initialization, ark uses spc (single-process-chain) variables, which are entire process chains that can be  programmed, compilied, executed, scheduled and limited.

### Features

cool types == cool features, some are already defined :

1. program
```ark
	program(alpha, IXR&->base.py)
```
which will call **base.py** in the path *@charms:d.run*

2. variable

```ark
	string(var_name, "Hello World\n")
	pointer(ptr_name, 512)
```
3. input/output:
```ark
	out(var_name)
	__TEXT(Hello World)
``` 
*NOTE : running 2&3 will display the output `Hello World` on what is known as `out(0)` which is essentially `stdout` in c, and more generally in the Controlling Terminal.*

as script processors:
	script(@mods/script_name)



a `d_` type can be defined to customize new types,


 utilizing the ability of nesting types and function declaration, essentially the data type of any language can be added on the fly as you can apply nesting through ark calls.










