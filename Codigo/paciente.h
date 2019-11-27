#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>
#include <list>

using std::istream;
using std::ostream;
using std::list;
using std::string;





class Paciente{

	private:

		string nombre_;
		string apellidos_;
		int edad_;
		double telefono_;
		float peso_;
		float altura_;

	public:

		Paciente(string, string, int = 0, double = 0, float = 0, float = 0);
		~Paciente();
		friend ostream &operator<<(ostream &stream, const Paciente &p);
		friend istream &operator>>(istream &stream, Paciente &p);
		inline void setNombre(string nombre){nombre_ = nombre;}
		inline void setApellidos(string apellidos){apellidos_ = apellidos;}
		inline void setEdad(int edad){edad_ = edad;}
		inline void setTelefono(double telefono){telefono_ = telefono;}
		inline void setPeso(float peso){peso_ = peso;}
		inline void setAltura(float altura){altura_ = altura;}
		inline string getNombre() const {return nombre_;}
		inline string getApellidos() const {return apellidos_;}
		inline int getEdad() const {return edad_;}
		inline double getTelefono() const {return telefono_;}
		inline float getPeso() const {return peso_;}
		inline float getAltura() const {return altura_;}

};

#endif
