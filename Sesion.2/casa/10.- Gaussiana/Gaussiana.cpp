/*
Programa que determina el valor del eje de ordenadas
que alcanza la función Gaussiana de estadística
en un punto x del eje de abscisas.
*/

#include <iostream>			   	// Inclusión de los recursos de E/S
#include <cmath>   				 // Inclusión de los recursos matemáticos

using namespace std;

int main(){
									// Declaración de variables
	double mu;						
	double sigma;
	double punto_abscisa;       	// Punto_abscisas = x
	double gauss;					// Resultado de la ecuación
	double pi = 3.1416;
	
	cout << "Introduzca el valor de la variable --> Mu: ";					// Introducción de datos
	cin >> mu;
	cout << "Introduzca el valor de la variable --> Sigma: ";
	cin >> sigma;
	cout << "Introduzca el valor de la variable --> X: ";
	cin >> punto_abscisa;
	
	gauss = (1 / sigma * sqrt(2 * pi) ) * exp( (-0.5) * pow( ( (punto_abscisa - mu) / sigma), 2) );
	
	cout << "El valor de ordenadas que recibe su variable X es: " << gauss;
}

/*
No he logrado hacer funcionar el programa.
No he conseguido expresar bien la ecuación gaussiana.
*/
