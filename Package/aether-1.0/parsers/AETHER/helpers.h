#ifndef CONFIGURATION_READER
#define CONFIGURATION_READER

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define AETHER_MAIN ".aether"
#define FILENAME_EXTENSION ""
#define FILE_SIZE_BUFFER 9000

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
