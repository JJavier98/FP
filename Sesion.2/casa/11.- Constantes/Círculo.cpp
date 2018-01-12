#include <iostream>
#include <cmath>

using namespace std;

int main(){ 

setlocale(LC_ALL, "spanish");


	double radio;                // Declaro radio
	double circunferencia;       // Declaro circunferencia
	double area;                 // Declaro area
	double PI = 3.141592;
	
	cout << "Introduzca el valor del radio: ";
	cin >> radio;
	
	circunferencia = 2 * PI * radio;
	area = PI * radio * radio;
	
	cout << "\n\nLongitud de la circunferencia: " << circunferencia;
	cout << "\nÁrea del círculo: " << area;
}
