/*
a) Definici�n de la clase y creaci�n de objetos
Defina la clase Recta. En este apartado utilice �nicamente datos miembro p�blicos.
Cree un programa principal que haga lo siguiente:
 Defina dos objetos de la clase Recta.
 Lea seis reales desde teclado.
 Le asigne los tres primeros a los coeficientes de una recta y los otros tres a
la segunda recta.
 Calcule e imprima la pendiente de cada recta aplicando la f�rmula:
pendiente = - A / B

b) M�todos p�blicos
En vez de calcular la pendiente en el programa principal, vamos a ponerlo como
un m�todo de la clase y as� lo reutilizaremos todas las veces que necesitemos.
A�ada un m�todo para el c�lculo de la pendiente y modifique el main para tener
en cuenta este cambio.
�A�adimos pendiente como dato miembro de la recta? La respuesta es que
no �Por qu�?
A�ada tambi�n los siguiente m�todos:
 Obtener la ordenada (y) dado un valor de abscisa x, aplicando la f�rmula:
(-C -xA) / B
 Obtener la abscisa (x) dado un valor de ordenada y, aplicando la f�rmula:
(-C -yB) / A
En la funci�n main lea un valor de abscisa e imprima la ordenada seg�n la recta.
A continuaci�n lea un valor de ordenada e imprima la abscisa que le corresponde.
H�galo s�lo con la primera recta.
*/


#include <iostream>
using namespace std;

// Clases
class Recta{
public:
	double A,
		 	 B,
			 C,
			 x,
			 y;

	double CalculaPendiente(){ // NO A�ADIMOS Pendiente COMO DATO MIEMBRO PORQUE SE TRATA DE UN M�TODO, Y ES �STE QUI�N ACT�A SOBRE LOS DATOS MIEMBROS.
		return -A / B;
	}
	double ObtieneOrdenada(double x){
		return (-C - x * A) / B;
	}
	double ObtieneAbscisa(double y){
		return (-C - y * B) / A;
	}
};

// Funci�n principal
int main(){
	
	// Variables
	double valorA1,
		 	 valorB1,
		 	 valorC1,
		 	 valorA2,
			 valorB2,
		 	 valorC2,
		 	 pendiente_1,
		 	 pendiente_2,
		 	 ordenada_1,
		 	 abscisa_1,
		 	 x,
		 	 y;
	string msj_A1 = "RECTA 1::: Introduzca un coeficiente entero para A.\n Coeficiente A: ",
			 msj_B1 = "RECTA 1::: Introduzca un coeficiente entero para B.\n Coeficiente B: ",
			 msj_C1 = "RECTA 1::: Introduzca un coeficiente entero para C.\n Coeficiente C: ",
			 msj_A2 = "\n\nRECTA 2::: Introduzca un coeficiente entero para A.\n Coeficiente A: ",
			 msj_B2 = "RECTA 2::: Introduzca un coeficiente entero para B.\n Coeficiente B: ",
			 msj_C2 = "RECTA 2::: Introduzca un coeficiente entero para C.\n Coeficiente C: ",
			 msj_pendiente_1 = "\n\nLa pendiente de la recta 1 es: ",
			 msj_pendiente_2 = "\nLa pendiente de la recta 2 es: ",
			 msj_ordenada_1 =  "\n\nSe�ale un valor de X para calcular un valor de Y en la RECTA 1.\n X: ",
			 msj_abscisa_1 = "Se�ale un valor de Y para calcular un valor de X en la RECTA 1.\n Y: ",
			 msj_resultado_ordn_1 = "\n\nEl valor de la ordenada en la RECTA 1 con el valor de abscisa dado es: ",
			 msj_resultado_abs_1 = "\nEl valor de la abscisa en la RECTA 1 con el valor de ordenada dado es: ";

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

	cout << msj_ordenada_1;
	cin >> x;
	cout << msj_abscisa_1;
	cin >> y;

	// Asignaciones
	recta_1.A = valorA1;
	recta_1.B = valorB1;
	recta_1.C = valorC1;

	recta_2.A = valorA2;
	recta_2.B = valorB2;
	recta_2.C = valorC2;

	// C�mputos
	ordenada_1 = recta_1.ObtieneOrdenada(x);
	abscisa_1 = recta_1.ObtieneAbscisa(y);
	pendiente_1 = recta_1.CalculaPendiente();
	pendiente_2 = recta_2.CalculaPendiente();

	// Resultados
	cout << "\n\nRecta 1 --> " << valorA1 << "x + " << valorB1 << "y + " << valorC1;
	cout << "\nRecta 2 --> " << valorA2 << "x + " << valorB2 << "y + " << valorC2;
	cout << msj_resultado_ordn_1 << ordenada_1;
	cout << msj_resultado_abs_1 << abscisa_1;
	cout << msj_pendiente_1 << pendiente_1;
	cout << msj_pendiente_2 << pendiente_2;
}
