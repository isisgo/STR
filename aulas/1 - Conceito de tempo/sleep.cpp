
/////\// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: sleep.c


#include <iostream> // para: cout
#include <stdio.h>
#include <unistd.h> // para: sleep()


using std::cout;

//using namespace std;


int main ( )
{

  double x = 1;
    
  //usleep(1000);
  sleep(2);
  cout << "passei. levou 2 segundos" << '\n';
  for(int i=0; i<5; i++) {
    sleep(i);
    cout << "teste "  << i <<'\n';
   
  }
  cout << "teste" <<'\n';
  return(0);
}

