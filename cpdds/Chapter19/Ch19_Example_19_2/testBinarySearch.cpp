#include <iostream>
#include "searchSortAlgorithms.h"
  
using namespace std;
 
int main()
{
    int intList[] = {2, 16, 34, 45, 53, 
                     56, 69, 70, 75, 96};           //Line 1

    int pos;                                        //Line 2

    pos = binarySearch(intList, 10, 45);            //Line 3

    if (pos != -1)                                  //Line 4
        cout << "Line 5: " << 45
             << " found at position " 
             << pos << endl;                        //Line 5
    else                                            //Line 6
        cout << "Line 7: " << 45 
             << " is not in intList " << endl;      //Line 7
    return 0;
}
