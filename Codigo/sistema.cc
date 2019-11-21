#include <iostream>
#include <string>
#include <list>
#include "paciente.h"
#include "sistema.h"

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

void Sistema::opciones(){

	cout<<"1) Crear paciente."<<endl;
	cout<<"2) Buscar paciente."<<endl;
	cout<<"3) Mostrar pacientes."<<endl;
	cout<<"4) Modificar paciente."<<endl;
	cout<<"5) Eliminar paciente."<<endl;

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
	string nombre;
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
				cout<<"Introduce el nombre completo del paciente a buscar: ";
				getline(cin, nombre);
				if(buscarPacientes(nombre)){
					cout<<"Se encontro al paciente."<<endl;
				}
			break;
			case 3:
				mostrarPacientes();
			break;
			case 4:

			break;
			case 5:
				cout<<"Introduce el nombre completo del paciente a eliminar: ";
				getline(cin, nombre);
				eliminarPaciente(nombre);
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
	SN = getchar();
	if('s' == SN || 'S' == SN){
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

bool Sistema::buscarPacientes(string nombre) {
		
	//list <Paciente> aux = getPacientes();		Es inutil pues puede acceder directamente ya que es de su propia clase
	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++) {
		if((*i).getApellidos() + " " + (*i).getNombre() == nombre ) {
			return true;
		}
	}
	return false;

}

void Sistema::mostrarPacientes(){

	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++){
		cout<<"Nombre: "<<(*i).getNombre()<<endl;
		cout<<"Apellidos: "<<(*i).getApellidos()<<endl;
		cout<<"Edad: "<<(*i).getEdad()<<endl;
		cout<<"Telefono: "<<(*i).getTelefono()<<endl;
		cout<<"Peso: "<<(*i).getPeso()<<endl;
		cout<<"Altura: "<<(*i).getAltura()<<endl;
	}

}

void Sistema::modificarPaciente(Paciente &p){
/* EN DESARROLLO : WIP */
	int opc;
	int n;
	string line;
	double m;
	float q;
	do{
		cout<<"¿Que desea modificar?"<<endl;
		cout<<"1. Nombre"<<endl;
		cout<<"2. Apellidos"<<endl;
		cout<<"3. Edad"<<endl;
		cout<<"4. Telefono"<<endl;
		cout<<"5. Peso"<<endl;
		cout<<"6. Altura"<<endl;
		cout<<"7. Guardar cambios"<<endl;
		switch(opc){
			case 1:
				getline(cin, line);
				p.setNombre(line);
			break;
			case 2:
				getline(cin, line);
				p.setApellidos(line);
			break;
			case 3:
				cin>>n;
				p.setEdad(n);
			break;
			case 4:
				cin>>m;
				p.setTelefono(m);
			break;
			case 5:
				cin>>q;
				p.setPeso(q);
			break;
			case 6:
				cin>>q;
				p.setAltura(q);
			break;
			case 7:
				cout<<"Cambios guardados"<<endl;
			break;
			default:
				cout<<"Opcion no valida"
		}
	}while(opc != 7);
	

}


bool Sistema::eliminarPaciente (string nombre) {
	
	//list <Paciente> aux = getPacientes();		Igual que el anterior
	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++) {
		if((*i).getApellidos() + " " + (*i).getNombre() == nombre ) {
			//Eliminar_Paciente_fich(i);
			pacientes_.erase(i);
			return true;
		}
	}
	return false;

}

/* EN DESARROLLO : WIP 
bool Sistema::Eliminar_Paciente_fich(string nombre) {
}*/
