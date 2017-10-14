#include "smartpark_sensor/ultrasonic.h"
#include "smartpark_sensor/smart_ultrasonic.h"
#include <alarm.h>
#include <gpio.h>
#include <utility/ostream.h>
#include <tsc.h>
#include <machine.h>
#include <thread.h>
#include <smart_data.h>

using namespace EPOS;

OStream cout;

int main(){
    GPIO    echo('A',0,GPIO::IN); // EXP1 3 - PA0 (UART RXD)
    GPIO trigger('A',1,GPIO::OUT); // EXP1 4 - PA1 (UART TXD)

    // create the ultrasonic sensor (low level)
    Ultrasonic ultrasonic(trigger, echo);

    // create the spot transducer
    Smartpark_Spot_Sensor spot_sensor(&ultrasonic);

    // create the smart data spot
    Smart_Data<spot_sensor> smart_spot(0, 1000000, Smartpark_Spot_Smart_Indicator::ADVERTISED);

    Thread::self()->suspend();

    return 0;
}
