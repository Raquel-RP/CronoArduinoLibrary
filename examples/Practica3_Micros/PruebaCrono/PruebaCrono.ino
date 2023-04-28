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
double tiempo, tiempo1, tiempo2;

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
	tiempo = cronometro.stop2millis();
  tiempo1 = cronometro.stop2millis();
  cronometro.restart();
  delay(2000);
  tiempo2 = cronometro.elapse2millis();
  Serial.print("Activacion ");
  Serial.print(count);
  Serial.print(" = ");
  Serial.print("Stop time 1 = ");
	Serial.println(tiempo);
  Serial.print("Stop time 2 = ");
  Serial.println(tiempo1);
  Serial.print("Tiempo de reactivación = ");
  Serial.println(tiempo2);
	count=count+1;	
}
