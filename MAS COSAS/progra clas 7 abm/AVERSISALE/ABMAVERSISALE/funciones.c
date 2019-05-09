#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int getInt (char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf("%s",input);
}


int getStringLetras (char mensaje[],char imput[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(imput,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros (char mensaje[],char imput[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(imput,aux);
        return 1;
    }

    return 0;
}
