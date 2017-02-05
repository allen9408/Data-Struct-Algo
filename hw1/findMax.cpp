#include "findMax.h"
#include <stdio.h>

// void dimReduc(int array[][], int array_new[], int size)
// {
// 	for (int i = 0; i<size; i++) {
// 		array_new[2*i] 		= array[i][0];
// 		array_new[2*i + 1] 	= array[i][1];
// 	}

// }

int Max(int array[], int low, int high)
{
	if (low == high) {
		return array[low];
	}
	int mid = (low + high) / 2;
	return (Max(array,low,mid)>Max(array,mid+1,high))?Max(array,low,mid):Max(array,mid+1,high);
}