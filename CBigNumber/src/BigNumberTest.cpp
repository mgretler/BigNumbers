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