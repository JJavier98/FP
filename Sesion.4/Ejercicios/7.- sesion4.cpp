#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	// Variables
																																		
	int numero1, numero2, numero3;
	bool ascendente, descendente;
	
	// Introducci�n de datos
																																		
	cout << "Introduzca una serie de tres n�meros enteros para ver si se encuentran escritos en orden.\n";
	cout << "N�mero 1 --> ";
	cin >> numero1;
	cout << "N�mero 2 --> ";
	cin >> numero2;
	cout << "N�mero 3 --> ";
	cin >> numero3;
	
	// C�mputos
																																		
	ascendente = (numero1 <= numero2 && numero2 <= numero3);
	descendente = (numero1 >= numero2 && numero2 >= numero3); 

	// Resultados
																																		
	if (ascendente){
		cout << "\nLos n�meros tal y como han sido introducidos se encuentran en orden ascendente:\n";
		cout << numero1 << " < " << numero2 << " < " << numero3;
	}
	
	else{
		if (descendente){
			cout << "\nLos n�meros tal y como han sido introducidos se encuentran en orden descendente:\n";
			cout << numero1 << " > " << numero2 << " > " << numero3;
		}
		
		else cout << "\nLos n�meros no siguen ning�n orden seg�n se han introducido.";
	}
}
