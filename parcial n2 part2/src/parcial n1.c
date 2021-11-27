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
#define TAM 100
#define TAMPEDIDO 1000
#define TAMLOCALIDAD 3
#define TAMCHOFER 3
int main(void) {
	setbuf(stdout,NULL);

	char Empresa[10];

	int Direccion;
	float Cuit;
	int idLocalidad;
	int buscarError ;
	int polipropileno = 0 ;
	int id=1;


	int idModificar;
	int idEliminar;
	int PedidosProcesadosDato;
	int PedidosPendientesDato;
	int idrecoleccion = 1;

	Clientes muestra[TAM];
	Pedido clientes[TAMPEDIDO];

	eLocalidad localidadArray[3] =
	{
			{100, "Avellaneda"},
			{101, "Lanus"},
			{102, "Quilmes"},
	};

	eRecolector Recolector[3] =
	{
			{200, "Robert", 3},
			{201, "Lucas", 5},
			{202, "Mariano", 7},

	};





	InicializarClientes( muestra, TAM);
	InicializarPedido( clientes,  TAM);
	int opcion;

	SelecionarMenu();
	do{
	scanf("%d",&opcion);



		switch (opcion) {
			case 1:








				do{
				buscarError = GetString("ingrese la Empresa","ERROR iNGRESE DE NUEVO ", Empresa, 10) ;
				}while(buscarError == -1);

				LocalidadMenu( localidadArray ,TAMLOCALIDAD);

				do{
				getNumero(&idLocalidad, "\nIngrese la Localidad");
				buscarError = BuscarLocalidadPorId(localidadArray, TAMLOCALIDAD, idLocalidad);
				}while(buscarError == -1);


				getNumero(&Direccion, "Ingrese la direccion");

				getNumeroFloat(&Cuit,"ingrese el cuit");

				if(AniadirCliente(muestra, TAM, id, Empresa, idLocalidad,Cuit,Direccion) == 0){
					id++;
					puts("cliente cargado exitosamente");
				}else {
					puts("no se puedo ingresar exitosamente");
				}

				Opcion();

			break;

			case 2:


				getNumero(&idModificar, "Ingrese el id del cliente que quiere modificar:");


				buscarError = ModificarDatosCliente(muestra, localidadArray, TAM, idModificar,TAMLOCALIDAD);
				if(buscarError == -1){
					puts("No existe ese ID");
				}
				Opcion();
			break;
			case 3:
				getNumero(&idEliminar, "Ingrese el id del cliente que quiere eliminar:");

				ElimiarCliente(muestra,  TAM, idEliminar);
				Opcion();
			break;

			case 4:

				MostrarDatos(muestra,clientes, localidadArray,TAM,TAMLOCALIDAD);

				buscarError = PedidoRecoleccion( muestra,clientes,Recolector, TAM,TAMCHOFER,idrecoleccion);
				if(buscarError != -1){

					idrecoleccion++;
				}else{
					puts("No se encontro el id");
				}

				Opcion();
				break;
			case 5:
				MostrarPedidosPendientes(muestra, clientes, TAM);
				polipropileno += ProcesarResiduos(muestra,  clientes, TAM);
				Opcion();
				break;

			case 6:

				MostrarDatosPendiente(muestra,clientes, localidadArray,TAM,TAMLOCALIDAD);
				Opcion();
			break;

			case 7:

				PedidosPendientesDato = MostrarPedidosPendientes(muestra, clientes, TAM);
				if(PedidosPendientesDato == -1){
					puts("no hay Pedidos Pendientes");
				}
				Opcion();
				break;

			case 8:
				PedidosProcesadosDato = MostrarPedidosProcesados(muestra, clientes, TAM);

				if(PedidosProcesadosDato == -1){
					puts("no hay Pedidos Procesados");
				}
				Opcion();
				break;
			case 9:
				LocalidadMenu( localidadArray ,TAMLOCALIDAD);
				MostrarPorDireccion(muestra, localidadArray,TAMLOCALIDAD, clientes,TAM);
				Opcion();
				break;
			case 10:
				RecolectorMenu(Recolector, TAMCHOFER );
				MostrarPorChofer(muestra, Recolector,TAMCHOFER, clientes,TAM);
				Opcion();
				break;

			case 11:

				CalcularPromedio( muestra, clientes, TAM, polipropileno);
				Opcion();
				break;
			case 12:
				PromedioClientesMayor(muestra, clientes, TAM);
				PromedioClientesMenos(muestra, clientes, TAM);

				Opcion();
				break;


		}





	}while(opcion != 13);

	return EXIT_SUCCESS;
}

