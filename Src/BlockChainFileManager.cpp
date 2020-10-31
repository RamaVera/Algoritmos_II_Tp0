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


status_t BlockChainFileManager::parse(std::istream * iss, raw_t * pRawData){
	//@TODO
	return STATUS_OK;
}

status_t BlockChainFileManager::convert(std::ostream * iss, blockchain_t * pBlockChain){
	//@TODO
	return STATUS_OK;
}


