/*
Programa demográfico.
Estimación de la población
atendiendo a la natalidad, mortalidad y
migración.
*/

	// Bibliotecas.

#include <iostream>											
#include <cmath>

using namespace std;

int main(){
	
	// Variables
	
	int const LIMITE_TASA = 1000;
	int anio, anio_para_doble;					
	double periodo;
	double natalidad;
	double mortalidad;
	double migracion;
	double tasa_de_crecimiento_total;
	double indice_de_crecimiento;
	long long poblacion_final, poblacion_inicial, poblacion_doble;
	
	// Entrada de datos

	cout << "Los datos de natalidad, mortalidad y migración se introducirán en tanto por mil.";	
	
	do{
		cout << "\n\nIntroduzca la población inicial: ";
		cin >> poblacion_inicial;

	}while (poblacion_inicial < 0);

	do{
		cout << "Introduzca la tasa de natalidad: ";
		cin >> natalidad;
		
	}while (natalidad > LIMITE_TASA || natalidad < 0 );
		
	do{
		cout << "Introduzca la tasa de mortalidad: ";
		cin >> mortalidad;
		
	}while (mortalidad > LIMITE_TASA || mortalidad < 0);
	
	do{
		cout << "Introduzca la tasa de migración: ";
		cin >> migracion;	
		
	}while (migracion > LIMITE_TASA || migracion < -LIMITE_TASA);

	do{
		cout << "Introduzca el periodo de años: ";
		cin >> periodo;

	}while (periodo <= 0);

	// Cómputo
	
	tasa_de_crecimiento_total = natalidad - mortalidad + migracion;
	indice_de_crecimiento =1 + (tasa_de_crecimiento_total / 1000.0);

	poblacion_final = poblacion_inicial;
	anio = 0;

	do{
		poblacion_final = poblacion_final * indice_de_crecimiento;			// Acostrumbrar a hacerlo con "While" y no con "do - while"
		anio++;
	}while (anio < periodo);

	poblacion_doble = poblacion_inicial;
	anio_para_doble = 0;

	do{
		poblacion_doble = poblacion_doble * indice_de_crecimiento;
		anio_para_doble++;
		
	}while (poblacion_doble < 2 * poblacion_inicial);							// Cambiar 2 * poblacion_inicial por una sola variable

	// Resultado.
	
	cout << "\n\nLa poblacion final trancurridos los años especificados es: " << poblacion_final;
	cout << "\nLos años que han pasado para alcanzar el doble de la poblacion inicial " << "<<" << poblacion_doble << ">>" << " son: " << anio_para_doble;
	
}

