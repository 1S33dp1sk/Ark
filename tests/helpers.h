


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>

// #define FILENAME_EXTENSION ""
// #define FILE_SIZE_BUFFER 9000

// #undef get16bits
// #if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
//   || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
// #define get16bits(d) (*((const uint16_t *) (d)))
// #endif

// #if !defined (get16bits)
// #define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
//                        +(uint32_t)(((const uint8_t *)(d))[0]) )
// #endif

uint32_t SuperFastHash (const char * data, int len) {
    uint32_t hash = len, tmp;
    int rem;
    if (len <= 0 || data == NULL) return 0;

    rem = len & 3;
    len >>= 2;

    /* Main loop */
    for (;len > 0; len--) {
        hash  += get16bits (data);
        tmp    = (get16bits (data+2) << 11) ^ hash;
        hash   = (hash << 16) ^ tmp;
        data  += 2*sizeof (uint16_t);
        hash  += hash >> 11;
    }

    /* Handle end cases */
    switch (rem) {
        case 3: hash += get16bits (data);
                hash ^= hash << 16;
                hash ^= ((signed char)data[sizeof (uint16_t)]) << 18;
                hash += hash >> 11;
                break;
        case 2: hash += get16bits (data);
                hash ^= hash << 11;
                hash += hash >> 17;
                break;
        case 1: hash += (signed char)*data;
                hash ^= hash << 10;
                hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    return hash;
}

typedef enum
{
    READ = 1,
    CHANGE,
    DELETE,
}file_operation;

typedef struct file_tag
{
    char *filename;
    file_operation operation;
    int key_line_location;
    int file_size;
    char *key;
    char *value;
    char *data;
}file_t;

// Determine the "I/O operation" used in command line (e.g., CONFRD | CONFCHG | CONFDEL)
bool get_operation(file_t *file, char **argv, int argc);

// Determine the "Options" used in command line such as [-n or -p]
// -n : <filename> in current directory
// -p : <filepath/filename> in any directory
void get_options(file_t *file, char **argv, int argc);

// Executes the I/O operation
void IO_executor(file_t *file, char **argv);

#endif
