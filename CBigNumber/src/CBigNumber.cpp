//============================================================================
// Name        : CBigNumber.cpp
// Author      : Markus Gretler
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CBigNumber.h"
#include <time.h>
using namespace std;

int main(int argc, char **argv) {
	clock_t start, ende;
	start = clock();
	CBigNumber bn1(54321);
	CBigNumber bn2(987654);
	CBigNumber res;

	res = bn1 + bn2;

	cout << "CBigNumber =" << bn1 << endl;
	cout << "CBigNumber =" << bn2 << endl;
	cout << "Resultat   =" << res << endl;
	ende = clock();
	cout << "Duration:" << (ende - start) << " ms" << endl;  // oder xx / CLOCKS_PER_SEC
	cout << start << endl;
	return 0;
}

CBigNumber::CBigNumber(unsigned int init) {
	clear();
	m_length = 0;
	while (init) {
		m_number[m_length++] = init % 10;
		init /= 10;
	}
}

CBigNumber::~CBigNumber() {
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
	// TODO:
	// if carry then noch eine ziffer
	if (carry) {
		res.m_number[res.m_length++] = carry;
	}
	return res;
}

//CBigNumber CBigNumber::operator *(const CBigNumber& factor) {
//}

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
