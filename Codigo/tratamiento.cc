

#include <iostream>
#include <fstream>
#include "tratamiento.h"


using namespace std;

Tratamiento::Tratamiento(){}

void Mostrar(string fichero){

	Tratamiento aux;
	fstream fichero_;
	fichero_.open(fichero, ios:: in ) ;
	if (fichero_.is_open ()){
		while (! fichero_.eof()){
			fichero_.read((char*)&aux, sizeof(Tratamiento));
			cout<< aux.getFechainicio()<<endl;
			cout << aux.getFechafinacilizacion()<<endl;
			cout << aux.getReceta()<<endl;
		}

	} 
	fichero_.close ();
}



	
	void Aniadir(string nombre){}
	void Finalizar(string nombre){} 
