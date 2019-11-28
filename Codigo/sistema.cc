#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>
#include "paciente.h"
#include "sistema.h"

using namespace std;

/*using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
*/
void Sistema::opciones(){

	cout<<"1) Crear paciente."<<endl;
	cout<<"2) Buscar paciente."<<endl;
	cout<<"3) Mostrar pacientes."<<endl;
	cout<<"4) Modificar paciente."<<endl;
	cout<<"5) Eliminar paciente."<<endl;
	cout<<"6) Leer pacientes."<<endl;
	cout<<"7) Salir del programa."<<endl;

}

void Sistema::leerPacientes(/*const Paciente p*/){

	Paciente aux("", "");
	/*string nombre, apellidos;
	int edad;
	float peso, altura;
	double telefono;
	char line[100];
	ifstream fichero("pacientes.txt");
	while(fichero.getline(line, 265, ',')){
		//nombre = line;
		aux.setNombre(line);
		fichero.getline(line, 265, ',');
		//apellidos = line;
		aux.setApellidos(line);
		fichero.getline(line, 265, ',');
		//edad = atoi(line);
		aux.setEdad(atoi(line));
		fichero.getline(line, 265, ',');
		//telefono = atof(line);
		aux.setTelefono(atof(line));
		fichero.getline(line, 265, ',');
		//peso = atof(line);
		aux.setPeso(atof(line));
		fichero.getline(line, 265);
		//altura = atof(line);
		aux.setAltura(atof(line));
		//Paciente aux(nombre, apellidos, edad, telefono, peso, altura);
		cout << aux;
	}*/
	ifstream fichero("pacientes.bin", ios::binary);
	//fichero.seekg(0L, ios::beg);
	while(fichero.read((char*)&aux, sizeof(Paciente))){
		cout << aux;
	}
	fichero.close();

}

void Sistema::agregarPaciente(const Paciente &p){

	pacientes_.push_back(p);
	/*ofstream fichero("pacientes.txt", ios::app);
	fichero << p.getNombre() << ",";
	fichero << p.getApellidos() << ",";
	fichero << p.getEdad() << ",";
	fichero << p.getTelefono() << ",";
	fichero << p.getPeso() << ",";
	fichero << p.getAltura() << "\n";*/
	ofstream fichero("pacientes.bin", ios::app | ios::binary);
	fichero.write((char*)&p, sizeof(Paciente));
	fichero.close();

}


void Sistema::modificaDatos(Paciente &p){

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
		cout<<"Elige una opcion: ";
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"Introduce el nuevo nombre: ";
				getline(cin, line);
				p.setNombre(line);
			break;
			case 2:
				cout<<"Introduce los nuevos apellidos: ";
				getline(cin, line);
				p.setApellidos(line);
			break;
			case 3:
				cout<<"Introduce la nueva edad: ";
				cin>>n;
				p.setEdad(n);
			break;
			case 4:
				cout<<"Introduce el nuevo telefono: ";
				cin>>m;
				p.setTelefono(m);
			break;
			case 5:
				cout<<"Introduce el nuevo peso: ";
				cin>>q;
				p.setPeso(q);
			break;
			case 6:
				cout<<"Introduce la nueva altura: ";
				cin>>q;
				p.setAltura(q);
			break;
			case 7:
				cout<<"Cambios guardados"<<endl;
			break;
			default:
				cout<<"Opcion no valida"<<endl;
		}
	}while(opc != 7);

}

void Sistema::start(){

	cout<<"--------Inicializando sistema--------"<<endl;
	menu();

}

void Sistema::menu(){

	int opc;
	string nombre, apellidos;
	Paciente aux(nombre, apellidos);
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
				cout<<"Introduce el nombre del paciente a buscar: ";
				getline(cin, nombre);
				aux.setNombre(nombre);
				cout<<"Introduce los apellidos del paciente a buscar: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				if(buscaPaciente(aux, 1)){
					cout<<"Se encontro al paciente."<<endl;
				}
				else{
					cout<<"No se encontro al paciente."<<endl;
				}
			break;
			case 3:
				mostrarPacientes();
			break;
			case 4:
				cout<<"Introduce el nombre del paciente a modificar: ";
				getline(cin, nombre);
				aux.setNombre(nombre);
				cout<<"Introduce los apellidos del paciente a modificar: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				buscaPaciente(aux, 2);
			break;
			case 5:
				cout<<"Introduce el nombre del paciente a eliminar: ";
				getline(cin, nombre);
				aux.setNombre(nombre);
				cout<<"Introduce los apellidos del paciente a eliminar: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				buscaPaciente(aux, 3);
			break;
			case 6:
				leerPacientes();
			break;
			case 7:
				cout<<"Saliendo del programa."<<endl;
			break;
			default:
				cout<<"Opcion no valida"<<endl;
		}

	}while(opc != 7);

}

void Sistema::setPaciente(){

	/*string nombre, apellido;
	int edad;
	double telefono;
	float peso, altura;
	char SN;	//Opcion que indica si quiere o no introducir el resto de datos
	bool valida = false;	//Gestiona el bucle para que no salga en caso de introducir algo distinto de si o no
	cout<<"Introduce el nombre del paciente: ";
	getline(cin, nombre);
	cout<<"Introduce los apellidos del paciente: ";
	getline(cin, apellido);
	do{
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
			agregarPaciente(p);
			valida = true;
		}
		else if('n' == SN || 'N' == SN){
			Paciente p(nombre, apellido);
			agregarPaciente(p);
			valida = true;
		}
		else{
			cout<<"Opcion no valida"<<endl;
			getchar();
		}
	}while(valida != true);*/
	Paciente aux("", "");
	cin>>aux;
	agregarPaciente(aux);

}

bool Sistema::buscaPaciente(const Paciente &p, int opc){	//Como varias funciones parten de buscar a un paciente para funcionar, las juntamos todas optimizando el programa

	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++){
		if((*i).getNombre() == p.getNombre() && (*i).getApellidos() == p.getApellidos()){
			if(opc == 1){	//OPC = 1 buscar y mostrar paciente
				cout<<(*i);		//Sobrecargado el operador << en las clase paciente
				return true;
			}
			else if(opc == 2){	//OPC = 2 busca el paciente y lo modifica
				modificaDatos(*i);
				return true;
			}
			else if(opc == 3){	//OPC = 3 busca un paciente y lo elimina
				pacientes_.erase(i);
				return true;
			}
		}
	}
	return false;

}

/*bool Sistema::buscarPacientes(const Paciente &p){
		
	//list <Paciente> aux = getPacientes();		Es inutil pues puede acceder directamente ya que es de su propia clase
	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++){
		if((*i).getNombre() == p.getNombre() && (*i).getApellidos() == p.getApellidos()){
			return true;
		}
	}
	return false;

}*/

void Sistema::mostrarPacientes(){

	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++){
		cout<<(*i);		//Sobrecargado el operador << en las clase paciente
	}

}

/*void Sistema::modificarPaciente(Paciente &p){

	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++){
		if((*i).getNombre() == p.getNombre() && (*i).getApellidos() == p.getApellidos()){
			modificaDatos(*i);
		}
	}

}*/


/*bool Sistema::eliminarPaciente(const Paciente &p){
	
	//list <Paciente> aux = getPacientes();		Igual que el anterior
	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++){
		if((*i).getNombre() == p.getNombre() && (*i).getApellidos() == p.getApellidos()){
			//Eliminar_Paciente_fich(i);
			pacientes_.erase(i);
			return true;
		}
	}
	return false;

}*/

/* EN DESARROLLO : WIP 
bool Sistema::Eliminar_Paciente_fich(string nombre) {
}*/
/*
void Sistema::Mostrar_historial_medico(string nombre) {
	Historial aux (nombre +".txt");
	aux.Mostrar(nombre +".txt");
}*/
