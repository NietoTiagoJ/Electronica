/**
*@file libUtil.h
*@author Nieto Tiago
*@version 1.0
*@date 2024-08-30
*/

#include "libUtil.h"

/**
 *@brief Return the bit in position the nBit
 *@param *dato dato a cambiar
 *@param nBit posicin del bit a cambiar
*/
void setBit(unsigned int *dato, unsigned int nBit){
	*dato |= (1<< nBit);
}



/**
 *@brief Resetea bit a 0 segun nBit
 *@param direccion de memoria 
 *@param dato entero unsigned
*/
void resetBit(unsigned int *dato, unsigned int nBit){
	*dato &= (0<<nBit);
}


/**
 *@brief Obtiene el bit de la posicon
 *@param direccion de memoria
 *@param posicion del bit a obtener
 *@returns bit sin signo
 */
unsigned int getBit(unsigned int dato, unsigned int nBit){
	return (dato >> nBit) & 1U;
}


/**
 *@brief
 *@param
 *@param
 */
void toggleBit(unsigned int *dato, unsigned int nBit){
	*dato ^= (1<<nBit); 
}


/**
 *@brief Imprime los bits
 *@param numero que queres los bits
 */
void printfBin(unsigned int dato){
	printf("%d",dato);
}

