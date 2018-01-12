/*
Programa que determina el valor de ordenadas
que alcanza la función Gaussiana de estadística
en un punto x del eje de abscisas
*/

#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

double const PI = 3.141592; // Como excepción definimos esta variable global PI.

// Prec:
// mensaje debe ser concorde al uso del programa
double LeeDoubleMayorIgualQue (double valor_minimo , string mensaje){
	double valor_superior;
	
	do{
		cout << mensaje;
		cin >> valor_superior;
	}while (valor_superior < valor_minimo);
	
	return valor_superior;
}

// Prec:
// Esperanza y desviacion deben ser reales y positivas
// x debe ser un número real
double Gaussiana (double esperanza , double desviacion , double x){
	double valor_tipificado,
			 exponente,
			 gaussiana;
	
	
	valor_tipificado = (x - esperanza) / desviacion;
	exponente = -0.5 * valor_tipificado * valor_tipificado;
	gaussiana = exp(exponente) / ( desviacion * sqrt(2*PI) );
	
	return gaussiana;
}

// Principal
int main(){
	
	// Declaración de variables
	double esperanza,						
			 desviacion,
			 punto_abscisa_min,
			 punto_abscisa_max,
			 incremento,
			 x,
			 gaussiana;
	char	 menu;
	string desviacion_txt = "Introduzca el valor de la variable --> desviacion: ",
			 abscisa_txt = "Introduzca el valor máximo de la variable --> X(abcisas): ",
			 incremento_txt = "Introduzca el incremento: ";
	
	cout << "48.-	Programa que determina el valor del eje de ordenadas\n	que alcanza la función Gaussiana de estadística\n	en un punto x del eje de x.\n\n\n";
	
	while (menu != 'S'){
		
		cout << " ··· Introducir parámetros (P)\n";
		cout << " ··· Salir del programa (S)\n\n";
		cin >> menu;
		menu = toupper(menu);
	
		// Introducción de datos
		while (menu == 'P'){
		
			cout << "\nIntroduzca el valor de la variable --> esperanza: ";
			cin >> esperanza;
			
			desviacion = LeeDoubleMayorIgualQue(0 , desviacion_txt);
			
			menu = '1';
			
			while (menu == '1'){
			
				cout << "\n\n\n ··· Introducir rango de valores de x (R)\n";
				cout << " ··· Volver al menú anterior (el menú principal) (M)\n\n";
				cin >> menu;
				menu = toupper(menu);
			
				while (menu == 'R'){
				
					cout << "\nIntroduzca el valor mínimo de la variable --> X(abcisas): ";
					cin >> punto_abscisa_min;
					
					punto_abscisa_max = LeeDoubleMayorIgualQue(punto_abscisa_min , abscisa_txt);
					
					incremento = LeeDoubleMayorIgualQue(0 , incremento_txt);
					
					// Cómputos y resultados
					x = punto_abscisa_min;
					
					do{
						gaussiana = Gaussiana(esperanza , desviacion , x);
	
						cout << "\n\nEl valor de la función gaussiana en " << x << " es " << gaussiana;
		
						x = x + incremento;
					}while (x <= punto_abscisa_max);
	
					menu = '1';
				}
			}
		}
	}
}


