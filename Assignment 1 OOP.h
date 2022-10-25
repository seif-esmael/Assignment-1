//
// Created by USER on 10/7/2022.
//
#include <iostream>
#include <string>
#include <regex>
#include <bits/stdc++.h>
using namespace std ;
class BigDecimalInt
{
private:
    string n1;
    string addTwoStrings(string num1, string num2, bool keepCarry);
    string getTenthComplement(string number, int greaterSize);
    string eliminateSign(string number);
    void deleteLeadingZeros(string& number);
public:
     BigDecimalInt();
     BigDecimalInt (string decStr); // Initializes from string & rejects bad input
     BigDecimalInt (int decInt); // Initialize from integer
     BigDecimalInt operator+ (BigDecimalInt anotherDec); // member fn
     BigDecimalInt operator- (BigDecimalInt anotherDec); // member fn
     bool operator< (BigDecimalInt anotherDec); // member fn
     bool operator> (BigDecimalInt anotherDec); // member fn
     bool operator==(BigDecimalInt anotherDec); // member fn
     BigDecimalInt operator= (BigDecimalInt anotherDec); // member fn
     int size(); // member fn
     int sign(); // member fn
     friend ostream& operator << (ostream& out, BigDecimalInt b);

};

#ifndef ASSIGNMENT_1__OOP__ASSIGNMENT_1_OOP_H
#define ASSIGNMENT_1__OOP__ASSIGNMENT_1_OOP_H

#endif //ASSIGNMENT_1__OOP__ASSIGNMENT_1_OOP_H
