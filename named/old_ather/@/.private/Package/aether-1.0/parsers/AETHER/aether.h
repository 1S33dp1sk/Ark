#ifndef AETHER
#define AETHER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "helpers.h"

// #define _AETHER_ ".aether"
#define _AETHER_ ".aether"
#define CONSOLE_NAME "Aether"

typedef struct {
	char *start_path;
} path;

typedef struct {
	char *node_path;
	char *aether_path;
	char *node_name;
} wrapper;

uid_t getuid(void);
uid_t geteuid(void); 
int aether_dir();

#endif