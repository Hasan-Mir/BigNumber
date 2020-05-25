#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H

#include "BigNumber.h"

class MyBigNumber : public BigNumber{
    friend MyBigNumber operator*(const MyBigNumber& left , const MyBigNumber& right);
    friend MyBigNumber operator/(const MyBigNumber& left , const MyBigNumber& right);
    friend MyBigNumber operator%(const MyBigNumber &left, const MyBigNumber &right);
private:
    MyBigNumber(){}

public:
    MyBigNumber( const std::string & str );
    MyBigNumber( const char * myCharArray );
    MyBigNumber(const long & intNum );
    MyBigNumber(const MyBigNumber & rightNum);     // copy constructor
    MyBigNumber(const BigNumber & rightNum);     // convert constructor
    MyBigNumber(MyBigNumber && rightNum) noexcept ;    // move constructor
    MyBigNumber& operator=(const MyBigNumber & rightNum);
    MyBigNumber& operator=(MyBigNumber && rightNum) noexcept;    // move assignment
    MyBigNumber operator<<( unsigned shift ) const;
    MyBigNumber multByOneDigit(int n) const;
    MyBigNumber power(int p);
    MyBigNumber operator()(int startIndex, int numberOfDigits) const;
};


#endif