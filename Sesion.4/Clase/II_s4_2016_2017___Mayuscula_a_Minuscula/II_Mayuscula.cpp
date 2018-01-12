//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Pasar un car�cter de may�scula a min�scula. 
// Si no es may�scula, se devuelve el mismo car�cter.


#include <iostream>
using namespace std;

/*
Se quiere leer un car�cter letra_original desde teclado, y comprobar con
una estructura condicional si es una letra may�scula.
En dicho caso, hay que calcular la min�scula correspondiente almacenando
el resultado en una variable llamada letra_convertida .
En el caso de que no sea una may�scula, le asignaremos a
letra_convertida el valor que tenga letra_original .
Finalmente, imprimiremos en pantalla el valor de letra_convertida .
No pueden usarse las funciones tolower ni toupper de la biblioteca cctype
*/

int main(){
   /*
   Hay 32 caracteres de diferencia entre las may�sculas y las min�sculas
   y hay el mismo n�mero de ellas (y est�n en el mismo orden)
   Por tanto, basta hacer mayuscula + 32 para obtener la correspondiente
   min�scula:
   
      letra_convertida = letra_original + 32;
   
   Pero debemos evitar los "n�meros m�gicos" como 32.
   Lo obtenemos a trav�s de la constante simb�lica DISTANCIA_MAY_MIN
   y no la inicializamos a 32 sino a 'a'-'A' que es mucho m�s informativo.
   */
   
   char letra_convertida, letra_original;
   const int DISTANCIA_MAY_MIN = 'a'-'A';

   cout << "\nIntroduzca una letra  --> ";
   cin >> letra_original;

   /* 
   El c�digo siguiente repite las expresiones l�gicas de las condiciones:
   
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

   cout  << "\nEl car�cter " << letra_original
         << " una vez convertido es: " << letra_convertida;

}
