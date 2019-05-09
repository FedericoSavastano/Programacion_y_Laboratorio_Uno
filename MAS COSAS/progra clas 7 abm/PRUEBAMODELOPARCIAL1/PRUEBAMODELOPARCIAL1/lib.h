


typedef struct{
    int estado;
    int idAsociado;
    int dniAsociado;
    char nombreAsociado[50];
    char apellidoAsociado[50];
    int edadAsociado;


}Asociado;

typedef struct{
    int idAsociado;
    char motivo[50];
    int idLlamada;
    int estado;
    int tiempo;
    int idAmbulancia;

}Llamada;

void inicializarArrayAsociados (Asociado arrayAsociados[],int cantidaddeelementos, int valor);
int getInt (char mensaje[]);
static int generarID (void);
int generarAsociado(Asociado arrayAsociados[]);
