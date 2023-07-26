# Librería de Cronómetro para Arduino

Cronómetro de alta precisión para sistemas Arduino para la asignatura Programación de Sistema Empotrados y de Tiempo Real

## Comenzando 🚀

Estas instrucciones te permitirán obtener una copia del proyecto en funcionamiento en tu máquina local para propósitos de desarrollo y pruebas.

Mira **Deployment** para conocer como desplegar el proyecto.


### Pre-requisitos 📋

Para la instalación no será necesario ningún software específico
Sin embargo, para ejecución será necesario tener a disposición una placa Arduino junto con el software Arduino

```
https://www.arduino.cc/en/software
```

### Instalación 🔧

Descarga el repositorio como ZIP con el siguiente enlace

```
https://github.com/Raquel-RP/CronoArduinoLibrary/archive/refs/heads/main.zip
```

Una vez descargado, conel software Arduino abierto, ve al apartado Sketch > Include Library >  Add .ZIP Library
Selecciona la capteza .ZIP recién descargada y espera la instalación correcta.

## Ejecutando las pruebas ⚙️

Con la librería ya incluida ya podrá usar los ejemplos que vienen incluídos en ella.
Para ello seleccione el ejemplo que quiera emplear desde el apartado _File > Examples > Crono > {ejemplo a elegir}_

### Uso de la librería ⌨️

Finalmente para usar la librería en cualquier código, será suficiente con incluirla al inicio del programa y crear un objeto de esta.
Tener en cuenta que el objeto tendrá como parámetro 0 para medir con la función micros() o 1 para medir con la función millis().

```
// Incluir librería
#include "crono2.h"

//Creación del objeto
Crono cronometro(0);
```
## Funciones principales 🛠️

Las principales funciones de esta librería se resumen con los siguientes métodos:

* elapse2millis - Intervalo de tiempo en milisegundos transcurrido sin parar crono. 
* stop2millis - Para el cronómetro y devuelve el tiempo transcurrido en milisegundos. 
* hasPassedMillis - Devuelve si ha transcurrido un cierto tiempo de timeout.
* waitMillis - Espera hasta que haya pasado un tiempo específico.
* waitMillisuntil - Espera hasta que haya transcurrido un cierto tiempo absoluto desde que se arracncó el crono.
 
_Variaciones: tiempo en microsegundos y segundos._


## Autores ✒️

* **Raquel Romero Pedraza** - [Raquel-RP](https://github.com/Raquel-RP)
* **Mariam Rahoutei César** 

