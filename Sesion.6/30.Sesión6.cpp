#include <iostream>
#include <cmath>
using namespace std;

int main(){

	// Variables
	
	int numero_base,
		cantidad_de_cifras = 1,
		limite_division,
		cifra_a_imprimir,
		calculador,
		exponente;
		
	// Introducci�n de datos

	cout << "\n\nIntroduzca un n�mero entero para separar sus cifras. \n  N�mero: ";
	cin >> numero_base;

	// C�mputos y salida de datos

	do{
		limite_division = numero_base / pow(10 , cantidad_de_cifras);
		cantidad_de_cifras ++;
	}while(limite_division >= 10);

	cout << "El n�mero introducido es de " << cantidad_de_cifras << " cifras.";

	calculador = numero_base;
	exponente = cantidad_de_cifras - 1;
	do{

		cifra_a_imprimir = calculador / pow(10 , exponente);
		calculador = calculador - ( cifra_a_imprimir * pow(10 , exponente) );
		exponente --;
		
		cout << "\n" << cifra_a_imprimir;
	}while(exponente > 0);
	
		cout << "\n" << calculador;
}
