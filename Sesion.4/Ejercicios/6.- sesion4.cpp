/*
Programa de aumento de salario atentiendo a distintas variables.
*/

#include <iostream>

using namespace std;

int main(){

	// Declaración de variables

	double salario_inicial, grado_de_satisfaccion, salario_final;
	int horas_trabajadas, casos_resuletos;

	// Entrada de datos

	cout << "Introduzca aquí su salario por hora: ";
	cin >> salario_inicial;
	cout << "Indique las horas trabajadas a lo largo del mes: " ;
	cin >> horas_trabajadas;
	cout << "Señale el total de casos resuletos satisfactoriamente durante el mes: ";
	cin >> casos_resuletos;
	cout << "Indique el grado medio de satisfacción de los usuarios de 0 a 5 puntos: ";
	cin >> grado_de_satisfaccion;

	// Cómputos

	if (casos_resuletos > 30 && grado_de_satisfaccion > 4.0)
		salario_final = salario_inicial * 1.06;
	else
		if (casos_resuletos > 30)
			salario_final = salario_inicial * 1.04;
		else
			if (grado_de_satisfaccion > 4.0)
				salario_final = salario_inicial * 1.02;
			else 
				salario_final = salario_inicial;

	// Salida de datos

	cout << "\nCon los datos introducidos su salario final es: " << salario_final * horas_trabajadas;
}
