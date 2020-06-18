/*
 ============================================================================
 Name        : primerParcial_Laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

#include "utn.h"
#include "menu.h"
#include "clientes.h"
#include "prestamos.h"
#include "informes.h"

int main(int argc, char *argv[]) {

	eClientes clientes[TAM_CLIENTES];
	ePrestamo prestamos[TAM_PRESTAMOS];
	int opcion;
	int seguirCl = 0;
	;
	int seguirP = 0;
	int legajo = 1000;

	//setbuf(stdout,NULL);

	inicializar_clientes(clientes, TAM_CLIENTES);
	inicializar_prestamos(prestamos, TAM_PRESTAMOS);
	//hardcodeo_clientes(clientes);
	//hardcodeo_prestamo(prestamos);
	//mostrarClientes(clientes, TAM_CLIENTES);
	//mostrarPrestamos(prestamos, TAM_PRESTAMOS);

	do {
		opcion = menu();
		switch (opcion) {
		case 1:
			while (seguirCl != 2) {
				if (altaCliente(clientes, TAM_CLIENTES, legajo)) {
					legajo++;
				}
				seguirCl = agregarMasClientes();
			}
			break;
		case 2:
			modificar(clientes, TAM_CLIENTES);
			break;

		case 3:
			darBaja(clientes, TAM_CLIENTES);
			break;
		case 4:
			while (seguirP != 2) {
				altaPrestamos(prestamos, TAM_PRESTAMOS, clientes, TAM_CLIENTES);
				seguirP = agregarMasPrestamos();
			}
			break;
		case 5:
			saldarPrestamo(prestamos, TAM_PRESTAMOS);
			break;
		case 6:
			reanudarPrestamo(prestamos, TAM_PRESTAMOS);
			break;
		case 7:
			imprimirClientePrestamos(clientes, prestamos, TAM_CLIENTES,
					TAM_PRESTAMOS);
			break;
		case 8:
			imprimirConCuil(prestamos, TAM_PRESTAMOS, clientes, TAM_CLIENTES);
			break;
		case 9:
			switch (menuDos()) {
			case 1:
				masPrestamos(clientes, prestamos, TAM_CLIENTES, TAM_PRESTAMOS,
						ACTIVO);
				break;
			case 2:
				masPrestamos(clientes, prestamos, TAM_CLIENTES, TAM_PRESTAMOS,
						SALDADO);
				break;

			case 3:
				clienteMasPrestamos(clientes, prestamos, TAM_CLIENTES,
						TAM_PRESTAMOS);
				break;
			case 4:
				prestamosMayores(prestamos, TAM_PRESTAMOS);
				break;
			case 5:
				prestamosDoceCuotas(prestamos, TAM_PRESTAMOS);
				break;
			case 6:
				prestamosPorCuotas(prestamos, TAM_PRESTAMOS);
				break;
			}

			break;
		}

	} while (opcion != 11);

	return EXIT_SUCCESS;
}
