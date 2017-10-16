#include "smartpark_sensor/ultrasonic.h"
#include "smartpark_sensor/spot_transducer.h"
#include <gpio.h>
#include <thread.h>

using namespace EPOS;

Ultrasonic * Smartpark_Spot_Transducer::ultrasonic;
GPIO * Smartpark_Spot_Transducer::led;

int main(){
    // ultrasonic pins
    GPIO    echo('A',0,GPIO::IN); // EXP1 3 - PA0 (UART RXD)
    GPIO trigger('A',1,GPIO::OUT); // EXP1 4 - PA1 (UART TXD)

    // // create the ultrasonic sensor (low level)
    Ultrasonic ultrasonic(trigger, echo);

    // set the device this ultrasonic sensor
    GPIO led('C',3, GPIO::OUT);
    Smartpark_Spot_Transducer::led = &led;
    Smartpark_Spot_Transducer::ultrasonic = &ultrasonic;

    // create the spot smart data on the device
    new Smartpark_Spot_Smart_Data(0, 1000000, Smartpark_Spot_Smart_Data::ADVERTISED);

    Thread::self()->suspend();

    return 0;
}
