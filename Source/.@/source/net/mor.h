
#ifndef __ANET__H
#include "anet.h"
#endif








#ifndef __mor_name
    #define __mor_name "mirror-order-reply"

int mor(void) {
    printf("d-cloud '%s' {%s}\n",__mor_name,"mor");

    #define SOK_CONNECT 1
    int sockfd, numbytes;  
    char buf[ATP_BUFFER_SIZE];
    struct addrinfo hints=__hints();
    struct addrinfo *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];


    if ((rv = getaddrinfo(NULL, ATP_PORT, &hints, &servinfo)) != 0) {
        #ifdef DEBUG
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        #endif
        return 1;
    }

    // loop through all the results and connect to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            #ifdef DEBUG
                perror("client: socket");
            #endif
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            #ifdef DEBUG
                perror("client: connect");
            #endif
            continue;
        }

        break;
    }

    if (p == NULL) {
        #ifdef DEBUG
            fprintf(stderr, "client: failed to connect\n");
        #endif
        return 2;
    }

    inet_ntop(p->ai_family, __sok_addr((struct sockaddr *)p->ai_addr),
            s, sizeof s);
    #if LBB_LOG == 2
        printf("client: connecting to %s\n", s);
    #endif
    freeaddrinfo(servinfo); // all done with this structure

    if ((numbytes = recv(sockfd, buf, ATP_BUFFER_SIZE-1, 0)) == -1) {
        #ifdef DEBUG
            perror("recv");
        #endif
        exit(1);
    }

    buf[numbytes] = '\0';

    #if LBB_LOG == 2
        printf("client: received '%s'\n",buf);
    #endif
    close(sockfd);

    return 0;
}

#endif
