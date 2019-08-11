//
//  thread9.cpp
//  
//
//  Created by Affonso on 15/03/16.
//
// Programa que configura os atributos de escalonamento da thread
// Para compilá-lo utilise: g++ -o thread9 thread9.cpp -lpthread


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>

void *thread_function(void *arg);

char letra_thread_a, letra_thread_b, letra_thread_c, letra_thread_d;
int thread_finished = 0;

int main() {
    int res;
    pthread_t a_thread, b_thread, c_thread, d_thread;
    void *thread_result;
    pthread_attr_t thread_attr;
    sched_param scheduling_value;
    int  max_priority, min_priority;
    
    res = pthread_attr_init(&thread_attr);
    if (res != 0) {
        perror("Falha na criação de Atributo");
        exit(EXIT_FAILURE);
    }
    
    res = pthread_attr_setschedpolicy(&thread_attr, SCHED_RR);
    if (res != 0) {
        perror("Falha na configuração de política de escalonamento");
        exit(EXIT_FAILURE);
    }
    
    res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
    if (res != 0) {
        perror("Falha na configuração de atributo detached");
        exit(EXIT_FAILURE);
    }
    
    // configurar prioridade das threads
    
    max_priority = sched_get_priority_max(SCHED_RR);
    min_priority = sched_get_priority_min(SCHED_RR);
    //scheduling_value.sched_priority = min_priority;  // setar prioridade mínima
    scheduling_value.sched_priority = max_priority;  // setar prioridade máxima
    
    res = pthread_attr_setschedparam(&thread_attr, &scheduling_value);
    if (res != 0) {
        perror("Falha na configuração da pol�tica de escalonamento");
        exit(EXIT_FAILURE);
    }
    
    
    // criação da thread a_thread
    letra_thread_a = 'a';
    res = pthread_create(&a_thread, &thread_attr, thread_function, (void *) &letra_thread_a);
    if (res != 0) {
        perror("Falha na criação da thread");
        exit(EXIT_FAILURE);
    }
    
    // criação da thread b_thread
    letra_thread_b = 'b';
    res = pthread_create(&b_thread, &thread_attr, thread_function, (void *) &letra_thread_b);
    if (res != 0) {
        perror("Falha na criação da thread");
        exit(EXIT_FAILURE);
    }
    
    // criação da thread c_thread
    letra_thread_c = 'c';
    res = pthread_create(&c_thread, &thread_attr, thread_function, (void *) &letra_thread_c);
    if (res != 0) {
        perror("Falha na criação da thread");
        exit(EXIT_FAILURE);
    }
    
    // criação da thread d_thread
    letra_thread_d = 'd';
    res = pthread_create(&d_thread, &thread_attr, thread_function, (void *) &letra_thread_d);
    if (res != 0) {
        perror("Falha na criação da thread");
        exit(EXIT_FAILURE);
    }
    
    
    /*
     
    //max_priority = sched_get_priority_max(SCHED_OTHER);
    //min_priority = sched_get_priority_min(SCHED_OTHER);
    //scheduling_value.sched_priority = min_priority;  // setar prioridade mínima
    //scheduling_value.sched_priority = max_priority;  // setar prioridade máxima
    
  
    res = pthread_attr_setschedparam(&thread_attr, &scheduling_value);
    if (res != 0) {
        perror("Falha na configuração da pol�tica de escalonamento");
        exit(EXIT_FAILURE);
    }
    
    */
    
    
    for(int i=0; i<10; i++) {
        printf("MAIN() --> A thread main() está rodando. i = %d\n", i);
        for (int j = 0; j < 2; j ++)
            for (int k = 0; k < 1387634340; k ++);
    }
    
    
    while(!thread_finished) {
        printf("MAIN() --> Aguardando a thread setar o flag de término...\n");
    }
    printf("MAIN() --> A thread vai terminar!\n");
    
    (void)pthread_attr_destroy(&thread_attr);
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
    
    for(int i=0; i<10; i++) {
        printf("THREAD() --> A thread %c está rodando. i = %d\n",    (char *) arg, i);
        for (int j = 0; j < 2; j ++)
            for (int k = 0; k < 1387634340; k ++);
    }
    printf("THREAD() --> A thread vai setar o flag\n");
    thread_finished = 1;
    printf("THREAD() --> A thread vai terminar\n");
    pthread_exit(NULL);
}
