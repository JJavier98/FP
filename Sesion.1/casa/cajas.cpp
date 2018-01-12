#include <cmath>
#include <iostream>

using namespace std;

int main(){
	
	double caja_izda;
	double caja_dcha;
	double caja_med;
	
	cout << "Introduce el valor que hay en la caja de la izquierda: ";
	cin >> caja_izda;
	
	cout << "Introduce el valor que hay en la caja de la derecha: ";
	cin >> caja_dcha;
	
	caja_med = caja_dcha;
	caja_dcha = caja_izda;
	caja_izda = caja_med;
	
	cout << "Contenido de la caja de la derecha: " << caja_dcha;
	cout << "\nContenido de la caja de la izquierda: " << caja_izda;
}
