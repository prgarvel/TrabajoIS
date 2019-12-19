#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

int menu();
int submenuTratamientos();
int submenuHistorial();
string comprobarDni(const int &dni);
bool validarEmail(string email);

#endif
