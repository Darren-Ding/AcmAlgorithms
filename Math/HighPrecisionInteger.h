//
// Created by  DingLixiang on 15/12/9.
//

#ifndef ACMALGORITHMS_HIGHPRECISIONINTEGER_H
#define ACMALGORITHMS_HIGHPRECISIONINTEGER_H

#include <string>

const int Ten[4] = {1, 10, 100, 1000};  //
const int MaxLen = 1000;    // 最大位数

struct BigInteger
{
    int d[MaxLen];

    BigInteger(const std::string &s = "0")
    {
        int len = s.size();
        d[0] = (len - 1) / 4 + 1;   //
        for (int i = 1; i < len; ++i) d[i] = 0; //
        for (int i = len - 1; i >= 0; --i)
        {
            int j = (len - i - 1) / 4 + 1;
            int k = (len - i - 1) % 4;
            d[j] += Ten[k] * (s[i] - '0');
        }

        while (d[0] > 1 && d[d[0]] == 0) --d[0];
    }

//    BigInteger()
//    {
//        *this = BigInteger(std::string("0"));
//    }

    std::string toString()
    {
        std::string s("");
        int i, j;
        for (i = 3; i >= 1; --i)
            if (d[d[0]] >= Ten[i])
                break;
        int temp = d[d[0]];
        for (j = i; j >= 0; --j)
        {
            s = s + (char)(temp / Ten[j] + '0');
            temp %= Ten[j];

        }

        for (i = d[0] - 1; i > 0; --i)
        {
            temp = d[i];
            for (j = 3; j >= 0; --j)
            {
                s = s + (char)(temp / Ten[j] + '0');
                temp %= Ten[j];
            }
        }
        return s;
    }
};// zero("0"), d, temp, mid1[15];

bool operator <(const BigInteger &a, const BigInteger &b)
{
    if (a.d[0] != b.d[0]) return a.d[0] < b.d[0];
    for (int i = a.d[0]; i > 0; --i)
        if (a.d[i] != b.d[i])
            return a.d[i] < b.d[i];
    return false;
}

BigInteger operator +(const BigInteger &a, const BigInteger &b)
{

}

BigInteger operator -(const BigInteger &a, const BigInteger &b)
{

}

BigInteger operator *(const BigInteger &a, const BigInteger &b)
{

}

bool smaller(const BigInteger &a, const BigInteger &b, int delta)
{

}

bool minus(const BigInteger &a, const BigInteger &b, int delta)
{

}

BigInteger operator *(const BigInteger &a, const int &k)
{

}

BigInteger operator /(const BigInteger &a, const BigInteger &b)
{

}

bool operator ==(const BigInteger &a, const BigInteger &b)
{

}

#endif //ACMALGORITHMS_HIGHPRECISIONINTEGER_H