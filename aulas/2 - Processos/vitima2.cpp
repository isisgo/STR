// UFRN-CT-DCA
// Disciplina: Sistemas de Tempo Real
// Programa vitima2.cpp

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system()

int main()
{
  // o processo que vai esperar pelo sinal de morte

  int meu_pid;

  meu_pid = getpid();
    
  printf("Meu PID é: %d \n", meu_pid);
  printf("Vou ficar num loop infinito\n");
    
  while(1);  // loop infinito

  
  exit(0);
}






