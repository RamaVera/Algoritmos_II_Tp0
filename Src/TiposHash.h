#ifndef _TiposHash_INCLUDED_
#define _TiposHash_INCLUDED_

enum TiposHash {
	clavehash256,
	clavefirma,
};

enum StatusBlock {
	BlockSinDatos,
	BlockCambiosPendientes,
	BlockCalculandoHash,
	BlockEstadoError,
	BlockEstadoOk,
};

#endif