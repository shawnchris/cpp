//STL Functions find_end and find_first_of
 
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int list1[10] = {12, 34, 56, 21, 34,
                     78, 34, 56, 12, 25};              //Line 1
    int list2[2] = {34, 56};                           //Line 2
    int list3[3] = {56, 21, 35};                       //Line 3
    int list4[5] = {33, 48, 21, 34, 73};               //Line 4

    int* location;                                     //Line 5

    ostream_iterator<int> screenOut(cout, " ");        //Line 6

    cout << "Line 7: list1: ";                         //Line 7
    copy(list1, list1 + 10, screenOut);                //Line 8
    cout << endl;                                      //Line 9

    cout << "Line 10: list2: ";                        //Line 10
    copy(list2, list2 + 2, screenOut);                 //Line 11
    cout << endl;                                      //Line 12

        //find_end
    location = find_end(list1, list1 + 10,
                        list2, list2 + 2);             //Line 13

    if (location != list1 + 10)                        //Line 14
        cout << "Line 15: list2 is found in list 1. "
             << "The last occurrence of \n         "
             << "list2 in list 1 is at position "
             << (location - list1) << endl;            //Line 15
    else                                               //Line 16
        cout << "Line 17: list2 is not in list1."
             << endl;                                  //Line 17

    cout << "Line 18: list3: ";                        //Line 18
    copy(list3, list3 + 3, screenOut);                 //Line 19
    cout << endl;                                      //Line 20

    location = find_end(list1, list1 + 10,
                        list3, list3 + 3);             //Line 21

    if (location != list1 + 10)                        //Line 22
        cout << "Line 23: list3 is found in list 1. "
             << "The last occurrence of list3 in "
             << endl << "list 1 is at position "
             << (location - list1) << endl;            //Line 23
    else                                               //Line 24
        cout << "Line 25: list3 is not in list1."
             << endl;                                  //Line 25

        //find_first_of
    cout << "Line 26: list4: ";                        //Line 26
    copy(list4, list4 + 5, screenOut);                 //Line 27
    cout << endl;                                      //Line 28

    location = find_first_of(list1, list1 + 10,
                             list4, list4 + 5);        //Line 29

    if (location != list1 + 10)                        //Line 30
        cout << "Line 31: The first element "
             << *location << " of list4 is found in "
             << endl << "         list 1 at position "
             << (location - list1) << endl;            //Line 31
    else                                               //Line 32
        cout << "Line 33: No element of list4 is "
             << "in list1." << endl;                   //Line 33

    return 0;
}

