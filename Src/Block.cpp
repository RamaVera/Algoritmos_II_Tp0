//Archivo fuente clase Block / AlgoBlock del tp0 para la materia 9512 Algoritmos y Programación 2.

#include<string>
#include "Vector.h"
#include "Block.h"
#include "TiposHash.h"

// Constructores
Block::Block() {
	// body = NULL;
}

// Destructor
Block::~Block() {
	// Debo destruir el objeto Body llamando a su destructor;
	// body.destroy();
	// delete body;  
}

// Getters
int Block::getCantTransacciones() {
	// ToDo
	return 0;
}

string Block::getpre_block() {
	return pre_block;
}

string Block::gettxns_hash() {
	return txns_hash;
}

string Block::getbits() {
	return bits;
}

string Block::getnonce() {
	return nonce;
}

bool Block::setpre_block( string valor ) {
	if ( valor.empty() ) {
		pre_block = "";
		// Hay que anorar, en un status ?, el error o disparar un throw
	}
	else {
		/* 1) Debo validar que sea una cadena de 32 bytes o 64 dígitos Hexa
			  2) Chequear que cada byte sea un caracter hexa válido.
		*/
		if ( Block::CheckPreBlock( valor ) ) {
			pre_block = valor;
		}
	}
	return true;
}

bool Block::CheckHash( string valor, TiposHash Tipo ) {
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

void Block::RecalculoHash() {
	// ToDo
	return;
}

bool Block::CheckPreBlock( string valor ) {
	/* Esta deberia ser más generica para hacer un check de Hash de distinas longitudes
		Podría meterse en un Enum o en #define o en Const int más estilo c++
	*/
	if ( valor.empty() ) {
		return false;
	}
	else if ( valor.length() != LargoHashEstandar ) {
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

int Block::CheckHexa( string value ) {
	unsigned int i;
	for (i = 0; i != value.length(); ++i) {
		if ( ! isxdigit ( value[i] ) ) break;
	} 
	if ( i < value.length() ) return i;
	return 0;
}