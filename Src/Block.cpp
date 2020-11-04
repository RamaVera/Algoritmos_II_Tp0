//Archivo fuente clase Block / AlgoBlock del tp0 para la materia 9512 Algoritmos y Programación 2.

#include<string>
#include <cstdlib>

#include "Block.h"
#include "TiposHash.h"
#include "Transaction.h"
#include "BlockChainBuilder.h"

// Constructores
Block::Block() 
	: pre_block(""), txns_hash(""), bits(3  /* El valor por default establecido en el TP0 */), nonce(""), eBlock(StatusBlock::BlockSinDatos)
{
	lista <Transaction> ListaTran;
	// this->CurTran = NULL;
	// this->txn_count = 0;
	// this->eBlock = BlockSinDatos;
}

// Destructor
Block::~Block() {
	// ListaTran se autodestruye
}

// Getters
int Block::getCantTransacciones() {
	// ToDo
	return 0;
}

std::string Block::getpre_block() {
	return this->pre_block;
}

std::string Block::gettxns_hash() {
	return this->txns_hash;
}

unsigned int Block::getbits() {
	return this->bits;
}

std::string Block::getnonce() {
	return this->nonce;
}

// Setters
bool Block::setpre_block( std::string valor ) {
	if ( valor.empty() ) {
		this->pre_block = "";
		// Hay que anotar, en un status ?, el error o disparar un throw
	}
	else {
		/* 1) Debo validar que sea una cadena de 32 bytes o 64 dígitos Hexa
		   2) Chequear que cada byte sea un caracter hexa válido.
		*/
		//if ( this->CheckHash( valor, clavehash256 ) ) {
		if ( BlockChainBuilder::CheckHash( valor, TiposHash::clavehash256 ) ) {
			this->pre_block = valor;
		}
	}
	return true;
}

bool Block::settxns_hash( std::string valor ) {
	if ( valor.empty() ) {
		this->txns_hash = "";
		// Hay que anotar, en un status ?, el error o disparar un throw
	}
	else {
		/* 1) Debo validar que sea una cadena de 32 bytes o 64 dígitos Hexa
		   2) Chequear que cada byte sea un caracter hexa válido.
		*/
		// if ( this->CheckHash( valor, clavehash256 ) ) /* Es otro hash de 32 bytes */ {
		if ( BlockChainBuilder::CheckHash( valor, TiposHash::clavehash256 ) ) /* Es otro hash de 32 bytes */ {
			this->txns_hash = valor;
		}
	}
	return true;
}

bool Block::setbits( unsigned int valor ) {
	if ( !valor ) {
		this->bits = 0;
		// Hay que anotar, en un status ?, el error o disparar un throw
	}
	else {
		this->bits = valor;
	}
	return true;
}

bool Block::setnonce( std::string valor ) {
	if ( valor.empty() ) {
		this->nonce = "";
		// Hay que anotar, en un status ?, el error o disparar un throw
	}
	else {
		/* No se valida nada, puede ser cualquier dato */
		this->nonce = valor;
	}
	return true;
}

std::string Block::RecalculoHash() {
	std::string cadena = "";
	if ( ! ListaTran.vacia() ) {
		// lista <Transaction>::iterador it();
		lista <Transaction>::iterador it(ListaTran);
		/* Itero la lista para recuperar todos los strings de la coleccion Transaction
		   que necesito para calcular el Hash.
		*/
		it = ListaTran.primero();
		while ( ! it.eol() ) {
			// ToDo
			// std::string cadena += ListaTran.texto <- falta definir el método que extrae el string en la Clase Transaction.
			it.avanzar();
		}
	}
	return cadena;
}