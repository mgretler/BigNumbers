//============================================================================
// Name        : CBigNumber.cpp
// Author      : Markus Gretler
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CBigNumber.h"
using namespace std;

CBigNumber::CBigNumber(unsigned int init) {
	clear();
	m_length = 0;
	while (init) {
		m_number[m_length++] = init % 10;
		init /= 10;
	}
}

CBigNumber::~CBigNumber() {
//	clog << "Destruktor aufgerufen" << endl;
}

CBigNumber CBigNumber::operator +(const CBigNumber& addend) {
	CBigNumber res;
	unsigned int carry = 0;
	unsigned int _max = max(this->m_length, addend.m_length);
	for (unsigned int i = 0; i < _max; i++) {
		unsigned int temp = this->m_number[i] + addend.m_number[i] + carry;
		res.m_number[i] = temp % 10;
		carry = temp / 10;
		res.m_length = i + 1;
	}
	if (carry)
		res.m_number[res.m_length++] = carry;

	return res;
}

//CBigNumber CBigNumber::operator *(const CBigNumber& factor) {
//}CBigNumber CBigNumber::operator *(const unsigned int factor) {

CBigNumber CBigNumber::operator *(unsigned int mult) {
	CBigNumber res;
	unsigned int carry = 0;
	unsigned int factor = 0;
	unsigned int shift = 0;
	unsigned int temp = 0;
	unsigned int i;

	while (mult) {
		factor = mult % 10;  // einstelliger Multiplikand
		carry = 0;
		unsigned int _max = max(this->m_length+shift, res.m_length);
		for (i = 0; i < _max; i++) {
			// TODO
			// Funktioniert nur solange die CBigNumber länger als mult ist
			temp = this->m_number[i] * factor + res.m_number[i + shift] + carry;
			res.m_number[i + shift] = temp % 10;
//			if ((i + shift) > res.m_length)
//				res.m_length = i + shift;
			carry = temp / 10;
		}
		res.m_length = this->m_length + shift;
		if (carry)
			res.m_number[res.m_length++] = carry;
		shift++;
		mult /= 10;
	}

	return res;
}

ostream& operator<<(ostream& o, const CBigNumber& n) {
	for (unsigned i = n.m_length; i > 0; i--) {
		o << n.m_number[i - 1];
	}
	return o;
}

void CBigNumber::clear() {
// könnte man weglassen, wenn m_lenght richtig funktioniert
	for (unsigned int i = 0; i < NUMBER_OF_DIGITS; i++) {
		m_number[i] = 0;
	}
	m_length = 0;
}
