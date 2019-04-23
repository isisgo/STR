/*
 *  clock1.cpp
 *  
 *
 *  Created by Luiz Affonso Guedes on 06/03/17.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

// UFRN-CT-DCA
// Manipulação de tempo em c,c++
// Programa: programa que calcula o tempo de CPU utilizada


#include  <time.h>   // clock()
#include <stdio.h>   // printf()
#include <unistd.h>  // sleep()
#include <stdlib.h>  // exit()
#include <math.h>    // sin()


// função para simular carregamento da CPU
void carga(int k){
	float f = 0.999999;
	for(int i=0; i<k; i++){
		f = f*f*f*f*f;
		for(int j=0; j<k; j++){
			f = sin(f)*sin(f)*f*f*f;
		}
	}
}

int main( ){
	
	time_t tempo1, tempo2;
	
		
	clock_t clock_1, clock_2;
	//Obter o tempo de CPU antes da carga de processamento 
	
	tempo1 = time( (time_t *) 0);  // apontando o ponteiro para null.

	clock_1 = clock();
	// Carga de processamento
	carga(30000);
	sleep(1);
	//Obter o tempo de CPU ap�s a carga de processamento
	clock_2 = clock();
	tempo2 = time( (time_t *) 0);  // apontando o ponteiro para null.
	
	printf("Tempo de utilização de CPU em ticks: %lu \n", (unsigned long)(clock_2-clock_1));
    printf("Tempo de utilização de CPU em segundos: %f \n", (double)(clock_2-clock_1)/(double) CLOCKS_PER_SEC);
	printf("Tempo de relógio em segundos: %ld \n", (int) tempo2 - tempo1 );
	exit(0);
}



