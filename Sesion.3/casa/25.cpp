/*
Programa para cambiar una letra de MAY�SCULA a min�scula.
*/

#include<iostream>

using namespace std;

int main(){
	
	char letra_MAYUSCULA, letra_minuscula;
	int const intervalo_mayus_minus = 32; // intervalo_mayus_minus = 'a' - 'A';
	
	cout << "Introduzca la letra may�scula que desea convertir a min�scula --> ";
	cin >> letra_MAYUSCULA;
	
	letra_minuscula = letra_MAYUSCULA + intervalo_mayus_minus;
	
	cout << "Aqu� est� su letra min�scula --> " << letra_minuscula << "\n\n";
}
