#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>
#include "paciente.h"
#include "sistema.h"
#include "cita.h"

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
	Reg r;
	ifstream fichero("pacientes.bin", ios::binary);
	//fichero.seekg(0L, ios::beg);
	while(fichero.read((char*)&r, sizeof(Reg))){
		aux.setReg(r);
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
	Reg aux = p.getReg();
	ofstream fichero("pacientes.bin", ios::app | ios::binary);
	fichero.write((char*)&aux, sizeof(Reg));
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
		getchar();
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
				getchar();
				p.setEdad(n);
			break;
			case 4:
				cout<<"Introduce el nuevo telefono: ";
				cin>>m;
				getchar();
				p.setTelefono(m);
			break;
			case 5:
				cout<<"Introduce el nuevo peso: ";
				cin>>q;
				getchar();
				p.setPeso(q);
			break;
			case 6:
				cout<<"Introduce la nueva altura: ";
				cin>>q;
				getchar();
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

void Sistema::modificaDatosFich(const Paciente &old_p, const Paciente &new_p){

	//cout << old_p << new_p;
	Reg r;
	int pos;
	fstream fichero("pacientes.bin", ios::binary | ios::in | ios::out);
	while(fichero.read((char*)&r, sizeof(Reg))){
		if(r.nombre == old_p.getNombre() && r.apellidos == old_p.getApellidos()){
			pos = fichero.tellg() / sizeof(Reg);
			fichero.seekg((pos-1) * sizeof(Reg), ios::beg);
			r = new_p.getReg();
			fichero.write((char*)&r, sizeof(Reg));
		}
	}
	fichero.close();

}

void Sistema::eliminarPacienteFich(const Paciente &p){

	//cout << p << "1" << endl;
	//Paciente aux(p);
	Reg r;
	ifstream fichero("pacientes.bin", ios::binary);
	ofstream temp("temporal.bin", ios::binary);
	while(fichero.read((char*)&r, sizeof(Reg))){
		//aux.setReg(r);
		//cout << p;
		if(r.nombre != p.getNombre() && r.apellidos != p.getApellidos()){
			temp.write((char*)&r, sizeof(Reg));
		}
	}
	fichero.close();
	temp.close();
	remove("pacientes.bin");
	rename("temporal.bin", "pacientes.bin");

}

void Sistema::insertarCita(const Cita &c){

	RegC r = c.getRegC();
	ofstream fichero("citas.bin", ios::binary | ios::app);
	fichero.write((char*)&r, sizeof(RegC));
	fichero.close();

}

void Sistema::modificaDatosCita(Cita &c){

	int opc;
	string line;
	do{
		cout<<"¿Que desea modificar?"<<endl;
		cout<<"1. Fecha"<<endl;
		cout<<"2. Hora"<<endl;
		cout<<"3. Guardar cambios"<<endl;
		cout<<"Elige una opcion: ";
		cin>>opc;
		getchar();
		switch(opc){
			case 1:
				cout<<"Introduce la nueva fecha: ";
				getline(cin, line);
				c.setFecha(line);
			break;
			case 2:
				cout<<"Introduce la nueva hora: ";
				getline(cin, line);
				c.setHora(line);
			break;
			case 3:
				cout<<"Cambios guardados"<<endl;
			break;
			default:
				cout<<"Opcion no valida"<<endl;
		}
	}while(opc != 3);

}

void Sistema::start(){

	cout<<"--------Inicializando sistema--------"<<endl;
	Paciente aux("", "");
	Reg r;
	ifstream fichero("pacientes.bin", ios::binary);
	while(fichero.read((char*)&r, sizeof(Reg))){
		aux.setReg(r);
		pacientes_.push_back(aux);
	}
	fichero.close();
	menu();

}

void Sistema::menu(){

	int opc;
	string nombre, apellidos;
	Paciente aux("", "");
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
				if(buscarPacientes(aux)){
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
				modificarPaciente(aux);
			break;
			case 5:
				cout<<"Introduce el nombre del paciente a eliminar: ";
				getline(cin, nombre);
				aux.setNombre(nombre);
				cout<<"Introduce los apellidos del paciente a eliminar: ";
				getline(cin, apellidos);
				aux.setApellidos(apellidos);
				eliminarPaciente(aux);
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

/*bool Sistema::buscaPaciente(Paciente &p, int opc){	//Como varias funciones parten de buscar a un paciente para funcionar, las juntamos todas optimizando el programa

	Paciente old_p("", "");
	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++){
		if((*i).getNombre() == p.getNombre() && (*i).getApellidos() == p.getApellidos()){
			if(opc == 1){	//OPC = 1 buscar y mostrar paciente
				cout<<(*i);		//Sobrecargado el operador << en las clase paciente
				return true;
			}
			else if(opc == 2){	//OPC = 2 busca el paciente y lo modifica
				old_p = *i;
				modificaDatos(*i);
				modificaDatosFich(old_p, *i);
				return true;
			}
			else if(opc == 3){	//OPC = 3 busca un paciente y lo elimina
				pacientes_.erase(i);
				eliminarPacienteFich(*i);
				return true;
			}
		}
	}
	return false;

}*/

bool Sistema::buscarPacientes(const Paciente &p){
		
	//list <Paciente> aux = getPacientes();		Es inutil pues puede acceder directamente ya que es de su propia clase
	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++){
		if((*i).getNombre() == p.getNombre() && (*i).getApellidos() == p.getApellidos()){
			return true;
		}
	}
	return false;

}

void Sistema::mostrarPacientes(){

	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++){
		cout<<(*i);		//Sobrecargado el operador << en las clase paciente
	}

}

bool Sistema::modificarPaciente(Paciente &p){

	Paciente old_p("", "");
	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++){
		if((*i).getNombre() == p.getNombre() && (*i).getApellidos() == p.getApellidos()){
			old_p = *i;
			modificaDatos(*i);
			modificaDatosFich(old_p, *i);
			return true;
		}
	}
	return false;

}


bool Sistema::eliminarPaciente(const Paciente &p){
	
	//list <Paciente> aux = getPacientes();		Igual que el anterior
	list <Paciente> :: iterator i;
	for(i = pacientes_.begin(); i != pacientes_.end(); i++){
		if((*i).getNombre() == p.getNombre() && (*i).getApellidos() == p.getApellidos()){
			//Eliminar_Paciente_fich(i);
			pacientes_.erase(i);
			eliminarPacienteFich(p);
			return true;
		}
	}
	return false;

}

bool Sistema::concertarCita(){

	Cita c;
	cin>>c;
	if(c.checkCita() == true){
		insertarCita(c);
		return true;
	}
	else{
		return false;
	}

}

bool Sistema::modificarCita(){

	Cita c;
	RegC r;
	int pos;
	string line;
	cout<<"Introduce el nombre completo del paciente cuya cita quiere cambiar: ";
	getline(cin, line);
	fstream fichero("citas.bin", ios::binary);
	while(fichero.read((char*)&r, sizeof(RegC))){
		if(r.paciente == line){
			c.setRegC(r);
			modificaDatosCita(c);
			pos = fichero.tellg() / sizeof(RegC);
			fichero.seekg((pos-1) * sizeof(RegC), ios::beg);
			r = c.getRegC();
			fichero.write((char*)&r, sizeof(RegC));
			return true;
		}
	}
	return false;

}

bool Sistema::eliminarCita(){

	RegC r;
	string line;
	cout<<"Introduce el nombre completo del paciente cuya cita quiere cambiar: ";
	getline(cin, line);
	ifstream fichero("citas.bin", ios::binary);
	ofstream temp("temporal.bin", ios::binary);
	while(fichero.read((char*)&r, sizeof(RegC))){
		//aux.setReg(r);
		//cout << p;
		if(line != r.paciente){
			temp.write((char*)&r, sizeof(RegC));
		}
	}
	fichero.close();
	temp.close();
	remove("citas.bin");
	rename("temporal.bin", "citas.bin");

}