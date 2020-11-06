/*
 * BlockChainBuilder.cpp
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#include "BlockChainBuilder.h"
#include "Block.h"

#include "TiposHash.h"

#include "lista.h"
#include "sha256.h"


BlockChainBuilder::BlockChainBuilder() : BlocklActual(), ListaBlocks(), hash_resultado( "" ), bits( 3 /* El valor por default establecido en el TP0 */), pRawData(NULL){}

BlockChainBuilder::BlockChainBuilder(size_t d) : BlocklActual(), ListaBlocks(), hash_resultado( "" ), bits( d ), pRawData(NULL){}

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

bool BlockChainBuilder::CheckHash( std::string valor, TiposHash Tipo ) {
	if ( valor.empty() ) {
		return false;
	}
	else if ( Tipo  == TiposHash::clavehash256 && valor.length() != LargoHashEstandar ) {
		return false;
	}
	else if ( Tipo  == TiposHash::clavefirma && valor.length() != LargoHashFirma ) {
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

std::string BlockChainBuilder::Calculononce() {
	static int contador = 0;
	contador++;
	return std::to_string( contador );

}

bool BlockChainBuilder::CalculoBits( std::string hash, size_t bits ) {
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
		do  {
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
		} while ( ! it.eol() );
	}
	return false;
}

const char* BlockChainBuilder::hex_char_to_bin( char c )
{
    // TODO handle default / error
	// https://stackoverflow.com/questions/18310952/convert-strings-between-hex-format-and-binary-format
    switch( toupper(c) )
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
		default: return "";
    }
}

std::string BlockChainBuilder::hex_str_to_bin_str( const std::string & hex )
{
    // TODO use a loop from <algorithm> or smth
    std::string bin;
	std::string hexbin;
    for( size_t i = 0; i != hex.length(); ++i ) {
		hexbin = hex_char_to_bin( hex[i] );
		if ( hexbin.empty() ) return "";
		bin += hexbin;
	}
    return bin;
}

int BlockChainBuilder::dificultad( const std::string value, const size_t dif ) {
	// Se corta el recorrido de la cadena una vez alcanzado el valor dif
	size_t j = 0;

	if ( value.empty() ) return -1;
	else if ( dif == 0 ) return -1;

	for ( size_t i = 0;  value[ i ]; i++ ) {
		if ( value[ i ] == '0' ) j++;
		else if ( value[ i ] == '1' ) break;
		else return -1;
		if ( j++ >= dif ) break; 
	}
	return j;
}

int BlockChainBuilder::CheckDificultadOk( std::string cadenaHexa, const size_t dif ) {
	int d;
	if ( cadenaHexa.empty() ) return -3;
	if ( dif == 0 ) return -2;
	d = dificultad( cadenaHexa, dif);
	if ( d < 0 ) return -1;
	return (size_t) d >= dif ? 1 : 0;
}
