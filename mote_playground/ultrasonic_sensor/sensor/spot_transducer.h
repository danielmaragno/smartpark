/*
Escrito por Ricardo Fritsche
*/

#ifndef SPOT_TRANSDUCER_H
#define SPOT_TRANSDUCER_H

#include <utility/observer.h>
#include <smart_data.h>
#include <transducer.h>
#include <tstp.h>
#include "ultrasonic.h"

using namespace EPOS;

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

    Smartpark_Spot_Transducer() {}

    static void sense(unsigned int dev, Smart_Data<Smartpark_Spot_Transducer> * data) {
        float s = ultrasonic[dev]->sense();

        if (s < 1.0) {
          // cout << "Erro ao realizar leitura do sensor (" << s << " cm)" << endl;
          data->_value = SMARTPARK_ERROR;
        } else if (s < SMARTPARK_TAKEN_VALUE) {
          // cout << "Vaga OCUPADA :( (" << s << " cm)" << endl;
          data->_value = SMARTPARK_TAKEN;
        } else {
          // cout << "Vaga LIVRE :) (" << s << " cm)" << endl;
          data->_value = SMARTPARK_FREE;
        }
    }

    static void actuate(unsigned int dev, Smart_Data<Smartpark_Spot_Transducer> * data, const Smart_Data<Smartpark_Spot_Transducer>::Value & command) {}

    static void attach(Observer * obs) { /*_observed.attach(obs);*/ }
    static void detach(Observer * obs) { /*_observed.detach(obs);*/ }

    static Ultrasonic * ultrasonic[MAX_DEVICES];

  // private:
  //   static Observed _observed;
};

typedef Smart_Data<Smartpark_Spot_Transducer> Smartpark_Spot_Smart_Data;

#endif // SPOT_TRANSDUCER_H
