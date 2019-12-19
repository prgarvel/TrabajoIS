#ifndef _HISTORIALMED_CPP_
#define _HISTORIALMED_CPP_

#include "historialMed.hpp"

void HistorialMedico::tratamientoEspecifico(int pos){

	if(pos >= _historial.size()){
		cout << endl << "No existe dicho tratamiento" << endl;
	}

	cout << "DNI del paciente: " << _historial[pos].getDNI() << ".	Medicacion: " << _historial[pos].getMedicacion() << endl;
	cout << "Duracion: " << _historial[pos].getDuracion() << ".	Observacion: " << _historial[pos].getObservaciones() << endl << endl;

}

void HistorialMedico::mostrarHistorial(){

	int i,pos;
	string clr;

	cout << endl << endl;

	for(i=0;i<_historial.size();i++)
	{
		cout << i <<") Paciente: " << _historial[i].getDNI() << " tratamiento: " << _historial[i].getMedicacion() << endl;
	}
		cout << endl << endl;

	cout << "Seleccione el indice del tratamiento (-1 para salir): ";
	cin >> pos;

	getline(cin, clr);

	if(pos>=0 && pos<_historial.size()){
		tratamientoEspecifico(pos);
	}

}

void HistorialMedico::grabarHistorial(){

	string ruta="historiales/"+_DNI+".txt";

	ofstream f(ruta.c_str());

	int i;

	for(i=0;i<_historial.size();i++)
	{
		f << _historial[i].getDNI() << endl;
		f << _historial[i].getMedicacion() << endl;
		f << _historial[i].getDuracion() << endl;
		f << _historial[i].getObservaciones() << endl;
	}

	f.close();

}

#endif
