// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa vitima.cpp
// Sinais sã eventos gerados pelo Unix em resposta a algumas condições, como:
//  erros, violação de memória, instrução ilegal, ...

#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system()



void sinal_de_morte (int sig)
{
  printf("Recebi um tiro fatal. \n");
 
}

int main()
{
  // o processo que vai esperar pelo sinal de morte

  int meu_pid;

  meu_pid = getpid();
    
 
  //(void) signal(SIGKILL, sinal_de_morte);

  while(1)
  {
    printf("Meu PID é: %d \n", meu_pid);
    printf("Vou dormir por 2 segundos e esperar alguém me matar \n");
    sleep(2);
  }

  //(void) signal(SIGKILL, sinal_morte);
  //   printf(" Após a função signal()\n");
  // pause();
  exit(0);
}






