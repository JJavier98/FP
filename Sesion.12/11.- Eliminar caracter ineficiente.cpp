/*

########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########

### Jos� Javier Alonso Ramos
### 1� de carrera
### Grupo A1
### Pr�ctica 12: Vectores y matrices
### Ejercicio 11
### 

###########################################################

[Elimina ocurrencias]

Sobre la clase SecuenciaCaracteres, a�ada el m�todo
EliminaOcurrencias para eliminar todas las apariciones de un determinado car�cter
a_borrar. Por ejemplo, despu�s de eliminar el car�cter 'o' de la secuencia
{'S','o','Y',' ','y','o'}, �sta debe quedarse con {'S','Y',' ','y'}.


Un primer algoritmo para resolver este problema ser�a el siguiente (en ejercicios posteriores
se ver�n m�todos m�s eficientes):

Recorrer todas las componentes de la secuencia
Si la componente es igual al car�cter a_borrar, eliminarla
(desplazando hacia la izda las componentes que hay a su dcha)

Queremos implementarlo llamando al m�todo Elimina (que borra un �nico car�cter)
La implementaci�n de este m�todo se ha visto en clase de teor�a.

class SecuenciaCaracteres{
.........
	void EliminaOcurrenciasERROR(){
		for (int i = 0; i < total_utilizados; i++)
			if (vector_privado[i] == a_borrar)
				Elimina(i);
	}
};

*/

#include <iostream>
using namespace std;

string MensajeComienzo(){
   return "########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########\n\n### Jos� Javier Alonso Ramos\n### 1� de carrera\n### Grupo A1\n### Pr�ctica 12: Vectores y matrices\n### Ejercicio 11\n\n\n\n";
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

	char caracter;
	SecuenciaCaracteres objeto;
	FrecuenciaCaracter moda;
	
	 //////////////////////////////////////////////////////////////////
   // Lectura de los datos - Trabajo con vectores dentro de una clase.
   
   objeto.SetVectorCaracteres();
   
   cout << "Caracter a eliminar: ";
   cin >> caracter;
   
   objeto.EliminaCaracter(caracter);
	
	 ///////////////////////////////////////////////////////////////
   // Resultados
	moda = objeto.Moda();
	cout << "El caracter que mas se repite es: " << moda.caracter << " \nY se repite:" << moda.frecuencia << " veces.\n";
	

	for(int i = 0 ; i < objeto.GetUtilizadosVector() ; i++){
		cout << objeto.GetVector()[i] << ", ";
	}
}
