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
			cout << endl;
			eliminarCita(Agenda);
			cout << endl;
			break;
		case 4:
			cout << endl;
			modificarCita(Agenda);
			cout << endl;
			break;
		default:
			cout << "\nError en la selección de opción.\n" << '\n';
			break;	
	}
	} while(opcion!=0);

	

}

void anhadirCita(vector<Cita> &vectorCitas){
	string dni, nombre, apellidos, fecha;
	Cita citaAuxiliar;
	
	cout << "DNI: ";
	cin >> dni;
	citaAuxiliar.setDni(dni);
	cout << "Primer apellido: ";
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
			cout << endl;
			cout <<  "DNI: " << vectorCitas[i].getDni() << endl;
			cout <<  "Primer apellido: " << vectorCitas[i].getApellidos() << endl;
			cout <<  "Nombre: " << vectorCitas[i].getNombre() << endl;
			cout <<  "Fecha: " << vectorCitas[i].getFechaCita() << endl;
			cout << endl;
		}
	}	
}

void eliminarCita(vector<Cita> &vectorCitas){
	
	if(vectorCitas.size()==0){
		cout << "No hay ninguna cita guardada. " << endl;
		cout << "Asique no es posible realizar eliminar ninguna cita de la agenda." << endl << endl;
	}else{
		string DNIAux, nombre, apellidos, fecha;
		Cita citaAuxiliar;
		int indice=-1;
		
		cout << "DNI del cliente a eliminar: ";
		cin >> DNIAux;
		cout << "Fecha que se desea eliminar: ";
		cin >> fecha;
				
		for(int i=0; i<vectorCitas.size(); i++){
			if(vectorCitas[i].getDni() == DNIAux){	
				if(vectorCitas[i].getFechaCita() == fecha){
					indice=i;
				}
			}
		}
		
		if(indice==-1){
			cout << endl;
			cout << "No se ha encontrado la cita con los datos seleccionados. " << endl;
			
		}else{
			vectorCitas.erase(vectorCitas.begin()+indice);
			cout << endl;
			cout << "La cita se elimino correctamente. " << endl;
		}
	}	
}

void modificarCita(vector<Cita> &vectorCitas){
	
	if(vectorCitas.size()==0){
		cout << "No hay ninguna cita guardada. " << endl;
		cout << "Asique no es posible realizar ninguna modificación." << endl << endl;
	}else{
		string DNIAux, nombre, apellidos, fecha;
		cout << "DNI del cliente a modificar: ";
		cin >> DNIAux;
		Cita citaAuxiliar;
		
		int opcion=-1, indice;
		
		cout << endl;
		cout << "Introduce la opcion:" << endl ;
		cout << "1) Modificar Apellido." << endl;
    		cout << "2) Modificar Nombre." << endl;
		cout << "3) Modificar Fecha." << endl;
		cout << "0) Salir." << endl;
		
		cout << "opcion: ";
		cin >> opcion;
		
		for(int i=0; i<vectorCitas.size(); i++){
			if(vectorCitas[i].getDni() == DNIAux){	
				indice=i;
				
				switch (opcion) {
					case 0:
						break;
					case 1:
						nombre = vectorCitas[i].getNombre();
						fecha = vectorCitas[i].getFechaCita();
						
						cout << "Nuevo primer apellido: ";
						cin >> apellidos;
						
						citaAuxiliar.setDni(DNIAux);
						citaAuxiliar.setApellidos(apellidos);
						citaAuxiliar.setNombre(nombre);
						citaAuxiliar.setFechaCita(fecha);
						
						break;
					case 2:
						fecha = vectorCitas[i].getFechaCita();
						apellidos = vectorCitas[i].getApellidos();
						
						cout << "Nuevo nombre: ";
						cin >> nombre;
						
						citaAuxiliar.setDni(DNIAux);
						citaAuxiliar.setApellidos(apellidos);
						citaAuxiliar.setNombre(nombre);
						citaAuxiliar.setFechaCita(fecha);
						
						break;
					case 3:
						nombre = vectorCitas[i].getNombre();
						apellidos = vectorCitas[i].getApellidos();
						
						cout << "Nueva fecha: ";
						cin >> fecha;
						
						citaAuxiliar.setDni(DNIAux);
						citaAuxiliar.setApellidos(apellidos);
						citaAuxiliar.setNombre(nombre);
						citaAuxiliar.setFechaCita(fecha);
						
						break;
					default:
						cout << "\nError en la selección de opción.\n" << '\n';
						break;	
				
				}
			}
		}
		
		//eliminar la cita anterior y cargar la nueva al final.
		vectorCitas.push_back(citaAuxiliar);
		
		vectorCitas.erase(vectorCitas.begin()+indice);
	}	
}


int main(){
	menu();
	return 0;
}


#endif
