#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_ALUMNOS 55 //**esto va de 0 a 54

int main()
{
    //**Es mas conveniente ponerle un define arriba para definir la cantidad, que ponerle el numero ahi porque complica la lectura del codigo
    //**en el momento de cambiarlo y mientras lo estoy trabajando conviene ponerle un numero bajo para hacerlo facil y al final le pongo el numero que va arriba
    int arraydeEdades[CANTIDAD_ALUMNOS];
    float arraydePesos[CANTIDAD_ALUMNOS];
    char arrayLetraNombre[CANTIDAD_ALUMNOS];


    int* pEdades //**es un puntero y lo declaro y lo guardo asi
    int bufferEdad;
    int aEdades [CANTIDAD_ALUMNOS]; //** el tipo de puntero y el tipo de array tiene que ser lo mismo siempre , porque el movimiento tiene que ser el mismo para coincidir bien. no se mueve lo mismo un int que un float que un char, etc.
    aEdades[100] = 22; //** al lugar 100 le asigno el valor 22
    bufferEdad= aEdades[100]; //en el buffer guardé lo que hay en la posicion 100
    pEdades = aEdades; //** el caso tipico de obtener el primer lugar en la memoria
    pEdades = &aEdades[0]; //**si quiero obtener una en particular si le pongo un nmumero

    pEdades = aEdades;
    pEdades[88] = 11;
    *(pEdades+88) = 11;  //en la posicion que tenias el puntero mas 88 le quiero poner el 11 , esto lo hace bien


    bufferEdad = *(pEdades+188); // si hago esto, me desplazo desde la direccion base dle array, mas 188 lugares
    bufferEdad = *pEdades+188; //** si hago esto al puntero le sumo 188, al valor que tenia guardado ahi. hace una suma

    //** estos son ejemplos para verlos, pero si estuviese bien hecho tendria que ir con defines e indices y demas



    int getInt ( char* msg,
                 char* msgErr,
                 int maximo,
                 int minimo,
                 int reintentos,
                 int* resultado )

                 //**lo que salga de aca lo voy a mandar al de abajo



    int getArrayInt (   char* msg,
                        char* msgErr,
                        int maximo,
                        int minimo,
                        int reintentos,
                        int* arrayResultado,
                        int limite )





    return 0;
}
