//
// Created by  DingLixiang on 15/12/9.
//

#ifndef ACMALGORITHMS_HIGHPRECISIONINTEGER_H
#define ACMALGORITHMS_HIGHPRECISIONINTEGER_H

#include <string>
#include <algorithm>

const int Ten[4] = {1, 10, 100, 1000};  //
const int MaxLen = 1000;    // 最大位数

struct BigInteger
{
    int d[MaxLen];

    BigInteger(const std::string &s = "0")
    {
        size_t len = s.size();
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
    BigInteger c;
    c.d[0] = a.d[0] > b.d[0] ? a.d[0] : b.d[0];
    int i, x = 0;
    for (i = 0; i <= c.d[0]; ++i)
    {
        x = a.d[i] + b.d[i] + x;
        c.d[i] = x % 10000;
        x /= 10000;
    }
    while (x != 0)
    {
        c.d[++c.d[0]] = x % 10000;
        x /= 10000;
    }

    return c;
}

BigInteger operator -(const BigInteger &a, const BigInteger &b)
{
    BigInteger c;
    c.d[0] = a.d[0];
    int i, x = 0;
    for (i = 0; i <= c.d[0]; ++i)
    {
        x = 10000 + a.d[i] - b.d[i] + x;
        c.d[i] = x % 10000;
        x = x / 10000 - 1;
    }
    while ((c.d[0] > 1) && (c.d[c.d[0]] == 0))
        --c.d[0];

    return c;
}

BigInteger operator *(const BigInteger &a, const BigInteger &b)
{
    BigInteger c;
    c.d[0] = a.d[0] + b.d[0];
    int i, j, x;
    for (i = 0; i <= a.d[0]; ++i)
    {
        x = 0;
        for (j = 0; j < b.d[0]; ++j)
        {
            x = a.d[i] * b.d[i] + x + c.d[i + j - 1];
            c.d[i + j - 1] = x % 10000;
            x /= 10000;
        }
    }

    while((c.d[0] > 1) && (c.d[c.d[0]] == 0))
        --c.d[0];

    return c;
}

bool smaller(const BigInteger &a, const BigInteger &b, int delta)
{
    // Add code here
    if (a.d[0] + delta != b.d[0])
        return a.d[0] + delta < b.d[0];

    int i;
    for (i = a.d[0]; i > 0; --i)
        if (a.d[i] != b.d[i + delta])
            return a.d[i] < b.d[i + delta];

    return true;
}

void minus(BigInteger &a, const BigInteger &b, int delta)
{
    // Add code here
    int i, x = 0;
    for (i = 1; i <= a.d[0] - delta; ++i)
    {
        x = 10000 + a.d[i + delta] - b.d[i] + x;
        a.d[i + delta] = x % 10000;
        x = x / 10000 - 1;
    }

    while ((a.d[0] > 1) && (a.d[a.d[0]] == 0))
        --a.d[0];
}

BigInteger operator *(const BigInteger &a, const int &k)
{
    BigInteger c;
    // Add code here

    return c;
}

BigInteger operator /(const BigInteger &a, const BigInteger &b)
{
    BigInteger c;
    // Add code here

    return c;
}

bool operator ==(const BigInteger &a, const BigInteger &b)
{
    // Add code here

    return true;
}

#endif //ACMALGORITHMS_HIGHPRECISIONINTEGER_H
