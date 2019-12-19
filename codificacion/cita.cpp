#include "cita.hpp"

void Cita::printCita(){

    cout << "Paciente: " << getApellidos() << ", " << getNombre() << endl;
    cout << "DNI: " << getDni() << endl;
    cout << "Fecha de la cita: " << getFechaCita() << endl;
}
