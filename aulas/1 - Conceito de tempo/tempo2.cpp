#include <iostream> // para: cout




#include <time.h>   // para: time()
#include <unistd.h>  // para: sleep()
#include <stdlib.h>




using std::cout;
using std::cin;


int main ( )
{

  time_t tempo1, tempo2, deltaT;
  
  int numero;

  tempo1 = time( (time_t *) 0);  // apontando o ponteiro para null.
  sleep(4);
  tempo2 = time( (time_t *) 0);  // apontando o ponteiro para null.
  deltaT = tempo2-tempo1;
    
  cout << "O tempo gasto foi: " << deltaT << " segundos" << '\n';

  exit(0);
}




