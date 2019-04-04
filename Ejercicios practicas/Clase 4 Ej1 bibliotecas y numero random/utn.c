#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/** en el c se incluyen las funciones
* se crean las funciones para obtener un float, un int y un char y devolverlo
*/

/**
*\brief pide y obtiene un float al usuario
*\param el mensaje a ser mostrado
*\return el float que ingreso el usuario
*/

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

/**
*\brief pide y obtiene un int al usuario
*\param el mensaje a mostrar
*\return el int ingresado por el usuario
*/

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
*\brief pide y obtiene un char al usuario
*\param el mensaje a ser mostrado
*recordar el comando de limpieza y cambiarlo si es windows o linux
*\return el char ingresado por el usuario
*/
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);// Win
    //fpurge(stdin); //Linux y OSx
    scanf("%c",&auxiliar);
    return auxiliar;
}


/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */

char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}
