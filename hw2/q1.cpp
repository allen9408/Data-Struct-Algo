#include <iostream>
#include <cstring>

using namespace std;


// Return the end of a prefix
int EndofPrefix(char a[], int low, int high) {
	if((a[low] >= 'a'&&a[low] <='z')||(a[low] >= 'A'&&a[low] <='Z')) {
		return low+1;
	}
	if (a[low]!='+' && a[low]!='-' && a[low]!='*' && a[low]!='/') {
		return 0;
	}
	int firstend = EndofPrefix(a, low+1, high);
	int secondend = EndofPrefix(a, firstend, high); 
	return secondend;
}

int main(int argc, char const *argv[])
{
	int len = strlen(argv[1]);
	char *a = new char[len];
	strcpy(a,argv[1]);
	int end = EndofPrefix(a, 0, len-1);
	cout << "End of prefix: " << end << endl;
	for (int i=0; i<len; i++) {
		if (i == end) {
			cout << "|";
		}
		cout << a[i];
	}
	cout << endl;
	return 0;
}