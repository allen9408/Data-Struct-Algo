#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "quickSort.h"

using namespace std;

int Bin_search(int array[], int key, int lo, int hi)
{

	int mid = 0;
	while (lo <= hi) {
		mid = lo + (hi - lo)/2;
		// cout << lo << '	' << mid << '	' << hi << endl;
		// cout << "key = " << key << "mid = " << array[mid] << endl;
		
		if (key < array[mid]) {
			hi = mid - 1;
		}else if (key > array[mid]) {
			lo = mid + 1;
		} else {
			// cout << "key" << key << endl;
			// cout << "mid" << mid << endl;
			return mid;
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	int len = atoi(argv[2]);
	int *data;
	data = new int[len];
	int count = 0;

	ifstream in;

	in.open(argv[1]);
	int i = 0;
	while (in >> data[i]) {
		// cout << data[i] << endl;
		i ++;
	}
	in.close();
	// cout << endl;

	exchange(data, 0, len-1);
	// for (i=0;i<len;i++)
	// 	cout << data[i] << endl;
	// cout << "sort complete" << endl;
	for (i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			// for (int k = j+1; k < len; k ++){
			// 	if (data[i] + data[j] + data[k] == 0)
			// 		count ++;
			// }
			int tmp = -(data[i] + data[j]);
			// cout << tmp << endl;
			if (Bin_search(data, tmp, j, len - 1) >= 0) {
				count ++;
				// cout << "tmp: " << tmp << "count" << count << endl;
			}
		}
	}
	cout << "Count = " << count << endl;
	return 0;
}