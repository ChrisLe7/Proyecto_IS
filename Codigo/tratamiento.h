//NO ESTA COMPILADO

#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H

#include <string>

using std::string;

class Tratamiento{

	private:

		string fechainicio_;
		string fechafinalizacion_;
		string receta_;
		
	public:

		Tratamiento();
		~Tratamiento();
		inline string getFechainicio() const {return fechainicio_;}
		inline string getFechafinacilizacion() const {return fechafinalizacion_;}
		inline string getReceta() const {return receta_;}
		void Mostrar(string nombre);
		void Anidir(string nombre);
		void Finalizar(string nombre);  

};

#endif