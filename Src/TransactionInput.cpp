/*
 * TransactionInput.cpp
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#include "TransactionInput.h"
#include <cstddef> // Para NULL

#ifndef HASH256_LENGTH
	#define HASH256_LENGTH 32
#endif

	//---Constructores---//

//Descripcion: Construye el objeto TransactionInput vacio
//Precondicion:
//Postcondicion: Todos los parametros a null y iniciados en 0
TransactionInput::TransactionInput(){
	this->outpoint.idx = 0;
	this->outpoint.tx_id = NULL;
	this->addr = NULL;
}

//Descripcion: Destruye el objeto TransactionInput
//Precondicion:
//Postcondicion: Todos los parametros a null y iniciados en 0
TransactionInput::~TransactionInput(){
	this->outpoint.idx = 0;
	if (this->outpoint.tx_id != NULL){
		delete [] this->outpoint.tx_id;
		this->outpoint.tx_id = NULL;
	}
	if (this->addr != NULL){
		delete [] this->addr;
		this->addr = NULL;
	}

}

	//---Getters---//

//Descripcion: Devuelve un la estructura outpoint_t
//Precondicion:
//Postcondicion:
const outpoint_t TransactionInput::getOutpoint(void) const{
	return this->outpoint;
}

//Descripcion: Devuelve el parametro tx_id del outpoint
//Precondicion:
//Postcondicion:
const char* TransactionInput::getTxId(void) const{
	return this->outpoint.tx_id;
}

//Descripcion: Devuelve el parametro idx del outpoint
//Precondicion:
//Postcondicion:
int TransactionInput::getIdx(void) const{
	return this->outpoint.idx;
}

//Descripcion: Devuelve el parametro addr
//Precondicion:
//Postcondicion:
const char* TransactionInput::getAddr(void) const{
	return this->addr;
}

	//---Setters---//

//Descripcion: Carga los atributos del outpoint
//Precondicion: Se pasa por referencia el Outpoint deseado
//Postcondicion:
void TransactionInput::setOutpoint(const outpoint_t & Outpoint){
	this->outpoint.idx = Outpoint.idx;
	this->outpoint.tx_id = Outpoint.tx_id;

}

//Descripcion: Carga el atributo tx_id
//Precondicion: Se asume que tx_id siempre sera de tamaño 32
//Postcondicion: Se genera un arreglo dinamico de tamaño de hash de 32
void TransactionInput::setTxId(char* tx_id){
	this->outpoint.tx_id = new char[HASH256_LENGTH];
	for(int i=0 ; i < HASH256_LENGTH ; i++)
		this->outpoint.tx_id[i] = tx_id[i];
}

//Descripcion: Carga el atributo idx
//Precondicion:
//Postcondicion:
void TransactionInput::setIdx(int idx){
	this->outpoint.idx = idx;
}

//Descripcion: Carga el atributo addr
//Precondicion: Se asume que addr siempre sera de tamaño 32
//Postcondicion: Se genera un arreglo dinamico de tamaño de hash de 32
void TransactionInput::setAddr(char* addr){
	this->addr = new char[HASH256_LENGTH];
	for(int i = 0 ; i < HASH256_LENGTH ; i++)
		this->addr[i] = addr[i];
}
