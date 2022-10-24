#include <iostream>
#include <string>
#include <regex>
using namespace std;
class BigDecimalInt
{
private:
    string n1;

    string addTwoStrings(string num1, string num2, bool keepCarry) {

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

    string getTenthComplement(string number, int greaterSize) {
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

    string eliminateSign(string number) {
        int len = number.size();
        if (number[0] == '+' || number[0] == '-') {
            return number.substr(1, len - 1);
        }
        else {
            return number;
        }
    }

    void deleteLeadingZeros(string& number) {
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

public:
    BigDecimalInt()
    {
        n1 = "";
    }
    //**************************************************************
      BigDecimalInt(string decStr)
    {
        n1 = decStr;
        if (n1[0] == '+' || n1[0] == '-' || isdigit(n1[0]))
        {
            for (size_t i = 1; i < n1.length(); i++)
            {
                if (!isdigit(n1[i]))
                {
                    cout << "invalid input , setting the number to 0" << endl;
                    n1 = "0";
                    break;
                }
            }
        }
        else
        {
            cout << "invalid input , setting the number to 0" << endl;
            n1 = "0";
        }

    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    BigDecimalInt(int decInt)
    {
        n1 = to_string(decInt);
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    BigDecimalInt operator+ (BigDecimalInt anotherDec)
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

                smaller = this->getTenthComplement(smaller, greater.size());
                string result = addTwoStrings(greater, smaller, false);
                this->deleteLeadingZeros(result);
                result = greaterSign + result;
                resDecimal.n1 = result;


            }

        }
        return resDecimal;
    }
    //**************************************************************
    BigDecimalInt operator- (BigDecimalInt anotherDec)
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
    //+++++++++++++++++++++++++++++++++++++++++++++++++++
    bool operator == (BigDecimalInt anotherDec)
    {
        for (int i = 0; i < 1; i++)
        {
            if (n1[i] == '+' && anotherDec.n1[i] != '+')
            {
                n1.erase(0, 1);
            }
            else if (n1[i] != '+' && anotherDec.n1[i] == '+')
            {
                anotherDec.n1.erase(0, 1);
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
        if (n1 == anotherDec.n1)
        {
            return true;
        }
        return false;
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++
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
                return anotherDec.n1 > n1;
            }
            else if (n1[i] == '+' && anotherDec.n1[i] == '-')
            {
                return n1 > anotherDec.n1;
            }
            else if (n1[i] == '+' && anotherDec.n1[i] == '+')
            {
                anotherDec.n1.erase(0,1);
                n1.erase(0,1);
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
        if (n1 > anotherDec.n1)
        {
            return true;
        }
        return false;
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
        if (n1[0] == '-') 
            return 1;
        else return 0;
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++
    int size()
    {
        for (int i = 0; i < 1; i++)
        {
            if (n1[i] == '+' || n1[i] == '-')
            {
                n1.erase(0, 1);
            }
        }
        return n1.size();
    }
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++
    friend ostream& operator<< (ostream& out, BigDecimalInt b)
    {
        out << b.n1;
        return out;
    }
};

int main()
{
    BigDecimalInt number1("00005");
    BigDecimalInt number2("5");
    if (number1 > number2)
    {
        cout << "Number 1";
    }
    else if (number1 == number2)
        cout << "Equal";
    else if (number2 > number1)
        cout << "Number 2";
}
