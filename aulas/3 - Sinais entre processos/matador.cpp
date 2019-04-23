// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa matatdor.cpp
// Sinais sã eventos gerados pelo Unix em resposta a algumas condições, como:
//  erros, violação de memória, instrução ilegal, ...

#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system()



int  main()
{
  // o processo que vai matar

  int meu_pid;
  int pid_vitima;
  int escolha;
  meu_pid = getpid();
    
  
 printf( "Eu sou um programa matador de programa meu PID é %d\n", meu_pid );
 printf("Você deseja (1) - Parar, (2) - Continuar ou (3) - Matar? \n");
 scanf("%d", &escolha);
 if(escolha==1){
	 printf("Digite o PID do processo que vai parar: \n");
	 scanf("%d", &pid_vitima);
	 printf("Vou parar o processo %d \n", pid_vitima);
	 
	 kill(pid_vitima, SIGSTOP);
 }else if(escolha==2){
	 printf("Digite o PID do processo que vai continuar: \n");
	 scanf("%d", &pid_vitima);
	 printf("Vou continuar com o processo %d \n", pid_vitima);

	 kill(pid_vitima, SIGCONT);
 }else if(escolha==3){
	 printf("Digite o PID do processo que vai morrer: \n");
	 scanf("%d",&pid_vitima);
	 printf("Vou matar o processo %d \n", pid_vitima);
  
 	kill(pid_vitima, SIGKILL);
 	printf( "\nAgora posso morrer tranquilo.\n");
	 exit(0);
 }}






