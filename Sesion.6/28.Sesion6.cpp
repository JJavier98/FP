#include <iostream>

using namespace std;

int main(){

	// Declaración de variables
	
	double SALARIO_HORA,
			divisor,
			media;
	const int TERMINADOR = -1;
	int codigo_empleado = 0,
		primer_empleado = 1,
		segundo_empleado = 2,
		tercer_empleado = 3,
		tiempo_de_atencion,
		solucion_de_problema,
		grado_de_satisfaccion,
		contador_de_casos_totales = 0,
		casos_1 = 0,
		casos_2 = 0,
		casos_3 = 0,
		satisfaccion_total_1 = 0,
		satisfaccion_total_2 = 0,
		satisfaccion_total_3= 0,
		grado_maximo,
		empleado_max;

	// Introducción de datos

	cout << "Introduzca el salario por hora de los trabajadores. \n  Salario: ";
	cin >> SALARIO_HORA;

	while(codigo_empleado != TERMINADOR){

		cout << "\n\nSeñale el identificador del empleado del que va a proporcionar la información. \nRecuerde que el dato '-1' le sacará del programa. \n  Indicador: ";
		cin >> codigo_empleado;

		if(codigo_empleado != TERMINADOR){

			cout << "¿Cuántos segundos ha durado, aproximadamente, su consulta? \n  Tiempo: ";
			cin >> tiempo_de_atencion;

			cout << "Marque '1' si resolvieron su problema o '0' en caso contrario \n  ¿Resuelto?: ";
			cin >> solucion_de_problema;

			cout << "Por último califique de 0 a 5 a nuestro operador según su grado de satisfacción \n  Nota: ";
			cin >> grado_de_satisfaccion;

			contador_de_casos_totales ++;
		}
		// Cómputos
		
		if(codigo_empleado == primer_empleado){
			satisfaccion_total_1 = satisfaccion_total_1 + grado_de_satisfaccion;
			casos_1 ++;
		}
		else 
			if(codigo_empleado == segundo_empleado){
				satisfaccion_total_2 = satisfaccion_total_2 + grado_de_satisfaccion;
				casos_2 ++;
			}
			else 
				if(codigo_empleado == tercer_empleado){
					satisfaccion_total_3 = satisfaccion_total_3 + grado_de_satisfaccion;
					casos_3 ++;
				}
	}
	
	divisor = 0.0;
	
	if(contador_de_casos_totales < 1)
		cout << "\n\nHa salido del programa";
	else{
		grado_maximo = satisfaccion_total_1;
		divisor = divisor + casos_1;
		empleado_max = primer_empleado;

		if(satisfaccion_total_2 > grado_maximo){
			grado_maximo = satisfaccion_total_2;
			divisor = divisor + casos_2;
			empleado_max = segundo_empleado;
		}
		else if (satisfaccion_total_3 > grado_maximo){
			grado_maximo = satisfaccion_total_3;
			divisor = divisor + casos_3;
			empleado_max = tercer_empleado;
		}
		media = grado_maximo / divisor;
		
		cout << "\n\nEl número de casos introducido es: " << contador_de_casos_totales;
		cout << "\nEl identificador del empleado con mayor media de satisfacción es: " << empleado_max;
		cout << "\nLa media de satisfacción del empleado es: " << media;
	}
}
		
		
		
		
