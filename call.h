/**
 * calls are simple
 * they abide by the main strucutre of the ather
 * 
 * 
 * arguments filepath 
 * 
 * 1. check access
 * 2. read contents into buffer (struct) 
 * 3. parse contents
 * 
 * 
 * **PARSING**
 * * language
 * * athername
 * * contents
 * 
 */
#include <stdio.h>
#include "misc.h"

typedef struct {
    char lang_header[256];
    char ather_name[4096];
    char contents[10000];
    int validity;
} kat;














