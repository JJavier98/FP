/*

########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########

### Jos� Javier Alonso Ramos
### 1� de carrera
### Grupo A1
### Pr�ctica 11: Vectores y matrices
### Ejercicio 4
### 
[Moda].
Se quiere calcular la moda de un vector de caracteres, es decir, el car�cter
que m�s veces se repite. Por ejemplo, si el vector fuese
{'l','o','s',' ','d','o','s',' ','c','o','f','r','e','s'}
los caracteres que m�s se repiten son 'o' y 's' con un total de 3 apariciones. La
moda ser�a cualquiera de ellos, por ejemplo, el primero encontrado 'o'.
Para almacenar de forma conjunta el car�cter y la frecuencia usaremos el siguiente
struct:

	struct FrecuenciaCaracter{
		char caracter;
		int frecuencia;
	}
	
El campo caracter contendr� el car�cter en cuesti�n ('o') y en el campo
frecuencia el conteo de la moda (3).
Construya un programa que lea caracteres con cin.get() (repase lo visto al inicio
de esta relaci�n de problemas) hasta que el usuario introduzca el car�cter #. Almacene
todos los valores en un vector de caracteres. A continuaci�n, calcule la moda y
mu�strela en pantalla junto con su frecuencia.
Para calcular la moda, se recomienda que use un vector auxiliar en el que almacene
los caracteres que ya se han procesado en alg�n momento anterior.
Utilice el texto del Quijote sin espacios en blanco disponible en:

http://decsai.ugr.es/~carlos/FP/Quijo_sin_espacios.txt

La moda es la letra 'e' con un total de 217900 apariciones.

*/

#include <iostream>
using namespace std;

string MensajeComienzo(){
   return "########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########\n\n### Jos� Javier Alonso Ramos\n### 1� de carrera\n### Grupo A1\n### Pr�ctica 11: Vectores y matrices\n### Ejercicio 4\n\n\n\n";
}

struct FrecuenciaCaracter{
	char caracter;
	int frecuencia;
};

int main(){
	//////////////////////////////////////////////////////////////////
	// Variables
	
	const int TAMANIO = 1e5;
	const char TERMINADOR = '#';
	char dato = ' ';
	long long utilizados_caracteres = 0;
	bool encontrado;
	FrecuenciaCaracter v_caracteres[TAMANIO], modelo;

	cout << MensajeComienzo();
	
	
	 //////////////////////////////////////////////////////////////////
   // Lectura de los datos ; Trabajo con vectores
   
	cout << "Introduzca la serie de caracteres.\n --> ";
	while (dato != TERMINADOR ){
      
		encontrado = false;
   	for (int j = 0 ; j < utilizados_caracteres ; j++){

   		if (v_caracteres[j].caracter == dato){
   			encontrado = true;
   			v_caracteres[j].frecuencia++;
   		}
   	}
   	if (encontrado == false && dato != ' '){
   		v_caracteres[utilizados_caracteres].caracter = dato;
   		v_caracteres[utilizados_caracteres].frecuencia = 1;
   		utilizados_caracteres++;
   	}
   	
      dato = cin.get();
   }

   for (int i = 0 ; i < utilizados_caracteres ; i++){
			
   	if (i == 0 || modelo.frecuencia < v_caracteres[i].frecuencia){
   		modelo = v_caracteres[i];
		}
	}
	
	 ///////////////////////////////////////////////////////////////
   // Resultados
	
	cout << "El caracter que mas se repite es: " << modelo.caracter << " \nY se repite:" << modelo.frecuencia;
}
