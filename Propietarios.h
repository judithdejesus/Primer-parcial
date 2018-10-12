typedef struct
{
    int idPropietario;
    char nombre[51];
    char apellido[51];
    char direccion[100];
    char tarjetaDeCredito[9];
    int estado;
} ePropietario;


void inicializarPropietario (ePropietario[], int, int);
int generarId ();
int buscarEspacio (ePropietario[], int);
int agregarPropietario(ePropietario[], int);
int getValidString(char[], char[]);
int getStringLetras(char [],char []);
void getString(char[],char[]);
int esSoloLetras(char []);
int esNumerica(char []);
int getInt(char []);
void modificarPropietarios (ePropietario [], int, int);
void borrarPropietario(ePropietario [], int, int, int);
void mostrarPropietarios(ePropietario [], int);
