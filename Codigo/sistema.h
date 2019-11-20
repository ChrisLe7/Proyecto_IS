#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <list>
#include "paciente.h"

using std::list
using std::string

class Sistema{

	private:

		list <Paciente> pacientes_;
		void opciones();
		void agregarPaciente(const Paciente &p);

	public:

		Sistema();
		~Sistema();
		void start();
		void menu();
		void setPaciente();
		inline void getPacientes() const {
			return pacientes_;
		}
		bool buscarPacientes(string nombre);
		void modificarPaciente(Paciente &p);
		bool eliminarPaciente(string nombre);

};

#endif