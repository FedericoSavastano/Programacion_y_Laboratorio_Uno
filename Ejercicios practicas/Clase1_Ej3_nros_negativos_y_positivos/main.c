#include <stdio.h>
#include <stdlib.h>
//#define INGRESODENUMEROS 10
/*Solicite al usuario 10 números
Calcule cuántos son negativos y cuantos son positivos
Muestre por pantalla la cantidad de negativos y la cantidad de positivos

*/
int main()
{
    int numeroIngresado;
    int contador=0;
    int contadorNegativos=0;
    int contadorPositivos=0;

    //for(INGRESODENUMEROS=10;INGRESODENUMEROS<10;INGRESODENUMEROS--)
    //otra version que funciona es con un define arriba
    for(contador=0;contador<10;contador++)
    {
        printf("Ingrese un numero \n");
        scanf("%d",&numeroIngresado);
        if(numeroIngresado>0 && numeroIngresado!=0)
        {
            contadorPositivos++;
        }else if(numeroIngresado<0 && numeroIngresado!=0)
        {
            contadorNegativos++;
        }
    }
    printf("La cantidad de numeros positivos es %d y la de negativos es %d",contadorPositivos,contadorNegativos);
    return 0;
}
