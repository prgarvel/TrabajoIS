#include "paciente.hpp"
#include "funcionesAuxiliares.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <fstream>

//Métodos privados
void Paciente::borrarPatologia(const int &pos)
{
	_patologias.erase(_patologias.begin()+pos);
}

void Paciente::borrarAlergia(const int &pos)
{
	_alergias.erase(_alergias.begin()+pos);
}

void Paciente::setVector(const int &opcion, const std::vector<std::string> &v)
{
	switch(opcion)
	{
		case 0:
			cleanPatologias();
			_patologias.resize(v.size());
			_patologias = v;
		break;

		case 1:
			cleanAlergias();
			_alergias.resize(v.size());
			_alergias = v;
		break;
	}
}
//Métodos públicos

std::string Paciente::addDni()
{
	std::string cadena, letra;
	int digitos;
	
	std::cout << "Introduzca el dni del paciente (EJEMPLO: 00000000C): ";
	std::cin >> cadena;

	if(cadena.size() < 9)
	{
		return "indefinido";
	}

	digitos = std::atoi(cadena.substr(0,8).c_str());
	letra = cadena.substr(8,1);

	if(comprobarDni(digitos) == letra)
	{
		std::cout << "Dni correcto" << std::endl;
	}
	else
	{
		std::cout << "Dni Incorrecto, defínalo de nuevo más adelante" << std::endl;
		cadena = "indefinido";
	}

	return cadena;
}

std::string Paciente::addFecha()
{
	int dia, mes, year;
	std::string fecha;

	std::cout << "Introduzca el día en valor númerico (Ejemplo 31): ";
	std::cin >> dia;

	std::cout << "Introduzca el mes en valor númerico (Ejemplo 12): ";
	std::cin >> mes;

	std::cout << "Introduzca el año (Ejemplo 1980): ";
	std::cin >> year;

	if(dia < 1 || dia > 31 || mes < 1 || mes > 12 || year < 1910 )
	{
		std::cout << "Opción no válida, se estable el valor como no definido" << std::endl;
		return "Sin definir";
	}

	fecha = std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(year);

	return fecha;
}

std::string Paciente::addSexo()
{
	int opcion;
	std::cout << "Introduzca 1 si es mujer o 0 si es hombre: ";
	std::cin >> opcion;

	if(opcion == 1)
	{
		return "Mujer";
	}
	else if(opcion == 1)
	{
		return "Hombre";
	}
	else
	{
		std::cout << "Opción no válida, se estable el valor como no definido" << std::endl;
		return "Sin definir";
	}
}

std::string Paciente::addGrupo()
{
	int grupo;
	int signo;
	std::string sangre;

	std::cout << "Elija entre los siguientes tipos de grupos sanguíneos (introduzca el número que le corresponda a cada opción): " << std::endl;
	std::cout << "1)AB\n2)A\n3)B\n4)O\n\tIntroduzca una opción: ";
	std::cin >> grupo;

	switch(grupo)
	{
		case 1:
			sangre = "AB";
		break;

		case 2:
			sangre = "A";
		break;

		case 3:
			sangre = "B";
		break;

		case 4:
			sangre = "O";
		break;

		default:
			std::cout << "Opción no válida, se estable el valor como no definido" << std::endl;
			sangre = "Sin definir";
			return sangre;
	}

	std::cout << "Indique si el grupo es positivo o negativo (1 positivo, 0 negativo): ";
	std::cin >> signo;

	switch(signo)
	{
		case 0:
			sangre += "-";
		break;

		case 1:
			sangre += "+";
		break;

		default:
			std::cout << "Opción no válida, se estable el valor como no definido" << std::endl;
			sangre = "Sin definir";
	}

	return sangre;
}

std::string Paciente::addEmail()
{
	std::string cadena;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<int>::max(),'\n');
	std::cout << "Introduzca el email: ";
	std::cin >> cadena;

	if(validarEmail(cadena))
	{
		return cadena;
	}
	else
	{
		std::cout << "Opción no válida, se estable el valor como no definido" << std::endl;
		return "Sin definir";
	}
}

std::string Paciente::addCadena(const std::string &titulo)
{
	std::string cadena;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<int>::max(),'\n');
	std::cout << "Introduzca " << titulo << ": ";
	std::getline(std::cin,cadena);

	return cadena;
}
void Paciente::accessSetters(std::string &cadena, const int &opcion)
{
	switch(opcion)
	{
		case 0:
			setNombre(cadena);
		break;

		case 1:
			setApellidos(cadena);
		break;

		case 2:
			setDni(cadena);
		break;

		case 3:
			setFecha(cadena);
		break;

		case 4:
			setSexo(cadena);
		break;

		case 5:
			setGrupo(cadena);
		break;

		case 6:
			setEmail(cadena);
		break;

		case 7:
			setDireccion(cadena);
		break;

		case 8:
			setMutua(cadena);
		break;
	}
}

int Paciente::findCadena(const std::vector <std::string> &v, const std::string &cadena)
{
	for(int i=0;i<v.size();i++)
	{
		if(v[i] == cadena)
		{
			return i;
		}
	}
	return -1;
}

//Método intermedio
void Paciente::borrar(const int &opcion, const int &pos)
{
	if(pos != -1)
	{
		switch (opcion)
		{
			case 0:
				borrarPatologia(pos);
			break;

			case 1:
				borrarAlergia(pos);
			break;
		}
	}	
}

void Paciente::printVector(const std::vector <std::string> &v)
{

}

bool Paciente::leerFichero(const std::string &fichero, std::vector <std::string> &v)
{
	ifstream file(fichero);
	string aux;

	if(!file)
	{
		return false;
	}
	else
	{
		while(!file.eof())
		{
			file >> aux;
			v.push_back(aux);
		}
	
		//Siempre guarda el último elemento 2 veces, se quita uno
		v.pop_back();
	}
	
	file.close();

	return true;
}

void Paciente::escribirFichero(const std::string &fichero, const std::vector<std::string> &v)
{
	ofstream file(fichero);

	for(int i=0;i<v.size();i++)
	{
		file << v[i] << std::endl;
	}

	file.close();
}

	