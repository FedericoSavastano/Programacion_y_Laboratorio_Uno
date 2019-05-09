#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANTIDAD_CHAR 15

int main()
{

    int pruebanumero;

    char eleccion[CANTIDAD_CHAR];
    printf("Ingrese su dato\n");
    scanf("%s",eleccion);


    decirQuepuso(eleccion);


    return 0;
}
