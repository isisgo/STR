/*
Author: Isis Gomes de Oliveira
UFRN - Sistemas de Tempo Real
*/

#include <iostream>
#include "PWM/PWM.h"
#include "ADC/Adc.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string>
#include <math.h>
#include "BlackGPIO/BlackGPIO.h"
#include <pthread.h>

using namespace BlackLib;

//LEDS:
BlackGPIO yellow(GPIO_23, output);      //P813
 BlackGPIO red(GPIO_26, output);          //P814
 BlackGPIO blue(GPIO_47, output);         //P815

 //BOTOES:
BlackGPIO b_yellow(GPIO_2, input);            //P922
BlackGPIO  b_red(GPIO_15, input);           //P924
BlackGPIO  b_blue(GPIO_14, input);          //P926
BlackGPIO reset(GPIO_49, input);             //P923


//DISPLAY 7 SEG:
BlackGPIO led_a(GPIO_65,output);//ok
BlackGPIO led_b(GPIO_61,output);//ok
BlackGPIO led_c(GPIO_20,output);//ok
BlackGPIO led_d(GPIO_60,output);//ok
BlackGPIO led_e(GPIO_31,output);//ok
BlackGPIO led_f(GPIO_4,output);//ok
BlackGPIO led_g(GPIO_5,output);//ok



//ADC:
ADC adc(AINx::AIN0);

#define MAX 3
int level=1, cont =0, maxLevel=9;
string sequence[MAX], user_sequence[MAX];
bool win=false, pressed=false;
double reactionTime;
float dutyCycle = 0;
//int period = 1000000000;

double time_answer=0;

//0 a 9 no display:

void zero(){
          cout << "level zero" << endl;
          //write 0 to the display
          led_a.setValue(low);
          led_b.setValue(low);
          led_c.setValue(low);
          led_d.setValue(low);
          led_e.setValue(low);
          led_f.setValue(low);
          led_g.setValue(high);
}

void one(){
          //write 1 to the display
          cout << "level one!" << endl;
          led_a.setValue(high);
          led_b.setValue(low);
          led_c.setValue(low);
          led_d.setValue(high);
          led_e.setValue(high);
          led_f.setValue(high);
          led_g.setValue(high);
}

void two(){
      //write 2 to the display
          cout << "level two!" << endl;
          led_a.setValue(low);
          led_b.setValue(low);
          led_c.setValue(high);
          led_d.setValue(low);
          led_e.setValue(low);
          led_f.setValue(high);
          led_g.setValue(low);
}

void three(){
//write 3 to the display
          cout << "level three!" << endl;
          led_a.setValue(low);
          led_b.setValue(low);
          led_c.setValue(low);
          led_d.setValue(low);
          led_e.setValue(high);
          led_f.setValue(high);
          led_g.setValue(low);
}

void four(){
        //write 4 to the display
          cout << "level four!" << endl;
          led_a.setValue(high);
          led_b.setValue(low);
          led_c.setValue(low);
          led_d.setValue(high);
          led_e.setValue(high);
          led_f.setValue(low);
          led_g.setValue(low);
}

void five(){
          cout << "level five" << endl;
          //write 5 to the display
          cout << "level 5" << endl;
          led_a.setValue(low);
          led_b.setValue(high);
          led_c.setValue(low);
          led_d.setValue(low);
          led_e.setValue(high);
          led_f.setValue(low);
          led_g.setValue(low);
}

void six(){
          cout << "level  six" << endl;
          //write 6 to the display
          led_a.setValue(low);
          led_b.setValue(high);
          led_c.setValue(low);
          led_d.setValue(low);
          led_e.setValue(low);
          led_f.setValue(low);
          led_g.setValue(low);
}

void seven(){
          cout << "level seven" << endl;
          //write 7 to the display
          led_a.setValue(low);
          led_b.setValue(low);
          led_c.setValue(low);
          led_d.setValue(high);
          led_e.setValue(high);
          led_f.setValue(high);
          led_g.setValue(high);
}

void eight(){
          cout << "level eight" << endl;
          //write 8 to the display
          led_a.setValue(low);
          led_b.setValue(low);
          led_c.setValue(low);
          led_d.setValue(low);
          led_e.setValue(low);
          led_f.setValue(low);
          led_g.setValue(low);
}

void nine(){
          cout << "level nine!" << endl;
          //write 9 to the display
          led_a.setValue(low);
          led_b.setValue(low);
          led_c.setValue(low);
          led_d.setValue(high);
          led_e.setValue(high);
          led_f.setValue(low);
          led_g.setValue(low);
}

void error(){
          cout << "error" << endl;
          led_a.setValue(low);
          led_b.setValue(high);
          led_c.setValue(high);
          led_d.setValue(low);
          led_e.setValue(low);
          led_f.setValue(low);
          led_g.setValue(low);
}

enum STATES{
          START,
          BLINK_LEDS,
          READ_USER,
          DISPLAY,
          FINAL,
}

typedef states;

void state_START(STATES &state){
          cout << "ARE YOU READY? PRESS START!" << endl;

          cout << "3 \n";
          sleep(1);
          cout << "2 \n";
          sleep(1);
          cout <<"1 \n";
          sleep(1);

          for (int i=0; i<MAX; i++){
                    sequence[i] = to_string(rand()%3+1);
          }

          //cout << "Duty before:" << dutyCycle << " \n";
          cout << "CHOOSE A LEVEL!\n" << endl;
          sleep(3);
          //cout << "Duty after: " << dutyCycle << "\n";

          if(time_answer == 5){
                    cout << "LEVEL HARD\n" << endl;
          }else if(time_answer == 7){
                    cout << "LEVEL MEDIUM\n" << endl;
          }else if(time_answer==10){
                    cout << "LEVEL EASY\n" << endl;
          }

          state = BLINK_LEDS;
}

void state_BLINK_LEDS(STATES &state){
          cout << "LEDS BLINKING" << endl;
          for(int i=0; i<MAX; i++){
                    if(sequence[i]=="1"){
                              yellow.setValue(high);
                              usleep(1000000);
                              yellow.setValue(low);
                    }else if(sequence[i]=="2"){
                              red.setValue(high);
                              usleep(1000000);
                               red.setValue(low);
                    }else if(sequence[i]=="3"){
                              blue.setValue(high);
                              usleep(1000000);
                              blue.setValue(low);
        }
  }
  state = READ_USER;
}

void state_READ_USER(STATES &state){
          cout << "Press the black button and then enter your answer" << endl;
          clock_t before, after;
          cont =0;
          while(!pressed){
                    if(reset.getValue() == "1"){
                              pressed = true;
                              cout << "Pressed! Value =  " << reset.getValue() << endl;
                              cout << "ENTER THE SEQUENCE" << endl;
                    }

          }

          sleep(1);

          while(pressed){
                    if(reset.getValue() == "1") {
                              cout << "ANSWER SAVED!" << endl;
                              pressed = false;
                              break;
          }

          before = clock();

          string by = b_yellow.getValue();
          string br = b_red.getValue();
          string bb = b_blue.getValue();

              if(by == "1"){
                user_sequence[cont] = "1";
                cout << "first" << user_sequence[cont] << endl;
                cont++;
                yellow.setValue(high);
                sleep(1);
                yellow.setValue(low);
                red.setValue(low);
                blue.setValue(low);
              }else if(br == "1"){
                user_sequence[cont] = "2";
                  cout << "second" << user_sequence[cont] << endl;
                cont++;
                red.setValue(high);
                 sleep(1);
                red.setValue(low);
                yellow.setValue(low);
                blue.setValue(low);
          }else if(bb == "1"){
                 cout << "third" << user_sequence[cont] << endl;
                user_sequence[cont] = "3";
                cont++;
                blue.setValue(high);
                sleep(1);
                blue.setValue(low);
                yellow.setValue(low);
                red.setValue(low);
          }
              after = clock();
          }

            reactionTime = 0;
            reactionTime =  (double)(after -before)/(double)CLOCKS_PER_SEC;
            state = DISPLAY;

}

void state_DISPLAY(STATES &state){
          cout << "NOW LETS CALCULATE YOUR RESULT!" << endl;
           cout << "Game sequence : " << endl;
          for(int i=0; i<MAX; i++){
                    cout << sequence[i] << endl;
          }
                    cout << "User sequence : " << endl;
          for(int i=0; i<MAX; i++){
                    cout << user_sequence[i] << endl;
          }

          for(int i=0; i<MAX; i++){
                    if(sequence[i] == user_sequence[i]){
                              win = true;
                    }else{
                              win = false;
                    break;
                    }
          }

          reactionTime = reactionTime*10000;

          if(win == true && reactionTime < time_answer){
                    cout << "CONGRATULATIONS! YOU WIN!" << endl;
                    cout << "Your time was: " << reactionTime << endl;
                    level++;
          }else{
                    cout << "You've failed! Try again!" << endl;
                    cout << "Your time was: " << reactionTime << endl;
          }
                    state = FINAL;
          }

void state_FINAL(STATES &state){

switch(level){
          case 1:
                    one();
          break;
          case 2:
                    two();
          break;
          case 3:
                    three();
          break;
          case 4:
                    four();
          break;
          case 5:
                    five();
          break;
          case 6:
                    six();
          break;
          case 7:
                    seven();
          break;
          case 8:
                    eight();
          break;
          case 9:
                    nine();
          break;
          default:
                    error();
          break;
}
  if(level > maxLevel){
    cout << "GAME OVER!" << endl;
    sleep(1);
    exit(0);
  }
  state = START;
}


int main(int argc, char * argv[]){
          srand(time(NULL));
          cout << "GENIUS GAME" << endl;
          states state;
          state = START;


          while(true){
                    dutyCycle = adc.getPercentValue();
                    //int period = 1000000000;

                    if(dutyCycle > 0.0 && dutyCycle <= 33.0){
                              time_answer = 5;
                    }else if(dutyCycle > 33.0 && dutyCycle <= 66.0){
                              time_answer = 7;
                    }else if(dutyCycle > 66.0 && dutyCycle <= 100.0){
                              time_answer = 10;
                    }

                    switch(state){
                              case START: state_START(state); break;
                              case BLINK_LEDS: state_BLINK_LEDS(state); break;
                              case READ_USER: state_READ_USER(state); break;
                              case DISPLAY: state_DISPLAY(state); break;
                              case FINAL: state_FINAL(state); break;
                    }
          }
                    return 0;
}
