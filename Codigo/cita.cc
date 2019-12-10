/*
	COMPILA SIN ERRORES PERO NO LE HE HECHOS PRUEBAS
*/

#include "cita.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


void Cita::setRegC( RegC r) {
	fecha_ = r.fecha;
	hora_ = r.hora;
	paciente_= r.paciente;
}

RegC Cita::getRegC() const {
	RegC r;
	strcpy(r.fecha , fecha_.c_str());
	strcpy(r.hora , hora_.c_str());
	strcpy(r.paciente , paciente_.c_str());		
	return r;
}

void Cita::InsertarCita() {
	RegC aux = getRegC();
	ofstream fichero ("citas.bin", ios::app | ios::binary) ;
	fichero.write((char * )& aux , sizeof (RegC));
	fichero.close();
}


bool Cita::check_cita () {
	RegC aux ;
	Cita aux_;
	ifstream fichero ("citas.bin", ios::in | ios::binary) ;
	// recorremos el fichero: 
	
	while (!fichero.read((char * ) &aux , sizeof (RegC) )) {
		
		aux_.setRegC(aux);
		if ((aux_.fecha_ == fecha_) & (aux_.hora_ == hora_) ) {
			fichero.close();
			return false;
		}
	}
	fichero.close ();
	return true;

}


bool Cita::ModificarCita () {
	RegC aux ;
	Cita aux_;
	check_cita ();

	ifstream fichero ("citas.bin", ios::in | ios::binary) ;
	ofstream fichero_aux ("aux.bin", ios::out | ios::binary) ;
	while (!fichero.eof()) {
		fichero.read((char * ) &aux , sizeof (RegC) );
		aux_.setRegC(aux);
		if ((aux_.paciente_ == paciente_) ) {
			aux = getRegC (); 						
			fichero_aux.write((char * )& aux , sizeof (RegC));
		}
		else {
			fichero_aux.write((char * )& aux , sizeof (RegC));

		}
	}
	fichero.close ();
	fichero_aux.close();
	//ELIMINAR EL FICHERO CITAS.bin Y RENOMBRAR EL OTRO.
	return true;

}





bool Cita::EliminarCita () {
		RegC aux ;
	Cita aux_;

	ifstream fichero ("citas.bin", ios::in | ios::binary) ;
	ofstream fichero_aux ("aux.bin", ios::out | ios::binary) ;
	
	while (!fichero.eof()) {
		fichero.read((char * ) &aux , sizeof (RegC) );
		aux_.setRegC(aux);
		if ((aux_.paciente_ == paciente_) ) {
			aux = getRegC (); 						
			fichero_aux.write((char * )& aux , sizeof (RegC));
		}
		else {
			fichero_aux.write((char * )& aux , sizeof (RegC));

		}
	}
	fichero.close ();
	fichero_aux.close();
	//ELIMINAR EL FICHERO CITAS.bin Y RENOMBRAR EL OTRO.
	return true;
}


