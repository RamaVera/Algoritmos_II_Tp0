/*
 * TransactionInput.cpp
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#include "TransactionInput.h"

#ifndef NULL
	#define NULL 0;
#endif

//---Constructores---//
TransactionInput::TransactionInput(){
	this->outpoint.idx = 0;
	this->outpoint.tx_id =NULL;
	this->addr = NULL;
}

TransactionInput::~TransactionInput(){
	this->outpoint.idx = 0;
	this->outpoint.tx_id =NULL;
	this->addr = NULL;
}
//---Getters---//
outpoint_t TransactionInput::getOutpoint(void) const{
	return this->outpoint;
}
char* TransactionInput::getTxId(void) const{
	return this->outpoint.tx_id;
}
int TransactionInput::getIdx(void) const{
	return this->outpoint.idx;
}
char* TransactionInput::getAddr(void) const{
	return this->addr;
}
//---Setters---//
void TransactionInput::setOutpoint(const outpoint_t & Outpoint){
	this->outpoint.idx = Outpoint.idx;
	this->outpoint.tx_id = Outpoint.tx_id;

}
void TransactionInput::setTxId(char* tx_id){

}
void TransactionInput::setIdx(int idx){

}
void TransactionInput::setAddr(char* addr){

}
