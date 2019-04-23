




// UFRN-CT-DCA
// Disciplina: Sistemas de Tempo Real
// Programa: prioridade.cpp


#include  <time.h>
#include <iostream> // para: cout
#include <stdio.h>
#include <unistd.h>  // para: sleep()
#include <stdlib.h>
#include <math.h>

#include <sys/time.h>     // getpriority(int which, int who)  setpriority(int which, int who, int prio);
#include <sys/resource.h>

//using std::cout;
using namespace std;


// função para simular carregamento da CPU
void carga(int k)
{
  float f = 0.999999;
  for(int i=0; i<k; i++)
    {
      f = f*f*f*f*f;
      f = 1.56;
        for(int j=0; j<k; j++)
           {
	     f = sin(f)*sin(f)*f*f*f;

            }
    }

}


int main( ){

     clock_t time_1, time_2;
     time_t  real_time_1, real_time_2, delta_real_time;
    
     int saida;
     double saida2;

    
    
    // nice(50); muda a prioridade do processo via comando nice(int valor): valores positivos - negativos só para root
    
    //int getpriority(int which, int who);  // which: PRIO_PROCESS, PRIO_PGRP, or PRIO_USER
    //int setpriority(int which, int who, int prio);

    
                                                               
                                                               
    cout << "valor da prioridade do processo: " << getpriority(PRIO_PROCESS, 0 ) <<endl;
    //cout << "valor da prioridade do processo: " << getpriority(PRIO_PROCESS, getpid() ) <<endl;
    
    setpriority(PRIO_PROCESS, 0, 5);
    cout << "valor da prioridade do processo, após primeiro setpriority(): " << getpriority(PRIO_PROCESS, 0 ) <<endl;
    
    setpriority(PRIO_PROCESS, 0, 10);
    cout << "valor da prioridade do processo: após segundo setpriority() " << getpriority(PRIO_PROCESS, 0 ) <<endl;

    
    (PRIO_PROCESS, 0, 5);
    cout << "valor da prioridade do processo: após terceiro setpriority() " << getpriority(PRIO_PROCESS, 0 ) <<endl;

    // --------------------------------------------------------------
    //  Outras formas de setar a prioridade do processo
    //
    //  setpriority(PRIO_PROCESS, getpid(), 5);
    //  setpriority(PRIO_USER, getuid(), 5);    // seta a prioridade do shell
    //  cout << "valor da prioridade do processo: " << getpriority(PRIO_PROCESS, 0 ) <<endl;
    //
    // ---------------------------------------------------------------
    
    
    //nice(10);
    //cout << "valor da prioridade do processo, após o nice(10): " << getpriority(PRIO_PROCESS, 0 ) <<endl;
    
    
    // ------------------------------------------------------------------------------------------------
    //
    //            Teste estas opções a baixo e tire as suas conclusões sobre os comandos nice e setpriority()
    //  -----------------------------------------------------------------------------------------------
    //
    //nice(1);
    //cout << "valor da prioridade do processo, após o segundo nice(): " << getpriority(PRIO_PROCESS, 0 ) <<endl;
    
    
    //nice(1);
    //cout << "valor da prioridade do processo, após o segundo nice(): " << getpriority(PRIO_PROCESS, 0 ) <<endl;
    
    //setpriority(PRIO_PROCESS, 0, 10);
    //cout << "valor da prioridade do processo, apos segundo setpriority(): " << getpriority(PRIO_PROCESS, 0 ) <<endl;
    //
    // -----------------------------------------------------------------------------------------------
    
    
    
    // ---------------------------------------------------------------------------------
    //
    //  Parte do código associada com uso intenso de CPU : início
    //
    //  --------------------------------------------------------------------------------
    
     time_1 = clock();
     real_time_1 = time(0);
     carga(10000);       // funcão de uso intenso de CPU
     sleep(6);
     real_time_2 = time(0);
     time_2 = clock();

    
    saida = (int) (time_2) - (time_1);  // tempo de CPU
    saida2 = (double) ((saida) / (double) CLOCKS_PER_SEC) ;
    delta_real_time = (real_time_2) - (real_time_1);
    
    printf("\n Tempo de uso da CPU em microsegundos: %d \n", saida);
    printf(" Tempo de uso da CPU em segundos: %f \n", saida2);
    printf(" Tempo Real decorrido em microsegundos: %d \n", (int) delta_real_time);
    cout << "\n\n  valor da prioridade do processo - final: " << getpriority(PRIO_PROCESS, 0 ) <<endl;
    
    // ---------------------------------------------------------------------------------
    //
    //  Parte do código associada com uso intenso de CPU : fim
    //
    //  --------------------------------------------------------------------------------
    
    
    
    exit(1);

}

