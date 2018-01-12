#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	setlocale(LC_ALL, "spanish");
	
	double salario_base;
	
	cout << "Introduce saliro base: ";
	cin >> salario_base;
	
	cout << "Salario final: " << salario_base*1.02;
}
