/*
 * BlockChainManager.h
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#ifndef BLOCKCHAINMANAGER_H_
#define BLOCKCHAINMANAGER_H_

#include<string>
#include <iostream>

//  Anterior
#include  "BlockChainStatus.h"

//  Nuevo
//#include "lista.h"
//#include "Block.h"

class BlockChainManager {
	//  Anterior
	status_t state;
	// Datos privados
	//lista <Block> ListaBlocks;
public:
	//  Anterior
	static void	proccesBlockChain( std::istream *iss, std::ostream *oss );
	static void	proccesStatus( status_t status );
	//  Nuevo
	//BlockChainManager();
	//virtual ~BlockChainManager();
};

#endif /* BLOCKCHAINMANAGER_H_ */
