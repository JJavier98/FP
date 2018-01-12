/*

########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########

### Jos� Javier Alonso Ramos
### 1� de carrera
### Grupo A1
### Pr�ctica 11: Vectores y matrices
### Ejercicio 3
### 
[k mayores que otro valor, eficiente].
Modifique la soluci�n del ejercicio 2 usando un
algoritmo m�s eficiente. Observe que no hace falta ordenar todo el vector, sino �nicamente
considerar los datos que son mayores que la referencia.
Aplique el siguiente algoritmo:
Recorrer las componentes del vector original
Si es mayor que la referencia, insertar dicho
valor de forma ordenada en el vector "mayores_que"
El vector "mayores_que" siempre tendr�,
como mucho, k componentes
Mientras que la versi�n vista en el ejercicio 2 tardaba varios segundos, esta nueva
versi�n tarda menos de un segundo.
Finalidad: Recorrido sobre un vector, insertando componentes. Dificultad Media.

*/

#include <iostream>
using namespace std;

string MensajeComienzo(){
   return "########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########\n\n### Jos� Javier Alonso Ramos\n### 1� de carrera\n### Grupo A1\n### Pr�ctica 11: Vectores y matrices\n### Ejercicio 3\n\n\n\n";
}

int main(){
	//////////////////////////////////////////////////////////////////
	// Variables
	
   const int TERMINADOR = -1;
   double dato, referencia, a_desplazar;
   const int TAMANIO = 1e5;
   double vector[TAMANIO], mayores_que[TAMANIO];
   int utilizados_vector = 0, iteraciones = 0, j, k;

	cout << MensajeComienzo();
	
   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:

   cout << "k valores mayores que."
        << "\nIntroduzca reales positivos con terminador "
        << TERMINADOR << "\n";
        
   utilizados_vector = 0;
   cin >> dato;

   while (dato != TERMINADOR && utilizados_vector < TAMANIO){
      vector[utilizados_vector] = dato;
      utilizados_vector++;
      cin >> dato;
   }
	
	cout << "Ahora introduzca el valor de referencia y k.\n";
   cin >> referencia;
   cin >> k;

	//////////////////////////////////////////////////////////////////
	// Trabajo con vectores

	for (int i = 0 ; i < utilizados_vector ; i++){
		
		if (vector[i] >= referencia && (vector[i] < mayores_que[k - 1] || mayores_que[k - 1] == 0 )){
			a_desplazar = vector[i];
			
			if (iteraciones == 0){
				mayores_que[iteraciones] = a_desplazar;
				iteraciones++;
				
			} else {
				for (j = i; j > 0 && (a_desplazar < mayores_que[j-1] || mayores_que[j-1] == 0); j--){
					if (j < k)
						mayores_que[j] = mayores_que[j-1];
				}
					
				mayores_que[j] = a_desplazar;
			}
		}
	}

   ///////////////////////////////////////////////////////////////
   // Resultados
	
   for (int l = 0; l < k; l++)
      cout << mayores_que[l] << " ";
}
