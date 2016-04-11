//STL Functions find and find_if
 
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    char cList[10] = {'a', 'i', 'C', 'd', 'e',
                      'f', 'o', 'H', 'u', 'j'};       //Line 1

    vector<char> charList(cList, cList + 10);         //Line 2

    ostream_iterator<char> screen(cout, " ");         //Line 3

    cout << "Line 4: Character list: ";               //Line 4
    copy(charList.begin(), charList.end(), screen);   //Line 5
    cout << endl;                                     //Line 6

    vector<char>::iterator position;                  //Line 7

        //find
    position = find(charList.begin(),
                    charList.end(), 'd');             //Line 8

    if (position != charList.end())                   //Line 9
        cout << "Line 10: The element is found at "
             << "position "
             << (position - charList.begin())
             << endl;                                 //Line 10
    else                                              //Line 11
        cout << "Line 12: The element is not in "
             << "the list." << endl;                  //Line 12

        //find_if
    position = find_if(charList.begin(),
                       charList.end(), isupper);      //Line 13

    if (position != charList.end())                   //Line 14
        cout << "Line 15: The first uppercase "
             << "letter is found at position "
             << (position - charList.begin())
             << endl;                                 //Line 15
    else                                              //Line 16
        cout << "Line 17: The element is not in "
             << "the list." << endl;                  //Line 17

    return 0;
}
