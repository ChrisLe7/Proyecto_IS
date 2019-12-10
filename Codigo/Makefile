all: main.exe

main.exe: main.o sistema.o paciente.o
	g++ -o main.exe main.o sistema.o paciente.o

main.o: main.cc
	g++ -c main.cc

sistema.o : sistema.cc
	g++ -c sistema.cc

paciente.o: paciente.cc
	g++ -c paciente.cc

tratamiento.o: tratamiento.cc
	g++ -c tratamiento.cc -std=gnu++11
	
.PHONY: clean

clean:
	del /Q /S *.o *.txt