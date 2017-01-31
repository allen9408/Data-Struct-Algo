#include <stdio.h>
#include "quickSort.h"
void divide(int array[], int low, int high)
{
	for (int i=0; i<= high; i++) {
		printf("%d\n", array[i]);
	}
}

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


void exchange(int array[], int low, int high)
{
	if (low >= high) {
		return;
	}
	int l = low;
	int h = high - 1;
	while (l < h) {
		while((array[l] < array[high]) && l < h) {
			l++;
		}
		while((array[h] >= array[high]) && l < h) {
			h--;
		}
		// exchange two number
		swap(&array[l], &array[h]);
	}
	// // printf("%d    %d",array[low] ,array[l] );
	// printf("%d - %d\n",low, high);
	if (array[l] >= array[high]) {
		// printf("swap\n");
		swap(&array[l], &array[high]);
	} else {
		l++;
	}
	// printf("l=%d\n",l);
	// for (int i=0; i<= 7; i++) {
	// 	printf("%d\t", array[i]);
	// }
	// printf("\n");
	exchange(array,low,l-1);
	exchange(array,l+1,high);

}

// int main(int argc, char const *argv[])
// {
// 	int array[8] = {5,8,1,3,6,2,4,7};
// 	int length = sizeof(array)/4 -1;
// 	//int *p = array[0];
// 	// printf("size = %d\n", length);
// 	exchange(array,0,length);
// 	for (int i=0; i<= 7; i++) {
// 		printf("%d\t", array[i]);
// 	}
// 	printf("\n");
// 	// exchange(array,0,3);
// 	// exchange(array,0,1);
// 	// divide(array,0,length);
// 	return 0;
// }

