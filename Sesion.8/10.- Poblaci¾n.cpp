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

long long ValorDobleSegunIncremento (long long valor_inicial , double crecimiento){
	
	long long valor_final = valor_inicial;
	int duracion = 0;
	
	do{
		valor_final = valor_final * crecimiento;
		duracion ++;
	}while (valor_final < valor_inicial * 2);
	
	return  valor_final;
}
/*
int NumAniosHastaPoblacionObjetivo / PoblacionFinalTrasXAnios(double poblacion_objetivo , long long valor_inicial , double crecimiento){
	
	long long valor_final = valor_inicial;
	int duracion = 0;
	
	do{
		valor_final = valor_final * crecimiento;
		duracion ++;
	}while (valor_final < valor_inicial * poblacion_objetivo);
	
	return  duracion / valor_final;
}
*/
int TiempoHastaDoble (long long valor_inicial , double crecimiento){
	
	long long valor_final = valor_inicial;
	int duracion = 0;
	
	do{
		valor_final = valor_final * crecimiento;
		duracion ++;
	}while (valor_final < valor_inicial * 2);
	
	return  duracion;
}

// Prec:
// valor_inicial y duracion deben ser un valor natural
// crecimiento debe ser un real positivo
long Crecimiento (long long valor_inicial , double crecimiento , int periodo){
	
	long long valor_final = valor_inicial;
	int duracion = 0;
	
	do{
		valor_final = valor_final * crecimiento;
		duracion ++;
	}while (duracion < periodo);
	
	return  valor_final;
}

// Prec:
// natalidad, mortalidad y migracion deben ser valores naturales
double IndiceDeCrecimiento (int natalidad , int mortalidad , int migracion){
	int tasa_de_crecimiento = natalidad + migracion - mortalidad;
	double indice_de_crecimiento = 1 + (tasa_de_crecimiento / 1000.0);
	
	return indice_de_crecimiento;
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

int main(){
	
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
	
	poblacion_inicial = LeeIntMayorIgualQue(0 , msj_poblacion_inicial);
	natalidad =			  LeeIntRango(0 , 1000 , msj_natalidad);
	mortalidad =		  LeeIntRango(0 , 1000 , msj_mortalidad);
	migracion = 		  LeeIntRango(0 , 1000 , msj_migracion);
	periodo =			  LeeIntMayorIgualQue(0 , msj_periodo);

	// Cómputo
	indice_de_crecimiento = IndiceDeCrecimiento(natalidad , mortalidad , migracion);

	poblacion_final = Crecimiento(poblacion_inicial , indice_de_crecimiento , periodo);
	
	anio_para_doble = TiempoHastaDoble(poblacion_inicial , indice_de_crecimiento);
	
	poblacion_doble = ValorDobleSegunIncremento(poblacion_inicial , indice_de_crecimiento);

	// Resultado.
	
	cout << "\n\nLa poblacion final trancurridos los años especificados es: " << poblacion_final;
	cout << "\nLos años que han pasado para alcanzar el doble de la poblacion inicial " << "<<" << poblacion_doble << ">>" << " son: " << anio_para_doble;
	
}

