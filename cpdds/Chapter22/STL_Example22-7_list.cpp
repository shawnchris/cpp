 
//List Container Example

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    list<int> intList1, intList2, intList3, intList4;   //Line 1

    ostream_iterator<int> screen(cout, " ");            //Line 2

    intList1.push_back(23);                             //Line 3
    intList1.push_back(58);                             //Line 4
    intList1.push_back(58);                             //Line 5
    intList1.push_back(58);                             //Line 6
    intList1.push_back(36);                             //Line 7
    intList1.push_back(15);                             //Line 8
    intList1.push_back(93);                             //Line 9
    intList1.push_back(98);                             //Line 10
    intList1.push_back(58);                             //Line 11

    cout << "Line 12: intList1: ";                      //Line 12
    copy(intList1.begin(), intList1.end(), screen);     //Line 13
    cout << endl;                                       //Line 14

    intList2 = intList1;                                //Line 15

    cout << "Line 16: intList2: ";                      //Line 16
    copy(intList2.begin(), intList2.end(), screen);     //Line 17
    cout << endl;                                       //Line 18

    intList1.unique();                                  //Line 19

    cout << "Line 20: After removing the consecutive "
         << "duplicates," << endl
         << "         intList1: ";                      //Line 20
    copy(intList1.begin(), intList1.end(), screen);     //Line 21
    cout << endl;                                       //Line 22

    intList2.sort();                                    //Line 23

    cout << "Line 24: After sorting, intList2: ";       //Line 24
    copy(intList2.begin(), intList2.end(), screen);     //Line 25
    cout << endl;                                       //Line 26

    intList3.push_back(13);                             //Line 27
    intList3.push_back(23);                             //Line 28
    intList3.push_back(25);                             //Line 29
    intList3.push_back(136);                            //Line 30
    intList3.push_back(198);                            //Line 31

    cout << "Line 32: intList3: ";                      //Line 32
    copy(intList3.begin(), intList3.end(), screen);     //Line 33
    cout << endl;                                       //Line 34

    intList4.push_back(-2);                             //Line 35
    intList4.push_back(-7);                             //Line 36
    intList4.push_back(-8);                             //Line 37

    cout << "Line 38: intList4: ";                      //Line 38
    copy(intList4.begin(), intList4.end(), screen);     //Line 39
    cout << endl;                                       //Line 40

    intList3.splice(intList3.begin(), intList4);        //Line 41

    cout << "Line 42: After moving the elements of "
         << "intList4 into intList3," << endl
         << "         intList3: ";                      //Line 42
    copy(intList3.begin(), intList3.end(), screen);     //Line 43
    cout << endl;                                       //Line 44

    intList3.sort();                                    //Line 45

    cout << "Line 46: After sorting, intList3: ";       //Line 46
    copy(intList3.begin(), intList3.end(), screen);     //Line 47
    cout << endl;                                       //Line 48

    intList2.merge(intList3);                           //Line 49

    cout << "Line 50: After merging intList2 and "
         << "intList3, intList2: " << endl
         << "         ";                                //Line 50
    copy(intList2.begin(), intList2.end(), screen);     //Line 51
    cout << endl;                                       //Line 52

    intList2.unique();                                  //Line 53

    cout << "Line 54: After removing the consecutive "
         << "duplicates, intList2: " << endl
         << "         ";                                //Line 54
    copy(intList2.begin(), intList2.end(), screen);     //Line 55
    cout << endl;                                       //Line 56

    return 0;
}
