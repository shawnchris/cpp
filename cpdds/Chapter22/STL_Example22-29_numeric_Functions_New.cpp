//Numeric algorithms: accumulate, adjacent_difference,
//                   inner_product, and partial_sum
 
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <functional>

using namespace std;

void print(vector<int>  vList);

int main()
{
    int list[8] = {1, 2, 3, 4, 5, 6, 7, 8};           //Line 1

    vector<int> vecList(list, list + 8);              //Line 2
    vector<int>    newVList(8);                       //Line 3

    cout << "Line 4: vecList: ";                      //Line 4
    print(vecList);                                   //Line 5

        //accumulate function
    int sum = accumulate(vecList.begin(),
                         vecList.end(), 0);           //Line 6

    cout << "Line 7: Sum of the elements of "
         << "vecList = " << sum << endl;              //Line 7

    int product = accumulate(vecList.begin(),
                             vecList.end(),
                             1, multiplies<int>());   //Line 8

    cout << "Line 9: Product of the elements of "
         << "vecList = " << product << endl;          //Line 9

        //adjacent_difference function
    adjacent_difference(vecList.begin(),
                        vecList.end(),
                        newVList.begin());            //Line 10

    cout << "Line 11: newVList: ";                    //Line 11
    print(newVList);                                  //Line 12

    adjacent_difference(vecList.begin(), vecList.end(),
                        newVList.begin(),
                        multiplies<int>());           //Line 13

    cout << "Line 14: newVList: ";                    //Line 14
    print(newVList);                                  //Line 15

        //inner_product function
    sum = inner_product(vecList.begin(), vecList.end(),
                        newVList.begin(), 0);         //Line 16

    cout << "Line 17: Inner product of vecList "
         << "and newVList: " << sum << endl;          //Line 17

    sum = inner_product(vecList.begin(), vecList.end(),
                        newVList.begin(), 0,
                        plus<int>(), minus<int>());   //Line 18

    cout << "Line 19: Inner product of vecList and "
         << "newVList, using - for *: "
         << sum << endl;                              //Line 19

        //partial_sum function
    partial_sum(vecList.begin(), vecList.end(),
                newVList.begin());                    //Line 20

    cout << "Line 21: newVList with partial sum : ";  //Line 21
    print(newVList);                                  //Line 22

        //partial_sum: the default + is replaced by *
    partial_sum(vecList.begin(), vecList.end(),
                newVList.begin(), multiplies<int>()); //Line 23

    cout << "Line 24: newVList with partial "
         << "multiplication: " << endl
         << "         ";                              //Line 24
    print(newVList);                                  //Line 25

    return 0;
}

void print(vector<int>  vList)
{
    ostream_iterator<int> screenOut(cout, " ");       //Line 26

    copy(vList.begin(), vList.end(), screenOut);      //Line 27
    cout << endl;                                     //Line 28
}
