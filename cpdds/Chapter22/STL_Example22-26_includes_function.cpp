//STL function includes 
//This function assumes that the elements in the given ranges
//are ordered according to some sorting criteria

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    char setA[5] = {'A', 'B', 'C', 'D', 'E'};      //Line 1
    char setB[10] = {'A', 'B', 'C', 'D', 'E',
                     'F', 'I', 'J', 'K', 'L'};     //Line 2
    char setC[5] = {'A', 'E', 'I', 'O', 'U'};      //Line 3

    ostream_iterator<char> screen(cout, " ");      //Line 4

    cout << "Line 5: setA: ";                      //Line 5
    copy(setA, setA + 5, screen);                  //Line 6
    cout << endl;                                  //Line 7

    cout << "Line 8: setB: ";                      //Line 8
    copy(setB, setB + 10, screen);                 //Line 9
    cout << endl;                                  //Line 10

    cout << "Line 11: setC: ";                     //Line 11
    copy(setC, setC + 5, screen);                  //Line 12
    cout << endl;                                  //Line 13

    if (includes(setB, setB + 10, setA, setA + 5)) //Line 14
        cout << "Line 15: setA is a subset of "
             << "setB." << endl;                   //Line 15
    else                                           //Line 16
        cout << "Line 17: setA is not a subset "
             << "of setB." << endl;                //Line 17

    if (includes(setB, setB + 10, setC, setC + 5)) //Line 18
        cout << "Line 19: setC is a subset of "
             << "setB." << endl;                   //Line 19
    else                                           //Line 20
        cout << "Line 21: setC is not a subset "
             << "of setB." << endl;                //Line 21

    return 0;
}
