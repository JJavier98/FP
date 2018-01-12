#include <iostream>
#include <cmath>

using namespace std;

double SumatoriaHastaTope (double primer_termino , double razon , int tope){
	double termino_k = primer_termino;
	double suma = termino_k;
	
	for (int k = 2 ; k <= tope ; k ++){
		a = a * pow (razon , exponente);
		suma = suma + a;
	}
	
	return suma;
}

/*
double TerminoK_esimo (double primer_termino , double razon , int k){
	int exponente = k - 1;
	double a = primer_termino;
	
	a = a * pow (razon , exponente);
	
	return a;
}

double SumatoriaHastaTopeConTerminoK_esimo (double primer_termino , double razon , int tope){
	double a_sumar,
			 sumatoria = 0;
	int k;
	
	for (int i = 1 ; i <= tope ; i ++){
		k = i;
		a_sumar = TerminoK_esimo (primer_termino , razon , k);
		sumatoria = sumatoria + a_sumar;
	}
	return sumatoria;
}
*/

int main(){
	double primer_termino,
			 resultado,
			 razon;
	int 	 tope;
	
	cin >> primer_termino;
	cin >> razon;
	cin >> tope;
	
	resultado = SumatoriaHastaTope (primer_termino , razon , tope);
	
	cout << resultado;
	
}
