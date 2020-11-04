/*
 * BlockChainBuilder.h
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#ifndef BLOCKCHAINBUILDER_H_
#define BLOCKCHAINBUILDER_H_

#include "TiposHash.h"
#include "Block.h"
#include "BlockChainDataTypes.h"


class BlockChainBuilder {
private:	// Redundante pero más legible
	//  Anterior
	static int CheckHexa( std::string value );	// <- esta le sería más util a BlockChainFileManager 
	// Datos privados
	Block BlocklActual;
	lista <Block> ListaBlocks;
	std::string hash_resultado;
	size_t bits;	/* La dificultad de bits */
	//  Nuevo
	bool CalculoBits( std::string hash, size_t bits );
	bool Minando();
	static std::string hex_str_to_bin_str( const std::string & hex );
	static const char* hex_char_to_bin( char c );
	static int dificultad( const std::string value, const size_t dif );  					// -1 -> Error
	
public:
	BlockChainBuilder();
	virtual ~BlockChainBuilder();
		// Getters
	unsigned int getbits();
	// Setters
	bool setbits( unsigned int valor );
	// Métodos
	unsigned int cantidadBlocks();
	static int CheckDificultadOk( const std::string cadenaHexa, const size_t dif );  // Error -> < 0, No -> 0, 0k -> 1
	static bool CheckHash( std::string valor, TiposHash Tipo = TiposHash::clavehash256 );
	static std::string Calculononce();
	
};

#endif /* BLOCKCHAINBUILDER_H_ */
