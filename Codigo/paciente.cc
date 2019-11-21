#include <iostream>
#include <string>
#include "paciente.h"

using std::ostream;
using std::endl;
using std::string;

Paciente::Paciente(string nombre, string apellidos, int edad, double telefono, float peso, float altura){

	nombre_ = nombre;
	apellidos_ = apellidos;
	edad_ = edad;
	telefono_ = telefono;
	peso_ = peso;
	altura_ = altura;

}

Paciente::~Paciente(){}

ostream &operator<<(ostream &stream, const Paciente &p){

	stream<<"Nombre: "<<p.getNombre()<<endl;
	stream<<"Apellidos: "<<p.getApellidos()<<endl;
	stream<<"Edad: "<<p.getEdad()<<endl;
	stream<<"Telefono: "<<p.getTelefono()<<endl;
	stream<<"Peso: "<<p.getPeso()<<endl;
	stream<<"Altura: "<<p.getAltura()<<endl;
	return stream;

}

