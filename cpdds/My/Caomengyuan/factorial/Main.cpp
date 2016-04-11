/*
 * Main.cpp
 *
 *  Created on: Nov 11, 2015
 *      Author: Shawn
 */

#include <iostream>
#include <math.h>
using namespace std;

long factorial (int n) {
	long result = 1;

	for (int i = 2; i <= n; i++)
		result *= i;

	return result;
}

double f (int n, double q, double p) {
	double result = 0;
	double left = 0;
	double right = 0;

	for (int r = 1; r < n; r++) {
		left = factorial(n)/factorial(r)/factorial(n-r) * pow(p, r) * pow(1-p, n-r);
		right = 0;
		for (int s = r + 1; s <= n; s++) {
			right += factorial(n)/factorial(s)/factorial(n-s) * pow(q, s) * pow(1-q, n-s);
		}
		result += left * right;
	}

	return result;
}

int main (int argc, char * const argv[])
{
    cout << f (10, 0.6, 0.4) << endl;
    cout << f (10, 0.4, 0.6) << endl;
    return 0;
}



