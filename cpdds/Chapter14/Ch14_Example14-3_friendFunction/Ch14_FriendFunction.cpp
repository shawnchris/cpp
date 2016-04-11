//Friend Function Illustration
  
#include <iostream>
#include "classIllusFriend.h"

using namespace std;

int main()
{	
    classIllusFriend aObject;                       //Line 9

    aObject.setx(32);                               //Line 10

    cout << "Line 11: aObject.x: ";                 //Line 11
    aObject.print();                                //Line 12
    cout << endl;                                   //Line 13

    cout << "*~*~*~*~*~* Testing Friend Function "
         << "two *~*~*~*~*~*" << endl << endl;      //Line 14

    two(aObject);                                   //Line 15

    return 0;
}
