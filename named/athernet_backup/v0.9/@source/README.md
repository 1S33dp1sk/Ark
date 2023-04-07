### @point check

every @point must have a FIFO in a known directory with WR permissions and accessiable


### /path check

every /path/to/file must have return true using `__sys_entry` which essentially calls `stat` from 
```c
#include <sys/stat.h>
```
and checks the user-id , group-id , etx.


### local\global.ip.address check

every **DNS** name should resolve to a *global.ip.address* and every *global.ip.address* should return the ***@point*** associated with it.


### blockchain-0xaddr check

every **blockchain address** should be resolved either by connecting to a local blockchain query or via checking the blockchain using a client. ather implementation here is to follow with the query until the end of the resolvment. So for example `ethereum` can be queried via a local *geth* client or any other, and bitcoin blockchain can query the extradata used in the transaction, as well as solana and anyother.

- mainly utilizing any type of free logging to formulate an **ather call*((*))**


