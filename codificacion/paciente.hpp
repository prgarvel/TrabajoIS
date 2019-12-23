#ifndef _PACIENTE_HPP
#define _PACIENTE_HPP

#include <string>
#include <vector>


class Paciente
{

	private:

		std::string _nombre;
		std::string _apellidos;
		std::string _dni;
		std::string _fechaNacimiento;
		std::string _sexo;
		std::string _grupoSanguineo;
		std::string _email;
		std::string _direccion;

		int _telefono;
		int _altura;

		float _peso;

	public:

		Paciente()
		{
			setNombre("Sin definir");
			setApellidos("Sin definir");
			setDni("Sin definir");
			setFecha("Sin definir");
			setSexo("Sin definir");
			setGrupo("Sin definir");
			setEmail("Sin definir");
			setDireccion("Sin definir");
		};

		~Paciente(){};

		//Métodos get

		inline std::string getNombre() const { return _nombre; }
		inline std::string getApellidos() const { return _apellidos; }
		inline std::string getDni() const { return _dni; }
		inline std::string getFecha() const { return _fechaNacimiento; }
		inline std::string getSexo() const { return _sexo; }
		inline std::string getGrupo() const { return _grupoSanguineo; }
		inline std::string getEmail() const { return _email; }
		inline std::string getDireccion() const { return _direccion; }
		inline int getTelefono() const { return _telefono; }
		inline int getAltura() const { return _altura; }
		inline float getPeso() const { return _peso; }

		//Métodos set

		inline void setNombre(const std::string &cadena) { _nombre = cadena; }
		inline void setApellidos(const std::string &cadena) { _apellidos = cadena; }
		inline void setDni(const std::string &cadena) { _dni = cadena; }
		inline void setFecha(const std::string &cadena) { _fechaNacimiento = cadena; }
		inline void setSexo(const std::string &cadena) { _sexo = cadena; }
		inline void setGrupo(const std::string &cadena) { _grupoSanguineo = cadena; }
		inline void setEmail(const std::string &cadena) { _email = cadena; }
		inline void setDireccion(const std::string &cadena) { _direccion = cadena; }
		inline void setTelefono(const int &t) { _telefono = t; }
		inline void setAltura(const int &a) { _altura = a; }
		inline void setPeso(const float &p) { _peso = p; }

		int findCadena(const std::vector <std::string> &v, const std::string &cadena);

		void printPaciente();

};

#endif