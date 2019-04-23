// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa sinal3.cpp
// Sinais são eventos gerados pelo Unix em resposta a algumas condições, como:
//  erros, violação de memória, instrução ilegal, ...

#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system()


void funcao1 (int sig)
{
  printf("Ah, Ah, Ah-  Eu não morro com : %d \n", sig);
  printf("Pelo menos, da primeira vez. Tente denovo..\n");
  signal(SIGINT, SIG_DFL);
}

int main()
{
  (void) signal(SIGINT, funcao1); // SIGINT - Terminal Interrupt
  int tempo_de_sono = 0;

  while(1) {
    printf("Olá, Mundo Cruel! Vou dormir por  1 segundo.\n");
    sleep(1);
    tempo_de_sono = tempo_de_sono + 1; 
    if(tempo_de_sono >= 10 )
      {
        printf("Já se passaram 10 segundos. Agora vou me matar.\n");
	kill(getpid(),SIGKILL); // Processo mandando um sinal si mesmo
      
      }
  }
  exit(0);
}


