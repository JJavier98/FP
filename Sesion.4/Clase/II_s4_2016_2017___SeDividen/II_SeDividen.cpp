//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////


// Ver si dos enteros se dividen

/*
Realice un programa en C++ que lea dos valores enteros desde teclado y
diga si cualquiera de ellos divide o no (de forma entera) al otro.
En este problema no hace falta decir quién divide a quién.
Supondremos que los valores leídos desde teclado son ambos distintos
de cero.
*/

#include <iostream>
using namespace std;

int main(){
   int a, b;   // Nunca usaremos nombres de variables tan cortos como a, b
					// Este ejercicio es una excepción ya que los datos son genéricos
   bool se_dividen;

	// Entrada de datos

   cout << "\nIntroduzca primer valor ";      
   cin >> a;                           
   cout << "\nIntroduzca segundo valor ";      
   cin >> b;                          

   // Cómputos
   
   se_dividen = (a % b == 0 || b % a == 0);

	// Salida de Resultados 

   if (se_dividen)
      cout << "\nUno divide al otro";
   else
      cout << "\nNinguno divide al otro";
}
