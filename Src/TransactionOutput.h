/*
 * TransactionOutput.h
 *
 *  Created on: 25 oct. 2020
 *      Author: Ramiro
 */

#ifndef TRANSACTIONOUTPUT_H_
#define TRANSACTIONOUTPUT_H_

class TransactionOutput {
private:
	float value;
	char * addr;
public:
	//---Constructores---//
	TransactionOutput();
	~TransactionOutput();
	//---Getters---//
	float getValue(void) const;
	const char* getAddr(void) const;
	//---Setters---//
	void setValue(float value);
	void setAddr(char* addr);
	//---Otros---//
};

#endif /* TRANSACTIONOUTPUT_H_ */
