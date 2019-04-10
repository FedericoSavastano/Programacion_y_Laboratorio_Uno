#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD_LETRAS_NOMBRE 30
#include "funcion.h"

//int validarNombre (char nombreBuffer[]);


int getString (char *msg,char *msgError, int minimo, int maximo, int reintentos, char *resultado);

int utn_isValidNumber(char *str);
int utn_getNumber(char *msg,char *msgError, int minimo, int maximo, int reintentos, int resultado);

/**
hay que tener una funcion que pida y otra que valide cualquier cosa, siempre dentro de esa va a haber un getstrin que toma, y eso manda a la funcion para que chequee la cosa especifica
*/


int main()
{


    /**

    Lo que dijo el prof:

    getString va a ser la funcion mas importante que veamos siempre
    porque todo lo ue haya ingresado el usuario lo vamos a mandar por ahi.
    si quiero tomar nombre, va a ser un getnombre y dentro un getstring
    si quiero tomar un mail, va a ser un get mail y dentro un get string
    vamos a tener que crear funciones de validacion de cada cosa que se ingresa

    la onda de esto es siempre tener una biblioteca de funciones y llamarlas para cuando las necesito

    recibe un string, lo tiene que recorrer y ver que tiene adentro

    la funcion devuelve verdero o falso

    despues se puede hacer una biblioteca especifica de validacion y despues otra de ingreso de datos etc,

    desarrollan la funcion de validacion, y la funcion devuelve que da verdadero
    para que la funcion pueda probar
    al de validacion le pongo verdadero, forzado inicializado
    testeo que mi funcion ande bien
    al de validacion le pongo falso, forzado inicializado
    testeo que tome que la info es falsa, anda bien.
    esto es para saber si me esta tomando bien las cosas y reaccionando bien
    despues de eso, me pongo a revisar que mi funcion anda como quiero










    char nombre [CANTIDAD_LETRAS_NOMBRE];
    char nombreBuffer [CANTIDAD_LETRAS_NOMBRE];

    printf("Ingrese su nombre \n");
    fgets(nombreBuffer,sizeof(nombreBuffer),stdin);

    validarNombre(nombreBuffer);
    strncpy(nombreBuffer,nombre, sizeof(nombre));
    printf("Su nombre es %s", nombre);



    //printf("Lo que toma despues de la funcion es %s",nombre);

    //strncpy(nombreBuffer,nombre, sizeof(nombre));

    //printf("Su nombre es %s", nombre);










*/

    return 0;
}


int utn_isValidNumber(char *str)
{
    return 1;
}


int getString (char *msg,char *msgError, int minimo, int maximo, int reintentos, char *resultado)
{
    strncpy ( resultado, "1234" ,5); //esto es un resultado que da mal a porposito para revisar


    return 0;
}


int utn_getNumber(char *msg,char *msgError, int minimo, int maximo, int reintentos, int resultado)
{

    int retorno = -1;

    cosa para controlar:
    los que son punteros que no sean null,
    que el maximo sea mas grande que el minimo
    un gran if donde valid todo

    char buffer [18];
    int bufferInt;

    if(msg != NULL )//FALTA VALIDAR
    {
        ME tiene que haber dado un numero el usuario
        y validar que este todo joya

        utn_GetString (msg, msgError, 1, 16, reintentos,buffer);
        //esto del min y max como son numeros les tire que puede ir por ahi,
        // me va a dar verdadero o falso si encontró un string que va joya

        entonces se pone:

        if( utn_GetString (msg, msgError, 1, 16, reintentos,buffer) ==0 )
        {

            if(utn_isValidNumber(buffer))
                bufferInt = atoi (buffer);
                if(bufferInt  >= minimo && bufferInt <= maximo)
                {
                    *resultado = bufferInt;
                    retorno = 0;
                }
        }
        else
        {
            poner un else no tiene sentido porque ya el retorno lo inicie en -1
        }
    }

    return retorno;

}



