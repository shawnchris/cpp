//STL Functions adjacent_find, merge, and inplace_merge
 
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int list1[10] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};   //Line 1
    int list2[10] = {0, 1, 1, 2, 3, 4, 4, 5, 6, 6};   //Line 2

    int list3[5] = {0, 2, 4, 6, 8};                   //Line 3
    int list4[5] = {1, 3, 5, 7, 9};                   //Line 4

    list<int> intList(list2, list2 + 10);             //Line 5
    list<int>::iterator listItr;                      //Line 6

    vector<int> vecList(list1, list1 + 10);           //Line 7
    vector<int>::iterator    intItr;                  //Line 8

    ostream_iterator<int> screen(cout, " ");          //Line 9

    cout << "Line 10: intList : ";                    //Line 10
    copy(intList.begin(), intList.end(), screen);     //Line 11
    cout << endl;                                     //Line 12

        //adjacent_find
    listItr = adjacent_find(intList.begin(),
                            intList.end());           //Line 13

    if (listItr != intList.end())                     //Line 14
        cout << "Line 15: Adjacent equal "
             << "elements are found " << endl
             << "         The first set of "
             << "adjacent equal elements: "
             << *listItr << endl;                     //Line 15
    else                                              //Line 16
        cout << "Line 17: No adjacent equal "
             << "element found" << endl;              //Line 17

    intList.clear();                                  //Line 18

        //merge
    merge(list3, list3 + 5, list4, list4 + 5,
          back_inserter(intList));                    //Line 19

    cout << "Line 20: intList after merging list3 "
         << "and " << "list4:\n"
         << "         ";                              //Line 20
    copy(intList.begin(), intList.end(), screen);     //Line 21
    cout << endl;                                     //Line 22

        //adjacent_find; second form
    intItr = adjacent_find(vecList.begin(),
                           vecList.end(),
                           greater<int>());           //Line 23

    cout << "Line 24: Last element of first "
         << "sorted sublist: " << *intItr << endl;    //Line 24
    intItr++;                                         //Line 25
    cout << "Line 26: First element of second "
         << "sorted sublist: " << *intItr << endl;    //List 26

    cout << "Line 27: vecList before "
         << "inplace_merge: ";                        //Line 27
    copy(vecList.begin(), vecList.end(), screen);     //Line 28
    cout << endl;                                     //Line 29

        //inplace_merge
    inplace_merge(vecList.begin(), intItr,
                  vecList.end());                     //Line 30

    cout << "Line 31: vecList after inplace_merge: "; //Line 31
    copy(vecList.begin(), vecList.end(), screen);     //Line 32
    cout << endl;                                     //Line 33

    return 0;
}
