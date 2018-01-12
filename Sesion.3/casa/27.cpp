/*
programa con distintas expresiones l�gicas.
*/

#include<iostream>
#include<cctype>

using namespace std;

int main(){
	
	char letra;
	int edad, adivine, anio;
	bool minuscula, joven_o_mayor, entre_centena, bisiesto;
	// mayor_de_edad = 18;
	// edad_de_jubilacion = 65;
	
	cout << "La salida en pantalla de un '1' significar� SI, por el contrario un '0' significar� NO.\n";
	cout << "\nIntroduzca una letra para comprobar si es min�scula o may�scula,\nuna edad para comprobar si es menor de 18 o mayor de 65,\nun n�mero para saber si est� entre 1 y 100 y\nun a�o para saber si es bisiesto:\n";
	cin >> letra;
	cin >> edad;
	cin >> adivine;
	cin >> anio;
	
	minuscula = 97 <= letra && letra <= 122; 				// 'a' <= letra && letra <= 'z';
	joven_o_mayor = edad < 18 || edad > 65; 				// edad < mayor_de_edad || edad > edad_de_jubilacion;
	entre_centena = adivine >= 1 && adivine <= 100;
	bisiesto = ((anio % 4 == 0) && (anio % 100 != 0)) || anio % 400 == 0;
	
	cout << "\n�La letra es min�scula? --> " << minuscula;
	cout << "\n�La persona es menor de edad o mayor de 65 a�os? --> " << joven_o_mayor;
	cout << "\n�El n�mero introducido se encuentra entre 1 y 100? --> " << entre_centena;
	cout << "\n�El a�o especificado es bisiesto? --> " << bisiesto;
}
