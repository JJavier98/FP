#include <cmath>
#include <iostream>

using namespace std;

int main(){
	
	int x;
	int y;
	int z;
	int caja_de_apoyo;
	
	cout << "Introduce el valor de la caja X: ";
	cin >> x;
	cout << "Introduce el valor de la caja Y: ";
	cin >> y;
	cout << "Introduce el valor de la caja Z: ";
	cin >> z;

	caja_de_apoyo = z;
	z = y;
	y = x;
	x = caja_de_apoyo;
		
	cout << "\nContenido de la caja de X: " << x;
	cout << "\nContenido de la caja de Y: " << y;
	cout << "\nContenido de la caja de Z: " << z;
}
