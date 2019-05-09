#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDAD 5
int mostrarNumerosEIndice(int  arrayDeNumeros[]);
int modificarUnNumero (int arrayDeNumeros[]);
int encontrarMaximo (int arrayDeNumeros[]);
int encontrarMinimo (int arrayDeNumeros[]);
int sacarPromedio (int arrayDeNumeros[]);

int main()
{
    int arrayDeNumeros[CANTIDAD];
    int indiceDeArray;
    int valorIngresado;
    int opcion=0;
    int maximo;
    int minimo;
    int promedio;

    for(indiceDeArray=0;indiceDeArray<CANTIDAD;indiceDeArray++)
    {
        valorIngresado = getInt("Ingrese un numero\n");
        arrayDeNumeros[indiceDeArray]= valorIngresado;
    }

    printf("Elija una opcion: \n 1. Mostrar numeros e Indice\n 2. Modificar un numero \n 3. Encontrar el maximo, el minimo y el promedio \n 4. Salir\n");
    scanf("%d",&opcion);

    while(opcion!=4)
    {
        switch(opcion)
        {
        case 1:
            mostrarNumerosEIndice(arrayDeNumeros);
        break;

        case 2:
            modificarUnNumero (arrayDeNumeros);
        break;

        case 3:
            maximo = encontrarMaximo(arrayDeNumeros);
            minimo = encontrarMinimo (arrayDeNumeros);
            promedio = sacarPromedio (arrayDeNumeros);

            printf("El numero maximo es %d , el numero minimo es %d y el promedio es %d  \n", maximo, minimo, promedio);
        break;
        }

        printf("Elija una opcion: \n 1. Mostrar numeros e Indice \n 2. Modificar un numero \n 3. Encontrar el maximo, el minimo y el promedio \n 4. Salir \n");
        scanf("%d",&opcion);
    }

    return 0;
}
