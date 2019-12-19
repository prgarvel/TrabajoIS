#ifndef _CITAS_HPP
#define _CITAS_HPP

#include "cita.hpp"
#include <iostream>
#include <string>
#include <vector>

class Citas
{

	private:

		vector<Cita> _citas;


	public:

		Citas(){};
		~Citas(){};

		inline void setCitas(const vector<Cita> &v) { _citas = v; }
		inline void clearCitas() { _citas.clear(); } //borrar todas las citas

		inline vector<Cita> getCitas() const { return _citas; }

		inline void addCita(const Cita &c) { _citas.push_back(c); }
		void mostrarCita(const string &dni);
		void borrarCita(const string &dni);
		void modificarCita(const string &dni);
		int buscarCita(const string &dni);//Para que te devuelva la posición de la cita en el vector y ya decidas que hacer con la cita (eliminarla, modificarla, etc...)

};
#endif