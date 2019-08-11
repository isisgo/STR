//
//  cliente7.cpp
//  str
//
//  Created by Affonso on 16/05/16.
//  Copyright © 2016 Affonso. All rights reserved.
//

// #include "cliente7.hpp"

// programa cliente7.cpp --> ler um vetor de caracter. Protocolo UDP


#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main( )
{
    int sockfd;
    int len;
    socklen_t len_recv;
    struct sockaddr_in address;
    int result;
    char vetor_ch[4] = {'A','B','C','D'};
    
    unsigned short porta = 9734;
    
    sockfd  = socket(AF_INET, SOCK_DGRAM,0);  // criacao do socket
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(porta);
    
    len = sizeof(address);
    len_recv = sizeof(address);
    
    printf("O cliente vai enviar a mensagem para o servidor \n");
    
    sendto(sockfd,  vetor_ch,sizeof(vetor_ch),0,(struct sockaddr *) &address, len);
    recvfrom(sockfd, vetor_ch,sizeof(vetor_ch),0,(struct sockaddr *) &address,&len_recv);
    // send(sockfd,  vetor_ch,sizeof(vetor_ch),0);
    // recv(sockfd, vetor_ch,sizeof(vetor_ch),0);
    //write(sockfd,  vetor_ch,sizeof(vetor_ch));
    //read(sockfd, vetor_ch,sizeof(vetor_ch));
    
    printf( "Caracter vindo do servidor = %c %c %c %c\n",vetor_ch[0],vetor_ch[1],vetor_ch[2],vetor_ch[3]);
    close(sockfd);
    exit(0);
}

