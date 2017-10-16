/*
Escrito por Ricardo Fritsche
*/

#ifndef SPOT_TRANSDUCER_H
#define SPOT_TRANSDUCER_H

#include <smart_data.h>
#include <utility/observer.h>
#include <tstp.h>
#include <utility/ostream.h>
#include <gpio.h>
#include "ultrasonic.h"

using namespace EPOS;

OStream cout;

class Smartpark_Spot_Transducer
{
  public:
    static const unsigned int MAX_DEVICES = 4;

    static const unsigned int SMARTPARK_ERROR = 0;
    static const unsigned int SMARTPARK_TAKEN = 10;
    static const unsigned int SMARTPARK_FREE  = 20;
    static const float SMARTPARK_TAKEN_VALUE = 15.0; // 15

    typedef _UTIL::Observed Observed;
    typedef _UTIL::Observer Observer;

    static const unsigned int UNIT = TSTP::Unit::Length;
    static const unsigned int NUM = TSTP::Unit::I32;
    static const int ERROR = 0;

    static const bool INTERRUPT = false;
    static const bool POLLING = true;

    Smartpark_Spot_Transducer(unsigned int dev) {}

    static void sense(unsigned int dev, Smart_Data<Smartpark_Spot_Transducer> * data) {
        float s = Smartpark_Spot_Transducer::ultrasonic->sense();
        GPIO led = *Smartpark_Spot_Transducer::led;
        // float s = 0.0;
        if (s < 1.0) {
          cout << "Erro ao realizar leitura do sensor (" << s << " cm)" << endl;
          data->_value = SMARTPARK_ERROR;
          led.set(false);
        } else if (s < SMARTPARK_TAKEN_VALUE) {
          cout << "Vaga OCUPADA :( (" << s << " cm)" << endl;
          data->_value = SMARTPARK_TAKEN;
          led.set(false);
        } else {
          cout << "Vaga LIVRE :) (" << s << " cm)" << endl;
          data->_value = SMARTPARK_FREE;
          led.set(true);
        }
    }

    static void actuate(unsigned int dev, Smart_Data<Smartpark_Spot_Transducer> * data, const Smart_Data<Smartpark_Spot_Transducer>::Value & command) {}

    static void attach(Observer * obs) { /*_observed.attach(obs);*/ }
    static void detach(Observer * obs) { /*_observed.detach(obs);*/ }

    static Ultrasonic * ultrasonic;
    static GPIO * led;

  // private:
  //   static Observed _observed;
};

typedef Smart_Data<Smartpark_Spot_Transducer> Smartpark_Spot_Smart_Data;

#endif // SPOT_TRANSDUCER_H
