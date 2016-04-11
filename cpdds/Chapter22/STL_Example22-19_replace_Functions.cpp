//STL Functions replace, replace_if, replace_copy, and
//                replace_copy_if

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
                      'c', 'D', 'e', 'F', 'A'};       //Line 1

    vector<char>  charList(cList, cList + 10);        //Line 2

    ostream_iterator<char> screen(cout, " ");         //Line 3

    cout << "Line 4: Character list: ";               //Line 4
    copy(charList.begin(), charList.end(), screen);   //Line 5
    cout << endl;                                     //Line 6

        //replace
    replace(charList.begin(), charList.end(),
            'A', 'Z');                                //Line 7

    cout << "Line 8: Character list after replacing "
         << "A with Z: " << endl
         << "        ";                               //Line 8
    copy(charList.begin(), charList.end(), screen);   //Line 9
    cout << endl;                                     //Line 10

        //replace_if
    replace_if(charList.begin(), charList.end(),
               isupper, '*');                         //Line 11
    cout << "Line 12: Character list after "
         << "replacing the uppercase  " << endl
         << "         letters with *: ";              //Line 12
    copy(charList.begin(), charList.end(), screen);   //Line 13
    cout << endl;                                     //Line 14

    int list[10] = {12, 34, 56, 21, 34,
                    78, 34, 55, 12, 25};              //Line 15

    vector<int>  intList(list, list + 10);            //Line 16

    ostream_iterator<int> screenOut(cout, " ");       //Line 17

    cout << "Line 18: intList: ";                     //Line 18
    copy(intList.begin(), intList.end(), screenOut);  //Line 19
    cout << endl;                                     //Line 20

    vector<int> temp1(10);                            //Line 21

        //replace_copy
    replace_copy(intList.begin(), intList.end(),
                 temp1.begin(), 34, 0);               //Line 22

    cout << "Line 23: temp1 list after copying "
         << "intList and " << endl
         << "         replacing 34 with 0: ";         //Line 23
    copy(temp1.begin(), temp1.end(), screenOut);      //Line 24
    cout << endl;                                     //Line 25

    vector<int> temp2(10);                            //Line 26

        //replace_copy_if
    replace_copy_if(intList.begin(), intList.end(),
              temp2.begin(), lessThanEqualTo50, 50);  //Line 27

    cout << "Line 28: temp2 after copying intList "
         << "and replacing any " << endl
         << "         numbers less than 50 "
          << "with 50: " << endl << "         ";      //Line 28
    copy(temp2.begin(), temp2.end(), screenOut);      //Line 29
    cout << endl;                                     //Line 30

    return 0;
}

bool lessThanEqualTo50(int num)
{
    return (num <= 50);
}