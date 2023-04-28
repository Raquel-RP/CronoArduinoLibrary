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
#include "crono.h"

/////////////////////////////////////////////
//Constructor por defecto
Crono::Crono() {
	// Start.
	restart(); // ó this->restart();
}

void Crono::restart(){
  _startTime = millis();
  _stopTime = _startTime;
  _isActive = true;
}

bool Crono::isActive(){
  return _isActive;
}

double Crono::elapse2millis(){
  return millis() - _startTime;
}

double Crono::elapse2micros(){
  double elapseTimeMicros;
  elapseTimeMicros = elapse2millis()*1000;

  return elapseTimeMicros;
}

double Crono::elapse2seconds(){
  double elapseTimeSeconds;
  elapseTimeSeconds = elapse2millis()/1000;

  return elapseTimeSeconds;
}

double Crono::stop2millis(){
  if (_isActive){
    _stopTime = millis() - _startTime;
    _isActive = false;
  }
  return _stopTime;
}

double Crono::stop2micros(){
  stop2millis();
  return _stopTime*1000;
}

double Crono::stop2seconds(){
  stop2millis();
  return _stopTime/1000;
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


