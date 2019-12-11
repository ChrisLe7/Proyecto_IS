#include "tratamiento.h"
#include <fstream>
#include "gtest/gtest.h"
#include <string>

using namespace std;
TEST(Historial, ConstructorParametrosDefecto) {
  Historial p("31/12/2025","Motivo");
  
  	EXPECT_EQ("31/12/2025", p.getFecha());
  	EXPECT_EQ("Motivo", p.getMotivo());

}

TEST(Historial, getRegH){
  Historial p("31/12/2025","29/07/20","Motivo");
	RegH r = p.getRegT();
	string fecha, motivo ;
	fecha = r.fecha;
	motivo = r.motivo;
	EXPECT_EQ("31/12/2025",fecha);
  	EXPECT_EQ("Receta::2", motivo);
}

TEST(Historial, setRegH){
	string fecha= "31/12/2025";
	string motivo = "Motivo";
	RegH r;
	strcpy(r.fecha, fecha.c_str());
	strcpy(r.motivo, motivo.c_str());
	
	Historial p;
	p.setRegH(r);

 	EXPECT_EQ("31/12/2025", p.getFecha());
  	EXPECT_EQ("Motivo", p.getMotivo());

}
