/*

########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########

### José Javier Alonso Ramos
### 1º de carrera
### Grupo A1
### Práctica 11: Vectores y matrices
### Ejercicio 4
### 
[Moda].
Se quiere calcular la moda de un vector de caracteres, es decir, el carácter
que más veces se repite. Por ejemplo, si el vector fuese
{'l','o','s',' ','d','o','s',' ','c','o','f','r','e','s'}
los caracteres que más se repiten son 'o' y 's' con un total de 3 apariciones. La
moda sería cualquiera de ellos, por ejemplo, el primero encontrado 'o'.
Para almacenar de forma conjunta el carácter y la frecuencia usaremos el siguiente
struct:

	struct FrecuenciaCaracter{
		char caracter;
		int frecuencia;
	}
	
El campo caracter contendrá el carácter en cuestión ('o') y en el campo
frecuencia el conteo de la moda (3).
Construya un programa que lea caracteres con cin.get() (repase lo visto al inicio
de esta relación de problemas) hasta que el usuario introduzca el carácter #. Almacene
todos los valores en un vector de caracteres. A continuación, calcule la moda y
muéstrela en pantalla junto con su frecuencia.
Para calcular la moda, se recomienda que use un vector auxiliar en el que almacene
los caracteres que ya se han procesado en algún momento anterior.
Utilice el texto del Quijote sin espacios en blanco disponible en:

http://decsai.ugr.es/~carlos/FP/Quijo_sin_espacios.txt

La moda es la letra 'e' con un total de 217900 apariciones.

*/

#include <iostream>
using namespace std;

string MensajeComienzo(){
   return "########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########\n\n### José Javier Alonso Ramos\n### 1º de carrera\n### Grupo A1\n### Práctica 11: Vectores y matrices\n### Ejercicio 4\n\n\n\n";
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
