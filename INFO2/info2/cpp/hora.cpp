#include <iostream>
#include <chrono>//Obtencion de tiempo y fechas
#include <ctime>//Conversion a formatos legibles

#include "hora.h"
using namespace std;

Hora::Hora(){ //Constructor establece predeterminadamente los valores en 0
	hora=minutos=segundos=0;
}

void Hora::set(int h, int m, int s){//funcion miembro para establecer valores
	hora = h;
	minutos = m;
	segundos = s;
}

void Hora::setHora(int h){
	hora = h;
}

void Hora::setMinutos(int m){
	minutos = m;
}

void Hora::setSegundos(int s){
	segundos = s;
}	

void Hora::get(){ //Funcion miembro para obterner valores
 	cout <<hora<<':'<<minutos<<':'<<segundos<<endl;
}

void Hora::setCurrentTime(){
	//Obtener el tiempo actual
	auto now = chrono::system_clock::now();
	
	//Convertir a time_t
	time_t now_time = chrono::system_clock::to_time_t(now);

	tm* local_time = localtime(&now_time);

	//Establece valores 
	hora = local_time->tm_hour;
	minutos = local_time->tm_min;
	segundos = local_t
