#include <iostream>
#include <string>
#include <regex>
#include <bits/stdc++.h>
using namespace std;
class BigDecimalInt
{
private:
    string n1;
public:
    BigDecimalInt (string decStr)
    {
        n1 = decStr;
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++
    bool operator == (BigDecimalInt anotherDec)
    {
        for (int i = 0; i < 1; i++)
        {
            if (n1[i] == '+' && anotherDec.n1[i] != '+')
            {
                n1.erase(0,1);
            }
            else if (n1[i] != '+' && anotherDec.n1[i] == '+')
            {
                anotherDec.n1.erase(0,1);
            }
        }
        if (n1 == anotherDec.n1)
        {
            return true;
        }
        return false;
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++
// Problem with negative and negative
    bool operator> (BigDecimalInt anotherDec)
    {
        for (int i = 0; i < 1; i++)
        {
            if (n1[i] == '+' && anotherDec.n1[i] != '+')
            {
                n1.erase(0,1);
            }
            else if (n1[i] != '+' && anotherDec.n1[i] == '+')
            {
                anotherDec.n1.erase(0,1);
            }
            else if (n1[i] == '-' && anotherDec.n1[i] == '+')
            {
                anotherDec.n1 > n1;
            }
            else if (n1[i] == '+' && anotherDec.n1[i] == '-')
            {
                n1 > anotherDec.n1;
            }
        }
        if (n1 > anotherDec.n1)
        {
            return true;
        }
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++
    bool operator< (BigDecimalInt anotherDec)
    {
        for (int i = 0; i < 1; i++)
        {
            if (n1[i] == '+' && anotherDec.n1[i] != '+')
            {
                n1.erase(0,1);
            }
            else if (n1[i] != '+' && anotherDec.n1[i] == '+')
            {
                anotherDec.n1.erase(0,1);
            }
            else if (n1[i] == '-' && anotherDec.n1[i] == '+')
            {
                anotherDec.n1 > n1;
            }
            else if (n1[i] == '+' && anotherDec.n1[i] == '-')
            {
                n1 > anotherDec.n1;
            }
        }
        if (n1 < anotherDec.n1)
        {
            return true;
        }
        return false;
    }

//+++++++++++++++++++++++++++++++++++++++++++++++++++
    BigDecimalInt operator= (BigDecimalInt anotherDec)
    {
        anotherDec = n1;
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++
    int sign()
    {
        for (int i = 0; i < 1; i++)
        {
            if (n1[i] == '-')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
//++++++++++++++++++++++++++++++++++++++++++++++++++++
    int size()
    {
        for (int i = 0; i < 1; i++)
        {
            if (n1[i] == '+' || n1[i] == '-')
            {
                n1.erase(0,1);
            }
        }
        return n1.size();
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
    friend ostream& operator<< (ostream& out , BigDecimalInt b)
    {
        out << b.n1;
    }
};
int main()
{
    BigDecimalInt number1("1231234234");
    BigDecimalInt number2("123781237123");
    BigDecimalInt number3 = number2;
    cout << number1 << " " << number3;
}
