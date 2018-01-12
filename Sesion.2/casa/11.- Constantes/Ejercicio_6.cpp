/*
Programa para calcular los segundos que
transcurren a lo largo de un tramo horario
de un mismo día
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
																							// Declaracion de variables
	double hora_inicial;
	double minuto_inicial;
	double segundo_inicial;
	
	double hora_final;
	double minuto_final;
	double segundo_final;
	
	double h_inicial_segundos;
	double min_inicial_segundos;
	
	double h_final_segundos;
	double min_final_segundos;
	
	double segundos_totales;
	
	/////////////////////////////////////////////////////////////////////////////			// Inclusión de datos			
	
	cout << "Introduzca hora inicial: ";
	cin >> hora_inicial;
	cout << "Introduzca minutos iniciales: ";
	cin >> minuto_inicial;
	cout << "Introduzca segundos iniciales: ";
	cin >> segundo_inicial;
	
	cout << "\nIntroduzca hora final: ";
	cin >> hora_final;
	cout << "Introduzca minutos finales: ";
	cin >> minuto_final;
	cout << "Introduzca segundos finales: ";
	cin >> segundo_final;
	
	///////////////////////////////////////////////////////////////////////////////			// Cómputo
	
	h_inicial_segundos =  hora_inicial * 60 * 60;
	min_inicial_segundos = minuto_inicial * 60;
	
	h_final_segundos = hora_final * 60 * 60;
	min_final_segundos = minuto_final * 60;
	
	segundos_totales = (h_final_segundos - h_inicial_segundos) + (min_final_segundos - min_inicial_segundos) + (segundo_final - segundo_inicial);
	
	//////////////////////////////////////////////////////////////////////////////// 		// Resultado
	
	cout << "\nEl total de segundos transcurridos es: " << segundos_totales;
}
