

// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: fork2.c
// Objetivo: utilizar as funções getpid() e getppid()

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main ()
{

// declaração de variáveis
  pid_t pid;          // definindo um identificador de processo - inteiro longo
   
  printf("Começando o programa fork2 ... \n");
  system("ps");  // tente ps -aux, ps -auf
  sleep(3); 
  printf( "\n\nEu sou o Pai %d e vou criar um Filho\n", getpid() );
  pid = fork();   // dividindo o processo em dois

  switch(pid)
    {
    case -1:       // erro na abertura do processo filho
      exit(1);  
    case 0:        // execução do processo Filho
      for(int i=0; i<3; i++) {
         sleep(2);  // dormir por 2 segundos
         printf( "\t Eu sou o processo %d, filho de %d \n", getpid(), getppid());
         printf( "\t Vou dormir um pouco\n");
      
      }
    break;
    default:      // excução do processo Pai    
      sleep(3);
      printf(" \nEu sou o processo Pai número de PID =  %d\n", getpid());
      printf(" Sou o Prcesso PAI. Acabei de ter um Filho. O PID dele é PID =  %d\n", pid);
      printf(" Fim do Processo Pai\n");
    break;
    }
    // execução de ambos os processos
    //system("ps -f");
    //if(pid > 0) {
      //sleep(10);
      //system("ps -aufx | grep fork2");
    //}
    //printf("Terminando o programa fork2 ... \n");
    exit (0);

}
