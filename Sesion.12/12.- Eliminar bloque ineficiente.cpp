/*

########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########

### José Javier Alonso Ramos
### 1º de carrera
### Grupo A1
### Práctica 12: Vectores y matrices
### Ejercicio 12
### 

###########################################################

[Elimina bloque, versión ineficiente]

Sobre la clase SecuenciaCaracteres, añada
el método EliminaBloque para que borre todos los caracteres que haya entre dos
posiciones. Por ejemplo, después de eliminar el bloque que hay entre las posiciones
1 y 3 de la secuencia {'S','o','Y',' ','y','o'}, ésta debe quedarse con
{'S','y','o'}.

Un primer algoritmo para resolver este problema sería el siguiente (en ejercicios posteriores
se verán métodos más eficientes):

Para borrar el bloque entre izda y dcha:
	Recorrer cada componente -i- de la secuencia
	entre las posiciones izda y dcha
	Eliminar dicha componente -i-
	Para eliminar una posición llame al método Elimina (que borra un único carácter) La
	implementación de este método se ha visto en clase de teoría.
	
Construya un programa que lea caracteres hasta el terminador #. A continuación lea
dos enteros que representen las posiciones izquierda ( 0) y derecha (entre izquierda
y la última componente de la secuencia) (use las funciones LeeIntMayorIgualQue
y LeeIntRango de los ejercicios 4 y 5 de esta relación de problemas) e imprima la
secuencia resultante de quitar el bloque de caracteres.

Ejemplo de entrada: abcdefg# 1 3 .... Salida correcta: aefg
Ejemplo de entrada: abcdefg# 1 0 -1 15 3 .... Salida correcta: aefg
Ejemplo de entrada: abcdefg# 0 5 .... Salida correcta: g

*/

#include <iostream>
using namespace std;

string MensajeComienzo(){
   return "########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########\n\n### José Javier Alonso Ramos\n### 1º de carrera\n### Grupo A1\n### Práctica 12: Vectores y matrices\n### Ejercicio 12\n\n\n\n";
}

// Prec:
// min y max deben ser enteros
// min < max
// mensaje concorde al uso del programa
int LeeIntRango(int min, int max, string mensaje) {
   int a_leer;
   
   do{
      cout << mensaje;
      cin >> a_leer;
   }while (min > a_leer || max < a_leer);
   
   return a_leer;
}

// Prec:
// mensaje debe ser concorde al uso del programa
int LeeIntMayorIgualQue (int valor_minimo , string mensaje){
	int valor_superior;
	
	do{
		cout << mensaje;
		cin >> valor_superior;
	}while (valor_superior < valor_minimo);
	
	return valor_superior;
}

struct FrecuenciaCaracter{
   char caracter;
   int frecuencia;
};

class SecuenciaCaracteres{
private:
	static const char TERMINADOR = '#';
   static const int TAMANIO = 2e6;
	char vector [TAMANIO];
	long long utilizados_vector;
	
public:
	SecuenciaCaracteres()
		:utilizados_vector(0)
		{
		}
		
	void SetVectorCaracteres(){
		char dato;

		cout << "Introduzca la serie de caracteres.\n --> ";
		dato = cin.get();
		while (dato != TERMINADOR ){
	      vector[utilizados_vector] = dato;
	      utilizados_vector++;	   	
	      dato = cin.get();
	   }
	}
	
	FrecuenciaCaracter Moda(){
		long long utilizados_caracteres = 0;
		bool encontrado;
		int j;
   	const int NUMERO_CARACTERES_ASCII = 256;
		FrecuenciaCaracter v_caracteres[NUMERO_CARACTERES_ASCII];
		FrecuenciaCaracter modelo;
		
		for (int i = 0 ; i < utilizados_vector ; i++){
			encontrado = false;
			
			for (j = 0 ; j < utilizados_caracteres ; j++){
	   		if (v_caracteres[j].caracter == vector[i]){
	   			encontrado = true;
	   			v_caracteres[j].frecuencia++;
	   			
			   	if (modelo.frecuencia < v_caracteres[j].frecuencia){
			   		modelo = v_caracteres[j];
					}
	   		}
	   	}
	   	
	   	if (encontrado == false){
	   		v_caracteres[utilizados_caracteres].caracter = vector[i];
	   		v_caracteres[utilizados_caracteres].frecuencia = 1;
	   		utilizados_caracteres++;
	   	}
			
	   	if (i == 0){
	   		modelo = v_caracteres[0];
			}
		}
		
		return modelo;
	}
	
	void Elimina (int posicion){
      if (posicion >= 0 && posicion < utilizados_vector){
         int tope = utilizados_vector-1;

         for (int i = posicion ; i < tope ; i++)
            vector[i] = vector[i+1];

         utilizados_vector--;
      }
   }
   
   	char* EliminaBloqueIneficiente(int p_inicial, int p_final){
	
		for (int j = p_inicial ; j <= p_final ; j++){
			Elimina(p_inicial);
			
		}
		
		return vector;
	}
	
	char* EliminaCaracter(char caracter){
		int tope;
		
		for (int posicion = 0 ; posicion < utilizados_vector; posicion++){
			if (caracter == vector[posicion]){
		
				tope = utilizados_vector-1;
				
				for (int j = posicion ; j < tope ; j++)
					vector[j] = vector[j+1];
					
				utilizados_vector--;
			}
			if (caracter == vector[posicion]){
				posicion--;
			}
		}
		return vector;
	}
	
	char* GetVector(){
		return vector;			
	}
	
	int GetUtilizadosVector(){
		return utilizados_vector;
	}
	
};

int main(){
	
	cout << MensajeComienzo();
	//////////////////////////////////////////////////////////////////
	// Variables

	const int TAMANIO = 1e5;
	char caracter;
	int minimo, maximo, utilizados_vector;
	SecuenciaCaracteres objeto;
	FrecuenciaCaracter moda;
	char vector[TAMANIO];
	string minimo_txt = "Introduzca un valor inicial para empezar a borrar: ";
	string maximo_txt = "Señale la posicion final de borrado: ";
	
	 //////////////////////////////////////////////////////////////////
   // Lectura de los datos - Trabajo con vectores dentro de una clase.
   
   objeto.SetVectorCaracteres();
   
 	minimo = LeeIntRango(0, objeto.GetUtilizadosVector(), minimo_txt);
 	maximo = LeeIntRango(minimo, objeto.GetUtilizadosVector(), maximo_txt); 	
	
	objeto.EliminaBloqueIneficiente(minimo, maximo);
	
	 ///////////////////////////////////////////////////////////////
   // Resultados
   
	cout << "El nuevo vector es: \n";
	utilizados_vector = objeto.GetUtilizadosVector();
	for(int i = 0 ; i < utilizados_vector ; i++){
		cout << objeto.GetVector()[i] << ", ";
	}
	
}
