
//Program to test the copy constructor of the class
//arrayListType and unorderedArrayListType

#include <iostream>
#include "unorderedArrayListType.h" 

using namespace std;

void testCopyConstructor(unorderedArrayListType testList);

int main()
{
    unorderedArrayListType intList(25);             //Line 1

    int number;                                     //Line 2

    cout << "List 3: Enter 8 integers: ";           //Line 3

    for (int count = 0; count < 8; count++)         //Line 4
    {
        cin >> number;                              //Line 5
        intList.insertEnd(number);                  //Line 6
    }

    cout << endl;                                   //Line 7

    cout << "Line 8: intList: ";                    //Line 8
    intList.print();                                //Line 9
    cout << endl;                                   //Line 10

        //test copy constructor
	testCopyConstructor(intList);                   //Line 11

	cout << "Line 12: intList after the copy "
         << "constructor: ";                        //Line 12
	intList.print();                                //Line 13
    cout << endl;                                   //Line 14

        //Create temp and initialize it using intList
    unorderedArrayListType temp(intList);           //Line 15

    cout << "Line 16: temp: ";                      //Line 16
    temp.print();                                   //Line 17
    cout << endl;                                   //Line 18

       //Replace the first element of temp.
    temp.replaceAt(0, -75);                         //Line 19

    cout << "Line 20: After replacing the first "
         << "element, temp: ";                      //Line 20
    temp.print();                                   //Line 21
    cout << endl;                                   //Line 22

    cout << "Line 23: intList: ";                   //Line 23
    intList.print();                                //Line 24
    cout << endl;                                   //Line 25

	return 0;                                       //Line 26
}

void testCopyConstructor(unorderedArrayListType testList)
{
      //This function first creates and then destroys
      //testList.
}

