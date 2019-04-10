#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_LETRAS_NOMBRE 30
#include "funcion.h"


int validarNombre(char nombreBuffer[])
{
    int i=0;

    while(nombreBuffer[i]!= '\0')
    {
        if((nombreBuffer[i]>='a') && (nombreBuffer[i]<= 'z') && (nombreBuffer[i]>= 'A') && (nombreBuffer<= 'Z') )
        {
            return 0;
        }

        i++;
    }
    return 1;
}
