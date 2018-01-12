#include <iostream>
#include <cmath>

using namespace std;

int main(){

	//Declaración de variables

	int anio;
	bool norma_1, norma_2;
		
	//Introducción de datos

	cout << "¿Qué año quiere comprobar si era bisiesto? -->";
	cin >> anio;
	
	//Cómputos

	norma_1 = (anio % 4 == 0 && anio % 100 != 0);
	norma_2 = anio % 400 == 0;
	
	//Salida de datos

	if (norma_1 || norma_2)
		cout << "El año señalado (" << anio << ") es bisiesto.\n";
	else 
		cout << "El año señalado (" << anio << ") NO es bisiesto.\n";
}
