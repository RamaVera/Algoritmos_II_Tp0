/*
 * Transaction.cpp
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */



#include "Transaction.h"
#include "TransactionInput.h"
#include "TransactionOutput.h"
#include <sstream>
#include <cstddef> // Para NULL

	//---Constructores---//

//Descripcion: Instancia el objeto Transaction vacio
//Precondicion: -
//Postcondicion: La lista de transacciones de entrada y salida apuntan a NULL
Transaction::Transaction(){
	this->n_tx_in = 0;
	this->n_tx_out = 0;
}

//Descripcion: Instancia el objeto Transaction a partir de un archivo raw_t
//Precondicion:
//Postcondicion: Dos punteros a memoria de tamaño definido creados y
// precargados con los datos de raw_t
Transaction::Transaction( const raw_t & Raw ){
	this->n_tx_in = Raw.inTx;
	for(int i = 0; i < this->n_tx_in ;i++ )
	{
		TransactionInput * pTxInput = new TransactionInput;
		pTxInput->setTxId(Raw.IN_tableOfTxId[i]);
		pTxInput->setIdx(Raw.IN_tableOfIndex[i]);
		pTxInput->setAddr(Raw.IN_tableOfAddr[i]);
		this->ListaTranIn.insertar(pTxInput);
	}
	this->n_tx_out = Raw.outTx;
	for(int i = 0; i < this->n_tx_out ;i++ )
	{
		TransactionOutput * pTxOutput = new TransactionOutput;
		pTxOutput->setValue(Raw.OUT_tableOfValues[i]);
		pTxOutput->setAddr(Raw.OUT_tableOfAddr[i]);
		this->ListaTranOut.insertar(pTxOutput);
	}
}


//Descripcion: Destruye elemento de Transaction
//Precondicion: Si se envia una transaccion nula no es necesario que se realice accion
//Postcondicion: Objeto destruido, memoria liberada, punteros a null y parametros a cero.
Transaction::~Transaction(){
	if( (n_tx_in != 0 ) || (n_tx_out != 0) || ! this->ListaTranIn.vacia() || ! this->ListaTranOut.vacia() ) {
		this->n_tx_in = 0;
		delete &ListaTranIn; //Invocacion explicita del destructor de lista^M
		this->n_tx_out = 0;
		delete &ListaTranOut; //Invocacion explicita del destructor de lista^M
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
//Precondicion: Si el indice esta fuera de rango debe devolver null
//Postcondicion:
TransactionInput * Transaction::getTransactionInput(int index){
	size_t index_ = (size_t)index;
	if( index < 0 || index_ > this->ListaTranIn.tamano())
		return NULL;
	else{
		lista <TransactionInput *>::iterador it(this->ListaTranIn);
		int counter = 0;
		while(counter != index){
			it.avanzar();
			counter++;
		}
		return it.dato();
	}
}

//Descripcion: Obtiene la transaccion de la lista de salidas
//Precondicion:  Si el indice esta fuera de rango debe devolver null
//Postcondicion:
TransactionOutput * Transaction::getTransactionOutput(int index){
	size_t index_ = (size_t)index;
	if( index < 0 || index_ > this->ListaTranOut.tamano())
		return NULL;
	else{
		lista <TransactionOutput *>::iterador it(this->ListaTranOut);
		int counter = 0;
		while(counter != index){
			it.avanzar();
			counter++;
		}
	return it.dato();
	}
}

//Descripcion: Devuelve un string de los valores concatenados de la listas
//para ser aplicado el hash correspondiente por fuera
//Precondicion: Se considera todo precargado antes
//Postcondicion:
std::string Transaction::getConcatenatedTransactions( void ){
       lista <TransactionInput *>::iterador itIn(this->ListaTranIn);
       lista <TransactionOutput *>::iterador itOut(this->ListaTranOut);
       std::ostringstream concatenation;
       concatenation << this->n_tx_in << '\n';
       for(itIn = ListaTranIn.primero(); !itIn.eol() ; itIn.avanzar()){
               concatenation<< itIn.dato()->getTxId() <<' ';
               concatenation<< itIn.dato()->getIdx()  <<' ';
               concatenation<< itIn.dato()->getAddr() <<'\n';
      }
       concatenation << this->n_tx_out << '\n';
      for(itOut = ListaTranOut.primero(); !itOut.eol() ; itOut.avanzar()){
              concatenation<< itOut.dato()->getValue() <<' ';
               concatenation<< itOut.dato()->getAddr()  <<'\n';
       }
       return concatenation.str();
}

