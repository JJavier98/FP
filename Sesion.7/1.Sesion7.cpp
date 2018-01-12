
// 1. Encuentre los errores de las siguientes funciones:

// Cuando no hay return cada compilador realiza un comportamiento indeterminado.


int ValorAbsoluto (int entero) {
	if (entero < 0)
		entero = -entero;
	else
		return entero;
}
/*
El fallo en esta función es que si introducimos un número negativo
no hay return de -entero luego no lo cambia de signo.
*/



void Imprime(double valor) {
	double valor;
	cout << valor;
}
/*
El fallo se encuentra en que nombramos al parametro formal y a la
constante local de la misma manera
*/



void Cuadrado (int entero) {
	return entero*entero;
}
/*
Este tipo de función no espera ningún resultado de vuelta (tipo void),
sin embargo, el return es de tipo int (un número entero).
*/



bool EsPositivo(int valor) {
	if (valor > 0)
		return true;
}
/*
En caso de que el entero introducido fuese negativo no habría valor de
retorno en la función.
*/
