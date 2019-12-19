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
		std::string _mutua;
		std::vector <std::string> _patologias;
		std::vector <std::string> _alergias;

		int _telefono;
		int _altura;

		float _peso;

		//Métodos set

		inline void setNombre(const std::string &cadena) { _nombre = cadena; }
		inline void setApellidos(const std::string &cadena) { _apellidos = cadena; }
		inline void setDni(const std::string &cadena) { _dni = cadena; }
		inline void setFecha(const std::string &cadena) { _fechaNacimiento = cadena; }
		inline void setSexo(const std::string &cadena) { _sexo = cadena; }
		inline void setGrupo(const std::string &cadena) { _grupoSanguineo = cadena; }
		inline void setEmail(const std::string &cadena) { _email = cadena; }
		inline void setDireccion(const std::string &cadena) { _direccion = cadena; }
		inline void setMutua(const std::string &cadena) { _mutua = cadena; }

		void borrarPatologia(const int &pos);
		void cleanPatologias(){ _patologias.clear(); }

		void borrarAlergia(const int &pos);
		void cleanAlergias(){ _alergias.clear(); }

		void setPatologia(const std::string &cadena) { _patologias.push_back(cadena); }
		void setAlergia(const std::string &cadena) { _alergias.push_back(cadena); }

		void setVector(const int &opcion, const std::vector<std::string> &v);

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
			setMutua("Sin definir");
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
		inline std::string getMutua() const { return _mutua; }
		inline std::vector <std::string> getPatologias() const { return _patologias; }
		inline std::vector <std::string> getAlergias() const { return _alergias; }

		//Funciones intermedias

		std::string addDni();
		std::string addFecha();
		std::string addSexo();
		std::string addGrupo();
		std::string addEmail();
		std::string addCadena(const std::string &titulo="");

		void accessSetters(std::string &cadena, const int &opcion);

		int findCadena(const std::vector <std::string> &v, const std::string &cadena);
		void borrar(const int &opcion, const int &pos);
		

		//Entrada y salida ficheros

		bool leerFichero(const std::string &fichero, std::vector <std::string> &v);
		void escribirFichero(const std::string &fichero, const std::vector<std::string> &v);


		void printVector(const std::vector <std::string> &v);

};

#endif