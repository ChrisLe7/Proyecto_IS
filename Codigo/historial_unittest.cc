#include "tratamiento.h"
#include <fstream>
#include "gtest/gtest.h"
#include <string>

using namespace std;
TEST(Historial, ConstructorParametrosDefecto) {
  remove("prueba.bin");
  ifstream fichero ("prueba.bin", ios:: in | ios ::binary) ;
  EXPECT_FALSE (fichero.is_open());
  Historial p("prueba.bin");
  ifstream fichero ("prueba.bin", ios:: in | ios ::binary) ;
  EXPECT_TRUE (fichero.is_open());
  fichero.close();
}

TEST(Historial, getRegH){
  Historial p("prueba.bin");
	p.setFecha ("31/12/2025");
	p.setMotivo("Motivo"); 
	RegH r = p.getRegT();
	string fecha, motivo ;
	fecha = r.fecha;
	motivo = r.motivo;
	EXPECT_EQ("31/12/2025",fecha);
  	EXPECT_EQ("Motivo", motivo);
}

TEST(Historial, setRegH){
	string fecha= "31/12/2025";
	string motivo = "Motivo";
	RegH r;
	strcpy(r.fecha, fecha.c_str());
	strcpy(r.motivo, motivo.c_str());
	
	Historial p("prueba.bin");
	p.setRegH(r);

 	EXPECT_EQ("31/12/2025", p.getFecha());
  	EXPECT_EQ("Motivo", p.getMotivo());

}
