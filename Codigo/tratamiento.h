//NO ESTA COMPILADO
// NO SE HAN HECHO LAS PRUEBAS
#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H

#include <string>
#include <iostream>

using namespace std;

struct RegT{

	char fechainicio[20];
	char fechafinalizacion[20];
	char receta [50];
	
};

class Tratamiento{

	private:

		string fechainicio_;
		string fechafinalizacion_;
		string receta_;
		
	public:

		Tratamiento();
		~Tratamiento() {}
		inline string getFechainicio() const {return fechainicio_;}
		inline string getFechafinacilizacion() const {return fechafinalizacion_;}
		inline string getReceta() const {return receta_;}
		inline void setFechainicio(string fechainicio)  {fechainicio_ = fechainicio;}
		inline void setFechafinacilizacion(string fechafinalizacion)  {fechafinalizacion_ = fechafinalizacion;}
		inline void setReceta(string receta) {receta_  = receta;}
		void setRegT(RegT r);
		RegT getRegT() const;
		void Mostrar(string nombre);
		void Anidir(string nombre);
		void Finalizar(string nombre);  

};

#endif