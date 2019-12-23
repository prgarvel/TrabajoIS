#include "funcionesAuxiliaresPaciente.hpp"

int buscarPaciente(const vector<Paciente> &v, const string &dni)
{
	for(int i=0;i<v.size();i++)
	{
		if(v[i].getDni() == dni)
		{
			return i;
		}
	}
	return -1;
}

void anyadirPaciente(vector <Paciente> & v){

	Paciente aux;
	string dni;

	dni=addDni();

	if ( existePaciente(v, dni)==false )
	{
		aux.setDni(dni);
		aux.setNombre(addNombre());
		aux.setApellidos(addApellidos());
		aux.setFecha(addFecha());
		aux.setSexo(addSexo());
		aux.setGrupo(addGrupo());
		aux.setEmail(addEmail());
		aux.setDireccion(addDireccion());
		aux.setTelefono(addTelefono());
		aux.setAltura(addAltura());
		aux.setPeso(addPeso());

		v.push_back(aux);

	}
	else
	{
		cout << endl << "El paciente ya se encuentra registrado en el sistema." << endl;
	}


}

void eliminarPaciente(vector <Paciente> &v){

	int pos,i;

	if(v.size()!=0)
	{
		for(i=0;i<v.size();i++)
		{
			cout << i <<") Paciente: " << v[i].getDni() << " , nombre: " << v[i].getApellidos() << " , " << v[i].getNombre() << endl;
		}

		cout << endl << endl;

		cout << "Seleccione el indice del paciente que quiera eliminar (-1 para salir): ";
		cin >> pos;

		if(pos != -1 && pos < v.size())
		{
			v.erase(v.begin()+pos);
		}
		else
		{
			cout << "Paciente no válido" << endl;
		}

		
		
	}else
	{
		cout << "No hay pacientes disponibles" << endl;
	}

}

void consultarPacientes(vector <Paciente> &v){

	int pos;

	if(v.size()!=0)
	{
		for(int i=0;i<v.size();i++)
		{
			cout << i <<") Paciente: " << v[i].getDni() << " , nombre: " << v[i].getApellidos() << " , " << v[i].getNombre() << endl;
		}

		cout << endl << endl;

		cout << "Seleccione el indice del paciente que quiera consultar (-1 para salir): ";
		cin >> pos;

		if(pos != -1)
		{
			v[pos].printPaciente();
		}
		
	}
	else
	{
		cout << "No hay pacientes disponibles" << endl;
	}

}

void modificarPaciente(vector <Paciente> & v){

	int pos, opcion = 0;

	if(v.size() > 0)
	{
		for(int i=0;i<v.size();i++)
		{
			cout << i <<") Paciente: " << v[i].getDni() << " , nombre: " << v[i].getApellidos() << " , " << v[i].getNombre() << endl;
		}

		cout << endl << endl;

		cout << "Seleccione el indice del paciente que quiera consultar (-1 para salir): ";
		cin >> pos;


		while(pos != -1)
		{
			cout << "¿Qué desea modificar?\n\t1) Nombre\n\t2) Apellidos\n\t3) Fecha de nacimineto\n\t4) Sexo\n\t5) Grupo sanguíneo\n\t6) Correo electrónico\n\t7) Dirección\n\t8) Teléfono\n\t9) Altura\n\t10) Peso\n\t-1) Volver atrás\n\nEscoja una opción: ";
			cin >> opcion;
			
			switch(opcion)
			{
				case -1:
					pos = -1;
				break;

				case 1:
					v[pos].setNombre(addNombre());
					cout << "¿Desea modificar algún otro parámetro?\n\t1) Si\n\t0) No: ";
					cin >> opcion;
					if(opcion != 1)
					{
						pos = -1;
					}
				break;

				case 2:
					v[pos].setApellidos(addApellidos());
					cout << "¿Desea modificar algún otro parámetro?\n\t1) Si\n\t0) No: ";
					cin >> opcion;
					if(opcion != 1)
					{
						pos = -1;
					}
				break;

				case 3:
					v[pos].setFecha(addFecha());
					cout << "¿Desea modificar algún otro parámetro?\n\t1) Si\n\t0) No: ";
					cin >> opcion;
					if(opcion != 1)
					{
						pos = -1;
					}
				break;

				case 4:
					v[pos].setSexo(addSexo());
					cout << "¿Desea modificar algún otro parámetro?\n\t1) Si\n\t0) No: ";
					cin >> opcion;
					if(opcion != 1)
					{
						pos = -1;
					}
				break;

				case 5:
					v[pos].setGrupo(addGrupo());
					cout << "¿Desea modificar algún otro parámetro?\n\t1) Si\n\t0) No";
					cin >> opcion;
					if(opcion != 1)
					{
						pos = -1;
					}
				break;

				case 6:
					v[pos].setEmail(addEmail());
					cout << "¿Desea modificar algún otro parámetro?\n\t1) Si\n\t0) No: ";
					cin >> opcion;
					if(opcion != 1)
					{
						pos = -1;
					}
				break;

				case 7:
					v[pos].setDireccion(addDireccion());
					cout << "¿Desea modificar algún otro parámetro?\n\t1) Si\n\t0) No";
					cin >> opcion;
					if(opcion != 1)
					{
						opcion = -1;
					}
				break;

				case 8:
					v[pos].setTelefono(addTelefono());
					cout << "¿Desea modificar algún otro parámetro?\n\t1) Si\n\t0) No:";
					cin >> opcion;
					if(opcion != 1)
					{
						pos = -1;
					}
				break;

				case 9:
					v[pos].setAltura(addAltura());
					cout << "¿Desea modificar algún otro parámetro?\n\t1) Si\n\t0) No";
					cin >> opcion;
					if(opcion != 1)
					{
						pos = -1;
					}
				break;

				case 10:
					v[pos].setPeso(addPeso());
					cout << "¿Desea modificar algún otro parámetro?\n\t1) Si\n\t0) No: ";
					cin >> opcion;
					if(opcion != 1)
					{
						pos = -1;
					}
				break;

				default:
					cout << "Opción incorrecta, inténtelo de nuevo" << endl;
				break;
			}
		}
	}
}