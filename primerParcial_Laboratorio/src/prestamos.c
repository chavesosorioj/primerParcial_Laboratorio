/*
 * prestamos.c
 *
 *  Created on: May 16, 2020
 *      Author: juliana
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

#include "clientes.h"
#include "prestamos.h"
#include "menu.h"
#include "utn.h"

void inicializar_prestamos(ePrestamo lista[], int tam) {
	int i;
	if (lista != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			lista[i].isEmpty = LIBRE;
			lista[i].estado = INACTIVO;
			lista[i].importe = 0;
			lista[i].cuotas = 0;
		}
	}
}

int espacioLibreP(ePrestamo lista[], int tam) {
	int i;
	int retorno = -1;
	for (i = 0; i < tam; i++) {
		if (lista[i].isEmpty == LIBRE) {
			return i;
			break;
		}
	}
	return retorno;
}
void hardcodeo_prestamo(ePrestamo *lista) {
	int harcodeo = 6;

	int ID[6] = { 1000, 1001, 1002, 1003, 1004, 1005 };
	int IDCLIENTE[6] = { 1, 2, 3, 4, 5, 6 };
	int IMPORTE[6] = { 200, 300, 400, 500, 600, 700 };
	int CUOTAS[6] = { 3, 4, 5, 6, 7, 8 };

	for (int i = 0; i < harcodeo; i++) {
		lista[i].id = ID[i];
		lista[i].clienteId = IDCLIENTE[i];
		lista[i].importe = IMPORTE[i];
		lista[i].cuotas = CUOTAS[i];
		lista[i].estado = ACTIVO;
		lista[i].isEmpty = OCUPADO;
	}
}

int agregarMasPrestamos(void) {
	int validar;

	validar =
			validaEntero(
					"\nDesea continuar agregando prestamos? Ingrese:\n1 - Si\n2 - No\n");
	while (validar != 1 && validar != 2) {
		printf("Error. Debe ingresar\n 1 - Si\n2 - No");
		__fpurge(stdin);
		scanf("%d", &validar);
	}
	return validar;
}
int cantidadOcupadoPrestamo(ePrestamo *lista, int tam) {

	int cantOcupados = 0;
	int i;

	for (i = 0; i < tam; i++) {
		if (lista[i].isEmpty == OCUPADO) {
			cantOcupados = 1;
			break;
		}
	}
	return cantOcupados;
}

int altaPrestamos(ePrestamo pLista[], int tamP, eClientes clientes[], int tamC) {
	ePrestamo nuevoPrestamo;
	int retorno = -1;
	int importe;
	int cuotas;
	int indice;
	int idCliente;
	int auxId;
	int confirmacion;

	if (pLista != NULL && tamP > 0) {
		//system("clear");
		__fpurge(stdin);

		printf("\n\t*********ALTA*********\t\n");

		indice = espacioLibreP(pLista, TAM_CLIENTES);
		if (indice == -1) {
			printf("\n**********No hay mas prestamos para tomar**********\n");
		} else {	//**********************************VALIDAR LO INGRESADO
			idCliente =
					validaEntero(
							"\n\tIngrese el ID del cliente que solicita el prestamo\t\n");
			auxId = buscarIdCliente(&idCliente, TAM_CLIENTES, clientes);
			if (auxId == -1) {
				printf("\n\tNo hay ningún cliente con ese id\t\n");
			} else {
				mostrarCliente(clientes[auxId]);
				confirmacion = validaConfirmacion();
				if (confirmacion == 1) {
					importe = validaEntero(
							"\n\tIngrese el importe del prestamo\t\n");
					cuotas = validaEntero(
							"\n\tIngrese la cantidad de cuotas\t\n");
				}

				printf("\n\tEl ID del prestamo es: %d", indice);

				nuevoPrestamo.id = indice;
				nuevoPrestamo.clienteId = auxId;
				nuevoPrestamo.importe = importe;
				nuevoPrestamo.cuotas = cuotas;
				nuevoPrestamo.estado = ACTIVO;
				nuevoPrestamo.isEmpty = OCUPADO;
				pLista[indice] = nuevoPrestamo;

				printf("\n**********CARGA EXITOSA**********\n");
				retorno = 1;
			}
		}

	}
	return retorno;
}

void mostrarPrestamo(ePrestamo lista) {
	printf("\n\t%d		%d			%d		%d		%d\t\n", lista.id, lista.clienteId,
			lista.importe, lista.cuotas, lista.estado);

}
void mostrarPrestamos(ePrestamo list[], int tam) {
	//system("clear");
	printf("\n\tID		ID CLIENTE		IMPORTE		CUOTAS		ESTADO\t\n");
	if (list != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (list[i].isEmpty == OCUPADO) {
				mostrarPrestamo(list[i]);
			}
		}
	}

}
int buscarIdPrestamo(int *id, int tam, ePrestamo lista[]) {
	int indice = -1;
	int i;
	for (i = 0; i < tam; i++) {
		if (lista[i].isEmpty == OCUPADO && lista[i].id == *id) {
			indice = i;
			break;
		}
	}
	return indice;
}
int saldarPrestamo(ePrestamo lista[], int tam) {
	int retorno = -1;
	int auxId;
	int buscaId;

	printf("\n\t*********SALDAR PRESTAMO*********\t\n");

	auxId = validaEntero("\n\tIngrese el ID del prestamo a saldar");
	buscaId = buscarIdPrestamo(&auxId, TAM_PRESTAMOS, lista);
	if (buscaId == -1) {
		printf("\n\tNo hay ningun prestamos con ID %d", auxId);
	} else {
		printf("\n\tEl prestamo pertenece al cliente:\t\n");
		printf("\n\tID\t\tID CLIENTE\t\tIMPORTE\t\tCUOTAS\t\tESTADO\t\n");
		mostrarPrestamo(lista[auxId]);
		if (validaConfirmacion() == 2) {
			printf("\n\tSe anulo la cancelación del prestamo\t\n");
		} else if (lista[auxId].estado == SALDADO) {
			printf("\n\tEl prestado ya se encuentra saldado\t\n");
		} else {
			lista[auxId].estado = SALDADO;
			printf("\n\tSe saldo el prestamo\t\n");
			retorno = 1;
		}
	}
	return retorno;
}

int reanudarPrestamo(ePrestamo lista[], int tam) {
	int retorno = -1;
	int auxId;
	int buscaId;

	if (lista != NULL && tam > 0) {

		printf("\n\t*******REANUDAR PRESTAMO*******\t\n");
		auxId = validaEntero("\n\tIngrese el ID del prestamo a saldar");
		buscaId = buscarIdPrestamo(&auxId, TAM_PRESTAMOS, lista);
		if (buscaId == -1) {
			printf("\n\tNo hay ningun prestamos con ID %d", auxId);
		} else {
			printf("\n\tEl prestamo pertenece al cliente:\t\n");
			printf("\n\tID\t\tID CLIENTE\t\tIMPORTE\t\tCUOTAS\t\tESTADO\t\n");
			mostrarPrestamo(lista[auxId]);
			if (validaConfirmacion() == 2) {
				printf("\n\tSe anulo la activación del prestamo\t\n");
			} else if (lista[auxId].estado == ACTIVO) {
				printf("\n\tEl prestamo ya se encuentra activo\t\n");
			} else {
				lista[auxId].estado = ACTIVO;
				printf("\n\tSe reanudo el prestamo\t\n");
				retorno = 1;
			}
		}
	}
	return retorno;
}

int imprimirConCuil(ePrestamo prestamos[], int tamP, eClientes clientes[],
		int tamC) {
	int retorno = -1;
	int ocupado;
	int i, j;

	if (prestamos != NULL && clientes != NULL && tamC > 0 && tamP > 0) {
		//system("clear");
		printf("\n\tLISTA PRESTAMOS ACTIVOS\t\n");

		ocupado = cantidadOcupadoPrestamo(prestamos, TAM_PRESTAMOS);
		if (ocupado == 0) {
			printf("\n\tNo hay prestamos tomados\t\n");
		} else {
			printf("\n\tLos datos del prestamo son:\t\n");
			printf("\n\tID\t\tIMPORTE\t\tCUOTAS\t\tCUIL\t\n");

			for (i = 0; i < tamP; i++) {
				if (clientes[i].isEmpty == OCUPADO) {
					for (j = 0; j < tamP; j++) {
						if (prestamos[j].clienteId
								== clientes[i].id&& prestamos[j].estado==ACTIVO) {
							printf("\n\t%d\t\t%d\t\t%d\t\t%s\t",
									prestamos[j].id, prestamos[j].importe,
									prestamos[j].cuotas, clientes[i].cuil);
						}

					}
				}
			}
		}
	}
	return retorno;
}
