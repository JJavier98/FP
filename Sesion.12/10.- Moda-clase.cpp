/*

########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########

### Jos� Javier Alonso Ramos
### 1� de carrera
### Grupo A1
### Pr�ctica 12: Vectores y matrices
### Ejercicio 10
### 

###########################################################

[Moda].

Recupere la soluci�n del ejercicio 4. Defina el m�todo Moda dentro de
la clase SecuenciaCaracteres. Este m�todo debe devolver un dato de tipo
FrecuenciaCaracter (struct)
Apl�quelo sobre el texto del Quijote sin espacios
en blanco disponible en:

http://decsai.ugr.es/~carlos/FP/Quijo_sin_espacios.txt

La moda es la letra 'e' con un total de 217900 apariciones.

*/

#include <iostream>
using namespace std;

string MensajeComienzo(){
   return "########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########\n\n### Jos� Javier Alonso Ramos\n### 1� de carrera\n### Grupo A1\n### Pr�ctica 12: Vectores y matrices\n### Ejercicio 10\n\n\n\n";
}

struct FrecuenciaCaracter{
   char caracter;
   int frecuencia;
};

class SecuenciaCaracteres{
private:
	static const char TERMINADOR = '#';
	static const int TAMANIO = 1e5;
	FrecuenciaCaracter v_caracteres[TAMANIO];
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
	      
			encontrado = false;
	   	for (int i = 0 ; i < utilizados_caracteres ; i++){

	   		if (v_caracteres[i].caracter == dato){
	   			encontrado = true;
	   			v_caracteres[i].frecuencia++;
	   		}
	   	}
	   	if (encontrado == false && dato != ' '){
	   		v_caracteres[utilizados_caracteres].caracter = dato;
	   		v_caracteres[utilizados_caracteres].frecuencia = 1;
	   		utilizados_caracteres++;
	   	}
	   	
	      dato = cin.get();
	   }
	}
	
	FrecuenciaCaracter Moda(){
		FrecuenciaCaracter modelo;

		for (int i = 0 ; i < utilizados_caracteres ; i++){
			
	   	if (i == 0 || modelo.frecuencia < v_caracteres[i].frecuencia){
	   		modelo = v_caracteres[i];
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
	
	 //////////////////////////////////////////////////////////////////
   // Lectura de los datos - Trabajo con vectores dentro de una clase.
   
   objeto.SetVectorCaracteres();
	
	 ///////////////////////////////////////////////////////////////
   // Resultados
	
	cout << "El caracter que mas se repite es: " << objeto.Moda().caracter << " \nY se repite:" << objeto.Moda().frecuencia << " veces.";
}
