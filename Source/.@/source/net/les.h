
#ifndef __ANET__H
#include "anet.h"
#endif


#ifndef __les_name
    #define __les_name "listen-evaluate-send"


int les(void) {
    printf("d-cloud '%s' {%s}\n",__les_name,"les");
    int __fd, temp_fd, __yes=1, __rv;
    struct addrinfo hints=__hints(); 
    struct addrinfo *__servinfo, *temp;
    struct sockaddr_storage __caddr;

    socklen_t __sin_size;
    char __saddr[INET6_ADDRSTRLEN];

    if ((__rv=getaddrinfo(NULL,ATP_PORT,&hints,&__servinfo))!=0){
        #ifdef DEBUG
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(__rv));
        #endif
        return 1;
    }

    for(temp=__servinfo;temp!=NULL;temp=temp->ai_next){
        if((__fd=socket(temp->ai_family,temp->ai_socktype,temp->ai_protocol))==-1){
            #ifdef DEBUG
                perror("server :: socket\n");
            #endif
            continue;
        }
        if(setsockopt(__fd,SOL_SOCKET,SO_REUSEADDR,&__yes,sizeof(unsigned))==-1){
            #ifdef DEBUG
                perror("setsockopt\n");
            #endif
            exit(1);
        }
        if(bind(__fd,temp->ai_addr,temp->ai_addrlen)==-1){
            close(__fd);
            #ifdef DEBUG
                perror("server: bind\n");
            #endif
            continue;
        }
        break;
    }

    freeaddrinfo(__servinfo);

    if(temp==NULL){
        #ifdef DEBUG
            fprintf(stderr,"server : failed to bind\n");
        #endif
        exit(1);
    }
    if(listen(__fd,ATP_INUM)==-1){
        #ifdef DEBUG
            perror("listen\n");
        #endif
        exit(1);
    }

    while(1){
        __sin_size=sizeof(__caddr);
        temp_fd=accept(__fd,(struct sockaddr*)&__caddr,&__sin_size);
        if(temp_fd==-1){
            #ifdef DEBUG
                perror("accept\n");
            #endif
            continue;
        }
        inet_ntop(__caddr.ss_family,__sok_addr((struct sockaddr*)&__caddr), __saddr, sizeof(__saddr));
        #if LBB_LOG >= 2
            printf("server : got connection from %s\n",__saddr);
        #endif
        if(!fork()){
            close(__fd);

            char *msg_to_send="Hello World\0";
            ulong msglen=strlen(msg_to_send);

            if(send(temp_fd,msg_to_send,msglen,0)==-1){
                #ifdef DEBUG
                    perror("send\n");
                #endif
            }
            close(temp_fd);
            exit(0);
        }
        close(temp_fd);
    }
    return 0;

}

#endif

