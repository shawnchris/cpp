//STL set theory functions set_union and set_intersection
//These functions assume that the elements in the given ranges
//are ordered according to some sorting criteria

#include <iostream>
#include <algorithm>
 
using namespace std;

int main()
{
    int setA[5] = {2, 4, 5, 7, 8};               //Line 1
    int setB[7] = {1, 2, 3, 4, 5, 6, 7};         //Line 2
    int setC[5] = {2, 5, 8, 8, 15};              //Line 3
    int setD[6] = {1, 4, 4, 6, 7, 12};           //Line 4

    int AunionB[10];                             //Line 5
    int AunionC[10];                             //Line 6
    int BunionD[15];                             //Line 7
    int AintersectB[10];                         //Line 8
    int AintersectC[10];                         //Line 9

    int *lastElem;                               //Line 10

    ostream_iterator<int> screen(cout, " ");     //Line 11

    cout << "Line 12: setA = ";                  //Line 12
    copy(setA, setA + 5, screen);                //Line 13
    cout << endl;                                //Line 14

    cout << "Line 15: setB = ";                  //Line 15
    copy(setB, setB + 7, screen);                //Line 16
    cout << endl;                                //Line 17

    cout << "Line 18: setC = ";                  //Line 18
    copy(setC, setC + 5, screen);                //Line 19
    cout << endl;                                //Line 20

    cout << "Line 21: setD = ";                  //Line 21
    copy(setD, setD + 6, screen);                //Line 22
    cout << endl;                                //Line 23

    lastElem = set_union(setA, setA + 5,
                         setB, setB + 7,
                         AunionB);               //Line 24

    cout << "Line 25: Set AunionB: ";            //Line 25
    copy(AunionB, lastElem, screen);             //Line 26
    cout << endl;                                //Line 27

    lastElem = set_union(setA, setA + 5,
                         setC, setC + 5,
                         AunionC);               //Line 28

    cout << "Line 29: Set AunionC: ";            //Line 29
    copy(AunionC, lastElem, screen);             //Line 30
    cout << endl;                                //Line 31

    lastElem = set_union(setB, setB + 7,
                         setD, setD + 6,
                         BunionD);               //Line 32

    cout << "Line 33: Set BunionD: ";            //Line 33
    copy(BunionD, lastElem, screen);             //Line 34
    cout << endl;                                //Line 35

    lastElem = set_intersection(setA, setA + 5,
                                setB, setB + 7,
                                AintersectB);    //Line 36

    cout << "Line 37: Set AintersectB: ";        //Line 37
    copy(AintersectB, lastElem, screen);         //Line 38
    cout << endl;                                //Line 39

    lastElem = set_intersection(setA, setA + 5,
                                setC, setC + 5,
                                AintersectC);    //Line 40

    cout << "Line 41: Set AintersectC: ";        //Line 41
    copy(AintersectC, lastElem, screen);         //Line 42
    cout << endl;                                //Line 43

    return 0;
}

