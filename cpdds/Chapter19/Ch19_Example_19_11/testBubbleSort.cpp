#include <iostream>
#include "searchSortAlgorithms.h"
  
using namespace std;
 
template <class elemType>
void print(elemType list[], int length);

int main()
{
    int intList[] = {2, 56, 34, 25, 73, 
                     46, 89, 10, 5, 16};         //Line 1

    cout << "Line 2: Before sorting, intList: "; //Line 2

    print(intList, 10);                          //Line 3

    cout << endl;                                //Line 4

    bubbleSort(intList, 10);                     //Line 5

    cout << "Line 6: After sorting, intList: ";  //Line 6

    print(intList, 10);                          //Line 7

    return 0;
}

template <class elemType>
void print(elemType list[], int length)
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";

    cout << endl; 
}
