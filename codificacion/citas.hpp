#ifndef _CITAS_HPP
#define _CITAS_HPP

#include "cita.hpp"
#include "funcionesAuxiliares.hpp"
#include "funcionesAuxiliaresCitas.hpp"
#include "funcionesAuxTratamiento.hpp"
#include "paciente.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
		bool existeFecha(string fecha, string hora);
		void listadoCitas();
		void borrarCita();
		void anyadirCita(vector <Paciente> v);
		void modificarCita();
		int buscarCita(const string &dni);//Para que te devuelva la posición de la cita en el vector y ya decidas que hacer con la cita (eliminarla, modificarla, etc...)
		void cargarAgenda();
		void guardarAgenda();

};
#endif
