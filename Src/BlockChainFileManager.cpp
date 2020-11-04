/*
 * BlockChainFileManager.cpp
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#include "BlockChainFileManager.h"



BlockChainFileManager::BlockChainFileManager() {
	// TODO Auto-generated constructor stub
}

BlockChainFileManager::~BlockChainFileManager() {
	// TODO Auto-generated destructor stub
}

status_t BlockChainFileManager::validate(std::istream * iss){
	int inTxTotal,outTxTotal;

	if( this->isTxIndexFromStream(iss,'\n',&inTxTotal) == false ) 	return STATUS_CORRUPT_FORMAT_BAD_TXIN;
	for(int inTx = 0 ; inTx < inTxTotal ; inTx++){
		if( this->isHashFromStream(iss,' ') == false ) 				return STATUS_CORRUPT_FORMAT_BAD_HASH;
		if( this->isTxIndexFromStream(iss,' ') == false ) 			return STATUS_CORRUPT_FORMAT_BAD_TXINDEX;
		if( this->isHashFromStream(iss) == false ) 					return STATUS_CORRUPT_FORMAT_BAD_HASH;
	}
	if( this->isTxIndexFromStream(iss,'\n',&outTxTotal) == false ) 	return STATUS_CORRUPT_FORMAT_BAD_TXOUT;
	for(int outTx = 0 ; outTx < outTxTotal ; outTx++){
		if( this->isBTCValueFromStream(iss,' ') == false ) 			return STATUS_CORRUPT_FORMAT_BAD_BTCVALUE;
		if( this->isHashFromStream(iss) == false ) 				    return STATUS_CORRUPT_FORMAT_BAD_HASH;
	}
	if( this->isEofFromStream(iss) == false ) 						return STATUS_CORRUPT_FORMAT;

	return STATUS_OK;
}

bool BlockChainFileManager::isTxIndexFromStream(std::istream *iss,char delim , int * pValue)
{
	int IndexValue;
	std::string line;
	std::stringstream ss;

	std::getline(*iss, line,delim);
	ss.str(line);
	if ((ss >> IndexValue).fail())	  return false;
	if (IndexValue < 0) 			  return false;
	//Debug
	//std::cout << line << std::endl;
	if(pValue != NULL) *pValue = IndexValue;
	return true;
}

bool BlockChainFileManager::isHashFromStream(std::istream *iss,char delim, std::string * pString)
{
	std::string line;
	std::stringstream ss;
	std::getline(*iss, line,delim);
	if ( line.size() != 64 ) return false;
	//Debug
	//std::cout << line << std::endl;
	if(pString != NULL) *pString = line;
	return true;

}

bool BlockChainFileManager::isBTCValueFromStream(std::istream *iss,char delim,float * pFloat)
{
	float floatValue;
	std::string line;
	std::stringstream ss;

	std::getline(*iss, line,delim);
	ss.str(line);
	if ((ss >> floatValue).fail())	  return false;
	if (floatValue < 0) 			  return false;
	//Debug
	//std::cout << line << std::endl;
	if(pFloat != NULL) *pFloat = floatValue;
	return true;
}

bool BlockChainFileManager::isEofFromStream(std::istream *iss){
	std::string line;
	return (std::getline(*iss, line))? false : true;
}


status_t BlockChainFileManager::parse(std::istream * iss, raw_t * &pRawData){
	//Vuelvo al principio del File para hacer la carga
	iss->clear();
	iss->seekg(0, iss->beg);

	//Creo el archivo raw_t para el builder
	pRawData = new raw_t{0};
	if(pRawData == NULL) return STATUS_BAD_ALLOC;
	pRawData->inTx = this->getTxIndexFromStream(iss,'\n');

	pRawData->IN_tableOfTxId = new std::string[pRawData->inTx];
	pRawData->IN_tableOfIndex = new int[pRawData->inTx];
	pRawData->IN_tableOfAddr = new std::string[pRawData->inTx];
	if(		pRawData->IN_tableOfTxId == NULL  ||
			pRawData->IN_tableOfIndex == NULL ||
			pRawData->IN_tableOfAddr == NULL ) 	return STATUS_BAD_ALLOC;

	for(int i = 0; i < pRawData->inTx; i++)
	{
		pRawData->IN_tableOfTxId[i]  = this->getHashFromStream(iss,' ');
		pRawData->IN_tableOfIndex[i] = this->getTxIndexFromStream(iss,' ');
		pRawData->IN_tableOfAddr[i]  = this->getHashFromStream(iss);
	}

	pRawData->outTx = this->getTxIndexFromStream(iss,'\n');
	pRawData->OUT_tableOfValues = new float[pRawData->outTx];
	pRawData->OUT_tableOfAddr = new std::string[pRawData->outTx];
	if(		pRawData->OUT_tableOfValues == NULL  ||
			pRawData->OUT_tableOfAddr   == NULL  ) 	return STATUS_BAD_ALLOC;

	for(int i = 0; i < pRawData->outTx; i++)
	{
		pRawData->OUT_tableOfValues[i]  = this->getBTCValueFromStream(iss,' ');
		pRawData->OUT_tableOfAddr[i] = this->getHashFromStream(iss);
	}
	return STATUS_OK;
}


int BlockChainFileManager::getTxIndexFromStream(std::istream *iss,char delim)
{
	int IndexValue;
	std::string line;
	std::stringstream ss;

	std::getline(*iss, line,delim);
	ss.str(line);
	ss >> IndexValue;
	return IndexValue;
}

std::string BlockChainFileManager::getHashFromStream(std::istream *iss,char delim)
{
	std::string line;
	std::stringstream ss;
	std::getline(*iss, line,delim);
	return line;
}

float BlockChainFileManager::getBTCValueFromStream(std::istream *iss,char delim)
{
	float floatValue;
	std::string line;
	std::stringstream ss;

	std::getline(*iss, line,delim);
	ss.str(line);
	ss >> floatValue;
	return floatValue;
}



status_t BlockChainFileManager::convert(std::ostream * iss, blockchain_t * pBlockChain){
	//@TODO
	return STATUS_OK;
}


