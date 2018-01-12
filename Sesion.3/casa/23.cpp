/*
Programa para calcular horas, minutos y
segundos dentro de un rango determinado.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int const MINUTOS_x_HORA__SEGUNDOS_x_MINUTO = 60;
	int const HORAS_DIA = 24;
	
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
	
	segundos_finales = segundos_iniciales % MINUTOS_x_HORA__SEGUNDOS_x_MINUTO;
	minutos_finales = (segundos_iniciales / MINUTOS_x_HORA__SEGUNDOS_x_MINUTO + minutos_iniciales) % MINUTOS_x_HORA__SEGUNDOS_x_MINUTO;
	horas_finales = ((segundos_iniciales / MINUTOS_x_HORA__SEGUNDOS_x_MINUTO + minutos_iniciales) / MINUTOS_x_HORA__SEGUNDOS_x_MINUTO + horas_iniciales) % HORAS_DIA;
	dias = ((segundos_iniciales / MINUTOS_x_HORA__SEGUNDOS_x_MINUTO + minutos_iniciales) / MINUTOS_x_HORA__SEGUNDOS_x_MINUTO + horas_iniciales) / HORAS_DIA;
	
	cout << "\nResultado en: DÍAS  HORAS  MINUTOS  SEGUNDOS.\n";
	cout << dias << "  " << horas_finales << "  " << minutos_finales << "  " << segundos_finales << "\n";
}
