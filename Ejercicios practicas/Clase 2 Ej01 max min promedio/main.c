/******************************************************************
* Programa: Ejemplo Clase 2
*
* Objetivo:
*   -Realizar un programa que solicite cinco números e imprima por pantalla el
*    promedio, el máximo y el mínimo.
*
* Aspectos a destacar:
*   -El uso de bucles para pedir un número tras otro
*   -El uso de acumuladores, se tiene que guardar la suma para luego hacer
*    el promedio
*   -El uso del if para preguntar si el numero ingresado es mayor o menor
*    para guardar los máximos y mínimos
*
* Version: 0.1 del 29 diciembre de 2015
* Autor: Mauricio Dávila
* Revisión: Ernesto Gigliotti
*
* *******************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroBuffer;
    int maximo;
    int minimo;
    int promedio;
    int acumulador;
    int contador;

    printf("Ingrese un numero: \n");
    scanf("%d",&numeroBuffer);
    maximo= numeroBuffer;
    minimo= numeroBuffer;
    acumulador= numeroBuffer;

    for(contador=0;contador<4;contador++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d",&numeroBuffer);
        acumulador= acumulador+ numeroBuffer;

        if(maximo<numeroBuffer)
        {
            maximo= numeroBuffer;
        }
        if(minimo>numeroBuffer)
        {
            minimo= numeroBuffer;
        }
    }
    promedio=acumulador/contador;

    printf("El mayor es: %d y el menor es: %d \n",maximo,minimo);
    printf("El promedio es: %d \n", promedio);
    return 0;
}
