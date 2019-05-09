#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define CANTIDAD_CLIENTES 200

/**HOLA SOY ESTRUCTU*/

typedef struct{
    char nombre[50];
    char apellido[50];
    int legajo;


}Persona;

void inicializarArrayPersonas(Persona arrayPersonas[],int cantidaddeelementos,int valor);
int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantidadeelementos,int valor);

int main()
{
    /*
    int arrayLegajos[CANTIDAD_CLIENTES];
    char arrayNombres[CANTIDAD_CLIENTES][50];
    char arrayApellidos[CANTIDAD_CLIENTES][50];
    */

    Persona arrayPersonas[CANTIDAD_CLIENTES];
    //Persona auxiliarCliente;


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


    inicializarArrayPersonas(arrayPersonas,CANTIDAD_CLIENTES,-1); /** le pongo -1 a todo para marcar que estan vacios*/


    while(opcion!= 8)
    {
        opcion=getInt("ELIJA UNA OPCION\n\n 1. Alta \n 2. Baja \n 3. Modificacion \n 4. Listar \n 5. Ordenar por nombre  \n 6. Ordenar por apellido \n 7. Ordenar por legajo \n 8. Salir \n\n");

        switch(opcion)
        {
        case 1:
            printf("Eligio Alta\n\n");

            indiceLugarLibre = (buscarPrimerOcurrencia(arrayPersonas,CANTIDAD_CLIENTES,-1));

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

            if(buscarPrimerOcurrencia(arrayPersonas,CANTIDAD_CLIENTES,auxiliarLegajoInt)!= -1)
            {
                printf("El legajo ya existe\n\n");
                break;
            }

            strcpy(arrayPersonas[indiceLugarLibre].nombre, auxiliarNombreString);
            strcpy(arrayPersonas[indiceLugarLibre].apellido,auxiliarApellidoString);
            arrayPersonas[indiceLugarLibre].legajo=auxiliarLegajoInt;

            break;
        case 2:
            printf("Eligio baja\n\n");

            if (!getStringNumeros("Ingrese el legajo a dar de baja :  ",auxiliarLegajoString))
            {
                printf("El legajo debe ser numerico\n\n");
                break;
            }

            indiceResultadoBusqueda= buscarPrimerOcurrencia(arrayPersonas,CANTIDAD_CLIENTES,atoi(auxiliarLegajoString));

            if(indiceResultadoBusqueda==-1)
            {
                printf("Ese legajo no existe\n\n");
                break;
            }

            arrayPersonas[indiceResultadoBusqueda].legajo = -1;
            printf("Legajo borrado exitosamente\n\n");

            break;
        case 3:
            printf("Eligio modificacion\n\n");


            if(!getStringNumeros("Ingrese el legajo a modificar : ",auxiliarLegajoString))
            {
                printf("El legajo debe ser numerico\n\n");
                break;
            }

            indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayPersonas,CANTIDAD_CLIENTES,atoi(auxiliarLegajoString));

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

            strcpy(arrayPersonas[indiceResultadoBusqueda].nombre,auxiliarNombreString);
            strcpy(arrayPersonas[indiceResultadoBusqueda].apellido,auxiliarApellidoString);


            break;
        case 4:
            printf("Eligio listar \n\n");

                printf(" LEGAJO   -   NOMBRE   -   APELLIDO \n");
            for(i=0;i<CANTIDAD_CLIENTES;i++)
            {
                if(arrayPersonas[i].legajo!= -1)
                    //
                   printf("\n   %d   -   %s   -   %s  \n", arrayPersonas[i].legajo, arrayPersonas[i].nombre, arrayPersonas[i].apellido );
                   // printf(" Legajo:  %d  -  Nombre:  %s  -  Apellido:  %s  \n", arrayLegajos[i],arrayNombres[i],arrayApellidos[i]);
            }


            break;
        case 5:
            printf("Eligio ordenar por nombre \n\n");

            for(i=0; i < CANTIDAD_CLIENTES -1; i++)
            {
                if(arrayPersonas[i].legajo== -1)
                {
                    continue;
                }
                for(j=i+1; j< CANTIDAD_CLIENTES;j++)
                {
                    if(arrayPersonas[j].legajo== -1)
                    {
                        continue;
                    }

                    if(strcmp(arrayPersonas[i].nombre,arrayPersonas[j].nombre) > 0 )
                    {
                        strcpy(auxiliarNombreStringParaOrdenar,arrayPersonas[i].nombre);
                        strcpy(arrayPersonas[i].nombre,arrayPersonas[j].nombre);
                        strcpy(arrayPersonas[j].nombre,auxiliarNombreStringParaOrdenar);

                        strcpy(auxiliarApellidoStringParaOrdenar,arrayPersonas[i].apellido);
                        strcpy(arrayPersonas[i].apellido,arrayPersonas[j].apellido);
                        strcpy(arrayPersonas[j].apellido,auxiliarApellidoStringParaOrdenar);

                        auxiliarLegajoIntParaOrdenar = arrayPersonas[i].legajo;
                        arrayPersonas[i].legajo = arrayPersonas[j].legajo;
                        arrayPersonas[j].legajo = auxiliarLegajoIntParaOrdenar;

                    }
                }
            }
            break;

        case 6:

            printf("Eligio ordenar por apellido \n\n");

            for(i=0; i < CANTIDAD_CLIENTES -1; i++)
            {
                if(arrayPersonas[i].legajo== -1)
                {
                    continue;
                }
                for(j=i+1; j< CANTIDAD_CLIENTES;j++)
                {
                    if(arrayPersonas[j].legajo== -1)
                    {
                        continue;
                    }

                    if(strcmp(arrayPersonas[i].apellido,arrayPersonas[j].apellido) > 0 )
                    {
                        strcpy(auxiliarNombreStringParaOrdenar,arrayPersonas[i].nombre);
                        strcpy(arrayPersonas[i].nombre,arrayPersonas[j].nombre);
                        strcpy(arrayPersonas[j].nombre,auxiliarNombreStringParaOrdenar);

                        strcpy(auxiliarApellidoStringParaOrdenar,arrayPersonas[i].apellido);
                        strcpy(arrayPersonas[i].apellido,arrayPersonas[j].apellido);
                        strcpy(arrayPersonas[j].apellido,auxiliarApellidoStringParaOrdenar);

                        auxiliarLegajoIntParaOrdenar = arrayPersonas[i].legajo;
                        arrayPersonas[i].legajo = arrayPersonas[j].legajo;
                        arrayPersonas[j].legajo = auxiliarLegajoIntParaOrdenar;
                    }
                }

            }

            break;

        case 7:

            printf("Eligio ordenar por legajo \n\n");


            for(i=0; i < CANTIDAD_CLIENTES -1; i++)
            {
                if(arrayPersonas[i].legajo== -1)
                {
                    continue;
                }
                for(j=i+1; j< CANTIDAD_CLIENTES;j++)
                {
                    if(arrayPersonas[j].legajo== -1)
                    {
                        continue;
                    }

                    if(arrayPersonas[i].legajo > arrayPersonas[j].legajo)
                    {
                        strcpy(auxiliarNombreStringParaOrdenar,arrayPersonas[i].nombre);
                        strcpy(arrayPersonas[i].nombre,arrayPersonas[j].nombre);
                        strcpy(arrayPersonas[j].nombre,auxiliarNombreStringParaOrdenar);

                        strcpy(auxiliarApellidoStringParaOrdenar,arrayPersonas[i].apellido);
                        strcpy(arrayPersonas[i].apellido,arrayPersonas[j].apellido);
                        strcpy(arrayPersonas[j].apellido,auxiliarApellidoStringParaOrdenar);

                        auxiliarLegajoIntParaOrdenar = arrayPersonas[i].legajo;
                        arrayPersonas[i].legajo = arrayPersonas[j].legajo;
                        arrayPersonas[j].legajo = auxiliarLegajoIntParaOrdenar;
                    }
                }
            }
            break;

        }

    }









    return 0;
}


void inicializarArrayPersonas(Persona arrayPersonas[],int cantidaddeelementos,int valor)
{
    int i=0;
    for(i=0;i<cantidaddeelementos;i++)
    {
        arrayPersonas[i].legajo=valor;
    }
}


int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantidadeelementos,int valor)
{
    int i=0;
    for(i=0;i<cantidadeelementos;i++)
    {
        if(arrayPersonas[i].legajo==valor)
        {
            return i;
        }
    }

    return -1;
}
