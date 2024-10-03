#pragma once

#include <math.h>
#include <vector>
#include <string>

vector<int> findAllPrimes(int A)
{
    vector<int> primes(A + 1, 1);
    for (int i = 2; i <= std::sqrt(A); i++)
    {
        if (primes[i])
        {
            for (int j = 2; i * j <= A; j++)
            {
                primes[i * j] = 0;
            }
        }
    }

    vector<int> res;
    for (int i = 2; i < primes.size(); i++)
    {
        if (primes[i])
        {
            res.push_back(i);
        }
    }
    return res;
}

string decToBin(int num)
{
    string res;

    while (num > 0)
    {
        char dig = (num % 2) ? '1' : '0';
        res.insert(0, 1, dig);
        num /= 2;
    }

    return res;
}

string decToBase(int base, int num)
{
    string res;

    while (num > 0)
    {
        int remainder = num % base;
        string remainder_str = std::to_string(remainder);
        res = remainder_str + res;
        num /= base;
    }

    return res;
}

int baseToDec(int base, int num)
{
    int res = 0;

    while (num > 0)
    {
        int rmdigit;
    }

    return res;
}


bool isPower(int A)
{
    if (A <= 1)
    {
        return true;
    }

    for (int base = 2; base < A; base++)
    {
        int temp = base;
        int _pow = 2;
        while (temp <= A && _pow < 32)
        {
            temp *= base;
            _pow++;
            if (temp == A)
            {
                return true;
            }
        }
    }

    return false;
}



int hammingDistance(const vector<int>& A) 
{
    int res = 0;
    for (const int& num1: A)
    {
        for (const int& num2 : A)
        {
            int distance = num1 ^ num2;
            for (int i = 0, bit = 1; i < 10; i++)
            {
                if (bit & distance)
                {
                    ++res;
                }
                bit = bit << 1;
            }
        }
    }

    return res;
}

// Sieve of Erastothenes
vector<int> primesum(int A) 
{
    vector<bool> primes(A + 1, true);
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i < A; i++)
    {
        if (!primes[i])
        {
            continue;
        }

        if (i > A / i)
        {
            break;
        }

        for (int j = i * i; j <= A; j += i)
        {
            primes[j] = false;
        }
    }

    for (int i = 2; i <= A; i++)
    {
        if (primes[i] && primes[A - i])
        {
            return { i, A - i };
        }
    }

    return {};
}