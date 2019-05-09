#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define CANTIDAD_ASOCIADOS 200
#define CANTIDAD_LLAMADAS 200
#define ESTADO_ASOCIADO_HABILITADO 1
#define ESTADO_ASOCIADO_INHABILITADO 0
#define ESTADO_ASOCIADO_LIBRE -1

static int generarID (void);

int main()
{
    Asociado arrayAsociados[CANTIDAD_ASOCIADOS];
    Llamada arrayLlamada[CANTIDAD_LLAMADAS];

    inicializarArrayAsociados(arrayAsociados,CANTIDAD_ASOCIADOS,ESTADO_ASOCIADO_LIBRE);

    //printf("%d",arrayAsociados[1].estado);

    int opcion = 0;
    while(opcion!=4)
    {
        opcion=getInt("ELIJA UNA OPCION \n\n\n 1. Alta \n 2. Baja \n 3. Modificacion \n 4. Salir\n\n ");

        switch(opcion)
        {
        case 1:
            printf("\n Eligio Alta \n");
            int i=0;
                        /*

                        BUSCAR UNA POSICION LIBRE Y A ESA LLAMARLA INDICE Y MANDARSELO A LA FUNCION DE CRAR USUARIO
            for(i=0;i<5;i++)
            {
                arrayAsociados[i].idAsociado=generarID();

                printf("los numeros de id asociados que esta generando son : %d \n" ,arrayAsociados[i].idAsociado);
            }
                */
            generarAsociado(arrayAsociados);


                        /**ok con esto le asigno ID a esa posicion*/



            break;

        case 2:
            for(i=0;i<CANTIDAD_ASOCIADOS;i++)
            {
                if(arrayAsociados[i].estado != ESTADO_ASOCIADO_LIBRE)
                {
                    //printf("El nombre es %s")
                    printf("el nombre guardado es: %s \n",arrayAsociados[i].nombreAsociado);
                    printf("el apellido guardado es: %s \n",arrayAsociados[i].apellidoAsociado);
                }
            }
            break;


        }
    }





    return 0;
}


static int generarID(void)
{
    static int iDAsociado=0;
    return iDAsociado++;
}


