/*
 * eLocalidad.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Matias
 */

#ifndef ELOCALIDAD_H_
#define ELOCALIDAD_H_


/// \brief busca la localidad por id
/// \param int tam
/// \param eLocalidad* localidadArray
/// \param int idLocalidad
/// \return retorna un entero
int BuscarLocalidadPorId(eLocalidad* localidadArray, int len, int idLocalidad);

/// \brief menu que muestra las localidades
/// \param eLocalidad* localidadArray
/// \param int lenLocalidad
/// \return no retorna nada
void LocalidadMenu(eLocalidad* localidadArray, int lenlocalidad);
#endif /* ELOCALIDAD_H_ */
