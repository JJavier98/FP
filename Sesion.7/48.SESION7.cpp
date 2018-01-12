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
	double esperanza,						
			 desviacion,
			 punto_abscisa_min,
			 punto_abscisa_max,
			 incremento,
			 abscisas,
			 valor_tipificado,
			 exponente,
			 gaussiana;
	const double PI = 3.1416;
	char	 menu;
	
	cout << "48.-	Programa que determina el valor del eje de ordenadas\n	que alcanza la función Gaussiana de estadística\n	en un punto x del eje de abscisas.\n\n\n";
	
	while (menu != 'S'){
		
		cout << " ··· Introducir parámetros (P)\n";
		cout << " ··· Salir del programa (S)\n\n";
		cin >> menu;
	
		while (menu == 'P'){
		
			cout << "\nIntroduzca el valor de la variable --> esperanza: ";					// Introducción de datos
			cin >> esperanza;
			
			do{
				cout << "Introduzca el valor de la variable --> desviacion: ";
				cin >> desviacion;
			}while (desviacion < 0);
			
			menu = '1';
			
			while (menu == '1'){
			
				cout << "\n\n\n ··· Introducir rango de valores de abscisas (R)\n";
				cout << " ··· Volver al menú anterior (el menú principal) (M)\n\n";
				cin >> menu;
			
				while (menu == 'R'){
				
					cout << "\nIntroduzca el valor mínimo de la variable --> X(abcisas): ";
					cin >> punto_abscisa_min;
					
					do{
						cout << "Introduzca el valor máximo de la variable --> X(abcisas): ";
						cin >> punto_abscisa_max;
					}while ( punto_abscisa_max < punto_abscisa_min );
					
					do{
						cout << "Introduzca el incremento: ";
						cin >> incremento;
					}while ( incremento < 0 );
					
					abscisas = punto_abscisa_min;
					
					// Cómputos y resultados
					
					do{
						valor_tiPIficado = (abscisas - esperanza) / desviacion;
						exponente = -0.5 * valor_tipificado * valor_tipificado;

						gaussiana = exp(exponente) / ( desviacion * sqrt(2*PI) );    
	
						cout << "\n\nEl valor de la función gaussiana en " << abscisas << " es " << gaussiana;
		
						abscisas = abscisas + incremento;
					}while (abscisas <= punto_abscisa_max);
	
					menu = '1';
				}
			}
		}
	}
}


