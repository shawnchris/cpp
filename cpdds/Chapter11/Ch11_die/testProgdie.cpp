//The user program that uses the class rollDie
 
#include <iostream>
#include "die.h"

using namespace std;

int main()    
{                                                       //Line 1
    die die1;                                           //Line 2
    die die2;                                           //Line 3

    cout << "Line 4: die1: " << die1.getNum() << endl;  //Line 4

    cout << "Line 5: die2: " << die2.getNum() << endl;  //Line 5

    cout << "Line 6: After rolling die1: "
         << die1.roll() << endl;                        //Line 6

    cout << "Line 7: After rolling die2: "
         << die2.roll() << endl;                        //Line 7
    cout << "Line 8: The sum of the numbers rolled"
         << " by the dice is: "
         << die1.getNum() + die2.getNum() << endl;      //Line 8

    cout << "Line 9: After again rolling, the sum of "
         << "the numbers rolled is: "
         << die1.roll() + die2.roll() << endl;          //Line 9

    return 0;                                           //Line 10
}//end main                                             //Line 11
