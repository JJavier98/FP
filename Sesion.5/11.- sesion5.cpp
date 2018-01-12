/*
Programa de aumento de salario atentiendo a distintas variables.
*/

#include <iostream>

using namespace std;

int main(){

	// Declaración de variables
	
	const double PORCENTAJE_MAS_DE_30_CASOS_RESUELTOS = 1.04;
	const double PORCENTAJE_ENTRE_20_Y_30_CASOS = 1.03;
	const double PORCENTAJE_POR_GRADO_DE_SATISFACCION = 0.02;
	const int MUCHOS_CASOS_RESUELTOS = 30;
	const int ALGUNOS_CASOS_RESUELTOS = 20;
	const int AMABLE = 4;

	double incremento;
	double salario_por_hora, salario_base, grado_de_satisfaccion, salario_final;
	int horas_trabajadas, casos_resueltos;

	// Entrada de datos

	cout << "Introduzca aquí su salario por hora: ";
	cin >> salario_por_hora;
	cout << "Indique las horas trabajadas a lo largo del mes: " ;
	cin >> horas_trabajadas;
	cout << "Señale el total de casos resuletos satisfactoriamente durante el mes: ";
	cin >> casos_resueltos;
	cout << "Indique el grado medio de satisfacción de los usuarios de 0 a 5 puntos: ";
	cin >> grado_de_satisfaccion;

	// Cómputos

	bool buen_trabajador = casos_resueltos >= MUCHOS_CASOS_RESUELTOS;
	bool trabajador_medio = casos_resueltos >= ALGUNOS_CASOS_RESUELTOS;
	bool trabajador_amable = grado_de_satisfaccion >= AMABLE;

	salario_base = salario_por_hora * horas_trabajadas;
	incremento = 1;

	if(buen_trabajador)
		incremento = PORCENTAJE_MAS_DE_30_CASOS_RESUELTOS;
	
	else if(trabajador_medio)
		incremento = PORCENTAJE_ENTRE_20_Y_30_CASOS;

	if(trabajador_amable)
		incremento = incremento + PORCENTAJE_POR_GRADO_DE_SATISFACCION;

	salario_final = salario_base * incremento;

	// Salida de datos

	cout << "\nCon los datos introducidos su salario final es: " << salario_final;

}
