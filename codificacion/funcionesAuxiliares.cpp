#include 'funcionesAuxiliares.hpp'

using namespace std;

void menu(){
	int opcion=-1;

	do{
		cout << "Introduce la opcion:" << endl << "1) Operaciones sobre paciente." << "2) Operaciones sobre tratamientos" << endl;
		cout << "3) Operaciones sobre la agenda." << endl << "4) Operaciones sobre historiales." << endl << "0) Salir" << endl << endl;
		cin >> opcion;
	}while(opcion!=0);
}