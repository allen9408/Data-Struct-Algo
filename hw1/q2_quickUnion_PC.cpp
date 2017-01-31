#include <iostream>
#include <fstream>

using namespace std;

int qufind_w(int id[], int p) {
	int i = p;
	while (p != id[p]) {
		p = id[p];
	}
	id[i] = p;
	return p;
}

void quunion_w(int id[], int height[], int p, int q, int len)
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
	int count = 0;
	int *id = new int[len];
	int *height = new int[len];
	for(int i=0; i<len; i++) {
		id[i] = i;
		height[i] = 1;
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
		quunion_w(id, height, data[i][0], data[i][1], len);
	}
	for(int i=0; i<len; i++){
		cout << height[i] << " ";
	}
	return 0;
}