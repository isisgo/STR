// UFRN-DCA
// Disciplina: Sistemas de Tempo Real
// Programa escolha.cpp
//Este programa dá opção de parar, matar, continuar, setar afinidade e prioridade para CPU de um processo.

#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h> 
#include <unistd.h>

#include <sys/time.h> // getpriority(int which, int who) e setpriority(int which, int who, int prio);
#include <sys/resource.h>



int main(int argc, char *argv[]) {
	//id do core da CPU: #0 para a 1a, #1 para a 2a, etc.
	int core_id;
	//pid do processo que está rodando esse programa
	int meu_pid;
	meu_pid = getpid();
	//pid do processo que será manipulado
 	int pid_vitima;
	//escolha do usuário
 	int escolha;
	//valor prioridade do processo (quanto mais baixa, maior)
	int prio;

	//cpu_set_t: bitset onde cada bit representa uma CPU;
 	cpu_set_t cpuset;
	// CPU_ZERO: macro que inicializa o conjunto CPU set para ser vazio;
	CPU_ZERO(&cpuset);


	printf( "Olá! Eu sou um programa manipulador de programas, meu PID é %d\n", meu_pid );
	printf("Você deseja (1) - Parar, (2) - Continuar, (3) - Matar, (4) - Setar o CPU? ou (5) - Setar a prioridade?\n");
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
 	}else if(escolha==4){
		printf("Digite o pid do processo: \n");
		scanf("%d", &pid_vitima);
		printf("Agora digite o id do core que será dedicado ao processo acima: \n");
		scanf("%d", &core_id);
		printf("Agora vou colocar o processo %d no core %d \n", pid_vitima, core_id);

 		// CPU_SET: macro que adicona a CPU para o conjunto cpu set.
 		CPU_SET(core_id, &cpuset);

		const int set_result = sched_setaffinity(pid_vitima, sizeof(cpu_set_t), &cpuset);
	
		const int get_affinity = sched_getaffinity(pid_vitima, sizeof(cpu_set_t), &cpuset);

  		// CPU_ISSET: macro que retorna um valor não nulo(true) se a cpu for um mebro do conjunto cpu set, ou zero (false) caso contrário.
 		if (CPU_ISSET(core_id, &cpuset)) {
		fprintf(stdout, "Thread %d setada por afinidade para CPU %d com sucesso!\n", pid_vitima, core_id);
		} else {

		fprintf(stderr, "Falha ao setar thread %d para CPU %d\n", pid_vitima, core_id);
  		}

	}else if(escolha==5){
		printf("Digite o pid do processo para setar prioridade:\n");
		scanf("%d", &pid_vitima);
		printf("Agora digite a prioridade (5 à 20) para esse processo\n");
		scanf("%d", &prio);
		printf("Em que cpu esse processo irá rodar com essa prioridade?\n");
		scanf("%d", &core_id);

		printf("Agora vou setar a prioridade do processo %d no core %d para: %d\n", pid_vitima, core_id, prio);

		CPU_SET(core_id, &cpuset); // set a cpu para o core_id 
		sched_setaffinity(pid_vitima, sizeof(cpu_set_t), &cpuset);
    
		setpriority(PRIO_PROCESS, pid_vitima, prio); //PRIO_PROCESS, PRIO_PGRP, ou PRIO_USER são usados para indicar se o argumento vai ser um ID de processo, de grupo ou de usuário
		
	}
  
  return 0;
}
