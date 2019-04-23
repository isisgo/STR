/*
 *  clock2.cpp
 *  
 *
 *  Created by Luiz Affonso Guedes on 06/03/17.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

// UFRN-CT-DCA
// Manipulação de tempo em c,c++
// Programa: programa que calcula o tempo de CPU utilizada

// UFRN-CT-DCA
// Manipulação de tempo em c,c++
// Programa: programa que mostra a diferen�a entre time e clock


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
		f = 1.56;
		for(int j=0; j<k; j++){
			f = sin(f)*sin(f)*f*f*f;
		}
	}
}

int main( ){
	//Variáveis usadas para o cálculo do clock
	clock_t clock_1, clock_2;
	//Váriáveis usadas para o cálculo do time
	time_t  time_1, time_2;
	//Obter os tempos de CPU e time (1970)
	clock_1 = clock();
	time_1 = time(NULL);
	// Carga de processamento
	carga(1000);
	sleep(6);
	//Obter os tempo de CPU e time (1970) ap�s a carga de processamento
	clock_2 = clock();
	time_2 = time(NULL);
	printf("Tempo de utilização de CPU em segundos: %f \n", (double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC);
	printf("Tempo gasto na execução do bloco em segundos: %li \n", time_2-time_1);
	exit(0);
}



