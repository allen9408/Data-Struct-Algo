#include <iostream>
#include <fstream>
#include "findMax.h"
#include <stdlib.h>

using namespace std;

int qufind_w(int id[], int p) {
	while (p != id[p]) {
		p = id[p];
	}
	return p;
}

void quunion_w(int id[], int height[], int p, int q)
{
	int pid = qufind_w(id, p);
	int qid = qufind_w(id, q);
	if (pid == qid)
	{
		return;
	}
	if (height[pid] < height[qid]) {
		id[pid] = qid;
		height[qid] = (height[qid]>height[pid])?height[qid]:(height[pid]+1);
	} else {
		id[qid] = pid;
		height[pid] = (height[pid]>height[qid])?height[pid]:(height[qid]+1);
	}
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
	}
	for (int i=0; i<len; i++) {
		temp[2*i] 	= data[i][0];
		temp[2*i+1]	= data[i][1];
	}
	/* Find max value */
	int max_val = Max(temp,0,2*len - 1);

	// Init
	int *id = new int[max_val];
	int *height = new int[max_val];
	for(int i=0; i<max_val; i++) {
		id[i] = i;
		height[i] = 1;
	}


	for(int i=0; i<len; i++){
		quunion_w(id, height, data[i][0], data[i][1]);
	}
	for(int i=0; i<len; i++){
		cout << height[i] << " ";
	}
	cout << endl;
	return 0;
}