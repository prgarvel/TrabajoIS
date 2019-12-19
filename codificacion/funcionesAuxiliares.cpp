#include "funcionesAuxiliares.hpp"


int menu(){
	int opcion=-1;

	cout << endl;
	cout << "Introduce la opcion:" << endl << "1) Operaciones sobre paciente." << endl <<"2) Operaciones sobre tratamientos" << endl;
	cout << "3) Operaciones sobre la agenda." << endl << "4) Operaciones sobre historiales." << endl << "0) Salir" << endl << "Opcion: ";
	cin >> opcion;

	cout << endl;

	return opcion;

}

int submenuTratamientos(){
	int opcion=-1;

	cout << endl;
	cout << "Operaciones sobre tratamientos:" << endl << "1) Añadir tratamiento." << endl << "2) Eliminar tratamiento" << endl;
	cout << "3) Modificar tratamiento" << endl << "4) Consultar tratamiento." << endl << "0) Salir" << endl << "Opcion: ";
	cin >> opcion;

	cout << endl;

	return opcion;
}

int submenuHistorial(){
	int opcion=-1;

	cout << endl;
	cout << "Operaciones sobre historiales:" << endl << "1) Cargar historial de un paciente." << endl << "2) Consultar historial de un paciente" << endl << "0) Salir" << endl << "Opcion: ";
	cin >> opcion;

	cout << endl;

	return opcion;
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