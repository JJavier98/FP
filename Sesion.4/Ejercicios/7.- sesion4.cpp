#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	// Variables
																																		
	int numero1, numero2, numero3;
	bool ascendente, descendente;
	
	// Introducción de datos
																																		
	cout << "Introduzca una serie de tres números enteros para ver si se encuentran escritos en orden.\n";
	cout << "Número 1 --> ";
	cin >> numero1;
	cout << "Número 2 --> ";
	cin >> numero2;
	cout << "Número 3 --> ";
	cin >> numero3;
	
	// Cómputos
																																		
	ascendente = (numero1 <= numero2 && numero2 <= numero3);
	descendente = (numero1 >= numero2 && numero2 >= numero3); 

	// Resultados
																																		
	if (ascendente){
		cout << "\nLos números tal y como han sido introducidos se encuentran en orden ascendente:\n";
		cout << numero1 << " < " << numero2 << " < " << numero3;
	}
	
	else{
		if (descendente){
			cout << "\nLos números tal y como han sido introducidos se encuentran en orden descendente:\n";
			cout << numero1 << " > " << numero2 << " > " << numero3;
		}
		
		else cout << "\nLos números no siguen ningún orden según se han introducido.";
	}
}
