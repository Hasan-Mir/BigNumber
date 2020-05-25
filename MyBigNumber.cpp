#include "MyBigNumber.h"
#include <stdexcept>


MyBigNumber::MyBigNumber( const std::string & str ) : BigNumber(str){}

MyBigNumber::MyBigNumber(const char *myCharArray) : BigNumber(myCharArray) {}

MyBigNumber::MyBigNumber(const long &intNum) : BigNumber(intNum) {}


MyBigNumber::MyBigNumber(const MyBigNumber &rightNum) {
    sign = rightNum.sign;
    numOfDigits = rightNum.numOfDigits;
    numArray = new int8_t[numOfDigits];
    for (size_t i = 0; i < numOfDigits; ++i) {
        numArray[i] = rightNum[i];
    }
}

MyBigNumber::MyBigNumber(const BigNumber &rightNum){
    sign = rightNum.getSign();
    numOfDigits = rightNum.getNumOfDigits();
    numArray = new int8_t[numOfDigits];
    for (size_t i = 0; i < numOfDigits; ++i) {
        numArray[i] = rightNum[i];
    }
}

MyBigNumber::MyBigNumber(MyBigNumber && rightNum) noexcept{
    sign = rightNum.sign;
    numOfDigits = rightNum.numOfDigits;
    numArray = rightNum.numArray;
    rightNum.numArray = nullptr;
}

MyBigNumber& MyBigNumber::operator=(const MyBigNumber & rightNum){
    if(this != &rightNum){
        sign = rightNum.sign;
        numOfDigits = rightNum.numOfDigits;
        delete [] numArray;
        numArray = new int8_t[numOfDigits];
        for (size_t i = 0; i < numOfDigits; ++i) {
            numArray[i] = rightNum[i];
        }
    }
    return *this;
}

MyBigNumber& MyBigNumber::operator=(MyBigNumber && rightNum) noexcept{
    if(this != &rightNum){
        sign = rightNum.sign;
        numOfDigits = rightNum.numOfDigits;
        delete [] numArray;
        numArray = rightNum.numArray;
        rightNum.numArray = nullptr;
    }
    return *this;
}


MyBigNumber MyBigNumber::operator<<(unsigned int shift) const{
    if(shift == 0 || *this == "0"){
        return *this;
    }
    MyBigNumber temp;
    temp.sign = sign;
    temp.numOfDigits = numOfDigits + shift;
    temp.numArray = new int8_t[temp.numOfDigits];
    size_t i = 0;
    for (; i < shift ; ++i) {
        temp[i] = 0;
    }
    for (; i < temp.numOfDigits ; ++i) {
        temp[i] = numArray[i-shift];
    }
    return temp;
}

MyBigNumber MyBigNumber::multByOneDigit(int n) const{      // n must be 1 digit
    if( n > 9 ){
        throw std::invalid_argument("The argument must be one digit.");
    }

    MyBigNumber multiply;
    if(n == 0 || *this == "0"){
        multiply = "0";
        return multiply;
    }
    if(n == 1){
        return *this;
    }
    if(n == -1){
        multiply = *this;
        multiply.sign = !(this->sign);
        return multiply;
    }
    else{
        multiply.sign = sign;
        if(n < 0 && sign){      // - * + = -
            multiply.sign = false;
        }
        else if(n < 0 && !sign){    // - * - = +
            multiply.sign = true;
        }
        multiply.numOfDigits = numOfDigits + 1;
        multiply.numArray = new int8_t[multiply.numOfDigits];
        size_t i = 0;
        int8_t carry = 0;
        int m;
        for (; i < multiply.numOfDigits - 1; ++i) {
            m = ( abs(n) * numArray[i] ) + carry;
            multiply[i] = m % 10;
            carry = m / 10;
        }
        if(carry == 0){
            multiply.numOfDigits -= 1;
        }
        else{
            multiply[i] = carry;
        }
        return multiply;
    }
}

MyBigNumber operator*(const MyBigNumber &left, const MyBigNumber &right) {
    MyBigNumber multiply = "0";
    MyBigNumber nLeft;
   // nLeft.sign = true;
    for (int i = 0; i < right.numOfDigits; ++i) {
        nLeft = (left << i);
        nLeft.sign = true;
        multiply = multiply + nLeft.multByOneDigit(right[i]);     // left must be positive here -> nLeft
    }
    /*multiply.numOfDigits = left.numOfDigits + right.numOfDigits;
    unsigned int numOfZerosOnLeft = 0;
    for (int i = multiply.numOfDigits - 1; i > 0; --i) {
        if(multiply.numArray[i] == 0){
            ++numOfZerosOnLeft;
        }
    }*/
    if(multiply != "0")
        multiply.sign = (left.sign == right.sign);

    //multiply.numOfDigits -= numOfZerosOnLeft;
    return multiply;
}

MyBigNumber MyBigNumber::power(int p) {
    if(p < 0){
        throw std::invalid_argument("The argument must be positive.");
    }
    MyBigNumber temp = 1;
    if(p == 0){
        temp = 1;
        return temp;
    }
    for (int i = 0; i < p; ++i) {
        temp = temp * *this;
    }
    return temp;
}
