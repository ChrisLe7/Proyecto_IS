#include <string>
#include "paciente.h"

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
