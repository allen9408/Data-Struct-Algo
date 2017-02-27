#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

static int compares = 0;

void merge(int a[], int left, int mid, int right)
{
	int *tmp = new int[right - left + 1];
	int i = left, j = mid, k = 0;
	while (i < mid && j <= right) {
		compares ++;
		if (a[i] < a[j]) {
			tmp[k++] = a[i++];
		} else {
			tmp[k++] = a[j++];
		}
	}
	while (i < mid) {
		tmp[k++] = a[i++];
	}
	while (j <= right) {
		tmp[k++] = a[j++];
	}
	for (i=0, k=left; k<=right;) {
		a[k++] = tmp[i++];
	}

	delete [] tmp;
}

void mergeSort(int a[], int left, int right) {
	if (left == right)
		return;
	int mid = (left + right)/2;
	mergeSort(a, left, mid);
	mergeSort(a, mid + 1, right);
	merge(a, left, mid+1, right);
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
	
	mergeSort(array, 0, size-1);
	
	fout.open(argv[3]);
	for (int i=0; i<size; i++) {
		fout << array[i] << endl;
	}
	cout << compares << " compares" << endl;
	return 0;
}