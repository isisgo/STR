
//
//  cliente1.cpp
//  
//
//  Created by Affonso on 25/04/16.
//
//

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main( )
{
    int sockfd;
    int len;
    struct sockaddr_un address;
    int result;
    char ch = 'A';
    
    sockfd  = socket(AF_UNIX, SOCK_STREAM,0);  // criacao do socket
    
    address.sun_family = AF_UNIX;
    strcpy (address.sun_path, "server_socket");
    len = sizeof(address);
    
    result = connect(sockfd, (struct sockaddr *) &address, len);
    
    if (result == -1)
    {
        perror ("Houve erro no cliente");
        exit(1);
    }
    
    
    // send(sockfd, &ch,1,0);
    // recv(sockfd, &ch,1,0);
    write(sockfd, &ch,1);
    read(sockfd, &ch,1);
    printf( "Caracter vindo do servidor = %c\n",ch);
    close(sockfd);
    exit(0);
}

