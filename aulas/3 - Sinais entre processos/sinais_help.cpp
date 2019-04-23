// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa sinal1.cpp
// Sinais são eventos gerados pelo Unix em resposta a algumas condições, como:
//  erros, violação de memória, instrução ilegal, ...

#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system()



int main()
{
  system("clear");
  printf("\n\n Sinais são eventos gerados pelo Unix em resposta a algumas condições, como: \n\t erros, violação de memória, instrução ilegal, ... \n\n");
  printf(" A funçao signal(tipo_do_sinal, funcao_programada),  reprograma um sinal. \n\n");
  printf(" A função kill(PID_do_processo, tipo_do_sinal)  envia um sinal a um processo. \n\n");
  printf(" Os sinais são números, aqui definidos com DEFINE em signal.h\n");
  printf(" Digite <man signal> para saber mais sobre os sinais e digite <kill -l> para listar os tipos de sinais.\n\n\n");


  // exit(0);
}

