## Eliminar paciente
**ID:** 4 **Descripcion:** Eliminamos el registro de un paciente en el sistema.

**Actores principales** Administrador.

**Precondiciones**
 * El paciente debe estar registrado previamente.
 
**Flujo principal**
  1. El administrador selecciona la opción de eliminar paciente.
  2. A continuación, busca el paciente a eliminar.
  3. Encuentra al paciente a eliminar.
  4. Selecciona la opción de eliminar paciente.
  5. El paciente queda borrado del sistema.
  
**Postcondiciones**
  * No deberá volver a poder listarse ese paciente.

**Flujos alternativos**
  * En caso de que el paciente no se encuentre registrado en el sistema devolverá un mensaje de aviso.
