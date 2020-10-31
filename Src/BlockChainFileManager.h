/*
 * BlockChainFileManager.h
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#ifndef BLOCKCHAINFILEMANAGER_H_
#define BLOCKCHAINFILEMANAGER_H_

#include <iostream>
#include <string>
#include <sstream>
#include "BlockChainStatus.h"
#include "BlockChainBuilder.h"

typedef int raw_t;
typedef int blockchain_t;

class BlockChainFileManager {
private:
	bool isTxIndexFromStream(std::istream *iss,char delim = '\n', int * pValue = NULL);
	bool isHashFromStream(std::istream *iss,char delim = '\n', std::string * pString = NULL);
	bool isBTCValueFromStream(std::istream *iss,char delim = '\n', float * pFloat = NULL);
	bool isEofFromStream(std::istream *iss);
public:
	BlockChainFileManager();
	~BlockChainFileManager();
	status_t validate(std::istream * iss);
	status_t parse(std::istream * iss,raw_t * pRawData);
	status_t convert(std::ostream * oss,blockchain_t * pBlockChain);
};

#endif /* BLOCKCHAINFILEMANAGER_H_ */
