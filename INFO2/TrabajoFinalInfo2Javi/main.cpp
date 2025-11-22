#include <iostream>
#include "./serialib/lib/serialib.h"
#include <unistd.h>

#define SERIAL_PORT "/dev/ttyUSB0"

int main() {
	serialib serial;
	
	char errorOpening = serial.openDevice(SERIAL_PORT, 115200);

	if (errorOpening!=1) return errorOpening;
    	printf ("Successful connection to %s\n",SERIAL_PORT);	
    
	char forzar[15] = "feedNow-";
     	char setHora[15] = "setFeedTime\n";	
  	char guion[15] = "-\n";

	serial.writeString(forzar);
    	printf ("String sent: %s", forzar);



    return 0;
}

