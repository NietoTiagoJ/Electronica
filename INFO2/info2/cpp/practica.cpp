#include "practica.h"
#include <iostream>
#include <Arduino.h>
#include <cmath>

using namespace std;

// Implementación de Cilindro
Cilindro::Cilindro() : radio(0), altura(0) {}

void Cilindro::calcularVolumen() {
    cout << "Cargar radio: ";
    cin >> radio;
    cout << "Cargar altura: ";
    cin >> altura;

    float volumen = radio * radio * altura * 3.14159; // Fórmula del volumen
    cout << "El volumen es: " << volumen << endl;
}

// Implementación de Vector2D
Vector2D::Vector2D() : x(0), y(0) {}

void Vector2D::cargarVector(long a, long b) {
    x = a;
    y = b;
}

void Vector2D::imprimirLongitud() {
    cout << "La longitud del vector es: " << sqrt((x * x) + (y * y)) << endl;
}

void Vector2D::multiplicacion(long a) {
    x *= a;
    y *= a;
}

Vector2D Vector2D::sumVector(Vector2D a, Vector2D b) {
    Vector2D result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

Vector2D Vector2D::restVector(Vector2D a, Vector2D b) {
    Vector2D result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

//Implementacion de Temperatura

Temperatura::Temperatura(){
	this->gCelcius =0;
}

void Temperatura::setCelcius(int c){
	this->gCelcius = c;
}

long Temperatura::toFahrenheit(void){
	return ((this->gCelcius * 1.8)+32);
}

long Temperatura::toKelvin(){
	return (this->gCelcius + 273.15);
}

void Temperatura::muestreo(){
 cout<<"Temperaturas"<<endl;
 cout<<"Celcius: "<<this->gCelcius<<endl;
 cout<<"Fahrenheit: "<<this->toFahrenheit()<<endl;
 cout<<"Kelvin: "<<this->toKelvin()<<endl;
}

//Implementacion de Entrada ejer6

Entrada::Entrada(uint8_t pin): pin(pin), estadoAnt(LOW), flancoAsc(false), flancoDes(false){
		pinMode(pin,INPUT);
		lastDebounceTime = 0;
    		debounceDelay = 50; // Tiempo de antirrebote por defecto
}

int Entrada::getEstado(){
	return digitalRead();
}

bool Entrada::getFlancoAsc(){
	bool tmp = flancoAsc;
	flancoAsc = false;
	return tmp;
}
bool Entrada::getFlancoDes(){
	bool tmp = flacoDes;
	flancoDes = false;
	return tmp;
}

int Temperatura::getEstado(unsigned long debounceTime){
	unsigned long currentTime = millis();
	int lectura = digitalRead(pin);
	if(lectura != estadoAnt){
		lastDebounceTime = currentTime();
	}

	if((currenTime - lastDebounceTime > debounceDelay)){
		if(lectura != estado){
			estado = lectura;
			if(estado==HIGH){
				flancoAsc=true;
			}else{
				flancoDes=true;
			}
		}
	}

	estadoAnt = lectura;
	return estado;
}

Tarea::Tarea(unsigned long periodo):perido(periodo),tiempoAnterior(0){
	tiempoEjecucion= millis();
}
	
Tarea::esTiempo(Tarea &tarea){
	unsigned long tiempoActual = millis();
	if((tiempoActual - tarea.tiempoEjecucion )>= periodo){
		tiempoAnterior = tiempoActual;
		return true;
	}
	return false;	
}
