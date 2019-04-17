/******************************************************************
* Programa: Ejemplo Clase 5
*
* Objetivo:
*   Solicitar al usuario 5 números, permitir listarlos por pantalla
*   indicando el máximo, el mínimo y el promedio
*   Permitir Modificar el valor de cualquiera de los números cargados
*   indicando el índice del mismo y su nuevo valor.
*
* Aspectos a destacar:
*   -Utilización de array
*
* Version: 0.1 del 29 diciembre de 2015
* Autor: Mauricio Dávila
* Revisión: Ernesto Gigliotti
*
* *******************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANTIDAD 5
//int getInt (char mensaje[]);
arreglar lo de max min y promerdio

int getMaxYMin (int *arrayDeNumeros, int *maximo, int *minimo);

int main()
{
    int arrayDeNumeros[CANTIDAD];
    int numeroIngresado;
    int indiceArray=0;
    int valorIngresado;
    int opcionMenu = 0;
    int maximoIngresado;
    int minimoIngresado;

    printf("Hola");

    for(indiceArray=0;indiceArray<CANTIDAD;indiceArray++)
    {
        numeroIngresado=getInt("Ingrese un numero\n");
        arrayDeNumeros[indiceArray]=numeroIngresado;

    }

    getMaxYMin(arrayDeNumeros,&maximoIngresado,&minimoIngresado);

    while(opcionMenu!=3)
    {
        opcionMenu=getInt("\n Opcion 1: Mostrar \n Opcion 2: Modificar \n Opcion 3: Salir \n");
        switch(opcionMenu)
        {
            case 1:
                printf("\n \n INDICE  -  VALOR\n");
                for(indiceArray = 0;indiceArray < CANTIDAD ;indiceArray++)
                {
                    printf(" %d   -   %d  \n",indiceArray,arrayDeNumeros[indiceArray]);
                    printf("El numero maximo es %d y el minimo es %d", maximoIngresado, minimoIngresado);
                }
            break;

            case 2:
                indiceArray= getInt("\n Ingrese el indice a modificar: \n ");
                if(indiceArray >= 0 && indiceArray<CANTIDAD)
                {
                    valorIngresado=getInt("Ingrese el nuevo valor: \n");
                    arrayDeNumeros[indiceArray]= valorIngresado;
                }else
                {
                    printf("\n El indice ingresado esta fuera de rango! \n");
                }
            break;
        }
    }



    int getMaxYMin (int *arrayDeNumeros, int *maximo, int *minimo)
    {
    int i;
    *maximo = *arrayDeNumeros;
    *minimo = *arrayDeNumeros;

    for(i=1;i<CANTIDAD;i++)
    {
        if(*(arrayDeNumeros+i)>*maximo)
            {
                *maximo= *(arrayDeNumeros+i);
            }
        if(*(arrayDeNumeros+i)<*minimo)
            {
                *minimo = *(arrayDeNumeros+i);
            }
    }
    return 0;
    }



    return 0;
}

