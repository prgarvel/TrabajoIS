#include "citas.hpp"


bool Citas::existeFecha(string fecha, string hora){

	int i;

	for(i=0;i<_citas.size();i++){
		if(_citas[i].getFechaCita()==fecha && _citas[i].getHoraCita()==hora){
			return true;
		}
	}

	return false;
}

void Citas::listadoCitas(){

	int i, pos;

	if(_citas.size()!=0){

		for(i=0; i<_citas.size();i++){
			cout << i << ") " << _citas[i].getDni() << " Fecha cita: " << _citas[i].getFechaCita() << " Hora: " << _citas[i].getHoraCita() << endl; 
		}

		cout << endl << endl << "Selecione el indice de la cita si quiere ver las observaciones o -1 para salir" << endl;
		cout << "Opcion: ";
		cin >> pos;

		if(pos>=0 && pos < _citas.size() ){
			_citas[pos].printCita();
		}

	}
	else{
		cout << "La agenda esta vacia." << endl;
	}

}

void Citas::borrarCita()
{
	int i, pos;

	if(_citas.size()!=0){

		for(i=0; i<_citas.size();i++){
			cout << i << ") " << _citas[i].getDni() << " Fecha cita: " << _citas[i].getFechaCita() << " Hora: " << _citas[i].getHoraCita() << endl; 
		}

		cout << endl << endl << "Selecione el indice de la cita si quiere ver las observaciones o -1 para salir" << endl;
		cout << "Opcion: ";
		cin >> pos;

		if(pos>=0 && pos < _citas.size() )
		{
			_citas.erase(_citas.begin()+pos);
		}
		else if (pos >= _citas.size())
		{
			cout << "Error no existe dicho indice." << endl;
		}
		else
		{
			cout << "No se han encontrado citas asociadas a ese paciente" << endl;
		}
	}
	else{
		cout << "La agenda esta vacia." << endl;
	}
}

void Citas::anyadirCita(vector <Paciente> v){

	string dni,fecha,hora, observaciones;
	int opc=0;
	Cita aux;



	cout << "Introduce el DNI del paciente: ";
	cin >> dni;
	if(existePaciente(v,dni)==true){

		aux.setDni(dni);

		fecha=tomarFecha();
		aux.setFechaCita(fecha);

		hora=tomarHora();
		aux.setHoraCita(hora);

		cout << "¿Quiere introducir alguna observacion?" << "\n\t0) No\n\t1) Si\nEscoja una opción: ";
		cin >> opc;

		if(opc==0){
			observaciones="Ninguna";
			aux.setObservaciones(observaciones);
		}else{
			observaciones=ModObservaciones();
			aux.setObservaciones(observaciones);
		}

	}

	if(existeFecha(fecha,hora)==false){
		_citas.push_back(aux);
	}
	else{
		cout << "Ya hay asignada una cita que coincide en fecha y hora" << endl;
	}

}

void Citas::modificarCita()
{
	int i, pos,opc;
	string dni,fecha,hora, observaciones;
	Cita aux;

	if(_citas.size()!=0){

		for(i=0; i<_citas.size();i++){
			cout << i << ") " << _citas[i].getDni() << " Fecha cita: " << _citas[i].getFechaCita() << " Hora: " << _citas[i].getHoraCita() << endl; 
		}

		cout << endl << endl << "Selecione el indice de la cita si quiere ver las observaciones o -1 para salir" << endl;
		cout << "Opcion: ";
		cin >> pos;

		aux=_citas[pos];

		if(pos>=0 && pos < _citas.size())
		{

			cout << endl <<"1) Modificar la fecha." << endl << "2)Modificar hora." << endl << "3)Modificar observaciones" << endl << "-1)Salir" << endl << "Opcion: ";
			cin >> opc;
			do{
				switch(opc){
					case 1:
						fecha=tomarFecha();
						aux.setFechaCita(fecha);
						break;

					case 2:
						hora=tomarHora();
						aux.setHoraCita(hora);
						break;


					case 3:
						observaciones=ModObservaciones();
						aux.setObservaciones(observaciones);
						break;

					case -1:
						break;

					default:
						cout << "Opcion equivocada.";

				}
			}while(opc==-1);


			if(existeFecha(fecha,hora)==false){
				_citas[pos]=aux;
			}
			else{
				cout << "Ya hay una cita dicho dia a dicha hora." << endl;
			}
		

		}
		else
		{
			cout << "No se han encontrado citas asociadas a ese paciente" << endl;
		}

	}
	else{
		cout << "La agenda esta vacia." << endl;
	}


}

int Citas::buscarCita(const string &dni)
{
	for(int i=0;i<getCitas().size();i++)
	{
		if(getCitas()[i].getDni() == dni)
		{
			return i;
		}
	}

	return -1;
}

void Citas::cargarAgenda(){

	ifstream f("BD/agenda.txt");
	string DNI, fecha, hora ,observaciones;

	Cita aux;

	if(!f)
	{
		cout << "Citas: " << endl;
		cout << "Base de datos no encontrada o sin crear" << endl;
	}
	else{


	while(getline(f, DNI) && f.eof()==0)	{
	
		aux.setDni(DNI);

		getline(f, fecha);
		aux.setFechaCita(fecha);

		getline(f, hora);
		aux.setHoraCita(hora);

		getline(f, observaciones);
		aux.setObservaciones(observaciones);

		_citas.push_back(aux);
	}

	f.close();

	}



}


void Citas::guardarAgenda(){

	ofstream f("BD/agenda.txt");

	int i;

	for(i=0;i<_citas.size();i++)
	{
		f << _citas[i].getDni() << endl;
		f << _citas[i].getFechaCita() << endl;
		f << _citas[i].getHoraCita() << endl;
		f << _citas[i].getObservaciones() << endl;
	}

}
