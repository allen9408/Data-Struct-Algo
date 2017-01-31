#include <iostream>
#include <fstream>

using namespace std;

int qufind(int id[], int p) {
	while (p != id[p]) {
		p = id[p];
	}
	return p;
}

void quunion(int id[], int p, int q, int len)
{
	int pid = qufind(id, p);
	int qid = qufind(id, q);
	id[pid] = qid;
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
		quunion(id, data[i][0], data[i][1], 8192);
	}
	// for(int i=0; i<8192; i++){
	// 	cout << id[i] << " ";
	// }
	return 0;
}