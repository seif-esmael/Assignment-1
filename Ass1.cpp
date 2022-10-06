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
    bool operator == (BigDecimalInt anotherDec)
    {
        if (n1 == anotherDec.n1)
        {
            return true;
        }
        return false;
    }
    bool operator> (BigDecimalInt anotherDec)
    {
        if (n1 > anotherDec.n1)
        {
            return true;
        }
    }
    BigDecimalInt operator= (BigDecimalInt anotherDec)
    {
        anotherDec = n1;
    }
};
int main()
{
    string n1 , n2;
    cin >> n1 >> n2;
    BigDecimalInt number1(n1);
    BigDecimalInt number2(n2);
}
