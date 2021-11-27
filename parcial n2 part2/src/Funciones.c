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

#define TRUE 0
#define FALSE 1
#define TAM 10

void Opcion(void){
	puts("..[ingrese una opcion].. \n");
};
void SelecionarMenu(void){

	setbuf(stdout,NULL);

	puts("ingrese una opcion \n");
	puts("[1] - DAR DE ALTA \n");
	puts("[2] - MODIFICAR DATOS \n");
	puts("[3] - ELIMINAR ID \n");
	puts("[4] - CREAR PEDIDO DE RECOLECCION  \n");
	puts("[5] -  PROCESAR PEDIDOS \n");
	puts("[6] -  MOSTRAR CLIENTES  \n");
	puts("[7] -  MOSTRAR LOS PENDIENTES \n");
	puts("[8] -  MOSTRAR LOS PROCESADOS \n");
	puts("[9] -  MOSTRAR LOS PEDIDOS POR DIRECCION \n");
	puts("[10] -  MOSTRAR PEDIDOS POR CHOFER \n");
	puts("[11] -  PROMEDIO DE PROLIPOPRILENO  \n");
	puts("[12] -  PROMEDIO DE CLIENTES \n");
	puts("[13] -  **SALIR**  \n");

}





//--------------------------------------------------------------------------------------------------------!!
void MostrarDatos(Clientes* muestra,Pedido* pedido,eLocalidad* localidadArray, int tamanio, int tamLocalidad){



	if(muestra != NULL && tamanio >= 0 && pedido != NULL && localidadArray != NULL && tamLocalidad>=0){
		puts("ID          EMPRESA       LOCALIDAD       DIRECCION           CUIT	    PedidosPendientes");
	for ( int i = 0;  i < tamanio;  i++) {

		for ( int j = 0;  j <tamLocalidad;  j++){

		if(muestra[i].isEmpty == FALSE && muestra[i].idLocalidad== localidadArray[j].idLocalidad  ){
			printf("%d",muestra[i].idCliente);
			printf("%16s",muestra[i].Empresa);
			printf("%17s",localidadArray[j].Localidad);
			printf("%15d",muestra[i].direccion);
			printf("%17.1f",muestra[i].cuit);
			printf("%12d\n",muestra[i].PedidosPendientes);



		}


		}


	 }
	}
}


//--------------------------------------------------------------------------------------------------------!!
void MostrarDatosPendiente(Clientes* muestra,Pedido* pedido,eLocalidad* localidadArray, int tamanio, int tamLocalidad){

	char completado[128]="COMPLETADO";
	char pendiente[128]="PENDIENTE";
	int retorno = -1;

	if(muestra != NULL && tamanio >= 0 && pedido != NULL && localidadArray != NULL && tamLocalidad>=0){
		puts("ID          EMPRESA       LOCALIDAD       DIRECCION           CUIT	    ESTADO");
	for ( int i = 0;  i < tamanio;  i++) {

		for ( int j = 0;  j <tamLocalidad;  j++){

		if(muestra[i].isEmpty == FALSE && muestra[i].idLocalidad== localidadArray[j].idLocalidad  ){
			retorno = 0;
			printf("%d",muestra[i].idCliente);
			printf("%16s",muestra[i].Empresa);
			printf("%17s",localidadArray[j].Localidad);
			printf("%15d",muestra[i].direccion);
			printf("%17.1f",muestra[i].cuit);

			if(muestra[i].PedidosPendientes!=0){
				printf("%20s \n",pendiente);

			}else{
				printf("%20s \n",completado);
			}

		}


		}


	 }
	}

	if(retorno != 0){
		puts("no hay clientes");
	}
}


//2--------------------------------------------------------------------------------------------------------!!
int ModificarDatosCliente(Clientes* muestra,eLocalidad* localidadArray, int tam, int idModificar,int tamLocalidad){
int idlocalidad;
int buscarError;
int retorno = -1;
	for ( int i = 0;  i < tam;  i++) {
		if(muestra[i].idCliente == idModificar){
			retorno = 0;

			getNumero(&muestra[i].direccion, "Ingrese la direccion");

			do{
			getNumero(&idlocalidad, "Ingrese la Localidad");
			buscarError = BuscarLocalidadPorId(localidadArray, tamLocalidad, idlocalidad);
			}while(buscarError == -1);
			muestra[i].idLocalidad= idlocalidad;

			puts("se modifico con exito");
		}

	}

return retorno;
}


//4--------------------------------------------------------------------------------------------------------!!
int PedidoRecoleccion(Clientes* muestra, Pedido* clientes,eRecolector* recolector, int tam ,int tamchofer,  int idrecoleccion){
	int retorno = -1;
	int id;
	int kilos;

	int chofer;
	int buscarError;


	if(muestra != NULL &&  tam >= 0 ){

		getNumero(&id, "\nIngrese El Id");


		for ( int i = 0;  i < tam;  i++) {

			for ( int j = 0;  j < tam;  j++) {
			if(clientes[j].isEmpty == TRUE && muestra[i].idCliente == id){
				RecolectorMenu(recolector, tamchofer );
				do{
				getNumero(&chofer, "\nIngrese id dEl Chofer");
				buscarError = BuscarChoferPorId(recolector, tamchofer, chofer);
				}while(buscarError == -1);

				getNumero(&kilos, "\nIngrese los kilos");
				muestra[i].PedidosPendientes ++;
				clientes[j].idCliente = muestra[i].idCliente;
				clientes[j].kilos=kilos;
				clientes[j].idRecoleccion = idrecoleccion;
				clientes[j].idRecolector = chofer;
				if(clientes[j].idRecolector == chofer){
					muestra[j].PedidosPendientesChofer++;

				}


				clientes[j].isEmpty = FALSE ;

				retorno = 0 ;

				break;

			}

			}



			}
		}



	return retorno;
}
//6--------------------------------------------------------------------------------------------------------!!
void ImprimirClientes(Clientes* muestra, Pedido* clientes,eLocalidad* localidadArray,eRecolector* recolector, int tam , int lenlocalidad){


	if(muestra != NULL && tam >= 0 && clientes != NULL && localidadArray != NULL && lenlocalidad>=0){
			puts("ID          EMPRESA       LOCALIDAD       DIRECCION           CUIT	    PedidosPendientes          Estado");
		for ( int i = 0;  i < tam;  i++) {

			for ( int j = 0;  j <lenlocalidad;  j++){

			if(muestra[i].isEmpty == FALSE && muestra[i].idLocalidad== localidadArray[j].idLocalidad  ){
				printf("%d",muestra[i].idCliente);
				printf("%16s",muestra[i].Empresa);
				printf("%17s",localidadArray[j].Localidad);
				printf("%15d",muestra[i].direccion);
				printf("%17.1f",muestra[i].cuit);
				printf("%12d\n",muestra[i].PedidosPendientes);
				if(clientes[i].estado == FALSE){
					printf("PENDIENTE \n");
				}else{
					printf("COMPLETADO \n");
				}


			}


			}


		 }
		}


}
//7--------------------------------------------------------------------------------------------------------!!
int MostrarPedidosPendientes(Clientes* muestra, Pedido* clientes, int tam){
int retorno = -1;
	if(muestra != NULL &&clientes!= NULL && tam >= 0 ){


		for ( int i = 0;  i < tam;  i++) {

			for ( int j = 0;  j < tam;  j++){

			if(clientes[j].isEmpty == FALSE && muestra[i].isEmpty == FALSE
					&& muestra[i].idCliente == clientes[j].idCliente){



				printf("\nEl ID  %d \n",muestra[i].idCliente);
				printf("\nEl ID recoleccion  %d \n",clientes[j].idRecoleccion);
				printf("\n Tiene   %d pedidos pendientes \n",muestra[i].PedidosPendientes);
				printf("El CUit del cliente es %f \n",muestra[i].cuit);
				printf("La direccion  del cliente es %d \n",muestra[i].direccion);
				printf("los kilos totales que debe es de %d \n",clientes[j].kilos);
				retorno = 0;
			}

		}
		}


	}
	return retorno;

}
//9--------------------------------------------------------------------------------------------------------!!
void MostrarPorDireccion(Clientes* muestra,eLocalidad* localidadArray,int tamLocalidad, Pedido* clientes, int tam){


	int i;
	int SumaPedidos = 0;
	int buscarError;
	int idLocalidad;

	do{
	getNumero(&idLocalidad, "Ingrese la Localidad");
	buscarError = BuscarLocalidadPorId(localidadArray, tamLocalidad, idLocalidad);
	}while(buscarError == -1);

	for (i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {

		if(muestra[i].idLocalidad == idLocalidad && muestra[i].idCliente==clientes[j].idCliente){
			SumaPedidos += muestra[i].PedidosPendientes;

			break;

		}
		}
		}


	if(SumaPedidos!=0){
	printf("LOS PEDIDOS PENDIENTES CON ESA DIRECCION SON  %d \n",SumaPedidos);
	}else{


		puts("LOS PEDIDOS PENDIENTES CON ESA DIRECCION SON  CERO \n");
	}

	}


//10--------------------------------------------------------------------------------------------------------!!
void MostrarPorChofer(Clientes* muestra,eRecolector* ChoferArray,int tamChofer, Pedido* clientes, int tam){


	int i;

	int buscarError;
	int idRecolector;

	do{
	getNumero(&idRecolector, "Ingrese el Recolector");
	buscarError = BuscarChoferPorId(ChoferArray, tamChofer, idRecolector);
	}while(buscarError == -1);

	for (i = 0; i < tam; i++) {
		for(int j = 0; j<tam;j++){

		if(clientes[j].idRecolector == idRecolector && muestra[i].idCliente==clientes[j].idCliente && clientes[j].idRecolector ==  idRecolector){


			printf("LOS PEDIDOS PENDIENTES DE %s CON ESE RECOLECTOR SON  %d \n",muestra[i].Empresa, muestra[j].PedidosPendientesChofer);
			break;





		}
		}
		}





	}




//5--------------------------------------------------------------------------------------------------------!!
int ProcesarResiduos(Clientes* muestra, Pedido* clientes, int tam){

	int id;
	int i;
	int  kilosAuxiliar;
	int retorno = -1;
	int kilosalta;
	int kilosBAJA;


	//int pocision;

	int kilosTotales;

		getNumero(&id, "\nIngrese EL ID");

	 //pocision =  buscarIdPedido(clientes, tam, id);
	for (i = 0; i < tam; ++i) {
		for (int j = 0; j < tam; ++j){
		if (clientes[j].isEmpty == FALSE && clientes[j].idRecoleccion==id && clientes[j].idCliente==muestra[i].idCliente){

			kilosTotales = clientes[j].kilos;

			printf("Cantidad de Kilos totales son %d \n",kilosTotales);

			kilosAuxiliar = IngresarEntero("ingrese la cantidad de prolipropileno",0,kilosTotales) ;


			kilosTotales -=  kilosAuxiliar;

			printf("Cantidad de Kilos totales son %d \n",kilosTotales);
			kilosalta = IngresarEntero("ingrese la cantidad de polietileno de alta Intensidad",0,kilosTotales) ;

			kilosTotales-=kilosalta;
			printf("Cantidad de Kilos restantes %d \n",kilosTotales);


			kilosBAJA= IngresarEntero("ingrese la cantidad de polietileno de Baja Intensidad",0,kilosTotales )  ;
			kilosTotales -= kilosBAJA;

			printf("Cantidad de Kilos restantes %d \n",kilosTotales);

			retorno = 0;

			clientes[j].isEmpty = TRUE;
			clientes[j].kilos = TRUE;
			clientes[j].estado = FALSE;
			muestra[i].PedidosPendientes --;
			muestra[j].PedidosPendientesChofer--;
			muestra[i].PedidosCompletados++;

			if(	muestra[i].PedidosPendientes == 0) {
				clientes[j].isEmpty = TRUE;
			}

			break;






		}

		}
		}


		if(retorno != 0){
			puts("no se pudo cargar");
		}

		return  kilosAuxiliar ;
	}

//8--------------------------------------------------------------------------------------------------------!!
int MostrarPedidosProcesados(Clientes* muestra, Pedido* clientes, int tam){
int retorno;
retorno = -1;
	if(muestra != NULL && clientes!= NULL && tam >= 0 ){
	for (int i = 0; i < tam; ++i) {
		if (muestra[i].PedidosCompletados>=0 && clientes[i].isEmpty == TRUE && clientes[i].estado == FALSE){



			printf("el id %d \n",clientes[i].idCliente);
			printf("los pedidos prosesados son %d \n",	muestra[i].PedidosCompletados);
			retorno = 0;




		}
		}

		}
	return retorno;
	}

//10--------------------------------------------------------------------------------------------------------!!
void CalcularPromedio(Clientes* listado,Pedido* listadoRecoleccion,int len, int  polipropileno){
	    if(listado != NULL && listadoRecoleccion != NULL && len >= 0 && polipropileno>=0){
	        int resultado;
	        int contador=0;
	        for(int i = 0; i < len; i ++){
	            if(listado[i].isEmpty == FALSE){
	                contador++;
	            }
	        }

	        resultado = polipropileno / contador;

	        printf("El promedio de kilos de polipropileno por cliente es de : %d \n",resultado);
	    }
	    else{
	        printf("Datos cargados con error \n");
	    }

	}





//--------------------------------------------------------------------------------------------------------!!





void PromedioClientesMayor(Clientes* muestra, Pedido* clientes, int tam){
	char auxiliarchar[20];

		int flag;
		int pedidoMayor = 0;



			for (int i = 0; i < tam; ++i) {



			 				if(flag == 0 && muestra[i].PedidosCompletados > 0 && muestra[i].isEmpty==FALSE){

			 				flag = 1;
			 				 pedidoMayor = 	muestra[i].PedidosCompletados;
			 				strcpy(auxiliarchar , muestra[i].Empresa);

			 				}else{

			 					if( pedidoMayor >	muestra[i].PedidosCompletados){

			 					}else{
			 						 pedidoMayor =	muestra[i].PedidosCompletados;
			 						strcpy(auxiliarchar , muestra[i].Empresa);
			 					}


			 			}

			 }
			if(pedidoMayor == 0){
				puts("no hay cliente con pedidos COMPLETADOS");
			}else{
			 	printf("el cliente con mas pedidos completados es %s con %d pedidos  \n",auxiliarchar,pedidoMayor );
			}
}



 void PromedioClientesMenos(Clientes* muestra, Pedido* clientes, int tam){
	char auxiliarchar[20];

	int flag;
	int pedidoMayor = 0;



		for (int i = 0; i < tam; ++i) {



		 				if(flag == 0 && muestra[i].PedidosPendientes > 0 && muestra[i].isEmpty==FALSE){

		 				flag = 1;
		 				 pedidoMayor = 	muestra[i].PedidosPendientes;
		 				strcpy(auxiliarchar , muestra[i].Empresa);

		 				}else{

		 					if( pedidoMayor >	muestra[i].PedidosPendientes){

		 					}else{
		 						 pedidoMayor =	muestra[i].PedidosPendientes;
		 						strcpy(auxiliarchar , muestra[i].Empresa);
		 					}


		 			}

		 }
		if(pedidoMayor == 0){
			puts("no hay cliente con pedidos pendientes");
		}else{
		 	printf("el cliente con mas pedidos pendientes es %s con %d pedidos  \n",auxiliarchar,pedidoMayor );
		}

}

