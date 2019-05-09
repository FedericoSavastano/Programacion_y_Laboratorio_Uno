
#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED




typedef struct {
int asociadoEstado;
int asociadoID;
char asociadoNombre[25];
char asociadoApellido[25];
char asociadoDNI[10];
int asociadoEdad;

}Asociado;




int getString2(char * punteroString, char * mensaje, char * mensajeError);
void getString(char mensaje[],char input[]);
int getInt (char mensaje[]);
float getFloat (char mensaje[]);
int getIntEnRango (char mensaje[],int max, int min);
int getStringLetras(char* punteroString, char * mensaje, char * mensajeError, int reintentos);
int getStringLetras2(char mensaje [], char input[]);



int esNumero (char* punteroString);
int esNumeroFlotante (char* punteroString);
int esLetras (char* punteroString);
int esAlfaNumerico (char* punteroString);
int esTelefono (char* punteroString);
int esDNI (char* punteroString);
int esCuit (char* punteroString);


int inicializarAsociados(Asociado * punteroAsociados, int cantidadAsociados);
static int generarId(void);
int encontrarPosicionLibre (Asociado* punteroAsociado, int cantidadDeAsociados);



#endif
