/*
Escrito por Ricardo Fritsche
*/

#ifndef SMART_ULTRASONIC_H
#define SMART_ULTRASONIC_H

#include "ultrasonic.h"

using namespace EPOS;

class Smartpark_Spot_Sensor
{
  static const unsigned int ERROR = 0;
  static const unsigned int TAKEN = 10;
  static const unsigned int FREE  = 20;

  static const unsigned float TAKEN_VALUE = 15.0; // 15 centimetros

public:
    typedef _UTIL::Observed Observed;
    typedef _UTIL::Observer Observer;

    static const unsigned int UNIT = TSTP::Unit::Length;
    static const unsigned int NUM = TSTP::Unit::I32;
    static const int ERROR = 0;

    static const bool INTERRUPT = false;
    static const bool POLLING = true;

public:
    Smartpark_Spot_Sensor(Ultrasonic * ultrasonic) : _ultrasonic(ultrasonic) {

    }

    static void sense(Smart_Data<Smartpark_Spot_Sensor> * data) {
        float s = _ultrasonic->sense();

        if (s < 1.0) {
          // cout << "Erro ao realizar leitura do sensor (" << s << " cm)" << endl;
          data->_value = ERROR;
        } else if (s < TAKEN_VALUE) {
          // cout << "Vaga OCUPADA :( (" << s << " cm)" << endl;
          data->_value = TAKEN;
        } else {
          // cout << "Vaga LIVRE :) (" << s << " cm)" << endl;
          data->_value = FREE;
        }
    }

    static void actuate(Smart_Data<Smartpark_Spot_Sensor> * data, const Smart_Data<Smartpark_Spot_Sensor>::Value & command) {}

    static void attach(Observer * obs) {}
    static void detach(Observer * obs) {}

private:
    Ultrasonic * _ultrasonic;
};

// typedef Smart_Data<Smartpark_Spot_Sensor> Smartpark_Spot_Smart_Indicator;

#endif // SMART_ULTRASONIC_H
