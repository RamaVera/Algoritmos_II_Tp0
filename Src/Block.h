//Archivo fuente header clase Block / AlgoBlock del tp0 para la materia 9512 Algoritmos y Programación 2.

#include <string>

enum TiposHash {
	clavehash256,
	clavefirma,
};

using namespace std;

const string::size_type LargoHashEstandar = 64;
const string::size_type LargoHashFirma    = 40;	// Hash Pública de la Cuenta

class Block {
    // Métodos
	private:
		// Atributos Seccion Header
		string pre_block;
		string txns_hash;
		string bits;
		string nonce;
		// Atributos Seccion Body
		// Body *body;	// Puntero a un objeto clase body.
		bool CheckPreBlock( string valor );
		int CheckHexa( string value );
    public:
        // Constructores
        Block();
        // Destructor
        ~Block();
		// Getters
        int getCantTransacciones();
		string getpre_block();
		string gettxns_hash();
		string getbits();
		string getnonce();
		// Setters
		bool setpre_block( string valor );
		bool settxns_hash( string valor );
		bool setbits( string valorbits );
		bool setnonce( string valor );
		// Métodos
		void RecalculoHash();
		bool CheckHash( string valor, TiposHash Tipo = clavehash256 );
};
