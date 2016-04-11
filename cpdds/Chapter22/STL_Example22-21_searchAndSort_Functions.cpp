//STL Functions search, search_n, sort, and binary_search

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    int intList[15] = {12, 34, 56, 34, 34,
                       78, 38, 43, 12, 25,
                       34, 56, 62, 5, 49};             //Line 1

    vector<int>  vecList(intList, intList + 15);      //Line 2
    int list[2] = {34, 56};                           //Line 3

    vector<int>::iterator location;                   //Line 4

    ostream_iterator<int> screenOut(cout, " ");       //Line 5

    cout << "Line 6: vecList: ";                      //Line 6
    copy(vecList.begin(), vecList.end(), screenOut);  //Line 7
    cout << endl;                                     //Line 8

    cout << "Line 9: list: ";                         //Line 9
    copy(list, list + 2, screenOut);                  //Line 10
    cout << endl;                                     //Line 11

        //search
    location = search(vecList.begin(), vecList.end(),
                      list, list + 2);                //Line 12

    if (location != vecList.end())                    //Line 13
        cout << "Line 14: list found in vecList. "
             << "The first occurrence of " << endl
             << "         list in vecList is at "
             << "the position "
             << (location - vecList.begin()) << endl; //Line 14
    else                                              //Line 15
        cout << "Line 16: list is not in vecList."
             << endl;                                 //Line 16

        //search_n
    location = search_n(vecList.begin(),
                        vecList.end(), 2, 34);        //Line 17

    if (location != vecList.end())                    //Line 18
        cout << "Line 19: two consecutive "
             << "occurrences of 34 found in " << endl
             << "         vecList at the position "
             << (location - vecList.begin()) << endl; //Line 19
    else                                              //Line 20
        cout << "Line 21: vecList does not contain "
             << "two consecutive occurrences of 34."
             << endl;                                 //Line 21

        //sort
    sort(vecList.begin(), vecList.end());             //Line 22

    cout << "Line 23: vecList after sorting:"
         << endl << "         ";                      //Line 23
    copy(vecList.begin(), vecList.end(), screenOut);  //Line 24
    cout << endl;                                     //Line 25

        //binary_search
    bool found;                                       //Line 26

    found = binary_search(vecList.begin(),
                          vecList.end(), 78);         //Line 27

    if (found)                                        //Line 28
        cout << "Line 29: 78 found in vecList."
             << endl;                                 //Line 29
    else                                              //Line 30
        cout << "Line 31: 78 not in vecList."
             << endl;                                 //Line 31

    return 0;
}

