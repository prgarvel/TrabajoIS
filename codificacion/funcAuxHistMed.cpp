#ifndef _FUNCAUXHISTMED_CPP_
#define _FUNCAUXHISTMED_CPP_

#include "funcAuxHistMed.hpp"

HistorialMedico cargarHistorialPaciente(string DNIP){

	string ruta="historiales/"+DNIP+".txt";

	ifstream f(ruta.c_str());

	string DNI, medicacion, dias,observaciones;

	Tratamiento aux;
	vector <Tratamiento> tratamientos;
	HistorialMedico histpaciente;


	if(!f)
	{
		cout << "No se ha podido cargar la base de datos." << endl;
	}
	else{

	while(getline(f, DNI) && f.eof()==0 )	{
	 
		aux.setDNI(DNI);

		getline(f, medicacion);
		aux.setMedicacion(medicacion);

		getline(f, dias);
		aux.setDuracion(atoi(dias.c_str()));

		getline(f, observaciones);
		aux.setObservaciones(observaciones);


		tratamientos.push_back(aux);
	}

	f.close();

	}

	histpaciente.setDNI(DNIP);
	histpaciente.setHistorial(tratamientos);

	return histpaciente;


}

bool existeHist(vector <HistorialMedico> v, string DNIP){

	int i;

	if(v.size()==0){
		return false;
	}

	
	for(i=0;i<v.size();i++){
		if(v[i].getDNI()==DNIP){
			return true;
		}
	}


	return false;

}

void mostrarHistoriales(vector <HistorialMedico> v){

	int i,pos;

	if(v.size()!=0){
		for(i=0;i<v.size();i++){
			cout << i << ") " << v[i].getDNI() << endl;
		}

		cout << endl << "Introduce el historial al que quiera ir (-1 salir): ";
		cin >> pos;

		if(pos>=0 && pos<v.size()){
			v[pos].mostrarHistorial();
		}
	}

}

#endif
