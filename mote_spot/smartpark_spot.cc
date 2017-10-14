#include "smartpark_sensor/ultrasonic.h"
#include "smartpark_sensor/spot_transducer.h"
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
    // ultrasonic pins
    GPIO    echo('A',0,GPIO::IN); // EXP1 3 - PA0 (UART RXD)
    GPIO trigger('A',1,GPIO::OUT); // EXP1 4 - PA1 (UART TXD)

    // create the ultrasonic sensor (low level)
    Ultrasonic ultrasonic(trigger, echo);

    // set the device 0 to this ultrasonic sensor
    Distance_Sensor::_ultrasonic[0] = &ultrasonic;

    // create the spot smart data
    Smartpark_Spot_Smart_Data spot_smart_data(0, 1000000, Smartpark_Spot_Smart_Data::ADVERTISED);

    Thread::self()->suspend();

    return 0;
}
