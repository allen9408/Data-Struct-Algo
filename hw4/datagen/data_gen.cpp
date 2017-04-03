#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int size = atoi(argv[1]);
	srand((unsigned)time(NULL));
	for (int i=0; i<size; i++) {
		cout << rand() << endl;
	}
	return 0;
}