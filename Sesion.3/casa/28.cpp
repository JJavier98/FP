#include<iostream>
#include<cmath>

using namespace std;

int main(){
	
// a)
	
//	int chico, chico1, chico2;
//	chico1 = 1234567;
//	chico2 = 1234567;
//	chico = chico1 * chico2;
	
//	cout << chico;
	
			/*
			Se produce un desbordamiento.
			El producto de las dos variables "int" chico1 y chico 2
			resulta en un número demasiado grande para asignárselo a un "int".
			Resultado: -557712591
			*/
			
					//_________________________________________________________________________
			
//	b)		
	
//	long grande;
//	int chico1, chico2;
//	chico1 = 1234567;
//	chico2 = 1234567;
//	grande = chico1 * chico2;
	
//	cout << grande;
	
			/*
			Se produce un desbordamiento.
			El producto de dos variables "int" da de resultado otro "int",
			y es aqui donde se produce el desbordamiento. El resultado es demasiado grande
			como para ser un "int" aunque no hay problema en asignarlo después a la variable "long".
			*/
			
					//_________________________________________________________________________
	
//	c)	
	
//	cout.precision(15);
			
//	double real, real1, real2;
//	real1 = 123.1;
//	real2 = 124.2;
//	real = real1 * real2;
	
//	cout << real;
	
			/*
			El programa no compila porque utiliza una variable (resultado)
			que no ha sido declarada con anterioridad. Suponiendo que 
			en vez de "resultado" se llamase "real" el resultado sería: 15289.02
			*/
			
					//_________________________________________________________________________
			
//	d)
	
//	cout.precision(20);

//	double real, real1, real2;
//	real1 = 123456789.1;
//	real2 = 123456789.2;
//	real = real1 * real2;
	
//	cout << real;
	
			/*
			El programa no compila porque utiliza una variable (resultado)
			que no ha sido declarada con anterioridad. Suponiendo que 
			en vez de "resultado" se llamase "real" el resultado sería: 15241578787227558
			Suponiendo un error de precisión.
			*/
			
					//_________________________________________________________________________
			
//	e)

//	cout.precision(20);
	
//	double real, otro_real;
//	real = 2e34;
//	otro_real = real + 1;
//	otro_real = otro_real - real;
	
//	cout << otro_real;
	
			/*
			Se produce un error de precisión debido a que
			los números con los que trabaja el programa son demasiado grandes.
			El resultado mostrado es 0.
			*/
	
					//_________________________________________________________________________
	
//	f)

//	cout.precision(20);

//	double real, otro_real;
//	real = 1e+300;
//	otro_real = 1e+200;
//	otro_real = otro_real * real;
	
//	cout << otro_real;

			/*
			Se produce un error de precisión debido a que
			los números con los que trabaja el programa son demasiado grandes.
			El resultado mostrado es infinito.
			*/
			
					//_________________________________________________________________________
			
//	g)

//	cout.precision(20);

//	float chico;
//	double grande;
//	grande = 2e+150;
//	chico = grande;
	
//	cout << chico;

			/*
			Se produce un error de precisión debido a que
			los números con los que trabaja el programa son demasiado grandes y
			se produciría un desbordamiento si el número de la variable "double" fuese demasiado grande
			como para asignárselo a la variable "float".
			El resultado mostrado es infinito.
			*/
}



























