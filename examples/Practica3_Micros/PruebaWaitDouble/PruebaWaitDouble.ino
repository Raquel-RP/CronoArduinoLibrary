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

#include "crono2.h"

int count, tiempoMillis, tiempoMillis2;

//double tiempoMillis = 300;
//double tiempoSeconds = 3;
//unsigned long tiempoMillisLong = 300;
//unsigned long tiempoSecondsLong = 3;

//Definicion y creacion del cronometro
Crono cronometro(0);;

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

  Serial.print("\nCiclo:");
  Serial.print(count);

  tiempoMillis = cronometro.elapse2millis();
  cronometro.waitMillis((unsigned long)200);
  tiempoMillis2 = cronometro.elapse2millis();

  Serial.print("\nTiempo antes de la espera:");
  Serial.print(tiempoMillis);
  Serial.print("\nTiempo despues de la espera:");
  Serial.print(tiempoMillis2);
 
  cronometro.restart();

	count=count+1;	
}
