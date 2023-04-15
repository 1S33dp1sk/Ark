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
