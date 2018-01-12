/*

########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########

### Jos� Javier Alonso Ramos
### 1� de carrera
### Grupo A1
### Pr�ctica 10: clases y struct
### Ejercicio 48

*/

	// BIBLIOTECAS
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.1415927; // Declaramos la constante global como excepci�n por tratarse del n�mero pi.

string MensajeComienzo(){
	return "########## FUNDAMENTOS DE PROGRAMACI�N - ETSIIT ##########\n\n### Jos� Javier Alonso Ramos\n### 1� de carrera\n### Grupo A1\n### Pr�ctica 10: clases y struct\n### Ejercicio 48\n\n\n\n";
}

	// STRUCTS Y CLASES
struct CoordenadasPunto2D{
   double abscisa;
   double ordenada;
};

class Circunferencia{
private:
	double radio,
			 longitud,
			 area;
	CoordenadasPunto2D centro;
public:
	void Setradio(){
		cout << "Introduzca el valor del radio: ";
		cin >> radio;
	}
	void SetLongitud(){
		longitud = 2 * PI * radio;
	}
	double ShowLongitud(){
		return longitud;
	}
	void SetArea(){
		area = PI * radio * radio;
	}
	double ShowArea(){
		return area;
	}
	void SetCoordenadasCentro(){
		cout << "Introduzca las cordenadas del centro de la circunferencia (x,y)\n Coordenadas: ";
		cin >> centro.abscisa;
		cin >> centro.ordenada;
	}
	bool Contiene(double x_1, double y_1){
		return (centro.abscisa - x_1) * (centro.abscisa - x_1) + (centro.ordenada - y_1) * (centro.ordenada - y_1) <= radio * radio;
	}
};
	// FUNCI�N PRINCIPAL
int main(){ 

	cout << MensajeComienzo();

	// OBJETO
	Circunferencia circulo_1;
	
	// VARIABLES
	double x_1,
			 y_1;
			 
	// INTRODUCCI�N Y C�LCULO DE DATOS MIEMBROS
	circulo_1.SetCoordenadasCentro();
	circulo_1.Setradio();
	circulo_1.SetLongitud();
	circulo_1.SetArea();
	
	cout << "Se�ala las cordenadas de un punto para comprobar si est�n dentro o no de la circunferencia\n Coordenadas: ";
	cin >> x_1;
	cin >> y_1;
	
	// RESULTADOS
	cout << "\n\nLongitud de la circunferencia: " << circulo_1.ShowLongitud();
	cout << "\n�rea del c�rculo: " << circulo_1.ShowArea();

	if (circulo_1.Contiene(x_1, y_1)){
		cout << "\nLa Circunferencia contiene al punto (" << x_1 << "," << y_1 << ")";
	}
	else
		cout << "\nLa Circunferencia NO contiene al punto (" << x_1 << "," << y_1 << ")";
}
