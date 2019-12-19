#include "citas.hpp"

void Citas::mostrarCita(const string &dni)
{
	int pos = buscarCita(dni);

	if(pos != -1)
	{
		getCitas()[pos].printCita();
	}
	else
	{
		cout << "No se han encontrado citas asociadas a ese paciente" << endl;
	}
}

void Citas::borrarCita(const string &dni)
{
	int pos = buscarCita(dni);

	if(pos != -1)
	{
		_citas.erase(_citas.begin()+pos);
	}
	else
	{
		cout << "No se han encontrado citas asociadas a ese paciente" << endl;
	}
}

void Citas::modificarCita(const string &dni)
{
	int pos = buscarCita(dni);

	if(pos != -1)
	{
		string fecha;
		cout << "Introduzca la nueva fecha de la cita: ";
		cin >> fecha;
		_citas[pos].setFechaCita(fecha);
		cout << "Cita modificada correctamente" << endl;
	}
	else
	{
		cout << "No se han encontrado citas asociadas a ese paciente" << endl;
	}
}

int Citas::buscarCita(const string &dni)
{
	for(int i=0;i<getCitas().size();i++)
	{
		if(getCitas()[i].getDni() == dni)
		{
			return i;
		}
	}

	return -1;
}