#include <stdint.h>
/**
 * in order to be able to get the full 
 * nav system and build paths correctly 
 * we will utilize the `PATH` structure.
*/
typedef struct {
    char *_main;
    char *aether_path;
    char *node_path;
    char *node_name;
} PATH;

/**
 * assume everything that the .aether file
 * is claiming to be true. If no such paths
 * exist then the system cannot retireve them.
 */
typedef struct {
    char **_files;
    int num_files;
    char **_dirs;
    int num_dirs;
    uint32_t *_hashes;
    int _total;
} CONNC;

typedef struct
{
    int __depth;
    char __ctx[150];
    char *__exec;
    int exec__res;

} ENTRY;

/**
 * due to the fact that directories can also be 
 * executable, --Handle with care.
 */

typedef struct
{
    char **__seq_calls;
    int __last;
} CALL;

typedef struct
{
    CALL *__call;
    ENTRY *__entry;
    int __callable;

} CALLABLE;

/**
 * any file to be accessed needs the basic
 * structure which includes the very important
 * struc.
 */
typedef struct
{
    int _size;
    char *_name;
    char *_contents;
} a_file;


/**
 * the structure for the `.aether` file 
 * included in any path, this resolves 
 * the permissions and interactions
 * between the current execution ctx 
 * and the nxt operation.
 */
typedef struct
{
    a_file *A_FILE;
    char *A_PATH;
    char *A_CONNC;
    char *A_CALL;
    char *A_ENTRY;
} AETHER_FILE;

/**
 * main `les` instance that will be
 * communicated with from `mor` requests.
 */
typedef struct
{
    struct sockaddr_in *s_in;
    struct sockaddr_un *s_un;
    char socket_path[STRING_BUFFER];
} Les;

