//
//  sinal4.cpp
//  
//
//  Created by Affonso on 09/03/16.
//
//

// Programa sinal4.cpp
// Sinais são eventos gerados pelo Unix em resposta a algumas condições:
//  erros, violação de memória, instrução ilegal, ...


// Processo mandando um alarme
//

#include <signal.h> // defini��o dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>




void alarme (int sig)
{
    printf("Alarme foi desligado. \n");
    
}

int main()
{
    // o processo filho espera por 5 segundos antes de enviar um sinal SIGALRM para seu pai
    
    int pid;
    
    
    printf("O alarme foi disparado. \n");
    
    if ( (pid = fork()) == 0)
    {
        // código do processo filho
        printf("\n\n            Execução do Filho- vai dormir por 5 segundos\n");
        sleep(5);
        kill(getppid(), SIGALRM);
        sleep(2);
        printf("            Execução do Filho- filho vai morrer\n\n");
        exit(0);
    }
    printf("Pai esperando pelo Sinal de alarme desligar (5s). \n");
    //(void) signal(SIGALRM, alarme);
    printf(" Após a função signal()\n");
    pause();
    printf("O sinal de alarme chegou ao Pai .\n");
    sleep(12);
    printf("Processo Pai após Sleep\n");
    exit(0);
    
    // exit(0);
}
