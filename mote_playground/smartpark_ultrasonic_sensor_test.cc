#include "smartpark_sensor/ultrasonic_sensor_controller.h"
#include <alarm.h>
#include <gpio.h>
#include <utility/ostream.h>

using namespace EPOS;

OStream cout;

int main(){
    GPIO echo('A',1,GPIO::IN); // EXP1 4
    GPIO trigger('A',0,GPIO::OUT); // EXP1 3

    Ultrasonic_Sensor_Controller controller(trigger,echo);

    //Alarm::delay(10000000); // time to initialize the ultrasonic sensor
    cout << "starting the reads!!" << endl;
    while(1){
        int s = controller.sense();
        cout << "distance: " << s << endl;
        Alarm::delay(10000000 / 5);
    }

    // blink led no id_sender.cc
    // Machine::id()

    return 0;
}
