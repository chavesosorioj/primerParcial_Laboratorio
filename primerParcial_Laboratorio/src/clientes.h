/*
 * empleados.h
 *
 *  Created on: May 9, 2020
 *      Author: juliana
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

#define TAM_NOMBRE 51
#define TAM_APELLIDO 51
#define TAM_CLIENTES 50



#define LIBRE 0
#define OCUPADO 1

typedef struct{

	int id;
	char nombre[51];
	char apellido[51];
	char cuil[50];
	int isEmpty;

}eClientes;

#include "prestamos.h"
/*
 * breif Indica que la posición isEmpty está vacía
 * 		la función pone el flag (isEmpty) en TRUE
 * 		en todas las posiciones del array
 * param lista, array clientes
 * param tam, tamaño del array
 * return void
 */
void inicializar_clientes(eClientes lista[], int tam);

/*
 * breif Harcodea todos los campos de la estructura
 *		a fin de comprobar que los datos se vean
 *		correctamente
 *	param eClientes, estructura a carcar
 *	param, tam, tamaño de la estructura
 *	return void
 */

void hardcodeo_clientes(eClientes* lista);

/*
 * breif busca el primer espacio libre en isEmpty, al encontrarlo rompe la iteración
 * param lista puntero al array de la estructura en la que busca
 * param tam, tamaño de la estructura
 * return, -1 si no se encontro lugar libre o [i] posicion libre
 */

int espacioLibre(eClientes lista[], int tam);

/*
 * brief pregunta al usuario si desea ingresar mas clientes
 * param void
 * return 1 - SI // 2 - NO
 */

int agregarMasClientes(void);
/*
 * breif da de alta un cliente
 * param lista, array a cargar
 * param tam, tamaño del array
 *return -1 si no cargo, 1 si se pudo
 */

int altaCliente(eClientes lista[], int tam);

/*
 * breif busca el id coincidente entre el pasado por parámetro
 * 		y el cargado en la estructura
 * param id; id a buscar
 * param tam, tamaño de la estructura
 * param eClientes, estructura en la que busca
 * return -1 en caso de no haber encontrado coincidencia, o el índice correspondiente con el id
 */


int buscarIdCliente(int* id, int tam, eClientes lista[]);

/*
 * breif muestra los elementos de la estructura
 * param lista en la que busca
 * retur void
 */
void mostrarCliente(eClientes lista);

/*
 * breif muestar todos los clientes de la estructura
 * param lista, array a mostrar
 * param tam, tamaño de la estructura
 * return void
 */

void mostrarClientes(eClientes list[],int len);

/*
 * breif da de baja un elemento del array clientes
 * param pClientes, estructura en la que busca
 * param tam, tamaño del array
 * return -1 si no se logro la baja y 1 si se pudo
 */

int darBaja(eClientes lista[], int tam);

/*
 * breif función que busca si hay clientes dados de alta
 * param pCLientes, estructura en la que busca
 * param tam, tamaño de la estructura
 * return 1 si hay clientes dados de alta o 0 en caso que no lo haya
 */


int cantidadOcupadoCliente(eClientes* lista, int tam);

/*
 * brief modifica los campos del array clientes
 *param lista, array a modificar
 *param tam, tamaño del array
 *return -1 si no se modifico y 1 si se logro
 */

int modificar(eClientes lista[], int tam);


/*
 * brief realiza una lista de los datos cargados segun
 * 		el campo apellido y nombre
 * param pClientes, estructura a listar
 * param tam, tamaño de la estructura
 * return void
 */
void clientes_listarNombre(eClientes* pEmpleados, int tam);

/*
 * brief busca la cantidad de prestamos activos que tiene un id
 * param id, id del cliente a buscar
 * param prestamos, array en el que busca
 * param tamP, tamaño del array
 */
int cantidadPrestamosCliente(int id,ePrestamo prestamos[], int tamP);
/*
 * brief imprime lista de clientes junto con la cantidad de prestamos de c/u
 * param clientes, array de clientes
 * param prestamos, array prestamos
 * param tamC, tamaño del array clientes
 * param tamP, tamaño del array prestamos
 */

int imprimirClientePrestamos(eClientes clientes[],ePrestamo prestamos[],int tamC, int tamP);

#endif /* CLIENTES_H_ */
