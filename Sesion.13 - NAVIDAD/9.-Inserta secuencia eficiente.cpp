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
		char dato;

		dato = cin.get();
		
		while (dato != TERMINADOR ){
	   	
   		v_caracteres[utilizados_caracteres] = dato;
   		utilizados_caracteres++;
	   	
	   	
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
	
	void EliminaExcesoBlancos(){
		int posicion = 0;
		
		while(posicion < utilizados_caracteres){
			if (v_caracteres[posicion] == ' ' && v_caracteres[posicion + 1] == ' '){
				
				for (int i = posicion + 1 ; i < utilizados_caracteres ; i++){
					v_caracteres[i] = v_caracteres[i+1];
				}
				utilizados_caracteres--;
			}
			else 
				posicion++;
		}
	}
	
	void Inserta (char caracter, int posicion){
		for (int i = utilizados_caracteres ; i > posicion ; i--)
			v_caracteres[i] = v_caracteres[i-1];
			
		v_caracteres[posicion] = caracter;
		utilizados_caracteres++;
	}
	
	string ToString(){
		return v_caracteres;
	}
	
};

int main(){
	cout << MensajeComienzo();
	//////////////////////////////////////////////////////////////////
	// Variables
	
	SecuenciaCaracteres cadena_1;
	
	cout << "Introduzca la cadena de caracteres: ";
	cadena_1.SetVectorCaracteres();
	
	cadena_1.EliminaExcesoBlancos();
	
	cout << cadena_1.ToString();
}






























