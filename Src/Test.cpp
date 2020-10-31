#include<string>
#include <iostream>

#include "Block.h"
#include "TiposHash.h"

using namespace std;

bool CheckPreBlock( std::string valor );
int CheckHexa( std::string value );
bool CheckHash( std::string valor, TiposHash Tipo );

extern const string::size_type LargoHashEstandar;  // -> Block.h
extern const string::size_type LargoHashFirma;	   // Hash Pública de la Cuenta definida en Block.h

int main() {
	std::string Hash = "e9dc0f0fbcb9021dc39ec104dfa51e813a86c8205a77d3be6c8cd6140b941e0c";
	std::string Dir = "f680e0021dcaf15d161604378236937225eeecae85cc3f";

	if ( CheckPreBlock( Hash ) ) {
		cout << "Ok 1" << std::endl;
	}
	
	if ( CheckHash( Hash, clavehash256 ) ) {
		cout << "Ok 2" << std::endl;
	}

	if ( CheckHash( Dir, clavefirma ) ) {
		cout << "Ok 3" << std::endl;
	}

	Dir = "f680e0021dcaf15d161604378236937225eeecae";
	if ( CheckHash( Dir, clavefirma ) ) {
		cout << "Ok 4" << std::endl;
	}
	
}

bool CheckHash( std::string valor, TiposHash Tipo = clavehash256 ) {
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

bool CheckPreBlock( std::string valor ) {
/* Esta deberia ser más genérica para hacer un check de Hash de distinas longitudes
	Podría meterse en un Enum o en #define o en Const int más estilo C++
*/
	if ( valor.empty() ) {
		return false;
	}
	else if ( valor.length() != LargoHashEstandar /* Hay que sacar este Hardcodeo */ ) {
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

int CheckHexa( std::string valor ) {
	unsigned int i;
	for (i = 0; i != valor.length(); ++i) {
		if ( ! isxdigit ( valor[i] ) ) break;
	} 
	if ( i < valor.length() ) return i;
	return 0;
}