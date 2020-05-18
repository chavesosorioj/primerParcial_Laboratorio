/*
 * prestamos.h
 *
 *  Created on: May 16, 2020
 *      Author: juliana
 */

#ifndef PRESTAMOS_H_
#define PRESTAMOS_H_

#define TAM_PRESTAMOS 50

#define LIBRE 0
#define OCUPADO 1

#define SALDADO 1
#define ACTIVO 0
#define INACTIVO -1

typedef struct{

	int id;
	int clienteId;
	int importe;
	int cuotas;
	int estado;
	int isEmpty;

}ePrestamo;

#include "clientes.h"
/*
 * breif Indica que la posición isEmpty está vacía
 * 		la función pone el flag (isEmpty) en TRUE
 * 		en todas las posiciones del array
 * param lista, puntero a array prestamos
 * param tam, tamaño del array
 * return void
 */
void inicializar_prestamos(ePrestamo lista[], int tam);
/*
 * breif busca el primer espacio libre en isEmpty, al encontrarlo rompe la iteración
 * param lista puntero al array de la estructura en la que busca
 * param tam, tamaño de la estructura
 * return, -1 si no se encontro lugar libre o [i] posicion libre
 */
int espacioLibreP(ePrestamo lista[], int tam);
/*
 * breif función que busca si hay prestamos dados de alta
 * param pPrestamos, estructura en la que busca
 * param tam, tamaño de la estructura
 * return 1 si hay prestamos dados de alta o 0 en caso que no lo haya
 */
int cantidadOcupadoPrestamo(ePrestamo* lista, int tam);
/*
 * brief harcodea una estructura
 * param lista, puntero a la estructura
 * return void
 */
void hardcodeo_prestamo(ePrestamo* lista);

/*
 * brief pregunta al usuario si desea ingresar mas prestamos
 * param void
 * return 1 - SI // 2 - NO
 */

int agregarMasPrestamos(void);
/*
 * breif da de alta un prestamo
 * param plista, array a cargar
 * param tamP, tamaño del array
 * param clientes, array de clientes
 * paran tamC, tamaño de clientes
 *return -1 si no cargo, 1 si se pudo
 */

int altaPrestamos(ePrestamo pLista[], int tamP,eClientes clientes[],int tamC);
/*
 * breif muestra un elemento de la estructura
 * param lista en la que busca
 * retur void
 */
void mostrarPrestamo(ePrestamo lista);
/*
 * breif muestar todos los empleados de la estructura
 * param lista, array a mostrar
 * param tam, tamaño de la estructura
 * return void
 */
void mostrarPrestamos(ePrestamo list[],int tam);

/*
 * breif busca el id coincidente entre el pasado por parámetro
 * 		y el cargado en la estructura
 * param id; id a buscar
 * param tam, tamaño de la estructura
 * param ePrestamos, estructura en la que busca
 * return -1 en caso de no haber encontrado coincidencia, o el índice correspondiente con el id
 */
int buscarIdPrestamo(int* id, int tam, ePrestamo lista[]);
int saldarPrestamo(ePrestamo lista[], int tam);
int reanudarPrestamo(ePrestamo lista[], int tam);
int imprimirConCuil(ePrestamo prestamos[],int tamP,eClientes clientes[], int tamC);

#endif /* PRESTAMOS_H_ */
