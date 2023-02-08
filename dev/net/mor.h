

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>


#define APOINT_PORT "9999"
#define APOINT_BACKLOG 10

#define __sockaddr struct sockaddr
#define __sockaddrin struct sockaddr_in
#define __sockaddrin6 struct sockaddr_in6

void *__get_addr(__sockaddr *sockaddr){
    if(sockaddr->sa_family==AF_INET){
        return &(((__sockaddrin*)sockaddr)->sin_addr);
    }
    return &(((__sockaddrin6*)sockaddr)->sin6_addr);
}


int mor() {
    int __fd, temp_fd, __yes=1, __rv;
    struct addrinfo __hints, *__servinfo, *temp;
    struct sockaddr_storage __caddr;
    memset(&__hints,0,sizeof(struct addrinfo));
    __hints.ai_family=AF_UNSPEC;
    __hints.ai_socktype=SOCK_STREAM;
    __hints.ai_flags=AI_PASSIVE;
    socklen_t __sin_size;
    char __saddr[INET6_ADDRSTRLEN];

    if ((__rv=getaddrinfo(NULL,APOINT_PORT,&__hints,&__servinfo))!=0){
        fprintf(stderr,"getaddrinfo :: %s\n",gai_strerror(__rv));
        return 1;
    }

    for(temp=__servinfo;temp!=NULL;temp=temp->ai_next){
        if((__fd=socket(temp->ai_family,temp->ai_socktype,temp->ai_protocol))==-1){
            perror("server :: socket\n");
            continue;
        }
        if(setsockopt(__fd,SOL_SOCKET,SO_REUSEADDR,&__yes,sizeof(unsigned))==-1){
            perror("setsockopt\n");
            exit(1);
        }
        if(bind(__fd,temp->ai_addr,temp->ai_addrlen)==-1){
            close(__fd);
            perror("server: bind\n");
            continue;
        }
        break;
    }

    freeaddrinfo(__servinfo);

    if(temp==NULL){
        fprintf(stderr,"server : failed to bind\n");
        exit(1);
    }
    if(listen(__fd,APOINT_BACKLOG)==-1){
        perror("listen\n");
        exit(1);
    }

    while(1){
        __sin_size=sizeof(__caddr);
        temp_fd=accept(__fd,(__sockaddr*)&__caddr,&__sin_size);
        if(temp_fd==-1){
            perror("accept\n");
            continue;
        }
        inet_ntop(__caddr.ss_family,__get_addr((__sockaddr*)&__caddr), __saddr, sizeof(__saddr));
        printf("server : got connection from %s\n",__saddr);
        if(!fork()){
            close(__fd);
            if(send(temp_fd,"Hello World\n",13,0)==-1){
                perror("send\n");
            }
            close(temp_fd);
            exit(0);
        }
        close(temp_fd);
    }
    return 0;
}
