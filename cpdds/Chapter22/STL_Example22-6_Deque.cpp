 
//deque Example
#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    deque<int> intDeq;                                //Line 1
    ostream_iterator<int> screen(cout, " ");          //Line 2

    intDeq.push_back(13);                             //Line 3
    intDeq.push_back(75);                             //Line 4
    intDeq.push_back(28);                             //Line 5
    intDeq.push_back(35);                             //Line 6

    cout << "Line 7: intDeq: ";                       //Line 7
    copy(intDeq.begin(), intDeq.end(), screen);       //Line 8
    cout << endl;                                     //Line 9

    intDeq.push_front(0);                             //Line 10
    intDeq.push_back(100);                            //Line 11

    cout << "Line 12: After adding two more "
         << "elements, one at the front " << endl
         << "         and one at the back, intDeq: "; //Line 12
    copy(intDeq.begin(), intDeq.end(), screen);       //Line 13
    cout << endl;                                     //Line 14

    intDeq.pop_front();                               //Line 15
    intDeq.pop_front();                               //Line 16

    cout << "Line 17: After removing the first "
         << "two elements, " << endl
         << "         intDeq: ";                      //Line 17
    copy(intDeq.begin(), intDeq.end(), screen);       //Line 18
    cout << endl;                                     //Line 19

    intDeq.pop_back();                                //Line 20
    intDeq.pop_back();                                //Line 21

    cout << "Line 22: After removing the last "
         << "two elements, " << endl
         << "         intDeq = ";                     //Line 22
    copy(intDeq.begin(), intDeq.end(), screen);       //Line 23
    cout << endl;                                     //Line 24

    deque<int>::iterator  deqIt;                      //Line 25

    deqIt = intDeq.begin();                           //Line 26
    ++deqIt;                    //deqIt points to the
                                //second element      //Line 27

    intDeq.insert(deqIt, 444);  //Insert 444 at the
                                //location deqIt      //Line 28

    cout << "Line 29: After inserting 444, "
         << "intDeq:  ";                              //Line 29
    copy(intDeq.begin(), intDeq.end(), screen);       //Line 30
    cout << endl;                                     //Line 31

    intDeq.assign(2, 45);                             //Line 32

    cout << "Line 33: After assigning two "
         << "copies of 45, intDeq: ";                 //Line 33
    copy(intDeq.begin(), intDeq.end(), screen);       //Line 34
    cout << endl;                                     //Line 35

    intDeq.push_front(-10);                           //Line 36
    intDeq.push_back(-999);                           //Line 37

    cout << "Line 38: After inserting two "
         << "elements, one at the front " << endl
         << "         and one at the back, intDeq: "; //Line 38
    copy(intDeq.begin(), intDeq.end(), screen);       //Line 39
    cout << endl;                                     //Line 40

    return 0;
}
