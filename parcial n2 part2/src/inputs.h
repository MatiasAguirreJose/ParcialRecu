/*
 * inputs.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Matias
 */

#ifndef INPUTS_H_
#define INPUTS_H_

/// \brief Se pide un char , se lo ingresa y valida si es un strig
/// \param mensaje[] char
/// \param entidad
/// \return int Retorna si es false o true enm caso de false se repite
int GetString(char mensaje[],char mensajeError[], char cadena[], int tam);


/// \brief valida si es un entero
/// \param int* pResultado
/// \return retorna false o true
int getInt(int* pResultado);

/// \brief valida si es un string
/// \param int* pResultad
/// \return int Retorna si es false o true
int esNumerica(char* cadena);

/// \brief Se pide un numero flotante, se lo ingresa y valida
/// \param har mensaje[]
/// \param float* pResultado
/// \return int Retorna un flotante
float getNumeroFloat(float* pResultado, char mensaje[]);

/// \brief verifica si no e sun string
/// \param float* pResultado)
/// \return int Retorna un entero
int getFloat(float* pResultado);

/// \brief Se pide un numero flotante, se lo ingresa y valida
/// \param har mensaje[]
/// \param float* pResultado
/// \return int Retorna un flotante
int esNumericaFloat(char* cadena);

/// \brief valida si es un string
/// \param char* cadena
/// \return int Retorna si es false o true
int esString(char* cadena);

/// \brief ingresa un numero y lo guarda
/// \param int* pResultado
/// \param char mensaje[]
/// \return retorna un entero
int getNumero(int* pResultado, char mensaje[]);

int IngresarEntero(char mensaje[],int min,int max);

#endif /* INPUTS_H_ */
