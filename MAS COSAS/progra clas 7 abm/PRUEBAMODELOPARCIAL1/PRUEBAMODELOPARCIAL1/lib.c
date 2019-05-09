

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define CANTIDAD_ASOCIADOS 200
#define CANTIDAD_LLAMADAS 200
#define ESTADO_ASOCIADO_HABILITADO 1
#define ESTADO_ASOCIADO_INHABILITADO 0
#define ESTADO_ASOCIADO_LIBRE -1
static int generarID(void);

int getInt (char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

void inicializarArrayAsociados (Asociado arrayAsociados[],int cantidaddeelementos, int valor)
{
    int i=0;
    for (i=0;i<CANTIDAD_ASOCIADOS;i++)
    {
        arrayAsociados[i].estado=valor;
    }
}


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

int esAlfanumerico (char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if((str[i]!=' ')&&(str[i]!='.')&&(str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z')
           &&(str[i]<'0' || str[i]>'9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
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

int getStringAlfaNumerico (char mensaje[],char imput[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esAlfanumerico(aux))
    {
        strcpy(imput,aux);
        return 1;
    }

    return 0;
}

int buscarLugarLibre(Asociado arrayAsociados[])
{
     int i=0;
     for (i=0;i<CANTIDAD_ASOCIADOS;i++)
            {
                if(arrayAsociados[i].estado=ESTADO_ASOCIADO_LIBRE)
                {
                    return i;
                }
            }
        return 0;

}


int generarAsociado(Asociado arrayAsociados[])
{

    char bufferNombre[250];
    char bufferApellido[250];
    int bufferDni[15];
    int bufferEdad[3];
    int indiceLibre;

    if(!getStringLetras("Ingrese el nombre: ",bufferNombre))
    {
        printf("El nombre debe ser solo letras");
    }else if(!getStringLetras("Ingrese el apellido: ", bufferApellido))
    {
        printf("El apellido debe ser solo letras");
    }else if(!getStringNumeros("Ingrese el DNI: ", bufferDni))
    {
        printf("El dni deben ser solo numeros");
    }
    else if(!getStringNumeros("Ingrese la edad: ", bufferEdad))
    {
        printf("La edad deben ser solo numeros");
    }

        indiceLibre=buscarLugarLibre(arrayAsociados);

        printf("El indice libre encontrado es : %d", indiceLibre);

        strcpy(arrayAsociados[indiceLibre].nombreAsociado,bufferNombre);
        strcpy(arrayAsociados[indiceLibre].apellidoAsociado,bufferApellido);
        arrayAsociados[indiceLibre].estado=ESTADO_ASOCIADO_HABILITADO;

        printf("el nombre guardado es: %s \n",arrayAsociados[indiceLibre].nombreAsociado);
        printf("el apellido guardado es: %s \n",arrayAsociados[indiceLibre].apellidoAsociado);




}

