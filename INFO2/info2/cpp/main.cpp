#include <iostream>
#include "practica.h"

using namespace std;

int main() {
    Temperatura temp;

    long celsius;
    cout << "Introduce la temperatura en Celsius: ";
    cin >> celsius;

    temp.setCelcius(celsius); // Establece la temperatura en Celsius
    temp.muestreo(); // Muestra las temperaturas en diferentes escalas

    return 0;
}

