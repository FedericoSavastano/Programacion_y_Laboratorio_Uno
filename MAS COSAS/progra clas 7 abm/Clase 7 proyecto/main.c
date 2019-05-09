#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANTIDAD_CLIENTES 200

void inicializarArrayInt(int array[], int cantidad_de_elementos, int valor);
int buscarPrimeraOcurrencia(int array[], int cantidad_de_elementos, int valor);


int main()
{
    //**arrays paralelos donde se guarda la informacion//
    char arrayNombres[CANTIDAD_CLIENTES][50];
    char arrayApellidos[CANTIDAD_CLIENTES][50];
    int arrayLegajos[CANTIDAD_CLIENTES];
    //_________________

    char auxiliarNombreStr[50];
    char auxiliarApellidoStr[50];
    char auxiliarLegajoStr[50];
    int auxiliarLegajo;

    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int opcion = 0;

    int i,j;


    inicializarArrayInt(arrayLegajos,CANTIDAD_CLIENTES,-1);


    while(opcion != 6)
    {
        opcion = getInt("\n\n\n 1 - ALTA \n 2 - BAJA \n 3 - MODIFICACION \n 4 - LISTAR \n 5 - ORDENAR \n 6 - SALIR\n\n\n");
        switch(opcion)
        {
        case 1:
            indiceLugarLibre = buscarPrimeraOcurrencia(arrayLegajos, CANTIDAD_CLIENTES,-1);
            if(indiceLugarLibre==-1)
            {
                printf("\n\n NO QUEDAN LUGARES LIBRES !\n\n");
                break;
            }

            printf("\nALTA\n");

            if(!getStringLetras("Ingrese el nombre: ", auxiliarNombreStr))
            {
                printf("El nombre debe estar compuesto solo de letras\n");
                break;
            }

            if(!getStringLetras("Ingrese el apellido: ",auxiliarApellidoStr))
            {
                printf("El apellido debe estar compuesto solo de letras\n");
                break;
            }

            if(!getStringNumeros("Ingrese el legajo: ",auxiliarLegajoStr))
            {
                printf("El legajo debe ser numerico\n");
                break;
            }

            auxiliarLegajo=atoi(auxiliarLegajoStr);

            if(buscarPrimeraOcurrencia(arrayLegajos,CANTIDAD_CLIENTES,auxiliarLegajo)!= -1)
            {
                printf("\n El legajo ya existe! \n");
                break;
            }


            strcpy(arrayNombres[indiceLugarLibre],auxiliarNombreStr);
            strcpy(arrayApellidos[indiceLugarLibre],auxiliarApellidoStr);
            arrayLegajos[indiceLugarLibre]=auxiliarLegajo;

            break;

        case 2:
            printf("\nBAJA\n");
            if(!getStringNumeros("Ingrese el legajo a dar de baja: ",auxiliarLegajoStr))
            {
                printf("El legajo debe ser numerico\n");
                break;
            }

            indiceResultadoBusqueda = buscarPrimeraOcurrencia(arrayLegajos,CANTIDAD_CLIENTES,atoi(auxiliarLegajoStr));

            if(indiceResultadoBusqueda == -1)
            {
                printf("\n\n No se encuentra ese legajo\n\n");
                break;
            }

            arrayLegajos[indiceResultadoBusqueda] = -1;
            break;

        case 3:
            printf("\nMODIFICACION\n");

            if (!getStringNumeros("Ingrese el legajo a modificar: ",auxiliarLegajoStr ))
            {
                printf("El legajo debe ser numerico\n");
                break;
            }

            indiceResultadoBusqueda = buscarPrimeraOcurrencia(arrayLegajos,CANTIDAD_CLIENTES,atoi(auxiliarLegajoStr));

            if(indiceResultadoBusqueda == -1)
            {
                printf("\nNo se encuentra ese legajo\n");
                break;
            }

            if(!getStringLetras("Ingrese el nombre",auxiliarNombreStr))
            {
                printf("\nEl nombre debe estar compuesto solo por letras\n");
                break;
            }

            if(!getStringLetras("Ingrese el apellido",auxiliarApellidoStr))
            {
                printf("\nEl apellido debe estar compuesto solo por letras\n");
                break;
            }

            strcpy(arrayNombres[indiceResultadoBusqueda],auxiliarNombreStr);
            strcpy(arrayApellidos[indiceResultadoBusqueda],auxiliarApellidoStr);

            break;

        case 4:
            printf("\n LISTAR \n");
            for(i=0;i<CANTIDAD_CLIENTES;i++)
            {
                if(arrayLegajos[i]!= -1)
                {
                    printf("\n %s  -  %s  -  %d ",arrayNombres[i],arrayApellidos[i],arrayLegajos[i]);
                }
            }
            break;

        case 5:
            printf("\n ORDENAR \n");

            for(i=0;i<CANTIDAD_CLIENTES -1;i++)
            {
               if(arrayLegajos[i]== -1)
               {
                   continue;
               }
               for(j=i+1; j< CANTIDAD_CLIENTES;j++)
               {
                   if(arrayLegajos[j]==-1)
                   {
                       continue;
                   }
               }

               if(strcmp(arrayApellidos[i],arrayApellidos[j]))
               {
                   strcpy(auxiliarNombreStr,arrayNombres[i]);
                   strcpy(arrayNombres[i],arrayNombres[j]);
                   strcpy(arrayNombres[j],auxiliarNombreStr);

                   strcpy(auxiliarApellidoStr,arrayApellidos[i]);
                   strcpy(arrayApellidos[i],arrayApellidos[j]);
                   strcpy(arrayApellidos[j],auxiliarApellidoStr);

                   auxiliarLegajo = arrayLegajos[i];
                   arrayLegajos[i] = arrayLegajos [j];
                   arrayLegajos[j] =auxiliarLegajo;
               }

            }

        }//switch
    }//while

    return 0;
}




/**
 * \brief Inicializa un array de enteros con el valor recibido
 * \param array Es el array a ser inicializado
 * \param cantidad_de_elementos Indica la logitud del array
 * \param valor Es el valor que sera cargado en cada posicion
 * \return -
 *
 */


    void inicializarArrayInt(int array[],int cantidad_de_elementos,int valor)
    {
        int i;
        for(i=0;i<cantidad_de_elementos;i++)
        {
            array[i]=valor;
        }
    }



/**
 * \brief Busca la primer ocurrencia de un valor en un array de enteros
 * \param array Es el array en el cual buscar
 * \param cantidad_de_elementos Indica la logitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */


    int buscarPrimeraOcurrencia(int array[],int cantidad_de_elementos,int valor)
    {
        int i;
        for(i=0;i<cantidad_de_elementos;i++)
        {
            if(array[i]==valor)
            {
                return i;
            }
        }

        return -1;
    }



