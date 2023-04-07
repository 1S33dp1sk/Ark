# JSON PARSER
Json Library for converting Configuration Files to Json Format

# Usage:
1. Create a json handle 
````c

json_handle json = {0};
````
2. Obtain the filename from the command line or by any other means
````c

json.filename = (char *)argv[1];
````
3. Pass in the handle to read the file
````c

json_read_conf(&json);
````
4. Call the Json Parser with the handle
````c

json_parser(&json);
````
# Complete Example
````c

#include "json_parser.h"

int main(int argc, char const *argv[])
{   
    if( !(argc > 1) ){return 0;}
    
    // 1. Create a json handle 
    json_handle json = {0};
    
    // 2. Obtain the filename from the command line
    json.filename = (char *)argv[1];
    
    // 3. Pass in the handle to read the file
    json_read_conf(&json);
    
    // 4. Call the Json Parser with the handle
    json_parser(&json);
    
    return 0;
}
````

# Configuration File
## Filename : a.conf
````jl

ex1:=20,10,12
ex2:=1
ex3:=0
ex4:=Calibration,Temperature
ex5:=120
ex6:=Upgrade
````
# Terminal compilation and Execution:
````shell

Linux@Desktop101:~$ gcc json_parser.c main.c -o env-conf
Linux@Desktop101:~$ ./env-conf a.conf
````

# Expected Output
```shell

Linux@Desktop101:~$ cat a.conf.json
```
````json

{
    "ex1" :  ["20", "10", "12"],
    "ex2" :  true,
    "ex3" :  false,
    "ex4" :  ["Calibration", "Temperature"],
    "ex5" :  120,
    "ex6" : "Upgrade"
}
````
