#ifndef __ANET__H
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <string.h>
	#include <sys/socket.h>
	#include <sys/types.h>
	#include <arpa/inet.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <sys/wait.h>
	#include <errno.h>

#define ATP_PORT "9999" // The common ATP port
#define ATP_INUM 10 // instances of the same id
#define ATP_SPEC_SIZE 8<<0x3
#define ATP_BUFFER_SIZE ATP_SPEC_SIZE<<0x3

// get sockaddr, IPv4 or IPv6:
void *__sok_addr(struct sockaddr *sa) {
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

struct addrinfo __hints() {
	struct addrinfo __;
	memset(&__,0,sizeof(struct addrinfo));
	__.ai_family=AF_UNSPEC;
	__.ai_socktype=SOCK_STREAM;
	#if SOK_CONNECT == 1
		__.ai_flags=AI_PASSIVE;
	#endif
	return __;
}

	#define __ANET__H 1
#endif