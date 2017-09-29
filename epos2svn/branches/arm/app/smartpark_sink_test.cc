#define HCSR04_RELAY

#include "ultrasonic_sensor/sensor/ultrasonic_sensor_controller.h"
#include <alarm.h>
#include <gpio.h>
#include <utility/ostream.h>

using namespace EPOS;

OStream cout;

int main(){
    // GPIO echo('C',7,GPIO::IN); // EXP2 5
    // GPIO trigger('C',6,GPIO::OUT); // EXP2 4
    // GPIO relay('B',3,GPIO::OUT);

    // Ultrasonic_Sensor_Controller controller(relay,trigger,echo);

    // Alarm::delay(10000000); // time to initialize the ultrasonic sensor
    // cout << "starting the reads!!" << endl;
    while(1) {
      
        int s = 0;
        cout << s << endl;
        Alarm::delay(1000000);
    }

    return 0;
}
