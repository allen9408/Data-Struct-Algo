template <class T>
void swap(T a[], int x, int y) {
	T tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

template <class T>
void sort(T a[], int lo, int hi) {
	if (hi <= lo)
		return;
	int lt = lo + 1;
	int gt = hi - 1;

	if (a[lo] > a[hi]) {
		swap(a, lo, hi);
	}

	T v1 = a[lo];
	T v2 = a[hi];

	int i = lo;
	while (i <= gt) {
		if (a[i] < a[lo]) {
			swap(a, i, lt);
			i++;
			lt++;
		} else if (a[i] > a[hi]) {
			swap(a, i, gt);
			gt--;
		} else {
			i++;
		}
	}
	
	lt--;
	gt++;
	swap(a, lo, lt);
	swap(a, hi, gt);
	sort(a, lo, lt-1);
	sort(a, lt, gt-1);
	sort(a, gt, hi);
}
