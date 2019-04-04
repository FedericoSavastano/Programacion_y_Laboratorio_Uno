#include <stdio.h>
#include <stdlib.h>

/*
Limpie la pantalla
Solicite dos valores numéricos al usuario distintos de cero
Asigne a las variables numero1 y numero2 los valores obtenidos
Realice la resta de dichas variables
Muestre el resultado por pantalla
Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor
Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero
*/

int main()
{
    int numeroUno;
    int numeroDos;
    int resta;
    char mensaje;

    do{
        printf("Ingrese el primer numero: \n");
        scanf("%d",&numeroUno);
        if(numeroUno==0)
        {
            printf("Ingrese el primer numero, que sea mayor a cero: \n");
            scanf("%d",&numeroUno);
        }
    }while(numeroUno==0);

    do{
        printf("Ingrese el segundo numero: \n");
        scanf("%d",&numeroDos);
        if(numeroDos==0)
        {
            printf("Ingrese el segundo numero, que sea mayor a cero: \n");
            scanf("%d",&numeroDos);
        }
    }while(numeroDos==0);

    resta= numeroUno - numeroDos;
    printf("El resultado de la resta es %d \n",resta);

    if(resta>0)
    {
        printf("El resultado es positivo");
    }else{
        printf("El resultado es negativo");
    }

    return 0;
}
