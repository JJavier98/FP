/* Programa para calcular el voltaje de un circuito*/

#include <iostream>

using namespace std;

int main(){
	double voltaje;
	double intensidad;
	double resistencia;
	
	cout << "Introduzca el valor de la Intensidad: ";
	cin >> intensidad;
	
	cout << "Introduzca el valor de la Resistencia: ";
	cin >> resistencia;
	
	voltaje = intensidad * resistencia;
	
	cout << "El voltaje del circuito es: " << voltaje;
}
