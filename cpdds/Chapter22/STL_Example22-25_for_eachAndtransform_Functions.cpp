//STL Functions for_each and transform
 
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

void doubleNum(int& num);

int main()
{
    char cList[5] = {'a', 'b', 'c', 'd', 'e'};       //Line 1

    vector<char>  charList(cList, cList + 5);        //Line 2

    ostream_iterator<char> screen(cout, " ");        //Line 3

    cout << "Line 4: cList: ";                       //Line 4
    copy(charList.begin(), charList.end(), screen);  //Line 5
    cout << endl;                                    //Line 6

        //transform
    transform(charList.begin(), charList.end(),
              charList.begin(), toupper);            //Line 7

    cout << "Line 8: cList after changing all "
         << "lowercase letters to \n"
         << "        uppercase: ";                   //Line 8
    copy(charList.begin(), charList.end(), screen);  //Line 9
    cout << endl;                                    //Line 10

    int list[7] = {2, 8, 5, 1, 7, 11, 3};            //Line 11

    ostream_iterator<int> screenOut(cout, " ");      //Line 12

    cout << "Line 13: list: ";                       //Line 13
    copy(list, list + 7, screenOut);                 //Line 14
    cout << endl;                                    //Line 15

    cout << "Line 16: The effect of for_each "
         << "function:\n         ";                  //Line 16

       //for_each
    for_each(list, list + 7, doubleNum);             //Line 17
    cout << endl;                                    //Line 18

    cout << "Line 19: list after a call to "
         << "for_each function:\n         ";         //Line 19
    copy(list, list + 7, screenOut);                 //Line 20
    cout << endl;                                    //Line 21

    return 0;
}

void doubleNum(int& num)
{
    num = 2 * num;

    cout << num << " ";
}
