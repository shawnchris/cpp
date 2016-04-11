/*
 *  sudoku.h
 *  Sudoku
 *  Created by Prof. Ramavarapu Sreenivas
 *  Inspired by: http://web.eecs.utk.edu/courses/spring2012/cs140/Notes/Sudoku/index.html
 */

#ifndef sudoku
#define sudoku

#include <vector>
#include <fstream>
using std::vector;
using namespace std;
class Sudoku
{
    // Private
    int puzzle[9][9];

    // Private member function that checks if the named row is valid
    bool row_valid(int row)
    {
        // write code that checks if "row" is valid
    	int a[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    	bool valid = true;
    	for (int i = 0; i < 9; i++) {
    		if (puzzle[row][i] != 0) {
    			if (a[puzzle[row][i]-1] != 0) {
    				valid = false;
    				break;
    			}
    			else {
    				a[puzzle[row][i]-1] = 1;
    			}
    		}
    	}
    	return valid;
    }

    // Private member function that checks if the named column is valid
    bool col_valid(int col)
    {
        // check validity of "col"
    	int a[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		bool valid = true;
		for (int i = 0; i < 9; i++) {
			if (puzzle[i][col] != 0) {
				if (a[puzzle[i][col]-1] != 0) {
					valid = false;
					break;
				}
				else {
					a[puzzle[i][col]-1] = 1;
				}
			}
		}
		return valid;
    }

    // Private member function that checks if the named 3x3 block is valid
    bool block_valid(int row, int col)
    {
        // check 3 x 3 block validity
    	int a[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		bool valid = true;
		for (int i = row; i < row+3; i++) {
			for (int j = col; j < col+3; j++) {
				if (puzzle[i][j] != 0) {
					if (a[puzzle[i][j]-1] != 0) {
						valid = false;
						break;
					}
					else {
						a[puzzle[i][j]-1] = 1;
					}
				}
			}
		}
		return valid;
    }

public:
    int total_solution;
    Sudoku::Sudoku() {
    	total_solution = 0;
    };
    // Public member function that reads the incomplete puzzle
    // we are not doing any checks on the input puzzle -- that is,
    // we are assuming they are indeed valid
    bool read_puzzle(int argc, char * const argv[])
    {
    	cout << "Input file name: " << argv[1] << endl;
    	ifstream f(argv[1], ios_base::in);
    	if (f.good()) {
    		for (int i = 0; i < 9; i++)
    			for (int j = 0; j < 9; j++)
    				f >> puzzle[i][j];
    		return true;
    	}
    	else {
    		cout << "Input file does not exist!" << endl;
    		return false;
    	}
    }

    // Public member function that prints the puzzle when called
    void print_puzzle()
    {
        std::cout << std::endl << "Board Position" << std::endl;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // check if we have a legitimate integer between 1 and 9
                if ((puzzle[i][j] >= 1) && (puzzle[i][j] <= 9))
                {
                    // printing initial value of the puzzle with some formatting
                    std::cout << puzzle[i][j] << " ";
                }
                else {
                    // printing initial value of the puzzle with some formatting
                    std::cout << "X ";
                }
            }
            std::cout << std::endl;
        }
    }

    void print_solution()
	{
		std::cout << std::endl << "Solution #" << total_solution << std::endl;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				std::cout << puzzle[i][j] << " ";
			std::cout << std::endl;
		}
	}

    // Public member function that (recursively) implements the brute-force
    // search for possible solutions to the incomplete Sudoku puzzle
    void Solve(int row, int col)
    {
        // this part of the code identifies the row and col number of the
        // first incomplete (i.e. 0) entry in the puzzle.  If the puzzle has
        // no zeros, the variable row will be 9 => the puzzle is done, as
        // each entry is row-, col- and block-valid...

        // use the pseudo code of figure 3 of the description
    	while (row < 9 && puzzle[row][col] != 0) {
    	    col++;
    	    if (col == 9) {
    	      row++;
    	      col = 0;
    	    }
    	}
    	if (row == 9) {
    		total_solution++;
    		print_solution();
    		return;
    	}

    	for (int i = 1; i <= 9; i++) {
    	    puzzle[row][col] = i;
    	    if (row_valid(row) && col_valid(col) &&
    	    	block_valid(row - row % 3, col - col % 3)) {
    	        	Solve(row , col);
    	    }
    	}

    	puzzle[row][col] = 0;
    	return;
    }
};

#endif

