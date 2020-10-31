/*
 * BlockChainManager.h
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#ifndef BLOCKCHAINMANAGER_H_
#define BLOCKCHAINMANAGER_H_

#include<string>

#include "TiposHash.h"
#include "lista.h"
#include "Block.h"

class BlockChainManager {
	std::string Calculononce();
	bool CalculoBits( std::string hash, unsigned int bits );
	int CheckHexa( std::string value );	// <- esta le sería más util a BlockChainFileManager 
	bool CheckHash( std::string valor, TiposHash Tipo = clavehash256 );
	// Datos privados
	lista <Block> ListaBlocks;
	Block BlocklActual;
	std::string hash_resultado;
	unsigned int bits;	/* La dificultad de bits */
public:
	BlockChainManager();
	virtual ~BlockChainManager();
	bool Minando();
};

#endif /* BLOCKCHAINMANAGER_H_ */
