#include "paciente.hpp"
#include "funcionesAuxiliares.hpp"
#include <cstdlib>
#include <iostream>

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

	if (opcion > 0)
	{
		return "Mujer";
	}
	else
	{
		return "Hombre";
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
			sangre = "Sin definir";
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
			sangre += " sin definir";
	}

	return sangre;
}

std::string Paciente::addEmail()
{
	std::string cadena;
	std::cout << "Introduzca el email: ";
	std::cin >> cadena;

	if(validarEmail(cadena))
	{
		return cadena;
	}
	else
	{
		return "indefinido";
	}
}

void Paciente::popPatologia(const std::string &cadena)
{

}

void Paciente::printVector(const std::vector <std::string> &v)
{

}