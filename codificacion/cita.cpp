#include "cita.hpp"

void ActualizarVectorCitas(const std::vector <std::string> &v){
  int tam = v.size();

  v[tam+1].setDni(dni);
  v[tam+1].setNombre(nombre);
  v[tam+1].setApellidos(apellidos);
  v[tam+1].setFechaCita(fechaCita);

}
void printVectorCitas(const std::vector <std::string> &v){
  int tam = v.size();

  for (int i=0; i<tam; i++){
    std::cout << "Paciente: " << v[i].getApellidos() << ", " << v[i].getNombre() << '\n';
    std::cout << "DNI: " << v[i].getDni() << '\n';
    std::cout << "Fecha de la cita: " << v[i].getFechaCita() << '\n';

  }

}
