/*
 * eCliente.c
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

int InicializarClientes(Clientes* muestra, int tam){


	int retorno;
	retorno = -1;

	if(muestra != NULL && tam>=0  ){
		for (int i = 0; i < tam; i++) {

			muestra[i].PedidosCompletados = 0;
			muestra[i].PedidosPendientes = 0;
			muestra[i].PedidosPendientesChofer= 0;
			muestra[i].idCliente=0;
			muestra[i].isEmpty = TRUE;


		}
		retorno = 0;
	}


	return retorno;

}

//1--------------------------------------------------------------------------------------------------------!!
int AniadirCliente(Clientes* muestra, int tamanio,int id,char empresa[],int localidad, float cuit, int direccion){
	setbuf(stdout,NULL);
	int retorno ;
	retorno = -1;


	if(muestra != NULL && tamanio >= 0 && id >= 0){

     for ( int i = 0;  i < tamanio; ++ i) {


    		 if(muestra[i].isEmpty == TRUE   ){
			muestra[i].idCliente = id;
			strcpy(muestra[i].Empresa, empresa);
			muestra[i].idLocalidad = localidad;
			muestra[i].direccion = direccion;
			muestra[i].cuit = cuit;
			muestra[i].isEmpty = FALSE;

			retorno = 0;

			 break;
    		 }



	  }

	}
return retorno;
}

//3--------------------------------------------------------------------------------------------------------!!
void ElimiarCliente(Clientes* muestra, int tam, int idEliminar){
	int Respuesta;


	for ( int i = 0;  i < tam;  i++) {

		if(muestra[i].idCliente == idEliminar){
			printf("Esta seguro que quiere eliminar? 1- si  2- no");
			fflush(stdin);
			scanf("%d",&Respuesta);

			if(Respuesta == 1){

				muestra[i].isEmpty = TRUE;
		}else {
			puts("no se elimino .... ");
		}


		}
	}


}
int buscarId(Clientes* muestra, int tam, int id){

	 int retorno = -1;
			for ( int j = 0;  j < tam;  j++){
					if( muestra[j].idCliente == id &&  muestra[j].isEmpty == FALSE){
						retorno = j;
				break;
					}
				}

		 return retorno;
}
