/******************************************************************
* Programa: Ejemplo Clase 2
*
* Objetivo:
*   -Realizar un programa que solicite cinco n�meros e imprima por pantalla el
*    promedio, el m�ximo y el m�nimo.
*
* Aspectos a destacar:
*   -El uso de bucles para pedir un n�mero tras otro
*   -El uso de acumuladores, se tiene que guardar la suma para luego hacer
*    el promedio
*   -El uso del if para preguntar si el numero ingresado es mayor o menor
*    para guardar los m�ximos y m�nimos
*
* Version: 0.1 del 29 diciembre de 2015
* Autor: Mauricio D�vila
* Revisi�n: Ernesto Gigliotti
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
