/*
 * Quick_Insertion_Sort.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: Shan Gao
 */

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define LEN 100000
#define K 1000

int partition(int[], int, int);
void limited_quicksort(int[], int, int, int);
void insertion_sort(int[], int, int);
void modified_quicksort(int A[], int p, int r);
void quicksort(int A[], int p, int r);

int main() {
	int a1[LEN];
	int a2[LEN];
	srand(time(NULL));

	for (int i=0; i<LEN; i++) {
		a1[i] = rand() % 100;
		a2[i]=a1[i];
	}

	clock_t startTime, endTime;
	cout << "Sorting array of length=" << LEN << " with k=" << K << endl;
	startTime = clock();
	modified_quicksort(a1, 0, LEN);
	endTime = clock();
	cout << "Quick Insertion Sort time: " << endTime - startTime << "ms" << endl;

	startTime = clock();
	quicksort(a2, 0, LEN);
	endTime = clock();
	cout << "Quick Sort time: " << endTime - startTime << "ms" << endl;

}

void quicksort(int A[], int p, int r) {
	if (p < r - 1) {
		int q = partition(A, p, r);
		quicksort(A, p, q);
		quicksort(A, q + 1, r);
	}
}

void modified_quicksort(int A[], int p, int r) {
	limited_quicksort(A, p, r, K);
	insertion_sort(A, p, r);
}

void limited_quicksort(int A[], int p, int r, int treshold) {
	if (r - p > treshold) {
		int q = partition(A, p, r);
		limited_quicksort(A, p, q, treshold);
		limited_quicksort(A, q + 1, r, treshold);
	}
}

int partition(int A[], int p, int r) {
	int x, i, j, tmp;

	x = A[r - 1];
	i = p;

	for (j = p; j < r - 1; j++) {
		if (A[j] <= x) {
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
			i++;
		}
	}

	tmp = A[i];
	A[i] = A[r - 1];
	A[r - 1] = tmp;

	return i;
}

void insertion_sort(int A[], int p, int r) {
	int i, j, key;

	for (j = p + 1; j < r; j++) {
		key = A[j];
		for (i = j - 1; i >= p && A[i] > key; i--) {
			A[i + 1] = A[i];
		}
		A[i + 1] = key;
	}
}


