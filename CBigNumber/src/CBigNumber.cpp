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

int main() {
	cout << "Hallo Test Nummer 2" << endl; // prints Hallo Test Nummer 2
	return 0;
}

CBigNumber::CBigNumber(int init) {
	// TODO Auto-generated constructor stub

}

CBigNumber::~CBigNumber() {
	// TODO Auto-generated destructor stub
}

ostream& operator<<(ostream& o, const CBigNumber&) {
	return o;
}

CBigNumber fact(unsigned factorCount) {
	return CBigNumber(0);
}

unsigned CBigNumber::clear() {
	for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
		m_number[i] = 0;
	}

}
