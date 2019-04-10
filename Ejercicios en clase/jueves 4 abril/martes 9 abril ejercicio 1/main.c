#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define CANTIDAD_CARACTERES_NOMBRE 30


int main()
{
    char nombre [CANTIDAD_CARACTERES_NOMBRE];
    char nombreBuffer[CANTIDAD_CARACTERES_NOMBRE];
    int lenght;
    int i=0;




    printf("Ingrese su nombre \n");
    fgets(nombreBuffer, sizeof(nombre),stdin);
    //length = strlen (nombre);

    while(nombreBuffer[i]!= '\0')
    {
        if (nombreBuffer[i] >= 'a' && nombreBuffer[i] <= 'z' || nombreBuffer[i] >= 'A' && nombreBuffer <= 'Z')
        {
            strncpy(nombre,nombreBuffer,sizeof(nombre));
            printf("Su nombre es %s",nombre);
        }
        else
        {
            printf("Ese no es un nombre valido");
        }

        i++;
    }


    return 0;




/**

    while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;


    strncpy(nombre,nombreBuffer,sizeof(nombre));
    printf("Su nombre es %s",nombre);




    if aux[i] >= 'a' && aux[i] <= 'z' || aux [i] >='A' && aux[i] <= 'Z'


    return 0;
    */
}
