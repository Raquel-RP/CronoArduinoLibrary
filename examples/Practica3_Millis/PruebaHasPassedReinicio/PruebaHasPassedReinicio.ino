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
	delay(4000); 

  Serial.print("\nCiclo:");
  Serial.print(count);

  Serial.print("\nHan pasado 3000 ms:");
  Serial.print(cronometro.hasPassedMillis((double)3000));
  Serial.print("\n");
  Serial.print(cronometro.hasPassedMillis((unsigned long) 300));
  Serial.print("\n");
  Serial.print(cronometro.elapse2millis());
  Serial.print("\n");

  Serial.print("\nHan pasado 2000 ms:");
  Serial.print(cronometro.hasPassedMillis((double)2000));
   Serial.print("\n");

  Serial.print(cronometro.hasPassedMillis((unsigned long) 200));
   Serial.print("\n");

  Serial.print(cronometro.elapse2millis());
   Serial.print("\n");


  Serial.print("\nHan pasado 4 s:");
  Serial.print(cronometro.hasPassedMillis((double)4));
   Serial.print("\n");

  Serial.print(cronometro.hasPassedMillis((unsigned long) 4));
   Serial.print("\n");

  Serial.print(cronometro.elapse2seconds());
   Serial.print("\n");

  cronometro.restart();

	count=count+1;	
}
