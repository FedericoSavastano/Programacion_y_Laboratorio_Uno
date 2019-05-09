#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define ESTADO_ASOCIADO_HABILITADO 1
#define ESTADO_ASOCIADO_INHABILITADO 0
#define ESTADO_ASOCIADO_LIBRE -1

static int generarId(void);

/**Funciones Get*/

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf("%s",input);

}


int getString2(char * punteroString, char * mensaje, char * mensajeError)
{
    char bufferString[50];
    printf("%s", mensaje);
    fgets(bufferString,sizeof(bufferString),stdin);
    bufferString[strlen(bufferString)-1] = '\0';
    if(punteroString!=NULL)
    {
        strncpy(punteroString,bufferString,sizeof(bufferString));
    }
    return 0;
}



int getInt (char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

int getIntEnRango (char mensaje[],int max, int min)
{
    int numeroIngresado;
    numeroIngresado=getInt(mensaje);
    //printf("el max ingresado es %d  y el minimo es %d \n", max, min);
    if((numeroIngresado>=min) && (numeroIngresado<=max))
    {
        //printf("El numero si esta en rango todo bien\n");
        return numeroIngresado;
    }else{
        printf("El numero esta fuera de rango\n");
    }

    return -1;

}


float getFloat (char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


int getStringLetras2(char mensaje [], char input[]) /** con 0 son letras, con -1 no*/
{

    printf("%s",mensaje);
    scanf("%s",input);

    if(esLetras(input)==1)
    {
        printf("Puso letras, todo piola\n");
        return 0;

    }else{
        printf("no son letras\n");
        return -1;
    }

}

int getStringAlfanumerico(char mensaje [], char input[]) /** con 0 son letras, con -1 no*/
{
    printf("%s",mensaje);
    scanf("%s",input);

    if(esAlfaNumerico(input)==1)
    {
        printf("Puso alfanumerico, todo piola\n");
        return 0;

    }else{
        printf("no son alfanumericos\n");
        return -1;
    }
}

int getStringNumerico(char mensaje [], char input[]) /** con 0 son letras, con -1 no*/
{
    printf("%s",mensaje);
    scanf("%s",input);

    if(esNumero(input)==1)
    {
        printf("Puso numerico, todo piola\n");
        return 0;

    }else{
        printf("no son numericos\n");
        return -1;
    }
}


/**Funciones Es (chequeo) */


int esNumero (char* punteroString) /**0 para no, 1 para si*/
{
    int i=0;
    while(punteroString[i]!='\0')
    {
        if(punteroString[i]<'0' || punteroString[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int esNumeroFlotante (char* punteroString) /**0 para no, 1 para si*/
{
    int i=0;
    int contadorPuntos=0;
    while(punteroString[i]!='\0')
    {
        if((punteroString[i]<'0' || punteroString[i]>'9')&&(punteroString[i]!='.'))
        {
            return 0;
        }
        if(punteroString[i]=='.')
        {
            contadorPuntos++;
            if(contadorPuntos>1)
            {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

int esLetras (char* punteroString)  /**0 para no, 1 para si*/
{
    int i=0;
    while(punteroString[i]!='\0')
    {
        if((punteroString[i]!=' ')&&(punteroString[i]<'a'||punteroString[i]>'z')&&(punteroString[i]<'A'||punteroString[i]>'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}


int esAlfaNumerico (char* punteroString)  /**0 para no, 1 para si*/
{
    int i=0;
    while(punteroString[i]!='\0')
    {
        if((punteroString[i]!=' ')&&(punteroString[i]!='.')&&(punteroString[i]<'a'||punteroString[i]>'z')&&(punteroString[i]<'A'||punteroString[i]>'Z')
           &&(punteroString[i]<'0' || punteroString[i]>'9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}


int esTelefono (char* punteroString)  /**0 para no, 1 para si*/
{
    int i=0;
    int contadorGuion=0;
    while(punteroString[i]!='\0')
    {
        if((punteroString[i]!=' ')&&(punteroString[i]!='-')&&(punteroString[i]<'0' || punteroString[i]>'9'))
        {
            return 0;
        }
        if(punteroString[i]=='-')
        {
            contadorGuion++;
        }
        i++;
    }
    if(contadorGuion==1)
        {
            return 1;
        }
    return 0;
}



int esDNI (char* punteroString)  /**0 para no, 1 para si*/
{
    int i=0;
    while(punteroString[i]!='\0')
    {
        if(!esNumero(punteroString))
        {
            return 0;
        }
        if(strlen(punteroString)<7 || strlen(punteroString)>8)
        {
            return 0;
        }
        i++;
    }
    return 1;
}


int esCuit (char* punteroString)
{
    int ret=0;
    int i=0;
    while(punteroString[i]!='\0')
    {
        if((punteroString[i]!='-')&&(punteroString[i]<'0' || punteroString[i]>'9'))
        {
            return 0;
        }
        else if((punteroString[2]=='-')&&(punteroString[10]=='-' || punteroString[11]=='-'))
        {
            ret=1;
        }
        i++;
    }
    return ret;
}


/** Funciones asociado*/

static int generarId(void)
{
    static int idAsociado=0;
    return idAsociado++;
}

int inicializarAsociados(Asociado * punteroAsociados, int cantidadAsociados)
{
    int i;
    if(punteroAsociados!= NULL && cantidadAsociados>0)
    {
        for(i=0;i<cantidadAsociados;i++)
        {
            punteroAsociados[i].asociadoID=-1;
            punteroAsociados[i].asociadoEstado=ESTADO_ASOCIADO_LIBRE;
        }
    }
    return 0;
}


int altaAsociado(Asociado *punteroAsociado, int cantidadAsociados, int punteroIndice, char mensajeError, int intentos)
{
   char bufferNombre[50];
   char bufferApellido[50];
   int bufferEdad;


    if(getStringLetras2( ("Ingrese el nombre:  ",bufferNombre)==0) && (getStringLetras2("Ingrese el apellido:   ",bufferApellido)==0) )
        if(getStringNumerico( "Ingrese la edad:  ", bufferEdad))
    {
        strncpy(punteroAsociado[punteroIndice].asociadoNombre,bufferNombre,sizeof(bufferNombre));
        strncpy(punteroAsociado[punteroIndice].asociadoApellido,bufferApellido,sizeof(bufferApellido));
    }
    else{
        return mensajeError;
    }
}
/*
int pan_addPan(Pantalla* pPantalla,int len,int pIndex,char* msgE,int tries)
{
    char bufferName[50];
    char bufferAdress[250];
    char bufferPrecio[20];
    char bufferTipo[20];
    float auxPrecio;
    int auxTipo;
    int retorno=-1;
    if((pPantalla!=NULL)&&(len>0))
    {
        if(((getStringLetras(bufferName,"\nIngrese Nombre: ",msgE,tries)==0)&&
            (getStringAlphanumeric(bufferAdress,"\nIngrese Direccion: ",msgE,tries)==0)))
        {
            if((getStringNumerosFloat(bufferPrecio,"\nIngrese Precio: ",msgE,tries)==0)
                &&(getStringNumeros(bufferTipo,"\nIngrese Tipo 1(LCD) 2(LED): ",msgE,tries)==0))
            {
                auxPrecio=atof(bufferPrecio);
                auxTipo=atoi(bufferTipo);
                strncpy(pPantalla[pIndex].nombre,bufferName,sizeof(bufferName));
                strncpy(pPantalla[pIndex].direccion,bufferAdress,sizeof(bufferAdress));
                pPantalla[pIndex].precio=auxPrecio;
                pPantalla[pIndex].tipo=auxTipo;
                pPantalla[pIndex].idPantalla=generarId();
                pPantalla[pIndex].isEmpty=0;
                retorno=0;
            }
        }
    }
    return retorno;
}
*/

int encontrarPosicionLibre (Asociado* punteroAsociado, int cantidadDeAsociados)
{
    int i;
    int ret=-1;
    for(i=0;i<cantidadDeAsociados;i++)
    {
        if(punteroAsociado[i].asociadoEstado==-1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}




