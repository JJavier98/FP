#include <iostream>
using namespace std;

int LeeIntRango (int numero){
	
	do{
		cout << "Introduzca un número entero que se encuentre dentro del intervalo [0,20].\n Número: ";
		cin >> numero;
	}while (numero < 0 && numero > 20);
	
	return numero;
}

long long Factorial (int){

	long long factorial = 1;
	int i;
	
	for (i = 2 ; i < numero ; i++){
		factorial = factorial * i;
	}
	return factorial;
}

long long SumaFactoriales (int numero){
	
	long long resultado = 0,
				 dato;
	
	for(i = 1 ; i <= numero ; i++){
		dato = Factorial(i);
		resultado = resultado + dato;
	}
	return resultado;
}
