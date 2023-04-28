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

//double tiempoMillis = 300;
//double tiempoSeconds = 3;
//unsigned long tiempoMillisLong = 300;
//unsigned long tiempoSecondsLong = 3;

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

  Serial.print("Ciclo:");
  Serial.print(count);

  Serial.print("Han pasado 300 ms:");
  Serial.print(cronometro.hasPassedMillis((double)300));
  Serial.print(cronometro.hasPassedMillis((unsigned long) 300));

  Serial.print("Han pasado 200 ms:");
  Serial.print(cronometro.hasPassedMillis((double)200));
  Serial.print(cronometro.hasPassedMillis((unsigned long) 200));

  Serial.print("Han pasado 3 s:");
  Serial.print(cronometro.hasPassedMillis((double)3));
  Serial.print(cronometro.hasPassedMillis((unsigned long) 3));

  Serial.print("Han pasado 2 s:");
  Serial.print(cronometro.hasPassedMillis((double)2));
  Serial.print(cronometro.hasPassedMillis((unsigned long) 2));

  cronometro.restart();

	count=count+1;	
}
