#ifndef _FUNCIONESAUXILIARESPACIENTE_HPP_
#define _FUNCIONESAUXILIARESPACIENTE_HPP_

#include <iostream>
#include <vector>
#include "funcionesAuxiliares.hpp"
#include "paciente.hpp"


using namespace std;

void anyadirPaciente(vector <Paciente> & v);
void eliminarPaciente(vector <Paciente> & v);
void consultarPacientes(vector <Paciente> &v);
void modificarPaciente(vector <Paciente> & v);
int buscarPaciente(const vector<string> &v, const string &dni);

#endif