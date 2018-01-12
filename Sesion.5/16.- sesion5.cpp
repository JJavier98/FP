#include <iostream>
#include <cmath>

using namespace std;

enum class OrdenNumero
	{creciente, decreciente, desorden};

int main(){
	
	// Declaración de variables
																																		
	long numero1, numero2, numero3;
	bool ascendente, descendente;
	OrdenNumero orden_numero;

	// Introducción de datos
																																		
	cout << "Introduzca una serie de tres números enteros para ver si se encuentran escritos en orden.\n";
	cout << "Número 1 --> ";
	cin >> numero1;
	cout << "Número 2 --> ";
	cin >> numero2;
	cout << "Número 3 --> ";
	cin >> numero3;
	
	// Cómputos
	
	ascendente = numero1 < numero2 && numero2 < numero3;
	descendente = numero1 > numero2 && numero2 > numero3; 

	// Resultados
																																		
	if (ascendente){
		orden_numero = OrdenNumero::creciente;
	}
	
	else{
		if (descendente){
			orden_numero = OrdenNumero::decreciente;
		}
		else
		orden_numero = OrdenNumero::desorden;
	}

	switch(orden_numero){
		case OrdenNumero::creciente:
			cout << "\nLos números tal y como han sido introducidos se encuentran en orden ascendente:\n";
			cout << numero1 << " > " << numero2 << " > " << numero3;
			break;
		case OrdenNumero::decreciente:
			cout << "\nLos números tal y como han sido introducidos se encuentran en orden descendente:\n";
			cout << numero1 << " > " << numero2 << " > " << numero3;
			break;
		case OrdenNumero::desorden:
			cout << "\nLos números no siguen ningún orden según se han introducido.";
			break;
	}
}
