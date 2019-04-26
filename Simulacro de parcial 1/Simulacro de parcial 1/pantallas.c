#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantallas.h"
#include "publicidad.h"
#include <string.h>
#include <ctype.h>


void pan_inicializarArrayPantallas (pantalla ePantallas[] ,int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        ePantallas[i].isEmpty = valor;
    }
}

int pan_buscarLugarLibre(pantalla ePantallas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(ePantallas[i].isEmpty == valor)
        {
            return i;
        }
    }
    return -1;
}



void MenuPantalla()
    {
    printf("\nMenu principal\n");
    printf("--------------\n");
    printf("1 - Alta de pantalla \n");
    printf("2 - Baja de pantalla \n");
    printf("3 - Modificacion\n");
    printf("4 - Salir\n");
    printf("Elija opcion: ");
    }



int isAlphaNumeric(char str[])
{
    int i = 0;
    int retorno = -1;

    while(str[i]!= '/0')
    {
        if((str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z') && (str[i]<'0' || str[i]>'9')  )
        {

            return 0;

        }
         i++;
    }
    return 1;
}


int getAlphaNumeric (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char resultado[])
{
    int retorno = -1;
    char bufferStr[4096];

    if( msg != NULL &&
        msgError != NULL &&
        minimo < maximo &&
        reintentos>=0 &&
        resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(!(isAlphaNumeric(bufferStr)))
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
            }
        }
    }
    return retorno;
}





int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString2(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(requestMessage, auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        auxFloat = atof(auxStr);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxFloat;
    }
}



int esNumericoFlotante(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}


void getString2(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}
