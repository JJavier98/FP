#include <iostream>
using namespace std;

int main(){
	const int TAMANIO = 30;
	double matriz_reales[TAMANIO][TAMANIO], matriz_traspuesta[TAMANIO][TAMANIO];
	int util_filas, util_columnas;

	cout << "Introduzca el numero de filas y de columnas."  << "\n Filas: ";
	cin >> util_filas;
	cout << " Columnas: ";
	cin >> util_columnas;

	cout << "Introduzca una matriz de reales de dicho tamaño.";

	for (int fil = 0 ; fil < util_filas ; fil++){
		for (int col = 0 ; col < util_columnas ; col++){
			double dato;

			cout << "Introduzca el elemento: [" << fil + 1 << "," << col + 1 << "]";
			cin >> dato;

			matriz_reales[fil][col] = dato;
			matriz_traspuesta[col][fil] = dato;
		}
	}

	for (int fil = 0 ; fil < util_filas ; fil++){
		for (int col = 0 ; col < util_columnas ; col++){	
			cout << matriz_reales[fil][col] << " ";
		}
		cout << "\n";
	}

	cout << "\n";

	for (int fil = 0 ; fil < util_filas ; fil++){
		for (int col = 0 ; col < util_columnas ; col++){	
			cout << matriz_traspuesta[fil][col] << " ";
		}
		cout << "\n";
	}
}
