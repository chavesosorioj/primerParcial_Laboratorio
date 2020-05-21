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
 * brief recorre clientes y encuentra el que tenga mas prestamos activos
 * param clientes, array clientes donde busca
 * param prestamos, array prestamos donde busca
 * param tamC, tamaño de clientes
 * param tamP, tamaño de prestamos
 * return 0
 */

int clienteMasPrestamosActivos(eClientes clientes[], ePrestamo prestamos[], int tamC, int tamP);

/*
 * brief recorre clientes y encuentra el que tenga mas prestamos saldados
 * param clientes, array clientes donde busca
 * param prestamos, array prestamos donde busca
 * param tamC, tamaño de clientes
 * param tamP, tamaño de prestamos
 * return 0
 */

int clienteMasPrestamosSaldados(eClientes clientes[], ePrestamo prestamos[], int tamC, int tamP);

#endif /* INFORMES_H_ */
