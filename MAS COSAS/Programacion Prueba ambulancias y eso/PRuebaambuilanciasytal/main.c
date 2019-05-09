#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define CANTIDAD_ASOCIADOS 200
#define ESTADO_ASOCIADO_HABILITADO 1
#define ESTADO_ASOCIADO_INHABILITADO 0
#define ESTADO_ASOCIADO_LIBRE -1


int main()
{
   Asociado arrayAsociado[CANTIDAD_ASOCIADOS];

   int posicionLibre;
   int opcion=0;

   inicializarAsociados(arrayAsociado,CANTIDAD_ASOCIADOS);




   while(opcion!=6)
   {
       opcion=getIntEnRango(" ELIJA UNA OPCION \n 1. Alta \n 2. orto. \n 6. salir \n\n",6,1);

       switch(opcion)
       {
       case 1:
        printf("eligio hacer un alta \n\n");

        posicionLibre=encontrarPosicionLibre(arrayAsociado,CANTIDAD_ASOCIADOS);

        if(posicionLibre>=0)
        {
          printf("\nSe encontró un lugar libre\n");
          if(altaAsociado(arrayAsociado,CANTIDAD_ASOCIADOS,posicionLibre,"no, nada quever", 3))
          {
            printf("Se esta haciendo el alta, todo ok\n");
            printf("el nombre es: %s \n", arrayAsociado[posicionLibre].asociadoNombre);
          }else
          {
              printf("estas en cualquiera\n");
          }

        }
        else
        {
            printf("No hay mas lugares libres\n");
        }




        break;

       case 2:
        printf("Eligio la 2, que es orto \n\n");
        break;
       }
   }






/**
   printf("el nombre es: %s \n", arrayAsociado[posicionLibre].asociadoNombre);
   printf("Su ID es : %d \n", arrayAsociado[posicionLibre].asociadoID);
   printf("su estado es : %d \n",arrayAsociado[posicionLibre].asociadoEstado);

    //printf("el apellidos es: %s ", arrayAsociado[posicionLibre].asociadoApellido);
*/













   /*char loquedice[50];
    char numeros[22];
    int numeroInt;
    float numeroFloat;

    getString(loquedice,"introduzca lo que va a decir: ", "lo dijo mal");
    printf("Lo que dijo es: %s \n/",loquedice);

    numeroFloat=getFloat("pone un float: ");
    printf("El float quie pusiste es: %.2f \n\n ",numeroFloat);



    //getStringLetras(loquedice,"a ver si son letras","pusiste cualquiera",3);
    //printf("escribiste: %s ",loquedice);


    getStringLetras2("a ver si son letras: ",loquedice);
    printf("lo que puso es : %s \n",loquedice);


*/
//*/
    return 0;
}
