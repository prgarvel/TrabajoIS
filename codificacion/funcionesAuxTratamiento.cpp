#include "funcionesAuxTratamiento.hpp"
Tratamiento anyadirTratamiento()
{

	string DNI;
	string medicacion;
	int duracion;
	string observaciones;
	string clr;


	getline(cin, clr);

	cout << "Introduce el DNI del paciente: ";
	//cin >> DNI;
	getline(cin, DNI);

	//Si no existe el paciente que no pueda introducirse el tratamiento
	/*
	if(exitePaciente(DNI)==false){
		cout << "El paciente no exite" << endl;
		exit(-1);
	}
	*/
	
	Tratamiento elemento(DNI);

	cout << "Introduce la medicacion: ";
	//cin >> medicacion;
	getline(cin, medicacion);

	elemento.setMedicacion(medicacion);

	cout << "Introduce la duracion (en dias): ";
	cin >> duracion;

	elemento.setDuracion(duracion);

	int opcion;

	cout << "¿Quieres introducir alguna observacion?" << endl << "1) Si" << endl << "2) No" << endl << "Opcion: ";
	cin >> opcion;

	getline(cin, clr);

	if(opcion==1)
	{
		cout << "Introduce la observacion: ";
		//cin >> observaciones;
		getline(cin, observaciones);
		elemento.setObservaciones(observaciones);

		//getline(cin, clr);
	}



	return elemento;

}

void consultarTratamiento(vector<Tratamiento> v){
	int i=0;
	int pos;
	string clr;

	cout << endl << endl;

	for(i=0;i<v.size();i++)
	{
		cout << i <<") Paciente: " << v[i].getDNI() << " tratamiento: " << v[i].getMedicacion() << endl;
	}

	cout << endl << endl;

	cout << "Seleccione el indice del tratamiento (-1 para salir): ";
	cin >> pos;

	getline(cin, clr);

	if(pos>=0){
		consultarTratamientoExaustivo(pos,v);
	}

}

void consultarTratamientoExaustivo(int pos, vector<Tratamiento> v){

	if(pos >= v.size()){
		cout << endl << "No existe dicho tratamiento" << endl;
	}

	cout << "DNI del paciente: " << v[pos].getDNI() << ".	Medicacion: " << v[pos].getMedicacion() << endl;
	cout << "Duracion: " << v[pos].getDuracion() << ".	Observacion: " << v[pos].getObservaciones() << endl << endl;

}

void eliminarTratamiento(int pos, vector<Tratamiento> v){
	
}