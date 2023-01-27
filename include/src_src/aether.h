#ifndef AETHER
#define AETHER

/**
 * .aether -> 
 * 		PATH:=
 * 		CONNC:=
 * 		CALL:=
 * 		ENTRY { }
 */

#define PATH__NAME "PATH"
#define CONNC__NAME "CONNC"
#define CALL__NAME "CALL"
#define ENTRY__NAME "ENTRY"
#define PUBK__NAME "ADDR"
#define CONF__NAME "CONF"


const static char ATTRIBUTES[6][10] = { 
	PATH__NAME , 
	CONNC__NAME , 
	CALL__NAME , 
	ENTRY__NAME , 
	PUBK__NAME , 
	CONF__NAME
};



// Basic aether execution 
#define _AETHER_ ".aether"
#define AETHER_HOME ".aether/"
#define AETHER__NAME "Aether"
#define STRING_BUFFER 100
#define AETHER_FILE_BUFFER 1000
#define AETHER_REPLY_MAX 2000
#define ATTIBUTE_BUFFER 10
#define NULL_PTR NULL
#define HASH_LEN 33


// LOGGING
#define AETHER_ENTRY "\t\t\t->\033[38;2;66;5;240m%s\n\n\tcontents\n"
#define AETHER_THREADS_NUM "\t\033[38;2;66;5;240m->\033[0;37m%d\n"
#define AETHER_SIG "\t\t\t\033[0;37mAether\n"
#define AETHER_PATH "\n\033[38;2;66;5;240mAether\e[0;37m- %s\n"
#define AETHER_F_EXEC "\n\033[38;2;255;215;50mAether\e[0;37m> %s \033[38;2;115;115;115m//%x\n"
#define AETHER_EXEC "\n\033[38;2;255;215;50mAether\e[0;37m> %s\n"
#define AETHER_LINE "\n\033[38;2;84;84;84mAether\e[0;37m :: %s\n"
#define AETHER_ERROR "\n\033[38;2;178;34;34mAETHER\e[0;37m : %s -> %s\n"
#define AETHER_LES "\n\033[38;2;84;84;84mAether\033[0;37m : L E S -> \n"
#define AETHER_LISTEN "\n\033[38;2;84;84;84mAether\e[0;37m :: listen : .aether : %d,-> \n%s\n"
#define AETHER_EVALUATE "\n\033[38;2;84;84;84mAether\e[0;37m :: evaluate :\n\n--->\n%s\n<---\n"
#define AETHER_SEND "\n\033[38;2;84;84;84mAether\e[0;37m :: send : %d\n"

#include "types.h"
#include "helpers/helpers.h"
#include "connc/connc.h"
#include "path/path.h"
#include "entry/entry.h"
#include "call/call.h"
#include "parser/parser.h"
#include "morles/mor.h"
#include "morles/les.h"


#endif



