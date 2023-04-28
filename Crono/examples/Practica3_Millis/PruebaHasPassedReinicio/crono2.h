//////////////////////////////////////////////////////////////////////////
//
//  Modulo: cronometro de alta precision
//
//  Autor: J.A. Holgado
//  Ultima modificacion: 27/03/20
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

//Definiciones basicas
#ifndef crono_h
#define crono_h
#ifdef __cplusplus

class Crono
{
	
	private:
	unsigned long _startTime; // marca de tiempo de referencia
	unsigned long _stopTime;  //marca de tiempo de parada
	bool _isActive;
    int _precison;
	
	public:
	/// Constructor.
	Crono(int precision);
	
	//registra la referencia de tiempo
	void restart();
	
	//en ejecucion
	bool isActive();
	
    //precisión del crono
    int getPrecision();
	/////////////////////////////////////////////////////////////
	// Funciones de parada temporal del cronometro
	
	// Devuelve el intervalo de tiempo transcurrido en millis sin parar cronometro
	double elapse2millis();	
	
	// Devuelve el intervalo de tiempo transcurrido en micros sin parar cronometro
	double elapse2micros();
	
	// Devuelve el intervalo de tiempo transcurrido en micros sin parar cronometro
	double elapse2seconds();
	
	// Devuelve el intervalo de tiempo transcurrido en micros parando el cronometro
	double stop2micros();
	
	// Devuelve el intervalo de tiempo transcurrido en micros parando el cronometro
	double stop2millis();
	
	// Devuelve el intervalo de tiempo transcurrido en micros parando el cronometro
	double stop2seconds();
	
	////////////////////////////////////////////////////////////
	// Funciones de timeout
	
	/// Devuelve true si ha transcurrido un cierto tiempo timeout
	bool hasPassedMillis(double timeout);
	bool hasPassedMillis(unsigned long timeout);
	
	bool hasPassedSeconds(double timeout);
	bool hasPassedSeconds(unsigned long timeout);
	
	//Devuelve true si ha transcurrido un cierto tiempo timeout y 
	//posibilita el arranque del cronometro
	bool hasPassedMillis(double timeout, bool restartIfPassed);
	bool hasPassedMillis(unsigned long timeout, bool restartIfPassed);
	
	bool hasPassedSeconds(double timeout, bool restartIfPassed);
	bool hasPassedSeconds(unsigned long timeout, bool restartIfPassed);


	//Espera hasta que transcurra un tiempo relativo
	void waitMillis(double timeout);
	void waitMillis(unsigned long timeout);

	//Espera hasta que transcurra un tiempo absoluto desde que 
	//arrancó el cronometro
	void waitMillisuntil(double timeout);
	void waitMillisuntil(unsigned long int timeout);
	
};

#endif // __cplusplus
#endif // crono_h
