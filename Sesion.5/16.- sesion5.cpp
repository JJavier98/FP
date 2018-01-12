#include <iostream>
#include <cmath>

using namespace std;

enum class OrdenNumero
	{creciente, decreciente, desorden};

int main(){
	
	// Declaraci�n de variables
																																		
	long numero1, numero2, numero3;
	bool ascendente, descendente;
	OrdenNumero orden_numero;

	// Introducci�n de datos
																																		
	cout << "Introduzca una serie de tres n�meros enteros para ver si se encuentran escritos en orden.\n";
	cout << "N�mero 1 --> ";
	cin >> numero1;
	cout << "N�mero 2 --> ";
	cin >> numero2;
	cout << "N�mero 3 --> ";
	cin >> numero3;
	
	// C�mputos
	
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
			cout << "\nLos n�meros tal y como han sido introducidos se encuentran en orden ascendente:\n";
			cout << numero1 << " > " << numero2 << " > " << numero3;
			break;
		case OrdenNumero::decreciente:
			cout << "\nLos n�meros tal y como han sido introducidos se encuentran en orden descendente:\n";
			cout << numero1 << " > " << numero2 << " > " << numero3;
			break;
		case OrdenNumero::desorden:
			cout << "\nLos n�meros no siguen ning�n orden seg�n se han introducido.";
			break;
	}
}
