#ifndef _CITA_HPP
#define _CITA_HPP

#include <string>
#include <vector>

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

		inline void setDni(const std::string &cadena) { _dni = cadena};
		inline void setNombre(const std::string &cadena) { _nombre = cadena; }
		inline void setApellidos(const std::string &cadena) { _apellidos = cadena; }
		inline void setFechaCita(const std::string &cadena) { _fechaCita = cadena};


		//Otros métodos

		void printVector(const std::vector <std::string> &v);

};

#endif
