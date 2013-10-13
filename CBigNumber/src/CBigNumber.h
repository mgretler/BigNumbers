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
	const static unsigned NUMBER_OF_DIGITS = 6000;
//	bool m_positiveNumber;
//	unsigned m_validDigits;
	unsigned m_number[NUMBER_OF_DIGITS];
	unsigned m_length;
	void clear();
public:
	CBigNumber(unsigned int initialValue = 0);
	virtual ~CBigNumber();

	CBigNumber operator+(const CBigNumber& addend); // only positive numbers supported
	CBigNumber operator*(const CBigNumber& factor);
	CBigNumber operator*(unsigned int factor);

	friend std::ostream& operator<<(std::ostream& o, const CBigNumber&);
};

#endif /* CBIGNUMBER_H_ */
