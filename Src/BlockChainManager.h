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
#include  "BlockChainStatus.h"


class BlockChainManager {
	status_t state;
	static size_t userDefinedDifficulty;
public:

	static void	proccesBlockChain( std::istream *iss, std::ostream *oss );
	static void	proccesStatus( status_t status );

	static void setUserDefinedDifficulty(int d);
	static size_t getUserDefinedDifficulty(void);

};

#endif /* BLOCKCHAINMANAGER_H_ */
