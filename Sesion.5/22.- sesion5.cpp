#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	// DECLARACI�N DE VARIABLES
	
	const double PI = 3.1415927; 

	double esperanza, desviacion, gaussiana, x;	                            
	double valor_tipificado, exponente, minimo, maximo, incremento;
	
	// INTRODUCC�ON DE DATOS
   
	cout << "Introduzca el valor de la variable ESPERANZA: ";
	cin >> esperanza;
	
	do{
		cout << "Introduzca el valor de la variable DESVIACI�N: ";
		cin >> desviacion;
	}while (desviacion < 0);
	
	do{
		cout << "\n\nIndique en rango sobre el que se calcular� el valor de la funci�n as� como el incremento de �sta.\n\n";
		cout << "Valor m�nimo de la funci�n --> ";
		cin >> minimo;
		cout << "Valor maximo de la funci�n --> ";
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
	
		cout << "\n\nEl valor de la funci�n gaussiana en " << x << " es " << gaussiana;
		
		x = x + incremento;
	}while (x <= maximo);
}
