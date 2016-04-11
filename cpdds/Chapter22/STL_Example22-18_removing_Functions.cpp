//STL Functions remove, remove_if, remove_copy, and
//                remove_copy_if
 
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

bool lessThanEqualTo50(int num);

int main()
{
    char cList[10] = {'A', 'a', 'A', 'B', 'A',
                      'c', 'D', 'e', 'F', 'A'};        //Line 1

    vector<char> charList(cList, cList + 10);          //Line 2
    vector<char>::iterator lastElem, newLastElem;      //Line 3

    ostream_iterator<char> screen(cout, " ");          //Line 4

    cout << "Line 6: Character list: ";                //Line 5
    copy(charList.begin(), charList.end(), screen);    //Line 6
    cout << endl;                                      //Line 7

        //remove
    lastElem = remove(charList.begin(),
                      charList.end(), 'A');            //Line 8

    cout << "Line 9: Character list after "
         << "removing A: ";                            //Line 9
    copy(charList.begin(), lastElem, screen);          //Line 10
    cout << endl;                                      //Line 11

        //remove_if
    newLastElem = remove_if(charList.begin(),
                            lastElem, isupper);        //Line 12
    cout << "Line 13: Character list after "
         << "removing the uppercase " << endl
         << "         letters: ";                      //Line 13
    copy(charList.begin(), newLastElem, screen);       //Line 14
    cout << endl;                                      //Line 15

    int list[10] = {12, 34, 56, 21, 34,
                    78, 34, 55, 12, 25};               //Line 16

    vector<int>  intList(list, list + 10);             //Line 17
    vector<int>::iterator endElement;                  //Line 18

    ostream_iterator<int> screenOut(cout, " ");        //Line 19

    cout << "Line 20: intList: ";                      //Line 20
    copy(intList.begin(), intList.end(), screenOut);   //Line 21
    cout << endl;                                      //Line 22

    vector<int> temp1(10);                             //Line 23

        //remove_copy
    endElement = remove_copy(intList.begin(),
                             intList.end(),
                             temp1.begin(), 34);       //Line 24

    cout << "Line 25: temp1 list after copying "
         << "all the elements of intList "
         << endl << "         except 34: ";            //Line 25
    copy(temp1.begin(), endElement, screenOut);        //Line 26
    cout << endl;                                      //Line 27

    vector<int> temp2(10, 0);                          //Line 28

        //remove_copy_if
    remove_copy_if(intList.begin(), intList.end(),
                   temp2.begin(), lessThanEqualTo50);  //Line 29

    cout << "Line 30: temp2 after copying all the "
         << "elements of intList except " << endl
         << "         numbers less than 50: ";         //Line 30
    copy(temp2.begin(), temp2.end(), screenOut);       //Line 31
    cout << endl;                                      //Line 32

    return 0;
}

bool lessThanEqualTo50(int num)
{
    return (num <= 50);
}
