#include <iostream>
#include <string>
#include <cstdio>
#include "paciente.h"

using std::istream;
using std::ostream;
using std::cout;
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

istream &operator>>(istream &stream, Paciente &p){

	string nombre, apellidos;
	int edad;
	double telefono;
	float peso, altura;
	char SN;	//Opcion que indica si quiere o no introducir el resto de datos
	bool valida = false;	//Gestiona el bucle para que no salga en caso de introducir algo distinto de si o no
	cout<<"Introduce el nombre del paciente: ";
	getline(stream, nombre);
	p.setNombre(nombre);
	cout<<"Introduce los apellidos del paciente: ";
	getline(stream, apellidos);
	p.setApellidos(apellidos);
	do{
		cout<<"¿Desea introducir la edad, el telefono, el peso y la altura del paciente? (S/N): ";
		SN = getchar();
		if('s' == SN || 'S' == SN){
			cout<<"Introduce la edad del paciente: ";
			stream>>edad;
			p.setEdad(edad);
			getchar();
			cout<<"Introduce el telefono del paciente: ";
			stream>>telefono;
			p.setTelefono(telefono);
			getchar();
			cout<<"Introduce el peso del paciente: ";
			stream>>peso;
			p.setPeso(peso);
			getchar();
			cout<<"Introduce la altura del paciente: ";
			stream>>altura;
			p.setAltura(altura);
			getchar();
			//Paciente p(nombre, apellidos, edad, telefono, peso, altura);
			//agregarPaciente(p);
			valida = true;
		}
		else if('n' == SN || 'N' == SN){
			//Paciente p(nombre, apellidos);
			//agregarPaciente(p);
			valida = true;
		}
		else{
			cout<<"Opcion no valida"<<endl;
			getchar();
		}
	}while(valida != true);

	return stream;

}