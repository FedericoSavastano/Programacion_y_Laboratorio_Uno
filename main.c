#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_NUMEROS 5

int main()
{
    calcularMinimoYMaximo();
    //solicitaNumeroYSacaPromedio();
    //calcularPromedio();
    return 0;
}

int solicitaNumeroYSacaPromedio (void)
{
    int numeroIngresado;
    int acumulador=0;
    int contador=0;
    int promedio;

    for(contador=0;contador<CANTIDAD_NUMEROS;contador++)
    {
        printf("Ingrese un numero\n");
        scanf("%d" , &numeroIngresado);
        acumulador=acumulador+numeroIngresado;
    }

    //promedio= (float) acumulador/CANTIDAD_NUMEROS;
    printf("el promedio de sus numeros ingresados es :%.2f\n", (float) acumulador/CANTIDAD_NUMEROS);
    //tener cuidado de que si es F o D, entero o flotante
    return 0;
//essto es otra forma de hacerlo mas copado, lo del final

    if(calcularPromedio(acumulador,CANTIDAD_NUMEROS,&promedio)==0)
    {

        printf("el promedio es:%.2f",promedio);

    }
    else{
        printf("ERROR");
    }

    return 0;
}


int calcularPromedio (int acumulador , int cantidad , float *promedio) //el * es porque este valor de promedio hace referencia al promedio que usamos arriba, necesitamos que este valor sea el que asignamos en la otra funcion, no que se calcule aca.
{
    int retorno= -1; //este seria el valor que es un error
    if(cantidad > 0 && promedio != NULL)
    {
        *promedio=(float)acumulador/cantidad;
        retorno= 0; //este seria el valor que esta bien, por eso cuando se cumple la funcion y cuando funciona la aplicacion, el retorno da bien. recien ahi, esto es para chequearlo.
    }

    return retorno;
}

int calcularMinimoYMaximo ()
{
    int numeroIngresado;
    int numeroMaximo;
    int numeroMinimo;
    int numeroAuxiliar;
    int contador=0;

    printf("Ingrese un numero: \n");
    scanf("%d", &numeroAuxiliar);
    numeroMaximo=numeroAuxiliar;
    numeroMinimo=numeroAuxiliar;

    for(contador=0;contador<4;contador++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d", &numeroAuxiliar);

        if(numeroAuxiliar>numeroMaximo)
        {
            numeroMaximo=numeroAuxiliar;
        }
        if(numeroAuxiliar<numeroMinimo)
        {
            numeroMinimo=numeroAuxiliar;
        }

    }

    printf("El numero maximo es: %i\n", numeroMaximo);
    printf("El numero minimo es %i\n", numeroMinimo);
    return 0;


//esta es otra version loca
    int calcularMinimoYMaximoSegundaVersion(int valorIngresado,int*maximo;int*minimo)
    {

        int retorno = -1;
        if(*maximo!=NULL && *minimo!=NULL)
        {
            if(valorIngresado > *maximo)
            {
                *maximo= valorIngresado;
            }
            if(valorIngresado < *minimo)
            {
                *minimo= valorIngresado;
            }
            retorno=0;
        }

        return retorno;
    }
}
