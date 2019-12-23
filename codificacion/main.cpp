#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "funcionesAuxiliares.hpp"
#include "funcionesAuxiliaresPaciente.hpp"
#include "funcionesAuxTratamiento.hpp"
#include "tratamiento.hpp"
#include "funcAuxHistMed.hpp"
#include "citas.hpp"
#include "paciente.hpp"

using namespace std;

int main(){

	int opcion=-1;
	int submenu=-1;
	string DNIP;
	int i;
	Citas agenda;
	agenda.cargarAgenda();

	vector <Tratamiento> tratamientos_en_curso;
	tratamientos_en_curso.resize(0);

	tratamientos_en_curso=CargarTratamientos();

	vector <HistorialMedico> historiales_medicos;
	historiales_medicos.resize(0);

	vector <Paciente> pacientes_actuales;
	pacientes_actuales.resize(0);
	bool lectura = leerFichero(pacientes_actuales);

	if(!lectura)
	{
		cout << "Pacientes: " << endl;
		cout << "Base de datos no encontrada o sin crear" << endl;
	}


	do{
		opcion=menu();


		switch(opcion)
		{
			case 1:


				do{
					submenu=submenupaciente();


					switch(submenu)
					{
						case 1:
							anyadirPaciente(pacientes_actuales);
							break;

						case 2:
							eliminarPaciente(pacientes_actuales);
							break;

						case 3:
							modificarPaciente(pacientes_actuales);
							break;

						case 4:
							consultarPacientes(pacientes_actuales);
							break;

						case 0:
							break;

						default:
							cout << "Opcion equivocada" << endl << endl;
							submenu = 0;
					}

				}while(submenu!=0);

				break;

			case 2: // Para tratamientos

				do{
					submenu=submenuTratamientos();


					switch(submenu)
					{
						case 1:
							anyadirTratamiento(tratamientos_en_curso, historiales_medicos, pacientes_actuales);
							break;

						case 2:
							eliminarTratamiento(tratamientos_en_curso);
							break;

						case 3:
							modificarTratamiento(tratamientos_en_curso, historiales_medicos);
							break;

						case 4:
							consultarTratamiento(tratamientos_en_curso);
							break;

						case 0:
							break;

						default:
							cout << "Opcion equivocada" << endl << endl;
					}

				}while(submenu!=0);

				break;

			case 3:
				do{
					submenu=submenuAgenda();


					switch(submenu)
					{
						case 1:
							agenda.anyadirCita(pacientes_actuales);
							break;

						case 2:
							agenda.borrarCita();
							break;

						case 3:
							agenda.modificarCita();
							break;

						case 4:
							agenda.listadoCitas();
							break;

						case 0:
							break;

						default:
							cout << "Opcion equivicada" << endl << endl;
					}

				}while(submenu!=0);
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
								cargarHistorialPaciente(DNIP, historiales_medicos);
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
							cout << "Opcion equivocada" << endl << endl;
					}

				}while(submenu!=0);

				break;

			case 0:
				cout << "Saliendo del sistema." << endl << endl;
				break;

			default:
				cout << "Opcion equivocada" << endl << endl;
		}

	}while(opcion!=0);


	for(i=0;i<historiales_medicos.size();i++){
		historiales_medicos[i].grabarHistorial();
	}


	GuardarTratamientos(tratamientos_en_curso);
	escribirFichero(pacientes_actuales);
	agenda.guardarAgenda();

	
	return 0;
}

