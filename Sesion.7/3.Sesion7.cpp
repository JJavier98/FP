/*
3. En las transparencias de clase se ha visto la función Max3 que calculaba el máximo
de tres valores enteros.
Defina ahora la función Max que calcule el máximo de dos valores enteros y cambie
la implementación de Max3 para que llame a la función Max.
Construya un programa principal que llame a Max3 con tres valores leídos desde
teclado.
*/

#include <iostream>
using namespace std;

	// Funciones

int Max(int a, int b){

	int max;

	max = a;

	if (b > max)
		max = b;

	return max;
}

int Max3(int a, int b, int c){

	int max;

	max = Max(a , b);

	if (c > max)
		max = c;

	return max;
}

	// Principal

int main(){

	// Variables

	int a, b, c,
		 resultado;
		 
	// Introducción de datos

	cout << "Introduzca unos números 'a', 'b' y 'c' para compararlos y mostrar el máximo de ellos.\n Número 'a': ";
	cin >> a;
	cout << " Número 'b': ";
	cin >> b;
	cout << " Número 'c': ";
	cin >> c;
	
	// Cómputos

	resultado = Max3(a , b , c);
	
	// Resultados

	cout << "\nEl número máximo de los tres introducidos es: " << resultado << "\n";
}
