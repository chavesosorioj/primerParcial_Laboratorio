/*
 * informes.h
 *
 *  Created on: May 17, 2020
 *      Author: juliana
 */

#ifndef INFORMES_H_
#define INFORMES_H_


/*
 * brief funcion que busca los prestamos con
 * 		importe mayor a 1000
 * 	param prestamos, arrar donde busca el importe
 * 	param tam, tamaño del array
 * 	return -1 si no se pudo, 1 si se logro recorrer
 */
int prestamosMayores(ePrestamo prestamos[],int tam);
/*
 * brief recorre clientes y encuentra el que tenga mas prestamos segun
 * 		parametro ingresado. O más activos[0] o más saldados[1]
 * param clientes, array clientes donde busca
 * param prestamos, array prestamos donde busca
 * param tamC, tamaño de clientes
 * param tamP, tamaño de prestamos
 * param estado, parametro segun el que arroja resultado
 * return 0
 */
int masPrestamos(eClientes clientes[], ePrestamo prestamos[], int tamC, int tamP, int estado);

/*
 * brief recorre clientes y encuentra el que tenga mas prestamos
 * param clientes, array clientes donde busca
 * param prestamos, array prestamos donde busca
 * param tamC, tamaño de clientes
 * param tamP, tamaño de prestamos
 * return 0
 */

int clienteMasPrestamos(eClientes clientes[], ePrestamo prestamos[], int tamC, int tamP);
/*
 * brief busca el prestamo que tenga doce cuotas
 * param prestamos, array donde busca
 * param tam, tamaño del array
 * return -1 si no se pudo buscar y 1 si se pudo
 */
int prestamosDoceCuotas(ePrestamo prestamos[], int tam);
/*
 * brief busca los prestamos que tenga la cantidad de cuotas
 * 		ingresadas por el usuario
 * 	param prestamos, array donde busca
 * 	param tam, tamaño del array
 * 	return -1 si no se pudo buscar y 1 si se pudo
 */
int prestamosPorCuotas(ePrestamo prestamos[], int tam);
#endif /* INFORMES_H_ */
