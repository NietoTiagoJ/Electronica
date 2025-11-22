#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define SERIAL_PORT "/dev/ttyUSB0"

int main() {
    int serialPort = open(SERIAL_PORT, O_RDWR);

    if (serialPort < 0) {
        std::cerr << "Error al abrir el puerto serial." << std::endl;
        return -1;
    }
    std::cout << "Conexión establecida con ESP32 en el puerto " << SERIAL_PORT << std::endl;

    struct termios tty;
    if (tcgetattr(serialPort, &tty) != 0) {
        std::cerr << "Error al obtener la configuración del puerto." << std::endl;
        close(serialPort);
        return -1;
    }

    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag |= CREAD | CLOCAL;
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    tty.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    if (tcsetattr(serialPort, TCSANOW, &tty) != 0) {
        std::cerr << "Error al establecer los parámetros del puerto." << std::endl;
        close(serialPort);
        return -1;
    }

    uint8_t data[] = {0xFE, 12, 34, 56, 78, 0xFF};

    std::cout << "Intentando enviar la estructura de datos: ";
    for (size_t i = 0; i < sizeof(data); ++i) {
        if (write(serialPort, &data[i], 1) < 0) {
            std::cerr << "Error al enviar el byte " << i << "." << std::endl;
            close(serialPort);
            return -1;
        }
        usleep(10000);  // Retardo de 10 ms entre bytes
        std::cout << "0x" << std::hex << (int)data[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Datos enviados correctamente." << std::endl;

    // Leer los datos reenviados por la ESP32
    unsigned char readBuffer[256];
    int bytesRead = read(serialPort, readBuffer, sizeof(readBuffer));

    if (bytesRead > 0) {
        std::cout << "Datos recibidos: " << std::endl;
        for (int i = 0; i < bytesRead; i++) {
            std::cout << "0x" << std::hex << (int)readBuffer[i] << " ";
        }
        std::cout << std::endl;

        // Procesar los datos recibidos
        if (readBuffer[0] == 0xFE && readBuffer[bytesRead - 1] == 0xFF) {
            uint8_t hora = readBuffer[1];
            uint8_t minuto = readBuffer[2];
            uint8_t segundo = readBuffer[3];
            uint8_t cantidad = readBuffer[4];

            std::cout << "Mensaje procesado:" << std::endl;
            std::cout << "Hora: " << (int)hora << std::endl;
            std::cout << "Minuto: " << (int)minuto << std::endl;
            std::cout << "Segundo: " << (int)segundo << std::endl;
            std::cout << "Cantidad: " << (int)cantidad << std::endl;
        } else {
            std::cout << "Formato de mensaje incorrecto." << std::endl;
        }
    } else {
        std::cout << "No se recibieron datos del ESP32." << std::endl;
    }

    close(serialPort);
    return 0;
}

