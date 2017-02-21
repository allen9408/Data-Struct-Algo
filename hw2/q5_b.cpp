#include "linkStack.h"

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
	int data[10] = {2,1,3,4,7,5,6,0,9,8};
	quickSort(data, 0, 9);
	for (int i=0; i<10; i++){
		cout <<data[i] << endl;
	}
	return 0;
}