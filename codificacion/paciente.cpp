#include "paciente.hpp"
#include "funcionesAuxiliares.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>

//Métodos públicos

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

void Paciente::printPaciente()
{
	std::cout << "Nombre: " << getNombre() << " " << getApellidos() << std::endl;
	std::cout << "Dni: " << getDni() << std::endl;
	std::cout << "Fecha de nacimiento: " << getFecha() << std::endl;
	std::cout << "Sexo: " << getSexo() << std::endl;
	std::cout << "Teléfono: " << getTelefono() << std::endl;
	std::cout << "Correo electrónico: " << getEmail() << std::endl;
	std::cout << "Dirección postal: " << getDireccion() << std::endl;
	std::cout << "Grupo sanguíneo: " << getGrupo() << std::endl;
	std::cout << "Altura: " << getAltura() << std::endl;
	std::cout << "Peso: " << getPeso() << std::endl;
}