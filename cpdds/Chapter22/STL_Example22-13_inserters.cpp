//Inserters
 
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int temp[8] = {1, 2, 3, 4, 5, 6, 7, 8};           //Line 1

    vector<int> vecList1;                             //Line 2
    vector<int> vecList2;                             //Line 3

    ostream_iterator<int> screenOut(cout, " ");       //Line 4

    copy(temp, temp + 8, back_inserter(vecList1));    //Line 5

    cout << "Line 6: vecList1: ";                     //Line 6
    copy(vecList1.begin(), vecList1.end(),
         screenOut);                                  //Line 7
    cout << endl;                                     //Line 8

    copy(vecList1.begin(), vecList1.end(),
         inserter(vecList2, vecList2.begin()));       //Line 9

    cout << "Line 10: vecList2: ";                    //Line 10
    copy(vecList2.begin(), vecList2.end(),
                           screenOut);                //Line 11
    cout << endl;                                     //Line 12

    list<int> tempList;                               //Line 13

    copy(vecList2.begin(), vecList2.end(),
         front_inserter(tempList));                   //Line 14

    cout << "Line 15: tempList: ";                    //Line 15
    copy(tempList.begin(), tempList.end(),
                           screenOut);                //Line 16
    cout << endl;                                     //Line 17

    return 0;
}

