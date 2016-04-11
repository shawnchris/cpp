// Soduku Solver using Brute-Force Search implemted using
// recursion.
// Written for IE523: Financial Computation by Prof. Sreenivas
// and GE523: Discrete Event Systems
//
#include <iostream>
#include "sudoku.h"

int main (int argc, char * const argv[])
{
    Sudoku x;
    if (x.read_puzzle(argc, argv)) {
    	x.print_puzzle();
    	x.Solve(0,0);
    	if (x.total_solution == 0)
    		cout << "No solution" << endl;
    }
    return 0;
}
