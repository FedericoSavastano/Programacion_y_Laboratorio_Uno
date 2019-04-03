#include <stdio.h>
#include <stdlib.h>

/*Escribir  un programa que realice las siguientes acciones
1. Limpie la pantalla
2. Asigne a 2 variables numero1 y numero2 valores distintos de cero
3. Efectœe el producto de dichas variables
4. Muestre el resultado pos pantalla
Obtenga el cuadrado de numero1 y lo muestre par pantalla*/

int main()
{
    int numeroUno;
    int numeroDos;
    int producto;
    int cuadradoNumeroUno;

    do{
        printf("Ingrese el primer numero: \n");
        scanf("%d",&numeroUno);
        if(numeroUno==0)
        {
            printf("Ingrese el primer numero, pero que sea mayor a cero: \n");
            scanf("%d",&numeroUno);
        }
    }while(numeroUno==0);

    do{
        printf("Ingrese el segundo numero: \n");
        scanf("%d",&numeroDos);
        if(numeroDos==0)
        {
            printf("Ingrese el segundo numero, pero que sea mayor a cero: \n");
            scanf("%d",&numeroDos);
        }
    }while(numeroDos==0);

    producto= numeroUno * numeroDos;
    cuadradoNumeroUno= numeroUno * numeroUno;

    printf("El producto de sus dos numeros es: %d \n",producto);
    printf("El cuadrado de su primer numero es: %d \n",cuadradoNumeroUno);

    return 0;
}
