#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre [257] = {'H','O','L','A','\0'}; /**se usa la cantidad que quiero usar mas uno, por el contrabarra cero es el ultimo */
                        /** se puede poner = solo aca, para inicializarlo, SIEMPRE VA con comilla simple, sino no es array. con comilla doble es un string, o sea dos caracteres */
    char nombre [257] = "HOLA";   /**esto es lo mismo a lo de arriba, de hacer esto, el compilador solo, lo va a transformar en lo de arriba. */
    nombre = "Juan"; /**ESTO NO, ES UNA BURRADA */
    /**ESTO HAY QUE HACERLO CON UNA FUNCION QUE RECORRE TODO EL array
    SE PUEDE HACER CON strcpy
    pero la mas copada es strncpy () */

    strncpy()
    /**se le pasa destino, origen y cantidad/tamaño, siempre el tamaño es igual o menor del del destino*/
    /**si yo quiero copiar el nombre hago:*/
    strncpy(nombre, nombre2,257) /**tengo el nombre , le asigno el destino y el tamaño, aunque esto va a estar en un DEFINE, no poner el numero aca */

    /**esta es la forma mas pro igualmente:
    /*/
    strncpy(nombre, nombre2,sizeof(nombre)); /**con esto copio bajo el nombre "nombre2" la informacion que h ay en "nombre" */
    /**se usa este sizeof para que no se vaya a la mierda la duracion, lo importante es el tamaño del destino

    */
    fgets(nombre, sizeof(nombre),stdin) /**tengo que decirle cual es el file de donde voy a tomar la informacion, donde quiero dejar la info? el primero"nombre" / le pongo un limite
    */
    printf("\n%s",nombre);

    /** esto lo que hizo es mostrar lo que estaba inicializado en el char, y luego se le agregó lo que tomó que se lo asignó,
    dice HOLA y si le escribo 12343555 despues, deberá decir ese numero/**/
    ddd

    strlen ( ) /** te dice la cantidad de caracteres que tiene
    str
    cmp
    si lo pongo completo se traba todo.



    fgets lee desde un archivo la cantidad de caracteres

    el cmp compara dos lugares para saber si uno entra en el otro, te devuelve un int para decirte si es verdadero o falso,
*/


    ejercicio:
    *pedir un nombre
    *guardar en un buffer
    *validar caracteres
    *guardar la variable destino
    *mostrar por pantalla


    return 0;
}
