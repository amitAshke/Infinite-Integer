//
// Created by amit on 11/7/18.
//

#include "LargeIntegers.h"
#include <iostream>
#include <string.h>
#include <algorithm>
#include <regex>

using namespace std;


//Constructors:

/**
 * A default constructor that insert 0 and true to the members "num" and sign" respectively.
 */
InfInt::InfInt() {
    num = "0";
    sign = true;
}

/**
 * A constructor that recieves a const char variable and set up the member "num" and "sign" accordingly.
 * @param number the value
 */
InfInt::InfInt(const char *number) {
    int index;
    int startingIndex;
    if (number == "0") {
        sign = true;
        num = number;
        return;
    }
    if (number[0] == '-') {
        sign = false;
        startingIndex = 1;

    } else {
        sign = true;
        startingIndex = 0;
    }
    /*for (index = startingIndex; index < strlen(number); index++) {
        if(!isdigit(number[index])) {
            throw;
        }
    }*/
    index = startingIndex;
    while (number[index] == '0' && index < strlen(number) - 1) {
        index++;
    }
    num = "";
    while(index < strlen(number)) {
        num += number[index];
        index++;
    }
}

/**
* A constructor that recieves a long int variable and set up the member "num" and "sign" accordingly.
* @param number the value
*/
InfInt::InfInt(long int number) {
    if (number < 0) {
        sign = false;
        num = toString(number * -1);
        toBinary(toString(number * -1), false);
    } else {
        sign = true;
        num = toString(number);
    }
}

/**
* A constructor that recieves an int variable and set up the member "num" and "sign" accordingly.
* @param number the value
*/
InfInt::InfInt(int number) {
    if (number < 0) {
        sign = false;
        num = toString(number * -1);
    } else {
        sign = true;
        num = toString(number);
    }
}


//Get & Set functions:

/**
 * A get function;
 * @return the value of the InfInt.
 */
string InfInt::getVal() {
    return num;
}

/**
 * A get function;
 * @return the sign of the InfInt (false if negative and true otherwise).
 */
const bool& InfInt::getSign() {
    return sign;
}

/**
 * A set function.
 * @param number the value to be set and change the members "num" and "sign" accordingly.
 */
void InfInt::setVal(char* number) {
    int index;
    int startingIndex;
    if (number == "0") {
        sign = true;
        num = number;
        return;
    }
    if (number[0] == '-') {
        sign = false;
        startingIndex = 1;

    } else {
        sign = true;
        startingIndex = 0;
    }
    /*for (index = startingIndex; index < strlen(number); index++) {
        if(!isdigit(number[index])) {
           throw;
        }
    }*/
    index = startingIndex;
    while (number[index] == '0' && index < strlen(number) - 1) {
        index++;
    }
    num = "";
    while(index < strlen(number)) {
        num += number[index];
        index++;
    }
}

/**
 * A set function.
 * @param number the value to be set and change the members "num" and "sign" accordingly.
 */
void InfInt::setVal(long int number) {
    if (number < 0) {
        sign = false;
        num = toString(number * -1);
        toBinary(toString(number * -1), false);
    } else {
        sign = true;
        num = toString(number);
    }
}

/**
 * A set function.
 * @param newSign the boolean value that is set to "sign".
 */
void InfInt::setSign(bool newSign) {
    sign = newSign;
}


//Assisting functions:

/**
 * The function converts a string variable to a char* variable and returns the result.
 * @param str the string variable that is converted.
 * @return the result of the conversion.
 */
char* InfInt::charArrayCopy(string str) {
    char *charNum = new char[str.length() + 1];
    strcpy(charNum, str.c_str());
    return charNum;
}

/**
 * The function performs a long division by 2 to create a reveresed binary number.
 * @param number the number in string variable.
 * @return a reversed binary number.
 */
string InfInt::longDivision(string number) {
    string ans;
    int index = 0;
    int temp = number[index] - '0';
    while (temp < 2)
        temp = temp * 10 + (number[++index] - '0');
    while (number.size() > index) {
        ans += (temp / 2) + '0';
        temp = (temp % 2) * 10 + number[++index] - '0';
    }
    if (ans.length() == 0)
        return "0";
    return ans;
}

/**
 * The function converts a long int variable to a string variable.
 * @param number the string that is converted.
 * @return the result of the conversion.
 */
string InfInt::toString(long int number) {
    string result = "";
    if (number == 0) {
        return "0";
    }
    while (number != 0) {
        int digit = number % 10;
        char charDig = digit + '0';
        result = charDig + result;
        number /= 10;
    }
    return result;
}

/**
 * The function receives a value and a sign and converts it to a binary number accordingly.
 * @param number the value of the number.
 * @param numSign the sign of the number.
 * @return a binary number representing the original number that was sent.
 */
string InfInt::toBinary(string number, bool numSign) {
    string binNum = "";
    while (number != "0") {
        char digit = number.at(number.length() - 1);
        if (int(digit) % 2 == 0) {
            binNum += "0";
        } else {
            binNum += "1";
        }
        number = longDivision(number);
    }
    std::reverse(binNum.begin(), binNum.end());
    if (!numSign) {
        notBin(binNum);
        add1Bin(binNum);
        toDecimal('1' + binNum);
        return '1' + binNum;
    }
    return '0' + binNum;
}

/**
 * The function receives a binary number and converts it to a decimal number accordingly.
 * @param binary the binary number.
 * @return the result of the conversion.
 */
string InfInt::toDecimal(string binary) {
    bool negative = false;
    InfInt temp = InfInt(1);
    InfInt two = InfInt(2);
    InfInt decimalNumber = InfInt("0");
    if (binary == "1" || binary == "0") {
        return binary;
    }
    if (binary[0] == '1') {
        notBin(binary);
        add1Bin(binary);
        negative = true;
    }
    for (int index1 = binary.length() - 1; index1 >= 0; index1--) {
        if  (binary[index1] == '1') {
            decimalNumber += temp;
        }
        temp *= two;
    }
    if (negative) {
        return '-' + decimalNumber.getVal();
    }
    return decimalNumber.getVal();
}

/**
 * The function applies "not" to a binary number that is given and chnges the binary number by reference.
 * @param binary the number that the "not" is apllied to.
 */
void InfInt::notBin(string& binary) {
    int index = 0;
    while (index < binary.length()) {
        if (binary[index] == '1') {
            binary[index] = '0';
        } else {
            binary[index] = '1';
        }
        index++;
    }
}

/**
 * The function adds 1 to a binary number it recieves and changes the binary number by reference. Note that the
 * function operates properly only if given a positive binary number.
 * @param binary the number to which 1 is added.
 */
void InfInt::add1Bin(string& binary) {
    int index = binary.length() - 1;
    while(index >= 0) {
        if (binary[index] == '0') {
            binary[index] = '1';
            break;
        } else {
            binary[index] = '0';
            index--;
        }
    }
    if (index == -1) {
        binary = '1' + binary;
    }
}

/**
 * The function receives two binary numbers and edits them without changing their value in order for them to have the
 * same length.
 * @param bin1 the first binary number.
 * @param bin2 the second binary number.
 * @param sign1 the sign of the first binary number.
 * @param sign2 the sign of the second binary number.
 */
void InfInt::adjustBinaryLength(string& bin1, string& bin2, bool sign1, bool sign2) {
    if (bin1.length() > bin2.length()) {
        if (sign2) {
            bin2.insert(0, bin1.length() - bin2.length(), '0');
        } else {
            bin2.insert(0, bin1.length() - bin2.length(), '1');
        }
    } else if (bin1.length() < bin2.length()) {
        if (sign1) {
            bin1.insert(0, bin2.length() - bin1.length(), '0');
        } else {
            bin1.insert(0, bin2.length() - bin1.length(), '1');
        }
    }
}

/**
 * The function converts and InfInt variable to int according to it's value.
 * @param other the InfInt variable that the function converts.
 * @return the result of the mentioned conversion.
 */
int InfInt::toInt() {
    int sum = 0;
    string value = this->getVal();
    InfInt intMax("2147483647");
    InfInt intMin("-2147483648");
    if (*this >= intMax) {
        sum = 2147483647;
        return sum;
    }
    if (*this <= intMin) {
        sum = -2147483648;
        return sum;
    }
    for(int index = 0; index < this->getVal().length(); index++) {
        sum = (sum * 10) + (value[index] - '0');
    }
    if (!this->getSign()) {
        sum *= -1;
    }
    return sum;
}

/**
 * The function creates a new InfInt variable that has the same value as the original but is positive.
 * @return a new InfInt variable that contain the original InfInt variable's value and the sign is positive.
 */
InfInt InfInt::absolute() {
    return InfInt(charArrayCopy(this->num));
}

/**
 * The function evaluates both of the InfInt variables and determine if they are equal.
 * @param number1 the first InfInt variable.
 * @param number2 the second InfInt variable.
 * @return true or false based on if they are equal.
 */
bool InfInt::equals(InfInt number1, InfInt number2) {
    return (number1.getVal() == number2.getVal())
           && (number1.getSign() == number2.getSign());
}

/**
 * The function evaluates both of the InfInt variables and determine if the first variable is lesser than the second.
 * @param number1 the first InfInt variable.
 * @param number2 the second InfInt variable.
 * @return true or false based on if the first variable is lesser than the second.
 */
bool InfInt::less(InfInt number1, InfInt number2) {
    bool sign1 = number1.getSign();
    bool sign2 = number2.getSign();
    if(! sign1 && sign2) {
        return true;
    } else if(sign1 && ! sign2) {
        return false;
    } else if(sign1) {
        if(number1.getVal().length() < number2.getVal().length())
            return true;
        if(number1.getVal().length() > number2.getVal().length())
            return false;
        return number1.getVal() < number2.getVal();
    } else {
        if(number1.getVal().length() > number2.getVal().length())
            return true;
        if(number1.getVal().length() < number2.getVal().length())
            return false;
        return number1.getVal().compare(number2.getVal()) > 0;
    }
}

/**
 * The function evaluates both of the InfInt variables and determine if the first variable is greater than the second.
 * @param number1 the first InfInt variable.
 * @param number2 the second InfInt variable.
 * @return true or false based on if the first variable is greater than the second.
 */
bool InfInt::greater(InfInt number1, InfInt number2) {
    return !equals(number1, number2) && !less(number1, number2);
}

/**
 * The function receives two number represented by string variables, perform an addition and return an InfInt variable.
 * @param number1 the first number represented by a string variable.
 * @param number2 the second number represented by a string variable.
 * @return the result of the addition in a form of an InfInt variable.
 */
string InfInt::addition(string number1, string number2) {
    string add = (number1.length() > number2.length()) ?  number1 : number2;
    char carry = '0';
    int differenceInLength = abs( (int) (number1.size() - number2.size()) );
    if(number1.size() > number2.size()) {
        number2.insert(0, differenceInLength, '0'); // put zeros from left
    } else {
        number1.insert(0, differenceInLength, '0');
    }
    for(int index = number1.size() - 1; index >= 0; --index) {
        add[index] = ((carry-'0')+(number1[index]-'0')+(number2[index]-'0')) + '0';
        if(index != 0) {
            if(add[index] > '9') {
                add[index] -= 10;
                carry = '1';
            } else {
                carry = '0';
            }
        }
    }
    if(add[0] > '9') {
        add[0]-= 10;
        add.insert(0,1,'1');
    }
    return add;
}

/**
 * The function receives two number represented by string variables, perform a subtraction and return a string
 * variable.
 * @param number1 the first number represented by a string variable.
 * @param number2 the second number represented by a string variable.
 * @return the result of the subtraction in a form of a string variable.
 */
string InfInt::subtraction(string number1, string number2) {
    string sub = (number1.length()>number2.length())? number1 : number2;
    int differenceInLength = abs((int)(number1.size() - number2.size()));
    if(number1.size() > number2.size()) {
        number2.insert(0, differenceInLength, '0');
    } else {
        number1.insert(0, differenceInLength, '0');
    }
    for(int i=number1.length() - 1; i >= 0; --i) {
        if(number1[i] < number2[i]) {
            number1[i] += 10;
            number1[i - 1]--;
        }
        sub[i] = ((number1[i] - '0') - (number2[i] - '0')) + '0';
    }
    while(sub[0] == '0' && sub.length() != 1) {
        sub.erase(0, 1);
    }
    return sub;
}

/**
 * The function receives two number represented by string variables, perform a multiplication and return a string
 * variable.
 * @param number1 the first number represented by a string variable.
 * @param number2 the second number represented by a string variable.
 * @return the result of the multiplication in a form of a string variable.
 */
string InfInt::multiplication(string number1, string number2) {
    string res = "0";
    if (number1.length() > number2.length()) {
        number1.swap(number2);
    }
    for (int index1 = number1.length() - 1; index1 >= 0; --index1) {
        string temp = number2;
        int currentDigit = number1[index1] - '0';
        int carry = 0;
        for (int index2 = temp.length() - 1; index2 >= 0; --index2) {
            temp[index2] = ((temp[index2] - '0') * currentDigit) + carry;
            if (temp[index2] > 9) {
                carry = (temp[index2] / 10);
                temp[index2] -= (carry * 10);
            } else {
                carry = 0;
            }
            temp[index2] += '0';
        }
        if (carry > 0) {
            temp.insert(0, 1, (carry + '0'));
        }
        temp.append((number1.length() - index1 - 1), '0');
        res = addition(res, temp);
    }
    while (res[0] == '0' && res.length() != 1) {
        res.erase(0, 1);
    }
    return res;
}

/**
 * The function receives two InfInt variables (the original sender the "other" parameter), perform an integer division
 * and return either the result of the division or the remainder
 * @param other the second InfInt variable.
 * @param type a boolean variable that determine wht the function will return.
 * @return if type is true then the result of the division, otherwise the remainder.
 */
InfInt InfInt::divide(InfInt other,bool type) {
    InfInt inf1 = this->absolute();
    InfInt inf2 = other.absolute();
    InfInt remaining;
    InfInt quotient;
    string quoBin = "";
    string remBin = "";
    string thisBin = toBinary(inf1.getVal(), inf1.getSign());
    string otherBin = toBinary(inf2.getVal(), inf2.getSign());
    int size = max(thisBin.length(), otherBin.length());
    if (other.getVal() == "1") {
        if (type) {
            quotient.setVal(charArrayCopy(this->getVal()));
            quotient.setSign(this->getSign() == other.getSign());
            return quotient;
        } else {
            return remaining;
        }
    }
    for (int i = 0; i<size; i++) {
        quoBin += '0';
    }
    for (int i = 0; i < thisBin.length(); i++) {
        remBin = toBinary(remaining.getVal(), remaining.getSign()) + '0';
        remBin[remBin.length() - 1] = thisBin[i];
        remaining.setVal(charArrayCopy(toDecimal('0' + remBin)));
        if (remaining >= inf2) {
            remaining -= inf2;
            quoBin[i] = '1';
        }
    }
    if (type) {
        quotient.setVal(charArrayCopy(toDecimal('0' + quoBin)));
        if (quotient.getVal() == "0") {
            quotient.setSign(true);
        } else {
            quotient.setSign(this->getSign() == other.getSign());
        }
        return quotient;
    } else {
        remaining.setSign(this->getSign() == other.getSign());
        return remaining;
    }
}


//Operators:

/**
 * A function for operator ==.
 * @param other an InfInt variable that the operator == applies to.
 * @return true or false based on whether or not the original InfInt and the "other" InfInt variable are equals.
 */
bool InfInt::operator == (InfInt other) {
    return equals((*this) , other);
}

/**
 * A function for operator !=.
 * @param other an InfInt variable that the operator != applies to.
 * @return true or false based on whether or not the original InfInt and the "other" InfInt variable are not equals.
 */
bool InfInt::operator != (InfInt other) {
    return !equals((*this) , other);
}

/**
 * A function for operator >=.
 * @param other an InfInt variable that the operator >= applies to.
 * @return true or false based on whether or not the original InfInt is greater or equal to the "other" InfInt
 * variable.
 */
bool InfInt::operator >= (InfInt other) {
    return equals((*this) , other) || greater((*this), other);
}

/**
 * A function for operator <=.
 * @param other an InfInt variable that the operator <= applies to.
 * @return true or false based on whether or not the original InfInt is lesser or equal to the "other" InfInt
 * variable.
 */
bool InfInt::operator <= (InfInt other) {
    return equals((*this) , other) || less((*this) , other);
}

/**
 * A function for operator >.
 * @param other an InfInt variable that the operator > applies to.
 * @return true or false based on whether or not the original InfInt is greater than the "other" InfInt variable.
 */
bool InfInt::operator > (InfInt other) {
    return greater((*this), other);
}

/**
 * A function for operator <.
 * @param other an InfInt variable that the operator < applies to.
 * @return true or false based on whether or not the original InfInt is lesser than the "other" InfInt variable.
 */
bool InfInt::operator < (InfInt other) {
    return less((*this), other);
}

/**
 * A function for operator +.
 * @param other an InfInt variable that the operator + applies to.
 * @return the addition result of both the InfInt that called the function and the "other" InfInt.
 */
InfInt InfInt::operator + (InfInt other) {
    InfInt add;
    if(getSign() == other.getSign()) {
        add.setVal(charArrayCopy(addition(getVal(), other.getVal())));
        add.setSign(getSign());
    } else {
        InfInt abs1 = absolute();
        InfInt abs2 = other.absolute();
        if ( absolute() > other.absolute()) {
            add.setVal(charArrayCopy(subtraction(this->getVal(), other.getVal())));
            add.setSign(getSign());
        } else {
            add.setVal(charArrayCopy(subtraction(other.getVal(), this->getVal())));
            add.setSign(other.getSign());
        }
    }
    if (add.getVal() == "0" ) {
        add.setSign(true);
    }
    return add;
}

/**
 * A function for operator -.
 * @param other an InfInt variable that the operator - applies to.
 * @return the subtraction result of both the InfInt that called the function and the "other" InfInt respectivaly.
 */
InfInt InfInt::operator - (InfInt other) {
    other.setSign(!other.getSign());
    return (*this) + other;
}

/**
 * A function for operator *.
 * @param other an InfInt variable that the operator * applies to.
 * @return the multiplication result of both the InfInt that called the function and the "other" InfInt.
 */
InfInt InfInt::operator * (InfInt other) {
    InfInt mul;
    if (this->num == "0" || other.getVal() == "0") {
        return mul;
    }
    mul.setVal(charArrayCopy(multiplication(getVal(), other.getVal())));
    mul.setSign(this->sign == other.getSign());
    return mul;
}

/**
 * A function for operator /.
 * @param other an InfInt variable that the operator / applies to.
 * @return the division result of both the InfInt that called the function and the "other" InfInt respectivaly.
 */
InfInt InfInt::operator / (InfInt other) {
    InfInt div = this->divide(other, true);
    return div;
}

/**
 * A function for operator %.
 * @param other an InfInt variable that the operator % applies to.
 * @return the division remainder of both the InfInt that called the function and the "other" InfInt respectivaly.
 */
InfInt InfInt::operator % (InfInt other) {
    InfInt rem = this->divide(other, false);
    return rem;
}

/**
 * A function for operator +=.
 * @param other an InfInt variable that the operator += applies to.
 * @return the original InfInt variable that used the operator and it's values are the result of it's addition with
 * the "other" InfInt.
 */
InfInt& InfInt::operator += (InfInt other) {
    (*this) = (*this) + other;
    return (*this);
}

/**
 * A function for operator -=.
 * @param other an InfInt variable that the operator -= applies to.
 * @return the original InfInt variable that used the operator and it's values are the result of it's subtraction with
 * the "other" InfInt.
 */
InfInt& InfInt::operator -= (InfInt other) {
    (*this) = (*this) - other;
    return (*this);
}

/**
 * A function for operator *=.
 * @param other an InfInt variable that the operator *= applies to.
 * @return the original InfInt variable that used the operator and it's values are the result of it's multiplication
 * with the "other" InfInt.
 */
InfInt& InfInt::operator *= (InfInt other) {
    (*this) = (*this) * other;
    return (*this);
}

/**
 * A function for operator /=.
 * @param other an InfInt variable that the operator /= applies to.
 * @return the original InfInt variable that used the operator and it's values are the result of it's division with
 * the "other" InfInt.
 */
InfInt& InfInt::operator /= (InfInt other) {
    (*this) = (*this) / other;
    return (*this);
}

/**
 * A function for operator *=.
 * @param other an InfInt variable that the operator *= applies to.
 * @return the original InfInt variable that used the operator and it's values are the remainder of it's division with
 * the "other" InfInt.
 */
InfInt& InfInt::operator %= (InfInt other) {
    (*this) = (*this) % other;
    return (*this);
}

/**
 * A function for operator _++.
 * @return the original InfInt variable that used the operator after it's numeric value increased by one.
 */
InfInt& InfInt::operator ++() {
    (*this) = (*this) + 1;
    return (*this);
}

/**
 * A function for operator ++_.
 * @return the original InfInt variable that used the operator before it's numeric value increased by one.
 */
InfInt InfInt::operator ++(int) {
    InfInt before = (*this);
    (*this) = (*this) + 1;
    return before;
}

/**
 * A function for operator _--.
 * @return the original InfInt variable that used the operator after it's numeric value decreased by one.
 */
InfInt& InfInt::operator --() {
    InfInt one(1);
    (*this) = (*this) - one;
    return (*this);
}

/**
 * A function for operator ++_.
 * @return the original InfInt variable that used the operator before it's numeric value decreased by one.
 */
InfInt InfInt::operator --(int) {
    InfInt before = (*this);
    (*this) = (*this) - 1;
    return before;
}

/**
 * A function for operator &.
 * @param other an InfInt variable that the operator & applies to.
 * @return the result of doing "and" between both InfInt variables' binary numbers.
 */
InfInt InfInt::operator & (InfInt other) {
    string bin1 = toBinary(this->num, this->sign);
    string bin2 = toBinary(other.getVal(), other.getSign());
    adjustBinaryLength(bin1, bin2, this->sign, other.getSign());
    int index = bin1.length() - 1;
    while (index >= 0) {
        if (bin1[index] == '0' || bin2[index] == '0') {
            bin1[index] = '0';
        }
        index--;
    }
    InfInt result(charArrayCopy(toDecimal(bin1)));
    return result;
}

/**
 * A function for operator |.
 * @param other an InfInt variable that the operator | applies to.
 * @return the result of doing "or" between both InfInt variables' binary numbers.
 */
InfInt InfInt::operator | (InfInt other) {
    string bin1 = toBinary(this->num, this->sign);
    string bin2 = toBinary(other.getVal(), other.getSign());
    adjustBinaryLength(bin1, bin2, this->sign, other.getSign());
    int index = bin1.length() - 1;
    while (index >= 0) {
        if (bin1[index] == '1' || bin2[index] == '1') {
            bin1[index] = '1';
        }
        index--;
    }
    InfInt result(charArrayCopy(toDecimal(bin1)));
    return result;
}

/**
 * A function for operator ^.
 * @param other an InfInt variable that the operator ^ applies to.
 * @return the result of doing "xor" between both InfInt variables' binary numbers.
 */
InfInt InfInt::operator ^ (InfInt other) {
    string bin1 = toBinary(this->num, this->sign);
    string bin2 = toBinary(other.getVal(), other.getSign());
    adjustBinaryLength(bin1, bin2, this->sign, other.getSign());
    int index = bin1.length() - 1;
    while (index >= 0) {
        if (bin1[index] == bin2[index]) {
            bin1[index] = '0';
        } else {
            bin1[index] = '1';
        }
        index--;
    }
    InfInt result(charArrayCopy(toDecimal(bin1)));
    return result;
}

/**
 * A function for operator <<.
 * @param shift an int variable that the operator << applies to.
 * @return the result of doing "left shift" on the original InfInt variable's binary as much as the "shift"'s numeric
 * value.
 */
InfInt InfInt::operator << (int shift) {
    string binary = toBinary(this->num, this->sign);
    InfInt newInt;
    while (shift > 0) {
        binary += '0';
        shift--;
    }
    newInt.setVal(charArrayCopy(toDecimal(binary)));
    newInt.setSign(this->sign);
    return newInt;
}

/**
 * A function for operator >>.
 * @param other an int variable that the operator >> applies to.
 * @return the result of doing "right shift" on the original InfInt variable's binary as much as the "shift"'s numeric
 * value.
 */
InfInt InfInt::operator >> (int shift) {
    string binary = toBinary(this->num, this->sign);
    InfInt length((long int)binary.size());
    InfInt newInt;
    bool newSign = this->sign;
    char addBack = '0';
    if (!newSign) {
        addBack = '1';
    }
    while (shift > 0) {
        binary.pop_back();
        binary = addBack + binary;
        shift--;
    }
    newInt.setVal(charArrayCopy(toDecimal(binary)));
    newInt.setSign(newSign);
    return newInt;
}

/**
 * A function for operator &=.
 * @param other an InfInt variable that the operator &= applies to.
 * @return the original InfInt variable that used the operator and it's values are the result of doing "and" between
 * both InfInt variables' binary numbers.
 */
InfInt& InfInt::operator &= (InfInt other) {
    (*this) = (*this) & other;
    return (*this);
}

/**
 * A function for operator |=.
 * @param other an InfInt variable that the operator |= applies to.
 * @return the original InfInt variable that used the operator and it's values are the result of doing "or" between
 * both InfInt variables' binary numbers.
 */
InfInt& InfInt::operator |= (InfInt other) {
    (*this) = (*this) | other;
    return (*this);
}

/**
 * A function for operator ^=.
 * @param other an InfInt variable that the operator ^= applies to.
 * @return the original InfInt variable that used the operator and it's values are the result of doing "xor" between
 * both InfInt variables' binary numbers.
 */
InfInt& InfInt::operator ^= (InfInt other) {
    (*this) = (*this) ^ other;
    return (*this);
}

/**
 * A function for operator <<=.
 * @param other an int variable that the operator <<= applies to.
 * @return the original InfInt variable that used the operator and it's values are the result of doing "left shift"
 * as much as the "shift"'s numeric value.
 */
InfInt& InfInt::operator <<= (int shift) {
    (*this) = (*this) << shift;
    return (*this);
}

/**
 * A function for operator >>=.
 * @param other an int variable that the operator >>= applies to.
 * @return the original InfInt variable that used the operator and it's values are the result of doing "right shift"
 * as much as the "shift"'s numeric value.
 */
InfInt& InfInt::operator >>= (int shift) {
    (*this) = (*this) >> shift;
    return (*this);
}

/**
 * A function for int casting operator.
 */
InfInt::operator int() {
    return this->toInt();
}

istream &operator>>(istream &strm, const InfInt &infinite) {
    strm >> infinite;
}

ostream &operator<<(ostream &strm, InfInt &infinite) {
    if (!infinite.getSign()) {
        strm << "-";
    }
    strm << infinite.getVal();
    return strm;
}