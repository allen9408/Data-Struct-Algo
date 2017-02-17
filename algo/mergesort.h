#include <iostream>

template <class T>
void merge(T a[], int left, int mid, int right)
{
	T *tmp = new T[right - left + 1];
	int i = left, j = mid, k = 0;
	while (i < mid && j < right) {
		// tmp[k++] = (a[i] < a[j])?a[i++]:a[j++];
		if (a[i] < a[j]) {
			tmp[k++] = a[i++];
		} else {
			tmp[k++] = a[j++];
		}
	}
	while (i < mid) {
		tmp[k++] = a[i++];
	}
	while (j < right) {
		tmp[k++] = a[j++];
	}
	for (i=0, k=left; k<right;) {
		a[k++] = tmp[i++];
	}

	delete [] tmp;
}

template <class T>
void mergeSort(T a[], int left, int right) {
	if (left == right)
		return;
	int mid = (left + right)/2;
	mergeSort(a, left, mid);
	mergeSort(a, mid + 1, right);
	merge(a, left, mid+1, right);
}
