#include <iostream>
#include <cstring>

using namespace std;

// Return if it's an identity
bool isId(char a[], int low, int high) {
	if(low == high) {
		if ((a[low] >= 'a'&&a[low] <='z')||(a[low] >= 'A'&&a[low] <='Z')) {
			return true;
		} else {
			return false;
		}
	} else if ((a[high] >= 'a'&&a[high] <='z')||(a[high] >= 'A'&&a[high] <='Z') ||(a[high] >= '0'&&a[high] <='9')) {
		return isId(a, low, high-1);
	} else {
		return false;
	}
}

// Return if it's a prefix
bool isPrefix(char a[], int low, int high) {
	if(isId(a, low, high)) {
		return true;
	}
	if (a[low]!='+' && a[low]!='-' && a[low]!='*' && a[low]!='/') {
		return false;
	}
	bool result = false;
	for (int i=1; i<high-low; i++) {
		result = isPrefix(a,low+1,high-i) && isPrefix(a,high-i+1, high);
		if (result) {
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int len = strlen(argv[1]);
	char *a = new char[len];
	strcpy(a,argv[1]);
	// Start from the end of the input
	for (int i=0; i<=len; i++) {
		if (isPrefix(a, 0, len-i)) {
			cout << "The end of prefix: " << len-i+1 << endl;
			return 1;
		}
	}
	cout << "Not a prefix format!" << endl;
	return 0;
}