#ifndef _FUNCIONESAUXTRATAMIENTO_CPP_
#define _FUNCIONESAUXTRATAMIENTO_CPP_

#include "funcionesAuxTratamiento.hpp"
#include "funcAuxHistMed.hpp"
#include <string>
#include "funcionesAuxiliares.hpp"
#include "paciente.hpp"

void anyadirTratamiento(vector <Tratamiento>  & trat, vector <HistorialMedico> &v, vector <Paciente> p)
{

	string DNI;
	string medicacion;
	int duracion,i;
	string observaciones;
	string clr;


	getline(cin, clr);

	cout << "Introduce el DNI del paciente: ";
	//cin >> DNI;
	getline(cin, DNI);

	//Si no existe el paciente que no pueda introducirse el tratamiento
	
	if(existePaciente(p,DNI)==false){
		cout << "El paciente no exite" << endl;
	}else{
	
	
	Tratamiento elemento(DNI);

	cout << "Introduce la medicacion: ";
	//cin >> medicacion;
	getline(cin, medicacion);

	elemento.setMedicacion(medicacion);

	cout << "Introduce la duracion (en dias): ";
	cin >> duracion;

	elemento.setDuracion(duracion);

	int opcion;

	cout << "¿Quieres introducir alguna observacion?" << endl << "1) Si" << endl << "2) No" << endl << "Opcion: ";
	cin >> opcion;

	getline(cin, clr);

	if(opcion==1)
	{
		cout << "Introduce la observacion: ";
		//cin >> observaciones;
		getline(cin, observaciones);
		elemento.setObservaciones(observaciones);

		//getline(cin, clr);
	}
	else{
		elemento.setObservaciones("Ninguna");
	}

	
	if(existeHist(v, DNI)==false){
		string ruta="historiales/"+DNI+".txt";
		ifstream f(ruta.c_str());
		
		if( f.is_open() ){
			f.close();
			cargarHistorialPaciente(DNI,v);

			for(i=0;i<v.size();i++){
				if(v[i].getDNI()==DNI){
					v[i].anyadirAlHistorial(elemento);
				}
			}
		}else{
			HistorialMedico histpaciente;
			histpaciente.setDNI(DNI);
			histpaciente.anyadirAlHistorial(elemento);
			v.push_back(histpaciente);
		}

	}else{

		for(i=0;i<v.size();i++){
			if(v[i].getDNI()==DNI){
				v[i].anyadirAlHistorial(elemento);
			}
		}

	}
	trat.push_back(elemento);
	}

}

void consultarTratamiento(vector<Tratamiento> v){
	int i=0;
	int pos;
	string clr;

	cout << endl << endl;

	if(v.size()!=0)
	{
		for(i=0;i<v.size();i++)
		{
			cout << i <<") Paciente: " << v[i].getDNI() << " tratamiento: " << v[i].getMedicacion() << endl;
		}

		cout << endl << endl;

		cout << "Seleccione el indice del tratamiento (-1 para salir): ";
		cin >> pos;

		getline(cin, clr);

		if(pos>=0){
			consultarTratamientoExaustivo(pos,v);
		}
	}else
	{
		cout << "No hay tratamientos disponibles" << endl;
	}

}

void consultarTratamientoExaustivo(int pos, vector<Tratamiento> v){

	if(pos >= v.size()){
		cout << endl << "No existe dicho tratamiento" << endl;
	}

	cout << "DNI del paciente: " << v[pos].getDNI() << ".	Medicacion: " << v[pos].getMedicacion() << endl;
	cout << "Duracion: " << v[pos].getDuracion() << ".	Observacion: " << v[pos].getObservaciones() << endl << endl;

}

void eliminarTratamiento(vector<Tratamiento> & v){

	int pos,i;
	vector<Tratamiento> aux;

	if(v.size()!=0)
	{
		for(i=0;i<v.size();i++)
		{
			cout << i <<") Paciente: " << v[i].getDNI() << " tratamiento: " << v[i].getMedicacion() << endl;
		}

		cout << endl << endl;

		cout << "Seleccione el indice del tratamiento que quiera eliminar (-1 para salir): ";
		cin >> pos;

		for(i=0 ;i<v.size(); i++)
		{
			if(pos!=i)
			{
				aux.push_back(v[i]);
			}
		}

		v=aux;


	}else
	{
		cout << "No hay tratamientos disponibles" << endl;
	}
	
}

void modificarTratamiento(vector<Tratamiento> & v, vector <HistorialMedico> &vh){

	int pos,i,opcion;
	vector <int> llaves;
	llaves.resize(3);
	string clr;

	llaves[0]=0;
	llaves[1]=0;
	llaves[2]=0;

	if(v.size()!=0)
	{
		for(i=0;i<v.size();i++)
		{
			cout << i <<") Paciente: " << v[i].getDNI() << " tratamiento: " << v[i].getMedicacion() << endl;
		}

		cout << endl << endl;

		cout << "Seleccione el indice del tratamiento que quiera modificar (-1 para salir): ";
		cin >> pos;

		do
		{
			cout << endl << endl;
			if(llaves[0]==0)
			{
				cout << "1) Modificar la medicacion." << endl;
			}
			if(llaves[1]==0)
			{
				cout << "2) Modificar la duracion." << endl;
			}
			if(llaves[2]==0)
			{
				cout << "3) Modificar las observaciones." << endl;
			}

			//getline(cin, clr);
			cout << "0) Salir" << endl << endl << "Opcion:";
			cin >> opcion;

			// Funciones de modificacion, falta añadirlos al historial cuando este
			if(llaves[0]==0 && opcion==1)
			{
				string nuevaMedicacion;
				nuevaMedicacion=ModMedicacion();
				v[pos].setMedicacion(nuevaMedicacion);
				llaves[0]=1;
			}
			if(llaves[1]==0 && opcion==2)
			{
				int nuevaDuracion;
				nuevaDuracion=ModDuracion();
				v[pos].setDuracion(nuevaDuracion);
				llaves[1]=1;
			}
			if(llaves[2]==0 && opcion==3)
			{
				string nuevasObservaciones;
				nuevasObservaciones=ModObservaciones();
				v[pos].setObservaciones(nuevasObservaciones);
				llaves[2]=1;	
			}

		}while(opcion!=0);

		if(existeHist(vh, v[pos].getDNI())==false){
			string ruta="historiales/"+v[pos].getDNI()+".txt";
			ifstream f(ruta.c_str());
			
			if( f.is_open() ){
				f.close();
				cargarHistorialPaciente(v[pos].getDNI(),vh);

				for(i=0;i<vh.size();i++){
					if(vh[i].getDNI()==v[pos].getDNI()){
						vh[i].anyadirAlHistorial(v[pos]);
					}
				}
			}else{
				HistorialMedico histpaciente;
				histpaciente.setDNI(v[pos].getDNI());
				histpaciente.anyadirAlHistorial(v[pos]);
				vh.push_back(histpaciente);
			}

		}else{

			for(i=0;i<vh.size();i++){
				if(vh[i].getDNI()==v[pos].getDNI()){
					vh[i].anyadirAlHistorial(v[pos]);
				}
			}

		}

	}else
	{
		cout << "No hay tratamientos disponibles" << endl;
	}
	

}

string ModMedicacion()
{
	string med,clr;

	getline(cin, clr);
	cout << endl << "Introduce la nueva medicacion: ";
	getline(cin, med);

	return med;
}

int ModDuracion()
{
	int duracion;

	cout << endl << "Introduce la nueva duracion del tratamiento: ";
	cin >> duracion;

	return duracion;
}

string ModObservaciones()
{
	string observaciones;
	string clr;

	getline(cin, clr);

	cout << endl << "Introduce las nuevas observaciones: ";
	getline(cin, observaciones);

	return observaciones;
}

vector <Tratamiento> CargarTratamientos(){
	
	ifstream f("BD/tratamientos_curso.txt");
	string DNI, medicacion, dias,observaciones;
	string nulo="";


	Tratamiento aux;
	vector <Tratamiento> tratamientos_en_curso;


	if(!f)
	{
		cout << "Tratamientos: " << endl;
		cout << "Base de datos no encontrada o sin crear" << endl;
	}
	else{

	while(getline(f, DNI) && f.eof()==0)	{
	
		aux.setDNI(DNI);

		//cout << f.eof() << endl;

		getline(f, medicacion);
		aux.setMedicacion(medicacion);

		getline(f, dias);
		aux.setDuracion(atoi(dias.c_str()));

		getline(f, observaciones);
		aux.setObservaciones(observaciones);
		//cout << "DNI: " << DNI << " Medicacion: " << medicacion << endl << "Duracion: " << dias << " Observaciones: " << observaciones << endl << endl;

		tratamientos_en_curso.push_back(aux);
	}

	f.close();

	}

	return tratamientos_en_curso;
}

void GuardarTratamientos(vector <Tratamiento> v){
	ofstream f("BD/tratamientos_curso.txt");

	int i;

	for(i=0;i<v.size();i++)
	{
		f << v[i].getDNI() << endl;
		f << v[i].getMedicacion() << endl;
		f << v[i].getDuracion() << endl;
		f << v[i].getObservaciones() << endl;
	}

}

#endif
