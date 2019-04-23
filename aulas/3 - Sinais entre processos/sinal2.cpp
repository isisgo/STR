// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa sinal2.cpp
// Sinais sã eventos gerados pelo Unix em resposta a algumas condições, como:
//  erros, violação de memória, instrução ilegal, ...

#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system()


static int cont=0;
void funcao1 (int sig)
{
  //static int cont=0;
  cont=cont+1;
  system("clear");
  printf("Ah, Ah, Ah-  Eu não morro com : %d \n", sig);
  printf("Pelo menos, da primeira vez. Tente de novo..\n\n\n");
  if(cont==2){  //morre com 3 tentativas
	  signal(SIGINT, SIG_DFL);
  }
}

int main()
{
  (void) signal(SIGINT, funcao1); // SIGINT - Terminal Interrupt

  while(1) {
    printf("Olá, Mundo Cruel! Vou dormir por  1 segundo.\n");
    printf("Tente me matar com Ctrl-C.\n");
    sleep(1);
  }
  // exit(0);
}
