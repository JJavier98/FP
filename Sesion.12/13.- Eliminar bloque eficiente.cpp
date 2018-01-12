/*

########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########

### José Javier Alonso Ramos
### 1º de carrera
### Grupo A1
### Práctica 12: Vectores y matrices
### Ejercicio 13
### 

###########################################################

[Elimina bloque, versión eficiente]

Resuelva el ejercicio 12 pero de una forma eficiente.
Para ello, implemente el siguiente algoritmo:

Para borrar el bloque entre izda y dcha:

	Calcular num_a_borrar como dcha - izda + 1
	
	Recorrer las componentes -i- de la secuencia
	entre las posiciones dcha+1 hasta el final
		Colocar la componente -i- en la posición
		i - num_a_borrar
			
	Actualizar total_utilizados
	
Este algoritmo resuelve el problema con un único bucle mientras que la versión ineficiente
recurría a dos bucles anidados.

*/

#include <iostream>
using namespace std;

string MensajeComienzo(){
   return "########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########\n\n### José Javier Alonso Ramos\n### 1º de carrera\n### Grupo A1\n### Práctica 12: Vectores y matrices\n### Ejercicio 13\n\n\n\n";
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
	
	char* EliminaBloqueEficiente(int p_inicial, int p_final){
		int tope = utilizados_vector;
		
		for (int j = p_final + 1 ; j < tope ; j++){
			vector[j - (p_final-p_inicial+1)] = vector[j];
		
		}
		utilizados_vector = utilizados_vector - (p_final-p_inicial+1);
		
		return vector;
	}
	
	char* EliminaCaracter(char caracter){
		int tope;
		
		for (int posicion = 0 ; posicion < utilizados_vector; posicion++){
			if (caracter == vector[posicion]){
				tope = utilizados_vector-1;
				
				for (int j = posicion ; j < tope ; j++){
					vector[j] = vector[j+1];
					utilizados_vector--;
				}
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

	char caracter;
	int minimo, maximo, utilizados_vector;
	SecuenciaCaracteres objeto;
	FrecuenciaCaracter moda;
	string minimo_txt = "Introduzca un valor inicial para empezar a borrar: ";
	string maximo_txt = "Señale la posicion final de borrado: ";
	
	 //////////////////////////////////////////////////////////////////
   // Lectura de los datos - Trabajo con vectores dentro de una clase.
   
   objeto.SetVectorCaracteres();
   
 	minimo = LeeIntRango(0, objeto.GetUtilizadosVector(), minimo_txt);
 	maximo = LeeIntRango(minimo, objeto.GetUtilizadosVector(), maximo_txt); 	
 	
 	objeto.EliminaBloqueEficiente(minimo, maximo);
	
	 ///////////////////////////////////////////////////////////////
   // Resultados
   
	cout << "El nuevo vector es: \n";
	utilizados_vector = objeto.GetUtilizadosVector();
	for(int i = 0 ; i < utilizados_vector ; i++){
		cout << objeto.GetVector()[i] << ", ";
	}
	
}
