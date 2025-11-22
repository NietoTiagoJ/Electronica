#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "./serialib/lib/serialib.h"
#include <unistd.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

// Función para obtener el último puerto conectado
std::string getLastConnectedPort() {
#if defined(_WIN32) || defined(_WIN64)
    std::vector<std::string> ports;
    for (int i = 1; i <= 256; ++i) {
        std::string portName = "\\\\.\\COM" + std::to_string(i);
        HANDLE hPort = CreateFileA(portName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

        if (hPort != INVALID_HANDLE_VALUE) {
            ports.push_back(portName);
            CloseHandle(hPort);
        }
    }
    return ports.empty() ? "" : ports.back(); // Devuelve el último puerto encontrado

#elif defined(__linux__) || defined(__APPLE__)
    std::string result;
    FILE* pipe = popen("ls -1t /dev/ttyUSB* /dev/ttyACM* 2>/dev/null | head -n 1", "r");
    if (!pipe) {
        throw std::runtime_error("Error al ejecutar el comando.");
    }
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    pclose(pipe);
    result.erase(result.find_last_not_of(" \n\r\t") + 1); // Eliminar saltos de línea
    return result;
#endif
    return ""; // Si no se reconoce el sistema operativo
}

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
    std::string serialPort;
    try {
        serialPort = getLastConnectedPort();
        if (serialPort.empty()) {
            std::cerr << "No se encontraron puertos seriales disponibles." << std::endl;
            return 1;
        }
        std::cout << "Último puerto conectado: " << serialPort << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    serialib serial;
    char errorOpening = serial.openDevice(serialPort.c_str(), 115200);

    // Verificación de conexión
    if (errorOpening != 1) {
        std::cerr << "Error al abrir el puerto serial." << std::endl;
        return errorOpening;
    }
    std::cout << "Conexión exitosa a " << serialPort << std::endl;

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

