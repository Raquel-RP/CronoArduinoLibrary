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
double tiempoSeconds, tiempo1;

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

	tiempoSeconds = cronometro.stop2seconds();
  tiempo1 = cronometro.stop2seconds();

  Serial.print("Cronometro activo:");
  Serial.print(cronometro.isActive());

  Serial.print("Tiempo transcurrido en us:");
  Serial.print(tiempoSeconds);
  
  Serial.print("Tiempo transcurrido en us, segunda vez:");
  Serial.print(tiempo1);

  cronometro.restart();

	count=count+1;	
}
