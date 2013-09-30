#include "stdafx.h"
#include <iostream>
#include "BigNumbers.h"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
    unsigned bigNumber1[BN_ARRAY_SIZE] = {2,0,3,4};
    unsigned bigNumber2[BN_ARRAY_SIZE] = {4,0,4,3,2,1};
    unsigned bnResult[BN_ARRAY_SIZE] = {8,0};
    unsigned bnFactResult[BN_ARRAY_SIZE] = {NUMBER_OF_DIGITS,0};
    char szResult[BN_ARRAY_SIZE] = {0};

    bnAdd(bigNumber2,bigNumber1,bnResult);
    bnMul(bigNumber2,bigNumber1,bnResult);

    bnFact(100,bnFactResult);

    bn2sz(bnFactResult,szResult,BN_ARRAY_SIZE);
    
    cout << szResult;
    return 0;
}

