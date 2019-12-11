//NO ESTA COMPILADO
// NO SE HAN HECHO LAS PRUEBAS

#include <iostream>
#include <fstream>
#include "tratamiento.h"
#include <string>
using namespace std;


void Tratamiento::Mostrar(string fichero){
	RegT r_aux;
	Tratamiento aux;
	ifstream fichero_ (fichero+"_tratamiento.bin");
	
	if (fichero_.is_open ()){
		while (!fichero_.read((char*)&r_aux, sizeof(RegT))) {
			aux.setRegT (r_aux);
			cout<< aux.getFechainicio()<<endl;
			cout << aux.getFechafinacilizacion()<<endl;
			cout << aux.getReceta()<<endl;
		}

	} 
	fichero_.close ();
}

void Tratamiento::setRegT(RegT r) {
	fechainicio_ = r.fechainicio;
	fechafinalizacion_ = r.fechafinalizacion;
	receta_ = r.receta;
}

RegT Tratamiento::getRegT() const {
	RegT r ;
	strcpy(r.fechainicio, fechainicio_.c_str());
	strcpy(r.fechafinalizacion, fechafinalizacion_.c_str());
	strcpy(r.receta, receta_.c_str());
}


void Tratamiento::Aniadir(string nombre){
		RegT aux = p.getRegT();
		ofstream fichero(nombre + "_tratamiento.bin", ios::app | ios::binary);
		fichero.write((char*)&aux, sizeof(RegT));
		fichero.close();
}

void Tratamiento::Finalizar(string nombre , string receta, string fechafinalizacion){
		ifstream fichero_ (nombre+"_tratamiento.bin");
		ofstream fichero_aux ("aux.bin"); 
		if (fichero_.is_open ()){
		while (!fichero_.read((char*)&r_aux, sizeof(RegT))) {
			aux.setRegT (r_aux);
			if (receta == aux.getReceta() ) {
				aux.setFechafinacilizacion (fechafinalizacion) ;
			}
			r_aux = aux.getRegT();
			fichero.write((char*)&r_aux, sizeof(RegT));
			fichero.close();		
			}		
		}	
} 
