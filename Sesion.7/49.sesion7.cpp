/*
49.- Diremos que un n�mero entero positivo es secuenciable si se puede generar como
suma de n�meros consecutivos (al menos dos). Por ejemplo, 6 = 1+2+3, 15 = 7+8.
Esta descomposici�n no tiene por qu� ser �nica. Por ejemplo, 15 = 7+8 = 4+5+6 =
1+2+3+4+5. Escriba un programa que lea un entero n  1 e imprima todas las
descomposiciones posibles. En este ejercicio puede mezclar operaciones de E/S y C
dentro del mismo bucle.
*/

#include <iostream>
using namespace std;

int  main(){

	// Variables

	int numero,
		suma,
		inicializador,
		final,
		Valor_suma;
		
	// Introduccion de datos

	cout << "Introduzca un valor para mostrarlo como una suma de n�meros consecutivos. \n Valor: ";
	cin >> numero;
	
	// C�mputos y resultados

	for (inicializador = 1 ; inicializador < numero ; inicializador++){

		suma = 0;
		
		for (final = inicializador ; suma < numero ; final++){

			suma = suma + final;

			if (suma == numero){
				for (Valor_suma = inicializador ; Valor_suma <= final ; Valor_suma++)
					cout << Valor_suma << " + ";

			cout << " | ";
			}
		}
	}
}
