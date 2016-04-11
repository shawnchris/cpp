//Program: Counter-Controlled Loop

#include <iostream>

using namespace std; 

int main()
{
    int limit;    //store the number of data items 
    int number;   //variable to store the number  
    int sum;      //variable to store the sum
    int counter;  //loop control variable

    cout << "Line 1: Enter the number of "
          << "integers in the list: ";              //Line 1
    cin >> limit;                                   //Line 2
    cout << endl;                                   //Line 3

    sum = 0;                                        //Line 4
    counter = 0;                                    //Line 5

    cout << "Line 6: Enter " << limit
         << " integers." << endl;                   //Line 6

    while (counter < limit)                         //Line 7
    {
        cin >> number;                              //Line 8
        sum = sum + number;                         //Line 9
        counter++;                                  //Line 10
    }

    cout << "Line 11: The sum of the " << limit
         << " numbers = " << sum << endl;           //Line 11

    if (counter != 0)                               //Line 12
        cout << "Line 13: The average = "
             << sum / counter << endl;              //Line 13
    else                                            //Line 14
        cout << "Line 15: No input." << endl;       //Line 15

    return 0;                                       //Line 16
}

