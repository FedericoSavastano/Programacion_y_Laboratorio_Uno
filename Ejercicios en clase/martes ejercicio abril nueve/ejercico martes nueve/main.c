#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_LETRAS_NOMBRE 30
#include "funcion.h"

int validarNombre (char nombreBuffer[]);

int main()
{
    char nombre [CANTIDAD_LETRAS_NOMBRE];
    char nombreBuffer [CANTIDAD_LETRAS_NOMBRE];

    printf("Ingrese su nombre \n");
    fgets(nombreBuffer,sizeof(nombreBuffer),stdin);

    validarNombre(nombreBuffer);
    strncpy(nombreBuffer,nombre, sizeof(nombre));
    printf("Su nombre es %s", nombre);



    //printf("Lo que toma despues de la funcion es %s",nombre);

    //strncpy(nombreBuffer,nombre, sizeof(nombre));

    //printf("Su nombre es %s", nombre);


    Lo que dijo el prof:









    return 0;
}



