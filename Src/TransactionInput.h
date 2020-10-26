/*
 * TransactionInput.h
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#ifndef TRANSACTIONINPUT_H_
#define TRANSACTIONINPUT_H_

typedef struct outpoint{
		char * tx_id;
		int	idx;
} outpoint_t;


class TransactionInput {
private:
		outpoint_t outpoint;
		char * addr;
public:
	//---Constructores---//
	TransactionInput();
	~TransactionInput();
	//---Getters---//
	const outpoint_t getOutpoint(void) const;
	const char* getTxId(void) const;
	int getIdx(void) const;
	const char* getAddr(void) const;
	//---Setters---//
	void setOutpoint(const outpoint_t & Outpoint);
	void setTxId(char* tx_id);
	void setIdx(int idx);
	void setAddr(char* addr);
	//---Otros---//
};

#endif /* TRANSACTIONINPUT_H_ */
