/*
Programa demográfico.
Estimación de la población
atendiendo a la natalidad, mortalidad y
migración.
*/

#include <iostream>											// Bibliotecas.
#include <cmath>

using namespace std;

int main(){
	
	double poblacion_inicial;								// Variables.
	double periodo;
	double natalidad;
	double mortalidad;
	double migracion;
	long long poblacion_final;
	
	
	cout << "Los datos de natalidad, mortalidad y migración se introducirán en tanto por mil.";				// E/S.
	
	cout << "\n\nintroduzca la población inicial: ";
	cin >> poblacion_inicial;
	
	cout << "introduzca los años: ";
	cin >> periodo;
	
	cout << "introduzca la natalidad: ";
	cin >> natalidad;
	
	cout << "introduzca la mortalidad: ";
	cin >> mortalidad;
	
	cout << "introduzca la migración: ";
	cin >> migracion;																					// Cáculo.
	
	
	poblacion_final = poblacion_inicial + (poblacion_inicial * periodo * natalidad / 1000.0) - (poblacion_inicial * periodo * mortalidad / 1000.0) + (poblacion_inicial * periodo * migracion / 1000.0);
	
	cout << "La poblacion final es: " << poblacion_final;												// Resultado.
	
	// Fallo en el cálculo de la población final. No es el resultado correcto.
}
