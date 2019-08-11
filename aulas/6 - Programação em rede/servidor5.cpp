//
//  servidor5.cpp
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
#include <stdlib.h>
#include <string.h>

int main( )
{
    int server_sockfd, client_sockfd;
    size_t server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    
    unlink("server_socket");  // remocao de socket antigo
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);  // cria um novo socket
    
    server_address.sin_family = AF_INET;
    //server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // s� clientes locais
    server_address.sin_addr.s_addr  = INADDR_ANY;  // qualquer cliente
    server_address.sin_port = 9734;
    
    //strcpy(server_address.sun_path, "server_socket");
    
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *) &server_address, server_len);
    
    listen(server_sockfd, 5);
    while(1) {
        //char vetor_ch[4];
        
        struct dado {
            int idade;
            char nome[34];
        };
        
        dado aluno;
        aluno.idade = 38;
        strcpy(aluno.nome, "Jose Silva");
        
        printf("Servidor esperando ...\n");
        client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, (socklen_t *) &client_len);
        
        //  read(client_sockfd, vetor_ch, sizeof(vetor_ch));
        // for(int i =0; i<4;i++) {
        //  vetor_ch[i]++;
        // }
        write(client_sockfd, &aluno, sizeof(aluno));
        close(client_sockfd);
    }
}

