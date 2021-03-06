#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


float getFloat (char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '/0')
    {
        if((str[i] != ' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z'))
            return 0;
        i++;
    }
    return 1;
}


int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '/0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

void getString(char mensaje[],char input[])
{
    printf("%s", mensaje);
    scanf("%s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 0;
    }

    printf("lo del getsletras input es : %s\n",input);
    printf("lo del getsletras aux es : %s\n",aux);
    return 1;
}




int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
