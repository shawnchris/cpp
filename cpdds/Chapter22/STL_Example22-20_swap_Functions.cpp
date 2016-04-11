//STL functions swap, iter_swap, and swap_ranges

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    char cList[10] = {'A', 'B', 'C', 'D', 'F',
                      'G', 'H', 'I', 'J', 'K'};        //Line 1

    vector<char> charList(cList, cList + 10);          //Line 2
    vector<char>::iterator  charItr;                   //Line 3

    ostream_iterator<char> screen(cout, " ");          //Line 4

    cout << "Line 5: Character list: ";                //Line 5
    copy(charList.begin(), charList.end(), screen);    //Line 6
    cout << endl;                                      //Line 7

    swap(charList[0], charList[1]);                    //Line 8

    cout << "Line 9: Character list after swapping "
         << "the first and second  " << endl
         << "        elements: ";                      //Line 9
    copy(charList.begin(), charList.end(), screen);    //Line 10
    cout << endl;                                      //Line 11

    iter_swap(charList.begin() + 2,
              charList.begin() + 3);                   //Line 12

    cout << "Line 13: Character list after swapping "
         << "the third and fourth " << endl
         << "         elements: ";                     //Line 13

    copy(charList.begin(), charList.end(), screen);    //Line 14
    cout << endl;                                      //Line 15

    charItr = charList.begin() + 4;                    //Line 16
    iter_swap(charItr, charItr + 1);                   //Line 17

    cout << "Line 18: Character list after swapping "
         << "the fifth and sixth " << endl
         << "         elements: ";                     //Line 18
    copy(charList.begin(), charList.end(), screen);    //Line 19
    cout << endl;                                      //Line 20

    int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};    //Line 21

    vector<int> intList(list, list + 10);              //Line 22

    ostream_iterator<int> screenOut(cout, " ");        //Line 23

    cout << "Line 24: intList: ";                      //Line 24
    copy(intList.begin(), intList.end(), screenOut);   //Line 25
    cout << endl;                                      //Line 26

        //swap_ranges
    swap_ranges(intList.begin(), intList.begin() + 4,
                intList.begin() + 5);                  //Line 27

    cout << "Line 28: intList after swapping the first "
         << "four elements " << endl
         << "         with four elements starting at "
         << "the sixth element " << endl
         << "         of intList: ";                   //Line 28
    copy(intList.begin(), intList.end(), screenOut);   //Line 29
    cout << endl;                                      //Line 30

    swap_ranges(list, list + 10, intList.begin());     //Line 31

    cout << "Line 32: list and intList after "
         << "swapping their elements " << endl;        //Line 32
    cout << "Line 33: list: ";                         //Line 33
    copy(list, list+10, screenOut);                    //Line 34
    cout << endl;                                      //Line 35
    cout << "List 36: intList: ";                      //Line 36
    copy(intList.begin(), intList.end(), screenOut);   //Line 37
    cout << endl;                                      //Line 38

    return 0;
}


