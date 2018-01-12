#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	// DECLARACIÓN DE VARIABLES
	
	const double PI = 3.1415927; 

	double esperanza, desviacion, gaussiana, x;	                            
	double valor_tipificado, exponente, minimo, maximo, incremento;
	
	// INTRODUCCÍON DE DATOS
   
	cout << "Introduzca el valor de la variable ESPERANZA: ";
	cin >> esperanza;
	
	do{
		cout << "Introduzca el valor de la variable DESVIACIÓN: ";
		cin >> desviacion;
	}while (desviacion < 0);
	
	do{
		cout << "\n\nIndique en rango sobre el que se calculará el valor de la función así como el incremento de ésta.\n\n";
		cout << "Valor mínimo de la función --> ";
		cin >> minimo;
		cout << "Valor maximo de la función --> ";
		cin >> maximo;
	}while (maximo  < minimo);

	cout << "Valor del incremento -->";
	cin >> incremento;

	// OPERACIONES Y SALIDA DE RESULTADOS

	x = minimo;

	do{
		valor_tipificado = (x - esperanza) / desviacion;
		exponente = -0.5 * valor_tipificado * valor_tipificado;

		gaussiana = exp(exponente) / ( desviacion * sqrt(2*PI) );    
	
		cout << "\n\nEl valor de la función gaussiana en " << x << " es " << gaussiana;
		
		x = x + incremento;
	}while (x <= maximo);
}
