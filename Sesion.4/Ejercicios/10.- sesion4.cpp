#include <iostream>
#include <cmath>

using namespace std;

int main(){

	/*
	0 - 30: 0.0412 €/min
	31 - 90: 0.0370 €/min
	91 - 660: 0.0493 €/min
	660 - ...: 31.55€
	*/
	
	double const min0_30 = 0.0412;
	double const min31_90 = 0.0370;
	double const min91_660 = 0.0493;
	double const min661 = 31.55;

	int const segundos_x_minuto = 60;
	int const segundos_x_hora = 60 * 60;
	
	double precio_final;

	int segundo_inicial, minuto_inicial, hora_inicial;
	int minuto_ini_en_segundos, hora_ini_en_segundos;
	int segundos_iniciales_totales;

	int segundo_final, minuto_final, hora_final;
	int minuto_final_en_segundos, hora_final_en_segundos;
	int segundos_finales_totales;

	int diferencia_de_tiempo_seg, minutos_transcurridos;
	
	
	
	cout << "Introduzca la hora a la que ENTRÓ en el parking en horas, minutos y segundos separando los datos por un espacio. --> ";
	cin >> hora_inicial;
	cin >> minuto_inicial;
	cin >> segundo_inicial;
	cout << "Introduzca la hora a la que SALIÓ del parking en horas, minutos y segundos separando los datos por un espacio. --> ";
	cin >> hora_final;
	cin >> minuto_final;
	cin >> segundo_final;
	


	minuto_ini_en_segundos = minuto_inicial * segundos_x_minuto;
	hora_ini_en_segundos = hora_inicial * segundos_x_hora;
	segundos_iniciales_totales = segundo_inicial + minuto_ini_en_segundos + hora_ini_en_segundos;

	minuto_final_en_segundos = minuto_final * segundos_x_minuto;
	hora_final_en_segundos = hora_final * segundos_x_hora;
	segundos_finales_totales = segundo_final + minuto_final_en_segundos + hora_final_en_segundos;

	diferencia_de_tiempo_seg = segundos_finales_totales - segundos_iniciales_totales;
	minutos_transcurridos = diferencia_de_tiempo_seg / segundos_x_minuto;
	


	if (minutos_transcurridos <= 30)
		precio_final = minutos_transcurridos * min0_30;
	else
		if (minutos_transcurridos > 30 && minutos_transcurridos <= 90)
			precio_final = minutos_transcurridos * min31_90;
		else
			if (minutos_transcurridos > 90 && minutos_transcurridos <= 660)
				precio_final = minutos_transcurridos * min91_660;
			else 
				if (minutos_transcurridos > 660)
					precio_final = min661;
				else 
					cout << "Ha ocurrido un error, vuelva a intentarlo";
					
	cout << "El tiempo estacionado se corresponde con " << precio_final << "€, BUENOS DÍAS.";
	
}
