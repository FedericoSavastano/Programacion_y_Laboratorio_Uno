

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/**
*\brief funcionan las tres funciones, piden y muestran numeros enteros, flotantes y un caracter
*
*
*/


int main()
{
    int numeroIngresado;
    float numeroComa;
    char palabraIngresada;

    printf("Hello world!\n");
    numeroIngresado=getInt("ingrese un numero entero");
    numeroComa=getFloat("Ingrese un numero con coma");
    palabraIngresada=getChar("Ingrese un texto");
    printf("Su numero es %d \n",numeroIngresado);
    printf("Su numero con coma es %f \n",numeroComa);
    printf("Su palabra es: %c \n",palabraIngresada);
    return 0;
}
