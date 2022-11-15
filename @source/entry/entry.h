#include <stdio.h>
#include <string.h>


#define MAX_KEY 512
#define eptr unsigned char *

struct _e_header {
	unsigned _level;
	char **requ;
	char **vals;
	unsigned rv_count;
};



eptr encode_header( struct _e_header entry_head ) {
	


}
