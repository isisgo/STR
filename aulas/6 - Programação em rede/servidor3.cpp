//
//  servidor3.cpp
//  
//
//  Created by Affonso on 25/04/16.
//
//

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>

int main( )
{
    int server_sockfd, client_sockfd;
    size_t server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    
    // unlink("server_socket");  // remocao de socket antigo
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);  // cria um novo socket
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(9734);
    
    //server_address.sin_addr.s_addr = inet_addr("10.13.96.16");
    //server_address.sin_port = 9734;
    
    //strcpy(server_address.sun_path, "server_socket");
    
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *) &server_address, server_len);
    
    listen(server_sockfd, 5);
    while(1) {
        char ch;
        
        printf("Servidor esperando ... Servidor Affonso\n");
        client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, (socklen_t *) &client_len);
        
        read(client_sockfd, &ch, 1);
        ch = ch +5;
        write(client_sockfd, &ch, 1);
        close(client_sockfd);
    }
}

