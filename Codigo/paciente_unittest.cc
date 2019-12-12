#include "paciente.h"
#include "gtest/gtest.h"

TEST(Paciente, ConstructorParametrosDefecto) {
  Paciente p("33XX","44XX");
  
  	EXPECT_EQ("33XX", p.getNombre());
  	EXPECT_EQ("44XX", p.getApellidos());
  	EXPECT_EQ(0, p.getTelefono());
  	EXPECT_EQ(0, p.getPeso());
	EXPECT_EQ(0, p.getEdad());
  	EXPECT_EQ(0, p.getAltura());
}

TEST(Paciente, getReg){
	Paciente p("33XX", "44XX");
	Reg r = p.getReg();

	EXPECT_EQ(0, strcmp("33XX", r.nombre));
	EXPECT_EQ(0, strcmp("44XX", r.apellidos));
	EXPECT_EQ(0, r.edad);
	EXPECT_EQ(0, r.telefono);
	EXPECT_EQ(0, r.peso);
	EXPECT_EQ(0, r.altura);
}

TEST(Paciente, setReg){
	string nombre = "33XX";
	string apellidos = "44XX";

	Reg r;
	strcpy(r.nombre, nombre.c_str());
	strcpy(r.apellidos, apellidos.c_str());
	r.edad = 0;
	r.telefono = 0;
	r.peso = 0;
	r.altura = 0;

	Paciente p("", "");
	p.setReg(r);

	EXPECT_EQ("33XX", p.getNombre());
 	EXPECT_EQ("44XX", p.getApellidos());
   	EXPECT_EQ(0, p.getTelefono());
  	EXPECT_EQ(0, p.getPeso());
  	EXPECT_EQ(0, p.getEdad());
  	EXPECT_EQ(0, p.getAltura());
}

