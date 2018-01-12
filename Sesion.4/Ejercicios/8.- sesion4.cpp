#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int anio;
	bool norma_1, norma_2;

	cout << "�Qu� a�o quiere comprobar si era bisiesto? -->";
	cin >> anio;

	norma_1 = (anio % 4 == 0 && anio % 100 != 0);
	norma_2 = anio % 400 == 0;

	if (norma_1)
		cout << "El a�o se�alado (" << anio << ") es bisiesto.\n";
	else 
		if (norma_2)
			cout << "El a�o se�alado (" << anio << ") es bisiesto.\n";
		else 
			cout << "El a�o se�alado (" << anio << ") NO es bisiesto.\n";
}
