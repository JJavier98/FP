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

c) Datos miembro privados
Cambie ahora los datos miembro p�blicos y p�ngalos privados. Tendr� que a�adir
m�todos para asignar y ver los valores de los datos miembro. A�ada m�todos
para asignar un valor a cada uno de los tres datos miembro. Modifique el main
para tener en cuenta estos cambios.

d) Pol�tica de acceso a los datos miembros
En vez de usar un m�todo para asignar un valor a cada dato miembro, defina un
�nico m�todo SetCoeficientes para asignar los tres a la misma vez.
Observe que los m�todos permiten definir la pol�tica de acceso a los datos miembro.
Si tengo previsto cambiar por separado los coeficientes de la recta, usar�
m�todos de asignaci�n individuales. En caso contrario, usar� un �nico m�todo
que modifique a la misma vez todos los datos miembro. Incluso pueden dejarse
en la clase ambos tipos de m�todos para que as� el cliente de la clase pueda usar
los que estime oportunos en cada momento. Por ahora, mantenga �nicamente el
m�todo de asignaci�n en bloque SetCoeficientes.

e) Constructor
Modifique el programa principal del �ltimo apartado e imprima los valores de los
datos miembros de una recta, antes de asignarles los coeficientes. Mostrar�, obviamente,
un valor indeterminado. Para evitar este problema, a�ada un constructor
a la recta para que el objeto est� en un estado v�lido en el mismo momento
de su definici�n. El constructor deber� tener como par�metros, obligatoriamente,
los tres coeficientes de la recta. Tendr� que modificar convenientemente el main
para tener en cuenta este cambio.

f ) Pol�tica de acceso a los datos miembro
Suprima ahora el m�todo SetCoeficientes. De esta forma, una vez creado
el objeto (pas�ndole los datos apropiados en el constructor) ya no podremos
modificar los datos miembro. Esto es �til en aquellas situaciones en las que no
queremos permitir que el estado del objeto cambie, una vez se ha creado.

g) M�todos privados
Vuelva a recuperar el m�todo SetCoeficientes. A�ada un m�todo privado
que nos indique si los coeficientes son correctos, es decir, A y B no pueden ser
simult�neamente nulos. Llame a este m�todo donde sea necesario.
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
	bool CoeficientesCorrectos(double pre_A, double pre_B){
		bool correctos = true;
		if (pre_A == 0 && pre_B == 0){
			correctos = false;
		}
		return correctos;
	}
public:
	//Recta(double A_ini, double B_ini, double C_ini){
	//	SetCoeficientesIniciales(A_ini, B_ini, C_ini);
	//}
	bool Error(double uno, double otro){
		bool error;
		if (CoeficientesCorrectos(uno,otro)){
			error = false;
		}else
			error = true;
		return error;
	}
	void SetCoeficientesRecta2(double valorA2,
										double valorB2,
										double valorC2){
		if (CoeficientesCorrectos(valorA2,valorB2)){
			A = valorA2;
			B = valorB2;
			C = valorC2;
		}
	}
	void SetCoeficientesRecta1(double valorA1,
										double valorB1,
										double valorC1){
		if (CoeficientesCorrectos(valorA1,valorB1)){
			A = valorA1;
			B = valorB1;
			C = valorC1;
		}
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
	string msj_A1 = "RECTA 1::: Introduzca un coeficiente real para A.\n Coeficiente A: ",
			 msj_B1 = "RECTA 1::: Introduzca un coeficiente real para B.\n Coeficiente B: ",
			 msj_C1 = "RECTA 1::: Introduzca un coeficiente real para C.\n Coeficiente C: ",
			 msj_A2 = "\n\nRECTA 2::: Introduzca un coeficiente real para A.\n Coeficiente A: ",
			 msj_B2 = "RECTA 2::: Introduzca un coeficiente real para B.\n Coeficiente B: ",
			 msj_C2 = "RECTA 2::: Introduzca un coeficiente real para C.\n Coeficiente C: ",
			 msj_pendiente_1 = "\n\nLa pendiente de la recta 1 es: ",
			 msj_pendiente_2 = "\n\nLa pendiente de la recta 2 es: ",
			 msj_ordenada_1 =  "\n\nSe�ale un valor de X para calcular un valor de Y en la RECTA 1.\n X: ",
			 msj_abscisa_1 = "Se�ale un valor de Y para calcular un valor de X en la RECTA 1.\n Y: ",
			 msj_resultado_ordn_1 = "\nEl valor de la ordenada en la RECTA 1 con el valor de abscisa dado es: ",
			 msj_resultado_abs_1 = "\nEl valor de la abscisa en la RECTA 1 con el valor de ordenada dado es: ";

	// Objetos
	Recta recta_1; //= Recta(1, 1, 1);
	Recta recta_2; //= Recta(1, 1, 1);


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

	// C�mputos
	ordenada_1 = recta_1.ObtieneOrdenada(x);
	abscisa_1 = recta_1.ObtieneAbscisa(y);
	pendiente_1 = recta_1.CalculaPendiente();
	pendiente_2 = recta_2.CalculaPendiente();

	// Resultados
	if (!(recta_1.Error(valorA1,valorB1))){
		cout << "\n\nRecta 1 --> " << valorA1 << "x + " << valorB1 << "y + " << valorC1;
		cout << msj_pendiente_1 << pendiente_1;
		cout << msj_resultado_ordn_1 << ordenada_1;
		cout << msj_resultado_abs_1 << abscisa_1;
	}
	else
		cout << "\nDatos incorrectos en la Recta 1. A y B no pueden ser nulos simult�neamente."; 
	if (!(recta_2.Error(valorA2,valorB2))){
		cout << "\n\n\nRecta 2 --> " << valorA2 << "x + " << valorB2 << "y + " << valorC2;
		cout << msj_pendiente_2 << pendiente_2;
	}
	else
		cout << "\nDatos incorrectos en la Recta 2. A y B no pueden ser nulos simult�neamente.";
}
