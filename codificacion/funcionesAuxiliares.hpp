#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include "paciente.hpp"

using namespace std;

int menu();
int submenuTratamientos();
int submenuHistorial();
string comprobarDni(const int &dni);
bool validarEmail(string email);
bool existePaciente(vector <Paciente> v, string dni);
int submenupaciente();
int submenuAgenda();
string addNombre();
string addApellidos();
string addDni();
string addFecha();
string addSexo();
string addGrupo();
string addEmail();
string addDireccion();
int addTelefono();
int addAltura();
float addPeso();

//Entrada y salida ficheros
bool leerFichero(vector <Paciente> &v);
void escribirFichero(const vector<Paciente> &v);

#endif
