// UFRN-CT-DCA
// Disciplina: Sistemas de Tempo Real


// Programa sinal1.cpp
// Sinais são eventos gerados pelo Unix em resposta a algumas condições, como:
//  erros, violação de memória, instrução ilegal, ...

#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system()


void ouch (int sig)
{ 
  system("clear");
  printf("Ah, Ah, Ah-  Eu não morro com : %d \n", sig);
  printf("Eu só morro com kill \n");
  printf("Digite o comando ps -a e identifique o meu número de PID\n");
  printf("Depois, mate-me com kill  <pid> \n\n\n\n");
}

int main()
{
  (void) signal(SIGINT, ouch); // SIGINT - Terminal Interrupt

  while(1) {
    printf("Olá, Mundo Cruel! Vou dormir por  3 segundo.\n");
    printf("Tente me matar com Ctrl-C.\n");
    sleep(3);
  }
  // exit(0);
}

