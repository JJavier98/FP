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

b) Métodos públicos
En vez de calcular la pendiente en el programa principal, vamos a ponerlo como
un método de la clase y así lo reutilizaremos todas las veces que necesitemos.
Añada un método para el cálculo de la pendiente y modifique el main para tener
en cuenta este cambio.
¿Añadimos pendiente como dato miembro de la recta? La respuesta es que
no ¿Por qué?
Añada también los siguiente métodos:
 Obtener la ordenada (y) dado un valor de abscisa x, aplicando la fórmula:
(-C -xA) / B
 Obtener la abscisa (x) dado un valor de ordenada y, aplicando la fórmula:
(-C -yB) / A
En la función main lea un valor de abscisa e imprima la ordenada según la recta.
A continuación lea un valor de ordenada e imprima la abscisa que le corresponde.
Hágalo sólo con la primera recta.

c) Datos miembro privados
Cambie ahora los datos miembro públicos y póngalos privados. Tendrá que añadir
métodos para asignar y ver los valores de los datos miembro. Añada métodos
para asignar un valor a cada uno de los tres datos miembro. Modifique el main
para tener en cuenta estos cambios.

d) Política de acceso a los datos miembros
En vez de usar un método para asignar un valor a cada dato miembro, defina un
único método SetCoeficientes para asignar los tres a la misma vez.
Observe que los métodos permiten definir la política de acceso a los datos miembro.
Si tengo previsto cambiar por separado los coeficientes de la recta, usaré
métodos de asignación individuales. En caso contrario, usaré un único método
que modifique a la misma vez todos los datos miembro. Incluso pueden dejarse
en la clase ambos tipos de métodos para que así el cliente de la clase pueda usar
los que estime oportunos en cada momento. Por ahora, mantenga únicamente el
método de asignación en bloque SetCoeficientes.

e) Constructor
Modifique el programa principal del último apartado e imprima los valores de los
datos miembros de una recta, antes de asignarles los coeficientes. Mostrará, obviamente,
un valor indeterminado. Para evitar este problema, añada un constructor
a la recta para que el objeto esté en un estado válido en el mismo momento
de su definición. El constructor deberá tener como parámetros, obligatoriamente,
los tres coeficientes de la recta. Tendrá que modificar convenientemente el main
para tener en cuenta este cambio.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Clases
class Recta{
private:
	double A,
		 	 B,
			 C,
			 x,
			 y;
public:
	Recta(double A_ini, double B_ini, double C_ini){
		SetCoeficientesIniciales(A_ini, B_ini, C_ini);
	}
	void SetCoeficientesRecta2(double valorA2,
										double valorB2,
										double valorC2){
		A = valorA2;
		B = valorB2;
		C = valorC2;
	}
	void SetCoeficientesRecta1(double valorA1,
										double valorB1,
										double valorC1){
		A = valorA1;
		B = valorB1;
		C = valorC1;
	}
	void SetCoeficientesIniciales(double _A, double _B, double _C){
		A = _A;
		B = _B;
		C = _C;
	}
	double CalculaPendiente(){
		return -A / B;
	}
	double ObtieneOrdenada(double x){
		return (-C - x * A) / B;
	}
	double ObtieneAbscisa(double y){
		return (-C - y * B) / A;
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
		 	 pendiente_2,
		 	 ordenada_1,
		 	 abscisa_1,
		 	 x,
		 	 y;
	string msj_A1 = "RECTA 1::: Introduzca un coeficiente real para A.\n Coeficiente A: ",
			 msj_B1 = "RECTA 1::: Introduzca un coeficiente real para B.\n Coeficiente B: ",
			 msj_C1 = "RECTA 1::: Introduzca un coeficiente real para C.\n Coeficiente C: ",
			 msj_A2 = "\n\nRECTA 2::: Introduzca un coeficiente real para A.\n Coeficiente A: ",
			 msj_B2 = "RECTA 2::: Introduzca un coeficiente real para B.\n Coeficiente B: ",
			 msj_C2 = "RECTA 2::: Introduzca un coeficiente real para C.\n Coeficiente C: ",
			 msj_pendiente_1 = "\n\nLa pendiente de la recta 1 es: ",
			 msj_pendiente_2 = "\n\nLa pendiente de la recta 2 es: ",
			 msj_ordenada_1 =  "\n\nSeñale un valor de X para calcular un valor de Y en la RECTA 1.\n X: ",
			 msj_abscisa_1 = "Señale un valor de Y para calcular un valor de X en la RECTA 1.\n Y: ",
			 msj_resultado_ordn_1 = "\nEl valor de la ordenada en la RECTA 1 con el valor de abscisa dado es: ",
			 msj_resultado_abs_1 = "\nEl valor de la abscisa en la RECTA 1 con el valor de ordenada dado es: ";

	// Objetos
	Recta recta_1 = Recta(1, 1, 1);
	Recta recta_2 = Recta(1, 1, 1);


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
	recta_1.SetCoeficientesRecta1(valorA1 , valorB1 , valorC1);
	recta_2.SetCoeficientesRecta2(valorA2 , valorB2 , valorC2);

	// Cómputos
	ordenada_1 = recta_1.ObtieneOrdenada(x);
	abscisa_1 = recta_1.ObtieneAbscisa(y);
	pendiente_1 = recta_1.CalculaPendiente();
	pendiente_2 = recta_2.CalculaPendiente();

	// Resultados
	
		cout << "\n\nRecta 1 --> " << valorA1 << "x + " << valorB1 << "y + " << valorC1;
		cout << msj_pendiente_1 << pendiente_1;
		cout << msj_resultado_ordn_1 << ordenada_1;
		cout << msj_resultado_abs_1 << abscisa_1;
	
		cout << "\n\n\nRecta 2 --> " << valorA2 << "x + " << valorB2 << "y + " << valorC2;
		cout << msj_pendiente_2 << pendiente_2;
}
