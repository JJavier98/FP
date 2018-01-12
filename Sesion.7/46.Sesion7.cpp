#include <iostream>
using namespace std;

int main(){
	
	// Variables
	
	long long resultado = 0,
				factorial;

	int 		numero,
				multiplicando,
				i;
	
	// Entrada de datos
	
	do{	
		cout << "Introduzca un número entre 0 y 20. \n Número: ";
		cin >> numero;
	}while (numero < 0 || numero > 20);
	
	// Cómputos
	
	for (i = 1 ; i <= numero ; i++){
		factorial = 1;

		for(multiplicando = 2 ; multiplicando <= i ; multiplicando++)
			factorial = factorial * multiplicando;

	resultado = resultado + factorial;

	}
	
	// Resultado
	
	cout << "\nEl resultado es: " << resultado << "\n\n";
		
}
