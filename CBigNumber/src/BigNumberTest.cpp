#include <iostream>
#include "CBigNumber.h"
#include <time.h>
using namespace std;

int main(int argc, char **argv) {
	clock_t start, ende, dauer;
	start = clock();
	CBigNumber bn1(54321);
	cout << "CBigNumber =" << bn1 << endl;

	CBigNumber bn2(9876);
	cout << "CBigNumber =" << bn2 << endl;

	CBigNumber res;
	res = bn1 + bn2;
	cout << "Resultat   =" << res << endl;

	res = bn2 * 987;
	cout << "Resultat   =" << res << endl;

//	res = res * 135;
//	cout << "Resultat   =" << res << endl;
//
//	res = res * 136;
//	cout << "Resultat   =" << res << endl;
//
	CBigNumber res1(1);
	start = clock();			// Stoppuhr starten
	// Fakultät von 1000 berechnen
	for (unsigned int i = 2; i < 1001; i += 3) {
		res1 = res1 * (i * (i + 1) * (i + 2));
//		cout << "Iteration " << i << ": " << res1 <<endl;
	}
	ende = clock();				// Stoppuhr anhalten

	cout << "Resultat   =" << res1 << endl;
	dauer = ende - start;

	cout << "Duration:" << ((double)dauer)/CLOCKS_PER_SEC*1000 << " ms" << endl; // oder xx / CLOCKS_PER_SEC
	cout << start << endl;
	return 0;
}
