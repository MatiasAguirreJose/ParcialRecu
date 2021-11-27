/*
 * eCliente.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Matias
 */

#ifndef ECLIENTE_H_
#define ECLIENTE_H_



/// \brief añade un clientee
/// \param int tam
/// \param Clientes* muestra
/// \param int tamanio
/// \param int id
/// \param char empresa[]
/// \param int localidad
/// \param float cuit
/// \param int direccion
/// \return retorna un entero

int AniadirCliente(Clientes* muestra, int tamanio,int id,char empresa[],int localidad, float cuit, int direccion);

/// \brief inicializa un cliente.
/// \param int tam
/// \param Clientes* muestra
/// \param   Pedido* clientes
/// \return retorna un entero;
int InicializarClientes(Clientes* muestra,  int tam);

/// \brief elimina un cliente.
/// \param int tam
/// \param Clientes* muestra
/// \param int idEliminar
/// \return no retorna nada;
void ElimiarCliente(Clientes* muestra, int tam, int idEliminar);


int buscarId(Clientes* muestra, int tam, int id);
#endif /* ECLIENTE_H_ */
