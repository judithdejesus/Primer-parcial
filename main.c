#include <stdio.h>
#include <stdlib.h>
#include "Propietarios.h"
#include <string.h>
#include <ctype.h>

#define CANTIDAD 20
#define VACIO 0
#define OCUPADO 1

int main()
{
   ePropietario listaPropietarios[CANTIDAD];
   int auxId;
   int opcion;

   do
    {
    printf("\n1- ALTA. Ingresar los propietarios \n");
    printf("2- MODIFICACION. Modificar datos de propietarios \n");
    printf("3- BAJA. Eliminar propietarios \n");
    printf("4- SALIR \n");

    printf("Ingrese la opcion que desea del menu: ");
    scanf("%d", &opcion);

    switch (opcion)
        {
        case 1:
                inicializarPropietario(listaPropietarios, CANTIDAD, VACIO);
                agregarPropietario(listaPropietarios, CANTIDAD);

            break;

        case 2:
            mostrarPropietarios(listaPropietarios, CANTIDAD);

            printf("Ingrese el id del propietario que desea modificar: ");
            scanf("%d", &auxId);
            modificarPropietarios(listaPropietarios, CANTIDAD, auxId);
            break;

        case 3:
            mostrarPropietarios(listaPropietarios, CANTIDAD);

            printf("Ingrese el numero de id del propietario que desea eliminar: ");
            scanf("%d", &auxId);
            borrarPropietario(listaPropietarios, CANTIDAD, auxId, VACIO);
            break;

        case 4:
            printf("Saliendo del programa \n");
            break;


            break;
        }
        system("pause");
        system("cls");

        } while (opcion != 1 || opcion != 2 || opcion != 3 || opcion != 4);

    return 0;
}
