#include <stdio.h>

int ponerBitAlto(unsigned int *dato, int b)
{
 *dato |= (1<<b);

 if(dato == NULL || b > sizeof(int)){
	return -1;
 }else if((1<<b) !=(*dato>>b)){
	return 1;
 }	 
}

int main()
{
    unsigned int valor;
    int bit;

    printf("Ingrese un valor entero positivo: ");
    scanf("%u", &valor);
    printf("Ingrese el bit a modificar: ");
    scanf("%d", &bit);

    // completar
    if( ponerBitAlto(*valor,dato) != -1 )
        printf("El valor modificado es: %u\n", valor);
    else
        printf("Error!\n");

    return 0;
}
