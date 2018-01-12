/*
a) Definición de la clase y creación de objetos
Defina la clase Recta. En este apartado utilice únicamente datos miembro públicos.
Cree un programa principal que haga lo siguiente:
 Defina dos objetos de la clase Recta.
 Lea seis reales desde teclado.
 Le asigne los tres primeros a los coeficientes de una recta y los otros tres a
la segunda recta.
 Calcule e imprima la pendiente de cada recta aplicando la fórmula:
pendiente = - A / B
*/

#include <iostream>
using namespace std;

// Clases
class Recta{
public:
	double A,
			 B,
			 C;

	double Pendiente (){
		return -A / B;
	}
};

// Función principal
int main(){
	
	// Variables
	double valorA1,
		 	 valorB1,
		 	 valorC1,
		 	 valorA2,
			 valorB2,
		 	 valorC2,
		 	 pendiente_1,
		 	 pendiente_2;
	string msj_A1 = "RECTA 1::: Introduzca un coeficiente entero para A.\n Coeficiente A: ",
			 msj_B1 = "RECTA 1::: Introduzca un coeficiente entero para B.\n Coeficiente B: ",
			 msj_C1 = "RECTA 1::: Introduzca un coeficiente entero para C.\n Coeficiente C: ",
			 msj_A2 = "\n\nRECTA 2::: Introduzca un coeficiente entero para A.\n Coeficiente A: ",
			 msj_B2 = "RECTA 2::: Introduzca un coeficiente entero para B.\n Coeficiente B: ",
			 msj_C2 = "RECTA 2::: Introduzca un coeficiente entero para C.\n Coeficiente C: ",
			 msj_pendiente_1 = "\n\nLa pendiente de la recta 1 es: ",
			 msj_pendiente_2 = "\nLa pendiente de la recta 2 es: ";

	// Objetos
	Recta recta_1;
	Recta recta_2;

	// E/S
	cout << msj_A1;
	cin >> valorA1;
	cout << msj_B1;
	cin >> valorB1;
	cout << msj_C1;
	cin >> valorC1;

	cout << msj_A2;
	cin >> valorA2;
	cout << msj_B2;
	cin >> valorB2;
	cout << msj_C2;
	cin >> valorC2;

	// Asignaciones
	recta_1.A = valorA1;
	recta_1.B = valorB1;
	recta_1.C = valorC1;

	recta_2.A = valorA2;
	recta_2.B = valorB2;
	recta_2.C = valorC2;

	// Cómputos
	pendiente_1 = recta_1.Pendiente();
	pendiente_2 = recta_2.Pendiente();

	// Resultados
	cout << msj_pendiente_1 << pendiente_1;
	cout << msj_pendiente_2 << pendiente_2;
}
