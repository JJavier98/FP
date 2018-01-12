/*
Programa que determina el valor del eje de ordenadas
que alcanza la funci�n Gaussiana de estad�stica
en un punto x del eje de abscisas.
*/

#include <iostream>			   	// Inclusi�n de los recursos de E/S
#include <cmath>   				 // Inclusi�n de los recursos matem�ticos

using namespace std;

int main(){
									// Declaraci�n de variables
	double mu;						
	double sigma;
	double punto_abscisa;       	// Punto_abscisas = x
	double gauss;					// Resultado de la ecuaci�n
	double pi = 3.1416;
	
	cout << "Introduzca el valor de la variable --> Mu: ";					// Introducci�n de datos
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
No he conseguido expresar bien la ecuaci�n gaussiana.
*/
