#ifndef _CITA_HPP
#define _CITA_HPP

#include <string>
#include <iostream>

using namespace std;

class Cita {

	private:

		string _dni, _nombre, _apellidos, _fechaCita;

	public:

		Cita(){};

		~Cita(){};

		//Métodos get
		inline string getDni() const { return _dni; }
		inline string getNombre() const { return _nombre; }
		inline string getApellidos() const { return _apellidos; }
		inline string getFechaCita() const { return _fechaCita; }

		//Métodos set

		inline void setDni(const string &cadena) { _dni = cadena; }
		inline void setNombre(const string &cadena) { _nombre = cadena; }
		inline void setApellidos(const string &cadena) { _apellidos = cadena; }
		inline void setFechaCita(const string &cadena) { _fechaCita = cadena; }


		//Otros métodos
		void printCita();

};

#endif
