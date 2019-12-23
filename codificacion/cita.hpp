#ifndef _CITA_HPP
#define _CITA_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Cita {
	private:
		string _dni, _fechaCita, _horaCita, _observaciones;

	public:

		Cita(){};

		~Cita(){};

		//Métodos get
		inline string getDni() const { return _dni; }
		inline string getFechaCita() const { return _fechaCita; }
		inline string getHoraCita() const { return _horaCita; }
		inline string getObservaciones() const { return _observaciones; }

		//Métodos set

		inline void setDni(const std::string &cadena) { _dni = cadena; };
		inline void setFechaCita(const std::string &cadena) { _fechaCita = cadena; };
		inline void setHoraCita(const std::string &cadena) { _horaCita = cadena; }
		inline void setObservaciones(const std::string &cadena) { _observaciones = cadena; }


		//Otros métodos

		void printCita();

};

#endif
