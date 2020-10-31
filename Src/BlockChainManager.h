/*
 * BlockChainManager.h
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#ifndef BLOCKCHAINMANAGER_H_
#define BLOCKCHAINMANAGER_H_

#include <iostream>
#include  "BlockChainStatus.h"


class BlockChainManager {
private:
	status_t state;
public:
	static void	proccesBlockChain( std::istream *iss, std::ostream *oss );
	static void	proccesStatus( status_t status );

};

#endif /* BLOCKCHAINMANAGER_H_ */
