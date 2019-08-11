//
//  cliente3.cpp
//  
//
//  Created by Affonso on 25/04/16.
//
//

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
    struct sockaddr_in address;
    int result;
    char ch = 'A';
    
    sockfd  = socket(AF_INET, SOCK_STREAM,0);  // criacao do socket
    
    address.sin_family = AF_INET;
    
    address.sin_addr.s_addr = inet_addr("10.13.110.65");
    
    //address.sin_addr.s_addr = inet_addr("10.13.98.140");
    
    address.sin_port = htons(9734);
    
    //address.sin_addr.s_addr = inet_addr("10.13.96.16");
    //address.sin_port = 9734;
    
    //strcpy (address.sun_path, "server_socket");
    len = sizeof(address);
    
    result = connect(sockfd, (struct sockaddr *) &address, len);
    
    if (result == -1)
    {
        perror ("Houve erro no cliente");
        exit(1);
    }
    
    write(sockfd, &ch,1);
    read(sockfd, &ch,1);
    printf( "Caracter vindo do servidor = %c\n",ch);
    close(sockfd);
    exit(0);
}

