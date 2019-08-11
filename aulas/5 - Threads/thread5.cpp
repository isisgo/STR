//
//  thread5.cpp
//  
//
//  Created by Affonso on 15/03/16.
//


// Programa que configura os atributos de escalonamento da thread
// Para compil�-lo utilise: g++ -o thread5 thread5.cpp -lpthread


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>

void *thread_function(void *arg);

char message[] = "Alô, Mundo!";
int thread_finished = 0;

int main() {
    int res;
    pthread_t a_thread;
    void *thread_result;
    pthread_attr_t thread_attr;
    sched_param scheduling_value;
    int  max_priority, min_priority;
    
    res = pthread_attr_init(&thread_attr);
    if (res != 0) {
        perror("Falha na criação de Atributo");
        exit(EXIT_FAILURE);
    }
    res = pthread_attr_setschedpolicy(&thread_attr, SCHED_OTHER);
    if (res != 0) {
        perror("Falha na configuração de política de escalonamento");
        exit(EXIT_FAILURE);
    }
    res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
    if (res != 0) {
        perror("Falha na configuração de atributo detached");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&a_thread, &thread_attr, thread_function, (void *)message);
    if (res != 0) {
        perror("Falha na criação da thread");
        exit(EXIT_FAILURE);
    }
    max_priority = sched_get_priority_max(SCHED_OTHER);
    min_priority = sched_get_priority_min(SCHED_OTHER);
    scheduling_value.sched_priority = min_priority;
    res = pthread_attr_setschedparam(&thread_attr, &scheduling_value);
    if (res != 0) {
        perror("Falha na configuração da pol�tica de escalonamento");
        exit(EXIT_FAILURE);
    }
    (void)pthread_attr_destroy(&thread_attr);
    while(!thread_finished) {
        printf("MAIN() --> Aguardando a thread setar o flag de término...\n");
        sleep(1);
    }
    printf("MAIN() --> A thread terminou!\n");
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
    for(int i=0; i<10; i++) {
        printf("THREAD() --> A thread_function está rodando. O argumento foi %s\n", (char *)arg);
    }
    sleep(4);
    printf("THREAD() --> A thread vai setar o flag\n");
    thread_finished = 1;
    printf("THREAD() --> A thread vai terminar\n");
    pthread_exit(NULL);
}
