#ifndef _TiposHash_INCLUDED_
#define _TiposHash_INCLUDED_

enum class TiposHash {
	clavehash256,
	clavefirma,
};

enum class StatusBlock {
	BlockSinDatos,
	BlockCambiosPendientes,
	BlockPendienteString,
	BlockCalculadoHash,
	BlockEstadoError,
	BlockEstadoOk,
};

#endif