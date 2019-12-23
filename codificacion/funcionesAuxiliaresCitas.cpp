#include "funcionesAuxiliaresCitas.hpp"
#include <string>
#include <vector>

using namespace std;

string tomarFecha(){

	int dia,mes,anyo,diaValido=0;
	string fecha;

		do{
			cout << "Año de la cita (mínimo año 2019): ";
			cin >> anyo;
			if(anyo<=2018){
				cout << "Año incorrecto" << endl;
			}
		}while(anyo<=2018);

		do{
			cout << "Mes de la cita (en formato numérico): ";
			cin >> mes;
			if(mes <=0 || mes >=13){
				cout << "Mes incorrecto" <<endl;
			}
		}while(mes <=0 || mes >=13);


		do{
			cout << "Día de la cita (en formato numérico): ";
			cin >> dia;
			if( (mes <= 7 && mes%2==1) || (mes>=8 && mes%2==0) ){
				if(dia<1 || dia>=32){
					cout << "Día no válido" << endl;
				}else{
					diaValido=1;
				}
			}else if (mes == 2){
				if( (dia<1 || dia >=29) && anyo%4!=1){
					cout << "Día no válido" << endl;
				}
				else if( (dia<1 || dia >=31) && anyo%4!=0)
				{
					cout << "Día no válido" << endl;
				}else{
					diaValido=1;	
				}
			}
			else
			{
				if(dia<1 || dia>=31){
					cout << "Día no válido" << endl;
				}else{
					diaValido=1;
				}
			}

		}while(diaValido==0);

		fecha = std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anyo);

	return fecha;
}

string tomarHora(){

	int hora,min;
	string horaC;

		do{
			cout << "Introduce la hora de la cita (0-23): ";
			cin >> hora;
			if(hora < 0 && hora >=24){
				cout << "Hora no válida" << endl;
			}
		}while(hora < 0 && hora >=24);

		do{
			cout << "Introduce el minuto de la cita (0-59): ";
			cin >> min;
			if(min < 0 && min >=60){
				cout << "Minutos no válidos" << endl;
			}
		}while(min < 0 && min >=60);

		if(min >=0 && min <10)
		{
			horaC= std::to_string(hora) + ":0" + std::to_string(min);
		}
		else
		{
			horaC= std::to_string(hora) + ":" + std::to_string(min);
		}
		
	return horaC;
}
