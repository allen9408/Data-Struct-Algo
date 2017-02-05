#include <iostream>
#include <fstream>
#include "findMax.h"

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
	int *temp = new int[2*len];
	
	int count = 0;
	ifstream in;

	/* Read data from file */
	in.open(argv[1]);
	for(int i=0; i<len; i++) {
		for (int j=0; j<2; j++) {
			in >> data[i][j];
		}
		// cout << data[i][0] << "	" << data[i][1] <<endl;
	}

	// 2-dim -> 1-dim
	for (int i=0; i<len; i++) {
		temp[2*i] 	= data[i][0];
		temp[2*i+1]	= data[i][1];
		// cout << temp[2*i] <<"---"<<temp[2*i+1]<<endl;
	}

	int max_val = Max(temp,0,2*len - 1);
	// cout << "max:" << max_val << endl;

	int *id = new int[max_val];
	for(int i=0; i<max_val; i++) {
		id[i] = i;
	}

	for(int i=0; i<len; i++){
		qfunion(id, data[i][0], data[i][1], 8192);
	}
	// for(int i=0; i<8192; i++){
	// 	cout << id[i] << " ";
	// }
	return 0;
}