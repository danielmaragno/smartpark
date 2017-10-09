/*
Escrito por Ricardo Fritsche
*/

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <gpio.h>
#include <tsc.h>
#include <timer.h>
#include <utility/ostream.h>

using namespace EPOS;

OStream usout;

class Ultrasonic
{
  public:
    Ultrasonic(GPIO tp, GPIO ep) : _trigPin(tp), _echoPin(ep) {
      _trigPin.direction(GPIO::OUT);
      _echoPin.direction(GPIO::IN);
    }

    unsigned long triggerAndListen() {
      TSC::Time_Stamp t0, t1;
      long ellapsedTime;
      TSC::Hertz freq = TSC::frequency();
      unsigned long timeout = 2000000;

      // trigger the ultrasonic sensor to send the pulses
      _trigPin.set(false);
      Machine::delay(50); // 50 microseconds to clear signals
      _trigPin.set(true);
      Machine::delay(10); // 10 microseconds (us)
      _trigPin.set(false);

      // enquanto o sinal inativo, vamos aguardar para iniciar
      t0 = TSC::time_stamp();
      ellapsedTime = 0;
      while ( ! _echoPin.get() && ellapsedTime < timeout) {
        t1 = TSC::time_stamp();
        ellapsedTime = t1 - t0;
      }

      if (ellapsedTime >= timeout) {
        // usout << "timeout enquanto esperava o sinal iniciar: " << ellapsedTime << endl;
        return 0;
      }

      // enquanto o sinal for ativo, podemos contar o tempo
      t0 = TSC::time_stamp();
      ellapsedTime = 0;
      while (_echoPin.get() && ellapsedTime < timeout) {
        t1 = TSC::time_stamp();
        ellapsedTime = t1 - t0;
      }

      if (ellapsedTime >= timeout) {
        // usout << "timeout enquanto esperava o sinal acabar: " << ellapsedTime << endl;
        return 0;
      }

      return ellapsedTime / (freq/1000000);
    }

    float sense() {
      return triggerAndListen() / 27.6233 / 2.0;
    }

  private:
    GPIO _trigPin;
    GPIO _echoPin;
};

#endif // ULTRASONIC_H
