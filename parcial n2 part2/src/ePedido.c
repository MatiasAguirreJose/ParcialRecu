/*
 * ePedido.c
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

int InicializarPedido(Pedido* clientes, int tam){

int retorno;
retorno = -1;

if( tam>=0 && clientes !=NULL ){
	for (int i = 0; i < tam; i++) {
		clientes[i].isEmpty = TRUE;
		clientes[i].idCliente = 0;
		clientes[i].idRecoleccion = 0;


	}
	retorno = 0;
}


return retorno;
}

int buscarIdPedido(Pedido* clientes, int tam, int id){
	 int retorno = -1;
		for ( int j = 0;  j < tam;  j++){
				if( clientes[j].idCliente == id &&  clientes[j].isEmpty == FALSE){
					retorno = j;
			break;
				}
			}

	 return retorno;

 }
