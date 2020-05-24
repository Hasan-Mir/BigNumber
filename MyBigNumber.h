#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H

#include "BigNumber.h"

class MyBigNumber : public BigNumber{
private:
    MyBigNumber(){}

public:
    MyBigNumber( const std::string & str );
    MyBigNumber( const char * myCharArray );
    MyBigNumber(const long & intNum );
    MyBigNumber(const MyBigNumber & rightNum);     // copy constructor
    MyBigNumber(MyBigNumber && rightNum) noexcept ;    // move constructor
    MyBigNumber& operator=(const MyBigNumber & rightNum);
    MyBigNumber& operator=(MyBigNumber && rightNum) noexcept;    // move assignment
    MyBigNumber multByOneDigit(int n);
};


#endif