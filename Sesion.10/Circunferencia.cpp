/*

########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########

### José Javier Alonso Ramos
### 1º de carrera
### Grupo A1
### Práctica 10: clases y struct
### Ejercicio 48

*/

	// BIBLIOTECAS
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.1415927; // Declaramos la constante global como excepción por tratarse del número pi.

string MensajeComienzo(){
	return "########## FUNDAMENTOS DE PROGRAMACIÓN - ETSIIT ##########\n\n### José Javier Alonso Ramos\n### 1º de carrera\n### Grupo A1\n### Práctica 10: clases y struct\n### Ejercicio 48\n\n\n\n";
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
	// FUNCIÓN PRINCIPAL
int main(){ 

	cout << MensajeComienzo();

	// OBJETO
	Circunferencia circulo_1;
	
	// VARIABLES
	double x_1,
			 y_1;
			 
	// INTRODUCCIÓN Y CÁLCULO DE DATOS MIEMBROS
	circulo_1.SetCoordenadasCentro();
	circulo_1.Setradio();
	circulo_1.SetLongitud();
	circulo_1.SetArea();
	
	cout << "Señala las cordenadas de un punto para comprobar si están dentro o no de la circunferencia\n Coordenadas: ";
	cin >> x_1;
	cin >> y_1;
	
	// RESULTADOS
	cout << "\n\nLongitud de la circunferencia: " << circulo_1.ShowLongitud();
	cout << "\nÁrea del círculo: " << circulo_1.ShowArea();

	if (circulo_1.Contiene(x_1, y_1)){
		cout << "\nLa Circunferencia contiene al punto (" << x_1 << "," << y_1 << ")";
	}
	else
		cout << "\nLa Circunferencia NO contiene al punto (" << x_1 << "," << y_1 << ")";
}
