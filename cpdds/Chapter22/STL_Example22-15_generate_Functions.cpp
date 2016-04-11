//STL Functions generate and generate_n

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int nextNum();

int main()
{
    vector<int>  vecList(8);                           //Line 1

    ostream_iterator<int> screen(cout, " ");           //Line 2

    generate(vecList.begin(), vecList.end(), nextNum); //Line 3

    cout << "Line 4: vecList after filling with "
          << "numbers: ";                              //Line 4

    copy(vecList.begin(), vecList.end(), screen);      //Line 5
    cout << endl;                                      //Line 6

    generate_n(vecList.begin(), 3, nextNum);           //Line 7

    cout << "Line 8: vecList after filling the "
         << "first three elements " << endl
         << "        with the next number: ";          //Line 8

    copy(vecList.begin(), vecList.end(), screen);      //Line 9
    cout << endl;                                      //Line 10

    return 0;
}

int nextNum()
{
    static int n = 1;

    return n++;
}
