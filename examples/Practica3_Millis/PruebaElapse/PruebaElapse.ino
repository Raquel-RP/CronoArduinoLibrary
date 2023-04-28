//////////////////////////////////////////////////////////////////////////
//
//  Modulo: Ejemplo del Cronometro de alta precision
//
//  Autor: J.A. Holgado
//  Ultima modificacion: 20/03/23
//  Plataforma: Arduino
//  Asignatura: Programacion de Sistemas Empotrados y de Tiempo Real
//  Departamento: Lenguaje y Sistemas Informatico
//  Universidad de Granada
//
//  Objetivo: Ejemplo sencillo del uso del cronometro de alta precision
//
//  Materiales:
//
//
///////////////////////////////////////////////////////////////////////////

#include "crono.h"

int count;
double tiempoMillis, tiempoMicros, tiempoSeconds;

//Definicion y creacion del cronometro
Crono cronometro;

void setup()
{
	count=0;
  //el cronometro se tiene que reiniciar
	cronometro.restart();
	Serial.begin(9600);
}

void loop()
{
	delay(2000); 
	tiempoMillis = cronometro.elapse2millis();
  tiempoMicros = cronometro.elapse2micros();
  tiempoSeconds = cronometro.elapse2seconds();
  cronometro.restart();
  Serial.print("Ciclo:");
  Serial.print(count);
  Serial.print("Tiempo transcurrido en ms:");
  Serial.print(tiempoMillis);
  Serial.print("Tiempo transcurrido en us:");
  Serial.print(tiempoMicros);
	Serial.print("Tiempo transcurrido en s:");
  Serial.print(tiempoSeconds);
	count=count+1;	
}
