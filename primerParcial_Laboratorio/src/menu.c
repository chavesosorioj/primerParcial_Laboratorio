/*
 * menu.c
 *
 *  Created on: May 7, 2020
 *      Author: juliana
 */

#include "menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

#include "utn.h"


// VERIFICAR CON NUMEROS
int menu()
{
      int opcion;

    printf("\n*********MENU*********\n\n");

    printf(" - 1  - ALTA\n\n");
    printf(" - 2  - MODIFICAR\n\n");
    printf(" - 3  - BAJA\n\n");
    printf(" - 4  - CREAR PRESTAMO\n\n");
    printf(" - 5  - SALDAR PRESTAMO\n\n");
    printf(" - 6  - REANUDAR PRESTAMO\n\n");
    printf(" - 7  - IMPRIMIR CLIENTES\n\n");
    printf(" - 8  - IMPRIMIR PRESTAMOS CON CUIL\n\n");
    printf(" - 9  - INFORMES \n\n");
    printf(" - 11  - SALIR\n\n");
    __fpurge(stdin);
    scanf("%d",&opcion);

    printf("\nOPCION ELEGIDA: %d\n", opcion);
    return opcion;
}

int menuUno()
{
	int opcion;

	printf("\n***INGRESE NÚMERO DE LO QUE DESEA MODIFICAR***\n\n");

	printf(" - 1  - NOMBRE\n\n");
	printf(" - 2  - APELLIDO\n\n");
	printf(" - 3  - CUIL\n\n");
	__fpurge(stdin);
	scanf("%d",&opcion);

	printf("\nOPCION ELEGIDA: %d\n", opcion);
	return opcion;;
}

int menuDos()
{
	int opcion;

	printf("\n***INGRESE NÚMERO DEL INFORME QUE DESEA VER***\n\n");

	printf(" - 1  - Cliente con mas prestamos activos\n\n");
	printf(" - 2  - Cliente con mas prestamos saldados\n\n");
	printf(" - 3  - Cantidad de prestamos mayor a 1000\n\n");
	__fpurge(stdin);
	scanf("%d",&opcion);

	printf("\n %d OPCION ELEGIDA: \n", opcion);
	return opcion;;
}
