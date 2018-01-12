/*

########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########

### José Javier Alonso Ramos
### 1º de carrera
### Grupo A1
### Práctica 10: clases y struct
## Ejercicio 28

*/

/*
Programa demográfico.
Estimación de la población
atendiendo a la natalidad, mortalidad y
migración.
*/

	// Bibliotecas.

#include <iostream>											
#include <cmath>

using namespace std;


string MensajeComienzo(){
	return "########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########\n\n### José Javier Alonso Ramos\n### 1º de carrera\n### Grupo A1\n### Práctica 10: clases y struct\n### Ejercicio 28\n\n\n\n";
}

// Prec:
// min y max deben ser enteros
// min < max
// mensaje concorde al uso del programa
int LeeIntRango(int min, int max, string mensaje) {
   int a_leer;
   
   do{
      cout << mensaje;
      cin >> a_leer;
   }while (min > a_leer || max < a_leer);
   
   return a_leer;
}

// Prec:
// mensaje debe ser concorde al uso del programa
int LeeIntMayorIgualQue(int minimo, string mensaje){
   int a_leer;

   do{
      cout << mensaje;
      cin >> a_leer;
   }while (minimo > a_leer);

   return a_leer;
}


class Poblacion{
private:
	long long poblacion_inicial, poblacion_tras_periodo, poblacion_doble;
	int natalidad,
		 mortalidad,
		 migracion,
		 periodo,
		 tiempo_doble;
	double indice_crecimiento;

public:
	void SetPoblacionInicial(string msj0){
		poblacion_inicial = LeeIntMayorIgualQue(0, msj0);
	}
	void SetPeriodo(string msj4){
		periodo = LeeIntMayorIgualQue(0, msj4);
	}
	void SetNatalidad(string msj1){
		natalidad = LeeIntRango(0, 1000, msj1);
	}
	void SetMortalidad(string msj2){
		mortalidad = LeeIntRango(0, 1000, msj2);
	}
	void SetMigracion(string msj3){
		migracion = LeeIntRango(0, 1000, msj3);
	}
	void SetIndiceCrecimiento(){
		indice_crecimiento = 1 + (natalidad - mortalidad + migracion) / 1000.0;
	}
	void PoblacionTrasXAnios (){
		poblacion_tras_periodo = poblacion_inicial;
		int duracion = 0;
		
		do{
			poblacion_tras_periodo = poblacion_tras_periodo * indice_crecimiento;
			duracion ++;
		}while (duracion < periodo);
}
void TiempoPoblacion_Doble (){
	long long TOPE = poblacion_inicial * 2;
	poblacion_doble = poblacion_inicial;
	tiempo_doble = 0;
	
	do{
		poblacion_doble = poblacion_doble * indice_crecimiento;
		tiempo_doble ++;
	}while (poblacion_doble < TOPE);
}
long long ShowPoblacionTrasPeriodo(){
	return poblacion_tras_periodo;
}
long long ShowPoblacionDoble(){
	return poblacion_doble;
}
int ShowTiempoDoble(){
	return tiempo_doble;
}
};

int main(){
	
	cout << MensajeComienzo();
	
	// Objetos
	Poblacion pueblo1;

	// Variables
	
	int anio, anio_para_doble;					
	double periodo;
	double natalidad;
	double mortalidad;
	double migracion;
	double indice_de_crecimiento;
	long long poblacion_final, poblacion_inicial, poblacion_doble;
	
	string msj_poblacion_inicial = "\n\nIntroduzca la población inicial: ",
			 msj_natalidad = 			 "Introduzca la tasa de natalidad: ",
			 msj_mortalidad = 		 "Introduzca la tasa de mortalidad: ",
			 msj_migracion = 			 "Introduzca la tasa de migración: ",
			 msj_periodo = 			 "Introduzca el periodo de años: ";
	
	// Entrada de datos

	cout << "Los datos de natalidad, mortalidad y migración se introducirán en tanto por mil.";	
	
	pueblo1.SetPoblacionInicial(msj_poblacion_inicial);
	pueblo1.SetNatalidad(msj_natalidad);
	pueblo1.SetMortalidad(msj_mortalidad);
	pueblo1.SetMigracion(msj_migracion);
	pueblo1.SetPeriodo(msj_periodo);

	// Cómputo
	pueblo1.SetIndiceCrecimiento();
	pueblo1.PoblacionTrasXAnios();
	pueblo1.TiempoPoblacion_Doble();

	// Resultado.
	
	cout << "\n\nLa poblacion final trancurridos los años especificados es: " << pueblo1.ShowPoblacionTrasPeriodo();
	cout << "\nLos años que han pasado para alcanzar el doble de la poblacion inicial " << "<<" << pueblo1.ShowPoblacionDoble() << ">>" << " son: " << pueblo1.ShowTiempoDoble();
	
}

