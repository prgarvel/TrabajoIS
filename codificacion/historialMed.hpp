#ifndef _HISTORIALMED_HPP_
#define _HISTORIALMED_HPP_

#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "tratamiento.hpp"

using namespace std;

class HistorialMedico{
	private:
		string _DNI;
		vector <Tratamiento> _historial;

	public:
		
	HistorialMedico(){};

	string getDNI(){
		return _DNI;
	}

	void setDNI(string DNI){
		_DNI=DNI;
	}

	void anyadirAlHistorial(Tratamiento t){
		_historial.push_back(t);
	}

	void setHistorial(vector <Tratamiento> historial){
		_historial=historial;
	}

	vector <Tratamiento> getHistorial(){
		return _historial;
	}

	void tratamientoEspecifico(int pos);

	void mostrarHistorial();

	void grabarHistorial();

};


#endif
