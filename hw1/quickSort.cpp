#include <iostream>
#include "quickSort.h"

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
