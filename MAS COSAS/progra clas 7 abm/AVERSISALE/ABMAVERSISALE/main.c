#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define CANTIDAD_CLIENTES 200

HOLA SOY ESTRUCTU

void inicializarArrayInt(int array[],int cantidaddeelementos,int valor);
int buscarPrimerOcurrencia(int array[],int cantidadeelementos,int valor);

int main()
{
    int arrayLegajos[CANTIDAD_CLIENTES];
    char arrayNombres[CANTIDAD_CLIENTES][50];
    char arrayApellidos[CANTIDAD_CLIENTES][50];

    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    char auxiliarNombreString[50];
    char auxiliarApellidoString[50];
    char auxiliarLegajoString[50];
    int auxiliarLegajoInt;

    char auxiliarNombreStringParaOrdenar[50];
    char auxiliarApellidoStringParaOrdenar[50];
    int auxiliarLegajoIntParaOrdenar;



    int opcion = 0;
    int i, j;


    inicializarArrayInt(arrayLegajos,CANTIDAD_CLIENTES,-1); /** le pongo -1 a todo para marcar que estan vacios*/


    while(opcion!= 8)
    {
        opcion=getInt("ELIJA UNA OPCION\n\n 1. Alta \n 2. Baja \n 3. Modificacion \n 4. Listar \n 5. Ordenar por nombre  \n 6. Ordenar por apellido \n 7. Ordenar por legajo \n 8. Salir \n\n");

        switch(opcion)
        {
        case 1:
            printf("Eligio Alta\n\n");

            indiceLugarLibre = (buscarPrimerOcurrencia(arrayLegajos,CANTIDAD_CLIENTES,-1));

            if(indiceLugarLibre == -1)
            {
                printf("No hay mas lugares libres\n");
            }

            if(!getStringLetras("Ingrese el nombre : ",auxiliarNombreString))
            {
                printf("El nombre debe ser solo de letras \n\n");
                break;
            }

            if(!getStringLetras("Ingrese el apellido: ",auxiliarApellidoString))
            {
                printf("El apellido debe ser solo letras \n\n");
                break;
            }

            if(!getStringNumeros("Ingrese el legajo: ",auxiliarLegajoString))
            {
                printf("El legajo debe ser solo numeros \n\n");
                break;
            }

            //printf("su legajo en string es : %s \n\n", auxiliarLegajoString);
            auxiliarLegajoInt= atoi(auxiliarLegajoString);
           // printf("su legajo en int es : %d \n\n ", auxiliarLegajoInt);

            if(buscarPrimerOcurrencia(arrayLegajos,CANTIDAD_CLIENTES,auxiliarLegajoInt)!= -1)
            {
                printf("El legajo ya existe\n\n");
                break;
            }

            strcpy(arrayNombres[indiceLugarLibre], auxiliarNombreString);
            strcpy(arrayApellidos[indiceLugarLibre],auxiliarApellidoString);
            arrayLegajos[indiceLugarLibre]=auxiliarLegajoInt;

            break;
        case 2:
            printf("Eligio baja\n\n");

            if (!getStringNumeros("Ingrese el legajo a dar de baja :  ",auxiliarLegajoString))
            {
                printf("El legajo debe ser numerico\n\n");
                break;
            }

            indiceResultadoBusqueda= buscarPrimerOcurrencia(arrayLegajos,CANTIDAD_CLIENTES,atoi(auxiliarLegajoString));

            if(indiceResultadoBusqueda==-1)
            {
                printf("Ese legajo no existe\n\n");
                break;
            }

            arrayLegajos[indiceResultadoBusqueda] = -1;
            printf("Legajo borrado exitosamente\n\n");

            break;
        case 3:
            printf("Eligio modificacion\n\n");


            if(!getStringNumeros("Ingrese el legajo a modificar : ",auxiliarLegajoString))
            {
                printf("El legajo debe ser numerico\n\n");
                break;
            }

            indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayLegajos,CANTIDAD_CLIENTES,atoi(auxiliarLegajoString));

            if(indiceResultadoBusqueda == -1)
            {
                printf("Ese legajo no existe\n\n");
                break;
            }

            if(!getStringLetras("Ingrese el nuevo nombre",auxiliarNombreString))
            {
                printf("El nombre debe ser letras\n");
                break;
            }
            if(!getStringLetras("Ingrese el nuevo apellido",auxiliarApellidoString))
            {
                printf("El apellido debe ser letras\n");
                break;
            }

            strcpy(arrayNombres[indiceResultadoBusqueda],auxiliarNombreString);
            strcpy(arrayApellidos[indiceResultadoBusqueda],auxiliarApellidoString);


            break;
        case 4:
            printf("Eligio listar \n\n");

                printf(" LEGAJO   -   NOMBRE   -   APELLIDO \n");
            for(i=0;i<CANTIDAD_CLIENTES;i++)
            {
                if(arrayLegajos[i]!= -1)
                    //
                   printf("\n   %d   -   %s   -   %s  \n", arrayLegajos[i], arrayNombres[i], arrayApellidos[i] );
                   // printf(" Legajo:  %d  -  Nombre:  %s  -  Apellido:  %s  \n", arrayLegajos[i],arrayNombres[i],arrayApellidos[i]);
            }


            break;
        case 5:
            printf("Eligio ordenar por Nombre \n\n");

            for(i=0; i < CANTIDAD_CLIENTES -1; i++)
            {
                if(arrayLegajos[i]== -1)
                {
                    continue;
                }
                for(j=i+1; j< CANTIDAD_CLIENTES;j++)
                {
                    if(arrayLegajos[j]== -1)
                    {
                        continue;
                    }

                    if(strcmp(arrayNombres[i],arrayNombres[j]) > 0 )
                    {
                        strcpy(auxiliarNombreStringParaOrdenar,arrayNombres[i]);
                        strcpy(arrayNombres[i],arrayNombres[j]);
                        strcpy(arrayNombres[j],auxiliarNombreStringParaOrdenar);

                        strcpy(auxiliarApellidoStringParaOrdenar,arrayApellidos[i]);
                        strcpy(arrayApellidos[i],arrayApellidos[j]);
                        strcpy(arrayApellidos[j],auxiliarApellidoStringParaOrdenar);

                        auxiliarLegajoIntParaOrdenar = arrayLegajos[i];
                        arrayLegajos[i] = arrayLegajos[j];
                        arrayLegajos[j] = auxiliarLegajoIntParaOrdenar;

                        //ME LO ESTA MOSTRANDO AL DERECHO O AL REVES DE LO QUE CARGUE
                        //la version del profesor hace lo mismo, asi que revisarla
                    }

                }



            }



            break;

        case 6:

            printf("Eligio ordenar por Apellido \n\n");

            for(i=0; i < CANTIDAD_CLIENTES -1; i++)
            {
                if(arrayLegajos[i]== -1)
                {
                    continue;
                }
                for(j=i+1; j< CANTIDAD_CLIENTES;j++)
                {
                    if(arrayLegajos[j]== -1)
                    {
                        continue;
                    }

                    if(strcmp(arrayApellidos[i],arrayApellidos[j]) > 0 )
                    {
                        strcpy(auxiliarNombreStringParaOrdenar,arrayNombres[i]);
                        strcpy(arrayNombres[i],arrayNombres[j]);
                        strcpy(arrayNombres[j],auxiliarNombreStringParaOrdenar);

                        strcpy(auxiliarApellidoStringParaOrdenar,arrayApellidos[i]);
                        strcpy(arrayApellidos[i],arrayApellidos[j]);
                        strcpy(arrayApellidos[j],auxiliarApellidoStringParaOrdenar);

                        auxiliarLegajoIntParaOrdenar = arrayLegajos[i];
                        arrayLegajos[i] = arrayLegajos[j];
                        arrayLegajos[j] = auxiliarLegajoIntParaOrdenar;

                        //ME LO ESTA MOSTRANDO AL DERECHO O AL REVES DE LO QUE CARGUE
                        //la version del profesor hace lo mismo, asi que revisarla
                    }

                }



            }
            break;

        case 7:

            printf("Eligio ordenar por Legajo \n\n");

            for(i=0; i < CANTIDAD_CLIENTES -1; i++)
            {
                if(arrayLegajos[i]== -1)
                {
                    continue;
                }
                for(j=i+1; j< CANTIDAD_CLIENTES;j++)
                {
                    if(arrayLegajos[j]== -1)
                    {
                        continue;
                    }

                    if(arrayLegajos[i] > arrayLegajos[j])
                    {
                        strcpy(auxiliarNombreStringParaOrdenar,arrayNombres[i]);
                        strcpy(arrayNombres[i],arrayNombres[j]);
                        strcpy(arrayNombres[j],auxiliarNombreStringParaOrdenar);

                        strcpy(auxiliarApellidoStringParaOrdenar,arrayApellidos[i]);
                        strcpy(arrayApellidos[i],arrayApellidos[j]);
                        strcpy(arrayApellidos[j],auxiliarApellidoStringParaOrdenar);

                        auxiliarLegajoIntParaOrdenar = arrayLegajos[i];
                        arrayLegajos[i] = arrayLegajos[j];
                        arrayLegajos[j] = auxiliarLegajoIntParaOrdenar;

                        //ME LO ESTA MOSTRANDO AL DERECHO O AL REVES DE LO QUE CARGUE
                        //la version del profesor hace lo mismo, asi que revisarla
                    }

                }



            }

            break;


        }
    }









    return 0;
}


void inicializarArrayInt(int array[],int cantidaddeelementos,int valor)
{
    int i=0;
    for(i=0;i<cantidaddeelementos;i++)
    {
        array[i]=valor;
    }
}


int buscarPrimerOcurrencia(int array[],int cantidadeelementos,int valor)
{
    int i=0;
    for(i=0;i<cantidadeelementos;i++)
    {
        if(array[i]==valor)
        {
            return i;
        }
    }

    return -1;
}
