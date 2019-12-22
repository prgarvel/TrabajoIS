#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include <stdio.h>
#include <iostream>
#include <string>

#include "cita.hpp"

	void menu();
	void anhadirCita(vector<Cita> &vectorCitas);
	void consultarCita(const vector<Cita> &vectorCitas);
	void eliminarCita(vector<Cita> &vectorCitas);
	void modificarCita(vector<Cita> &vectorCitas);

#endif
