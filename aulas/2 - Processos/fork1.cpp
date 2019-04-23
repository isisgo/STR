
// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: fork1

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{

// declarações de variáveis
  int i;
  pid_t pid;          // definindo um identificador de processo - inteiro longo
  
  
   
  printf("Começando o programa fork1 ... \n");
  sleep(1);
  printf("Sou o processo Pai \n");
  system("ps");
  
  pid = fork();   // dividindo o processo em dois
  switch(pid)
    {
      case -1:       // erro na abertura do processo filho
        exit(1);  
      case 0:        // Parte a ser executada pelo processo Filho1
        for(i=1;i<10;i++) {
          sleep(1);
          printf("\n\nSou o processo Filho1 \n");
          //system("ps -axf| grep fork1 &");
        
        }
        printf("Sou o processo Filho e vou morrer agora - Até la vista baby :( \n");
         break;
      default:       // parte a ser executada pelo processo Pai
        for(i=1;i<5;i++) {
           sleep(1);
           printf("\n\nSou o processo Pai \n");
           //system("ps -axf| grep fork1");
        }
            printf("Sou o processo Pai e vou morrer agora - Até la vista, baby :( \n");
   }
      
    exit (0);

}
