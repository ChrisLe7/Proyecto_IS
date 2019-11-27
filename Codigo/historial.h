//NO ESTA COMPILADO
#ifndef HISTORIAL_H
#define HISTORIAL_H 

#include <fstream>
#include <string>

using std::string;

class Historial{

	private:

		string fecha_;
		string motivo_;

	public:

		Historial(string fichero);
		~Historial();
		void Historial::Mostrar (string fichero) ;
		void Historial::Aniadir (string fichero) ;
		inline string getFecha() const {return fecha_;}
		inline string getMotivo() const {return motivo_;}

};

#endif