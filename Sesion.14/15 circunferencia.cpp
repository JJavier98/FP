#include <cmath>  // NAN
#include <iostream>
using namespace std;

const double PI = 3.1415927;

struct CoordenadasPunto2D{
	double abscisa;
	double ordenada;
};

class Punto2D{
private:
	double abscisa;
	double ordenada;
public:
	Punto2D(double x, double y)
		:abscisa(x), ordenada(y)
		{
		}
		
	double GetAbscisa(){
		return abscisa;
	}
	
	double GetOrdenada(){
		return ordenada;
	}		
};

class SegmentoDirigido{
private:
	double x_1 = 0.0,
			 y_1 = 0.0,
			 x_2 = 0.0,
			 y_2 = 0.0;
public:
	void 	SetCoordenadas(double origen_abscisa, double origen_ordenada, double final_abscisa,	double final_ordenada){
									
		if (! (origen_abscisa == final_abscisa &&	origen_ordenada == final_ordenada)){
			
			x_1 = origen_abscisa;
			y_1 = origen_ordenada;
			x_2 = final_abscisa;
			y_2 = final_ordenada;
		}
	}
	
	double OrigenAbscisa(){
		return x_1;
	}
	
	double OrigenOrdenada(){
		return y_1;
	}
	
	double FinalAbscisa(){
		return x_2;
	}
	
	double FinalOrdenada(){
		return y_2;
	}
	
	double Longitud(){
		double resta_abscisas = x_2 - x_1;
		double resta_ordenadas = y_2 - y_1;
		
		return sqrt(resta_abscisas * resta_abscisas + resta_ordenadas * resta_ordenadas);
	}
	
	void TrasladaHorizontal(double unidades){
		x_1 = x_1 + unidades;
		x_2 = x_2 + unidades;
	}
	
	void TrasladaVertical(double unidades){
		y_1 = y_1 + unidades;
		y_2 = y_2 + unidades;
	}
};


class Circunferencia{
private:
	CoordenadasPunto2D centro = {NAN, NAN};
	double radio = NAN;
	
	bool EsCorrectoRadio(double long_radio){
	   return long_radio >= 0;
	}
public:
   // Hemos decidido que, una vez establecidos el centro y el radio
   // en el constructor, luego ya no pueden modificarse, por lo que
   // no proporcionamos ningún método del tipo SetRadio o SetCentro
   
   // Si los valores pasados en el constructor no son correctos
   // los datos miembro se quedarán con NAN, indicativo de que
   // ha habido un error.
   
	Circunferencia(Punto2D centro_circunferencia, 
                  double longitud_radio)
   {
      if (EsCorrectoRadio(longitud_radio)){
         centro.abscisa = centro_circunferencia.GetAbscisa();
         centro.ordenada = centro_circunferencia.GetOrdenada();
         radio  = longitud_radio;
      }
	}
	
	double Longitud(){
		return 2*PI*radio;
	}
	
	double Area(){
		return PI*radio*radio;
	}
	
	SegmentoDirigido SegmentoRadio(){
		SegmentoDirigido segm_1;
		
		segm_1.SetCoordenadas(centro.abscisa, centro.ordenada, centro.abscisa + radio, centro.ordenada);
		
		return segm_1;
		
	}
	
	bool Contiene(CoordenadasPunto2D un_punto){
		double diferencia_abscisas, diferencia_ordenadas;
		bool contiene;

		diferencia_abscisas = centro.abscisa - un_punto.abscisa;
		diferencia_ordenadas = centro.ordenada - un_punto.ordenada;

		contiene = diferencia_abscisas*diferencia_abscisas 
                 + 
                 diferencia_ordenadas*diferencia_ordenadas 
                 <= 
                 radio * radio; 
              
      return contiene;
	}
};

/*
// Ampliación:
//	En la siguiente versión se define PI como una constante estática de la clase Circunferencia.
//	El problema es que lo normal es que tengamos en este programa más clases relativas a 
// conceptos de Trigonometría y posiblemente también sea necesario acceder a PI desde dichas clases
// Por eso, en este ejemplo, es preferible definir PI como una constante global

// Un dato declarado como const en una clase declara un dato constante
//	en cada objeto, pero puede ser distinto entre objetos
// Para que sea la misma cte para todos los objetos, debemos declararla como static
// Las constantes enteras static se pueden incializar dentro de la clase
//	pero no las doubles!!! que deben asignarse fuera del class :-((

class Circunferencia{
private:
	CoordenadasPunto2D centro;
	double radio;
	static const double PI;
public:
	Circunferencia(CoordenadasPunto2D centro_circunferencia, double longitud_radio)
		: centro(centro_circunferencia),
		  radio(longitud_radio)
		{	
		}
	double Longitud(){
		return 2*PI*radio;
	}
	double Area(){
		return PI*radio*radio;
	}
};

const double Circunferencia::PI = 3.1416;
*/



int main(){
	double abscisa, ordenada;
	double radio;
	SegmentoDirigido seg_rad;

   cout << "Circunferencia\n\n";
   cout << "Introduzca las coordenadas del centro y la longitud del radio:\n";   
   cin >> abscisa;
   cin >> ordenada;
   cin >> radio;
   
   Punto2D centro_1(abscisa, ordenada);
   Circunferencia circunf(centro_1, radio);
   
   seg_rad = circunf.SegmentoRadio();
   
   cout << "\n\nLongitud de radio de circunferencia: " << radio;
   cout << "\nLongitud de segmento-radio: " << seg_rad.Longitud();
}

