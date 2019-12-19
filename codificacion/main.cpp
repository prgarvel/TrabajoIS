#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "funcionesAuxiliares.hpp"
#include "funcionesAuxTratamiento.hpp"
#include "tratamiento.hpp"
#include "funcAuxHistMed.hpp"

using namespace std;

int main(){

	int opcion=-1;
	int submenu=-1;
	string DNIP;
	int i;

	vector <Tratamiento> tratamientos_en_curso;
	tratamientos_en_curso.resize(0);

	tratamientos_en_curso=CargarTratamientos();

	vector <HistorialMedico> historiales_medicos;
	historiales_medicos.resize(0);

	do{
		opcion=menu();


		switch(opcion)
		{
			case 1:

				break;

			case 2: // Para tratamientos

				do{
					submenu=submenuTratamientos();


					switch(submenu)
					{
						case 1:
							//Tratamiento aux;
							//aux=anyadirTratamiento();
							tratamientos_en_curso.push_back(anyadirTratamiento(historiales_medicos));
							break;

						case 2:
							eliminarTratamiento(tratamientos_en_curso);
							break;

						case 3:
							modificarTratamiento(tratamientos_en_curso);
							break;

						case 4:
							consultarTratamiento(tratamientos_en_curso);
							break;

						case 0:
							break;

						default:
							cout << "Opcion equivicada" << endl << endl;
					}

				}while(submenu!=0);

				break;

			case 3:

				break;

			case 4:// Para historiales
				do{
					submenu=submenuHistorial();


					switch(submenu)
					{
						case 1:
							cout << "Introduce el DNI del paciente al que pertenezca el historial: ";
							cin >> DNIP;
							if(existeHist(historiales_medicos,DNIP)==false) // El historial del paciente no esta cargado
							{
								historiales_medicos.push_back(cargarHistorialPaciente(DNIP));
								cout << endl << "El historial cargado correctamente." << endl;
							}else{
								cout << endl << "El historial del paciente ya esta cargado." << endl;
							}

							break;

						case 2:
							mostrarHistoriales(historiales_medicos);
							break;

						case 0:
							break;

						default:
							cout << "Opcion equivicada" << endl << endl;
					}

				}while(submenu!=0);

				break;

			case 0:
				cout << "Saliendo del sistema." << endl << endl;
				break;

			default:
				cout << "Opcion equivicada" << endl << endl;
		}

	}while(opcion!=0);


	for(i=0;i<historiales_medicos.size();i++){
		historiales_medicos[i].grabarHistorial();
	}


	GuardarTratamientos(tratamientos_en_curso);

	
	return 0;
}

