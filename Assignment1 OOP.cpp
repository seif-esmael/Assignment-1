//
// Created by USER on 10/7/2022.
//
#include "Assignment 1 OOP.h"

BigDecimalInt::BigDecimalInt()
{
    n1 = "";
}
BigDecimalInt::BigDecimalInt(int decInt)
{
    n1 = to_string(decInt);
}
BigDecimalInt:: BigDecimalInt (string decStr)
{
    n1 = decStr;
}
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec)
{


    string s1 = this->eliminateSign(n1);
    string s2 = this->eliminateSign(anotherDec.n1);
    BigDecimalInt resDecimal;

    if (this->sign() == anotherDec.sign())
    {
        string result = addTwoStrings(s1, s2, true);
        if (this->sign() == 1) {
            result = "-" + result;
        }
        resDecimal.n1 = result;
    }
    else {

        string greater;
        string smaller;
        string greaterSign;
        bool equal = true;

        if (s1.size() > s2.size()) {
            greater = s1;
            smaller = s2;
            if (this->sign()) {
                greaterSign = "-";
            }
            else {
                greaterSign = "+";
            }
            equal = false;
        }
        else if (s2.size() > s1.size()) {
            greater = s2;
            smaller = s1;
            if (anotherDec.sign()) {
                greaterSign = "-";
            }
            else {
                greaterSign = "+";
            }
            equal = false;
        }
        else {
            int i = 0;
            while (i < s1.size()) {
                if (s1[i] > s2[i]) {
                    greater = s1;
                    smaller = s2;
                    if (this->sign()) {
                        greaterSign = "-";
                    }
                    else {
                        greaterSign = "+";
                    }
                    equal = false;
                    break;
                }
                else if (s2[i] > s1[i]) {
                    greater = s2;
                    smaller = s1;
                    if (anotherDec.sign()) {
                        greaterSign = "-";
                    }
                    else {
                        greaterSign = "+";
                    }
                    equal = false;
                    break;
                }
                else {
                    i++;
                }
            }

        }
        if (equal) resDecimal.n1 = "0";
        else {
            if(smaller != "0")
                smaller = this->getTenthComplement(smaller, greater.size());

            string result = addTwoStrings(greater, smaller, false);
            this->deleteLeadingZeros(result);
            if (greaterSign == "-")
            {
                result = greaterSign + result;
            }
            resDecimal.n1 = result;
        }

    }
    return resDecimal;}
BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec)
{
    if (this->sign() != anotherDec.sign())
    {
        if (anotherDec.sign()) {
            int len = anotherDec.n1.size();
            anotherDec.n1 = anotherDec.n1.substr(1, len - 1);
        }
        else {
            if (anotherDec.n1[0] == '+') {
                int len = anotherDec.n1.size();
                anotherDec.n1 = anotherDec.n1.substr(1, len - 1);
            }
            anotherDec.n1 = "-" + anotherDec.n1;
        }
        return *this + anotherDec;
    }
    char sign = '-';
    bool check = true;
    string str = "";
    if (anotherDec.n1[0] == '+')
    {
        anotherDec.n1.erase(0, 1);
    }
    if (n1[0] == '+')
    {
        n1.erase(0, 1);
    }
    while (anotherDec.n1.length() > n1.length())
    {
        n1.insert(0,"0");
    }
    while (n1.length() > anotherDec.n1.length())
    {
        anotherDec.n1.insert(0,"0");
    }

    int carry = 0;
    if (n1 > anotherDec.n1)
    {
        reverse(n1.begin(), n1.end());
        reverse(anotherDec.n1.begin(), anotherDec.n1.end());
        for (int i = 0; i < n1.length(); i++) {
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
        check = false;
        for (int i = 0; i < n1.length(); i++) {
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
            return str;
        }
        else
        {
            return sign + str;

        }

    }
}
bool BigDecimalInt::operator == (BigDecimalInt anotherDec)
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
    int len = max(n1.size(),anotherDec.n1.size());

    for (int j = 0 ; j < len ; j++)
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
    for (int j = 0 ; j < len ; j++)
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
    if (n1 == anotherDec.n1)
    {
        return true;
    }
    return false;
}
bool BigDecimalInt::operator> (BigDecimalInt anotherDec)
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
            return anotherDec.n1 > n1;
        }
        else if (n1[i] == '+' && anotherDec.n1[i] == '-')
        {
            return n1 > anotherDec.n1;
        }
        else if (n1[i] == '-' && anotherDec.n1[i] == '-')
        {
            n1.erase(0,1);
            anotherDec.n1.erase(0,1);
        }
    }

    int len = max(n1.size(),anotherDec.n1.size());

    for (int j = 0 ; j < len ; j++)
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
    for (int j = 0 ; j < len ; j++)
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
    if (n1 > anotherDec.n1)
    {
        return true;
    }
    else
    {
        return false ;
    }

}
bool BigDecimalInt:: operator< (BigDecimalInt anotherDec)
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
    }int len = max(n1.size(),anotherDec.n1.size());

    for (int j = 0 ; j < len ; j++)
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
    for (int j = 0 ; j < len ; j++)
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
BigDecimalInt BigDecimalInt::operator= (BigDecimalInt anotherDec)
{
    anotherDec = n1;
}
int BigDecimalInt:: sign()
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
int BigDecimalInt:: size()
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
ostream&operator<< (ostream& out , BigDecimalInt b)
{
    out << b.n1;
}
string BigDecimalInt::addTwoStrings(string num1, string num2, bool keepCarry)
{

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    for (int i = num1.size() - 1; i >= 0; i--)
    {
        v1.push_back(int(num1[i] - '0'));
    }
    for (int i = num2.size() - 1; i >= 0; i--)
    {
        v2.push_back(int(num2[i] - '0'));
    }
    int carry = 0;
    int i = 0; int j = 0;


    while (i < v1.size() && j < v2.size())
    {
        int result = v1[i] + v2[j] + carry;
        carry = result / 10;
        result = result % 10;
        v3.push_back(result);
        i++;
        j++;
    }
    while (i < v1.size())
    {
        int result = v1[i] + carry;
        carry = result / 10;
        result = result % 10;
        v3.push_back(result);
        i++;

    }
    while (j < v2.size())
    {
        int result = v2[j] + carry;
        carry = result / 10;
        result = result % 10;
        v3.push_back(result);
        j++;
    }
    if (carry != 0 && keepCarry)
    {
        v3.push_back(carry);
    }
    string result = "";
    for (int i = v3.size() - 1; i >= 0; i--)
    {
        result += char(v3[i] + '0');
    }
    return result;
}
string BigDecimalInt::getTenthComplement(string number, int greaterSize)
{
    string result = "";
    for (int i = number.size(); i < greaterSize; i++) {
        number = "0" + number;
    }
    for (int i = 0; i < greaterSize ; i++) {
        result += char('0' + (9 - (number[i] - '0')));
    }
    result = addTwoStrings(result, "1", true);
    return result;
}
string BigDecimalInt::eliminateSign(string number)
{
    int len = number.size();
    if (number[0] == '+' || number[0] == '-') {
        return number.substr(1, len - 1);
    }
    else {
        return number;
    }
}
void BigDecimalInt::deleteLeadingZeros(string &number)
{
    int i = 0;
    int count = 0;
    int len = number.size();
    while (i < len) {
        if (number[i] != '0') break;
        i++;
        count++;
    }
    number = number.substr(count, len - count);
}