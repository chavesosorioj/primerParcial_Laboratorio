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
						if(prestamos[j].estado==ACTIVO)
						{
							cantPrestamos++;
						}//FIN CUARTO IF
					}//fin segundo if
				}//fin segundo for

				if(cantPrestamos>max)
				{
					max= cantPrestamos;
					auxCliente.id=clientes[i].id;
					strcpy(auxCliente.nombre,clientes[i].nombre);
					strcpy(auxCliente.apellido, clientes[i].apellido);
					auxCliente.cuil=clientes[i].cuil;
				}
			}//fin segundo if
		}// fin for
	}//fin primer if

	printf("\t\n ID: %d\t\tNOMBRE: %10s\t\t APELLIDO: %10s\t\t CUIL: %lli\t\n",
			auxCliente.id+1,
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
						}//FIN CUARTO IF
					}//fin segundo if
				}//fin segundo for

				if(cantPrestamos>max)
				{
					max= cantPrestamos;
					auxCliente.id=clientes[i].id;
					strcpy(auxCliente.nombre,clientes[i].nombre);
					strcpy(auxCliente.apellido, clientes[i].apellido);
					auxCliente.cuil=clientes[i].cuil;
				}
			}//fin segundo if
		}// fin for
	}//fin primer if

	printf("\t\n ID: %d\t\tNOMBRE: %10s\t\t APELLIDO: %10s\t\t CUIL: %lli\t\n",
			auxCliente.id+1,
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


