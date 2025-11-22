#include <iostream>
#include <iomanip>
#include <sstream>
#include "./serialib/lib/serialib.h"
#include <unistd.h>

//#define SERIAL_PORT "/dev/ttyUSB0"


#if defined (_WIN32) || defined(_WIN64)
    // En Windows, usa la sintaxis extendida de "\\.\COMx" para el puerto serial.
    #define SERIAL_PORT "\\\\.\\COM6"  // Cambia COM6 por el puerto adecuado en tu sistema
#elif defined (__linux__) || defined(__APPLE__)
    // En Linux (Ubuntu) o macOS, usa "/dev/ttyACM0" o el puerto adecuado.
    #define SERIAL_PORT "/dev/ttyUSB0"  // O ajusta el puerto según tu sistema
#endif


// Función para enviar un comando por el puerto serial
void enviarComando(serialib &serial, const char* mensaje) {
    serial.writeString(mensaje);
    std::cout << "Comando enviado: " << mensaje << std::endl;
}

// Función para leer una respuesta del dispositivo serial
void leerRespuesta(serialib &serial) {
    char buffer[100];
    int resultado = serial.readString(buffer, '\n', 99, 2000);
    if (resultado > 0) {
        std::cout << "Respuesta recibida: " << buffer << std::endl;
    } else {
        std::cout << "Error o tiempo de espera agotado al leer respuesta." << std::endl;
    }
}

// Función para obtener la hora en formato "setFeedTime-HH-MM-SS"
std::string obtenerComandoSetHora() {
    int hh, mm, ss;
    std::cout << "Ingrese la hora (HH): ";
    std::cin >> hh;
    std::cout << "Ingrese los minutos (MM): ";
    std::cin >> mm;
    std::cout << "Ingrese los segundos (SS): ";
    std::cin >> ss;

    // Crear el comando en formato "setFeedTime-HH-MM-SS"
    std::ostringstream comando;
    comando << "setFeedTime-" 
            << std::setw(2) << std::setfill('0') << hh << "-"
            << std::setw(2) << std::setfill('0') << mm << "-"
            << std::setw(2) << std::setfill('0') << ss << "\n";
    
    return comando.str();
}

int main() {
    serialib serial;
    char errorOpening = serial.openDevice(SERIAL_PORT, 115200);

    // Verificación de conexión
    if (errorOpening != 1) {
        std::cerr << "Error al abrir el puerto serial." << std::endl;
        return errorOpening;
    }
    std::cout << "Conexión exitosa a " << SERIAL_PORT << std::endl;

    // Comando "forzar"
    const char forzar[] = "feedNow-\n";

    int opcion;
    do {
        // Menú principal
        std::cout << "\nMenú:\n";
        std::cout << "1. Forzar\n";
        std::cout << "2. Set Hora\n";
        std::cout << "3. Leer respuesta\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                enviarComando(serial, forzar);
                break;
            case 2: {
                std::string setHoraComando = obtenerComandoSetHora();
                enviarComando(serial, setHoraComando.c_str());
                break;
            }
            case 3:
                leerRespuesta(serial);
                break;
            case 0:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
                break;
        }
    } while (opcion != 0);

    // Cerrar el dispositivo serial
    serial.closeDevice();

    // Espera antes de cerrar la ventana
    std::cout << "Presione Enter para salir...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}

