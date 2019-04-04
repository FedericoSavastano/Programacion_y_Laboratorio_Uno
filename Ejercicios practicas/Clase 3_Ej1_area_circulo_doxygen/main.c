/******************************************************************
* Programa: Ejemplo Clase 3
*
* Objetivo:
*   -Crear una función que permita ingresar un numero al usuario y lo retorne.
*   -Crear una función que reciba el radio de un círculo y retorne su área
*   -Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule
*    el área de un círculo cuyo radio es ingresado por el usuario
*   -Documentar las funciones al estilo Doxygen
*
* Aspectos a destacar:
*   -Declaración de funciones que devuelven y reciben valores
*   -Hacer notar que el uso de funciones evita el código repetido y ayuda a que
*    el mismo sea mas legible
*   -La función debería comenzar indicando el objetivo que persigue y el
*    significado de sus parámetros.
*
* Version: 0.1 del 29 diciembre de 2015
* Autor: Mauricio Dávila
* Revisión: Ernesto Gigliotti
*
* *******************************************************************/



#include <stdio.h>
#include <stdlib.h>


/**marco prototipos de funciones
*/
float ingresarNumero();
float calcularAreaCirculo (float radio);

int main()
{
    float numeroIngresado;
    float resultadoArea;

    numeroIngresado= ingresarNumero();
    resultadoArea= calcularAreaCirculo(numeroIngresado);
    printf("El area del circulo es %.2f ", resultadoArea);
    return 0;
}


/**
*\brief Solicito y obtengo un numero, en este caso el radio
*\return el numero ingresado
*
*/
float ingresarNumero()
{
    float numeroIngresado;
    printf("Ingrese el radio de su circulo \n");
    scanf("%f",&numeroIngresado);

    return numeroIngresado;
}

/**
*\brief con el numero ingresado, es el radio y con eso calculo el area
*\return el area del circulo
*/

float calcularAreaCirculo(float radioIngresado)
{
    float resultadoArea;
    resultadoArea= 3.14 * radioIngresado * radioIngresado;

    return resultadoArea;
}
