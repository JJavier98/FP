/*
Programa para cambiar una letra de MAYÚSCULA a minúscula.
*/

#include<iostream>

using namespace std;

int main(){
	
	char letra_MAYUSCULA, letra_minuscula;
	int const intervalo_mayus_minus = 32; // intervalo_mayus_minus = 'a' - 'A';
	
	cout << "Introduzca la letra mayúscula que desea convertir a minúscula --> ";
	cin >> letra_MAYUSCULA;
	
	letra_minuscula = letra_MAYUSCULA + intervalo_mayus_minus;
	
	cout << "Aquí está su letra minúscula --> " << letra_minuscula << "\n\n";
}
