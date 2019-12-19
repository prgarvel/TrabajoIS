#ifndef _TRATAMIENTO_HPP_
#define _TRATAMIENTO_HPP_


#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Tratamiento{
	private:
		string _DNI;
		string _medicacion;
		int _duracion;
		string _observaciones;

	public:
		Tratamiento();
		Tratamiento(string DNI);

		inline string getDNI()
		{
			return _DNI;
		}

		inline void setDNI(string DNI)
		{
			_DNI=DNI;
		}

		inline string getMedicacion()
		{
			return _medicacion;
		}

		inline void setMedicacion(string medicacion)
		{
			_medicacion=medicacion;
		}

		inline int getDuracion()
		{
			return _duracion;
		}

		inline void setDuracion(int duracion)
		{
			_duracion=duracion;
		}

		inline string getObservaciones()
		{
			return _observaciones;
		}

		inline void setObservaciones(string observaciones)
		{
			_observaciones=observaciones;
		}

};

#endif
