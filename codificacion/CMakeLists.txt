CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(Proyecto_IS)
SET(CMAKE_CXX_FLAGS "-std=c++11 ")
ADD_EXECUTABLE(main.x main.cpp paciente.cpp cita.cpp citas.cpp tratamiento.cpp historialMed.cpp funcionesAuxiliares.cpp  funcionesAuxTratamiento.cpp  funcAuxHistMed.cpp funcionesAuxiliaresPaciente.cpp funcionesAuxiliaresCitas.cpp)