/*
 * Transaction.h
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include "TransactionInput.h"
#include "TransactionOutput.h"
#include "BlockChainDataTypes.h"
#include "lista.h"

class Transaction {
private:
	int n_tx_in; 					//Indica cantidad total de inputs
	TransactionInput * pInputs; 		// Lista de inputs
	int n_tx_out; 					//Indica cantidad total de outputs
	TransactionOutput * pOutputs;		// Lista de outputs

	// Vas a tener que meter algo asi, con lista o vectores
	lista <TransactionInput *> ListaTranIn;      // <- Con lista
	lista <TransactionOutput *> ListaTranOut;    // <- Con lista
public:
	//---Constructores---//
	Transaction();
	Transaction(int n_tx_in,int n_tx_out);
	Transaction( const & raw_t );
	~Transaction();
	//---Getters---//
	int getNumTransactionIn();
	int getNumTransactionOut();
	TransactionInput * getTransactionInput(int index);
	TransactionOutput * getTransactionOutput(int index);
	//---Setters---//
	//---Otros---//
};

#endif /* TRANSACTION_H_ */
