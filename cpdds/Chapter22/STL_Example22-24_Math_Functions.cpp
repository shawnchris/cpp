//STL Functions count, count_if, min_element,
//                max_element, random_shuffle
 
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

void doubleNum(int num);

int main()
{
    char cList[10] = {'Z', 'a', 'Z', 'B', 'Z',
                      'c', 'D', 'e', 'F', 'Z'};        //Line 1

    vector<char>  charList(cList, cList + 10);         //Line 2

    ostream_iterator<char> screen(cout, " ");          //Line 3

    cout << "Line 4: charList: ";                      //Line 4
    copy(charList.begin(), charList.end(), screen);    //Line 5
    cout << endl;                                      //Line 6

        //count
    int noOfZs = count(charList.begin(),
                       charList.end(), 'Z');           //Line 7

    cout << "Line 8: Number of Zs in charList = "
         << noOfZs << endl;                            //Line 8

        //count_if
    int noOfUpper = count_if(charList.begin(),
                             charList.end(), isupper); //Line 9

    cout << "Line 10: Number of uppercase letters "
         << "in charList = " << noOfUpper << endl;     //Line 10

    int list[10] = {12, 34, 56, 21, 34,
                    78, 34, 55, 12, 25};               //Line 11

    ostream_iterator<int> screenOut(cout, " ");        //Line 12

    cout << "Line 13: list: ";                         //Line 13
    copy(list, list + 10, screenOut);                  //Line 14
    cout << endl;                                      //Line 15

        //max_element
    int *maxLoc = max_element(list, list + 10);        //Line 16

    cout << "Line 17: Largest element in list = "
         << *maxLoc << endl;                           //Line 17

        //min_element
    int *minLoc = min_element(list, list + 10);        //Line 18

    cout << "Line 19: Smallest element in list = "
         << *minLoc << endl;                           //Line 19

        //random_shuffle
    random_shuffle(list, list + 10);                   //Line 20

    cout << "Line 21: list after random shuffle:\n"
         << "         ";                               //Line 21
    copy(list, list + 10, screenOut);                  //Line 22
    cout << endl;                                      //Line 23

    return 0;
}

void doubleNum(int num)
{
    cout << 2 * num << " ";
}
