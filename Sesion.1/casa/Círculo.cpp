#include <iostream>
#include <cmath>

using namespace std;

int main(){ 

setlocale(LC_ALL, "spanish");


	double radio;                // Declaro radio
	double circunferencia;       // Declaro circunferencia
	double area;                 // Declaro area
	
	cout << "Introduzca el valor del radio: ";
	cin >> radio;
	
	circunferencia = 2*3.141592*radio;
	area = 3.141592*radio*radio;
	
	cout << "\n\nLongitud de la circunferencia: " << circunferencia;
	cout << "\nÁrea del círculo: " << area;
}
