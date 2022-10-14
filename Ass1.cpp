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
     BigDecimalInt operator- (BigDecimalInt anotherDec)
     {
         
    char sign = '-';
    bool check = true ;
    string str = "";
    if (anotherDec.n1[0] == '+')
    {
        anotherDec.n1.erase(0,1);
    }
    if (n1[0] == '+')
    {
        n1.erase(0,1);
    }

    int carry = 0;
    if (n1 > anotherDec.n1)
    {
        reverse(n1.begin(), n1.end());
        reverse(anotherDec.n1.begin(), anotherDec.n1.end());
        for (int i = 0 ; i < n1.length() ; i++ ) {
            int sub = ((n1[i] - '0') - (anotherDec.n1[i] - '0') - carry);
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;

            str.push_back(sub + '0');
        }
    }
    else
    {
        reverse(n1.begin(), n1.end());
        reverse(anotherDec.n1.begin(), anotherDec.n1.end());
        check = false ;
        for (int i = 0 ; i < n1.length() ; i++ ) {
            int sub = ((anotherDec.n1[i] - '0') - (n1[i] - '0') - carry);
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;

            str.push_back(sub + '0');
        }
    }
    reverse(str.begin(), str.end());

    while (str.length() != 1 and str[0] == '0')
    {
        str.erase(str.begin());
    }
    if (check)
    {
        return str;
    }
    else
    {
        if (str == "0")
        {
            return str ;
        }
        else
        {
            return sign + str ;

        }

    }

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
            else if (n1[i] == '-' && anotherDec.n1[i] == '-')
            {
                n1.erase(0,1);
                anotherDec.n1.erase(0,1);
                if (n1 > anotherDec.n1)
                {
                    return false;
                }
                else
                {
                    return true;
                }  
            }
        }
        for (int j = 0 ; j < n1.size(); j++)
        {
            if (anotherDec.n1[j] == '0' || n1[j] == '0')
            {
                n1.erase(0,1);
                anotherDec.n1.erase(0,1);
            }
            else
            {
                break;
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
        else if (n1[i] == '+' && anotherDec.n1[i] == '+')
        {
            anotherDec.n1.erase(0,1);
            n1.erase(0,1);
        }
        else if (n1[i] == '-' && anotherDec.n1[i] == '+')
        {
            return n1 < anotherDec.n1 ;
        }
        else if (n1[i] == '+' && anotherDec.n1[i] == '-')
        {
            return anotherDec.n1 < n1 ;
        }
        else if (n1[i] == '-' && anotherDec.n1[i] == '-')
        {
            n1.erase(0,1);
            anotherDec.n1.erase(0,1);
            if (n1 < anotherDec.n1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
    for (int j = 0 ; j < n1.size(); j++)
    {
        if (anotherDec.n1[0] == '0' )
        {
            anotherDec.n1.erase(0,1);
        }
        else
        {
            break;
        }
    }
    for (int j = 0 ; j < n1.size(); j++)
    {
        if (n1[0] == '0' )
        {
            n1.erase(0,1);
        }
        else
        {
            break;
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
    BigDecimalInt number1("999999999999");
    BigDecimalInt number2("0999999999999");
    if (number1 > number2)
    {
        cout << "BIG";
    }
    else
    {
        cout << "SMALL";
    }
    
}
