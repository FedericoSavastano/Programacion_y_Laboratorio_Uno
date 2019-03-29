#include <stdio.h>
#include <stdlib.h>



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





float isValidFloat (float numero, float minimo, float maximo)
{
    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }
    return 0;
}

float getFloat (char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos, float *resultado)
{

    float buffer;
    int retorno = -1;
    if( mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo>= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%f", &buffer);
            if(isValidFloat(buffer, minimo, maximo))
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

