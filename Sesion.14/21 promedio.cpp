#include <iostream>
using namespace std;


class SecuenciaReales{
private:
   static  const  int  TAMANIO  =  50;
   double  vector_privado[TAMANIO];
   int  total_utilizados;
public:
   SecuenciaReales()
      :total_utilizados(0)
   {
   }

   int  TotalUtilizados(){
      return  total_utilizados;
   }

   void  Aniade(double  nuevo){
      if (total_utilizados  <  TAMANIO){
         vector_privado[total_utilizados]  =  nuevo;
         total_utilizados++;
      }
   }

   double Elemento(int  indice){
      return  vector_privado[indice];
   }

   void Modifica(int indice_componente, double nuevo){
      if (indice_componente >= 0  &&  indice_componente < total_utilizados)
         vector_privado[indice_componente] = nuevo;
   }

   void EliminaTodos(){
      total_utilizados = 0;
   }

   int PrimeraOcurrenciaEntre(int pos_izda, int pos_dcha, double buscado){
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

   int PrimeraOcurrencia (double buscado){
      return PrimeraOcurrenciaEntre(0, total_utilizados - 1, buscado);
   }
   

   void Ordena_por_Insercion(){
      int izda, i;
      int a_desplazar;

      for (izda = 1; izda < total_utilizados; izda++){
         a_desplazar = vector_privado[izda];

         for (i = izda; i>0 && a_desplazar < vector_privado[i-1]; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[i] = a_desplazar;
      }
   }
};


/*
	Para obligar a que una matriz sea cuadrada,
   lo podemos hacer de varias formas. Por ejemplo:
   
	a) En el constructor de la matriz pasamos el número de columnas que
      tendrán todas las filas de la amtriz.
      
	b) En el constructor de la matriz pasamos una primera fila.
      La longitud actual de dicha fila será el valor que
      determine el número de columnas de todas las filas. 
      
	Para permitir ambas formas, sobrecargamos el constructor.
	
	En cualquier caso, es importante destacar que la matriz no
	estará en un estado válido hasta que se hayan añadido
	todas las filas, ya que es una matriz cuadrada.
	Para paliar este problema, añadimos un método EsCuadrada
	que nos dice si la matriz es cuadrada en un momento determinado.
*/

class TablaCuadradaReales{
private:
   static const int MAX_FILAS_COLUMNAS = 40;
   double matriz_privada[MAX_FILAS_COLUMNAS][MAX_FILAS_COLUMNAS];
   const int util_fil_col = 0;
   int indice_ultima_fila_aniadida = -1;
   
   void AsignaFila (SecuenciaReales fila, int indice_fila){
      for (int i=0; i < util_fil_col; i++)
         matriz_privada[indice_fila][i] = fila.Elemento(i);
   }
public:
   TablaCuadradaReales(SecuenciaReales primera_fila)
      :util_fil_col(primera_fila.TotalUtilizados())
   {
      AniadeFila(primera_fila);
      indice_ultima_fila_aniadida = 0;
   }

	TablaCuadradaReales(int numero_columnas)
      :util_fil_col(numero_columnas)
   {
   }
   
   double Elemento (int fil, int col){
      return matriz_privada[fil][col];
   }

   int NumeroFilas_y_Columnas(){
      return util_fil_col;
   }
   
   bool EsCuadrada(){
      return util_fil_col == indice_ultima_fila_aniadida + 1;
   }

   void AniadeFila(SecuenciaReales nueva_fila){
      if (indice_ultima_fila_aniadida < MAX_FILAS_COLUMNAS){
         if (nueva_fila.TotalUtilizados() == util_fil_col){
            indice_ultima_fila_aniadida++;
            AsignaFila(nueva_fila, indice_ultima_fila_aniadida);
         }
      }
   }
   
   SecuenciaReales Fila(int indice_fila){
      SecuenciaReales fila;
      
      for (int i=0; i < util_fil_col; i++){
         fila.Aniade(matriz_privada[indice_fila][i]);
      }
      return fila;
   }
   
   TablaCuadradaReales Promedio(){
      /*
         Algoritmo Matriz Promedio

         Recorrer todas las filas -i- de la matriz original
            Asignar el mismo elemento de la diagonal principal

            Recorrer las columnas -j- desde la última hasta i
               Ir acumulando en una variable suma
               el sumatorio de los m[i][j]
               Asignar media correspondiente a la componente ij y a la ji
      */

      /*
      Con una matriz tan pequeña como la siguiente no se aprovecha la
      eficiencia de este algoritmo. De hecho, obsérvese que sólo se aprovecha
      con una componente, la 01 -> (7+9)/3
      */
      /*
      9  7   4  5         9    (7+9)/3      (4+5)/2    5/1
      2  18  2  12        =    18           (2+12)/2   12/1
      7  9   1  5         =    =            1          5/1
      0  1   2  3         =    =            =          3
      */
      
      /*
      IMPORTANTE:
         Observad cómo accedemos directamente al dato miembro privado
         del objeto suavizada. Esto es posible ya que está dentro
         de un método de la misma clase.
      */
      double suma;
      TablaCuadradaReales tabla(util_fil_col);
		
		for (int i = 0; i < util_fil_col; i++){
         tabla.matriz_privada[i][i] = matriz_privada[i][i];
         suma = 0;
         
         for (int j = util_fil_col - 1 ; j > i; j--){
            suma           = suma + matriz_privada[i][j];
            tabla.matriz_privada[i][j] = suma / (util_fil_col - j);
            tabla.matriz_privada[j][i] = tabla.matriz_privada[i][j];
         }
      }
      return tabla;
   }
};


int main(){
   int util_filas_original, util_filas_promedio;
   double valor;
   SecuenciaReales fila;

   // No etiquetamos las entradas porque suponemos que leemos de un fichero
   // Supondremos que util_filas > 0

   cin >> util_filas_original;
   
   TablaCuadradaReales tabla(util_filas_original);

   for (int i = 0; i < util_filas_original; i++){
      for (int j = 0; j < util_filas_original; j++){
         cin >> valor;
         fila.Aniade(valor);
      }
      
      tabla.AniadeFila(fila);
      fila.EliminaTodos();
   }

   if (tabla.EsCuadrada()){
      TablaCuadradaReales promedio(tabla.Promedio());  // Constructor de copia
      
      util_filas_promedio = promedio.NumeroFilas_y_Columnas();
   
      cout << "\n\n";
      cout << "Matriz promedio:\n";

      for (int i = 0; i < util_filas_promedio; i++){
         cout << "\n";

         for (int j = 0; j < util_filas_promedio; j++)
            cout << promedio.Elemento(i,j) << '\t';
      }
   }
  

   // Entrada:
   // 4   9 7 4 5    2 18 2 12    7 9 1 5   0 1 2 3
   
   // Salida:
   /*
   9       5.33333 4.5     5
   5.33333 18      7       12
   4.5     7       1       5
   5       12      5       3
   */
}
