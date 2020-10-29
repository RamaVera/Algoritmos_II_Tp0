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
		string pre_block;
		string txns_hash;
		unsigned int bits;	/* La dificultad de bits */
		string nonce;
		// Atributos Seccion Body;
		unsigned int txn_count;
		lista <Transaction> ListaTran;
		Transaction *CurTran;
		// Métodos privados
		bool CheckPreBlock( string valor );
		int CheckHexa( string value );
		// StatusBlock eBlock;
    public:
        // Constructores
        Block();
        // Destructor
        ~Block();
		// Getters
        int getCantTransacciones();
		string getpre_block();
		string gettxns_hash();
		unsigned int getbits();
		string getnonce();
		// Setters
		bool setpre_block( string valor );
		bool settxns_hash( string valor );
		bool setbits( unsigned int valor );
		bool setnonce( string valor );
		// Métodos
		void RecalculoHash();
		bool CheckHash( string valor, TiposHash Tipo = clavehash256 );
		// StatusBlock EstatusBlock();
		// bool Minando();
};