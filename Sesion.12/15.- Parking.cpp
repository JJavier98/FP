/*

########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########

### José Javier Alonso Ramos
### 1º de carrera
### Grupo A1
### Práctica 12: Vectores y matrices
### Ejercicio 15
### 

###########################################################

[Parking]

Recupere la solución del ejercicio 9 de la relación de problemas III (párking).
Re-escríbalo definiendo la clase TarifadorParking para calcular la tarifa.

La clase debe permitir cualquier número de tramos. Para ello, haga lo siguiente:

	 Defina dos vectores como datos miembro de la clase. En uno almacenaremos los
		límites de los tramos y en el otro la correspondiente tarifa.
	 Defina el siguiente método:
		void AniadeTramo(double limite_superior_tramo,
		double tarifa_tramo)
		Este método se llamará tantas veces como tramos tengamos.
	 Defina el método GetTarifa para calcular la tarifa según el número de minutos
		de un estacionamiento.
	 Cree dos objetos de la clase TarifadorParking (uno para cada parking) y
		modifique adecuadamente el programa principal para calcular las tarifas a partir
		de los métodos de los objetos.
		
Mantenga la definición de la función MinutosEntreInstantes para calcular los
minutos que hay entre dos instantes.

*/
#include <iostream>
#include <cmath>
#include <cctype>
using namespace std; 

string MensajeComienzo(){
   return "########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########\n\n### José Javier Alonso Ramos\n### 1º de carrera\n### Grupo A1\n### Práctica 12: Vectores y matrices\n### Ejercicio 13\n\n\n\n";
}

struct InstanteTiempo{
   int hora;
   int minuto;
   int segundo;
};

int MinutosEntreInstantes (InstanteTiempo inicial, InstanteTiempo final){
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

// Prec:
// límites positivos y en orden de menor a mayor
// tarifas todas reales positivos
// minutos_estacionamiento positivo
/*
   Nota:
   Otra posibilidad pasaría por comprobar las precondiciones dentro de la función
   y si no se satisfacen, devolveríamos -1
*/

class TarifadorParking{
private:
	static const int TAMANIO = 100;
	int tramos_usados = 0;
   int v_limites_tramos[TAMANIO];
   double v_tarifas[TAMANIO];
   double TARIFA_DIA_COMPLETO;
public:

	void AniadeTramo(double limite_superior_tramo, double tarifa_tramo){
		
		v_limites_tramos[tramos_usados] = limite_superior_tramo;
		v_tarifas[tramos_usados] = tarifa_tramo;
		
		tramos_usados++;
	}
   
   double GetTarifa(int minutos_estacionamiento){
      int tramo_maximo;
      double tarifa;
      bool tiempo_limite_rebasado;

      tiempo_limite_rebasado  = (minutos_estacionamiento > v_limites_tramos[tramos_usados]);
		
      for (int i = tramos_usados ; minutos_estacionamiento < v_limites_tramos[i] ; i--){
      	tramo_maximo = i;
		}
		
		if(tramo_maximo == 0){
			tarifa = minutos_estacionamiento * v_tarifas[0];
		}
		if(tiempo_limite_rebasado){
			tarifa = TARIFA_DIA_COMPLETO;
		}else 
			if(tramo_maximo > 0){
				tarifa = v_limites_tramos[0] * v_tarifas[0];
				
				for(int i = 1 ; i <= tramo_maximo ; i++){
					tarifa = tarifa + (v_limites_tramos[i] - v_limites_tramos[i - 1]) * v_tarifas[i];
				}
			}
      
      return tarifa;
   }
};


int main(){
	cout << MensajeComienzo();
	
	//////////////////////////////////////////////////////////////////
	// Variables
	
	const int TERMINADOR = -1;
	char menu = '#';
	int limite_1, limite_2, minutos_estacionamiento;
	double precio_1, precio_2, total_recaudado_parking_1 = 0, total_recaudado_parking_2 = 0, tarifa_parking_1, tarifa_parking_2;
	InstanteTiempo instante_inicial, instante_final;
	
	TarifadorParking parking_1, parking_2;
	
	while (menu != 'S'){
		
		cout << " ··· Señale el parking (1 / 2)\n";
		cout << " ··· Salir del programa (S)\n\n";
		cin >> menu;
		menu = toupper(menu);
	
		/////////// Introducción de datos
		while (menu == '1'){
		
			cout << " ··· Introducir tramos de tarifas (T)\n";
			cout << " ··· Salir del programa (S)\n\n";
			cin >> menu;
			menu = toupper(menu);
			
			while (menu == 'T'){
				
				while(limite_1 != -1 && precio_1 != -1){
					cout << "Cuando desee dejar de introducir tramos marque el terminador --> " << TERMINADOR << "\n\n";
					cout << "Indique el límite superior del tramo: ";
					cout << "Señale el precio de ese tramo: ";
					cin >> limite_1;
					cin >> precio_1;
					
					if (limite_1 != -1 && precio_1 != -1)
						parking_1.AniadeTramo(limite_1, precio_1);
				}
				menu = '#';
			}
		}
		while (menu == '2'){
		
			cout << " ··· Introducir tramos de tarifas (T)\n";
			cout << " ··· Salir del programa (S)\n\n";
			cin >> menu;
			menu = toupper(menu);
			
			while (menu == 'T'){
				
				while(limite_2 != -1 && precio_2 != -1){
					cout << "Cuando desee dejar de introducir tramos marque el terminador --> " << TERMINADOR << "\n\n";
					cout << "Indique el límite superior del tramo: ";
					cin >> limite_2;
					cout << "Señale el precio de ese tramo: ";
					cin >> precio_2;
					
					if (limite_2 != -1 && precio_2 != -1)
						parking_2.AniadeTramo(limite_2, precio_2);
				}
				menu = '#';
			}
		}
	}
	
	cout << "Indique el momento de entrada al parking (hora minuto segundo) o introduzca el TERMINADOR: ";
   cin >> instante_inicial.hora;
   
   while (instante_inicial.hora != TERMINADOR){
      cin >> instante_inicial.minuto;
      cin >> instante_inicial.segundo;

		cout << "Indique el momento de salida al parking (hora minuto segundo): ";
      cin >> instante_final.hora;
      cin >> instante_final.minuto;
      cin >> instante_final.segundo;

      minutos_estacionamiento =
         MinutosEntreInstantes(instante_inicial, instante_final);

      cout << "\nTarifa resultante con cada parking:\n" 
           << parking_1.GetTarifa(minutos_estacionamiento) << "\n" << parking_2.GetTarifa(minutos_estacionamiento) << "\n"; 
      
      tarifa_parking_1 = parking_1.GetTarifa(minutos_estacionamiento);
      tarifa_parking_2 = parking_2.GetTarifa(minutos_estacionamiento);
      
      total_recaudado_parking_1 = total_recaudado_parking_1 + tarifa_parking_1;
      total_recaudado_parking_2 = total_recaudado_parking_2 + tarifa_parking_2;
      
      cout << "Indique el momento de entrada al parking (hora minuto segundo) o introduzca el TERMINADOR: ";
      cin >> instante_inicial.hora;
   }
   
   cout << "\nTotal recaudado en cada parking:\n"
        << total_recaudado_parking_1 << "\n"
        << total_recaudado_parking_2 << "\n";
}
