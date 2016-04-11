 
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    equal_to<int> compare;                            //Line 1
    bool isEqual = compare(6, 6);                     //Line 2

    cout << "Line 3: isEqual = " << isEqual << endl;  //Line 3

    greater<string> greaterStr;                       //Line 4

    string str1 = "Hello";                            //Line 5
    string str2 = "There";                            //Line 6

    if (greaterStr(str1, str2))                       //Line 7
        cout << "Line 8: \"" << str1 << "\" is "
             << "greater than \"" << str2 << "\""
             << endl;                                 //Line 8
    else                                              //Line 9
        cout << "Line 10: \"" << str1 << "\" is "
             << "not greater than \"" << str2
             << "\"" << endl;                         //Line 10

    int temp[8] = {2, 3, 4, 5, 1, 7, 8, 9};           //Line 11

    vector<int> vecList(temp, temp + 8);              //Line 12
    vector<int>::iterator intItr1, intItr2;           //Line 13
    ostream_iterator<int> screen(cout, " ");          //Line 14

    cout << "Line 15: vecList: ";                     //Line 15
    copy(vecList.begin(), vecList.end(), screen);     //Line 16
    cout << endl;                                     //Line 17

    intItr1 = adjacent_find(vecList.begin(),
                            vecList.end(),
                            greater<int>());          //Line 18
    intItr2 = intItr1 + 1;                            //Line 19

    cout << "Line 20: In vecList, the first set of "
         << "out-of-order elements is: " << *intItr1
         << " " << *intItr2 << endl;                  //Line 20
    cout << "Line 21: In vecList, the first out-of-"
         << "order element is at position "
         << vecList.end() - intItr2 << endl;          //Line 21

    return 0;
}

