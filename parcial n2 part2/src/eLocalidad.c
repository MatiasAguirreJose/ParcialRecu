/*
 * eLocalidad.c
 *
 *  Created on: 25 nov. 2021
 *      Author: Matias
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Funciones.h"
#include "eCliente.h"
#include "ePedido.h"
#include "inputs.h"
#include "eRecolector.h"
#include "eLocalidad.h"

int BuscarLocalidadPorId(eLocalidad* localidadArray, int len, int idLocalidad){
	int retorno = -1;
	int i;
	for (i = 0; i < len; ++i) {

		if(localidadArray[i].idLocalidad ==  idLocalidad){
			retorno = 0;

		}
	}


	return retorno;

}
void LocalidadMenu(eLocalidad* localidadArray, int lenlocalidad){
		int i;

		puts("La localidades son\n");

		for (i = 0; i < lenlocalidad; ++i) {
			printf("%d %s \n",localidadArray[i].idLocalidad,localidadArray[i].Localidad);

		}



}
