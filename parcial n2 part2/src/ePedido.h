/*
 * ePedido.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Matias
 */



#ifndef EPEDIDO_H_
#define EPEDIDO_H_



/// \brief modifica los datos del cliente.
/// \param int tam
/// \param Clientes* muestra
/// \param eLocalidad* localidadArray
/// \param int tamLocalidad
/// \param  int idModificar
/// \return retorna un entero;

int InicializarPedido( Pedido* clientes, int tam);

int buscarId(Clientes* muestra, int tam, int id);

int buscarIdPedido(Pedido* clientes, int tam, int id);


#endif /* EPEDIDO_H_ */
