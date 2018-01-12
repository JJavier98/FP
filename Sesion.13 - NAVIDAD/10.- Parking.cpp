//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Parking con vectores dentro de una clase

/*
Recupere la solución del ejercicio 9 de la relación de problemas III (párking). Re-
escríbalo definiendo la clase TarifadorParking para calcular la tarifa.
La clase debe permitir cualquier número de tramos. Para ello, haga lo siguiente:

• Defina dos vectores como datos miembro de la clase. En uno almacenaremos los
límites de los tramos y en el otro la correspondiente tarifa.

• Defina el siguiente método:

void AniadeTramo(double limite_superior_tramo,
                 double tarifa_tramo)
                 
Este método se llamará tantas veces como tramos tengamos.

• Defina el método GetTarifa para calcular la tarifa según el número de minutos
de un estacionamiento.

• Cree dos objetos de la clase TarifadorParking (uno para cada parking) y
modifique adecuadamente el programa principal para calcular las tarifas a partir
de los métodos de los objetos.

Mantenga la definición de la función MinutosEntreInstantes para calcular los
minutos que hay entre dos instantes.
*/

/*
Ejemplo de entrada:

4  30 0.0412  90 0.0370  120 0.0311  660 0.0305 31.55
4  35 0.0402  85 0.0375  110 0.0319  660 0.0315 32
2 1 30 4 2 50
2 1 30 3 41 31
2 1 30 5 41 31
2 1 30 23 1 1 -1

-- Salida correcta:

4.4195 4.4262
3.767 3.7605
7.439 7.5445
31.55 32
47.1755
47.731
*/

#include <iostream>  
#include <cmath>
using namespace std; 

struct InstanteTiempo{
   int hora;
   int minuto;
   int segundo;
};

class Instante{
	private:
		InstanteTiempo inicial, final;
	public:
		int MinutosEntreInstantes (){
		   const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60;
		   int segundos_iniciales, segundos_finales, segundos_diferencia;
		   
		   segundos_iniciales = SEGUNDOS_POR_MINUTO * (inicial.hora * MINUTOS_POR_HORA   +
		                                               inicial.minuto) +
		                        inicial.segundo;
		
		   segundos_finales   = SEGUNDOS_POR_MINUTO * (final.hora * MINUTOS_POR_HORA   +
		                                               final.minuto) +
		                       final.segundo;
		
		   segundos_diferencia = abs(segundos_finales - segundos_iniciales);
		
		   return segundos_diferencia / SEGUNDOS_POR_MINUTO;
		}
		
	void SetTiempoInicial(InstanteTiempo principio){
		inicial = principio;
	}
	
	void SetTiempoFinal(InstanteTiempo final){
		final = final;
	}
};



class TarifadorParking{
private:
   static const int MAXIMO_NUM_TRAMOS = 20;
   int    limite_tramo[MAXIMO_NUM_TRAMOS];    // Será de la forma [30, 60, 120, 660, ...]
   double tarifa_por_tramo[MAXIMO_NUM_TRAMOS];
   double TARIFA_DIA_COMPLETO;
   int    num_tramos = 0;
public:
   TarifadorParking(){
      for (int i = 0; i < MAXIMO_NUM_TRAMOS; i++){
         limite_tramo[i] = 0;
         tarifa_por_tramo[i] = NAN;
      }
   }
   
   void SetTarifaDiaCompleto(double tarifa_de_dia_completo){
      TARIFA_DIA_COMPLETO = tarifa_de_dia_completo;
   }
   void AniadeTramo(double limite_superior_tramo, double tarifa_tramo){
      if (num_tramos < MAXIMO_NUM_TRAMOS){
         limite_tramo[num_tramos] = limite_superior_tramo;
         tarifa_por_tramo[num_tramos] = tarifa_tramo;
         num_tramos++;
      }
   }
   
   int NumeroTramos(){
      return num_tramos;
   }
   
   int CapacidadTramos(){
      return MAXIMO_NUM_TRAMOS;
   }
   
   // Normalmente añadiríamos métodos para ver el valor de los tramos
   double GetTarifa(int minutos_estacionamiento){
      /*
      Calculamos los minutos a tarifar de cada tramo.
      Por ejemplo, si los límites de los tramos son:
      30 90 120 660
      Y tenemos 115 minutos a tarifar, los minutos por tramo serán:
      30 60 25 0
      Una vez calculados los minutos de cada tramo, basta con
      multiplicar por la tarifa de cada tramo y sumar.
      */
      int minutos_a_tarifar_por_tramo[MAXIMO_NUM_TRAMOS] = {0};
      double tarifa;
      bool tiempo_limite_rebasado;

      tiempo_limite_rebasado  = (minutos_estacionamiento > limite_tramo[num_tramos-1]);
   
      if (!tiempo_limite_rebasado){
         double limite_anterior = 0;
         bool seguir = true;
         
         for (int i = 0; i < num_tramos && seguir; i++){
            if (minutos_estacionamiento < limite_tramo[i]){
               minutos_a_tarifar_por_tramo[i] = minutos_estacionamiento 
                                                - 
                                                limite_anterior ;
               seguir = false;   // <- IMPORTANTE
            }
            else
               minutos_a_tarifar_por_tramo[i] = limite_tramo[i] 
                                                - 
                                                limite_anterior;
                                                
            limite_anterior = limite_tramo[i];
         }
      }
   
      if (tiempo_limite_rebasado)
         tarifa = TARIFA_DIA_COMPLETO;
      else{
         tarifa = 0.0;
         
         for (int i = 0; i < num_tramos; i++){
            tarifa = tarifa + minutos_a_tarifar_por_tramo[i] 
                              * 
                              tarifa_por_tramo[i];
         }
      }
   
      return tarifa;      
      
      /*
      Ampliación.
         En vez de calcular el número de minutos de cada tramo
         (que sería cero, para todos aquellos tramos 
         a los que no se ha llegado)
         podríamos haber calculado el número de tramos a los
         que se ha llegado y luego aplicar la tarifa correspondiente.
         Por ejemplo, si son 115 minutos a tarifar, en vez de
         calcular el vector
            30 60 25 0
         podríamos haber calculado que se tarifan 2 tramos completos
         (los dos primeros) y 25 minutos (del tercero)
      */
   }
};


int main(){   
   const int TERMINADOR_ENTRADA_DATOS = -1;
   int limite_tramo;
   double tarifa_tramo;
   double tarifa_dia_completo;
   double tarifa_parking_1, tarifa_parking_2;
   double total_recaudado_parking_1, total_recaudado_parking_2;
   int numero_tramos;
   
   InstanteTiempo instante_inicial, instante_final;  
   int minutos_estacionamiento;
   
   TarifadorParking tarifador_parking_1;
   TarifadorParking tarifador_parking_2;
   
   
   cout << "Parking1.\n\n";

	cout << "Introduce num tramos: ";
   cin >> numero_tramos;
   

   
   for (int i = 0; i < numero_tramos; i++) {
   	cout << "Señala limite del tramo y su tarifa: ";
      cin >> limite_tramo;
      cin >> tarifa_tramo;
      tarifador_parking_1.AniadeTramo(limite_tramo, tarifa_tramo);
   }
   cout << "Indica la tarifa dia completo: ";
   cin >> tarifa_dia_completo;
   
   tarifador_parking_1.SetTarifaDiaCompleto(tarifa_dia_completo);
   
   ///////////////////////////////////////////////////
   
   cout << "Parking2.\n\n";
   
   cout << "Introduce num tramos: ";
   cin >> numero_tramos;
   
   for (int i = 0; i < numero_tramos; i++) {
   	cout << "Señala limite del tramo y su tarifa: ";
      cin >> limite_tramo;
      cin >> tarifa_tramo;
      tarifador_parking_2.AniadeTramo(limite_tramo, tarifa_tramo);
   }
   cout << "Indica la tarifa dia completo: ";
   cin >> tarifa_dia_completo;
   
   tarifador_parking_2.SetTarifaDiaCompleto(tarifa_dia_completo);
   
   ///////////////////////////////////////////////////

	Instante instante;
 
   total_recaudado_parking_1 = 0.0; 
   total_recaudado_parking_2 = 0.0; 

	cout << "Señala el instante inicial: ";
   cin >> instante_inicial.hora;
   
   while (instante_inicial.hora != TERMINADOR_ENTRADA_DATOS){     
      cin >> instante_inicial.minuto;
      cin >> instante_inicial.segundo;
      
      instante.SetTiempoInicial(instante_inicial);
   
   	cout << "Señala el instante final: ";
      cin >> instante_final.hora;
      cin >> instante_final.minuto;
      cin >> instante_final.segundo;
      
      instante.SetTiempoFinal(instante_final);
      
      minutos_estacionamiento = instante.MinutosEntreInstantes();
      
      tarifa_parking_1 = tarifador_parking_1.GetTarifa(minutos_estacionamiento);
      tarifa_parking_2 = tarifador_parking_2.GetTarifa(minutos_estacionamiento);
                                   
                                
      cout << "\nTarifa resultante con cada parking:\n" 
        << tarifa_parking_1 << "\n" << tarifa_parking_2 << "\n";  
      
      total_recaudado_parking_1 = total_recaudado_parking_1 + tarifa_parking_1;
      total_recaudado_parking_2 = total_recaudado_parking_2 + tarifa_parking_2;
      
      cout << "Señala el instante inicial: ";
      cin >> instante_inicial.hora;
   }
   
   cout << "\nTotal recaudado en cada parking:\n"
        << total_recaudado_parking_1 << "\n"
        << total_recaudado_parking_2 << "\n";

}



