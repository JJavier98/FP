#include <iostream>

using namespace std;

int main(){

	int minimo, maximo, nuevo;
	int contador;

	double distancia_minimo;
	double distancia_maximo;
	
	cout << "Introduzca un valor m�nimo y otro m�ximo para formar un intervalo.\n";

	do{
		cout << "Indique el valor m�nimo --> ";
		cin >> minimo;
	}while (minimo < 0);

	do{
		cout << "Indique el valor m�ximo --> ";
		cin >> maximo;
	}while (maximo < minimo);
	
	contador = 0;
	
	do{
		cout << "Se�ale un valor dentro del intervalo --> ";
		cin >> nuevo;
		contador++;
	}while(nuevo < minimo || nuevo > maximo);

	distancia_minimo = nuevo - minimo;
	distancia_maximo = maximo - nuevo;

	if (contador >= 3){
		cout << "N�mero de intentos sobrepasado";
		
	}
	else{
		cout << "La distacia que hay nuevo_minimo es: " << distancia_minimo;
		cout << "\nLa distacia que hay maximo_nuevo es : " << distancia_maximo;
	}
}

/*
do{
		cout << "Se�ale un valor dentro del intervalo --> ";
		cin >> nuevo;
		contador++;
		
		no_hay_mas_intentos = contador == MAX_NUMERO_INTENTOS;
		esta_en_rango = min < nuevo && nuevo < max;
	}while(nuevo < minimo || nuevo > maximo);
*/
