#include "smartpark_sensor/ultrasonic.h"
#include <alarm.h>
#include <gpio.h>
#include <utility/ostream.h>
#include <tsc.h>

using namespace EPOS;

OStream cout;

int main(){
    GPIO    echo('A',0,GPIO::IN); // EXP1 3 - PA0 (UART RXD)
    GPIO trigger('A',1,GPIO::OUT); // EXP1 4 - PA1 (UART TXD)

    Ultrasonic ultrasonic(trigger, echo);

    TSC::Time_Stamp t0, t1;

    t0 = TSC::time_stamp();

    unsigned long ellapsedTime = 0;
    unsigned long freq = TSC::frequency();

    while(1){
        float s = ultrasonic.sense();

        if (s < 1.0) {
          cout << "Erro ao realizar leitura do sensor (" << s << " cm)" << endl;
        } else if (s < 15.0) {
          // 15 centimetros (para testes)
          cout << "Vaga OCUPADA :( (" << s << " cm)" << endl;
        } else {
          cout << "Vaga LIVRE :) (" << s << " cm)" << endl;
        }

        // @todo: transmitir via TSTP se o estado da vaga for diferente do anterior

        Alarm::delay(1000000);
    }

    return 0;
}
