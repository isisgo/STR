//
//  sinal6.cpp
//  
//
//  Created by Affonso on 09/03/16.
//
//



// Programa sinal6.cpp -- utilização do sinal ALARM SIGALRM) + SIGINT

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void detecao_alarme (int sig)
{
    printf("O sinal %d foi recebido: SIGALRM\n", sig);
    printf("Vontando para o programa principal\n");
}

void  detecao_interrupcao(int sig)
{
    printf("Recepção do sinal %d: SIGINT\n", sig);
    printf("Por isto vou morrer!\n");
    exit(1);
}

int main()
{
    unsigned segundos;
    signal(SIGINT, detecao_interrupcao); // intercepta��o do sinal de interrup��o
    signal(SIGALRM, detecao_alarme); // intercepta��o do sinal ALARME
    printf("Gerando o alarme em 10s\n");
    segundos = alarm(10);
    printf("Valor retornado pela função alarm(): %d\n",segundos);
    printf("Vou dormir por 3s\n");
    sleep(3);
    printf("Se passaram 3s. Agora vou armar um alarme para 5s\n");
    segundos = alarm(5);
    printf("Novo valor retornado pela função alarm(): %d\n",segundos);
    printf("Vai entrar num loop infinito (CTRL-C para acabar)\n");
    while(1)
    {
        sleep(1);
        printf("Estou num loop infinito\n");
        printf("CTRL-C para me matar\n");
    }
}