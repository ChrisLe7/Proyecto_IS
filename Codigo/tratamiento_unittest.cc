#include "tratamiento.h"
#include <fstream>
#include "gtest/gtest.h"
#include <string>
// NO COMPILAR TODAVIA 
using namespace std;
TEST(Tratamiento, ConstructorParametrosDefecto) {
  Tratamiento p("31/12/2025","29/07/2020","Receta::2");
  
  	EXPECT_EQ("31/12/2025", p.getFechainicio());
  	EXPECT_EQ("29/07/2020" ,p.getFechafinacilizacion());
  	EXPECT_EQ("Receta::2", p.getReceta());

}

TEST(Tratamiento, getRegT){
  Tratamiento p("31/12/2025","29/07/20","Receta::2");
	RegT r = p.getRegT();
	string fecha_inicio, fecha_final, receta ;
	fecha_inicio = r.fechainicio;
	fecha_final = r.fechafinalizacion;
	receta = r.receta;
	EXPECT_EQ("31/12/2025",fecha_inicio);
  	EXPECT_EQ("29/07/2020" ,fecha_final);
  	EXPECT_EQ("Receta::2", receta);
}

TEST(Tratamiento, setRegT){
	string fecha_inicio = "31/12/2025";
	string fecha_final = "12:02";
	string receta = "Pepe Botella";
	RegT r;
	strcpy(r.fechainicio, fecha_inicio.c_str());
	strcpy(r.fechafinalizacion, fecha_final.c_str());
	strcpy(r.receta, receta.c_str());
	
	Tratamiento p;
	p.setRegT(r);

 	EXPECT_EQ("31/12/2025", p.getFechainicio());
  	EXPECT_EQ("29/07/2020" ,p.getFechafinacilizacion());
  	EXPECT_EQ("Receta::2", p.getReceta());

}
