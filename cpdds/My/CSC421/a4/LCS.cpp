/*
 * LCS.cpp
 *
 *  Created on: May 5, 2015
 *      Author: Shan Gao
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

void LCS_length (string x, string y, int m, int n, int **c, char **b) {
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			if (x[i-1] == y[j-1]) {
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = 'D';
			}
			else if (c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 'U';
			}
			else {
				c[i][j] = c[i][j-1];
				b[i][j] = 'L';
			}
		}
	}
}

void print_LCS (char **b, string x, int i, int j) {
	if (i==0 || j==0)
		return;
	if (b[i][j] == 'D') {
		print_LCS(b, x, i-1, j-1);
		cout << x[i-1] << " ";
	}
	else if (b[i][j] == 'U') {
		print_LCS(b, x, i-1, j);
	}
	else {
		print_LCS(b, x, i, j-1);
	}
}

int main() {
	string x = "10010101";
	string y = "010110110";
	const int m = x.length();
	const int n = y.length();
	//initialize two dimensional arrays
	int **c = new int *[m+1];
	for (int i=0; i<=m; i++)
		c[i] = new int[n+1];
	char **b = new char *[m+1];
	for (int i=0; i<=m; i++)
		b[i] = new char[n+1];
	for (int i=1; i<=m; i++)
		c[i][0] = 0;
	for (int j=1; j<=n; j++)
		c[0][j] = 0;

	LCS_length(x, y, m, n, c, b);
	cout << "The LCS is ";
	print_LCS(b, x, m, n);

}
