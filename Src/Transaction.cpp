/*
 * Transaction.cpp
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */



#include "Transaction.h"
#include "TransactionInput.h"
#include "TransactionOutput.h"

#ifndef NULL
	#define NULL 0;
#endif

	//---Constructores---//

//Descripcion: Instancia el objeto Transaction vacio
//Precondicion: -
//Postcondicion: La lista de transacciones de entrada y salida apuntan a NULL
Transaction::Transaction(){
	this->n_tx_in = 0;
	this->n_tx_out = 0;
	this->pInputs = NULL;
	this->pOutputs = NULL;
}

//Descripcion: Instancia el objeto Transaction de tamaño especifico
//Precondicion: Si por error se envia tamaño menor a 1 devuelve un Transaction vacio
//Postcondicion: Dos punteros a memoria de tamaño definido creados
Transaction::Transaction(int n_tx_in,int n_tx_out){
	if( (n_tx_in < 1) || (n_tx_out < 1) ){
		this->n_tx_in = 0;
		this->n_tx_out = 0;
		this->pInputs = NULL;
		this->pOutputs = NULL;
	}else{
		this->n_tx_in = n_tx_in;
		this->n_tx_out = n_tx_out;
		this->pInputs = new TransactionInput[n_tx_in];
		this->pOutputs = new TransactionOutput[n_tx_out];
	}

}

//Descripcion: Destruye elemento de Transaction
//Precondicion: Si se envia una transaccion nula no es necesario que se realice accion
//Postcondicion: Objeto destruido, memoria liberada, punteros a null y parametros a cero.
Transaction::~Transaction(){
	if( (n_tx_in != 0 ) || (n_tx_out != 0) ){
		delete [] this->pInputs ;
		delete [] this->pOutputs ;
		this->pInputs = NULL;
		this->pOutputs = NULL;
		this->n_tx_in = 0;
		this->n_tx_out = 0;
	}
}
//---Getters---//

//Descripcion: Devuelve cantidad de transacciones de input
//Precondicion:
//Postcondicion:
int Transaction::getNumTransactionIn(){
	return this->n_tx_in;
}

//Descripcion: Devuelve cantidad de transacciones de output
//Precondicion:
//Postcondicion:
int Transaction::getNumTransactionOut(){
	return this->n_tx_out;
}

//Descripcion: Obtiene la transaccion de la lista de entradas
//Precondicion:
//Postcondicion:
TransactionInput * Transaction::getTransactionInput(int index){
	if( index < this->n_tx_in )
		return &(this->pInputs[index]);
	else
		return NULL
}

//Descripcion: Obtiene la transaccion de la lista de entradas
//Precondicion:
//Postcondicion:
TransactionOutput * Transaction::getTransactionOutput(int index){
	if( index < this->n_tx_out )
		return &(this->pOutputs[index]);
	else
		return NULL
}
