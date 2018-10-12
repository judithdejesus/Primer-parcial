#include <stdio.h>
#include <stdlib.h>
#include "Propietarios.h"
#include <string.h>
#include <ctype.h>

void inicializarPropietario (ePropietario lista[], int cant, int estado)
{
    int i;
    for (i=0; i<cant; i++)
    {
       lista[i].estado = estado;
    }
}

int generarId ()
{
    static int id=0;
    id++;
    return id;

}

int buscarEspacio (ePropietario lista[], int cant)
{
    int indice = -1;
    int i;

    for (i=0; i<cant; i++)
    {
        if (lista[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int agregarPropietario(ePropietario lista[], int cant)
{

    ePropietario nuevoPropietario;

    int retorno=-1;
    int indice;

    system("cls");
    printf("  *** Alta Cliente ***\n\n");

    indice = buscarEspacio(lista, cant);


    if(indice == -1)
    {
        printf("No hay suficiente lugar\n\n");
    }
    else
    {
        getValidString("Ingrese el apellido: ",nuevoPropietario.apellido);
        getValidString("Ingrese el nombre: ",nuevoPropietario.nombre);

        printf("Ingrese la direccion: ");
        scanf("%s", nuevoPropietario.direccion);

        printf("Ingrese el numero de tarjeta de credito: ");
        fflush(stdin);
        getInt("Error reingrese el numero: ");

        nuevoPropietario.idPropietario = generarId();

        nuevoPropietario.estado = 1;

        lista[indice]=nuevoPropietario;

    }
    return retorno;
}

int getValidString(char requestMessage[], char input[])
{
    int retorno=-1;
    char auxInput[50];

    while(1)
    {

        if (!getStringLetras(requestMessage,auxInput))
        {
            printf ("Debe contener solo letras\n");
            continue;
        }

        retorno=0;
        strcpy(input,auxInput);
        break;
    }

    return retorno;
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);


    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int esNumerica(char cadena[])
{
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!(isdigit(cadena[i])))
            {
                return 0;
            }
            i++;
        }
    }
    return 1;
}

int getInt(char error[])
{
    int aux;
    char buffer[64];
    scanf("%s",buffer);
    while(esNumerica(buffer)==0)
    {
        printf("%s",error);
        fflush(stdin);
        scanf("%s",buffer);
    }
    aux = atoi(buffer);
    return aux;
}

void modificarPropietarios (ePropietario lista[], int cant, int id)
{
    int i;

    for (i=0; i<cant; i++)
    {
        if (id == lista[i].idPropietario)
        {
                printf("Ingrese el nuevo numero de tarjeta de credito: ");
                fflush(stdin);
                scanf("%d", &lista[i].tarjetaDeCredito);
        }
        else
        {
            printf("\nNo hay un cliente asignado con ese id");
        }
        break;
    }
}

void borrarPropietario(ePropietario lista[], int cant, int id, int vacio)
{
    int i;
    for (i=0; i<cant; i++)
    {
        if (lista[i].idPropietario == id)
        {
            lista[i].estado = vacio;
            break;
        }
        else
        {
            printf("No hay un empleado con ese id");
        }
    }

}

void mostrarPropietarios(ePropietario lista[], int cant)
{
    int i;

    printf("\n\tApellido -- \tNombre -- \tId -- \tDireccion -- \tTarjeta de credito\n");

    for (i=0; i<cant; i++)
    {
        if (lista[i].estado == 1)
        {
            printf("\t%s -- \t%s -- \t%d -- \t%s -- \t%d \n", lista[i].apellido, lista[i].nombre, lista[i].idPropietario, lista[i].direccion, lista[i].tarjetaDeCredito);

        }
    }
}
