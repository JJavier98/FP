/*
Programa que aumenta un 2% un salario base
y acto seguido incrementa un 3% este último.
*/
	
#include <iostream>                      																    // Inclusión de los recursos de E/S

using namespace std;

int main(){																									// Programa principal
	
	double salario_base;																					// Declaración de variables
	double salario_dos;
	double salario_tres;
	
	cout << "Introduzca su salario base: ";																	//  Introducción del dato del usuario
	cin >> salario_base;
	
	salario_dos = salario_base * 1.02;																		// Cómputos
	salario_tres = salario_dos * 1.03;
	
	cout << "\nSu salario con un 2% de interés añadido es: " << salario_dos;								//Resultados
	cout << "\nAñadiendo un 3% de interés al salario inmediatamente anterior es: " << salario_tres;
}
