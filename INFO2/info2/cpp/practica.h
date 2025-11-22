#ifndef PRACTICA_H
#define PRACTICA_H

#include <Arduino.h>

class Cilindro {
public:
    Cilindro();
    void calcularVolumen();
private:
    long radio;
    long altura;
};

class Vector2D {
	public:
		Vector2D();
    		void cargarVector(long a, long b);
    		void imprimirLongitud();
    		void multiplicacion(long n);
    		Vector2D sumVector(Vector2D a, Vector2D b);
    		Vector2D restVector(Vector2D a, Vector2D b);
	private:
    		long x;
    		long y;
};

class Temperatura{
	public:
		Temperatura ();
		void setCelcius(int c);
		long toFahrenheit(void);
		long toKelvin();
		void muestreo();
	private:
		long gCelcius;
};

class Entrada {
	public:
		Entrada(uint8_t pin);//Indicar pin a utilizar
		int getEstado();//Estado actual de la entrada
		bool getFlancoAsc()//Devuelve si de tecta up
		bool getFlancoDes()//Devuelve si se detecta un down

	private:
		uint8_t pin; // pin de entrada
		int estadoAnt,estado; //estado anterior y actual
		bool flancoAsc, flancoDes; // detectar flancos
		unsigned long lastDebounceTime; //ultimo tiempo de rebote
		unsigned long debounceDelay; //tiempo antirebote
}

class Tarea{
	public:
		Tarea(unsigned long periodo);
		bool esTiempo(Tarea &tarea);
	private:
		unsigned long periodo;
		unsigned long tiepoAnterior
};
#endif // PRACTICA_H

