#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

static int compares = 0;

void mergeSort(int array[], int low, int high) {
	int length = high - low + 1;
	int *aux = new int[length];

	for (int len = 1; len < length; len += len) {
		/* Copy array to aux */
		for (int i=0; i<length; i++) {
			aux[i] = array[i];
		}

		/* Merge */
		for (int start=0; start<length; start+=2*len) {
			int mid = start + len - 1;
			int end = (start+2*len-1<length)?start+2*len-1:length;
			int i = start;
			int j = mid + 1;

			for(int k = start; k <= end; k++) {
				if (i > mid) {
					array[k] = aux[j++];
				} else if (j > end) {
					array[k] = aux[i++];
				} else if (aux[i] < aux[j]) {
					array[k] = aux[i++];
					compares ++;
				} else {
					array[k] = aux[j++];
					compares ++;
			}
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
	
	mergeSort(array, 0, size-1);
	
	fout.open(argv[3]);
	for (int i=0; i<size; i++) {
		fout << array[i] << endl;
	}
	cout << compares << " compares" << endl;
	return 0;
}