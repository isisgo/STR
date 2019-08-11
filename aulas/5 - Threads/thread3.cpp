/*
 *  thread3.cpp
 *  teste
 *
 *  Created by Luiz Affonso on 04/09/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// programa thread3.cpp
// Programa que executar duas threads simultaneamente: main () e thread_function() 
// Para compilá-lo utilise: g++ -o thread3 thread3.cpp -lpthread

//#include "thread3.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);
int run_now = 1;
char message[] = "Hello World";

int main() {
    int res;
    pthread_t a_thread;
    void *thread_result;
    int print_count1 = 0;
	
    res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
	
    while(print_count1++ < 20) {
        if (run_now == 1) {
            printf("MAIN() --> 1\n");
            run_now = 2;
        }
        else { 
			printf("MAIN() --> Vai dormir por 1 segundo\n");  
			sleep(1);
        }
    }
	
    printf("\nMAIN() --> Esperando a thread terminar...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("MAIN() --> A Thread foi terminada\n");
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
    int print_count2 = 0;
	
    while(print_count2++ < 20) {
        if (run_now == 2) {
            printf("THREAD --> 2\n");
            run_now = 1;
        }
        else {
			printf("THREAD() --> Vai dormir por 1 segundo\n");  
			sleep(1);
        }
    }
	
    printf("THREAD() --> Vai dormir por 3 segundos\n");  
    sleep(3);
    printf("THREAD() --> Vai terminar thread\n");  
}



