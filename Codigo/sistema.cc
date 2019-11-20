#include <iostream>
#include <string>
#include <list>
#include "paciente.h"
#include "sistema.h"

using std::cin;
using std::cout;
using std::list;
using std::string;

void Sistema::opciones(){

	cout<<"1) Crear paciente."<<endl;
	cout<<"2) Buscar paciente paciente."<<endl;
	cout<<"3) Modificar paciente."<<endl;
	cout<<"4) Eliminar paciente."<<endl;

}

void Sistema::agregarPaciente(const Paciente &p){

	pacientes_.push_back(p);
	//fichero

}

void Sistema::start(){

	cout<<"--------Inicializando sistema--------"<<endl;
	menu();

}

void Sistema::menu(){

	int opc;
	do{

		opciones();
		cout<<"Elige una opcion: ";
		cin>>opc;
		getchar();
		switch(opc){
			case 1:
				setPaciente();
			break;
			case 2:

			break;
			case 3:

			break;
			case 4:

			break;
			default:
				cout<<"Opcion no valida"<<endl;
		}

	}while(opc != 7);

}

void Sistema::setPaciente(){

	string nombre, apellido;
	int edad;
	double telefono;
	float peso, altura;
	char SN;	//Opcion que indica si quiere o no introducir el resto de datos
	cout<<"Introduce el nombre del paciente: ";
	getline(cin, nombre);
	cout<<"Introduce los apellidos del paciente: ";
	getline(cin, apellido);
	cout<<"¿Desea introducir la edad, el telefono, el peso y la altura del paciente? (S/N): ";
	if('S' == getchar(SN) || 's' == getchar(SN)){
		cout<<"Introduce la edad del paciente: ";
		cin>>edad;
		getchar();
		cout<<"Introduce el telefono del paciente: ";
		cin>>telefono;
		getchar();
		cout<<"Introduce el peso del paciente: ";
		cin>>peso;
		getchar();
		cout<<"Introduce la altura del paciente: ";
		cin>>altura;
		getchar();
		Paciente p(nombre, apellido, edad, telefono, peso, altura);
	}
	Paciente p(nombre, apellido);
	agregarPaciente(p);

}

void Sistema::modificarPaciente(Paciente &p){
/* EN DESARROLLO : WIP */
}

bool Sistema::buscarPacientes(string nombre) {
		
	list <Paciente> aux = getPacientes();
	list <Paciente> :: iterator i;
	for(i= aux.begin();i !=aux.end();i++) {
		if ((*i).getApellidos() + (*i).getNombre() = nombre ) {
			return true;
		}
	}
	return false;

}

bool Sistema::eliminarPaciente (string nombre) {
	
	list <Paciente> aux = getPacientes();
	list <Paciente> :: iterator i;
	for(i= aux.begin();i !=aux.end();i++) {
			if ((*i).getApellidos() + (*i).getNombre() = nombre ) {
				Eliminar_Paciente_fich(i);
				aux.erase(i);
					return true;
			}
	}
	return false;

}

/* EN DESARROLLO : WIP 
bool Sistema::Eliminar_Paciente_fich(string nombre) {
}*/
