#include <iostream>
#include "PWM/PWM.h"    //setPeriod(int period): void   setDutyCycle(int dc): void  setState(statePwm st): void (run, stop)
#include "ADC/Adc.h"    //getintvalue(), getfloatvalue(), getpercentvalue()
#include "unistd.h"
#include "BlackGPIO/BlackGPIO.h"

//pinos de alimentação:
/*
Usar o VDD_ADC(P9_32) e GND_ADC(P9_34)
*/

using namespace BlackLib;

int main(int argc, char * argv[])
{
    BlackGPIO digitalwrite(GPIO_15, output); //
    BlackGPIO digitalread(GPIO_66, input);

    //ADC:
    ADC adc(AINx::AIN0);

    //PWM:
    PWM pwm(P9_22);
    pwm.setState(statePwm::run);

    while(true){
        float dutyCycle = adc.getPercentValue();
        cout << "Duty: " << dutyCycle << "	";
        int period = 1000000000;
        pwm.setPeriod(period);
        pwm.setDutyCycle(dutyCycle*period/100.0);
	
	cout << "State PWM: " << pwm.getState() << " ";
	cout << "PWM: " << pwm.getDutyCycle() << "	";
	cout << "Led: " << digitalwrite.getValue() << "	";

        std::string val = digitalread.getValue();
        if(val=="1"){
            digitalwrite.setValue(high);
            std::cout << "i'm high" << endl;

        }else{
            digitalwrite.setValue(low);
            std::cout << "i'm low" << endl;
        }

    }

    return 0;
}
