//NO ESTA COMPILADO

#include <fstream>
#include <iostream>
#include "historial.h"


Historial::Historial() {
	fstream fichero_;
	fichero_.open(fichero, ios:: in | ios ::binary) ;
	if (fichero.is_open ()) {
		//fichero_.read(())
	} 

}

void Historial::Mostrar (string fichero) {
	Historial aux;
	fstream fichero_;
	fichero_.open(fichero, ios:: in | ios ::binary) ;
	if (fichero.is_open ()) {
		while (! fichero.eof () ) {
			fichero_.read((&aux), sizeof(Historial));
			cout<< aux.getFecha()<<endl;
			cout << aux.getMotivo()<<endl;
		}

	} 
	fichero_.close ();
}

void Historial::Aniadir (string fichero) {
	Historial aux;
	ostream fichero_;
	fichero_.open(fichero, ios ::binary) ;

	if (fichero.is_open ()) {
		fichero_.write(& aux,sizeof (Historial));
	} 
	fichero_.close ();


}