#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <list>
#include "paciente.h"

using std::list;
using std::string;

class Sistema{

	private:

		list <Paciente> pacientes_;
		void opciones();
		void agregarPaciente(const Paciente &p);
		void modificaDatos(Paciente &p);

	public:

		//Sistema();
		//~Sistema();
		void start();
		void menu();
		void setPaciente();
		inline list <Paciente> getPacientes() const {return pacientes_;}
		bool buscaPaciente(const Paciente &p, int opc);		//Recibe como primer parametro el paciente con el que trabajara y como segundo el que hara con el paciente
		//bool buscarPacientes(const Paciente &p);
		void mostrarPacientes();
		void leerPacientes(/*const Paciente p*/);
		//void modificarPaciente(Paciente &p);
		//bool eliminarPaciente(const Paciente &p);

};

#endif