#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantallas.h"
#include "publicidad.h"
#include <string.h>
#include <ctype.h>
#define CANTIDAD_CHAR_NOMBRE 50
#define CANTIDAD_CHAR_MINIMO 2
#define CANTIDAD_CHAR_MAXIMO 15
#define CANTIDAD_CHAR_DIRECCION 128
#define CANTIDAD_PANTALLAS 5
#define VALOR_ESPACIO_LIBRE -1
#define OPCION_MINIMA 1
#define OPCION_MAXIMA 4
#define REINTENTOS 2
#define PRECIO_MINIMO 50
#define PRECIO_MAXIMO 1000
#define OPCION_TIPO_MIN 1
#define OPCION_TIPO_MAX 3



int main()
{


    pantalla ePantallas[CANTIDAD_PANTALLAS];

    char auxNombre[CANTIDAD_CHAR_NOMBRE];
    char auxDireccion[CANTIDAD_CHAR_DIRECCION];
    char auxPrecio[CANTIDAD_CHAR_MAXIMO];
    char auxTipo[4];
    char auxOpcion[2];
    int opcion;
    int auxEmpty;

    pan_inicializarArrayPantallas(ePantallas,CANTIDAD_PANTALLAS,VALOR_ESPACIO_LIBRE);

    do
    {
        MenuPantalla();
        getOption("Ingrese una opción","Opcion no valida",OPCION_MINIMA,OPCION_MAXIMA,REINTENTOS,auxOpcion);
        opcion = atoi(auxOpcion);

        switch(opcion)
        {
            case 1:


            auxEmpty = pan_buscarLugarLibre(ePantallas,CANTIDAD_PANTALLAS,VALOR_ESPACIO_LIBRE);
            if(auxEmpty== -1)
            {
                printf("No hay mas pantallas disponibles\n");
                break;
            }
            ePantallas[auxEmpty].isEmpty = auxEmpty;


            if(getName("Ingrese nombre\n","nombre no valido\n",CANTIDAD_CHAR_MINIMO,CANTIDAD_CHAR_MAXIMO,REINTENTOS,auxNombre))
            {
                printf("El nombre debe contener solo letras\n");
                break;
            }

            if(getAlphaNumeric("Ingrese dirección\n","Dirección no valida\n",CANTIDAD_CHAR_MINIMO,CANTIDAD_CHAR_MAXIMO,REINTENTOS,auxDireccion))
            {
                printf("La dirección no es valida\n");
                break;
            }

            if(getNumber("ingrese el precio\n","precio no valido", PRECIO_MINIMO, PRECIO_MAXIMO, REINTENTOS, auxPrecio))
            {
                printf("El Precio ingresado no es valido\n");
                break;
            }

            printf("el precio es %s",auxPrecio);

            do{
                getOption("Seleccione 1. para LCD o 2. para LED\n","Error, ingrese 1 o 2\n",OPCION_TIPO_MIN, OPCION_TIPO_MAX, REINTENTOS, auxTipo)

            }while(opcion!=3);











            printf("Esta todo bien\n");
            break;
        }

    }while(opcion!=4);




  return 0;
}
