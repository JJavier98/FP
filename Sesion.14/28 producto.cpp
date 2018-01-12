#include <iostream>
using namespace std;


////////////////////////////////////////////////////////////////////////////////
int main(){
	
	const int TAMANIO = 30;
	double matriz_reales_1[TAMANIO][TAMANIO],matriz_reales_2[TAMANIO][TAMANIO], matriz_traspuesta_1[TAMANIO][TAMANIO], matriz_traspuesta_2[TAMANIO][TAMANIO], Producto[TAMANIO][TAMANIO];
	int util_filas_1, util_columnas_1,
		 util_filas_traspuesta_1, util_columnas_traspuesta_1,
		 util_filas_2, util_columnas_2,
		 util_filas_traspuesta_2, util_columnas_traspuesta_2;
	
////////////////////////////////////////////////////////////////////////////////

	cout << "Introduzca el numero de filas y de columnas."  << "\n Filas: ";
	cin >> util_filas_1;
	cout << " Columnas: ";
	cin >> util_columnas_1;
	
////////////////////////////////////////////////////////////////////////////////

	cout << "\nMatriz 1 de reales [" << util_filas_1 << "," << util_columnas_1 << "]\n\n";

	for (int fil = 0 ; fil < util_filas_1 ; fil++){
		for (int col = 0 ; col < util_columnas_1 ; col++){
			double dato;

			cout << "Introduzca el elemento: [" << fil + 1 << "," << col + 1 << "]";
			cin >> dato;

			matriz_reales_1[fil][col] = dato;
			matriz_traspuesta_1[col][fil] = dato;
		}
	}
	
////////////////////////////////////////////////////////////////////////////////
	
	cout << "Señale el numero de columnas que tendrá la matriz 2: ";
	cin >> util_columnas_2;
	util_filas_2 = util_filas_1;
	cout << "Matriz 2 de reales [" << util_filas_2 << "x" << util_columnas_2 << "]\n\n";

	for (int fil = 0 ; fil < util_filas_2 ; fil++){
		for (int col = 0 ; col < util_columnas_2 ; col++){
			double dato;

			cout << "Introduzca el elemento: [" << fil + 1 << "," << col + 1 << "]";
			cin >> dato;

			matriz_reales_2[fil][col] = dato;
			matriz_traspuesta_2[col][fil] = dato;
		}
	}
	
////////////////////////////////////////////////////////////////////////////////

	cout << "\nLa matriz 1 es: \n";

	for (int fil = 0 ; fil < util_filas_1 ; fil++){
		for (int col = 0 ; col < util_columnas_1 ; col++){	
			cout << matriz_reales_1[fil][col] << " ";
		}
		cout << "\n";
	}

	util_filas_traspuesta_1 = util_columnas_1;
	util_columnas_traspuesta_1 = util_filas_1;

	cout << "\nLa matriz traspuesta 1 es: \n";

	for (int fil = 0 ; fil < util_filas_traspuesta_1 ; fil++){
		for (int col = 0 ; col < util_columnas_traspuesta_1 ; col++){	
			cout << matriz_traspuesta_1[fil][col] << " ";
		}
		cout << "\n";
	}
	
////////////////////////////////////////////////////////////////////////////////
	
	cout << "\nLa matriz 2 es: \n";

	util_filas_2 = util_columnas_1;
	
	for (int fil = 0 ; fil < util_filas_2 ; fil++){
		for (int col = 0 ; col < util_columnas_2 ; col++){	
			cout << matriz_reales_2[fil][col] << " ";
		}
		cout << "\n";
	}

	util_filas_traspuesta_2 = util_columnas_2;
	util_columnas_traspuesta_2 = util_filas_2;

	cout << "\nLa matriz traspuesta 2 es: \n";

	for (int fil = 0 ; fil < util_filas_traspuesta_2 ; fil++){
		for (int col = 0 ; col < util_columnas_traspuesta_2 ; col++){	
			cout << matriz_traspuesta_2[fil][col] << " ";
		}
		cout << "\n";
	}
	
////////////////////////////////////////////////////////////////////////////////

	// Inicializamos la matriz Producto.
    for(int i = 0 ; i < util_filas_1 ; i++)
        for(int j = 0 ; j < util_columnas_2 ; j++)
            Producto[i][j] = 0;

    // Generamos la matriz Producto.
    for(int i = 0 ; i < util_filas_1 ; i++)
        for(int j = 0 ; j < util_columnas_2 ; j++)
            for(int z = 0 ; z < util_columnas_1 ; z++)
                Producto[i][j] += matriz_reales_1[i][z] * matriz_reales_2[z][j];



cout << "\nLa matriz Producto es: \n";

	for (int fil = 0 ; fil < util_filas_1 ; fil++){
		for (int col = 0 ; col < util_columnas_2 ; col++){	
			cout << Producto[fil][col] << " ";
		}
		cout << "\n";
	}
}
