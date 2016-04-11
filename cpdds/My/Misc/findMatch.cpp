#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <stack>
using namespace std;

int findMatchingPair(const string& input) {
    stack<char> stack;
    int size = input.size();
    cout << size;
    int match = -1;
    if (size <= 1) return match;

    for (int i = 0; i < size; i++) {
        if (stack.empty()) {
            stack.push(input[i]);
            continue;
        }
        if (stack.top() - 32 == input[i]) {
            stack.pop();
            match = i;
        }
        else {
            stack.push(input[i]);
        }
    }

    return match;
}

int main (int argc, char* argv[])
{
 string input = "PTtCNVvncp";
 stack<char> stack;
     int size = input.size();
     cout << size;
     int match = -1;
     if (size <= 1) return match;

     for (int i = 0; i < size; i++) {
         if (stack.empty()) {
             stack.push(input[i]);
             continue;
         }
         if (stack.top() - 32 == input[i]) {
             stack.pop();
             match = i;
         }
         else {
             stack.push(input[i]);
         }
     }

}
