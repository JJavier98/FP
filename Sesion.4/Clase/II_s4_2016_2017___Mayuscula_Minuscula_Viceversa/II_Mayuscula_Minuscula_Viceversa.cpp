//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Pasar un carácter de mayúscula a minúscula y viceversa

/*
Leer un carácter letra_original desde teclado y hacer lo siguiente:

• Si es una letra mayúscula, almacenaremos en la variable letra_convertida
la correspondiente letra minúscula.
• Si es una letra minúscula, almacenaremos en la variable letra_convertida
la correspondiente letra mayúscula.
• Si es un carácter no alfabético, almacenaremos el mismo carácter en la
variable letra_convertida

El programa debe imprimir en pantalla el valor de letra_convertida e
indicar si la letra introducida era una minúscula, mayúscula o no era
una carácter alfabético.

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
   // La siguiente también lo es.
   // La usaremos cuando tengamos varios if else if ...
   
   if ((letra_original >= 'A') && (letra_original <= 'Z'))
      letra_convertida = letra_original + DISTANCIA_MAY_MIN;
   else if ((letra_original >= 'a') && (letra_original <= 'z'))
      letra_convertida = letra_original - DISTANCIA_MAY_MIN;
   else
      letra_convertida = letra_original;

   cout << "\nEl carácter " << letra_original  
        << " una vez convertido es: " << letra_convertida;
}
