#include <iostream>
#include "CBigNumber.h"
#include <time.h>
using namespace std;

int main(int argc, char **argv) {
	clock_t start, ende;
	start = clock();
	CBigNumber bn1(54321);
	cout << "CBigNumber =" << bn1 << endl;

	CBigNumber bn2(1234);
	cout << "CBigNumber =" << bn2 << endl;

	CBigNumber res;
	res = bn1 + bn2;
	cout << "Resultat   =" << res << endl;

	res = bn2 * 134;
	cout << "Resultat   =" << res << endl;

	res = res * 135;
	cout << "Resultat   =" << res << endl;

	res = res * 136;
	cout << "Resultat   =" << res << endl;

	CBigNumber res1(1);
	for (unsigned int i = 2; i < 15; i++) {
		res1 = res1 * i;
//		cout << "Iteration " << i << ": " << res1 <<endl;
	}
	for (unsigned int i = 15; i < 17; i++) {
		res1 = res1 * i;
		cout << "Iteration " << i << ": " << res1 <<endl;
	}

	cout << "Resultat   =" << res1 << endl;

	ende = clock();
	cout << "Duration:" << (ende - start) << " ms" << endl; // oder xx / CLOCKS_PER_SEC
	cout << start << endl;
	return 0;
}
