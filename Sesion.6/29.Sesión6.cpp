#include <iostream>
#include <cmath>
using namespace std;

int main(){

	// Constantes

	double temperatura,
			temperatura_anterior = 0;
	int const CERRAR_PROGRAMA = -1;
	int longitud = 0,
		longitud_max = 0,
		inicio = 1,
		inicio_de_secuencia,
		posicion = 0;

	// Introducción de datos y cómputo

	cout << "El programa leerá temperaturas dadas en grados centígrados.\nDeberán ser siempre positivas\nEl dato '-1' cerrará el programa.\n";

	while(temperatura != CERRAR_PROGRAMA){

		cout << "\nIntroduzca la temperatura media de hoy. \n  Temperatura: ";
		cin >> temperatura;

		posicion ++;

		if(temperatura > temperatura_anterior){
			longitud ++;

			if(longitud > longitud_max){
				longitud_max = longitud;
				inicio_de_secuencia = inicio;
			}
		}else{
			longitud = 1;
			inicio = posicion;
		}

		temperatura_anterior = temperatura;

	}

	// Salida de resultados

	cout << "\n\nLa secuencia de temperaturas ascendentes introducida más larga empieza en el día " << inicio_de_secuencia << " y ha durado " << longitud_max << " días.";

}
