#include <iostream>
#include <pthread.h>
#include "BlackGPIO/BlackGPIO.h"
#include "ADC/Adc.h"
#include <unistd.h>
#include <sys/time.h>     // getpriority(int which, int who)  setpriority(int which, int who, int prio);
#include <sys/resource.h>
#include <math.h>
#include <errno.h>


using namespace BlackLib;

void carga(int k){
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


int main(int argc, char * argv[]){
  float v0,v1;

  ADC adc0(AINx::AIN0);
  ADC adc1(AINx::AIN1);
  BlackGPIO led1(GPIO_4, output);
  BlackGPIO led2(GPIO_5, output);
  led1.setValue(low); //blue
  led2.setValue(low); //red

  int pfilho1, pfilho2, cont;

  pfilho1=fork(); /* criacao do filho 1 */
  cont = 0;

  if(pfilho1==0){/* acoes do filho 1*/

    while(true){
      std::cout<<"filho1 "<<getpid()<<endl;
      std::cout << "PROCESSO 1 (LED BRANCO): " << getpriority(PRIO_PROCESS, pfilho1) <<endl;
      cont++;
      carga(1200);
      if(cont%2 == 0){
        led1.setValue(high);
      }else{
        led1.setValue(low);
      }
    }

  }else{
    pfilho2=fork(); /* criacao do filho 2 */

    if(pfilho2==0){/* acoes do filho 2*/

      while(true){
        std::cout<<"filho2 "<<getpid()<<endl;
        std::cout << "PROCESSO 2 (LED AZUL) " << getpriority(PRIO_PROCESS, pfilho2) <<endl;
        cont++;
        carga(1200);
        if(cont%2 == 0){
          led2.setValue(high);
        }else{
          led2.setValue(low);
        }
      }
    }
  }

  while(true){ /* ações do pai*/
    //seta a prioridade do processo pai para 0
    setpriority(PRIO_PROCESS, 0, 0);

    v0 = adc0.getFloatValue();
    v1 = adc1.getFloatValue();
    if(v0>=1.0){
      //seta a prioridade do processo filho 1 para 5
      setpriority(PRIO_PROCESS, pfilho1, 5);
    }else if (v0<1.0){
      setpriority(PRIO_PROCESS, pfilho1, 19);
    }
    if(v1>=1.0){
      //seta a prioridade do processo filho 2 para 5
      setpriority(PRIO_PROCESS, pfilho2, 5);
    }else if(v1<1.0){
      //seta a prioridade do processo filho 1 para 19
      setpriority(PRIO_PROCESS, pfilho2, 19);
    }
    usleep(050000);
  }

  return 0;
}