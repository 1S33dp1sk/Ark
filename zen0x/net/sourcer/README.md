# Conf I/O
* ### A library to manipulate Configuration files with the following command line arguments.

## Supported Commands:
* `CONFRD`  (Read key:=values)
* `CONFCHG` (Change key:=values)
* `CONFDEL` (Delete key:=values)

# Usage:

1. Specify the name of the default file, if it should be different.
````c

#define DEFAULT_FILENAME "default.conf"
#define FILENAME_EXTENSION ".conf"
````
2. Create a File Handle
````c

file_t file = {0};
````
3. Determine the "I/O operation" used in the command line. Returns '0' if not successful.
````c

get_operation(&file, argv, argc);
````
4. Determine the "Options" used in the command line such as [-n or -p]
* -n  "filename" (e.g., conf_1) 
* -p  "filepath/filename" (e.g., /home/Linux/Desktop/conf_2)
````c

get_options(&file, argv, argc);
````
5. Finally, Execute the I/O operation
````c

IO_executor(&file, argv);
````

# Complete Example 1
````c

#include "config_reader.h

int main(int argc, char **argv)
{
    if(!(argc >= 3)){return 0;}}

    // 2. Create a File Handle
    file_t file = {0};
    
    // 3. Determine the "I/O operation" used in the command line. Returns '0' if not successful.
    if(!get_operation(&file, argv, argc)){return 0;}

    // 4. Determine the "Options" used in the command line such as [-n or -p]
    get_options(&file, argv, argc);

    // 5. Finally, Execute the I/O operation
    IO_executor(&file, argv);

    return 0;
}

````
# Configuration File
## Filename : default.conf (Inside Current Working Directory)
````jl

ex1:=20,10,12
ex2:=1
ex3:=0
ex4:=Calibration,Temperature
ex5:=120
ex6:=Upgrade
````
# Terminal compilation
````shell

Linux@Desktop101:~$ gcc config_reader.c main.c -o reader

````
## e.g.1. Read Operation (default file)
````shell

Linux@Desktop101:~$ ./reader CONFRD ex1
20,10,12
Linux@Desktop101:~$
````
## e.g.2. Change & Read Operation (default file)
````shell

Linux@Desktop101:~$ ./reader CONFCHG ex4 "Optimize, Humidity"
Linux@Desktop101:~$ ./reader CONFRD ex4
Optimize, Humidity
Linux@Desktop101:~$
````
## e.g.3. Delete & Read Operation (default file)
````shell

Linux@Desktop101:~$ ./reader CONFDEL ex5
Linux@Desktop101:~$ ./reader CONFRD ex5
"NE"
Linux@Desktop101:~$
````
# Example Usage using (-n or -p ):

## Location of file I want to operate on : /home/Linux/Desktop/conf_1.conf
````jl

ex1:=50
ex4:=Calibration,Temperature
ex5:=120
ex6:=Upgrade
````
# Terminal
````shell

Linux@Desktop101:~/Desktop/Test$ pwd
/home/Linux/Desktop/Test
Linux@Desktop101:~/Desktop/Test$
````

## e.g.1. Read Operation ( Option: -p filepath/filename )
````shell

Linux@Desktop101:~/Desktop/Test$ ./reader CONFRD ex1 -p ../conf_1
50
Linux@Desktop101:~/Desktop/Test$
````

## e.g.2. Read Operation ( Option: -n filename)
````shell

Linux@Desktop101:~/Desktop/Test$ cd .. 
Linux@Desktop101:~/Desktop$ ./reader CONFRD ex2 -n conf_1
Calibration,Temperature
Linux@Desktop101:~/Desktop/Test$
````
