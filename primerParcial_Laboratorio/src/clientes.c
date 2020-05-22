/*
 * empleados.c
 *
 *  Created on: May 9, 2020
 *      Author: juliana
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

#include "prestamos.h"
#include "clientes.h"
#include "menu.h"
#include "utn.h"


void inicializar_clientes(eClientes lista[], int tam)
{
	int i;
	if(lista != NULL && tam>0)
	{
		for(i=0; i<tam;i++)
			{
				lista[i].isEmpty=LIBRE;
			}
	}
}

void hardcodeo_clientes(eClientes* lista)
{
    int harcodeo = 6;

    int ID[6]                      ={1000,1001,1002,1003,1004,1005};
    char nombre[6][51]        ={"Eduardo","Maria", "Cristina", "Sabrina", "Gabriel","Tomas"};
    char apellido[6][51]={"Casarero","Gomez", "Sanchez", "Villar", "Chaves","Gallegos"};
    char cuil[6][50] = {"27111111111","27222222221","27333333331","27444444441","27555555551","27666666661"};
    for(int i=0; i<harcodeo; i++)
    {
    	lista[i].id=ID[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].apellido, apellido[i]);
        strcpy(lista[i].cuil, cuil[i]);
        lista[i].isEmpty=OCUPADO;
    }
}

int espacioLibre(eClientes lista[], int tam)
{	int i;
	int retorno=-1;
	for(i=0; i<tam;i++)
	{
		if(lista[i].isEmpty== LIBRE)
		{
			return i;
			break;
		}
	}
	return retorno;
}

int agregarMasClientes(void)
{
	int validar;


	validar =validaEntero("\nDesea continuar agregando clientes? Ingrese:\n1 - Si\n2 - No\n");
	while(validar != 1 && validar != 2)
	{
			printf("Error. Debe ingresar\n 1 - Si\n2 - No");
			__fpurge(stdin);
			scanf("%d",&validar);
	}
	return validar;
}

int altaCliente(eClientes lista[], int tam, int legajo)
{
	eClientes nuevoCliente;
	int retorno =-1;
	char nombre[50];
	char apellido[50];
	char cuil[50];
	int indice;

	if(lista != NULL && tam >0)
	{
		system("clear");
		__fpurge(stdin);

		printf("\n\t*********ALTA*********\t\n");

		indice = espacioLibre(lista, TAM_CLIENTES);
		if(indice==-1)
		{
			printf("\n|**********No hay espacios libres**********|\n");
		}
		else
		{
			getName(nombre, TAM_NOMBRE);
			getLastName(apellido,TAM_APELLIDO);
			tomarCuil(cuil);

			nuevoCliente.id=legajo;
			strcpy(nuevoCliente.nombre,nombre);
			strcpy(nuevoCliente.apellido,apellido);
			strcpy(nuevoCliente.cuil,cuil);
			nuevoCliente.isEmpty=OCUPADO;
			lista[indice] =nuevoCliente;

		printf("\n**********CARGA EXITOSA**********\n");
		retorno=1;
		}

	}
	return retorno;
}

void mostrarCliente(eClientes lista)
{
	printf("\n\t%d\t\t%s\t\t%s\t\t%s\t\n",
			lista.id,
			lista.nombre,
			lista.apellido,
			lista.cuil
	);

}
void mostrarClientes(eClientes list[],int len)
{

    printf("\n\tID\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
        	mostrarCliente(list[i]);
        }
    }

}

int buscarIdCliente(int* id, int tam, eClientes lista[])
{
	int indice=-1;
	int i;
	for(i=0;i<tam;i++)
	{
		if(lista[i].isEmpty == OCUPADO && lista[i].id==*id)
		{
			indice=i;
			break;
		}
	}
	return indice;
}
int cantidadOcupadoCliente(eClientes *lista, int tam)
{

    int cantOcupados=0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
            cantOcupados =1;
            break;
        }
    }
    return cantOcupados;
}

int darBaja(eClientes lista[], int tam)
{
	int retorno=-1;
	int indice;
	int verifBaja=0;
	int verifIndice;
	int aux;

	printf("*********BAJA*********");
	verifIndice = cantidadOcupadoCliente(lista, TAM_CLIENTES);
	if(verifIndice==0)
	{
		printf("\n\tNo hay clientes para dar de baja\t\n");
	}
	else
	{
		aux = validaEntero("\n\tIngrese el número de ID que quiere dar de baja\t\n");
		indice = buscarIdCliente(&aux, TAM_CLIENTES, lista);

		if(indice==-1)
		{
			printf("\n\tNo hay ningun empleado con ese ID\t\n");
		}
		else
		{
			mostrarCliente(lista[indice]);
			verifBaja= validaEntero("\n\tConfirma desea eliminar el ID? \n   1 - SI\n    2- NO\t\n");
			if(verifBaja==1)
			{
				printf("\n\tBaja exitosa\t\n");
				lista[indice].isEmpty=LIBRE;
				retorno=1;
			}
			else
			{
					printf("\n\tSe ha cancelado la baja\t\n");
			}
		}

	}

	return retorno;
}


int modificar(eClientes lista[], int tam)
{
	int retorno = -1;
	int buscaId;
	int verificacion;
	int auxIndice;
	int confirmacion;
	char nombre[51];
	char apellido[51];
	char cuil[51];

	//system("clear");
	printf("*********MODIFICACION*********");


	verificacion = cantidadOcupadoCliente(lista, TAM_CLIENTES);
	if(verificacion ==0)
	{
		printf("\n\tNo hay datos para modificar\t\n");
	}
	else
	{
		auxIndice = validaEntero("\n\tIngrese el id que quiere modificar\t\n");
		buscaId = buscarIdCliente(&auxIndice, tam, lista);
		if(buscaId == -1)
		{
			printf("\n\tNo hay cliente con ese id\t\n");
		}
		else
		{
			printf("\n\tSe modificará el ID %d\n\t",auxIndice);

			switch(menuUno())
			{
				case 1:
				{
					//system("clear");
					confirmacion = validaEntero("\t\nConfirma desea modificar el nombre? \n   1 - SI\n    2- NO\t\n");
					if(confirmacion == 1 )
					{
						getName(nombre, TAM_NOMBRE);
						strcpy(lista[auxIndice].nombre,nombre);
						printf("\n\tSe realizo la modificación\t\n");
						retorno=1;
					}
					else
					{
						printf("\n\tSe cancelo la modificación\t\n");
					}
				}
					break;
				case 2:
				{	//system("clear");
					confirmacion = validaEntero("\n\tConfirma desea modificar el apellido? \n   1 - SI\n    2- NO\t\n");
					if(confirmacion == 1 )
					{
						getLastName(apellido, TAM_APELLIDO);
						strcpy(lista[auxIndice].apellido,apellido);
						printf("\n\tSe realizo la modificación\t\n");
						retorno = 1;
					}
					else
					{
						printf("\n\tSe cancelo la modificación\t\n");
					}
				}
					break;
				case 3:
					//system("clear");
					confirmacion = validaEntero("\t\nConfirma desea modificar el cuil? \n   1 - SI\n    2- NO\t\n");
					if(confirmacion==1)
					{
						tomarCuil(cuil);
						strcpy(lista[auxIndice].cuil,cuil);
						printf("\n\tSe realizo la modificación\t\n");
						retorno=1;
					}
					else
					{
						printf("\n\tSe cancelo la modificación\t\n");
					}
					break;

			}
		}
	}
	return retorno;
}


int cantidadPrestamosCliente(int id,ePrestamo prestamos[], int tamP)
{
	int i;
	int cantidadPrestamos=0;

	if(prestamos!=NULL && tamP>0)
	{
		for(i=0;i<tamP;i++)
		{
			if(prestamos[i].clienteId== id && prestamos[i].estado==ACTIVO)
			{
				cantidadPrestamos++;
			}
		}
	}
	return cantidadPrestamos;
}
int imprimirClientePrestamos(eClientes clientes[],ePrestamo prestamos[],int tamC, int tamP)
{
	int retorno =-1;
	int i;
	int verifIndice;

	if(clientes != NULL && prestamos != NULL && tamC>0 && tamP >0)
	{
		//system("clear");
		printf("*********CLIENTE CON PRESTAMOS ACTIVOS*********");
		verifIndice = cantidadOcupadoCliente(clientes, TAM_CLIENTES);
		if(verifIndice==0)
		{
			printf("\n\tNo hay clientes cargados\t\n");
		}
		else
		{
			printf("\n\tID\t\tNOMBRE\t\tAPELLIDO\t\tCUIL\t\tPRESTAMOS ACTIVOS\t\n");
				for(i=0;i<tamC;i++)
				{
					if(clientes[i].isEmpty==OCUPADO)
					{
						printf("\n\t%d\t\t%10s\t\t%10s\t\t%14s\t\t%d\t\n",
								clientes[i].id,
								clientes[i].nombre,
								clientes[i].apellido,
								clientes[i].cuil,
								cantidadPrestamosCliente(clientes[i].id, prestamos, TAM_PRESTAMOS)
						);
										retorno=1;

					}
				}
		}
	}
	return retorno;
}
