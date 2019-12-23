#include "funcionesAuxiliares.hpp"

int menu(){
	int opcion=-1;

	cout << endl;
	cout << "Introduce la opcion:" << endl << "1) Operaciones sobre paciente." << endl <<"2) Operaciones sobre tratamientos" << endl;
	cout << "3) Operaciones sobre la agenda." << endl << "4) Operaciones sobre historiales." << endl << "0) Salir" << endl << "Opcion: ";
	cin >> opcion;

	cout << endl;

	return opcion;

}

int submenuTratamientos(){
	int opcion=-1;

	cout << endl;
	cout << "Operaciones sobre tratamientos:" << endl << "1) Añadir tratamiento." << endl << "2) Eliminar tratamiento" << endl;
	cout << "3) Modificar tratamiento" << endl << "4) Consultar tratamiento." << endl << "0) Salir" << endl << "Opcion: ";
	cin >> opcion;

	cout << endl;

	return opcion;
}

int submenuHistorial(){
	int opcion=-1;

	cout << endl;
	cout << "Operaciones sobre historiales:" << endl << "1) Cargar historial de un paciente." << endl << "2) Consultar historial de un paciente" << endl << "0) Salir" << endl << "Opcion: ";
	cin >> opcion;

	cout << endl;

	return opcion;
}

string comprobarDni(const int &dni)
{
	string letras = "TRWAGMYFPDXBNJZSQVHLCKE";
	int indice = dni%23;
	return letras.substr(indice,1);
}

bool validarEmail(string email)
{
   const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
   return regex_match(email, pattern);
}

bool existePaciente(vector <Paciente> v, string dni){

	int i;

	for(i=0;i<v.size();i++){
		if(v[i].getDni()==dni){
			return true;
		}

	}

	return false;
} 

int submenupaciente(){

	int opcion=-1;

	cout << endl;
	cout << "Operaciones sobre pacientes:" << endl << "1) Añadir paciente." << endl << "2) Eliminar paciente" << endl;
	cout << "3) Modificar datos del paciente" << endl << "4) Consultar paciente." << endl << "0) Salir" << endl << "Opcion: ";
	cin >> opcion;

	cout << endl;

	return opcion;

}

int submenuAgenda(){

	int opcion=-1;

	cout << endl;
	cout << "Operaciones sobre agenda:" << endl << "1) Añadir cita." << endl << "2) Eliminar cita" << endl;
	cout << "3) Modificar cita" << endl << "4) Consultar cita." << endl << "0) Salir" << endl << "Opcion: ";
	cin >> opcion;

	cout << endl;

	return opcion;

}

string addNombre()
{
	string cadena = "Sin definir", aux;
	int opcion = -1;
	cout << "¿El nombre del paciente es simple o compuesto?\n\t1) Simple\n\t2) Compuesto\n\nEscoja una opción: ";
	cin >> opcion;

	while(opcion != -1)
	{
		switch(opcion)
		{
			case -1:
			break;

			case 1:
				cout << "Introduzca el nombre del paciente: ";
				cin >> cadena;
				opcion = -1;
			break;
			case 2:
				cout << "Introduzca el primer nombre del paciente: ";
				cin >> cadena;
				cout << "Introduzca el segundo nombre del paciente: ";
				cin >> aux;
				cadena += " " + aux;
				opcion = -1;
			break;

			default:
				cout << "Opción incorrecta, inténtelo de nuevo" << endl;
				cin >> opcion;
				break;
		}
	}
	
	return cadena;
}

string addApellidos()
{
	string cadena;
	cin.clear();
	cin.ignore(numeric_limits<int>::max(),'\n');
	cout << "Introduzca los apellidos del paciente: ";
	getline(cin,cadena);

	return cadena;
}

string addDni()
{
	string cadena, letra;
	int digitos;
	
	cout << "Introduzca el dni del paciente (EJEMPLO: 00000000C): ";
	cin >> cadena;

	if(cadena.size() < 9)
	{
		return "indefinido";
	}

	digitos = atoi(cadena.substr(0,8).c_str());
	letra = cadena.substr(8,1);

	if(comprobarDni(digitos) == letra)
	{
		cout << "Dni correcto" << endl;
	}
	else
	{
		cout << "Dni Incorrecto, defínalo de nuevo más adelante" << endl;
		cadena = "indefinido";
	}

	return cadena;
}

string addFecha()
{
	int dia, mes, year;
	string fecha;

	cout << "Introduzca el día en valor númerico (Ejemplo 31): ";
	cin >> dia;

	cout << "Introduzca el mes en valor númerico (Ejemplo 12): ";
	cin >> mes;

	cout << "Introduzca el año (Ejemplo 1980): ";
	cin >> year;

	if(dia < 1 || dia > 31 || mes < 1 || mes > 12 || year < 1910 )
	{
		cout << "Opción no válida, se estable el valor como no definido" << endl;
		return "Sin definir";
	}

	fecha = to_string(dia) + "/" + to_string(mes) + "/" + to_string(year);

	return fecha;
}

string addSexo()
{
	int opcion;
	cout << "Introduzca 1 si es mujer o 0 si es hombre: ";
	cin >> opcion;

	if(opcion == 1)
	{
		return "Mujer";
	}
	else if(opcion == 0)
	{
		return "Hombre";
	}
	else
	{
		cout << "Opción no válida, se estable el valor como no definido" << endl;
		return "Sin definir";
	}
}

string addGrupo()
{
	int grupo;
	int signo;
	string sangre;

	cout << "Elija entre los siguientes tipos de grupos sanguíneos (introduzca el número que le corresponda a cada opción): " << endl;
	cout << "1)AB\n2)A\n3)B\n4)O\n\tIntroduzca una opción: ";
	cin >> grupo;

	switch(grupo)
	{
		case 1:
			sangre = "AB";
		break;

		case 2:
			sangre = "A";
		break;

		case 3:
			sangre = "B";
		break;

		case 4:
			sangre = "O";
		break;

		default:
			cout << "Opción no válida, se estable el valor como no definido" << endl;
			sangre = "Sin definir";
			return sangre;
	}

	cout << "Indique si el grupo es positivo o negativo (1 positivo, 0 negativo): ";
	cin >> signo;

	switch(signo)
	{
		case 0:
			sangre += "-";
		break;

		case 1:
			sangre += "+";
		break;

		default:
			cout << "Opción no válida, se estable el valor como no definido" << endl;
			sangre = "Sin definir";
	}

	return sangre;
}

string addEmail()
{
	string cadena;
	cin.clear();
	cin.ignore(numeric_limits<int>::max(),'\n');
	cout << "Introduzca el email: ";
	cin >> cadena;

	if(validarEmail(cadena))
	{
		return cadena;
	}
	else
	{
		cout << "Opción no válida, se estable el valor como no definido" << endl;
		return "Sin definir";
	}
}

string addDireccion()
{
	string cadena;
	string nombre;
	int opcion;
	
	cout << "Introduzca el tipo de vía\n\t1) Calle\n\t2) Avenida\n\t3) Bulevar\n\t4) Callejón\n\t5) Camino\n\t6) Carretera\n\t7) Corredera\n\t8) Pasaje\n\t9) Plaza\n\t10) Paseo marítimo\n\t11) Urbanización\n\t12) Otro tipo de vía\n\nElija un tipo: ";
	cin >> opcion;
	switch(opcion)
	{
		case 1:
			cadena = "Calle";
		break;

		case 2:
			cadena = "Avenida";
		break;

		case 3:
			cadena = "Bulevar";
		break;

		case 4:
			cadena = "Callejón";
		break;

		case 5:
			cadena = "Camino";
		break;

		case 6:
			cadena = "Carretera";
		break;

		case 7:
			cadena = "Corredera";
		break;

		case 8:
			cadena = "Pasaje";
		break;

		case 9:
			cadena = "Plaza";
		break;

		case 10:
			cadena = "Paseo marítimo";
		break;

		case 11:
			cadena = "Urbanización";
		break;

		case 12:
			cadena = "Otro tipo de vía";
		break;

		default:
			cout << "Opción no encontrada, se asigna por defecto: Calle" << endl;
		break;
	}
	cin.clear();
	cin.ignore(numeric_limits<int>::max(),'\n');
	cout << "Nombre de la vía: ";
	getline(cin,nombre);
	cadena += " " + nombre;

	cout << "Número: ";
	cin >> nombre;
	cadena += " " + nombre;

	cin.clear();
	cin.ignore(numeric_limits<int>::max(),'\n');
	cout << "Resto de detalles (escalera, piso, número, letra, bloque, etc): ";
	getline(cin,nombre);
	cadena += " " + nombre;

	return cadena;
}

int addTelefono()
{
	int telefono;

	cout << "Indique el número de teléfono (fijo o móvil): ";
	cin >> telefono;

	if(to_string(telefono).size() != 9)
	{
		cout << "Formato de teléfono no indentificado, vuelva a intentarlo" << endl;
		return -1;
	}

	return telefono;
}

int addAltura()
{
	int altura;

	cout << "Introduzca la altura del paciente en centímetros: ";
	cin >> altura;

	if(to_string(altura).size() < 2 || to_string(altura).size() > 3)
	{
		cout << "La altura introducida no se corresponde con ningún ser humano conocido" << endl;
		return -1;
	}

	return altura;
}

float addPeso()
{
	float peso;

	cout << "Indique el peso del paciente en kilogramos: ";
	cin >> peso;

	return peso;
}

bool leerFichero(vector <Paciente> &v)
{
	ifstream f("BD/pacientes.txt");
	Paciente aux;
	string dni, nombre, apellidos, fecha, sexo, grupo, email, direccion, telefono, peso, altura;

	if(!f)
	{
		return false;
	}
	else
	{
		while(getline(f,dni) && f.eof() == 0)
		{
			aux.setDni(dni);

			getline(f,nombre);
			aux.setNombre(nombre);

			getline(f,apellidos);
			aux.setApellidos(apellidos);

			getline(f,fecha);
			aux.setFecha(fecha);

			getline(f,sexo);
			aux.setSexo(sexo);

			getline(f,grupo);
			aux.setGrupo(grupo);

			getline(f,email);
			aux.setEmail(email);

			getline(f,direccion);
			aux.setDireccion(direccion);

			getline(f,telefono);
			aux.setTelefono(atoi(telefono.c_str()));

			getline(f,peso);
			aux.setPeso(atoi(peso.c_str()));

			getline(f,altura);
			aux.setAltura(atof(altura.c_str()));

			v.push_back(aux);
			
		}
	
	}
	
	f.close();

	return true;
}

void escribirFichero(const vector<Paciente> &v)
{
	ofstream f("BD/pacientes.txt");

	for(int i=0;i<v.size();i++)
	{
		f << v[i].getDni() << endl;
		f << v[i].getNombre() << endl;
		f << v[i].getApellidos() << endl;
		f << v[i].getFecha() << endl;
		f << v[i].getSexo() << endl;
		f << v[i].getGrupo() << endl;
		f << v[i].getEmail() << endl;
		f << v[i].getDireccion() << endl;
		f << v[i].getTelefono() << endl;
		f << v[i].getAltura() << endl;
		f << v[i].getPeso() << endl;
	}

	f.close();
}