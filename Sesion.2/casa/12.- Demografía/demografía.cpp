/*
Programa demogr�fico.
Estimaci�n de la poblaci�n
atendiendo a la natalidad, mortalidad y
migraci�n.
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
	
	
	cout << "Los datos de natalidad, mortalidad y migraci�n se introducir�n en tanto por mil.";				// E/S.
	
	cout << "\n\nintroduzca la poblaci�n inicial: ";
	cin >> poblacion_inicial;
	
	cout << "introduzca los a�os: ";
	cin >> periodo;
	
	cout << "introduzca la natalidad: ";
	cin >> natalidad;
	
	cout << "introduzca la mortalidad: ";
	cin >> mortalidad;
	
	cout << "introduzca la migraci�n: ";
	cin >> migracion;																					// C�culo.
	
	
	poblacion_final = poblacion_inicial + (poblacion_inicial * periodo * natalidad / 1000.0) - (poblacion_inicial * periodo * mortalidad / 1000.0) + (poblacion_inicial * periodo * migracion / 1000.0);
	
	cout << "La poblacion final es: " << poblacion_final;												// Resultado.
	
	// Fallo en el c�lculo de la poblaci�n final. No es el resultado correcto.
}
