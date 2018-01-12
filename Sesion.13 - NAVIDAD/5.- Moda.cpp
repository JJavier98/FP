/*

########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########

### José Javier Alonso Ramos
### 1º de carrera
### Grupo A1
### Práctica 13: Vectores
### Ejercicio 5
### 

###########################################################

[Moda]

Recupere la solución del ejercicio 10 de la relación de problemas IV (Moda).
Re-escriba el método Moda de la siguiente forma:
	 Use como dato local para guardar los caracteres procesados un objeto de la clase
SecuenciaCaracteres, en vez de un vector clásico de corchetes.

	 Defina dentro de la clase SecuenciaCaracteres el método
int NumeroOcurrencias(char buscado, int izda, int dcha)
que devuelve el número de ocurrencias de un valor buscado entre las posiciones
izda y dcha de la secuencia. Llame a este método dentro de Moda para calcular
las frecuencias de cada carácter.

*/

#include <iostream>
using namespace std;

string MensajeComienzo(){
   return "########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########\n\n### José Javier Alonso Ramos\n### 1º de carrera\n### Grupo A1\n### Práctica 13: Vectores\n### Ejercicio 5\n\n\n\n";
}

struct FrecuenciaCaracter{
   char caracter;
   int frecuencia;
};

class SecuenciaCaracteres{
private:
	static const char TERMINADOR = '#';
	static const int TAMANIO = 1e5;
	char v_caracteres[TAMANIO];
	long long utilizados_caracteres;
	
public:
	SecuenciaCaracteres()
		:utilizados_caracteres(0)
		{
		}
		
	void SetVectorCaracteres(){
		char dato = ' ';
		bool encontrado;

		cout << "Introduzca la serie de caracteres.\n --> ";
		while (dato != TERMINADOR ){
	   	if ( dato != ' ' ){
	   		v_caracteres[utilizados_caracteres] = dato;
	   		utilizados_caracteres++;
	   	}
	   	
	      dato = cin.get();
	   }
	}
	
	int NumeroOcurrencias(char caracter, int izda, int dcha){
		int num_ocurrencias = 0;
		
		for ( int i = izda ; i <= dcha && i <= utilizados_caracteres ; i++){
	   	if (v_caracteres[i] == caracter){
	   		num_ocurrencias++;
			}
		}
		return num_ocurrencias;
	}
	
	FrecuenciaCaracter Moda(){
		FrecuenciaCaracter modelo;
		int num_ocurrencias;

		for (int i = 0 ; i < utilizados_caracteres ; i++){
			
	   	num_ocurrencias = NumeroOcurrencias(v_caracteres[i], 0, utilizados_caracteres);
	   	
	   	if (modelo.frecuencia < num_ocurrencias || i == 0){
	   		modelo.caracter = v_caracteres[i];
	   		modelo.frecuencia = num_ocurrencias;
			}
		}
		return modelo;
	}
	
};

int main(){
	cout << MensajeComienzo();
	//////////////////////////////////////////////////////////////////
	// Variables

	SecuenciaCaracteres objeto;
	
	int izquierda, derecha, ocurrencias;
	char caracter;
	
	 //////////////////////////////////////////////////////////////////
   // Lectura de los datos - Trabajo con vectores dentro de una clase.
   
   objeto.SetVectorCaracteres();
   
   cout << "Señale el caracter a buscar, el limite izquierdo y el derecho en ese orden: ";
   cin >> caracter;
   cin >> izquierda;
   cin >> derecha;
   
	 ///////////////////////////////////////////////////////////////
   // Resultados
	
	cout << "El caracter que mas se repite es: " << objeto.Moda().caracter << " \nY se repite:" << objeto.Moda().frecuencia << " veces.";
	cout << "\n\nEl número de ocurrencias del caracter '" << caracter << "' es: " << objeto.NumeroOcurrencias(caracter, izquierda, derecha);
}
