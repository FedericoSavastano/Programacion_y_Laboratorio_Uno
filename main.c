#include <stdio.h>
#include <stdlib.h>
#include "utn.h"



char getChar (char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado);


int main()
{

    char numeroIngresado;
    int errorDeIngreso;
    errorDeIngreso= getChar("Ingrese el numero", "Error", 0, 50, 2, &numeroIngresado);
    if(errorDeIngreso)
    {
        printf("Se ha ingresado algo invalido");
    }else
    {
        printf("El caracter ingresado es: %c", numeroIngresado);
    }
    return 0;
}


int maindelfloat()
{

    float numeroIngresado;
    int errorDeIngreso;
    errorDeIngreso= getFloat("Ingrese el numero", "Error", 0, 50, 2, &numeroIngresado);
    if(errorDeIngreso)
    {
        printf("Se ha ingresado algo invalido");
    }else
    {
        printf("El numero ingresado es: %f", numeroIngresado);
    }
    return 0;
}

int elmainconint()
{
    int numeroIngresado;
    int errorDeIngreso;
    errorDeIngreso= getInt("Ingrese el numero", "Error", 0, 50, 2, &numeroIngresado);
    if(errorDeIngreso)
    {
        printf("Se ha ingresado algo invalido");
    }else
    {
        printf("El numero ingresado es: %d", numeroIngresado);
    }
    return 0;
}

int isValidInt(int numero, int minimo, int maximo)
{

    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }

        return 0;

}

int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int *resultado)
{

    int buffer; //aca guardo lo que el tipo ingreso
    int i;
    int retorno= -1;
    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        for(i=0;i<=reintentos;i++)
        {
            printf("%s", mensaje);
            scanf("%d", &buffer);
            if(isValidInt(buffer, minimo, maximo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }else
            {
                printf("%s", mensajeError);
            }
        }

    }

    return retorno; //0;
}




fflush(stdin); para windows
fpurge(stdin); para el resto


char isValidChar (char numero, char minimo, char maximo)
{
    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }
    return 0;
}

char getChar (char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado)
{
    char buffer;
    int retorno = -1;

    if(mensaje != NULL && mensajeError != NULL && maximo>= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%c", &buffer);
            if(isValidChar(buffer, minimo, maximo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }else
            {
                printf("%s", mensajeError);
            }
            reintentos--;
        }while(reintentos >= 0);
    }

    return retorno;
}

