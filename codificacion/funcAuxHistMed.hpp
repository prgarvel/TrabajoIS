#ifndef _FUNCAUXHISTMED_HPP_
#define _FUNCAUXHISTMED_HPP_

#include "funcionesAuxTratamiento.hpp"
#include "historialMed.hpp"

void cargarHistorialPaciente(string DNIP , vector <HistorialMedico> & v);
bool existeHist(vector <HistorialMedico> v, string DNIP);
void mostrarHistoriales(vector <HistorialMedico> v);

#endif
