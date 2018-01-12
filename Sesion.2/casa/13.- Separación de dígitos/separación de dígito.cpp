/*
Programa que lee un valor entero y
muestra en pantalla sus digitos espaciados.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int numero_entero;
	int numero_1;
	int numero_2;
	int numero_3;
	
	cout << "Introduce un número entero de tres cifras: ";
	cin >> numero_entero;
	
	numero_1 = numero_entero / 100;
	numero_2 = (numero_entero - 100 * numero_1) / 10;
	numero_3 = (numero_entero - (100 * numero_1) - (10 * numero_2));
	
	cout << numero_1 << "  " << numero_2 << "  " << numero_3;
}
