/*
 * eRecolector.c
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

int BuscarChoferPorId(eRecolector* RecolectorArray, int len, int idchofer){
	int retorno = -1;
	int i;
	for (i = 0; i < len; ++i) {

		if(RecolectorArray[i].idRecolector ==  idchofer){
			retorno = 0;

		}
	}


	return retorno;

}


void RecolectorMenu(eRecolector* RecolectorArray, int lenRecolector){
		int i;

		puts("La recolectores son\n");

		for (i = 0; i < lenRecolector; ++i) {
			printf("%d %s %d \n",RecolectorArray[i].idRecolector,RecolectorArray[i].chofer,RecolectorArray[i].Antiguedad);

		}



}

