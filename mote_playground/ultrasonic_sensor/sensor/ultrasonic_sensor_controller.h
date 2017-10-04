#ifndef ultrasonic_sensor_controller_hdr
#define ultrasonic_sensor_controller_hdr

#include "ultrasonic_sensor_hcsr04.h"

using namespace EPOS;

class Ultrasonic_Sensor_Controller{
protected:

    enum Sample_strategy{
        NUMBER_OF_READS = 4, // arbitrary and intentionally multiple of a potency of 2
        INTERVAL_BETWEEN_READS = 60000, //60ms recommended by datasheet
    };

    Ultrasonic_Sensor_HC_SR04 _sensor;

public:
    typedef Ultrasonic_Sensor_HC_SR04::Sense Sense;
    typedef void (*Sense_Callback)(Sense) ;
    typedef unsigned int (*Sense_Callback_Dynamic)(Sense);

    Ultrasonic_Sensor_Controller(GPIO trigger,GPIO echo) : _sensor(trigger,echo){
      // constructor
    }

    int sense(){
        return evaluate_strategy();
    }

    void sense(unsigned int interval, unsigned int times, Sense* const values){
        for(int i = 0; i < times; ++i){
            values[i] = evaluate_strategy();
            Machine::delay(interval);
        }
    }

    void sense(unsigned int interval, Sense_Callback f){
        while(1){
            f(evaluate_strategy());
            Machine::delay(interval);
        }
    }

    void sense(Sense_Callback_Dynamic f){
        while(1){
            Machine::delay(f(evaluate_strategy()));
        }
    }

protected:

    //The simplest and naive sample strategy is a simple forward to the sensor method.
    int evaluate_strategy(){
        return _sensor.sense();
    }

    /*
    Sense evaluate_strategy(){
        Sense ret = 0;

        for(int i = 0; i < Sample_strategy::NUMBER_OF_READS; ++i){
            Sense sense = _sensor.sense();
            ret += (sense == -1)? 0 : sense;
            Machine::delay(Sample_strategy::INTERVAL_BETWEEN_READS);
        }

        return ret/Sample_strategy::NUMBER_OF_READS;
    }
    */
};

#endif
