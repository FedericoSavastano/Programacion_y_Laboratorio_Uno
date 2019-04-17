#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

int getInt (char mensaje[])
{
    int numeroBuffer;
    printf("%s",mensaje);
    scanf("%d",&numeroBuffer);
    return numeroBuffer;

}



