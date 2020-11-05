/*
 * BlockChainManager.cpp
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */
 
#include<string>

#include "BlockChainManager.h"
#include "BlockChainFileManager.h"
#include "BlockChainBuilder.h"
#include "Block.h"
#include "lista.h"

void BlockChainManager::proccesBlockChain(std::istream *iss,std::ostream *oss){
	BlockChainBuilder builder(BlockChainManager::getUserDefinedDifficulty());
	BlockChainFileManager fileManager;

	std::cout<< "Begin Validate ...";
	BlockChainManager::proccesStatus( fileManager.validate(iss) );

	std::cout<< "Begin Parsing ..." ;
	BlockChainManager::proccesStatus( fileManager.parse(iss,builder.getRawPointer()) );

	std::cout<< "Begin Creating Block ..." ;
	//BlockChainManager::proccesStatus( builder.createBlockChain() );

	std::cout<< "Begin Converting Block to File ..." ;
	//BlockChainManager::proccesStatus( fileManager.convert(oss,builder->getBlockChainPointer()) );

}

void BlockChainManager::proccesStatus(status_t status){
	switch(status){

	case STATUS_OK:
		std::cout << "OK" << std::endl;
		break;

	case STATUS_CORRUPT_FORMAT:
		std::cout << "Error de Formato: Formato Incorrecto" << std::endl;
		std::cerr << "Error de Formato: Formato Incorrecto" << std::endl;
		std::abort();
		break;
	case STATUS_CORRUPT_FORMAT_BAD_HASH:
		std::cout << "Error de Formato: Hash incorrecto" << std::endl;
		std::cerr << "Error de Formato: Hash incorrecto" << std::endl;
		std::abort();
		break;
	case STATUS_CORRUPT_FORMAT_BAD_TXINDEX:
		std::cout << "Error de Formato: Indice de Tx incorrecto" << std::endl;
		std::cerr << "Error de Formato: Indice de Tx incorrecto" << std::endl;
		std::abort();
		break;
	case STATUS_CORRUPT_FORMAT_BAD_TXIN:
		std::cout << "Error de Formato: Indice Tx In Incorrecto" << std::endl;
		std::cerr << "Error de Formato: Indice Tx In Incorrecto" << std::endl;
		std::abort();
		break;
	case STATUS_CORRUPT_FORMAT_BAD_TXOUT:
		std::cout << "Error de Formato: Indice Tx Out Incorrecto" << std::endl;
		std::cerr << "Error de Formato: Indice Tx Out Incorrecto" << std::endl;
		std::abort();
		break;
	case STATUS_CORRUPT_FORMAT_BAD_BTCVALUE:
		std::cout << "Error de Formato: Valor de Bitcoin Incorrecto" << std::endl;
		std::cerr << "Error de Formato: Valor de Bitcoin Incorrecto" << std::endl;
		std::abort();
		break;
	default:
		std::cout << std::endl;
		break;
	}
}


#define DIFFICULTY_DEFAULT_VALUE 3
size_t BlockChainManager::userDefinedDifficulty = DIFFICULTY_DEFAULT_VALUE;

void BlockChainManager::setUserDefinedDifficulty(int d){
	if( d < 0 ){
		std::cout << "Error de Formato: Dificultad debe ser mayor a cero " << std::endl;
		std::cerr << "Error de Formato: Dificultad debe ser mayor a cero" << std::endl;
		std::abort();
	}
	userDefinedDifficulty = (size_t) d;
}


size_t BlockChainManager::getUserDefinedDifficulty( void ){
	return userDefinedDifficulty;
}
