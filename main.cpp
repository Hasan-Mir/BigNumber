#include <iostream>
#include <cstdint>

#include "BigNumber.h"
#include "MyBigNumber.h"

using namespace std;

int main() {
    cout << boolalpha;
    BigNumber bigNum1(123458);
    BigNumber bigNum2 = "-5450965855";
    // Test >> and <<
    cout << "Num1 = " << bigNum1 << endl;
    cout << "Num2 = " << bigNum2 << endl;
    cout << "---------------------------" << endl;
    // Test + and -
    cout << "Num1 + Num2 = " << bigNum1 + bigNum2 << endl;
    cout << "Num1 - Num2 = " << bigNum1 - bigNum2 << endl;
    cout << "---------------------------" << endl;

    // Test []
    cout << "Num1[2] = " << bigNum1[2] << endl;
    cout << "---------------------------" << endl;

    // Test assignment =
    BigNumber bigNum3 = 1;
    bigNum3 = bigNum2;
    cout << "Num3 = " << bigNum3 << endl;
    cout << "---------------------------" << endl;

    // Test unary -
    cout << "-Num3 = " << -bigNum3 << endl;
    cout << "---------------------------" << endl;

    // Test == != > >= < <=
    cout << "Num3 == Num2   -->   " << (bigNum3 == bigNum2) << endl;
    cout << "Num3 == Num1   -->   " << (bigNum3 == bigNum1) << endl;
    cout << "Num3 != Num1   -->   " << (bigNum3 != bigNum1) << endl;
    cout << "Num3 > Num2   -->   " << (bigNum3 > bigNum2) << endl;
    cout << "Num3 >= Num2   -->   " << (bigNum3 >= bigNum2) << endl;
    cout << "Num3 < Num1   -->   " << (bigNum3 < bigNum1) << endl;
    cout << "Num3 <= Num1   -->   " << (bigNum3 <= bigNum1) << endl;
    cout << "---------------------------" << endl;

    // Test ++ and --
    bigNum1++;
    cout << "Num1++  =  " << bigNum1 << endl;
    cout << "++Num1  =  " << ++bigNum1 << endl;
    cout << "++++Num1  =  " << ++ ++bigNum1 << endl;
    bigNum1--;
    cout << "Num1--  =  " << bigNum1 << endl;
    cout << "--Num1  =  " << --bigNum1 << endl;
    cout << "----Num1  =  " << -- --bigNum1 << endl;
    cout << "---------------------------" << endl;

    // Test shift operator >> and <<
    MyBigNumber myBigNum1 = "6465412338985210";
    MyBigNumber myBigNum2 = "98950003121649841";
    cout << "myBigNum1 = " << myBigNum1 << endl;
    cout << "myBigNum2 = " << myBigNum2 << endl;
    cout << "Num1 >> 3  =  " << (bigNum1 >> 3) << endl;
    cout << "myBigNum1 >> 3  =  " << (myBigNum1 >> 3) << endl;
    cout << "myBigNum1 << 3  =  " << (myBigNum1 << 3) << endl;
    cout << "---------------------------" << endl;


    // Test *  and  /  and  %
    cout << "myBigNum1 * myBigNum2  =  " << myBigNum1 * myBigNum2 << endl;
    cout << "myBigNum1 * 84465454  =  " << myBigNum1 * 84465454 << endl;
    cout << "myBigNum1 / myBigNum2  =  " << myBigNum1 / myBigNum2 << endl;
    cout << "myBigNum2 / myBigNum1  =  " << myBigNum2 / myBigNum1 << endl;
    cout << "myBigNum1 % myBigNum2  =  " << myBigNum1 % myBigNum2 << endl;
    cout << "myBigNum2 % myBigNum1  =  " << myBigNum2 % myBigNum1 << endl;
    cout << "---------------------------" << endl;

    // Test power function  and  ()
    cout << "myBigNum1 ^ 5  =  " << myBigNum1.power(5) << endl;
    cout << "myBigNum1 ^ 0  =  " << myBigNum1.power(0) << endl;
    cout << "myBigNum1(6,5)  =  " << myBigNum1(6,5) << endl;
    cout << "myBigNum2(3,1)  =  " << myBigNum2(3,1) << endl;
    cout << "myBigNum2(3,0)  =  " << myBigNum2(3,0) << endl;
    return 0;
}
