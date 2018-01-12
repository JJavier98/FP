//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Pasar un car�cter de may�scula a min�scula y viceversa

/*
Leer un car�cter letra_original desde teclado y hacer lo siguiente:

� Si es una letra may�scula, almacenaremos en la variable letra_convertida
la correspondiente letra min�scula.
� Si es una letra min�scula, almacenaremos en la variable letra_convertida
la correspondiente letra may�scula.
� Si es un car�cter no alfab�tico, almacenaremos el mismo car�cter en la
variable letra_convertida

El programa debe imprimir en pantalla el valor de letra_convertida e
indicar si la letra introducida era una min�scula, may�scula o no era
una car�cter alfab�tico.

No pueden usarse las funciones tolower ni toupper de la biblioteca cctype
*/

#include <iostream>
using namespace std;

int main(){
   char letra_convertida, letra_original;
   const int DISTANCIA_MAY_MIN = 'a'-'A';             

   cout << "\nIntroduzca una letra  --> ";
   cin >> letra_original;

   /*
   if ((letra_original >= 'A') && (letra_original <= 'Z'))
      letra_convertida = letra_original + DISTANCIA_MAY_MIN;    
   else
      if ((letra_original >= 'a') && (letra_original <= 'z'))
         letra_convertida = letra_original - DISTANCIA_MAY_MIN;
      else
         letra_convertida = letra_original;
   */
   
   // La forma anterior de tabular es correcta.
   // La siguiente tambi�n lo es.
   // La usaremos cuando tengamos varios if else if ...
   
   if ((letra_original >= 'A') && (letra_original <= 'Z'))
      letra_convertida = letra_original + DISTANCIA_MAY_MIN;
   else if ((letra_original >= 'a') && (letra_original <= 'z'))
      letra_convertida = letra_original - DISTANCIA_MAY_MIN;
   else
      letra_convertida = letra_original;

   cout << "\nEl car�cter " << letra_original  
        << " una vez convertido es: " << letra_convertida;
}
