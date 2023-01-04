#include <stdio.h>
#include <string.h>
/**
 * K @ athername {					* hash @ lesaddr {
 * 		mor					-> 		*		log
 * }								* }
 */

typedef struct {
	char __key[256];
	unsigned int kommand;
	char __name[256];
	int resolved;
	char *body;
	unsigned int body_len;
} kall;

typedef struct {
	kall **ops;
	unsigned int ops_count;
	char *__raw;
	unsigned int __len;
} kommand;



unsigned int atomic( kommand *__k ) {

	int at_count = __k -> ops_count , klen = __k -> __len;

	for ( int i=0; i < klen ; i++ ) {
		if ( __k -> __raw[i] == '@' ) {
			__k -> ops_count += 1;
		}
	}


	return __k -> ops_count;
}


