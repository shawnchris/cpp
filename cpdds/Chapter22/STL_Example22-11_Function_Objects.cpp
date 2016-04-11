//Function Objects
 
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <functional>

using namespace std;

int funcAdd(plus<int>, int, int);

int main()
{
    plus<int> addNum;                                 //Line 1
    int num = addNum(34, 56);                         //Line 2

    cout << "Line 3: num = " << num << endl;          //Line 3

    plus<string> joinString;                          //Line 4

    string str1 = "Hello ";                           //Line 5
    string str2 = "There";                            //Line 6

    string str = joinString(str1, str2);              //Line 7

    cout << "Line 8: str = " << str << endl;          //Line 8

    cout << "Line 9: Sum of 34 and 26 = "
         << funcAdd(addNum, 34, 26) << endl;          //Line 9


    int list[8] = {1, 2, 3, 4, 5, 6, 7, 8};           //Line 10

    vector<int>  intList(list, list + 8);             //Line 11
    ostream_iterator<int> screenOut(cout, " ");       //Line 12

    cout << "Line 13: intList: ";                     //Line 13
    copy(intList.begin(), intList.end(), screenOut);  //Line 14
    cout << endl;                                     //Line 15

        //accumulate function
    int sum = accumulate(intList.begin(),
                         intList.end(), 0);           //Line 16

    cout << "Line 17: Sum of the elements of "
         << "intList = " << sum << endl;              //Line 17

    int product = accumulate(intList.begin(),
                             intList.end(),
                             1, multiplies<int>());   //Line 18

    cout << "Line 19: Product of the elements of "
         << "intList = " << product << endl;          //Line 19

    return 0;
}

int funcAdd(plus<int> sum, int x, int y)
{
    return sum(x, y);
}