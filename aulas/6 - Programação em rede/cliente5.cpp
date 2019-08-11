//
//  cliente5.cpp
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
#include <iostream>
#include <string.h>


using std::cout;
using std::endl;

int main( )
{
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    //char vetor_ch[4] = {'A','B','C','D'};
    
    struct dado {
        int idade;
        char nome[34];
    };
    
    dado pessoa1;
    
    
    
    sockfd  = socket(AF_INET, SOCK_STREAM,0);  // criacao do socket
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost
    //address.sin_addr.s_addr = inet_addr("10.13.96.16"); //euler
    address.sin_port = 9734;
    
    //strcpy (address.sun_path, "server_socket");
    len = sizeof(address);
    
    result = connect(sockfd, (struct sockaddr *) &address, len);
    
    if (result == -1)
    {
        perror ("Houve erro no cliente");
        exit(1);
    }
    
    // write(sockfd,  pessoa1,sizeof(pessoa1));
    read(sockfd, &pessoa1,sizeof(pessoa1));
    
    cout << " nome : " << pessoa1.nome << endl;
    cout << " idade : " << pessoa1.idade <<endl;
    
    close(sockfd);
    exit(0);
}

