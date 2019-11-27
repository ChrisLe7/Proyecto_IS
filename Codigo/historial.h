//NO ESTA COMPILADO

#include <fstream> 
#include <iostream>

#ifndef HISTORIAL_H
#define HISTORIAL_H 

class Historial
{
private:
	 string fecha_;
	 string motivo_;
public:
	Historial(string fichero);
	~Historial();
	void Historial::Mostrar (string fichero) ;
	void Historial::Aniadir (string fichero) ;
	inline string getFecha () {return fecha_;}
	inline string getMotivo () {return motivo_;}
};
#endif