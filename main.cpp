#include <iostream>
#include <cstdint>

#include "BigNumber.h"
#include "MyBigNumber.h"

using namespace std;

int main() {
    cout << boolalpha;

//    for(unsigned char i{0}; i <= 127; ++i){
//        std::cout << (int) i << '\t' << i << std::endl;
//    }
    //std::cout << x << std::endl;
//    BigNumber x{-37};
//    string str = "-0000";
//    BigNumber y{str};
//    cout << y << endl;
//    cout << "Enter a number: ";
//    cin >> x;
//    x = -y;
//    BigNumber z = -y;
//    cout << (x != y) << endl;
    //  BigNumber myBig1 = -17319;
    // BigNumber myBig2 = "0000173";
    //cout << BigNumber::unsignedLessOrEqual(myBig1, myBig2) << endl;
    //BigNumber a = BigNumber::unsignedSubtract(myBig1, myBig2);
    // cout << (myBig1 >> 3) << "\t" << (myBig1 >> 3).getSign() << endl;
//    try{
//        cout << BigNumber::unsignedSubtract(myBig1, myBig2) << endl;
//    }
//    catch( out_of_range e){
//        cout << e.what() << endl;
//    }

    MyBigNumber myBig1("-10564545654123123");
    MyBigNumber myBig2 = "562198778123";

    //cout << (myBig1 << 5) << "   " << (myBig1 << 5).getNumOfDigits() << endl;

    /*myBig2 = myBig2<<2;
    cout << myBig2 << "\t" << myBig2.getNumOfDigits() << endl;
    myBig2 = myBig2<<2;
    cout << myBig2 << "\t" << myBig2.getNumOfDigits() << endl;*/

    //cout << myBig2.multByOneDigit(9) << "\t\t" << myBig2.multByOneDigit(9).getNumOfDigits() << endl << endl;
//    cout << myBig2 * myBig1 << "\t\t" << (myBig2 * myBig1).getNumOfDigits() << endl;
//    cout << myBig1.power(2) << endl;
//    cout << myBig2.power(5) << endl;

    cout << myBig2 - myBig1 << endl;
    return 0;
}
