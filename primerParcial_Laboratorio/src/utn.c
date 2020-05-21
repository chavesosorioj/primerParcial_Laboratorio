/*
 * ejerUtn.c
 *
 *  Created on: Apr 14, 2020
 *      Author: juliana
 */
#include "utn.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
 int retorno =-1;
 int bufferInt;
 while(reintentos>=0)
 {
	 printf("%s",mensaje);
	 scanf("%d",&bufferInt);
	 __fpurge(stdin);
	 if(bufferInt >= minimo && bufferInt <= maximo)
	 {
		 *pResultado = bufferInt;
		 retorno=0;
		 break;
	 }
	 else
	 {
		 printf("%s", mensajeError);
		 reintentos--;
	 }

   }

return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin);
			scanf("%c",&buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}

int getInt(char mensaje[])
{
	int aux;
	printf("%s",mensaje);
	scanf("%d",&aux);
	return aux;
}

float getFloat(char mensaje[])
{
	float aux;
	printf("%s",mensaje);
	scanf("%f",&aux);
	return aux;
}

char getChar(char mensaje[])
{
	char aux;
	printf("%s",mensaje);
	__fpurge(stdin);
	scanf("%c",&aux);
	return aux;
}

int getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

float esFlotante(char* mensaje)
{
	char buffer[41];
	float valor;

	printf("%s",mensaje);
	__fpurge(stdin);
	fgets(buffer,40,stdin);//tenia gets()

	while(validaNumFlotante(buffer)==-1)
	{
		printf("Error, ingreso inválido. Vuelva a intentarlo: ");
		__fpurge(stdin);
		fgets(buffer,40,stdin);

	}

		valor =atof(buffer);

	return valor;
}

int validaNumFlotante(char* buffer)
{
	int retorno;
	int i;

	if(buffer != NULL && strlen(buffer) > 0)
	{
		for(i=0;i<strlen(buffer);i++)
		{
			if((buffer[i]=='.' || buffer[i]=='.')&& (buffer[i]<'9' || buffer[i]>'0'))
			{
				retorno=1;
			}
		}
	}
	else {
		retorno = -1;
	}
	return retorno;
}

int validaEntero(char* mensaje)
{
	int numeroValidado;
	char buffer[41];

	printf("%s",mensaje);
	__fpurge(stdin);
	fgets(buffer,40,stdin);

	while(esNumerico(buffer)==1)
	{
		printf("Error, lo ingresado no es numérico. Vuelva a intentarlo");
		__fpurge(stdin);
		fgets(buffer,40,stdin);
	}

	numeroValidado =atoi(buffer);


	return numeroValidado;
}



int esNumerico(char* cadena)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int esTelefono(char str[])
{	int i=0;
	int contadorGuion=0;
	while(str[i] != '\0')
	{
		 if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
		       return 0;
		if(str[i]== '-')
		{
			contadorGuion++;
		}
		i++;
	}
	if(contadorGuion ==1)
		return 1;

	return 0;
}

int esAlfanumerico(char str[])
{	int i=0;
	while(str[i] != '\0')
	{
		  if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
		       return 0;
		i++;
	}
	return 1;
}

int getStringNumeros(char mensaje[], char input[])
{
		char aux[256];
		getString(mensaje, aux);
		if(esNumerico(aux))
		{
			strcpy(input, aux);
			return 1;
		}
		return 0;
}

void inicializarArrayInt(int array[], int cantidad_de_elementos, int valor)
{
	int i;
	for(i=0; i<cantidad_de_elementos;i++)
	{
		array[i]=valor;
	}
}

int getStringLetras(char* msg,char* msgErr,char* pBuffer)
{
    char aux[51];
    int retorno=-1;
    do{
        getString(msg,aux);
        if(esSoloLetras(aux))
        {
            strcpy(pBuffer,aux);
            retorno=0;
            break;
        }
     msg=msgErr;
    }while(retorno!=0);
    return retorno;
}

int esSoloLetras(char str[])
{
    int i=0;
    int retorno = 1;
    if(str[i] == '\0')
        retorno = 0;
    else{
        while(str[i] != '\0')
        {
            if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
void getString(char msg[],char* pBuffer)
{
    printf("%s",msg);
    fflush(stdin);
    fgets(pBuffer, 51 , stdin);
    pBuffer[strcspn(pBuffer, "\n")] = 0;
    //gets(pBuffer);
}

int validaConfirmacion(void)
{
	int validar;


	validar =validaEntero("\nDesea continuar? Ingrese:\n1 - Si\n2 - No\n");
	while(validar != 1 && validar != 2)
	{
			printf("Error. Debe ingresar\n 1 - Si\n2 - No");
			__fpurge(stdin);
			scanf("%d",&validar);
	}
	return validar;
}
void tomarCuil(char *cuil)
{
	int bufferUno;
	int bufferDos;
	int bufferTres;
	char auxBufferUno[10];
	char auxBufferDos[10];
	char auxBufferTres[10];
	char buffer[1000];

	//system("clear");
	printf("\n Formato de cuil: XX-XXXXXXXX-X");

		bufferUno = validaEntero("\nIngrese los primeros dos números. [20-23-24-27 // 30-33-34]\n");
		while(bufferUno != 20 && bufferUno !=23 && bufferUno != 24 && bufferUno !=27 && bufferUno != 30 && bufferUno != 33 && bufferUno !=34)
		{
			bufferUno = validaEntero("\nEl número ingresado es incorrecto. Vuelva a intentarlo. [20-23-24-27 // 30-33-34]\n");
		}
		//system("clear");
		bufferDos = validaEntero("\nIngrese el número de DNI o numero de sociedad\n");
		while(bufferDos<1000000 || bufferDos>100000000)
		{
			bufferDos = validaEntero("\nError en cantidad de números. Vuelva a intentarlo.\n");
		}
		bufferTres = validaEntero("\nIngrese el último digito.");
		while(bufferTres<0 || bufferTres>10)
		{
			bufferTres = validaEntero("\nError. Debe ser un solo digito");
		}

		sprintf(auxBufferUno,"%d",bufferUno);
		sprintf(auxBufferDos,"%d",bufferDos);
		sprintf(auxBufferTres,"%d",bufferTres);

		strcpy(buffer,auxBufferUno);
		strcat(buffer,"-");
		strcat(buffer,auxBufferDos);
		strcat(buffer,"-");
		strcat(buffer, auxBufferTres);

		strcpy(cuil, buffer);

		printf("\nEl cuil es %s",buffer);
	printf("\n\tCuit cargado exitosamente\t\n");
    //system("clear");
}
