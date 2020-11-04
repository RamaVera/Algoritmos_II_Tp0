//Archivo fuente header clase Block / AlgoBlock del tp0 para la materia 9512 Algoritmos y Programación 2.

#ifndef BLOCK_H_
#define BLOCK_H_

#include<string>
#include "TiposHash.h"
#include "Transaction.h"
#include "lista.h"

const size_t LargoHashEstandar = 64;
const size_t LargoHashFirma    = 40;	// Hash Pública de la Cuenta
// https://stackoverflow.com/questions/2268749/defining-global-constant-in-c
// Análisis de Pro vs Contras contra #define y otras formas

using namespace std;

class Block {
	private:
		// Atributos Seccion Header
		std::string pre_block;
		std::string txns_hash;
		size_t bits;	/* La dificultad de bits */
		std::string nonce;
		StatusBlock eBlock;
		// Atributos Seccion Body;
		size_t txn_count;
		lista <Transaction> ListaTran;
		Transaction *CurTran;
		// Métodos privados
		std::string RecalculoHash();

	public:
    // Métodos
        // Constructores
        Block();
        // Destructor
        ~Block();
		// Getters
        int getCantTransacciones();
		std::string getpre_block();
		std::string gettxns_hash();
		unsigned int getbits();
		std::string getnonce();
		// Setters
		bool setpre_block( std::string valor );
		bool settxns_hash( std::string valor );
		bool setbits( unsigned int valor );
		bool setnonce( std::string valor );
		StatusBlock EstatusBlock();

};

#endif /* BLOCK_H_ */