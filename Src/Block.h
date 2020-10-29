//Archivo fuente header clase Block / AlgoBlock del tp0 para la materia 9512 Algoritmos y Programación 2.

#include<string>
#include "TiposHash.h"
#include "Transaction.h"
#include "lista.h"

using namespace std;

const string::size_type LargoHashEstandar = 64;
const string::size_type LargoHashFirma    = 40;	// Hash Pública de la Cuenta

class Block {
    // Métodos
	private:
		// Atributos Seccion Header
		std::string pre_block;
		std::string txns_hash;
		unsigned int bits;	/* La dificultad de bits */
		std::string nonce;
		// Atributos Seccion Body;
		unsigned int txn_count;
		lista <Transaction> ListaTran;
		Transaction *CurTran;
		// Métodos privados
		bool CheckPreBlock( std::string valor );
		int CheckHexa( std::string value );
		StatusBlock eBlock;
		std::string Calculononce();
		bool CalculoBits( std::string hash, unsigned int bits );
    public:
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
		// Métodos
		std::string RecalculoHash();
		bool CheckHash( std::string valor, TiposHash Tipo = clavehash256 );
		StatusBlock EstatusBlock();
		bool Minando();
};