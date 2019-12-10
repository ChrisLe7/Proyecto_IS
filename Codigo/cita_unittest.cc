#include "cita.h"
#include <fstream>
#include "gtest/gtest.h"
#include <string>

using namespace std;
TEST(Cita, ConstructorParametrosDefecto) {
  Cita p("31/12/2025","12:02","Pepe Botella");
  
  	EXPECT_EQ("31/12/2025", p.getFecha());
  	EXPECT_EQ("12:02", p.getHora());
  	EXPECT_EQ("Pepe Botella", p.getPaciente());

}

TEST(Cita, getRegC){
	Cita p("31/12/2025","12:02","Pepe Botella");
	RegC r = p.getRegC();
	string fecha, hora, paciente ;
	fecha = r.fecha;
	hora = r.hora;
	paciente = r.paciente;
	EXPECT_EQ("31/12/2025", fecha);
  	EXPECT_EQ("12:02",hora);
  	EXPECT_EQ("Pepe Botella",paciente);
	
}

TEST(Cita, setRegC){
	string fecha = "31/12/2025";
	string hora = "12:02";
	string paciente = "Pepe Botella";
	RegC r;
	strcpy(r.fecha, fecha.c_str());
	strcpy(r.hora, hora.c_str());
	strcpy(r.paciente, paciente.c_str());
	
	Cita p;
	p.setRegC(r);

	EXPECT_EQ("31/12/2025", p.getFecha());
  	EXPECT_EQ("12:02", p.getHora());
  	EXPECT_EQ("Pepe Botella", p.getPaciente());

}
// NO LO PASA
TEST(Cita, ConcertarCita ){
	Cita p("31/12/2025","12:02","Pepe Botella");
	EXPECT_TRUE(p.ConcertarCita());
	Cita d("31/12/2025","12:02","Pepe Botella");
	EXPECT_FALSE(d.ConcertarCita());
	ifstream fichero ("citas.bin", ios::in | ios::binary) ;
	// recorremos el fichero: 
	RegC aux;
	Cita aux_;
	int i = 0;
	while (!fichero.read((char * ) &aux , sizeof (RegC) )) {
		i++;
		
		aux_.setRegC(aux);
	}
	EXPECT_EQ(1,i);
	fichero.close ();
	EXPECT_EQ("31/12/2025", aux_.getFecha());
  	EXPECT_EQ("12:02", aux_.getHora());
  	EXPECT_EQ("Pepe Botella", aux_.getPaciente());
}

