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
