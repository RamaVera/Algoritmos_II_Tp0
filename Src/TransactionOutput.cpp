/*
 * TransactionOutput.cpp
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#include "TransactionOutput.h"
#include <cstddef>

#ifndef HASH256_LENGTH
	#define HASH256_LENGTH 32
#endif
	//---Constructores---//

//Descripcion: Construye el objeto TransactionOutput vacio
//Precondicion:
//Postcondicion: Atributos inicializados en cero y en NULL
TransactionOutput::TransactionOutput(){
	this->value = 0;
	this->addr = NULL;
}

//Descripcion: Destruye el objeto TransactionOutput
//Precondicion:
//Postcondicion: Si el objeto habia pedido memoria dinamica
// se libera y postinicializa en null y atributos en cero
TransactionOutput::~TransactionOutput(){
	this->value = 0;
	if(this->addr != NULL){
		delete [] this->addr;
		this->addr = NULL;
	}
}
	//---Getters---//

//Descripcion: Devuelve el valor de Value
//Precondicion:
//Postcondicion:
float TransactionOutput::getValue(void) const{
	return this->value;
}

//Descripcion: Devuelve el arreglo de char del parametro addr
//Precondicion:
//Postcondicion: Debe ser un rvalue lo que devuelve
const char* TransactionOutput::getAddr(void) const{
	return this->addr;
}
	//---Setters---//

//Descripcion: Carga el atributo value
//Precondicion:
//Postcondicion:
void TransactionOutput::setValue(float value){
	this->value = value;

}

//Descripcion: Carga el atributo addr
//Precondicion: Se asume que addr siempre sera de tamaño 32
//Postcondicion: Se genera un arreglo dinamico de tamaño de hash de 32
void TransactionOutput::setAddr(char* addr){
	this->addr = new char[HASH256_LENGTH];
	for(int i = 0 ; i < HASH256_LENGTH ; i++)
			this->addr[i] = addr[i];
}

