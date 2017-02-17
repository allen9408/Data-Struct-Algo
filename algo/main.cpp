#include "mergeSort.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int test[10] = {23,52,34,515,42,35,745,7664,2684,584};
	mergeSort(test,0,9);
	for (int i=0; i<9; i++)
		cout << test[i] << endl;
	return 0;
}