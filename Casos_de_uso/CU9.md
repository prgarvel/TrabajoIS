## Añadir tratamiento
**ID:** 09 **Descripcion:** Introducimos un nuevo tratamiento para un paciente en el sistema
**Actores principales** Administrador
**Precondiciones**
  * El usuario existe en el sistema

**Flujo principal**
  1. El administrador quiere añadir un tratamiento
  2. El administrador busca el usuario en el sistema
  3. El administrador introduce la duracion del tratamiento con la fecha de inicio y la fecha final
  4. El administrador introduce observaciones si son necesarias
  5. El tratamiento se guarda en el sistema
  
**Postcondiciones**
  * El tratamiento tiene que estar guardado en el sistema

**Flujos alternativos**
  2.a. Si el usuario no existe en el sistema se mostrara una venta
