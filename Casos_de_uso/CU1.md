## Añadir paciente
**ID:** 1 **Descripcion:** Añadimos un paciente al sistema

**Actores principales** Administrador.

**Precondiciones**
 * No debe de estar almacenado previamente el paciente a registrar
 
**Flujo principal**
  1. El administrador selecciona la opción de añadir paciente.
  2. El administrador va completando la información solicitada por el sistema.
  3. El administrador confirma los datos.
  4. El sistema comprueba la no existencia de dicho paciente.
  4. Los datos se guardan en el sistema.
  
**Postcondiciones**
  * Ninguna.

**Flujos alternativos**
  * Si el paciente a registrar ya se encontraba registrado, el sistema no almacena la información.
