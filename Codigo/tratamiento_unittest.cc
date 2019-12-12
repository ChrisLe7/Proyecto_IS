#include "tratamiento.h"
#include <fstream>
#include "gtest/gtest.h"
#include <string>

using namespace std;
TEST(Tratamiento, ConstructorParametrosDefecto) {
  remove("prueba.bin");
  ifstream fichero ("prueba.bin", ios:: in | ios ::binary) ;
  EXPECT_FALSE (fichero.is_open());
  Tratamiento p("prueba.bin");
  ifstream fichero ("prueba.bin", ios:: in | ios ::binary) ;
  EXPECT_TRUE (fichero.is_open());
  fichero.close();
}

TEST(Tratamiento, getRegT){
  	Tratamiento p("prueba.bin");
	p.setFechainicio("31/12/2025");
	p.setFechafinalizacion("29/07/2020");
	p.setReceta("Receta::2");
	EXPECT_EQ("31/12/2025", p.getFechainicio());
  	EXPECT_EQ("29/07/2020" ,p.getFechafinacilizacion());
  	EXPECT_EQ("Receta::2", p.getReceta());
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
	string fecha_final = "29/07/2020";
	string receta = "Receta::2";
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
