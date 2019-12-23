#ifndef _FUNCIONESAUXTRATAMIENTO_HPP_
#define _FUNCIONESAUXTRATAMIENTO_HPP_

#include "tratamiento.hpp"
#include "historialMed.hpp"
#include "paciente.hpp"
#include <vector>
#include <fstream>
#include <stdio.h>  

void anyadirTratamiento(vector <Tratamiento>  & trat, vector <HistorialMedico> &v, vector <Paciente> p);
void consultarTratamiento(vector<Tratamiento> v);
void consultarTratamientoExaustivo(int pos, vector<Tratamiento> v);
void eliminarTratamiento(vector<Tratamiento> & v);
void modificarTratamiento(vector<Tratamiento> & v, vector <HistorialMedico> &vh);
string ModMedicacion();
int ModDuracion();
string ModObservaciones();
vector <Tratamiento> CargarTratamientos();
void GuardarTratamientos(vector <Tratamiento> v);
#endif
