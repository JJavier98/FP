/*
Programa que aumenta un 2% un salario base
y acto seguido incrementa un 3% este �ltimo.
*/
	
#include <iostream>                      																    // Inclusi�n de los recursos de E/S

using namespace std;

int main(){																									// Programa principal
	
	double salario_base;																					// Declaraci�n de variables
	double salario_dos;
	double salario_tres;
	
	cout << "Introduzca su salario base: ";																	//  Introducci�n del dato del usuario
	cin >> salario_base;
	
	salario_dos = salario_base * 1.02;																		// C�mputos
	salario_tres = salario_dos * 1.03;
	
	cout << "\nSu salario con un 2% de inter�s a�adido es: " << salario_dos;								//Resultados
	cout << "\nA�adiendo un 3% de inter�s al salario inmediatamente anterior es: " << salario_tres;
}
