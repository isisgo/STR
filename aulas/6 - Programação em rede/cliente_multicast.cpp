//
//  cliente_multicast.cpp
//  str
//
//  Created by Affonso on 18/05/16.
//  Copyright © 2016 Affonso. All rights reserved.
//

//#include "cliente_multicast.hpp"

// programa cliente_multicast.cpp --> ler um vetor de caracter. Protocolo UDP


#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


#define MULTICAST_ADDR "225.0.0.37"

int main( )
{
    int sockfd;
    int len;
    socklen_t len_recv;
    struct sockaddr_in address;
    int result;
    
    
    unsigned short porta = 9734;
    
    sockfd  = socket(AF_INET, SOCK_DGRAM,0);  // criacao do socket
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(MULTICAST_ADDR);
    //address.sin_addr.s_addr = inet_addr("10.13.96.16"); // euler
    address.sin_port = htons(porta);
    
    len = sizeof(address);
    
    for(int i=0;i<10;i++)
    {
        sendto(sockfd, &i,sizeof(i),0,(struct sockaddr *) &address, len);
        sleep(1);
    }
    close(sockfd);
    exit(0);
}
