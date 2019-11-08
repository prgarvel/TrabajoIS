| Clase: *Paciente* | ||
| :------- | :------: | :----- |
| Clase que almacena la información relativa a un paciente. Se podrá añadir, consultar, modificar y eliminar un paciente |||
| **Datos** | Tipo | Descripción |
| + nombre   | string | Nombre del paciente |
| + apellidos   | string | Apellidos del paciente |
| + dni   | string | DNI del paciente |
| + fecha de nacimiento   | string | Fecha de nacimiento del paciente |
| + sexo   | string | Sexo del paciente |
| + Grupo sanguíneo | string | Medicación recetada por el medico |
| + teléfono   | int | teléfono de contacto del paciente |
| + dirección   | string | dirección postal del paciente |
| + email | string | correo electrónico del paciente |
| + Compañía médica | string | nombre de la compañía a la que pertenezca |
| + Altura | int | Altura en cm del paciente |
| + Peso | float | Peso en kg del paciente |
| + Alergias | string | Posibles alergias que padezca el paciente (medicamentos, alimentarias, etc) |
| + Patologías | string | Lista con las patalogías que padece (en caso de que las padezca) |
| **Métodos** | |||
| Init | Constructor de la clase Paciente | ||
| Añadir paciente | Añade un paciente a nuestro sistema de ficheros | ||
| Eliminar paciente| Elimina un paciente a nuestro sistema de ficheros | ||
| Modificar paciente | Modifica un paciente de nuestro sistema de ficheros | ||
| Consultar paciente | Muestra los datos relativos a un paciente | ||

| Clase: *Tratamiento* | ||
| :------- | :------: | :----- |
| Clase que almacena el tratamiento de un paciente. Se podra añadir, consultar, modificar y eliminar un tratamiento |||
| **Datos** | Tipo | Descripción |
| + dni   | string | DNI del paciente del tratamiento |
| + medicacion | string | Medicación recetada por el medico |
| + duracion | entero | Duracion de la medicación |
| + Observaciones | string | Observaciones realizadas por el médico |
| **Métodos** | |||
| Init | Constructor de la clase tratamiento | ||
| Añadir tratamiento | Añade un tratamiento a a un paciente | ||
| Eliminar tratamiento | Elimina un tratamiento en curso | ||
| Modificar tratamiento | Modifica el tratamiento en curso | ||
| Consultar tratamiento | Consulta un tratamiento de una lista de tratamientos en curso | ||

| Clase: *Cita* | ||
| :------- | :------: | :----- |
| Clase que gestiona las citas de todos los pacientes. Se podra añadir, consultar, modificar y eliminar una cita  |||
| **Datos** | Tipo | Descripción |
| + dni   | string | DNI del paciente |
| + fecha | entero | Fecha de la cita |
| + Observaciones | string | Observaciones referidas a la cita |
| **Métodos** | |||
| Init | Constructor de la clase cita | ||
| Añadir cita | Añade una cita de un paciente a la agenda | ||
| Eliminar cita | Elimina una cita de la agenda | ||
| Modificar cita | Modifica la cita en la agenda | ||
| Consultar cita | Consulta una cita de la lista de citas en la agenda | ||

| Clase: *Agenda* | ||
| :------- | :------: | :----- |
| Clase que gestiona la agenda de citas. Se podra consultar la agenda en la fecha o fechas que se desee |||
| **Datos** | Tipo | Descripción |
| + dni   | string | DNI del paciente |
| + fecha | entero | Fecha de la cita |
| **Métodos** | |||
| Init | Constructor de la clase agenda | ||
| Consultar agenda | Consulta una la lista de citas de la agenda | ||

| Clase: *Historial de citas* | ||
| :------- | :------: | :----- |
| Clase que almacena el listado de las citas de un paciente |||
| **Datos** | Tipo | Descripción |
| + n_historial   | entero | número de historial del paciente |
| + dni   | string | DNI del paciente del tratamiento |
| + listado_Citas | array de tratamiento | Listado de las citas de un paciente |
| **Métodos** | |||
| Init | Constructor de la clase historial de citas | ||
| Añadir historial | Añade al historial del paciente cualquier cita nueva o la modificación de una cita | ||
| Consultar historial | Consultar el historial de un paciente en concreto | ||


| Clase: *Historial de tratamiento* | ||
| :------- | :------: | :----- |
| Clase que almacena el listado de tratamiento de un paciente |||
| **Datos** | Tipo | Descripción |
| + n_historial   | entero | número de historial del paciente |
| + dni   | string | DNI del paciente del tratamiento |
| + listado_tratamientos | array de tratamiento | Listado de los tratamientos de un paciente |
| **Métodos** | |||
| Init | Constructor de la clase historial de tratamientos | ||
| Añadir historial | Añade al historial del paciente cualquier tratamiento nuevo o un tratamiento que se haya modificado | ||
| Consultar historial | Consultar el historial de un paciente en concreto | ||


