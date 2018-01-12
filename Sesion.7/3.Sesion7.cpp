/*
3. En las transparencias de clase se ha visto la funci�n Max3 que calculaba el m�ximo
de tres valores enteros.
Defina ahora la funci�n Max que calcule el m�ximo de dos valores enteros y cambie
la implementaci�n de Max3 para que llame a la funci�n Max.
Construya un programa principal que llame a Max3 con tres valores le�dos desde
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
		 
	// Introducci�n de datos

	cout << "Introduzca unos n�meros 'a', 'b' y 'c' para compararlos y mostrar el m�ximo de ellos.\n N�mero 'a': ";
	cin >> a;
	cout << " N�mero 'b': ";
	cin >> b;
	cout << " N�mero 'c': ";
	cin >> c;
	
	// C�mputos

	resultado = Max3(a , b , c);
	
	// Resultados

	cout << "\nEl n�mero m�ximo de los tres introducidos es: " << resultado << "\n";
}
