/*
Reescriba la soluci�n del ejercicio 46 que calcula la suma de los primeros T factoriales.
Para ello, debe leer el valor T usando la funci�n LeeIntRango del ejercicio 4
para obligar a que est� en el intervalo [1,20].
Debe definir la funci�n SumaFactoriales que calcule la suma pedida. Implemente
dos versiones de esta funci�n:
	 En una primera versi�n, la funci�n SumaFactoriales debe llamar a la funci�n
		Factorial, para realizar la suma tal y como se indica en el ejercicio 46
	 En una segunda versi�n, la funci�n SumaFactoriales debe realizar la suma
		de forma directa tal y como se indica en el ejercicio 47. Ponga dentro de un
		comentario la primera versi�n.
*/

#include <iostream>
using namespace std;

// Funciones

// Prec:
// min y max n�meros enteros positivos
// min < max
// mensaje concorde al uso del programa
int LeeIntRango(int min, int max, string mensaje) {
   int a_leer;
   
   do{
      cout << mensaje;
      cin >> a_leer;
   }while (min > a_leer || max < a_leer);
   
   return a_leer;
}

/*

// Prec:
// n debe ser un n�mero natural en el intervalo [0,20]
long long Factorial(int n){
	long long factorial = 1;
	int multiplicando;
	
	for(multiplicando = 2 ; multiplicando <= n ; multiplicando++)
		factorial = factorial * multiplicando;

	return factorial;
}

// Prec:
// n debe ser un n�mero natural en el intervalo [0,20]
long long SumaFactoriales(int n){
	long long suma = 0;
	long long factorial;
	
	for (int i = 1 ; i <= n ; i++){
		factorial = Factorial(i);
		
		suma = suma + factorial;
	}
	return suma;
}

int main(){
	
	// Variables
	int const RANGO_MIN = 1,
				 RANGO_MAX = 20;
	string 	 msj_rango;
	int 		 numero;
	long long factoriales;
	
	msj_rango = "Introduzca un n�mero entero entre 1 y 20 ambos inclusives.\n N�mero: ";
	
	
	numero = LeeIntRango(RANGO_MIN , RANGO_MAX , msj_rango);
	
	factoriales = SumaFactoriales(numero);
	
	cout << "\nLa sumatoria de los primeros " << numero << " factoriales es: " << factoriales;
}
*/

// Prec:
// n es un n�mero entero positivo en el intervalo [1,20]
long long SumaFactoriales(int n){
	long long suma = 0;
	long long factorial = 1;
	
	for (int i = 1 ; i <= n ; i++){
		factorial = factorial * i;
		
		suma = suma + factorial;
	}
	return suma;
}

// Principal

int main(){
	
	// Variables
	int const RANGO_MIN = 1,
				 RANGO_MAX = 20;
	string 	 msj_rango;
	int 		 numero;
	long long factoriales;
	
	msj_rango = "Introduzca un n�mero entero entre 1 y 20 ambos inclusives.\n N�mero: ";
	
	// C�mputos
	numero = LeeIntRango(RANGO_MIN , RANGO_MAX , msj_rango);
	factoriales = SumaFactoriales(numero);
	
	// Resultados
	cout << "\nLa sumatoria de los primeros " << numero << " factoriales es: " << factoriales;
}
