/*
 * BlockChainBuilder.cpp
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#include "BlockChainBuilder.h"
#include "Block.h"
#include "TiposHash.h"
#include "sha256.h"

BlockChainBuilder::BlockChainBuilder() {
	// TODO Auto-generated constructor stub

}

BlockChainBuilder::~BlockChainBuilder() {
	// TODO Auto-generated destructor stub
}


int BlockChainBuilder::CheckHexa( string value ) {
	unsigned int i;
	for (i = 0; i != value.length(); ++i) {
		if ( ! isxdigit ( value[i] ) ) break;
	}
	if ( i < value.length() ) return i;
	return 0;
}

std::string BlockChainBuilder::Calculononce() {
	static int contador = 0;
	contador++;
	return std::to_string( contador );
}

bool BlockChainBuilder::CalculoBits( std::string hash, unsigned int bits ) {
	return true;
}

bool BlockChainBuilder::Minando() {
	std::string resultado = "";

	if ( ! this->ListaBlocks.vacia() ) {
		lista <Block>::iterador it;
		/* Itero la lista para recuperar todos los strings de la coleccion Transaction
		   que necesito para calcular el Hash.
		*/
		it = this->ListaBlocks.primero();
		while ( ! it.extremo() ) {
			this->BlocklActual = it.dato();
			resultado += this->BlocklActual.gettxns_hash(); 	// <- falta definir el método que extrae el string en la Clase Transaction.
			resultado += this->BlocklActual.getnonce();
			if ( resultado.length() > 0  ) {
				this->hash_resultado = sha256( resultado );
				if ( CalculoBits( this->hash_resultado, this->bits ) ) {
					break;
				}
			}
			it.avanzar();
		}
	}
	return false;
}

bool BlockChainBuilder::CheckHash( std::string valor, TiposHash Tipo ) {
	if ( valor.empty() ) {
		return false;
	}
	else if ( Tipo  == clavehash256 && valor.length() != LargoHashEstandar ) {
		return false;
	}
	else if ( Tipo  == clavefirma && valor.length() != LargoHashFirma ) {
		return false;
	}
	else {
		int i = CheckHexa( valor );
		if ( i > 0 ) {
			// Anotar la posición y valor del dígito erróneo
			return false;
		}
		else return true;
	}
}


