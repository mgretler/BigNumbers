// Negative numbers not supported

#ifndef __BIGNUMBERS_
#define __BIGNUMBERS__

// functions
unsigned bnClear(unsigned bn[]);
unsigned bnCopy(unsigned bnSrc[], unsigned bnDest[]);

unsigned unsigned2bn(unsigned value,unsigned bn[]);
unsigned bn2sz(unsigned bn[],char* sz, unsigned szSize);

unsigned bnAdd(unsigned bn1[], unsigned bn2[],unsigned bnSum[]);
unsigned bnMul(unsigned bn1[], unsigned bn2[],unsigned bnProd[]);

unsigned bnFact(unsigned factNumber, unsigned bnResult[]);


// error values
#define ERROR_SUCCESS   0
#define ERROR_OVERFLOW  1
#define ERROR_ALIGNMENT 2

// other definitions
#define DIGIT_BASE    10
#define NUMBER_OF_DIGITS 30000
#define BN_ARRAY_SIZE (NUMBER_OF_DIGITS + 2)


#endif // __BIGNUMBERS__