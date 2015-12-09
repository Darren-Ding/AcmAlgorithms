#include <iostream>

#include "Math/HighPrecisionInteger.h"

using namespace std;

//
void TestMathHighPrecisionInteger();

int main()
{
    TestMathHighPrecisionInteger();

    return 0;
}

void TestMathHighPrecisionInteger()
{
    BigInteger zero("0");   // zero --- A bug unfixed!
    BigInteger one("1");
    BigInteger nine2("99");
    BigInteger big("1234567890098765432232341874874717837483724123737473274732737217437471");
    cout << zero.toString() << endl << one.toString()
        << endl << nine2.toString() << endl << big.toString();
}