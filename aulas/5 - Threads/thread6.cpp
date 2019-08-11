//
//  teste6.cpp
//  
//
//  Created by Affonso on 15/03/16.
//
//

//#include "teste6.hpp"

// Programa que cancela uma thread
// Para compil�-lo utilise: g++ -o thread6 thread6.cpp -lpthread



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

int main() {
    int res;
    pthread_t a_thread;
    void *thread_result;
    
    res = pthread_create(&a_thread, NULL, thread_function, NULL);
    if (res != 0) {
        perror("Falha na cria��o da Thread");
        exit(EXIT_FAILURE);
    }
    sleep(3);
    printf("MAIN() --> Cancelando thread...\n");
    res = pthread_cancel(a_thread);
    if (res != 0) {
        perror("FAlha na cancelamento da Thread");
        exit(EXIT_FAILURE);
    }
    printf("MAN() --> Esperando a thread terminar...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("Falha na jun��o da Thread");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
    int i, res, j;
    res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    if (res != 0) {
        perror("Falha na Thread pthread_setcancelstate");
        exit(EXIT_FAILURE);
    }
    res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    if (res != 0) {
        perror("FAlha na Thread pthread_setcanceltype");
        exit(EXIT_FAILURE);
    }
    printf("THREAD() --> thread_function est� rodando\n");
    for(i = 0; i < 10; i++) {
        printf("THREAD() --> A Thread ainda est� rodando (%d)...\n", i);
        sleep(1);
    }
    pthread_exit(0);
}
