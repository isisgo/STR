// UFRN-CT-DCA
// Disciplina: Sistemas de Tempo Real
// Programa: sistema.cpp



#include <stdlib.h>
#include <stdio.h>

int main ()
{
 printf("Rodando o comando do shell com a system call system(): Início \n");
 printf("\n\n\n");
 system ("ps -axf | grep sleep");
 system ("./sleep"); // execução de comando do shell
 //system ("./sleep &");
 //system ("firefox &");
 system ("ps -axf | grep sleep");
 printf("Rodando o comando ps com system(): Fim \n");
 exit (0);
}
