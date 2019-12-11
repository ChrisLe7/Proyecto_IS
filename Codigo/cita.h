/*
	COMPILA SIN ERRORES PERO NO LE HE HECHOS PRUEBAS
*/

#ifndef CITA_H
#define CITA_H 

#include <string>

using namespace std;

struct RegC {
	char fecha[20];
	char hora[10];
	char paciente[50];	
};

class Cita
{
private:
	string fecha_;
	string hora_;
	string paciente_;
public:
	Cita(string fecha = "NO_ASIGNADO", string hora = "NO_ASIGNADO", string paciente = "NO_ASIGNADO") {
		fecha_ =fecha ; hora_ = hora; paciente_ = paciente;
	}
	~Cita(){}
	bool checkCita();
	//void InsertarCita();
	friend ostream &operator<<(ostream &stream, const Cita &c);
	friend istream &operator>>(istream &stream, Cita &c);
	string getFecha() const {return fecha_;}
	string getHora() const {return hora_;}
	string getPaciente() const {return paciente_;}
	void setFecha(string fecha) {fecha_ =fecha ;}
	void setHora(string hora) { hora_ = hora;}
	void setPaciente(string paciente) {paciente_ = paciente;}
	void setRegC(RegC r) ;
	RegC getRegC() const ;
	//bool ConcertarCita() {if (check_cita() == true) {InsertarCita();return true;} else {/*VOLVER A INTRODUCIR UNA CITA _ SE PUEDE IMPLEMENTAR AQUI O EN LA FUNCION PRINCIPAL*/ return false;}}
	//bool ModificarCita () ;
	//bool EliminarCita () ;
	
};

#endif