#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int len = atoi(argv[2]);
	int *data;
	data = new int[len];
	int count = 0;

	ifstream in;

	/* Read data from File */
	in.open(argv[1]);
	int i = 0;
	while (in >> data[i]) {
		// cout << data[i] << endl;
		i ++;
	}
	in.close();
	
	/* Find three numbers which have the sum of 0 */
	for (i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			for (int k = j+1; k < len; k ++){
				if (data[i] + data[j] + data[k] == 0) {
					count ++;
					// break;
				}
			}
		}
	}
	cout << "count = " << count << endl;
	return 0;
}