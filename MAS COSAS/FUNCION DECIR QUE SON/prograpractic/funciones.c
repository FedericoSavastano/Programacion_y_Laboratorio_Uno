

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANTIDAD_CHAR 15


int mostrarMenu()
{

    char eleccion[CANTIDAD_CHAR];
    printf("1. Ingresar un dato\n");
    printf("2. decir que dato es\n");
    scanf("%s",eleccion);

    return *eleccion;
}

int decirQuepuso(char *eleccion)
{
    //printf("Lo que le esta llegando a la funcion decir quepuso es %s \n",eleccion);

    int i = 0;
    int validarNumeros = 0;
    int validarLetras = 0;
    int contadorGuion=0;
    int validarNumerosEnTelefono=0;
    //int validarAlfanumerico = 0;
    int validarTelefono = 0;
    int length;



    while(eleccion[i]!= '\0')
    {
        if((eleccion[i]>'a' || eleccion[i]<'z') && (eleccion[i]>'A' || eleccion[i]>'Z'))
        {
            validarLetras=1;
        }
         else if(eleccion[i]>'0'&& eleccion[i]<'9')
        {
            validarNumeros=1;

        }else if(eleccion[i]=='-')
        {
            contadorGuion++;
            //printf("el contador de guiones esta en %d \n",contadorGuion);
        }


        i++;
    }


    if(contadorGuion==1)
    {
        length = strlen(eleccion);

        if(eleccion=9)
        {
           validarTelefono=1;
        }


        if(validarTelefono==1)
        {
            validarNumeros=0;
            printf("Es un telefono\n");
        }
    }
    if(validarNumeros==1 && validarLetras==1)
    {
        validarLetras=0;
        validarNumeros=0;
        printf("Es alfanumerico\n");
    }


    if(validarNumeros==1)
    {
        printf("Son numeros\n");
    }
    if(validarLetras==1)
    {
        printf("Son letras\n");
    }


        return 0;
}
