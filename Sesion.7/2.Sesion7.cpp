/*
Calcule mediante un programa en C++ la funci�n potencia xn, y la funci�n factorial n!
con n un valor entero y x un valor real. No pueden usarse las funciones de la biblioteca
cmath, por lo que tendr� que implementar los c�mputos con los bucles necesarios.

Escriba un programa de prueba que lea un n�mero entero n obligando a que est� en
el intervalo [1; 20]. A continuaci�n lea un valor real x y calcule e imprima en pantalla
el factorial de n y la potencia de x elevado a n.
*/

#include <iostream>
using namespace std;

	// Funciones

long long Factorial(int num){
	
	long long factorial = 1;
	int multiplicando;
	
	for(multiplicando = 2 ; multiplicando <= num ; multiplicando++)
		factorial = factorial * multiplicando;
		
	return factorial;
}

long long Potencia(int base, int exponente){
	
	long long potencia = 1.0;
	int i;

	for (i = 1; i <= exponente; i++)    
      potencia = potencia * base;
      
   return potencia;
}

	// Funci�n principal

int main(){
	
		// Declaraci�n de variables
	
	long long factorial;
	int 	 	 n;
	double	 x, potencia;
	
		// Introducci�n de datos
	
	do{	
		cout << "Introduzca un n�mero 'n' entre 0 y 20 para calcular su factorial y un n�mero real 'x' para elevarlo a n veces. \n N�mero 'n': ";
		cin >> n;
		cout << " N�mero 'x': ";
		cin >> x;
	}while (n < 0 || n > 20);
	
		// C�mputos
	
	factorial = Factorial(n);
	potencia = Potencia(x, n);
	
		// Salida de resultados
	
	cout << "\nEl factorial de " << n << " es: " << factorial << ". Y " << x << " elevado a " << n << " es: " << potencia << "\n\n";
	
	
}
