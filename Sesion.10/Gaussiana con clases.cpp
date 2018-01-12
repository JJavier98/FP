/*

########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########

### José Javier Alonso Ramos
### 1º de carrera
### Grupo A1
### Práctica 10: clases y struct
## Ejercicio 27

*/


/*
Programa que determina el valor de ordenadas
que alcanza la función Gaussiana de estadística
en un punto x del eje de abscisas.

27. Recupere la solución del ejercicio 8 de esta relación de problemas sobre la función
gaussiana. En vez de trabajar con funciones, plantee la solución con una clase. Debe
diseÃ±ar la clase teniendo en cuenta que la función matemática gaussiana viene determinada
unívocamente por el valor de la esperanza y la desviación, es decir, son estos
dos parámetros lo que distinguen a una función gaussiana de otra.
*/

#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

double const PI = 3.141592; // Como excepción definimos esta variable global PI.


/////////// Funciones

string MensajeComienzo(){
	return "########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########\n\n### José Javier Alonso Ramos\n### 1º de carrera\n### Grupo A1\n### Práctica 10: clases y struct\n### Ejercicio 27\n\n\n\n";
}

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

long long Potencia(double base, int exponente){
	
	long long potencia = 1.0;
	int i;

	exponente = abs(exponente);
	
	for (i = 1; i <= exponente; i++)    
      potencia = potencia * base;
      
   if (exponente < 0){
   	potencia = 1 / potencia;
	}
   return potencia;
}
/////////// Clases
class Gaussiana{
private:
	double esperanza,
			 desviacion,
			 abscisa_minima,
			 abscisa_maxima,
			 incremento,
			 cdf,
			 valor_de_funcion;

public:
	void SetDesviacion(string msj0){
		desviacion = LeeDoubleMayorIgualQue(0, msj0);
	}
	double ShowDesviacion(){
		return desviacion;
	}
	void SetEsperanza(string msj1){
		double dato_esperanza;

		cout << msj1;
		cin >> dato_esperanza;
		esperanza = dato_esperanza;
	}
	double ShowEsperanza(){
		return esperanza;
	}
	void SetXMinima(string msj2){
		double dato_x_min;

		cout << msj2;
		cin >> dato_x_min;
		abscisa_minima = dato_x_min;
	}
	double ShowXMinima(){
		return abscisa_minima;
	}
	void SetXMaxima(string msj3){
		abscisa_maxima = LeeDoubleMayorIgualQue(abscisa_minima, msj3);
	}
	double ShowXMaxima(){
		return abscisa_maxima;
	}
	void SetIncremento(string msj4){
		incremento = LeeDoubleMayorIgualQue(0, msj4);
	}
	double ShowIncremento(){
		return incremento;
	}
	void SetGaussiana(double x){
		valor_de_funcion = CalculaGaussiana(x);
	}
	double ShowGaussiana(){
		return valor_de_funcion;
	}
	void SetCDF(double x){
		cdf = CalculaCDF(x);
	}
	double ShowCDF(){
		return cdf;
	}
	double CalculaGaussiana(double x){
		double valor_tipificado,
			 	 exponente;

		valor_tipificado = (x - esperanza) / desviacion;
		exponente =			-0.5 * valor_tipificado * valor_tipificado;
		
		return exp(exponente) / ( desviacion * sqrt(2*PI) );
	}
	double CalculaCDF(double x){
		const double b0 = 	0.2316419,
						 b1 = 	0.319381530,
						 b2 =	  -0.356563782,
						 b3 = 	1.781477937,
						 b4 =   -1.821255978,
						 b5 = 	1.330274429;
		double t = 1 / ( 1 + b0 * x ),
				 Taylor = b1*t + b2*Potencia(t , 2) + b3*Potencia(t , 3) + b4*Potencia(t , 4) + b5*Potencia(t , 5);
		return 1 - CalculaGaussiana(x) * Taylor;
	}
};

/////////// Principal
int main(){
	
	cout << MensajeComienzo();
	
	/////////// Objetos
	Gaussiana funcion;

	/////////// Declaración de variables
	double x;
	char	 menu;
	string desviacion_txt = 	"Introduzca el valor de la variable --> desviacion: ",
			 abscisa_txt = 		"Introduzca el valor máximo de la variable --> X(abcisas): ",
			 incremento_txt = 	"Introduzca el incremento: ",
			 esperanza_txt = 		"\nIntroduzca el valor de la variable --> esperanza: ",
			 x_min_txt = 			"\nIntroduzca el valor mínimo de la variable --> X(abcisas): ";
	
	while (menu != 'S'){
		
		cout << " ··· Introducir parámetros (P)\n";
		cout << " ··· Salir del programa (S)\n\n";
		cin >> menu;
		menu = toupper(menu);
	
		/////////// Introducción de datos
		while (menu == 'P'){
		
			funcion.SetEsperanza(esperanza_txt);

			funcion.SetDesviacion(desviacion_txt);
			
			menu = '1';
			
			while (menu == '1'){
			
				cout << "\n\n\n ··· Introducir rango de valores de x (R)\n";
				cout << " ··· Volver al menú anterior (el menú principal) (M)\n\n";
				cin >> menu;
				menu = toupper(menu);
			
				while (menu == 'R'){
				
					funcion.SetXMinima(x_min_txt);
					funcion.SetXMaxima(abscisa_txt);					
					funcion.SetIncremento(incremento_txt);
					
					/////////// Cómputos y resultados
					x = funcion.ShowXMinima();
					
					do{
						funcion.SetGaussiana(x);
						funcion.SetCDF(x);

						cout << "\n\nEl valor de la función gaussiana en " << x << " es " << funcion.ShowGaussiana();
						cout << "\nEl valor de la distribución acumulada hasta " << x << " es " << funcion.ShowCDF();
		
						x = x + funcion.ShowIncremento();
					}while (x <= funcion.ShowXMaxima());
	
					menu = '1';
				}
			}
		}
	}
}
