/*
 * BlockChainDataTypes.h
 *
 *  Created on: 4 nov. 2020
 *      Author: Ramiro
 */

#ifndef BLOCKCHAINDATATYPES_H_
#define BLOCKCHAINDATATYPES_H_
#include <string>

//Interfaz entre FileManager Hacia Builder
typedef struct{
	int inTx;
	std::string * tableOfTxId;
	int * tableOfIndex ;
	std::string * tableOfAddr;
	int outTx;
	float * tableOfValues;
	std::string * tableOfAdd;
} raw_t;

//TODO DEFINIR INTERFAZ ENTRE BUILDER HACIA FILEMANAGER
typedef int blockchain_t;

#endif /* BLOCKCHAINDATATYPES_H_ */
