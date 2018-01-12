/*
Programa para calcular horas, minutos y
segundos dentro de un rango determinado.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int horas_iniciales;
	int minutos_iniciales;
	int segundos_iniciales;
	
	int dias;
	int horas_finales;
	int minutos_finales;
	int segundos_finales;
	
	cout << "Introduzca el numero de horas: ";
	cin >> horas_iniciales;
	cout <<"Introduzca el numero de minutos: ";
	cin >> minutos_iniciales;
	cout << "Introduzca el numero de segundos: ";
	cin >> segundos_iniciales;
	
	segundos_finales = segundos_iniciales % 60;
	minutos_finales = (segundos_iniciales / 60 + minutos_iniciales % 60) % 60;
	horas_finales = minutos_iniciales / 60 + horas_iniciales % 24;
	dias = horas_iniciales / 24;
	
	cout << "Resultado en: DÍAS  HORAS  MINUTOS  SEGUNDOS.\n";
	cout << dias << "  " << horas_finales << "  " << minutos_finales << "  " << segundos_finales;
}
