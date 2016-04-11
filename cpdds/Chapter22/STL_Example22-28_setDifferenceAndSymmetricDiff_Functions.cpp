//STL set theory functions: set_difference and
//                          set_symmetric_difference.
//These functions assume that the elements in the given
//ranges are ordered according to some sorting criteria.
 
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int setA[5] = {2, 4, 5, 7, 8};                     //Line 1
    int setB[7] = {3, 4, 5, 6, 7, 8, 10};              //Line 2
    int setC[5] = {1, 5, 6, 8, 15};                    //Line 3

    int AdifferenceC[5];                               //Line 4
    int BsymDiffC[10];                                 //Line 5

    int *lastElem;                                     //Line 6

    ostream_iterator<int> screen(cout, " ");           //Line 7

    cout << "Line 8: setA = ";                         //Line 8
    copy(setA, setA + 5, screen);                      //Line 9
    cout << endl;                                      //Line 10

    cout << "Line 11: setB = ";                        //Line 11
    copy(setB, setB + 7, screen);                      //Line 12
    cout << endl;                                      //Line 13

    cout << "Line 14: setC = ";                        //Line 14
    copy(setC, setC + 5, screen);                      //Line 15
    cout << endl;                                      //Line 16


    lastElem = set_difference(setA, setA + 5,
                              setC, setC + 5,
                              AdifferenceC);           //Line 17

    cout << "Line 18: AdifferenceC: ";                 //Line 18
    copy(AdifferenceC, lastElem, screen);              //Line 19
    cout << endl;                                      //Line 20

    lastElem = set_symmetric_difference(setB, setB + 7,
                                        setC, setC + 5,
                                        BsymDiffC);    //Line 21

    cout << "Line 22: BsymDiffC: ";                    //Line 22
    copy(BsymDiffC, lastElem, screen);                 //Line 23
    cout << endl;                                      //Line 24

    return 0;
}
