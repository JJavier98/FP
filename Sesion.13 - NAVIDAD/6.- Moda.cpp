/*

########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########

### Jos� Javier Alonso Ramos
### 1� de carrera
### Grupo A1
### Pr�ctica 13: Vectores
### Ejercicio 6
### 

###########################################################

[Moda vs 2]

Recupere la soluci�n del ejercicio 5 (Moda) Elimine el m�todo
NumeroOcurrencias y en su lugar defina el m�todo

	SecuenciaEnteros PosicionesOcurrencias
		(char buscado, int izda, int dcha)
		
que devuelve las posiciones en las que se encuentra el elemento buscado. Para ello,
tendr� que usar la clase SecuenciaEnteros, an�loga a SecuenciaCaracteres,
cuya definici�n puede encontrarse en:

http://decsai.ugr.es/~carlos/FP/SecuenciaEnteros.cpp

Cambie la implementaci�n del m�todo Moda del ejercicio 5 para que use este nuevo
m�todo.

*/

#include <iostream>
using namespace std;

string MensajeComienzo(){
   return "########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########\n\n### Jos� Javier Alonso Ramos\n### 1� de carrera\n### Grupo A1\n### Pr�ctica 13: Vectores\n### Ejercicio 6\n\n\n\n";
}

struct FrecuenciaCaracter{
   char caracter;
   int frecuencia;
   int posicion;
};

class SecuenciaEnteros{
private:
   static const int TAMANIO = 50;
   long vector_privado[TAMANIO];
   int total_utilizados;
   
   void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
      long intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }
public:
   SecuenciaEnteros()
      :total_utilizados(0) {
   }
   
   int TotalUtilizados(){
      return total_utilizados;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void EliminaTodos(){
      total_utilizados = 0;
   }
   
   void Aniade(long nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   
   void Modifica(int posicion, long nuevo){
      if (posicion >= 0 && posicion < total_utilizados)
         vector_privado[posicion] = nuevo;
   }

   long Elemento(int indice){
      return vector_privado[indice];
   }
   
   string ToString(){
      // Si el n�mero de caracteres en memoria es muy grande,
      // es mucho m�s eficiente reservar memoria previamente
      // y usar push_back

      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++){
         cadena.append(to_string(vector_privado[i]));
         cadena.append(" ");
         //cadena = cadena + to_string(vector_privado[i])  <- Evitarlo. Muy ineficiente para tama�os grandes;
      }
      
      return cadena;
   }

   int PrimeraOcurrenciaEntre (int pos_izda, int pos_dcha, long buscado){
      int i = pos_izda;
      bool encontrado = false;

      while (i <= pos_dcha  &&  !encontrado)
         if (vector_privado[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }
   
   int PrimeraOcurrencia (long buscado){
      return PrimeraOcurrenciaEntre (0, total_utilizados - 1, buscado);
   }
   

   /////////////////////////////////////////////////////////////
   // B�squedas
   
   // Precond: 0 <= izda <= dcha < total_utilizados
   int PosicionMinimoEntre(int izda, int dcha){
      int posicion_minimo = -1;
      long minimo;

      minimo = vector_privado[izda];
      posicion_minimo = izda;

      for (int i = izda+1 ; i <= dcha ; i++)
         if (vector_privado[i] < minimo){
            minimo = vector_privado[i];
            posicion_minimo = i;
         }

      return posicion_minimo;
   }
   
   int PosicionMinimo(){
      return PosicionMinimoEntre(0, total_utilizados - 1);
   }
   
   int BusquedaBinaria (long buscado){
      int izda, dcha, centro;
      bool encontrado = false;

      izda = 0;
      dcha = total_utilizados - 1;
      centro = (izda + dcha) / 2;

      while (izda <= dcha  &&  !encontrado){
         if (vector_privado[centro] == buscado)
            encontrado = true;
         else if (buscado < vector_privado[centro])
            dcha = centro - 1;
         else
            izda = centro + 1;

         centro = (izda + dcha) / 2;
      }

      if (encontrado)
         return centro;
      else
         return -1;
   }
   
   
   /////////////////////////////////////////////////////////////
   // Recorridos que modifican las componentes
   
   // Inserta un valor en la posici�n especificada
   void Inserta(int pos_insercion, long valor_nuevo){
      if (total_utilizados < TAMANIO  &&  pos_insercion >= 0    
         &&  pos_insercion <= total_utilizados){

         for (int i = total_utilizados ; i > pos_insercion ; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[pos_insercion] = valor_nuevo;
         total_utilizados++;
      }
   }
   
   // Elimina una componente, dada por su posici�n
   void Elimina (int posicion){
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados-1;

         for (int i = posicion ; i < tope ; i++)
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;
      }
   }
   
   
   /////////////////////////////////////////////////////////////
   // Algoritmos de ordenaci�n
   
   void Ordena_por_Seleccion(){
      int pos_min;

      for (int izda = 0 ; izda < total_utilizados ; izda++){
         pos_min = PosicionMinimoEntre(izda, total_utilizados - 1);
         IntercambiaComponentes_en_Posiciones(izda, pos_min);
      }
   }
   
   void Ordena_por_Insercion(){
      int izda, i;
      long a_desplazar;

      for (izda=1; izda < total_utilizados; izda++){
         a_desplazar = vector_privado[izda];

         for (i=izda; i > 0 && a_desplazar < vector_privado[i-1]; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[i] = a_desplazar;
      }
   }
   
   void Ordena_por_Burbuja(){
      int izda, i;

      for (izda = 0; izda < total_utilizados; izda++)
        for (i = total_utilizados-1 ; i > izda ; i--)
          if (vector_privado[i] < vector_privado[i-1])
             IntercambiaComponentes_en_Posiciones(i, i-1);
   }
   
   void Ordena_por_BurbujaMejorado(){
      int izda, i;
      bool cambio;

      cambio= true;

      for (izda=0; izda < total_utilizados && cambio; izda++){
        cambio=false;

        for (i=total_utilizados-1 ; i>izda ; i--)
          if (vector_privado[i] < vector_privado[i-1]){
             IntercambiaComponentes_en_Posiciones(i, i-1);
             cambio=true;
          }
      }
   }
   
   void AniadeVarios(SecuenciaEnteros nuevos){
      int totales_a_aniadir = nuevos.TotalUtilizados();
      
      for (int i = 0; i < totales_a_aniadir; i++)
         Aniade(nuevos.Elemento(i)); // Es importante entender
   }


   // Busca una sub-secuencia
   // Las posiciones deben estar en orden y consecutivas
   int PosicionContiene (SecuenciaEnteros a_buscar){
      int  inicio;
      int  ultima_componente;
      bool encontrado;
      int  posicion_contiene;
      bool va_coincidiendo;
      int  utilizados_a_buscar;

      /*
      Tenemos una secuencia "grande" de tama�o G y otra peque�a de tama�o P

      Recorrer la secuencia "grande" fijando una posici�n inicial inicio
      La �ltima posici�n inicial a probar ser� G-P
         A partir de inicio recorrer en paralelo las
         dos secuencias "grande" y "peque�a"
         Si no coinciden todas las componentes, hay que
         empezar de nuevo a partir de inicio + 1.
      */

      utilizados_a_buscar = a_buscar.TotalUtilizados();

      if (utilizados_a_buscar > 0){
         ultima_componente = total_utilizados - utilizados_a_buscar;
         encontrado = false;

         for (inicio = 0; inicio <= ultima_componente && !encontrado; inicio++){
            va_coincidiendo = true;

            for (int i = 0; i < utilizados_a_buscar && va_coincidiendo; i++)
               va_coincidiendo = vector_privado[inicio + i] == a_buscar.Elemento(i);

            if (va_coincidiendo){
               posicion_contiene = inicio;
               encontrado = true;
            }
         }
      }
      else
         encontrado = false;

      if (encontrado)
         return posicion_contiene;
      else
         return -1;
   /*
   Bater�a de pruebas:
      Los dos vectores vac�os.
      Alguno de ellos vac�o.
      Los dos vectores iguales.  atti / atti
      Que no se encuentre.   atti / tj
      Que se encuentre al principio.  atti / at
      Que se encuentre justo al final. atti / ti
      Que haya un emparejamiento parcial pero no total,
      aunque luego s� se encuentre.  atttij / ti
   */
   }
};



class LectorSecuenciaEnteros{
private:
   long terminador;
public:
   LectorSecuenciaEnteros(long entero_terminador)
      :terminador(entero_terminador)
   {
   }
   SecuenciaEnteros Lee(){
      SecuenciaEnteros a_leer;
      int total_introducidos;  // Esta variable es para contar los introducidos
                               // y que no nos pasemos de la capacidad de la secuencia.
      int capacidad_secuencia;
      long entero;

      total_introducidos = 0;
      capacidad_secuencia = a_leer.Capacidad();
      cin >> entero;

      while (entero != terminador && total_introducidos < capacidad_secuencia){
         a_leer.Aniade(entero);
         total_introducidos++;
         cin >> entero;
      }

      return a_leer;
   }
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

		cout << "Introduzca la serie de caracteres.\n --> ";
		while (dato != TERMINADOR ){
	   	if ( dato != ' ' ){
	   		v_caracteres[utilizados_caracteres] = dato;
	   		utilizados_caracteres++;
	   	}
	   	
	      dato = cin.get();
	   }
	}
	
	SecuenciaEnteros PosicionesOcurrencias(char caracter, int izda, int dcha){
		SecuenciaEnteros sec_enteros;
		
		for ( int i = izda ; i <= dcha && i <= utilizados_caracteres ; i++){
	   	if (v_caracteres[i] == caracter){
	   		sec_enteros.Aniade(i);
			}
		}
		return sec_enteros;
	}
	
	FrecuenciaCaracter Moda(){
		FrecuenciaCaracter modelo;
		SecuenciaEnteros pos_ocurencias;

		for (int i = 0 ; i < utilizados_caracteres ; i++){
	   	pos_ocurencias = PosicionesOcurrencias(v_caracteres[i], 0, utilizados_caracteres);
	   	
	   	if (pos_ocurencias.TotalUtilizados() > modelo.frecuencia || i == 0){
	   		modelo.caracter = v_caracteres[i];
	   		modelo.frecuencia = pos_ocurencias.TotalUtilizados();
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
