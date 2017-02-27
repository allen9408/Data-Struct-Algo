#include "linkStack.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int partition(int a[], int low, int high) {
	int k = a[low];

	do {
		while(low < high && a[high] >= k) {
			--high;
		}
		if (low < high) {
			a[low] = a[high];
			++low;
		}
		while(low < high && a[low] <= k) {
			++low;
		}
		if (low < high) {
			a[high] = a[low];
			--high;
		}
	} while(low != high);
	a[low] = k;
	return low;
}

void quickSort(int a[], int low, int high) {
	linkStack<int> st;

	if (low < high) {
		int mid = partition(a, low, high);
		if (low < mid-1) {
			st.push(low);
			st.push(mid-1);
		}
		if (high > mid+1) {
			st.push(mid+1);
			st.push(high);
		}
		while(!st.isEmpty()) {
			int q = st.pop();
			int p = st.pop();
			mid = partition(a, p, q);
			if (p < mid-1) {
				st.push(p);
				st.push(mid-1);
			}
			if (q > mid+1) {
				st.push(mid+1);
				st.push(q);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ifstream fin;
	ofstream fout;
	int size = atoi(argv[2]);
	int *array = new int[size];

	fin.open(argv[1]);
	for (int i=0; i<size; i++) {
		fin >> array[i];
	}
	fin.close();
	
	quickSort(array, 0, size-1);
	
	fout.open(argv[3]);
	for (int i=0; i<size; i++) {
		fout << array[i] << endl;
	}
	return 0;
}