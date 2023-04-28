//////////////////////////////////////////////////////////////////////////
//
//  Modulo: Implementacion del Cronometro de alta precision
//
//  Autor: J.A. Holgado
//  Ultima modificacion: 20/03/23
//  Plataforma: Arduino
//  Asignatura: Programacion de Sistemas Empotrados y de Tiempo Real
//  Departamento: Lenguaje y Sistemas Informatico
//  Universidad de Granada
//
//  Objetivo: Programacion de un cronometro de alta precision
//
//  Materiales:
//
//
///////////////////////////////////////////////////////////////////////////

//Necesario para cargar las definiciones basicas de Arduino
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

//Definicion de crono
#include "crono2.h"

/////////////////////////////////////////////
//Constructor por defecto
Crono::Crono(int precision) {
	_precision = precision;
    // Start.
	restart(); // ó this->restart();
}

int Crono::getPrecision(){
    return _precision;
}

bool Crono::isActive(){
  return _isActive;
}

void Crono::restart(){
    if(getPrecision() == 1){
        _startTime = millis();
    }
    else{
        _startTime = micros();
    }
  _stopTime = _startTime;
  _isActive = true;
}


double Crono::elapse2millis(){
    if(getPrecision() == 1){
        return millis() - _startTime;
    }
    else{
        return micros()/1000 - _startTime/1000;
    } 
}

double Crono::elapse2micros(){
  double elapseTimeMicros;
  
  if(getPrecision() == 1){
        elapseTimeMicros = elapse2millis()*1000;
    }
    else{
        elapseTimeMicros = micros() - _startTime;
    } 

  return elapseTimeMicros;
}

double Crono::elapse2seconds(){
  double elapseTimeSeconds;

  elapseTimeSeconds = elapse2millis()/1000;

  return elapseTimeSeconds;
}

double Crono::stop2millis(){
  if (_isActive){
    if(getPrecision() == 1){
        _stopTime = millis() - _startTime;
    }
    else{
        _stopTime = micros()/1000 - _startTime/1000;
    }
    _isActive = false;
  }
  return _stopTime;
}

double Crono::stop2micros(){
  stop2millis();
    if(getPrecision() == 1){
        return _stopTime*1000;
    }
    else{
        return _stopTime;
    }
}

double Crono::stop2seconds(){
  stop2millis();
  if(getPrecision() == 1){
        return _stopTime/1000;
    }
    else{
        return _stopTime/1000000;
    }
}

bool Crono::hasPassedMillis(double timeout){
  bool timeOff = false;
  if (elapse2millis() >= timeout){
        timeOff = true;
  }
  return timeOff;
}

bool Crono::hasPassedMillis(unsigned long timeout){
  bool timeOff = false;
  if (elapse2millis() >= (double) timeout){
        timeOff = true;
  }
  return timeOff;
}

bool Crono::hasPassedSeconds(double timeout){
  bool timeOff = false;
  if (elapse2seconds() >= timeout){
        timeOff = true;
  }
  return timeOff;
}

bool Crono::hasPassedSeconds(unsigned long timeout){
  bool timeOff = false;
  if (elapse2seconds() >= (double) timeout){
        timeOff = true;
  }
  return timeOff;
}

bool Crono::hasPassedMillis(double timeout, bool restartIfPassed){
  bool timeOff = hasPassedMillis(timeout);
  if (timeOff && restartIfPassed){
      restart();
  }
  return timeOff;
}

bool Crono::hasPassedMillis(unsigned long timeout, bool restartIfPassed){
  bool timeOff = hasPassedMillis(timeout);
  if (timeOff && restartIfPassed){
      restart();
  }
  return timeOff;
}

bool Crono::hasPassedSeconds(double timeout, bool restartIfPassed){
  bool timeOff = hasPassedSeconds(timeout);
  if (timeOff && restartIfPassed){
      restart();
  }
  return timeOff;
}

bool Crono::hasPassedSeconds(unsigned long timeout, bool restartIfPassed){
  bool timeOff = hasPassedSeconds(timeout);
  if (timeOff && restartIfPassed){
      restart();
  }
  return timeOff;
}

void Crono::waitMillis(double timeout){
  delay(timeout);
}

void Crono::waitMillis(unsigned long timeout){
  delay(timeout);
}

void Crono::waitMillisuntil(double timeout){
  while(!hasPassedMillis(timeout));
}

void Crono::waitMillisuntil(unsigned long int timeout){
  while(!hasPassedMillis(timeout));
}


