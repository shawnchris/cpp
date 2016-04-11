/*
 * Find_maximum_subarray.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: Shawn
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//The object used to hold the return values
struct ret_obj {
public:
	int low;
	int high;
	int sum;
	ret_obj::ret_obj(int, int, int);
};

ret_obj::ret_obj(int l, int h, int s) {
	low = l;
	high = h;
	sum = s;
}

ret_obj *create(int l, int h, int s) {
	return new ret_obj(l, h, s);
}

//Calculate max-crossing-subarray
ret_obj *max_cross_subarray(int a[], int low, int mid, int high) {
	int  leftSum = a[mid], rightSum = a[mid+1];
	int  sum=0, l=mid, h=mid+1;
	for (int i = mid; i >= low; i--) {
		sum += a[i];
		if (sum > leftSum) {
			leftSum = sum;
			l = i;
		}
	}
	sum = 0;
	for (int j = mid + 1; j <= high; j++) {
		sum += a[j];
		if (sum > rightSum) {
			rightSum = sum;
			h = j;
		}
	}
	return new ret_obj(l, h, leftSum + rightSum);
}

//Compare 3 return_value objects and return the max one
ret_obj *max3(ret_obj *a, ret_obj *b, ret_obj *c) {
	return a->sum > b->sum ? (a->sum > c->sum ? a : c) : (b->sum > c->sum ? b : c);
}

//Main recursive method
ret_obj *find_maximum_subarray(int a[], int low, int high) {

	if (low == high) // Base case, only one element.
		return new ret_obj(low, high, a[low]);

	int mid = (low + high)/2;
	ret_obj *maxLeftSum = find_maximum_subarray(a, low, mid);
	ret_obj *maxRightSum = find_maximum_subarray(a, mid + 1, high);
	ret_obj *maxCrossSum = max_cross_subarray(a, low, mid, high);

	return max3(maxLeftSum, maxRightSum, maxCrossSum);
}


int main() {
	int a[100];
	srand(time(NULL));

	cout << "A = (";
	for (int i=0; i<100; i++) {
		a[i] = rand() % 100;
		a[i] = (rand() % 2 == 0) ? (a[i]) : (-1 * a[i]);
		cout << a[i] << ",";
	}
	cout << ")" << endl;

	ret_obj *result = find_maximum_subarray(a, 0, 99);
	cout << "The maximum subarray A[" << result->low << ".." << result->high << "] = " << result->sum << endl;

}


