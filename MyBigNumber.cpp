#include "MyBigNumber.h"

MyBigNumber::MyBigNumber( const std::string & str ) : BigNumber(str){}

MyBigNumber::MyBigNumber(const char *myCharArray) : BigNumber(myCharArray) {}

MyBigNumber::MyBigNumber(const long &intNum) : BigNumber(intNum) {}
