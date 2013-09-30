// BigNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BigNumbers.h"

unsigned bnAdd(unsigned bn1[], unsigned bn2[],unsigned bnSum[])
{
    unsigned digits;                    // number of digits to process
    unsigned *pDigitBN1 = bn1 + 2;      // pointer to access a single digit within bn1
    unsigned *pDigitBN2 = bn2 + 2;      // pointer to access a single digit within bn2
    unsigned *pDigitBNSum = bnSum + 2;  // pointer to access a single digit within bnSum
    unsigned carry = 0;                 // carry to the next digit
    unsigned retValue = ERROR_SUCCESS;  // return value

    // process one digit more as the bigger number has
    if (bn1[0] > bn2[0])
        digits = bn1[0];
    else
        digits = bn2[0];

    // enough space in the result
    // if (digits > bnSum[0]) return ERROR_OVERFLOW;
  
    for (unsigned currentDigit=0; currentDigit < digits; currentDigit++)
    {
        *pDigitBNSum = *pDigitBN1 + *pDigitBN2 + carry;
    
        //if (*pDigitBNSum >= DIGIT_BASE)   // Why is this code faster than the two lines below?
        //{
        //    carry = 1;
        //    *pDigitBNSum -= DIGIT_BASE;
        //}
        //else
        //{
        //    carry = 0;
        //}

        carry = *pDigitBNSum / DIGIT_BASE;
        *pDigitBNSum %= DIGIT_BASE;

        pDigitBN1++;
        pDigitBN2++;
        pDigitBNSum++;
    }
    if (carry) retValue = ERROR_OVERFLOW;

    return retValue;;
}

unsigned bnMul(unsigned bn1[], unsigned bn2[],unsigned bnProd[])
{
    unsigned digitBN1 = 0;                  // current digit of bn1
    unsigned digitBN2 = 0;                  // current digit of bn2
    unsigned *pDigitBN1 = bn1 + 2;          // pointer to access a single digit within bn1
    unsigned *pDigitBN2 = bn2 + 2;          // pointer to access a single digit within bn2
    unsigned carry = 0;                     // carry to the next digit
    unsigned bnIntermediate[BN_ARRAY_SIZE] = {0}; // Intermediate result
    unsigned bnSumHelper[BN_ARRAY_SIZE] = {0}; // Intermediate result
    unsigned *pDigitBNIntermediate = 0;    // pointer to access a single digit within bnProd

    // check available digits for the result
    if (bn1[0]+bn2[0] > bnProd[0]) return ERROR_OVERFLOW;

    // clear the result
    bnClear(bnProd);
    
    // prepare intermediate result and sumhelper
    bnIntermediate[0] = bn1[0] + bn2[0];
    bnSumHelper[0] = bnProd[0];

    for (digitBN1 = 0;digitBN1 < bn1[0];digitBN1++)
    {
        bnClear(bnIntermediate);
        pDigitBNIntermediate = bnIntermediate + 2 + digitBN1;
        pDigitBN1 = bn1 + 2 + digitBN1;
        pDigitBN2 = bn2 + 2;
        carry = 0;

        for (digitBN2 = 0;digitBN2 < bn2[0];digitBN2++)
        {
            *pDigitBNIntermediate = *pDigitBN2 * *pDigitBN1 + carry;
            carry = *pDigitBNIntermediate / DIGIT_BASE; // getting rid of this two lines may 
            *pDigitBNIntermediate %= DIGIT_BASE;        // increase speed
            pDigitBNIntermediate++;
            pDigitBN2++;
        }
        *pDigitBNIntermediate = carry;
        
        bnCopy(bnProd,bnSumHelper);
        bnAdd(bnSumHelper,bnIntermediate,bnProd);
    }
    
    return ERROR_SUCCESS;
}

unsigned bnClear(unsigned bn[])
{
    unsigned digits = bn[0];
    unsigned *pDigitsBN = bn + 2;

    bn[1] = 0; // sign
    while (digits--) *pDigitsBN++ = 0;  // digits

    return ERROR_SUCCESS;
}

unsigned bnCopy(unsigned bnSrc[], unsigned bnDest[])
{
    unsigned digits = bnSrc[0];
    unsigned *pDigitsBNSrc = bnSrc + 2;
    unsigned *pDigitsBNDest = bnDest + 2;

    if (bnDest[0] < bnSrc[0]) return ERROR_OVERFLOW;
    
    bnClear(bnDest);
    bnDest[1] = bnSrc[1];   //sign
    while (digits--) *pDigitsBNDest++ = *pDigitsBNSrc++;  // digits

    return ERROR_SUCCESS;
}

unsigned bnFact(unsigned factNumber, unsigned bnResult[])
{
    unsigned factor = 1;
    unsigned bnIntermediate[BN_ARRAY_SIZE] = {0};
    unsigned bnFactor[BN_ARRAY_SIZE] = {0};
 
    bnResult[0] = NUMBER_OF_DIGITS;
    bnClear(bnResult);

    // initialize bnResult with bnOne
    unsigned2bn(1,bnResult);
    
    for (factor=2; factor <= factNumber; factor++)
    {
        bnIntermediate[0] = bnResult [0];
        bnCopy(bnResult,bnIntermediate);
        
        unsigned2bn(factor,bnFactor);

        bnResult[0] += bnFactor[0];
        //bnMul(bnFactor,bnIntermediate,bnResult);      // < 0.01.00 1000! , Why is this line faster than the line below?
        bnMul(bnIntermediate,bnFactor,bnResult);    //1.22.47 1000!
    }
    return ERROR_SUCCESS;
}

unsigned unsigned2bn(unsigned value,unsigned bn[])
{
    unsigned *pDigitsBN = bn + 2;

    bn[0] = NUMBER_OF_DIGITS;
    bnClear(bn);
    bn[0] = 0;
    
    do
    {
        *pDigitsBN++ = value % DIGIT_BASE;
        value /= DIGIT_BASE;
        bn[0]++;
    }
    while (value > 0);

    return ERROR_SUCCESS;
}

unsigned bn2sz(unsigned bn[],char* sz, unsigned szSize)
{
    unsigned *pDigitsBN = bn + 2 + bn[0];
    while (*pDigitsBN == 0) pDigitsBN--;    //remove leading zeros

    while (pDigitsBN > bn+1 && --szSize) *sz++ = *pDigitsBN-- + '0';
    *sz = 0;
    return ERROR_SUCCESS;
}