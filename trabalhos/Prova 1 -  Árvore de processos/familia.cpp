#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <syslog.h>
#include <signal.h>


void fala(){
	printf("Meu pid é %d\n", getpid());
	printf("Meu pai é %d\n", getppid());
}

int main()
{

pid_t pid_pai, pid_filho1, pid_filho2, pid_neto1, pid_neto2, pid_neto3, pid_neto4;


pid_pai = fork();
fala();
printf("Vou dormir por 5 segundos!\n");
sleep(5);
switch(pid_pai){
case 0:	
	pid_filho1 = getpid();
	pid_filho1 = fork();
		if(pid_filho1 ==0){
			printf("Sou filho e tive o neto 1!\n");
			pid_neto1 = getpid();
			fala();
			printf("Vou dormir por 20 segundos!\n");
			sleep(30);
			printf("Neto 1 vai morrer!\n");
			//kill(pid_neto1, SIGKILL);
			exit(0);		
		}
	printf("Sou filho1 e vou dormir por 10 segundos!\n");	
	sleep(10);
	pid_filho1 = fork();
		if(pid_filho1 ==0){
			printf("Sou filho e tive o neto 2!\n");
			pid_neto2 = getpid();
			fala();
			printf("Vou dormir por 20 segundos!\n");
			sleep(30);
			printf("Neto 2 vai morrer!\n");
			exit(0);
			//kill(pid_neto2, SIGKILL);
		}
	sleep(10);
	printf("Filho 1 vai morrer!\n");
	exit(0);
	//kill(pid_filho1, SIGKILL);

}
printf("Vou dormir 10 segundos antes de ter meu segundo filho!\n");
sleep(10);
pid_pai = fork();
switch(pid_pai){
case 0:
	pid_filho2 = getpid();
	pid_filho2 = fork();
		if(pid_filho2 ==0){
			printf("Sou filho2 e tive o neto 3!\n");
			pid_neto3 = getpid();
			fala();
			printf("Vou dormir por 20 segundos!\n");
			sleep(30);
			printf("Neto 3 vai morrer!\n");
			//kill(pid_neto3, SIGKILL);
			exit(0);		
		}
	printf("Sou filho2 e vou dormir por 10 segundos!\n");	
	sleep(10);
	pid_filho2 = fork();
		if(pid_filho2 ==0){
			printf("Sou filho2 e tive o neto 4!\n");
			pid_neto4 = getpid();
			fala();
			printf("Vou dormir por 20 segundos!\n");
			sleep(30);
			printf("Neto 4 vai morrer!\n");
			exit(0);
			//kill(pid_neto4, SIGKILL);
		}
	sleep(10);
	printf("Filho 2 vai morrer!\n");
	exit(0);
}
sleep(50);
printf("Sou pai, meu pid eh %d e ja vou morrer!\n", getpid());
kill(pid_pai, SIGKILL);	
}
