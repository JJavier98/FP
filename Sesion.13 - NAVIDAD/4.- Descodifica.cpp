/*

########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########

### Jos� Javier Alonso Ramos
### 1� de carrera
### Grupo A1
### Pr�ctica 13: Vectores
### Ejercicio 4
### 

###########################################################

[Descodifica en la clase SecuenciaCaracteres]

(Examen Febrero 2016) Recupere la soluci�n del ejercicio 5 (Descodifica) de la relaci�n de problemas IV.
Implemente el m�todo de descodificaci�n como un m�todo de la clase SecuenciaCaracteres.
El m�todo no modificar� la secuencia de caracteres sobre la que se aplica, sino que
construir� y devolver� una nueva secuencia.

*/

#include <iostream>
using namespace std;

string MensajeComienzo(){
   return "########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########\n\n### Jos� Javier Alonso Ramos\n### 1� de carrera\n### Grupo A1\n### Pr�ctica 13: Vectores\n### Ejercicio 4\n\n\n\n";
}

class SecuenciaCaracteres{
private:
	static const char TERMINADOR = '#';
   static const int TAMANIO = 100;
	char texto[TAMANIO];
	char descodificada[TAMANIO];
	int utilizados_texto;
   int utilizados_descodificada;
	
public:
	SecuenciaCaracteres()
		:utilizados_texto(0),utilizados_descodificada(0)
		{
		}
		
	void SetVectortexto(){
		char caracter;

		cout << "Cadena codificada."
       		<< "\nIntroduzca caracteres con terminador " << TERMINADOR << "\n";

	   utilizados_texto = 0;
	   caracter = cin.get();
	
	   while (caracter != TERMINADOR && utilizados_texto < TAMANIO){
	      texto[utilizados_texto] = caracter;
	      utilizados_texto++;
	      caracter = cin.get();
	   }
	}
	
	int GetUtilizados(){
		return utilizados_texto;
	}
	
	
	void DescodificaTexto(){
		
	   int i = 0, siguiente;
	   bool anterior_es_blanco = true;
	
	   while (i < utilizados_texto){
	      siguiente = i+1;
	
	      if (texto[i] != ' '){
	         if (anterior_es_blanco ||
	            (siguiente < utilizados_texto && texto[siguiente] == ' ')){
	               
	            descodificada[utilizados_descodificada] = texto[i];
	            utilizados_descodificada++;
	         }
	
	         anterior_es_blanco = false;
	      }
	      else
	         anterior_es_blanco = true;
	
	      i = siguiente;
	   }


		 cout << "\nCadena descodificada:\n" << "<";
   
	   for (int i = 0; i < utilizados_descodificada; i++)
	      cout << descodificada[i];
	
	   cout << ">";
   
   
	}
	
	char* GetVectorDescodifica(){
		return texto;			
	}
	
	int GetUtilizadosDescodifica(){
		return utilizados_descodificada;
	}
	
};
      
int main(){
   cout << MensajeComienzo();
   SecuenciaCaracteres texto_1;
   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:

   texto_1.SetVectortexto();

   //////////////////////////////////////////////////////////////////
   
   texto_1.DescodificaTexto();
   
   /////////////////////////////////////////////////////////////////////
}



