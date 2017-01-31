#include <iostream>
#include <fstream>

using namespace std;

void qfunion(int id[], int p, int q, int len)
{
	int pid = id[p];
	int qid = id[q];
	for (int i = 0; i < len; ++i)
	{
		/* code */
		if (id[i] == pid) {
			id[i] = qid;
		}
	}
}

int qffind(int id[], int p) {
	return id[p];
}

int main(int argc, char const *argv[])
{
	int len = atoi(argv[2]);
	int (*data)[2] = new int[len][2];
	int count = 0;
	int *id = new int[8192];
	for(int i=0; i<8192; i++) {
		id[i] = i;
	}
	ifstream in;

	/* Read data from file */
	in.open(argv[1]);
	for(int i=0; i<len; i++) {
		for (int j=0; j<2; j++) {
			in >> data[i][j];
		}
		// cout << data[i][0] << "	" << data[i][1] <<endl;
	}
	for(int i=0; i<len; i++){
		qfunion(id, data[i][0], data[i][1], 8192);
	}
	// for(int i=0; i<8192; i++){
	// 	cout << id[i] << " ";
	// }
	return 0;
}