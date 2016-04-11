
#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    set<int> intSet;                                    //Line 1
    set<int, greater<int> > intSetA;                    //Line 2

    set<int, greater<int> >::iterator intGtIt;          //Line 3

    ostream_iterator<int> screen(cout, " ");            //Line 4

    intSet.insert(16);                                  //Line 5
    intSet.insert(8);                                   //Line 6
    intSet.insert(20);                                  //Line 7
    intSet.insert(3);                                   //Line 8

    cout << "Line 9: intSet: ";                         //Line 9
    copy(intSet.begin(), intSet.end(), screen);         //Line 10
    cout << endl;                                       //Line 11

    intSetA.insert(36);                                 //Line 12
    intSetA.insert(84);                                 //Line 13
    intSetA.insert(30);                                 //Line 14
    intSetA.insert(39);                                 //Line 15
    intSetA.insert(59);                                 //Line 16
    intSetA.insert(238);                                //Line 17
    intSetA.insert(156);                                //Line 18

    cout << "Line 19: intSetA: ";                       //Line 19
    copy(intSetA.begin(), intSetA.end(), screen);       //Line 20
    cout << endl;                                       //Line 21

    intSetA.erase(59);                                  //Line 22

    cout << "Line 23: After removing 59, intSetA: ";    //Line 23
    copy(intSetA.begin(), intSetA.end(), screen);       //Line 24
    cout << endl;                                       //Line 25

    intGtIt = intSetA.begin();                          //Line 26
    ++intGtIt;                                          //Line 27
    ++intGtIt;                                          //Line 28
    ++intGtIt;                                          //Line 29

    intSetA.erase(intGtIt);                             //Line 30

    cout << "Line 31: After removing the fourth "
         << "element, " << endl
         << "         intSetA: ";                       //Line 31
    copy(intSetA.begin(), intSetA.end(), screen);       //Line 32
    cout << endl;                                       //Line 33


    set<int, greater<int> >  intSetB(intSetA);          //Line 34

    cout << "Line 35: intSetB: ";                       //Line 35
    copy(intSetB.begin(), intSetB.end(), screen);       //Line 36
    cout << endl;                                       //Line 37

    intSetB.clear();                                    //Line 38

    cout << "Line 39: After removing all elements, "
         << endl << "         intSetB: ";               //Line 39
    copy(intSetB.begin(), intSetB.end(), screen);       //Line 40
    cout << endl;                                       //Line 41

    multiset<string, greater<string> > namesMultiSet;   //Line 42
    multiset<string, greater<string> >::iterator iter;  //Line 43

    ostream_iterator<string> pScreen(cout, " ");        //Line 44

    namesMultiSet.insert("Donny");                      //Line 45
    namesMultiSet.insert("Zippy");                      //Line 46
    namesMultiSet.insert("Goofy");                      //Line 47
    namesMultiSet.insert("Hungry");                     //Line 48
    namesMultiSet.insert("Goofy");                      //Line 49
    namesMultiSet.insert("Donny");                      //Line 50

    cout << "Line 51: namesMultiSet: ";                 //Line 51
    copy(namesMultiSet.begin(), namesMultiSet.end(),
         pScreen);                                      //Line 52
    cout << endl;                                       //Line 53

    return 0;
}
