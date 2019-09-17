//
// Created by amit on 11/7/18.
//

#ifndef TEST_INFIINT_H
#define TEST_INFIINT_H

#include <string>

using namespace std;

class InfInt {
    string num;
    bool sign;
public:
    //Constructor:
    InfInt();
    InfInt(const char *number);
    InfInt(long int number);
    InfInt(int number);

    //Get & Set functions:
    string getVal();
    const bool& getSign();
    void setVal(char* number);
    void setVal(long int number);
    void setSign(bool newSign);

    //Assisting functions:
    char* charArrayCopy(string str);
    string longDivision(string number);
    string toString(long int number);
    string toBinary(string number, bool numSign);
    string toDecimal(string binary);
    void notBin(string& binary);
    void add1Bin(string& binary);
    void adjustBinaryLength(string& bin1, string& bin2, bool sign1, bool sign2);
    int toInt();
    InfInt absolute();
    bool equals(InfInt number1, InfInt number2);
    bool less(InfInt number1, InfInt number2);
    bool greater(InfInt number1, InfInt number2);
    string addition(string number1, string number2);
    string subtraction(string number1, string number2);
    string multiplication(string number1, string number2);
    InfInt divide(InfInt inf, bool type);

    //Operators:
    bool operator == (InfInt other);
    bool operator != (InfInt other);
    bool operator >= (InfInt other);
    bool operator <= (InfInt other);
    bool operator > (InfInt other);
    bool operator < (InfInt other);
    InfInt operator + (InfInt other);
    InfInt operator - (InfInt other);
    InfInt operator * (InfInt other);
    InfInt operator / (InfInt other);
    InfInt operator % (InfInt other);
    InfInt& operator += (InfInt other);
    InfInt& operator -= (InfInt other);
    InfInt& operator *= (InfInt other);
    InfInt& operator /= (InfInt other);
    InfInt& operator %= (InfInt other);
    InfInt& operator ++();
    InfInt operator ++(int);
    InfInt& operator --();
    InfInt operator --(int);
    InfInt operator & (InfInt other);
    InfInt operator | (InfInt other);
    InfInt operator ^ (InfInt other);
    InfInt operator << (int shift);
    InfInt operator >> (int shift);
    InfInt& operator &= (InfInt other);
    InfInt& operator |= (InfInt other);
    InfInt& operator ^= (InfInt other);
    InfInt& operator <<= (int shift);
    InfInt& operator >>= (int shift);
    explicit operator int();
    friend istream &operator>>(istream &strm, InfInt &infinite);
    friend ostream &operator<<(ostream &strm, InfInt &infinite);
};


#endif //TEST_INFIINT_H
