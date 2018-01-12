#include <iostream>
using namespace std;

class ImagenBlancoNegro{
private:
	static const int 	MAX_FIL_COL = 1e5,
							NEGRO = 0,
							BLANCO = 255;
	int matriz_privada[MAX_FIL_COL][MAX_FIL_COL];
	const int util_filas, util_columnas;
public:
	ImagenBlancoNegro(int filas_utilizadas, int columnas_utilizadas)
		:util_filas(filas_utilizadas), util_columnas(columnas_utilizadas)
		{
			// Inicializa
			for (int fil = 0 ; fil < util_filas ; fil++){
				for (int col = 0 ; col < util_columnas ; col++){
					matriz_privada[fil][col] = 0;
				}
			}
		}
	
	int Pixel(int fil, int col){
		int pixel;
		pixel = matriz_privada[fil][col];
		return pixel;
	}
	
	void Modifica(int fil, int col, int nuevo){
		if(nuevo <= BLANCO && NEGRO <= nuevo)
			matriz_privada[fil][col] = nuevo;
	}
	
	ImagenBlancoNegro MeanFilterforSmoothing(){
		int suma, contador, valor_final;
		ImagenBlancoNegro imagen_suavizada(util_filas, util_columnas);

		for (int i = 0 ; i < util_filas ; i++){
			for (int j = 0 ; j < util_columnas ; j++){
				imagen_suavizada.Modifica(i, j, Pixel(i, j));
			}
		}
		 
		for (int i = 0 ; i < util_filas ; i++){
			for (int j = 0 ; j < util_columnas ; j++){
				cout << imagen_suavizada.Pixel(i, j);
			}
		}

		 for(int fil = 1 ; fil < util_filas - 1 ; fil++){
		 	for(int col = 1 ; col < util_columnas - 1 ; col++){

				if ( Pixel(fil, col) < 0 ){
					suma = 0;
					contador = 0;

					for (int fil_suave = fil - 1 ; fil_suave < util_filas + 2 ; fil_suave++){
						for (int col_suave = col - 1 ; col_suave < util_columnas + 2 ; col_suave++){
							if ( Pixel(fil_suave, col_suave) ){
								suma = suma + Pixel(fil_suave, col_suave);
								contador++;
							}
						}
					}
					if (suma == 0)
						valor_final = 0;
					else
						valor_final = suma / contador;

					imagen_suavizada.Modifica(fil, col, valor_final);
				}
			}
		}

		return imagen_suavizada;
	}
};

int main(){
	int filas_usadas, columnas_usadas, nuevo;

	cout << "Introduzca tamaño: ";
	cin >> filas_usadas;
	cin >> columnas_usadas;

	ImagenBlancoNegro imagen(filas_usadas, columnas_usadas);

	for (int i = 0 ; i < filas_usadas ; i++){
		for (int j = 0 ; j < columnas_usadas ; j++){
			cout << "introduzca pixel";
			cin >> nuevo;
			imagen.Modifica(i, j, nuevo);
		}
	}

	ImagenBlancoNegro procesada(imagen.MeanFilterforSmoothing());

	for (int i = 0 ; i < filas_usadas ; i++){
		for (int j = 0 ; j < columnas_usadas ; j++){
			cout << procesada.Pixel(i, j);
		}
	}

}
