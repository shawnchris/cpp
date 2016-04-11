     
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int firstNum, secondNum;
    double z;
    char ch;
    string name;

    cout << "When prompted, enter the following data and " 
         << "press the enter key: " 
         << endl;
    cout << "8 16.3 Jenny D" << endl;

    firstNum = 4;                                    //Statement 1
    cout << "firstNum = " << firstNum << endl;

    secondNum = 2 * firstNum + 6;                    //Statement 2
    cout << "firstNum = " << firstNum << ", secondNum = " 
         << secondNum << endl;

    z = (firstNum + 1) / 2.0;                        //Statement 3
    cout << "firstNum = " << firstNum << ", secondNum = " 
         << secondNum 
         << ", z = " << z << endl;

    ch = 'A';                                        //Statement 4
    cout << "firstNum = " << firstNum << ", secondNum = " 
         << secondNum 
         << ", z = " << z << ", ch = " << ch << endl;

    cin >> secondNum;                                //Statement 5
    cout << "firstNum = " << firstNum << ", secondNum = " 
         << secondNum << ", z = " << z << ", ch = " 
         << ch << endl;

    cin >> z;                                        //Statement 6
    cout << "firstNum = " << firstNum << ", secondNum = " 
         << secondNum << ", z = " << z << ", ch = " 
         << ch << endl;

    firstNum = 2 * secondNum + static_cast<int>(z);  //Statement 7
    cout << "firstNum = " << firstNum << ", secondNum = " 
         << secondNum << ", z = " << z << ", ch = " 
         << ch << endl;

    cin >> name;                                     //Statement 8
    cout << "firstNum = " << firstNum << ", secondNum = " 
         << secondNum << ", z = " << z << ", ch = " << ch 
         << " , name = " << name << endl;

    secondNum = secondNum + 1;                       //Statement 9
    cout << "firstNum = " << firstNum << ", secondNum = "  
         << secondNum << ", z = " << z << ", ch = " << ch 
         << " , name = " << name << endl;

    cin >> ch;                                       //Statement 10
    cout << "firstNum = " << firstNum << ", secondNum = " 
         << secondNum << ", z = " << z << ", ch = " << ch 
         << " , name = " << name << endl;

    firstNum = firstNum + static_cast<int>(ch);  //Statement 11
    cout << "firstNum = " << firstNum << ", secondNum = " 
         << secondNum << ", z = " << z << ", ch = " << ch 
         << " , name = " << name << endl;

    z = firstNum - z;                       //Statement 12
    cout << "firstNum = " << firstNum << ", secondNum = " 
         << secondNum << ", z = " << z << ", ch = " << ch 
         << " , name = " << name << endl;
   
    return 0;
}
