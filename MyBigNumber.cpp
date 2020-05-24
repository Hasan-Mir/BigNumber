#include "MyBigNumber.h"

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