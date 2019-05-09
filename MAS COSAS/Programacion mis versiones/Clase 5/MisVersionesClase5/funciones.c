#include <stdio.h>
#include <stdlib.h>


#define CANTIDAD 5


int getInt(char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);

    return numero;
}

int mostrarNumerosEIndice(int  arrayDeNumeros[])
{
    int indiceDeArray;


    for(indiceDeArray=0;indiceDeArray<CANTIDAD;indiceDeArray++)
    {
        printf("INDICE ---- NUMERO INGRESADO\n");
        printf("   %d   ----       %d        \n", indiceDeArray, arrayDeNumeros[indiceDeArray]);

    }

    return 0;
}


int modificarUnNumero (int arrayDeNumeros[])
{
    int indiceDeArray;
    int valorIngresado;


    indiceDeArray= getInt("Seleccione el indice a modificar\n");
    if(indiceDeArray<CANTIDAD)
    {
        valorIngresado = getInt("Ingrese el nuevo valor\n");
        arrayDeNumeros[indiceDeArray]= valorIngresado;
    }
    else{
        printf("Indice fuera de alcance!\n");
        }


    return 0;

}


int encontrarMaximo (int arrayDeNumeros[])
{

    int numeroMaximo;
    int indiceDeArray;

    numeroMaximo= arrayDeNumeros[0];
    //indiceDeArrays=0

    for(indiceDeArray=0;indiceDeArray<CANTIDAD;indiceDeArray++)
    {
        if(arrayDeNumeros[indiceDeArray]>numeroMaximo)
        {
            numeroMaximo=arrayDeNumeros[indiceDeArray];
        }
    }

    return numeroMaximo;


}


int encontrarMinimo (int arrayDeNumeros[])
{

    int numeroMinimo;
    int indiceDeArray;

    numeroMinimo = arrayDeNumeros[0];
    //indiceDeArrays=0

    for(indiceDeArray=0;indiceDeArray<CANTIDAD;indiceDeArray++)
    {
        if(numeroMinimo > arrayDeNumeros[indiceDeArray])
        {
            numeroMinimo=arrayDeNumeros[indiceDeArray];
        }
    }

    return numeroMinimo;


}

int sacarPromedio (int arrayDeNumeros[])
{

    int indiceDeArray;
    int acumulador=0;
    int promedio;

    for(indiceDeArray=0;indiceDeArray<CANTIDAD;indiceDeArray++)
    {
        acumulador = arrayDeNumeros[indiceDeArray] + acumulador;
    }

    promedio = acumulador / CANTIDAD;

    return promedio;
}


