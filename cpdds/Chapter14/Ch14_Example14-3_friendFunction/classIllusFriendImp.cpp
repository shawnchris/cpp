  
#include <iostream>
#include "classIllusFriend.h"
 
using namespace std;

void classIllusFriend::print()
{
    cout << "In class classIllusFriend: x = " << x << endl;
}

void classIllusFriend::setx(int a)
{
    x = a;
}

void two(classIllusFriend cIFObject)                //Line 1
{
    classIllusFriend localTwoObject;                //Line 2

    localTwoObject.x = 45;                          //Line 3

    localTwoObject.print();                         //Line 4

    cout << "Line 5: In Friend Function two "
         << "accessing private member variable "
         << "x = " << localTwoObject.x
         << endl;                                   //Line 5

    cIFObject.x = 88;                               //Line 6

    cIFObject.print();                              //Line 7

    cout << "Line 8: In Friend Function two "
         << "accessing private member variable "
         << "x = " << cIFObject.x << endl;          //Line 8
}
