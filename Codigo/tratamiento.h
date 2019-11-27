//NO ESTA COMPILADO

#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H 

class Tratamiento
{
private:
	string fechainicio_;
	string fechafinalizacion_;
	string receta_;
	
public:
	Tratamiento();
	~Tratamiento();
	inline getFechainicio() {return fechainicio_;}
	inline getFechafinacilizacion() {return fechafinalizacion_;}
	inline getReceta() {return receta_;}
	void Motrar (string nombre) ;
	void Anidir (string nombre) ;
	void Finalizar (string nombre) ;  
};
#endif