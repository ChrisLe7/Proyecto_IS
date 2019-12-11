//NO ESTA COMPILADO
// NO SE HAN HECHO LAS PRUEBAS
#ifndef HISTORIAL_H
#define HISTORIAL_H 

#include <fstream>
#include <string>

using std::string;


struct RegH{

	char fecha[20];
	char motivo [50];
	
};
class Historial{

	private:

		string fecha_;
		string motivo_;

	public:

		Historial(string fichero);
		~Historial() {}
		void Historial::Mostrar (string fichero) ;
		void Historial::Aniadir (string fichero) ;
		inline string getFecha() const {return fecha_;}
		inline string getMotivo() const {return motivo_;}
		inline void setFecha(string fecha) {fecha_  = fecha ;}
		inline void setMotivo(string motivo) {motivo_ = motivo;}
		
		RegH getRegH () ;
		void setRegH (RegH r) ;
};

#endif