#ifndef _FUNCIONESAUXILIARES_CPP_
#define _FUNCIONESAUXILIARES_CPP_

#include "funcionesAuxiliaresCitas.hpp"

#include <vector>

using namespace std;

void menu(){
	int opcion=-1;
	string DNI;
	vector<Cita> Agenda;
	
	do {
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Introduce la opcion:" << endl ;
		cout << "1) Consultar Agenda." << endl;
    	cout << "2) Añadir cita." << endl;
		cout << "3) Eliminar cita." << endl;
		cout << "4) Modificar cita." << endl;
		cout << "0) Salir." << endl;
		
		cout << "opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 0:
			break;
		case 1:
			cout << endl;
			consultarCita(Agenda);
			cout << endl;
			break;

		case 2:
			cout << endl;
			anhadirCita(Agenda);
			cout << endl;
			break;
		case 3:
		
			break;
		case 4:
		
			break;
		default:
			cout << "\nError en la selección de opción.\n" << '\n';
			break;	
	}
	} while(opcion!=0);

	

}
//El fallo está en que no usas punteros
void anhadirCita(vector<Cita> &vectorCitas){
	string dni, nombre, apellidos, fecha;
	Cita citaAuxiliar;
	
	cout << "DNI: ";
	cin >> dni;
	citaAuxiliar.setDni(dni);
	cout << "Apellidos: ";
	cin >> apellidos;
	citaAuxiliar.setApellidos(apellidos);
	cout << "Nombre: ";
	cin >> nombre;
	citaAuxiliar.setNombre(nombre);
	cout << "Fecha: ";
	cin >> fecha;
	citaAuxiliar.setFechaCita(fecha);
	
	vectorCitas.push_back(citaAuxiliar);

}

void consultarCita(const vector<Cita> &vectorCitas){
	
	if(vectorCitas.size()==0){
		cout << "No hay ninguna cita guardada. " << endl << endl;
	}else{
		cout << "Las citas guardadas son: " << endl;
		for(int i=0; i<vectorCitas.size(); i++){
			cout <<  "DNI: " << vectorCitas[i].getDni() << endl;
			
			cout << endl;
		}
	}	
}

int main(){
	cout << "holi" << endl;
	menu();
	return 0;
}


#endif
