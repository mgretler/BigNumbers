/*
 * CBigNumber.h
 *
 *  Created on: 30.09.2013
 *      Author: Markus
 */

#ifndef CBIGNUMBER_H_
#define CBIGNUMBER_H_

#include <iostream>

class CBigNumber {
private:
	const int NUMBER_OF_DIGITS = 4000;
//	bool m_positiveNumber;
//	unsigned m_validDigits;
	unsigned m_number[NUMBER_OF_DIGITS];
	unsigned clear();
public:
	CBigNumber(int initialValue = 0);
	virtual ~CBigNumber();

	CBigNumber operator+(const CBigNumber& addend); // only positive numbers supported
	CBigNumber operator*(const CBigNumber&factor);

	friend std::ostream& operator<<(std::ostream& o, const CBigNumber&);
};

#endif /* CBIGNUMBER_H_ */