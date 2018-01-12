//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Pasar un carácter de mayúscula a minúscula. 
// Si no es mayúscula, se devuelve el mismo carácter.


#include <iostream>
using namespace std;

/*
Se quiere leer un carácter letra_original desde teclado, y comprobar con
una estructura condicional si es una letra mayúscula.
En dicho caso, hay que calcular la minúscula correspondiente almacenando
el resultado en una variable llamada letra_convertida .
En el caso de que no sea una mayúscula, le asignaremos a
letra_convertida el valor que tenga letra_original .
Finalmente, imprimiremos en pantalla el valor de letra_convertida .
No pueden usarse las funciones tolower ni toupper de la biblioteca cctype
*/

int main(){
   /*
   Hay 32 caracteres de diferencia entre las mayúsculas y las minúsculas
   y hay el mismo número de ellas (y están en el mismo orden)
   Por tanto, basta hacer mayuscula + 32 para obtener la correspondiente
   minúscula:
   
      letra_convertida = letra_original + 32;
   
   Pero debemos evitar los "números mágicos" como 32.
   Lo obtenemos a través de la constante simbólica DISTANCIA_MAY_MIN
   y no la inicializamos a 32 sino a 'a'-'A' que es mucho más informativo.
   */
   
   char letra_convertida, letra_original;
   const int DISTANCIA_MAY_MIN = 'a'-'A';

   cout << "\nIntroduzca una letra  --> ";
   cin >> letra_original;

   /* 
   El código siguiente repite las expresiones lógicas de las condiciones:
   
   if ((letra_original >= 'A') && (letra_original <= 'Z'))
      letra_convertida = letra_original + DISTANCIA_MAY_MIN

   if (!(((letra_original >= 'A') && (letra_original <= 'Z'))))
      letra_convertida = letra_original;
   
   Al ser mutuamente excluyentes, usamos mejor un else:
   */

   if ((letra_original >= 'A') && (letra_original <= 'Z'))
      letra_convertida = letra_original + DISTANCIA_MAY_MIN
   else
      letra_convertida = letra_original;

   cout  << "\nEl carácter " << letra_original
         << " una vez convertido es: " << letra_convertida;

}
