struct{
	int idRecoleccion;
	int idCliente;
	int flag;
	int estado;
	int idRecolector;
	int kilos;
	int isEmpty;
	int promedioCliente;


}typedef Pedido;

struct{
	 int idCliente ;
	 char Empresa[21];
	 int PedidosPendientes;
	 int PedidosCompletados;
	 int idLocalidad ;
	 float cuit;
	 int direccion;
	 int isEmpty;
	 int PedidosPendientesChofer ;
}typedef Clientes;


struct{
	int idRecolector;
	char chofer[30];
	int Antiguedad;

}typedef eRecolector;

struct{
	int idLocalidad;
	char Localidad[30];

}typedef eLocalidad;

#define TRUE 0
#define FALSE 1


/// \brief mensaje menu.
/// \return no retorna nada
void SelecionarMenu(void);

/// \brief mensaje opcion.
/// \return no retorna nada
void Opcion(void);


/// \brief muestra los datos del cliente.
/// \param int tam
/// \param Clientes* muestra
/// \param eLocalidad* localidadArray
/// \param int tamanio
/// \param int tamLocalidad
/// \return no retorna nada
void MostrarDatos(Clientes* muestra,Pedido* pedido,eLocalidad* localidadArray, int tamanio, int tamLocalidad);



int ModificarDatosCliente(Clientes* muestra,eLocalidad* localidadArray, int tam, int idModificar,int tamLocalidad);
/// \brief crea el pedido de recoleccion.
/// \param int tam
/// \param Clientes* muestra
/// \param Pedido* clientes
/// \return retorna un entero;
int PedidoRecoleccion(Clientes* muestra, Pedido* clientes,eRecolector* recolector, int tam ,int tamchofer,  int idrecoleccion);
/// \brief Imprime los clientes.
/// \param int tam
/// \param Clientes* muestra
/// \param eLocalidad* localidadArray
/// \param int tamLocalidad
/// \param Pedido* clientes
/// \return no retorna nada;
void ImprimirClientes(Clientes* muestra, Pedido* clientes,eLocalidad* localidadArray,eRecolector* recolector, int tam , int lenlocalidad);
/// \brief muestra los pedidos pendientes .
/// \param int tam
/// \param Clientes* muestra
/// \param Pedido* clientes
/// \return retorna un entero;
int MostrarPedidosPendientes(Clientes* muestra, Pedido* clientes, int tam);
/// \brief muestra los pedidos pendientes de esa localidad.
/// \param int tam
/// \param Clientes* muestra
/// \param eLocalidad* localidadArray
/// \param int tamLocalidad
/// \param Pedido* clientes
/// \return no retorna nada;
void MostrarPorDireccion(Clientes* muestra,eLocalidad* localidadArray,int tamLocalidad, Pedido* clientes, int tam);
/// \brief procesa los residuos pendientes.
/// \param int tam
/// \param Clientes* muestra
/// \param Pedido* clientes
/// \return int Retorna el numero enviado;
int ProcesarResiduos(Clientes* muestra, Pedido* clientes, int tam);
/// \brief Muestra los pedidos procesados.
/// \param int tam
/// \param Clientes* muestra
/// \param Pedido* clientes
/// \return int Retorna el numero enviado;
int MostrarPedidosProcesados(Clientes* muestra, Pedido* clientes, int tam);
/// \brief Se pide el promedio.
/// \param Clientes* muestra
/// \param Pedido* clientes
/// \param int cantidadCliente
/// \param int polipropileno
/// \return no retorna nada;
void CalcularPromedio(Clientes* muestra, Pedido* clientes, int cantidadCliente,int polipropileno);



/// \brief promedio del cliente con mayor pedidos pendientes
/// \param int tam
/// \param Clientes* muestra
/// \param Clientes* clientes
/// \return no retorna nada
void PromedioClientesMayor(Clientes* muestra, Pedido* clientes, int tam);
/// \brief promedio del cliente con mayor pedidos procesados
/// \param int tam
/// \param Clientes* muestra
/// \param Clientes* clientes
/// \return no retorna nada
void PromedioClientesMenos(Clientes* muestra, Pedido* clientes,  int tam);
/// \brief promedio del cliente con mayor pedidos
/// \param int tam
/// \param Clientes* muestra
/// \param Clientes* clientes
/// \return no retorna nada
void PromedioClientesMasPedidos(Clientes* muestra, Pedido* clientes,  int tam);





void MostrarPorChofer(Clientes* muestra,eRecolector* ChoferArray,int tamChofer, Pedido* clientes, int tam);

void MostrarDatosPendiente(Clientes* muestra,Pedido* pedido,eLocalidad* localidadArray, int tamanio, int tamLocalidad);

