#define CANTIDAD_CHAR_NOMBRE 50
#define CANTIDAD_CHAR_DIRECCION 128

typedef struct {

    int idPantalla;
    int isEmpty;
    char nombre[CANTIDAD_CHAR_NOMBRE];
    char direccion [CANTIDAD_CHAR_DIRECCION];
    float precio;
    char tipo;


}pantalla;


int pan_buscarLugarLibre(pantalla ePantallas[],int cantidadDeElementos,int valor);
void pan_inicializarArrayPantallas (pantalla ePantallas[] ,int cantidadDeElementos,int valor);
void MenuPantalla();

int isAlphaNumeric(char str[]);


int getAlphaNumeric (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char resultado[]);

int esNumericoFlotante(char str[]);

float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

int getStringNumerosFlotantes(char mensaje[],char input[]);

void getString2(char mensaje[],char input[]);

