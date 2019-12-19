#ifndef _FUNCIONESAUXTRATAMIENTO_HPP_
#define _FUNCIONESAUXTRATAMIENTO_HPP_

#include "tratamiento.hpp"
#include "historialMed.hpp"
#include <vector>
#include <fstream>
#include <stdio.h>  

Tratamiento anyadirTratamiento(vector <HistorialMedico> &v);
void consultarTratamiento(vector<Tratamiento> v);
void consultarTratamientoExaustivo(int pos, vector<Tratamiento> v);
void eliminarTratamiento(vector<Tratamiento> & v);
void modificarTratamiento(vector<Tratamiento> & v);
string ModMedicacion();
int ModDuracion();
string ModObservaciones();
vector <Tratamiento> CargarTratamientos();
void GuardarTratamientos(vector <Tratamiento> v);
#endif
