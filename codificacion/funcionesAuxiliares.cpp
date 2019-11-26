#include "funcionesAuxiliares.hpp"

using namespace std;

void menu()
{
	int opcion=-1;

	do
	{
		cout << "Introduce la opcion:" << endl << "1) Operaciones sobre paciente." << "2) Operaciones sobre tratamientos" << endl;
		cout << "3) Operaciones sobre la agenda." << endl << "4) Operaciones sobre historiales." << endl << "0) Salir" << endl << endl;
		cin >> opcion;
	}while(opcion!=0);
}

string comprobarDni(const int &dni)
{
	string letras = "TRWAGMYFPDXBNJZSQVHLCKE";
	int indice = dni%23;
	return letras.substr(indice,1);
}

bool validarEmail(string email)
{
   const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
   return std::regex_match(email, pattern);
}