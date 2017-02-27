#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int divide(int array[], int low, int high)
{
	int k = array[low];
	do {
		while (low < high && array[high] >= k)
			--high;
		if (low < high) {
			array[low] = array[high];
			++ low;
		}
		while (low < high && array[low] <= k)
			++ low;
		if (low < high) {
			array[high] = array[low];
			-- high;
		}
	} while(low != high);
	array[low] = k;
	return low;
}


void exchange(int array[], int low, int high)
{
	int mid;

	if (low >= high) {
		return;
	}
	mid = divide(array, low, high);
	// cout << low <<"-" << mid <<"-" << high<< endl;
	exchange(array, low, mid-1);
	exchange(array, mid+1, high);
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
	
	exchange(array, 0, size-1);
	
	fout.open(argv[3]);
	for (int i=0; i<size; i++) {
		fout << array[i] << endl;
	}
	return 0;
}