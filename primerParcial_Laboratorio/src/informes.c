/*
 * informes.c
 *
 *  Created on: May 17, 2020
 *      Author: juliana
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

#include "clientes.h"
#include "prestamos.h"
#include "informes.h"
#include "utn.h"


int clienteMasPrestamosActivos(eClientes clientes[], ePrestamo prestamos[], int tamC, int tamP)
{
	eClientes auxCliente;


	int cantPrestamos=0;;
	int max=0;
	int i,j;

	if(clientes !=NULL && prestamos !=NULL && tamC>0 && tamP>0)
	{
		for(i=0;i<tamC;i++)
		{
			if(clientes[i].isEmpty== OCUPADO)
			{
				for(j=0;j<tamP;j++)
				{
					if(prestamos[j].isEmpty==OCUPADO && prestamos[j].clienteId== clientes[j].id)
					{
						if(prestamos[j].estado==ACTIVO)
						{
							cantPrestamos++;
						}
					}
				}

				if(cantPrestamos>max)
				{
					max= cantPrestamos;
					auxCliente.id=clientes[i].id;
					strcpy(auxCliente.nombre,clientes[i].nombre);
					strcpy(auxCliente.apellido, clientes[i].apellido);
					strcpy(auxCliente.cuil,clientes[i].cuil);
				}
			}
		}
	}

	printf("\t\n ID: %d\t\tNOMBRE: %10s\t\t APELLIDO: %10s\t\t CUIL: %s\t\n",
			auxCliente.id,
			auxCliente.nombre,
			auxCliente.apellido,
			auxCliente.cuil
		);
	return 0;
}


int clienteMasPrestamosSaldados(eClientes clientes[], ePrestamo prestamos[], int tamC, int tamP)
{
	eClientes auxCliente;


	int cantPrestamos=0;;
	int max=0;
	int i,j;

	if(clientes !=NULL && prestamos !=NULL && tamC>0)
	{
		for(i=0;i<tamC;i++)
		{
			if(clientes[i].isEmpty== OCUPADO)
			{
				for(j=0;j<tamP;j++)
				{
					if(prestamos[j].isEmpty==OCUPADO && prestamos[j].clienteId== clientes[j].id)
					{
						if(prestamos[j].estado==SALDADO)
						{
							cantPrestamos++;
						}
					}
				}

				if(cantPrestamos>max)
				{
					max= cantPrestamos;
					auxCliente.id=clientes[i].id;
					strcpy(auxCliente.nombre,clientes[i].nombre);
					strcpy(auxCliente.apellido, clientes[i].apellido);
					strcpy(auxCliente.cuil,clientes[i].cuil);
				}
			}
		}
	}

	printf("\t\n ID: %d\t\tNOMBRE: %10s\t\t APELLIDO: %10s\t\t CUIL: %s\t\n",
			auxCliente.id,
			auxCliente.nombre,
			auxCliente.apellido,
			auxCliente.cuil
		);
	return 0;
}
int clienteMasPrestamos(eClientes clientes[], ePrestamo prestamos[], int tamC, int tamP)
{
	eClientes auxCliente;


	int cantPrestamos=0;;
	int max=0;
	int i,j;

	if(clientes !=NULL && prestamos !=NULL && tamC>0)
	{
		for(i=0;i<tamC;i++)
		{
			if(clientes[i].isEmpty== OCUPADO)
			{
				for(j=0;j<tamP;j++)
				{
					if(prestamos[j].isEmpty==OCUPADO && prestamos[j].clienteId== clientes[j].id)
					{
						if(prestamos[j].estado==SALDADO || prestamos[j].estado==ACTIVO)
						{
							cantPrestamos++;
						}
					}
				}

				if(cantPrestamos>max)
				{
					max= cantPrestamos;
					auxCliente.id=clientes[i].id;
					strcpy(auxCliente.nombre,clientes[i].nombre);
					strcpy(auxCliente.apellido, clientes[i].apellido);
					strcpy(auxCliente.cuil,clientes[i].cuil);
				}
			}
		}
	}

	printf("\t\n ID: %d\t\tNOMBRE: %10s\t\t APELLIDO: %10s\t\t CUIL: %s\t\n",
			auxCliente.id,
			auxCliente.nombre,
			auxCliente.apellido,
			auxCliente.cuil
		);
	return 0;
}
int prestamosMayores(ePrestamo prestamos[],int tam)
{
	int retorno=-1;
	int i;

	printf("\n\tPrestamos con importe mayor a $1000:\t\n");
	printf("\n\tID\t\t\tID CLIENTE\t\t\tIMPORTE\t\t\tCUOTAS\t\t\n");

	for(i=0;i<tam;i++)
	{
		if(prestamos[i].importe>1000 && prestamos[i].estado==ACTIVO)
		{
			printf("\n\t%d\t\t\t%d\t\t\t%d\t\t\t%d",
					prestamos[i].id,
					prestamos[i].clienteId,
					prestamos[i].importe,
					prestamos[i].cuotas
				);
			retorno=1;
		}
	}
	return retorno;
}

int prestamosDoceCuotas(ePrestamo prestamos[], int tam)
{
	int retorno=-1;
	int i;
	if(prestamos != NULL && tam>0)
	{
		printf("\nPrestamos de 12 cuotas saldados:\n");
		printf("\nID   ID CLIENTE    IMPORTE   CUOTAS\n");
		for(i=0;i<tam;i++)
		{
			if(prestamos[i].estado==SALDADO && prestamos[i].cuotas==12)
			{
				printf("\n\t%d\t\t\t%d\t\t\t%d\t\t\t%d",
						prestamos[i].id,
						prestamos[i].clienteId,
						prestamos[i].importe,
						prestamos[i].cuotas
						);
				retorno=1;

			}
		}
	}
	return retorno;
}

int prestamosPorCuotas(ePrestamo prestamos[], int tam)
{
	int retorno=-1;
	int i;
	int cuotas;

	if(prestamos !=NULL && tam>0)
	{
		cuotas= validaEntero("\nIngrese la cantidad de cuotas\n");

		printf("\nID   ID CLIENTE    IMPORTE   CUOTAS\n");
		for(i=0; i<tam;i++)
		{
			if(prestamos[i].estado==ACTIVO && prestamos[i].cuotas== cuotas)
			{
				printf("\n\t%d\t\t\t%d\t\t\t%d\t\t\t%d",
						prestamos[i].id,
						prestamos[i].clienteId,
						prestamos[i].importe,
						prestamos[i].cuotas
						);
				retorno=1;
			}

		}
	}
	return retorno;
}
