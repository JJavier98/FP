#include <iostream>
using namespace std;

class SecuenciaCaracteres{
private:
   static const int TAMANIO = 50;
   char vector_privado[TAMANIO];
   int total_utilizados;

   void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
      char intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }
public:
   SecuenciaCaracteres()
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

   void Aniade(char nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }

   void Modifica(int posicion, char nuevo){
      if (posicion >= 0 && posicion < total_utilizados)
         vector_privado[posicion] = nuevo;
   }

   char Elemento(int indice){
      return vector_privado[indice];
   }

   string ToString(){
      // Si el número de caracteres en memoria es muy grande,
      // es mucho más eficiente reservar memoria previamente
      // y usar push_back

      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++)
         cadena.push_back(vector_privado[i]);
         //cadena = cadena + vector_privado[i]  <- Evitarlo. Muy ineficiente para tamaños grandes;

      return cadena;
   }


   int PrimeraOcurrenciaEntre (int pos_izda, int pos_dcha, char buscado){
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

   int PrimeraOcurrencia (char buscado){
      return PrimeraOcurrenciaEntre (0, total_utilizados - 1, buscado);
   }


   /////////////////////////////////////////////////////////////
   // Búsquedas

   // Precond: 0 <= izda <= dcha < total_utilizados
   int PosicionMinimoEntre(int izda, int dcha){
      int posicion_minimo = -1;
      char minimo;

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

   int BusquedaBinaria (char buscado){
      int izda, dcha, centro;
      bool encontrado = false;

      izda = 0;
      dcha = total_utilizados - 1;

      while (izda <= dcha  &&  !encontrado){
         centro = (izda + dcha) / 2;

         if (vector_privado[centro] == buscado)
            encontrado = true;
         else if (buscado < vector_privado[centro])
            dcha = centro - 1;
         else
            izda = centro + 1;
      }

      if (encontrado)
         return centro;
      else
         return -1;
   }


   /////////////////////////////////////////////////////////////
   // Recorridos que modifican las componentes

   // Inserta un valor en la posición especificada
   void Inserta(int pos_insercion, char valor_nuevo){
      if (total_utilizados < TAMANIO  &&  pos_insercion >= 0
         &&  pos_insercion <= total_utilizados){

         for (int i = total_utilizados ; i > pos_insercion ; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[pos_insercion] = valor_nuevo;
         total_utilizados++;
      }
   }

   // Elimina una componente, dada por su posición
   void Elimina (int posicion){
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados-1;

         for (int i = posicion ; i < tope ; i++)
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;
      }
   }


   /////////////////////////////////////////////////////////////
   // Algoritmos de ordenación

   void Ordena_por_Seleccion(){
      int pos_min;

      for (int izda = 0 ; izda < total_utilizados ; izda++){
         pos_min = PosicionMinimoEntre(izda, total_utilizados - 1);
         IntercambiaComponentes_en_Posiciones(izda, pos_min);
      }
   }

   void Ordena_por_Insercion(){
      int izda, i;
      char a_desplazar;

      for (izda=1; izda < total_utilizados; izda++){
         a_desplazar = vector_privado[izda];

         for (i=izda; i > 0 && a_desplazar < vector_privado[i-1]; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[i] = a_desplazar;
      }
   }
};

class Texto{
private:
	static const int MAX_FIL_COL = 50;
	char matriz_privada[MAX_FIL_COL][MAX_FIL_COL];
	int util_fil,
		 col_util_por_fila[MAX_FIL_COL];
		 
	void RemplazaFila(int fila_a_borrar, int fila_origen){
		int columnas_utilizadas = col_util_por_fila[fila_origen];
		
		for(int i = 0 ; i < columnas_utilizadas ; i++){
			matriz_privada[fila_a_borrar][i] = matriz_privada[fila_origen][i];
		}
		
		col_util_por_fila[fila_a_borrar] = columnas_utilizadas;
	 
public:
	Texto()
		:util_fil(0)
		{
			for (int i = 0; i < MAX_FIL_COL ; i++){
				col_util_por_fila[i] = 0;
			}
		}
	
	int CapacidadFilas(){
		return MAX_FIL_COL;
	}
	
	int CapacidadcOLUMNAS(){
		return MAX_FIL_COL;
	}
	
	int FilasUtilizadas(){
		return util_fil;
	}
	
	int ColumnasUtilizadas(int numero_fila){
		numero_fila = numero_fila - 1; // Consideramos que el usuario
												 // considera la primera fila
												 // como numero 1 y no como numero 0.
		return col_util_por_fila[numero_fila];;		
	}
	
	char Elemento(int fila, int columna){
		return matriz_privada[fila][columna];
	}
	
	SecuenciaCaracteres Fila(int fila){
		SecuenciaCaracteres fila_to_string;
		
		for (int i = 0 ; i < col_util_por_fila[fila] ; i++){
			fila_to_string.vector_privado[i] = matriz_privada[fila][i];
		}
	}
};
